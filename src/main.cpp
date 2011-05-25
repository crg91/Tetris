#include "T.h"
#include "Square.h"
#include "N.h"
#include "mirrorN.h"
#include "L.h"
#include "mirrorL.h"
#include "Line.h"
#include "alphabets.h"
#include "numbers.h"
#include<ctime>
#include<cmath>
enum Status{CONTINUE, OVER, PAUSED};
Status gameStatus=CONTINUE;
void init()
{
	srand(time(0));
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
}
	int choiceNext= rand()%7;
	int choice = rand()%7;


	Square s1(7,30);
	Line l1(7,30);
	N n1(7,30);
	mirrorN mn1(7,30);
	L ll1(7,30);
	mirrorL mll1(7,30);
	T t1(7,30);

	Square s1Next(21,14);
	Line l1Next(21,14);
	N n1Next(21,14);
	mirrorN mn1Next(21,14);
	L ll1Next(21,14);
	mirrorL mll1Next(21,14);
	T t1Next(21,14);

	double storeTime=clock();


void resetAllPosition()//on pressing r, setting position default
{
	s1.setValue();
	l1.setValue();
	n1.setValue();
	mn1.setValue();
	ll1.setValue();
	mll1.setValue();
	t1.setValue();
}

void moveDown()//to move down the current object
{
	switch(choice)
	{
	case 0:
		s1.moveDown();
		break;
	case 1:
		l1.moveDown();
		break;
	case 2:
		n1.moveDown();
		break;
	case 3:
		mn1.moveDown();
		break;
	case 4:
		ll1.moveDown();
		break;
	case 5:
		mll1.moveDown();
		break;
	case 6:
		t1.moveDown();
		break;
	default:
		break;
	}
		if(change==1)
		{
			if(Array[WIDTH/2][LENGTH-1]==1)
				gameStatus=OVER;
			else
			{
				choice=choiceNext;
				choiceNext= rand()%7;
				change=0;
			}
		}
		
}

void drawStar(float fX, float fY) {
	const float kfPi = 3.1415926535897932384626433832795;
	// Draw ten triangles
	const float kfRadius = 0.5;
	const float kfInnerRadius = kfRadius*(1.0/(sin((2.0*kfPi)/5.0)*2.0*cos(kfPi/10.0) + sin((3.0*kfPi)/10.0)));
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(fX, fY, 0.0);
		for (int iVertIndex = 0; iVertIndex < 10; ++iVertIndex) {
			float fAngleStart	= kfPi/2.0 + (iVertIndex*2.0*kfPi)/10.0;
			float fAngleEnd		= fAngleStart + kfPi/5.0;
			if (iVertIndex % 2 == 0) {
				glVertex3f(fX + kfRadius*cos(fAngleStart), fY + kfRadius*sin(fAngleStart), 0.0);
				glVertex3f(fX + kfInnerRadius*cos(fAngleEnd), fY + kfInnerRadius*sin(fAngleEnd), 0.0);
			} else {
				glVertex3f(fX + kfInnerRadius*cos(fAngleStart), fY + kfInnerRadius*sin(fAngleStart), 0.0);
				glVertex3f(fX + kfRadius*cos(fAngleEnd), fY + kfRadius*sin(fAngleEnd), 0.0);
			}
		}
	glEnd();
}

void drawStars()
{
	drawStar(2, 28);
	drawStar(8, 20);
	drawStar(10,26);
	drawStar(4,22);
	drawStar(7, 15);
	drawStar(13, 18);
}

void background()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);
		glVertex3f(14.5, -0.5, 0.0);
		glVertex3f(15.0, -0.5, 0.0);
		glVertex3f(15.0, 30.5, 0.0);
		glVertex3f(14.5, 30.5, 0.0);
	glEnd();
    drawStars();
	glColor3f(1.0, 0.0, 0.0);
	drawString("CRG", 18.0, 28.0, 0.0, 0.4, 3.0);
	drawString("SCORE", 18.0, 25.0, 0.0, 0.2, 1.5);
	drawString("UP NEXT", 16.8, 17.0, 0.0, 0.2, 1.5);
	drawFourDigiNumber(score, 18.0, 22.0, 1.0);
	drawString("LEVEL", 17.0, 8, 0.0, 0.2, 1.5);
	drawSingleDigiNumber(LEVEL, 25, 8, 1);
}

void display()
{
	background();
	glColor3f(1.0, 1.0, 1.0);

	switch(choice)
	{
	case 0:
		s1.draw();
		break;
	case 1:
		l1.draw();
		break;
	case 2:
		n1.draw();
		break;
	case 3:
		mn1.draw();
		break;
	case 4:
		ll1.draw();
		break;
	case 5:
		mll1.draw();
		break;
	case 6:
		t1.draw();
		break;
	default:
		break;
	}
	

	if(gameStatus!=OVER)
	{
	switch(choiceNext)
	{
	case 0:
		s1Next.draw();
		break;
	case 1:
		l1Next.draw();
		break;
	case 2:
		n1Next.draw();
		break;
	case 3:
		mn1Next.draw();
		break;
	case 4:
		ll1Next.draw();
		break;
	case 5:
		mll1Next.draw();
		break;
	case 6:
		t1Next.draw();
		break;
	default:
		break;
	}
	}
	
	if(gameStatus==OVER)
	{
		glColor3f(1.0, 0.0, 0.0);
		drawString("GAME OVER", 1, 15, 0.0, 0.25, 1.5);

	}
	if(gameStatus==PAUSED)
	{
		drawString("PAUSED", 3, 15, 0.0, 0.25, 1.5);
	}
		glFlush();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-0.5, 27.5, -0.5, 30.5);
	glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
	case 'p':
		if(gameStatus==CONTINUE)
		{
			gameStatus=PAUSED;
			glutPostRedisplay();
		    break;
		}
		if(gameStatus==PAUSED)
		{
			gameStatus=CONTINUE;
			glutPostRedisplay();
			break;
		}
	case 'r':
		score=0;
		scoreOld=score;
		LEVEL=1;
		for(int i=0; i<= WIDTH; i++)
		{
			for(int j=0; j<=LENGTH; j++)
			{
				Array[i][j]=0;
			}
		}
		choice=rand()%7;
		choiceNext= rand()%7;
		change=0;
		resetAllPosition();
		glutPostRedisplay();
		break;
	default:
		break;
	}
}
void special(int key, int x, int y)
{
	if(gameStatus==CONTINUE)
	{
	switch(key)
	{
	case GLUT_KEY_LEFT:
		switch(choice)
	{
	case 0:
		s1.translateLeft();
		break;
	case 1:
		l1.translateLeft();
		break;
	case 2:
		n1.translateLeft();
		break;
	case 3:
		mn1.translateLeft();
		break;
	case 4:
		ll1.translateLeft();
		break;
	case 5:
		mll1.translateLeft();
		break;
	case 6:
		t1.translateLeft();
		break;
	default:
		break;
	}
		glutPostRedisplay();
		break;
	case GLUT_KEY_RIGHT:
		switch(choice)
	{
	case 0:
		s1.translateRight();
		break;
	case 1:
		l1.translateRight();
		break;
	case 2:
		n1.translateRight();
		break;
	case 3:
		mn1.translateRight();
		break;
	case 4:
		ll1.translateRight();
		break;
	case 5:
		mll1.translateRight();
		break;
	case 6:
		t1.translateRight();
		break;
	default:
		break;
		}
		glutPostRedisplay();
		break;
	case GLUT_KEY_DOWN:
		moveDown();
		storeTime=clock();
		glutPostRedisplay();
		break;
	case GLUT_KEY_UP:
		switch(choice)
	{
	case 0:
		s1.rotate();
		break;
	case 1:
		l1.rotate();
		break;
	case 2:
		n1.rotate();
		break;
	case 3:
		mn1.rotate();
		break;
	case 4:
		ll1.rotate();
		break;
	case 5:
		mll1.rotate();
		break;
	case 6:
		t1.rotate();
		break;
	default:
		break;
	}
		glutPostRedisplay();
		break;
	default:
		break;
	}
	}
}

void gravity()
{
	if(storeTime<clock()-100 && gameStatus==CONTINUE)
	{
		moveDown();
		glutPostRedisplay();
		storeTime=clock();
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(280*2, 310*2);
	glutInitWindowPosition(50, 50);
	glutCreateWindow(">>crg<<");
	
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutSpecialFunc(special);
	glutKeyboardFunc(keyboard);
	glutIdleFunc(gravity);
	glutMainLoop();
	
	return 0;
}
