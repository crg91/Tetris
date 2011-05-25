#ifndef UTILITYFUNCTIONS_H
#define UTILITYFUNCTIONS_H
#include "numbers.h"
int score=0;
int scoreOld= score;
int LEVEL= 4;
void drawGrid(int i, int j)
{
	glColor3f(0.0, 1.0, 0.0);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glBegin(GL_QUADS);
			glVertex2f(i- 0.5, j- 0.5);
			glVertex2f(i+ 0.5, j- 0.5);
			glVertex2f(i+ 0.5, j+ 0.5);
			glVertex2f(i- 0.5, j+ 0.5);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glBegin(GL_QUADS);
			glVertex2f(i- 0.5, j- 0.5);
			glVertex2f(i+ 0.5, j- 0.5);
			glVertex2f(i+ 0.5, j+ 0.5);
			glVertex2f(i- 0.5, j+ 0.5);
		glEnd();
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}
	
bool checkRow(int row)
{
	for(int i=0; i<= WIDTH; i++)
		if(Array[i][row]==0)
			return false;
		
	score= score+ 5;
	if(scoreOld==score-15 && LEVEL<9)
		{
			scoreOld=score;
			LEVEL++;
		}
	return true;
}
void shift(int row)
{
	for(int i= row; i<=LENGTH-1; i++)
	{
		for(int j=0; j<= WIDTH; j++)
		{
			Array[j][i]= Array[j][i+1];
		}
	}
}
	
void rearrange()
{
	for(int i=0; i<= LENGTH-1; i++)
	{
		if(checkRow(i))
		{
			shift(i);
			i=i-1;
		}
	}
}

void drawSingleDigiNumber(GLint value, GLfloat x,GLfloat y,GLfloat length )
{
	switch(value)
	{
	case 0:
		drawZero(x, y, 0.0, length);
		break;
	case 1:
		drawOne(x, y, 0.0, length);
		break;
	case 2:
		drawTwo(x, y, 0.0, length);
		break;
	case 3:
		drawThree(x, y, 0.0, length);
		break;
	case 4:
		drawFour(x, y, 0.0, length);
		break;
	case 5:
		drawFive(x, y, 0.0, length);
		break;
	case 6:
		drawSix(x, y, 0.0, length);
		break;
	case 7:
		drawSeven(x, y, 0.0, length);
		break;
	case 8:
		drawEight(x, y, 0.0, length);
		break;
	case 9:
		drawNine(x, y, 0.0, length);
		break;
	default:
		break;
	}
}
void drawFourDigiNumber(GLint value, GLfloat x, GLfloat y, GLfloat length)
{
	int d1, d2, d3, d4;
	d4=value%10;
	value= value/10;
	d3=value%10;
	value= value/10;
	d2=value%10;
	value= value/10;
	d1= value%10;
	drawSingleDigiNumber(d1, x, y, length);
	drawSingleDigiNumber(d2, x + 2*length, y, length);
	drawSingleDigiNumber(d3, x + 4*length, y, length);
	drawSingleDigiNumber(d4, x + 6*length, y, length);
}

#endif