#include "drawing.h"

void drawSquare (Frame *frm, Coord kiriAtas, Coord kananBawah, RGB color)
{
	//atas
	plotLine(frm, kiriAtas.x, kiriAtas.y, kananBawah.x, kiriAtas.y, color);
	//kanan
	plotLine(frm, kananBawah.x, kiriAtas.y, kananBawah.x, kananBawah.y, color);
	//kiri
	plotLine(frm, kiriAtas.x, kiriAtas.y, kiriAtas.x, kananBawah.y, color);
	//bawah
	plotLine(frm, kiriAtas.x, kananBawah.y, kananBawah.x, kananBawah.y, color);
}

void drawKapal(Frame *frm, Coord loc, RGB color){
	plotLine(frm,loc.x-15,loc.y-10,loc.x+15,loc.y-10,color);
	plotLine(frm,loc.x-15,loc.y+10,loc.x+15,loc.y+10,color);
	plotLine(frm,loc.x-15,loc.y-10,loc.x-20,loc.y,color);
	plotLine(frm,loc.x+15,loc.y-10,loc.x+20,loc.y,color); 	
	plotLine(frm,loc.x-15,loc.y+10,loc.x-20,loc.y,color);
	plotLine(frm,loc.x+15,loc.y+10,loc.x+20,loc.y,color);
	}

void drawPeta(Frame *frame, Coord center, RGB color) {
	std::vector<Line> sumatera;
	Coord offset = coord(30, 10);
	sumatera.push_back(line(offset, coord(offset.x+20, offset.y+20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())+10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+15, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+10, EndY(sumatera.back())+20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+5, EndY(sumatera.back())+20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+5, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())+10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+15, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+5, EndY(sumatera.back())+30)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+45, EndY(sumatera.back())+20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+35, EndY(sumatera.back())+30)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back()), EndY(sumatera.back())+5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+3, EndY(sumatera.back())+8)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+5, EndY(sumatera.back())+5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+10, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+10, EndY(sumatera.back())+5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+10, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-10, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())+20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-3, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())+5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-20, EndY(sumatera.back())+15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-10, EndY(sumatera.back())-5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-15, EndY(sumatera.back())-5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-10, EndY(sumatera.back())-5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-10, EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-20, EndY(sumatera.back())-5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-15, EndY(sumatera.back())-8)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-10, EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())-15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+5, EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+3, EndY(sumatera.back())-20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-10, EndY(sumatera.back())-15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())-25)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())-15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back()), EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())-15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-10, EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())-15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back()), EndY(sumatera.back())-15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-15, EndY(sumatera.back())-20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-15, EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+10, EndY(sumatera.back())-15)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back()), EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())-5, EndY(sumatera.back())-5)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+8, EndY(sumatera.back())-20)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back()), EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back())+3, EndY(sumatera.back())-7)));
	sumatera.push_back(line(End(sumatera.back()), coord(EndX(sumatera.back()), EndY(sumatera.back())-10)));
	sumatera.push_back(line(End(sumatera.back()), offset));

	std::vector<Line> jawa;
	Coord offsetJawa = coord(offset.x+180, offset.y+350);
	jawa.push_back(line(offsetJawa, coord(offsetJawa.x+15, offsetJawa.y-10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+15, EndY(jawa.back())+10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+25, EndY(jawa.back())+5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back()))));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+15, EndY(jawa.back())+10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+20, EndY(jawa.back())+8)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+8, EndY(jawa.back())-2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+15, EndY(jawa.back())+7)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+15, EndY(jawa.back()))));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())-3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+15, EndY(jawa.back())-5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())-1)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+5, EndY(jawa.back())+3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+8, EndY(jawa.back())+6)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())+3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())+8)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+20, EndY(jawa.back())+2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())+3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+30, EndY(jawa.back())-3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())-5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+5, EndY(jawa.back())-7)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+5, EndY(jawa.back())-4)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+3, EndY(jawa.back()))));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())+2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+15, EndY(jawa.back())+4)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+10, EndY(jawa.back())+10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+3, EndY(jawa.back())+15)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+2, EndY(jawa.back())+10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-5, EndY(jawa.back())+15)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+3, EndY(jawa.back())+4)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+6, EndY(jawa.back())+5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+5, EndY(jawa.back())+2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+4, EndY(jawa.back())+4)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+5, EndY(jawa.back())+4)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-5, EndY(jawa.back())+2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-25, EndY(jawa.back())+4)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-15, EndY(jawa.back())-3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-10, EndY(jawa.back())-6)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-15, EndY(jawa.back())+5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-25, EndY(jawa.back())-10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-45, EndY(jawa.back())+2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-35, EndY(jawa.back())+2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-40, EndY(jawa.back())-3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-20, EndY(jawa.back())-5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-15, EndY(jawa.back())-3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-25, EndY(jawa.back())+2)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-20, EndY(jawa.back())-10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-15, EndY(jawa.back())-15)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-10, EndY(jawa.back())+3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-8, EndY(jawa.back())-5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-25, EndY(jawa.back())-15)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-20, EndY(jawa.back())-10)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-5, EndY(jawa.back()))));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-15, EndY(jawa.back())-8)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())-3, EndY(jawa.back())-5)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+5, EndY(jawa.back())-4)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back())+5, EndY(jawa.back())-3)));
	jawa.push_back(line(End(jawa.back()), coord(EndX(jawa.back()), EndY(jawa.back())-2)));
	jawa.push_back(line(End(jawa.back()), offsetJawa));

	std::vector<Line> kalimantan;
	Coord offsetKalimantan = coord(offset.x+230, offset.y+150);
	kalimantan.push_back(line(offsetKalimantan, coord(offsetKalimantan.x+5, offsetKalimantan.y-5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())+8)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())+5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+15, EndY(kalimantan.back())+8)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())-1)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+5, EndY(kalimantan.back())+3)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())-5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+15, EndY(kalimantan.back())-3)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+15, EndY(kalimantan.back())-2)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())-6)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+15, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+15, EndY(kalimantan.back())-3)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())+1)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())+2)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+15, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+8, EndY(kalimantan.back())-15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+10, EndY(kalimantan.back())-15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+15, EndY(kalimantan.back())-20)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+5, EndY(kalimantan.back())-15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+5, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+6, EndY(kalimantan.back())-3)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+6, EndY(kalimantan.back())-5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+4, EndY(kalimantan.back())-5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+4, EndY(kalimantan.back())+3)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+3, EndY(kalimantan.back())+8)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+5, EndY(kalimantan.back())+35)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-4, EndY(kalimantan.back())+20)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-2, EndY(kalimantan.back())+20)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-8, EndY(kalimantan.back())+10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-1, EndY(kalimantan.back())+5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+3, EndY(kalimantan.back())+5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-1, EndY(kalimantan.back())+5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-5, EndY(kalimantan.back())+15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-10, EndY(kalimantan.back())+8)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-+2, EndY(kalimantan.back())+5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-5, EndY(kalimantan.back())+15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-10, EndY(kalimantan.back())+25)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+3, EndY(kalimantan.back())+25)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-1, EndY(kalimantan.back())+15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-3, EndY(kalimantan.back())+15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-20, EndY(kalimantan.back())+15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-15, EndY(kalimantan.back())+10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-25, EndY(kalimantan.back())+3)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-10, EndY(kalimantan.back())-2)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-7, EndY(kalimantan.back())-5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-5, EndY(kalimantan.back())+1)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-5, EndY(kalimantan.back())+2)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-25, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-30, EndY(kalimantan.back())-25)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-15, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-5, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-5, EndY(kalimantan.back())-5)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-7, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-10, EndY(kalimantan.back())-15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+2, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-3, EndY(kalimantan.back())-25)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-10, EndY(kalimantan.back())-15)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())-10, EndY(kalimantan.back())-10)));
	kalimantan.push_back(line(End(kalimantan.back()), coord(EndX(kalimantan.back())+7, EndY(kalimantan.back())-7)));
	kalimantan.push_back(line(End(kalimantan.back()), offsetKalimantan));


	std::vector<Line> sulawesi;
	Coord offsetSulawesi = coord(offset.x+520, offset.y+170);
	sulawesi.push_back(line(offsetSulawesi, coord(offsetSulawesi.x+2, offsetSulawesi.y-15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+4, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())-4)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+8, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+10, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+15, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())-5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())-1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())-2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+15, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+20, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+30, EndY(sulawesi.back())-1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+25, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+10, EndY(sulawesi.back())-5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())-6)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+4, EndY(sulawesi.back())-5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+7, EndY(sulawesi.back())-8)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+7, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+7, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())+4)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-9, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-9, EndY(sulawesi.back())+15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())+4)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-15, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-15, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-15, EndY(sulawesi.back())+1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-25, EndY(sulawesi.back())-1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-8, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-15, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-6, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-2, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+1, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-2, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+10, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+8, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+15, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+10, EndY(sulawesi.back())-2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+8, EndY(sulawesi.back())-2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+9, EndY(sulawesi.back())+1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())-2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+8, EndY(sulawesi.back())-1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+7, EndY(sulawesi.back())+1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+15, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())+1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+7, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+10, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+3, EndY(sulawesi.back())+4)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+6, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+3, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-4, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-4, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-6, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-7, EndY(sulawesi.back())+4)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-4, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())+1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())-1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-4, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-11, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-6, EndY(sulawesi.back())+2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-4, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())+8)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-4, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-7, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())+4)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+3, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())+3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+18, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+8, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+15, EndY(sulawesi.back())+20)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-2, EndY(sulawesi.back())+7)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+1, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+8, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+20, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+1, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())+5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-20, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-25, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())-5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-5)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-6, EndY(sulawesi.back())-8)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-7, EndY(sulawesi.back())-2)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-2, EndY(sulawesi.back())+15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())+20)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+3, EndY(sulawesi.back())+10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+4, EndY(sulawesi.back())+15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-2, EndY(sulawesi.back())+20)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())+4)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())+1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())-7)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+2, EndY(sulawesi.back())-3)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-10, EndY(sulawesi.back())-20)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())-15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-8, EndY(sulawesi.back())+1)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-3, EndY(sulawesi.back())-8)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+1, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+2, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-1, EndY(sulawesi.back())-15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-2, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+4, EndY(sulawesi.back())-15)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())-5, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+3, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+2, EndY(sulawesi.back())-7)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+5, EndY(sulawesi.back())-8)));
	sulawesi.push_back(line(End(sulawesi.back()), coord(EndX(sulawesi.back())+2, EndY(sulawesi.back())-10)));
	sulawesi.push_back(line(End(sulawesi.back()), offsetSulawesi));

	std::vector<Line> papua;
	Coord offsetPapua = coord(offset.x+900, offset.y+170);
	papua.push_back(line(offsetPapua, coord(offsetPapua.x+5, offsetPapua.y-5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())-5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())+2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())-6)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+5, EndY(papua.back())+2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+8, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())+7)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+3, EndY(papua.back())+5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+3, EndY(papua.back())+7)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+1, EndY(papua.back())+7)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-3, EndY(papua.back())+7)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+1, EndY(papua.back())+5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+5, EndY(papua.back())+11)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())+10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+5, EndY(papua.back())+7)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+7, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+4, EndY(papua.back())+8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+8, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())+2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+7, EndY(papua.back())-5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+8, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+6, EndY(papua.back())-11)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+7, EndY(papua.back())-14)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+7, EndY(papua.back())-14)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())-2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())+6)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())+10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())+3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())+2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+8, EndY(papua.back())-1)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())-2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())+3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back()), EndY(papua.back())+150)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-5, EndY(papua.back())-5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())+1)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())+8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-4, EndY(papua.back())+5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-7, EndY(papua.back())+2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-8, EndY(papua.back())+3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+2, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-12, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+2, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-6)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-7)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-9)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-12, EndY(papua.back())+1)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-6)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-12, EndY(papua.back())+1)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-13)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-18, EndY(papua.back())-8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-20, EndY(papua.back())-5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-7)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())+4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-5, EndY(papua.back())+5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())+3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-1)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-3, EndY(papua.back())-8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+5, EndY(papua.back())-5)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+9, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+15, EndY(papua.back())-8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+10, EndY(papua.back())-8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+4, EndY(papua.back())-6)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+6, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-5, EndY(papua.back())-2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-4, EndY(papua.back())-8)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-6, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-7, EndY(papua.back())+1)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-8, EndY(papua.back())-2)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-9, EndY(papua.back())-4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-8, EndY(papua.back())-10)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-6)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-15, EndY(papua.back())-4)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-8, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), coord(EndX(papua.back())+1, EndY(papua.back())-3)));
	papua.push_back(line(End(papua.back()), offsetPapua));
	//papua.push_back(line(End(papua.back()), coord(EndX(papua.back())-10, EndY(papua.back())-6)));

	std::vector<Line> allLine;
	drawSquare(frame, coord(400, 300), coord(800, 600), color);
	
	for(int i=0;i<sumatera.size();++i)  
	{
		allLine.push_back(sumatera.at(i));
		//cohen_sutherland(frame, StartX(sumatera.at(i)), StartY(sumatera.at(i)), EndX(sumatera.at(i)), EndY(sumatera.at(i)), 400, 300, 800, 600, color);
		plotLine(frame, sumatera.at(i), color);
	}
	
	for(int i=0;i<jawa.size();++i)
	{
		allLine.push_back(jawa.at(i));
		plotLine(frame, jawa.at(i), color);
		//cohen_sutherland(frame, StartX(jawa.at(i)), StartY(jawa.at(i)), EndX(jawa.at(i)), EndY(jawa.at(i)), 400, 300, 800, 600, rgb(100,100,100));
	}
	for(int i=0;i<kalimantan.size();++i)
	{
		allLine.push_back(kalimantan.at(i));
		//cohen_sutherland(frame, StartX(kalimantan.at(i)), StartY(kalimantan.at(i)), EndX(kalimantan.at(i)), EndY(kalimantan.at(i)), 400, 300, 800, 600, color);
		plotLine(frame, kalimantan.at(i), color);
	}
	for(int i=0;i<sulawesi.size();++i)
	{
		allLine.push_back(sulawesi.at(i));
		//cohen_sutherland(frame, StartX(sulawesi.at(i)), StartY(sulawesi.at(i)), EndX(sulawesi.at(i)), EndY(sulawesi.at(i)), 400, 300, 800, 600, color);
		plotLine(frame, sulawesi.at(i), color);
	}
	for(int i=0;i<papua.size();++i)
	{
		allLine.push_back(papua.at(i));
		plotLine(frame, papua.at(i), color);
	}
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
}
