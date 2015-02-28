#ifndef CLIP_H
#define CLIP_H

//http://electrofriends.com/source-codes/software-programs/c/graphics/c-program-to-implement-the-cohen-sutherland-line-clipping-algorithm/

#include <stdio.h>
const int TOP=8,BOTTOM=4,RIGHT=2,LEFT=1;

typedef int outcode;

typedef struct s_coord {
	int x;
	int y;
} Coord;

typedef struct s_line{
	Coord P1;
	Coord P2;
} Line;

Line line(int x1, int y1, int x2, int y2);

outcode compute(int x, int y , int xmax, int ymax, int xmin, int ymin);
		
Line cohen_sutherland (int x1,int y1,int x2,int y2, int xmin,int ymin, int xmax, int ymax);

#endif
