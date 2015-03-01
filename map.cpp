#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <linux/fb.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <stack>
#include "allstruct.h"
#include "video.h"
#include "plotting.h"
#include "rotasi.h"
#include "drawing.h"
#include "clip.h"

using namespace std;

/* FUNCTIONS FOR SCANLINE ALGORITHM ---------------------------------------------------- */

bool isSlopeEqualsZero(int y0, int y1){
	if(y0 == y1){
		return true;
	}else{
		return false;
	}
}

bool isInBetween(int y0, int y1, int yTest){
	if((yTest >= y0 && yTest <= y1 || yTest >= y1 && yTest <= y0) && !isSlopeEqualsZero(y0, y1)){
		return true;
	}else{
		return false;
	}
}

/* Function to calculate intersection between line (a,b) and line with slope 0 */
Coord intersection(Coord a, Coord b, int y){
	int x;
	double slope;
	
	if(b.x == a.x){
		x = a.x;
	}else{
		slope = (double)(b.y - a.y) / (double)(b.x - a.x);
		x = round(((double)(y - a.y) / slope) + (double)a.x);
	}
	
	return coord(x, y);
}

bool compareByAxis(const s_coord &a, const s_coord &b){
	return a.x <= b.x;
}

bool compareSameAxis(const s_coord &a, const s_coord &b){
	return a.x == b.x;
}

bool operator==(const Coord& lhs, const Coord& rhs) {
	if(lhs.x==rhs.x && lhs.y==rhs.y)
		return true;
	return false;
}

bool isLocalMaxima(const Coord& a, const Coord& b, const Coord& titikPotong) {
	return ((titikPotong.y<a.y && titikPotong.y<b.y) || (titikPotong.y>a.y && titikPotong.y>b.y));
}

vector<Coord> intersectionGenerator(int y, vector<Coord> polygon){
	vector<Coord> intersectionPoint;
	Coord prevTipot = coord(-9999,-9999);
	for(int i = 0; i < polygon.size(); i++){
		if(i == polygon.size() - 1){
			if(isInBetween(polygon.at(i).y, polygon.at(0).y, y)){				
				Coord a = coord(polygon.at(i).x, polygon.at(i).y);
				Coord b = coord(polygon.at(0).x, polygon.at(0).y);
						
				Coord titikPotong = intersection(a, b, y);

				if(titikPotong==b){
					if(isLocalMaxima(polygon.at(i), polygon.at(1), titikPotong))
						intersectionPoint.push_back(titikPotong);
				}
				else {
					if(prevTipot==titikPotong){
						if(isLocalMaxima(polygon.at(i-1), polygon.at(0), titikPotong))
							intersectionPoint.push_back(titikPotong);
					}
					else
						intersectionPoint.push_back(titikPotong);
				}
			}
		}else{
			if(isInBetween(polygon.at(i).y, polygon.at(i + 1).y, y)){
				Coord a = coord(polygon.at(i).x, polygon.at(i).y);
				Coord b = coord(polygon.at(i + 1).x, polygon.at(i + 1).y);
				
				Coord titikPotong = intersection(a, b, y);

				// Jika sama dgn tipot sebelumnya, cek apakah local minima/maxima
				if(titikPotong==prevTipot) {
					Coord z = coord(polygon.at(i-1).x, polygon.at(i-1).y);
					if(isLocalMaxima(z, b, titikPotong)) {
						intersectionPoint.push_back(titikPotong);
					}
				}
				else {
					intersectionPoint.push_back(titikPotong);
				}
				prevTipot = intersectionPoint.back();
			}
		}
	}
	
	sort(intersectionPoint.begin(), intersectionPoint.end(), compareByAxis);
	
	return intersectionPoint;
}
vector<Coord> combineIntersection(vector<Coord> a, vector<Coord> b){
	for(int i = 0; i < b.size(); i++){
		a.push_back(b.at(i));
	}
	
	sort(a.begin(), a.end(), compareByAxis);
	
	return a;
}

void fillShape(Frame *frame, int xOffset, int yOffset, int startY, int shapeHeight, std::vector<Coord> shapeCoord, RGB color) {
	for(int i = startY; i <= shapeHeight; i++){
		vector<Coord> shapeIntersectionPoint = intersectionGenerator(i, shapeCoord);	
		for(int j = 0; j < shapeIntersectionPoint.size() - 1; j++){
			if(j % 2 == 0){
				int x0 = shapeIntersectionPoint.at(j).x + xOffset;
				int y0 = shapeIntersectionPoint.at(j).y + yOffset;
				int x1 = shapeIntersectionPoint.at(j + 1).x + xOffset;
				int y1 = shapeIntersectionPoint.at(j + 1).y + yOffset;
				
				plotLine(frame, x0, y0, x1, y1, color);
			}
		}		
	}
}

Coord lengthEndPoint(Coord startingPoint, int angle, int length){
	Coord endPoint;
	
	endPoint.x = int((double)length * cos((double)angle * PI / (double)180)) + startingPoint.x;
	endPoint.y = int((double)length * sin((double)angle * PI / (double)180)) + startingPoint.y;
	
	return endPoint;
}

void viewPort(Frame *frame, Coord origin, int size){
	// viewport frame
	plotLine(frame, origin.x, origin.y, origin.x + size, origin.y, rgb(255,255,255));
	plotLine(frame, origin.x, origin.y, origin.x, origin.y + size, rgb(255,255,255));
	plotLine(frame, origin.x, origin.y + size, origin.x + size, origin.y + size, rgb(255,255,255));
	plotLine(frame, origin.x + size, origin.y, origin.x + size, origin.y + size, rgb(255,255,255));
}

void window(Frame *frame, Coord origin, int size){
	
}

/* MAIN FUNCTION ------------------------------------------------------- */
int main() {	
	/* Preparations ---------------------------------------------------- */
	
	// get fb and screenInfos
	struct fb_var_screeninfo vInfo; // variable screen info
	struct fb_fix_screeninfo sInfo; // static screen info
	int fbFile;	 // frame buffer file descriptor
	fbFile = open("/dev/fb0",O_RDWR);
	if (!fbFile) {
		printf("Error: cannot open framebuffer device.\n");
		exit(1);
	}
	if (ioctl (fbFile, FBIOGET_FSCREENINFO, &sInfo)) {
		printf("Error reading fixed information.\n");
		exit(2);
	}
	if (ioctl (fbFile, FBIOGET_VSCREENINFO, &vInfo)) {
		printf("Error reading variable information.\n");
		exit(3);
	}
	
	// create the FrameBuffer struct with its important infos.
	FrameBuffer fb;
	fb.smemLen = sInfo.smem_len;
	fb.lineLen = sInfo.line_length;
	fb.bpp = vInfo.bits_per_pixel;
	
	// and map the framebuffer to the FB struct.
	fb.ptr = (char*)mmap(0, sInfo.smem_len, PROT_READ | PROT_WRITE, MAP_SHARED, fbFile, 0);
	if ((long int)fb.ptr == -1) {
		printf ("Error: failed to map framebuffer device to memory.\n");
		exit(4);
	}
	
	// prepare mouse controller
	FILE *fmouse;
	char mouseRaw[3];
	fmouse = fopen("/dev/input/mice","r");
	Coord mouse; // mouse internal counter
	mouse.x = 0;
	mouse.y = 0;
		
	// prepare environment controller
	unsigned char loop = 1; // frame loop controller
	Frame cFrame; // composition frame (Video RAM)
	
	// prepare canvas
	Frame canvas;
	flushFrame(&canvas, rgb(0,0,0));
	int canvasWidth = 1300;
	int canvasHeight = 700;
	Coord canvasPosition = coord(screenX/2,screenY/2);
	
	// viewport properties
	int viewportSize = 300;
	Coord viewportOrigin = coord(999, 399);
	
	//baling
	int balingCounter=0;
	int planeVelocity = 20;
	int planeXPosition = canvasWidth;
	int planeYPosition = 100;
	int kapalXPosition = 250;
	int kapalVelocity = 15;
	int kapalYPosition = 250;

	//crop
	vector<Line> mapLines;
	//vector<Line> heliLines;
	//vector<Line> kapalLines;
	
	vector<Line> allLines;
	vector<Line> croppedLines;
	while (loop) {
		
		// clean composition frame
		flushFrame(&cFrame, rgb(33,33,33));
		
		viewPort(&canvas, viewportOrigin, viewportSize);
				
		showCanvas(&cFrame, &canvas, canvasWidth, canvasHeight, canvasPosition, rgb(99,99,99), 1);
								
		// clean canvas
		flushFrame(&canvas, rgb(0,0,0));
		
		//clean vector
		allLines.clear();
		
		//Nambahin Lines biar semua jadi 1
		mapLines = drawPeta(&canvas, coord(0,0), rgb(50,150,0));
		//heliLines = drawPlane()
		//kapalLines = drawKapal()
		
		allLines.insert(allLines.end(), mapLines.begin(), mapLines.end());
		//allLines.insert(allLines.end(), heliLines.begin(), heliLines.end());
		//allLines.insert(allLines.end(), kapalLines.begin(), kapalLines.end());
		//~ printf("Ukuran allLines = %d\n", allLines.size());
		
		//Draw window and get cropped lines
		croppedLines = cohen_sutherland(&canvas, allLines, coord(450, 300), 100);
		//printf("Jumlah cropped lines = %d\n", croppedLines.size());
		for(int i = 0; i < croppedLines.size(); i++)
			plotLine(&canvas, croppedLines.at(i), rgb(0,255,0));
			//cohen_sutherland (&canvas, StartX(croppedLines.at(i)),StartY(croppedLines.at(i)),EndX(croppedLines.at(i)),EndY(croppedLines.at(i)), 400, 400, 1000, 600, rgb(255,0,0));
		
		drawKapal(&canvas,coord(kapalXPosition -= -kapalVelocity,kapalYPosition),rgb(99,99,99));
		
		rotateBaling(&canvas,coord(planeXPosition -= planeVelocity,planeYPosition),rgb(255,255,255),balingCounter++);

		//show frame
		showFrame(&cFrame,&fb);	
	}

	/* Cleanup --------------------------------------------------------- */
	munmap(fb.ptr, sInfo.smem_len);
	close(fbFile);
	fclose(fmouse);
	return 0;
}
