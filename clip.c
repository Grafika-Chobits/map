#include "clip.h"

Line line(int x1, int y1, int x2, int y2)
{
	Line line1;
	line1.P1.x = x1;
	line1.P1.y = y1;
	line1.P2.x = x2;
	line1.P2.y = y2;
	return line1;
}

//xmin = sisi kiri dari clip
//ymin = sisi bawah dari clip
//xmax = sisi kanan dari clip
//ymax = sisi atas dari clip

outcode compute(int x, int y , int xmax, int ymax, int xmin, int ymin)
{
	outcode oc=0;
	if(x<xmin)
		oc|=LEFT;
	else if(x>xmax)
		oc|=RIGHT;
	
	if(y<ymax)
		oc|=TOP;
	else if(y>ymin)
		oc|=BOTTOM;

	return oc;
}

Line cohen_sutherland(int x1,int y1,int x2,int y2, int xmin,int ymin, int xmax, int ymax)
{
	bool accept = false, done=false;double m;
	outcode o1,o2,ot;
	o1=compute(x1,y1,xmax,ymax,xmin,ymin);
	o2=compute(x2,y2,xmax,ymax,xmin,ymin);
	do{

		if(!(o1 | o2))
		{
			done=true;
			accept=true;
		}
		else if(o1&o2)
		{
			done=true;
		}
		else
		{
			int x,y;
			ot=o1?o1:o2;
			if(ot & TOP)			// point is above the clip rectangle
			{
				//~ y=ymax;
				//~ x = x1 + (x2-x1)*(ymax-y1)/(y2-y1); 
				y=ymin;
				x = x1 + (x2-x1) * (ymin - y1) / (y2-y1);
			} 
			else if(ot & BOTTOM) 	// point is below the clip rectangle
			{
				//~ y=ymin;
				//~ x = x1 + (x2 - x1) * (ymin - y1) / (y2 - y1);
				y=ymax;
				x = x1 + (x2 - x1) * (ymax - y1) / (y2-y1);
			}
			else if(ot & RIGHT)		// point is to the right of clip rectangle
			{
				x=xmax;
				y = y1 + (y2 - y1) * (xmax - x1) / (x2 - x1);
			}
			else if(ot & LEFT)		// point is to the left of clip rectangle
			{
				x=xmin;
				y = y1 + (y2 - y1) * (xmin - x1) / (x2 - x1);

			}
			if(ot==o1)
			{
				x1=x;
				y1=y;
				o1=compute(x1,y1,xmax,ymax,xmin,ymin);
			}
			else
			{
				x2=x;
				y2=y;
				o2=compute(x2,y2,xmax,ymax,xmin,ymin);
			}
		}
	}while(done==false);

	if(accept==true)
	{
		//printf("Point 1 = (%d, %d)\n",x1, y1);
		//printf("Point 2 = (%d, %d)\n",x2, y2);
		return line(x1,y1,x2,y2);
	}
	return line(0,0,0,0);
}
