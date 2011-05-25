#ifndef SHAPES_H
#define SHAPES_H
#include "Grid.cpp"
#include "utilityFunctions.h"
bool change=0;
class Shapes
{
	protected:
		Grid* ptr1;
		Grid* ptr2;
		Grid* ptr3;
		Grid* ptr4;
		int position; //keep track of orientation
		
	public:
		Shapes(GLint x= WIDTH/2, GLint y= LENGTH-1)
		{
			setValue(x, y);
			position=0;
		}
		virtual void setValue(GLint= WIDTH/2, GLint= LENGTH-1)=0;
		void translateLeft();
		void translateRight();
		void moveDown();
		void draw();
		virtual void rotate()=0;
		int getPosition();
		void setPosition(int);
};

void Shapes::setValue(GLint x, GLint y)
		{
			ptr1= new Grid(x, y);
			ptr2= new Grid(x+ 1, y);
			ptr3= new Grid(x+ 1, y-1);
			ptr4= new Grid(x, y-1);
		}
void Shapes::translateLeft()
{
	if(ptr1->canTranslateLeft() && ptr2->canTranslateLeft() && ptr3->canTranslateLeft() && ptr4->canTranslateLeft())
	{
		ptr1->translateLeft();
		ptr2->translateLeft();
		ptr3->translateLeft();
		ptr4->translateLeft();
	}
}

void Shapes::translateRight()
{
	if(ptr1->canTranslateRight() && ptr2->canTranslateRight() && ptr3->canTranslateRight() && ptr4->canTranslateRight() )
	{
		ptr1->translateRight();
		ptr2->translateRight();
		ptr3->translateRight();
		ptr4->translateRight();
	}
}

void Shapes::moveDown()
{
	if(ptr1->canMoveDown() && ptr2->canMoveDown() && ptr3->canMoveDown() && ptr4->canMoveDown() )
	{
		ptr1->moveDown();
		ptr2->moveDown();
		ptr3->moveDown();
		ptr4->moveDown();
	}
	
	else if(!ptr1->ifStatic() && !ptr2->ifStatic() && !ptr3->ifStatic() && !ptr4->ifStatic() )
		{
			ptr1->makeStatic();
			ptr2->makeStatic();
			ptr3->makeStatic();
			ptr4->makeStatic();

			delete ptr1;
			delete ptr2;
			delete ptr3;
			delete ptr4;
		
			change=1;
			rearrange();
			setValue();
		}
}

void Shapes::draw()
{
	for(int i=0; i<=WIDTH; i++)
	{
		for(int j=0; j<LENGTH; j++)
		{
			if(Array[i][j]==1)
			   drawGrid(i, j);
		}
	}

	ptr1->draw();
	ptr2->draw();
	ptr3->draw();
	ptr4->draw();
}

int Shapes::getPosition()
{
	return position;
}

void Shapes::setPosition(int a)
{
	position=a;
}
#endif