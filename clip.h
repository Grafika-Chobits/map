#ifndef CLIP_H
#define CLIP_H

//http://electrofriends.com/source-codes/software-programs/c/graphics/c-program-to-implement-the-cohen-sutherland-line-clipping-algorithm/

#include <stdio.h>
#include "allstruct.h"
#include "drawing.h"

const int TOP=8,BOTTOM=4,RIGHT=2,LEFT=1;

typedef int outcode;

Line line(int x1, int y1, int x2, int y2);

outcode compute(int x, int y , int xmax, int ymax, int xmin, int ymin);
		
void cohen_sutherland (Frame *frm, int x1,int y1,int x2,int y2, int xmin,int ymin, int xmax, int ymax, RGB color);

void cohen_sutherland (int x1,int y1,int x2,int y2, int xmin,int ymin, int xmax, int ymax);
#endif
