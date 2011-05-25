#ifndef T_H
#define T_H
#include "Shapes.h"

class T: public Shapes
{
	public:
		T(GLint x= WIDTH/2, GLint y= LENGTH-1)
		:Shapes(x, y)
		{
			setValue(x, y);
		}
		
		void setValue(GLint x= WIDTH/2, GLint y= LENGTH- 1)
		{
			ptr1= new Grid(x, y);
			ptr2= new Grid(x, y-1);
			ptr3= new Grid(x-1, y-1);
			ptr4= new Grid(x+1, y-1);
			position=0;
			for(int i=0; i<=(rand()%4);i++)//for randomization of orientation
				rotate();
		}

		void rotate()
		{
			if(position==0)
			{
				if(ptr2->yValue()>0 && Array[ptr2->xValue()][ptr2->yValue()-1]==0)
				{
					delete ptr3;
					ptr3= new Grid(ptr2->xValue(), ptr2->yValue()-1);
					position=1;
				}
			}

			else if(position==1)
			{
				if(ptr2->xValue()>0 && Array[ptr2->xValue()-1][ptr2->yValue()]==0)
				{
					delete ptr1;
					ptr1= new Grid(ptr2->xValue()-1, ptr2->yValue());
					position=2;
				}
			}
			else if(position==2)
			{
				if(Array[ptr2->xValue()][ptr2->yValue()+1]==0)
				{
					delete ptr4;
					ptr4= new Grid(ptr2->xValue(), ptr2->yValue()+1);
					position=3;
				}
			}
			else
			{
				if(ptr2->xValue()<WIDTH && Array[ptr2->xValue()+1][ptr2->yValue()]==0)
				{
					delete ptr4;
					ptr4= new Grid(ptr2->xValue()+1, ptr2->yValue());
					delete ptr1;
					ptr1= new Grid(ptr2->xValue(), ptr2->yValue()+1);
					delete ptr3;
					ptr3= new Grid(ptr2->xValue()-1, ptr2->yValue());
					position=0;
				}
			}
		}



};

#endif