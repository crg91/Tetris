#ifndef GRID_H
#define GRID_H
#include<GL/glut.h>
#include<stdlib.h> //for enabling srand function
#include<ctime>
const int WIDTH = 14;
const int LENGTH = 31;

bool Array[WIDTH+ 1][LENGTH+ 1]={};

class Grid
{
	public:
		Grid(GLint x=0, GLint y=0)
		{
			isStatic= 0;
			centre[0]= x;
			centre[1]= y;
		}
		
		void draw();
		void translateRight();
		bool canTranslateRight();
		void translateLeft();
		bool canTranslateLeft();
		void moveDown();
		bool canMoveDown();
		bool ifStatic();
		void makeStatic();
		GLint xValue();
		GLint yValue();
	private:
		GLint centre[2];
		bool isStatic;
};
#endif