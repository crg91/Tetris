#ifndef SQUARE1_H
#define SQUARE1_H
#include "Shapes.h"

class Square: public Shapes
{
	public:
		Square(GLint x= WIDTH/2, GLint y= LENGTH- 1)
		:Shapes(x, y)
		{}
	
		void setValue(GLint x= WIDTH/2, GLint y= LENGTH-1)
		{
			ptr1= new Grid(x, y);
			ptr2= new Grid(x+ 1, y);
			ptr3= new Grid(x+ 1, y-1);
			ptr4= new Grid(x, y-1);
		}

		void rotate()
		{
		}
};
#endif