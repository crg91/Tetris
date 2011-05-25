#ifndef GRIDS_H
#define GRIDS_H
#include "Grid.cpp"

void drawGrid(int i, int j)
{
	glColor3f(1.0, 1.0, 1.0);
		
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_QUADS);
		glVertex2f(i- 0.5, j- 0.5);
		glVertex2f(i+ 0.5, j- 0.5);
		glVertex2f(i+ 0.5, j+ 0.5);
		glVertex2f(i- 0.5, j+ 0.5);
	glEnd();
}
	
bool checkRow(int row)
{
	for(int i=0; i<= WIDTH; i++)
		if(Array[i][row]==0)
			return false;
		
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

	
class Grids
{
	private:
		Grid* ptr;
	public:
		Grids(GLint x=7, GLint y=30)
		{
		    if(Array[x][y]==0)
			{
				ptr= new Grid(x, y);
			}
		}
		
		void draw()
		{
			for(int i=0; i<=WIDTH; i++)
			{
				for(int j=0; j<LENGTH; j++)
				{
					if(Array[i][j]==1)
					   drawGrid(i, j);
				}
			}

			ptr->draw();
		}
		
		void translateRight()
		{
			ptr->translateRight();
		}
		
		void translateLeft()
		{
			ptr->translateLeft();
		}
		
		void moveDown()
		{
			ptr->moveDown();
			if(ptr->ifStatic())
			{
				rearrange();
				ptr= new Grid(7, 30);
			}
		}
};
#endif