#ifndef GRID1_CPP
#define GRID1_CPP
#include<iostream>
using namespace std;
#include "Grid.h"
    void Grid::draw()
	{
		
		
		

		glColor3f(0.0, 1.0, 0.0);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glBegin(GL_QUADS);
			glVertex2f(centre[0]- 0.5, centre[1]- 0.5);
			glVertex2f(centre[0]+ 0.5, centre[1]- 0.5);
			glVertex2f(centre[0]+ 0.5, centre[1]+ 0.5);
			glVertex2f(centre[0]- 0.5, centre[1]+ 0.5);
		glEnd();

		glColor3f(0.0, 0.0, 0.0);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glBegin(GL_QUADS);
			glVertex2f(centre[0]- 0.5, centre[1]- 0.5);
			glVertex2f(centre[0]+ 0.5, centre[1]- 0.5);
			glVertex2f(centre[0]+ 0.5, centre[1]+ 0.5);
			glVertex2f(centre[0]- 0.5, centre[1]+ 0.5);
		glEnd();
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	}
		
	void Grid::translateRight()
	{
		if(Array[centre[0]+ 1][centre[1]]==0 && centre[0]<WIDTH)
			centre[0] = centre[0]+ 1;
		//play sound here
	}

	bool Grid::canTranslateRight()
	{
		if(Array[centre[0]+ 1][centre[1]]==0 && centre[0]< WIDTH)
			return true;
		
		return false;
	}
	
	void Grid::translateLeft()
	{
			if(centre[0]!=0)
			{
				if(Array[centre[0]- 1][centre[1]]== 0)
					centre[0] = centre[0]-1;
			}
		//play sound
	}
	
	bool Grid::canTranslateLeft()
	{
			if(centre[0]!=0)
				if(Array[centre[0]- 1][centre[1]]==0)
					return true;
		return false;
	}
	
	void Grid::moveDown()
	{
			if(Array[centre[0]][centre[1]- 1]== 0 && centre[1]> 0)
			{
				centre[1] =centre[1]- 1;
			}
			else if(Array[centre[0]][centre[1]- 1]==1 || centre[1]==0)
			{
				isStatic=1;
				Array[centre[0]][centre[1]]=1;
			}
	}
	
	bool Grid::canMoveDown()
	{
			if(Array[centre[0]][centre[1]- 1]== 0 && centre[1]> 0)
				return true;
		return false;
	}
	
	bool Grid::ifStatic()
	{
		return isStatic;
	}

	void Grid::makeStatic()
	{
		isStatic=1;
		Array[centre[0]][centre[1]]=1;
	}

	GLint Grid::xValue()
	{
		return centre[0];
	}

	GLint Grid::yValue()
	{
		return centre[1];
	}
#endif