#ifndef DRAWING_H
#define DRAWING_H

#include "rotasi.h"
#include "plotting.h"
#include "allstruct.h"
#include <vector>

void drawPeta(Frame *frame, Coord center, RGB color);
void drawKapal(Frame *frm, Coord loc, RGB color);
void drawBaling(Frame *frm , Coord loc,int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4 ,RGB color);
void rotateBaling(Frame *frm,Coord loc, RGB col ,int counter );

#endif
