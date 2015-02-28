#ifndef CLIP_H
#define CLIP_H

typedef int OutCode;
 
const int INSIDE = 0; // 0000
const int LEFT = 1;   // 0001
const int RIGHT = 2;  // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8;    // 1000

OutCode ComputeOutCode(double x, double y);
void CohenSutherlandLineClipAndDraw(double x0, double y0, double x1, double y1);

#endif
