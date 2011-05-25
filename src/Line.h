#ifndef LINE_H
#define LINE_H
#include "Shapes.h"

class Line: public Shapes
{
	public:
		Line(GLint x= WIDTH/2, GLint y= LENGTH-1)
		:Shapes(x, y)
		{
			setValue(x, y);
		}
		
		void setValue(GLint x= WIDTH/2, GLint y= LENGTH-1)
		{
			ptr1= new Grid(x, y);
			ptr2= new Grid(x, y-1);
			ptr3= new Grid(x, y-2);
			ptr4= new Grid(x, y-3);
			position=0;
			for(int i=0;i<=(rand()%2);i++)
				rotate();
		}

		void rotate()
		{
			if(position==0)
			{
				if(ptr2->xValue()>0 && ptr2->xValue()<=WIDTH-2&& Array[ptr2->xValue()-1][ptr2->yValue()]==0 && Array[ptr2->xValue()+1][ptr2->yValue()]==0 && Array[ptr2->xValue()+2][ptr2->yValue()]==0)
				{
				Grid* temp= ptr1;
				ptr1= new Grid(temp->xValue()-1, temp->yValue()-1);
				delete temp;
				temp= ptr3;
				ptr3= new Grid(temp->xValue()+1, temp->yValue()+1);
				delete temp;
				temp= ptr4;
				ptr4= new Grid(temp->xValue()+2, temp->yValue()+2);
				delete temp;
				position=1;
				}
			}
			else
			{
				if(ptr2->yValue()>=2 && Array[ptr2->xValue()][ptr2->yValue()+1]==0 && Array[ptr2->xValue()][ptr2->yValue()-1]==0 && Array[ptr2->xValue()][ptr2->yValue()-2]==0)
				{
					Grid* temp= ptr1;
					ptr1= new Grid(temp->xValue()+1, temp->yValue()+1);
					delete temp;
					temp= ptr3;
					ptr3= new Grid(temp->xValue()-1, temp->yValue()-1);
					delete temp;
					temp= ptr4;
					ptr4= new Grid(temp->xValue()-2, temp->yValue()-2);
					delete temp;
					position=0;
				}
			}
		}
};

#endif