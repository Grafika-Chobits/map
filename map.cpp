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

#define min(X,Y) (((X) < (Y)) ? (X) : (Y))
#define max(X,Y) (((X) > (Y)) ? (X) : (Y))

#define PI 3.14159265

#define degreesToRadians(angleDegrees) (angleDegrees * M_PI / 180.0)

/* SETTINGS ------------------------------------------------------------ */
#define screenXstart 250
#define screenX 1366
#define screenY 768
#define mouseSensitivity 1

using namespace std;

/* TYPEDEFS ------------------------------------------------------------ */

//RGB color
typedef struct s_rgb {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} RGB;

//Frame of RGBs
typedef struct s_frame {
	RGB px[screenX][screenY];
} Frame;

//Coordinate System
typedef struct s_coord {
	int x;
	int y;
} Coord;

//The integrated frame buffer plus info struct.
typedef struct s_frameBuffer {
	char* ptr;
	int smemLen;
	int lineLen;
	int bpp;
} FrameBuffer;


/* MATH STUFF ---------------------------------------------------------- */

// construct coord
Coord coord(int x, int y) {
	Coord retval;
	retval.x = x;
	retval.y = y;
	return retval;
}

unsigned char isInBound(Coord position, Coord corner1, Coord corner2) {
	unsigned char xInBound = 0;
	unsigned char yInBound = 0;
	if (corner1.x < corner2.x) {
		xInBound = (position.x>corner1.x) && (position.x<corner2.x);
	} else if (corner1.x > corner2.x) {
		xInBound = (position.x>corner2.x) && (position.x<corner1.x);
	} else {
		return 0;
	}
	if (corner1.y < corner2.y) {
		yInBound = (position.y>corner1.y) && (position.y<corner2.y);
	} else if (corner1.y > corner2.y) {
		yInBound = (position.y>corner2.y) && (position.y<corner1.y);
	} else {
		return 0;
	}
	return xInBound&&yInBound;
}

/* MOUSE OPERATIONS ---------------------------------------------------- */

// get mouse coord, with integrated screen-space bounding
Coord getCursorCoord(Coord* mc) {
	Coord xy;
	if (mc->x < 0) {
		mc->x = 0;
		xy.x = 0;
	} else if (mc->x >= screenX*mouseSensitivity) {
		mc->x = screenX*mouseSensitivity-1;
		xy.x = screenX-1;
	} else {
		xy.x = (int) mc->x / mouseSensitivity;
	}
	if (mc->y < 0) {
		mc->y = 0;
		xy.y = 0;
	} else if (mc->y >= screenY*mouseSensitivity) {
		mc->y = screenY*mouseSensitivity-1;
		xy.y = screenY-1;
	} else {
		xy.y = (int) mc->y / mouseSensitivity;
	}
	return xy;
}

/* VIDEO OPERATIONS ---------------------------------------------------- */

// construct RGB
RGB rgb(unsigned char r, unsigned char g, unsigned char b) {
	RGB retval;
	retval.r = r;
	retval.g = g;
	retval.b = b;
	return retval;
}

// insert pixel to composition frame, with bounds filter
void insertPixel(Frame* frm, Coord loc, RGB col) {
	// do bounding check:
	if (!(loc.x >= screenX || loc.x < 0 || loc.y >= screenY || loc.y < 0)) {
		frm->px[loc.x][loc.y].r = col.r;
		frm->px[loc.x][loc.y].g = col.g;
		frm->px[loc.x][loc.y].b = col.b;
	}
}

// delete contents of composition frame
void flushFrame (Frame* frm, RGB color) {
	int x;
	int y;
	for (y=0; y<screenY; y++) {
		for (x=0; x<screenX; x++) {
			frm->px[x][y] = color;
		}
	}
}

// copy composition Frame to FrameBuffer
void showFrame (Frame* frm, FrameBuffer* fb) {
	int x;
	int y;
	for (y=0; y<screenY; y++) {
		for (x=0; x<screenX; x++) {
			int location = x * (fb->bpp/8) + y * fb->lineLen;
			*(fb->ptr + location    ) = frm->px[x][y].b; // blue
			*(fb->ptr + location + 1) = frm->px[x][y].g; // green
			*(fb->ptr + location + 2) = frm->px[x][y].r; // red
			*(fb->ptr + location + 3) = 255; // transparency
		}
	}
}

void showCanvas(Frame* frm, Frame* cnvs, int canvasWidth, int canvasHeight, Coord loc, RGB borderColor, int isBorder) {
	int x, y;
	for (y=0; y<canvasHeight;y++) {
		for (x=0; x<canvasWidth; x++) {
			insertPixel(frm, coord(loc.x - canvasWidth/2 + x, loc.y - canvasHeight/2 + y), cnvs->px[x][y]);
		}
	}
	
	//show border
	if(isBorder){
		for (y=0; y<canvasHeight; y++) {
			insertPixel(frm, coord(loc.x - canvasWidth/2 - 1, loc.y - canvasHeight/2 + y), borderColor);
			insertPixel(frm, coord(loc.x  - canvasWidth/2 + canvasWidth, loc.y - canvasHeight/2 + y), borderColor);
		}
		for (x=0; x<canvasWidth; x++) {
			insertPixel(frm, coord(loc.x - canvasWidth/2 + x, loc.y - canvasHeight/2 - 1), borderColor);
			insertPixel(frm, coord(loc.x - canvasWidth/2 + x, loc.y - canvasHeight/2 + canvasHeight), borderColor);
		}
	}
}

int rotasiX(int xAwal,int yAwal,Coord loc,int sudut){
	return ((xAwal-loc.x)*cos(sudut)-(yAwal-loc.y)*sin(sudut)+loc.x);
}

int rotasiY(int xAwal,int yAwal,Coord loc,int sudut){
	return ((xAwal-loc.x)*sin(sudut)+(yAwal-loc.y)*cos(sudut)+loc.y);
}

void plotCircle(Frame* frm,int xm, int ym, int r,RGB col)
{
   int x = -r, y = 0, err = 2-2*r; /* II. Quadrant */ 
   do {
      insertPixel(frm,coord(xm-x, ym+y),col); /*   I. Quadrant */
      insertPixel(frm,coord(xm-y, ym-x),col); /*  II. Quadrant */
      insertPixel(frm,coord(xm+x, ym-y),col); /* III. Quadrant */
      insertPixel(frm,coord(xm+y, ym+x),col); /*  IV. Quadrant */
      r = err;
      if (r <= y) err += ++y*2+1;           /* e_xy+e_y < 0 */
      if (r > x || err > y) err += ++x*2+1; /* e_xy+e_x > 0 or no 2nd y-step */
   } while (x < 0);
}

void plotHalfCircle(Frame *frm,int xm, int ym, int r,RGB col)
{
   int x = -r, y = 0, err = 2-2*r; /* II. Quadrant */ 
   do {
      insertPixel(frm,coord(xm+x, ym-y),col); /* III. Quadrant */
      insertPixel(frm,coord(xm+y, ym+x),col); /*  IV. Quadrant */
      r = err;
      if (r <= y) err += ++y*2+1;           /* e_xy+e_y < 0 */
      if (r > x || err > y) err += ++x*2+1; /* e_xy+e_x > 0 or no 2nd y-step */
   } while (x < 0);
}

/* Fungsi membuat garis */
void plotLine(Frame* frm, int x0, int y0, int x1, int y1, RGB lineColor)
{
	int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1; 
	int err = dx+dy, e2; /* error value e_xy */
	int loop = 1;
	while(loop){  /* loop */
		insertPixel(frm, coord(x0, y0), rgb(lineColor.r, lineColor.g, lineColor.b));
		if (x0==x1 && y0==y1) loop = 0;
		e2 = 2*err;
		if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
		if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
	}
}

void plotLineWidth(Frame* frm, int x0, int y0, int x1, int y1, float wd, RGB lineColor) { 
	int dx = abs(x1-x0), sx = x0 < x1 ? 1 : -1; 
	int dy = abs(y1-y0), sy = y0 < y1 ? 1 : -1; 
	int err = dx-dy, e2, x2, y2;                          /* error value e_xy */

	float ed = dx+dy == 0 ? 1 : sqrt((float)dx*dx+(float)dy*dy);

	for (wd = (wd+1)/2; ; ) {                                   /* pixel loop */
		insertPixel(frm, coord(x0, y0), rgb(max(0,lineColor.r*(abs(err-dx+dy)/ed-wd+1)), 
											max(0,lineColor.g*(abs(err-dx+dy)/ed-wd+1)), 
											max(0,lineColor.b*(abs(err-dx+dy)/ed-wd+1))));

		e2 = err; x2 = x0;
		if (2*e2 >= -dx) {                                           /* x step */
			for (e2 += dy, y2 = y0; e2 < ed*wd && (y1 != y2 || dx > dy); e2 += dx)
				y2 += sy;
				insertPixel(frm, coord(x0, y2), rgb(max(0,lineColor.r*(abs(e2)/ed-wd+1)), 
															max(0,lineColor.g*(abs(e2)/ed-wd+1)), 
															max(0,lineColor.b*(abs(e2)/ed-wd+1)))); 
			if (x0 == x1) break;
			e2 = err; err -= dy; x0 += sx; 
		} 
		
		if (2*e2 <= dy) {                                            /* y step */
			for (e2 = dx-e2; e2 < ed*wd && (x1 != x2 || dx < dy); e2 += dy)
				x2 += sx;
				insertPixel(frm, coord(x2, y0), rgb(max(0,lineColor.r*(abs(e2)/ed-wd+1)), 
															max(0,lineColor.g*(abs(e2)/ed-wd+1)), 
															max(0,lineColor.b*(abs(e2)/ed-wd+1)))); 
			if (y0 == y1) break;
			err += dx; y0 += sy; 
		}
	}
}

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

void drawBaling(Frame *frm , Coord loc,int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4 ,RGB color){
	int xOffset = loc.x-x1;
	int yOffset = loc.y-y1;

	plotCircle(frm,loc.x,loc.y,15,color);
	std::vector<Coord> balingCoordinates;
	balingCoordinates.push_back(loc);
	balingCoordinates.push_back(coord(x1, y1));
	balingCoordinates.push_back(coord(x2, y2));
	balingCoordinates.push_back(coord(x3,y3));
	balingCoordinates.push_back(coord(x4,y4));

	// Gambar baling-baling
	for(int i = 0; i < balingCoordinates.size(); i++){
		int x0, y0, x1, y1;
		if(i < balingCoordinates.size() - 1){
			x0 = balingCoordinates.at(i).x;
			y0 = balingCoordinates.at(i).y;
			x1 = balingCoordinates.at(i + 1).x;
			y1 = balingCoordinates.at(i + 1).y;
		}else{
			x0 = balingCoordinates.at(balingCoordinates.size() - 1).x;
			y0 = balingCoordinates.at(balingCoordinates.size() - 1).y;
			x1 = balingCoordinates.at(0).x;
			y1 = balingCoordinates.at(0).y;
		}
		plotLine(frm, x0, y0, x1, y1, color);
	}

	int balingHeight = 80;
	//fillShape(frm, loc.x, loc.y, loc.y-40, balingHeight, balingCoordinates, color);

	// plotLine(frm,loc.x,loc.y,x1,y1,color);
	// plotLine(frm,loc.x,loc.y,x2,y2,color);
	// plotLine(frm,x1,y1,x2,y2,color);
	
	// plotLine(frm,loc.x,loc.y,x3,y3,rgb(255,0,0));
	// plotLine(frm,loc.x,loc.y,x4,y4,color);
	// plotLine(frm,x3,y3,x4,y4,color);
}
				
void rotateBaling(Frame *frm,Coord loc, RGB col ,int counter ){
	int x1=loc.x+40; int y1=loc.y+5;
	int x2=loc.x+40; int y2=loc.y-5;
	int x3=loc.x-40; int y3=loc.y+5;
	int x4=loc.x-40; int y4=loc.y-5;
	
	int temp;
	temp=rotasiX(x1,y1,loc,counter*10);
	y1=rotasiY(x1,y1,loc,counter*10);
	x1=temp;
	temp=rotasiX(x2,y2,loc,counter*10);
	y2=rotasiY(x2,y2,loc,counter*10);
	x2=temp;
	temp=rotasiX(x3,y3,loc,counter*10);	
	y3=rotasiY(x3,y3,loc,counter*10);
	x3=temp;
	temp=rotasiX(x4,y4,loc,counter*10);
	y4=rotasiY(x4,y4,loc,counter*10);
	x4=temp;
	drawBaling(frm,loc,x1,x2,x3,x4,y1,y2,y3,y4,col);
}

Coord lengthEndPoint(Coord startingPoint, int degree, int length){
	Coord endPoint;
	
	endPoint.x = int((double)length * cos((double)degree * PI / (double)180)) + startingPoint.x;
	endPoint.y = int((double)length * sin((double)degree * PI / (double)180)) + startingPoint.y;
	
	return endPoint;
}

void drawWalkingStickman(Frame *frame, Coord center, RGB color){
	int bodyLength = 50;
	int rightUpperArmLength = 30;
	int rightLowerArmLength = 20;
	int leftUpperArmLength = 30;
	int leftLowerArmLength = 20;
	int rightUpperLegLength = 30;
	int rightLowerLegLength = 20;
	int leftUpperLegLength = 30;
	int leftLowerLegLength = 20;
	
	static int centerPositionY = center.y;
	
	// head
	plotCircle(frame, center.x, centerPositionY - 20, 20, color);
	
	// body	
	Coord bodyEndPoint = lengthEndPoint(coord(center.x, centerPositionY), 88, bodyLength);
	plotLine(frame, center.x, centerPositionY, bodyEndPoint.x, bodyEndPoint.y, color);
	
	// right upper arm
	Coord rightUpperArmEndPoint;
	static int rightUpperArmRotation = 125;
	{
		static int moveBackwardArm = 1;
		
		if(rightUpperArmRotation == 125){
			moveBackwardArm = 1;
		}
		if(rightUpperArmRotation == 65){
			moveBackwardArm = 0;
		}
		
		
		if(moveBackwardArm){
			rightUpperArmRotation -= 5;
		}else{
			rightUpperArmRotation += 5;
		}
		
		rightUpperArmEndPoint = lengthEndPoint(coord(center.x, centerPositionY), rightUpperArmRotation, rightUpperArmLength);
		plotLine(frame, center.x, centerPositionY, rightUpperArmEndPoint.x, rightUpperArmEndPoint.y, color);
	}
	
	// right lower arm
	Coord rightLowerArmEndPoint = lengthEndPoint(coord(rightUpperArmEndPoint.x, rightUpperArmEndPoint.y), rightUpperArmRotation + 50, rightLowerArmLength);
	plotLine(frame, rightUpperArmEndPoint.x, rightUpperArmEndPoint.y, rightLowerArmEndPoint.x, rightLowerArmEndPoint.y, color);
	
	// left upper arm
	Coord leftUpperArmEndPoint;
	static int leftUpperArmRotation = 65;
	{
		
		static int moveForwardArm = 1;
		
		if(leftUpperArmRotation == 65){
			moveForwardArm = 1;
		}
		if(leftUpperArmRotation == 125){
			moveForwardArm = 0;
		}
		
		if(moveForwardArm){
			leftUpperArmRotation += 5;
		}else{
			leftUpperArmRotation -= 5;
		}
		
		leftUpperArmEndPoint = lengthEndPoint(coord(center.x, centerPositionY), leftUpperArmRotation, leftUpperArmLength);
		plotLine(frame, center.x, centerPositionY, leftUpperArmEndPoint.x, leftUpperArmEndPoint.y, color);
	}
	
	// left lower arm
	Coord leftLowerArmEndPoint = lengthEndPoint(coord(leftUpperArmEndPoint.x, leftUpperArmEndPoint.y), leftUpperArmRotation + 30, leftLowerArmLength);
	plotLine(frame, leftUpperArmEndPoint.x, leftUpperArmEndPoint.y, leftLowerArmEndPoint.x, leftLowerArmEndPoint.y, color);
	
	// right upper leg
	Coord rightUpperLegEndPoint;
	static int rightUpperLegRotation = 125;
	{
		static int moveBackwardLeg = 1;
		
		if(rightUpperLegRotation == 125){
			moveBackwardLeg = 1;
		}
		if(rightUpperLegRotation == 65){
			moveBackwardLeg = 0;
		}
		
		if(moveBackwardLeg){
			rightUpperLegRotation -= 5;
		}else{
			rightUpperLegRotation += 5;
		}
		
		rightUpperLegEndPoint = lengthEndPoint(coord(bodyEndPoint.x, bodyEndPoint.y), rightUpperLegRotation, rightUpperLegLength);
		plotLine(frame, bodyEndPoint.x, bodyEndPoint.y, rightUpperLegEndPoint.x, rightUpperLegEndPoint.y, color);
	}
	
	// right lower leg
	{
		static int rightLowerLegRotation = 95;
		static int moveBackwardLeg = 1;
		
		if(rightUpperLegRotation == 125){
			moveBackwardLeg = 1;
			rightLowerLegRotation = 95;
		}
		if(rightUpperLegRotation == 65){
			moveBackwardLeg = 0;
			rightLowerLegRotation = 70;
		}
		
		if(rightUpperLegRotation <= 90 ){
			if(moveBackwardLeg){
				rightLowerLegRotation = rightUpperLegRotation;
			}else{
				rightLowerLegRotation -= 5;
			}
		}else{
			if(!moveBackwardLeg){
				rightLowerLegRotation += 10;
				if(centerPositionY <= center.y + 1){
					centerPositionY++;
				}
			}else{
				if(centerPositionY > center.y){
					centerPositionY--;
				}
			}
		}

		Coord rightLowerLegEndPoint = lengthEndPoint(coord(rightUpperLegEndPoint.x, rightUpperLegEndPoint.y), rightLowerLegRotation, rightLowerLegLength);
		plotLine(frame, rightUpperLegEndPoint.x, rightUpperLegEndPoint.y, rightLowerLegEndPoint.x, rightLowerLegEndPoint.y, color);
	}
	
	// left upper leg
	Coord leftUpperLegEndPoint;
	static int leftUpperLegRotation = 65;
	{
		static int moveForwardLeg = 1;
		
		if(leftUpperLegRotation == 125){
			moveForwardLeg = 0;
		}
		if(leftUpperLegRotation == 65){
			moveForwardLeg = 1;
		}
		
		if(moveForwardLeg){
			leftUpperLegRotation += 5;
		}else{
			leftUpperLegRotation -= 5;
		}
		
		leftUpperLegEndPoint = lengthEndPoint(coord(bodyEndPoint.x, bodyEndPoint.y), leftUpperLegRotation, leftUpperLegLength);
		plotLine(frame, bodyEndPoint.x, bodyEndPoint.y, leftUpperLegEndPoint.x, leftUpperLegEndPoint.y, color);
	}
	
	// left lower leg
	{
		static int leftLowerLegRotation = 70;
		static int moveForwardLeg = 1;
		
		if(leftUpperLegRotation == 125){
			moveForwardLeg = 0;
			leftLowerLegRotation = 95;
		}
		if(leftUpperLegRotation == 65){
			moveForwardLeg = 1;
			leftLowerLegRotation = 70;
		}
		
		if(leftUpperLegRotation <= 90 ){
			if(moveForwardLeg){
				leftLowerLegRotation -= 5;
			}else{
				leftLowerLegRotation = leftUpperLegRotation;
			}
		}else{
			if(moveForwardLeg){
				leftLowerLegRotation += 10;
				if(centerPositionY <= center.y + 1){
					centerPositionY++;
				}
			}else{
				if(centerPositionY > center.y){
					centerPositionY--;
				}
			}
		}
		
		Coord leftLowerLegEndPoint = lengthEndPoint(coord(leftUpperLegEndPoint.x, leftUpperLegEndPoint.y), leftLowerLegRotation, leftLowerLegLength);
		plotLine(frame, leftUpperLegEndPoint.x, leftUpperLegEndPoint.y, leftLowerLegEndPoint.x, leftLowerLegEndPoint.y, color);
	}
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
	
	/* Main Loop ------------------------------------------------------- */
	
	while (loop) {
		
		// clean composition frame
		flushFrame(&cFrame, rgb(33,33,33));
				
		showCanvas(&cFrame, &canvas, canvasWidth, canvasHeight, canvasPosition, rgb(99,99,99), 1);
		
		// clean canvas
		flushFrame(&canvas, rgb(0,0,0));

		//show frame
		showFrame(&cFrame,&fb);	
	}

	/* Cleanup --------------------------------------------------------- */
	munmap(fb.ptr, sInfo.smem_len);
	close(fbFile);
	fclose(fmouse);
	return 0;
}
