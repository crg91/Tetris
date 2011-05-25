#ifndef ALPHABETS_H
#define ALPHABETS_H
#include<iostream>
using namespace std;

#include<GL/glut.h>

void drawPoint(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   a=9*a/10; //to enable spacing between two points in the alphabet
   GLfloat b= a/10; //dimension to give curve like feeling at corners
   GLfloat c= a/2-b;

   glPushMatrix(); //save the initial conditions
   glTranslatef(x, y, z); //move the point after drawing at origin

   glBegin(GL_POLYGON);
      glVertex2f(-a/2, -c);
      glVertex2f(-c, -a/2);
      glVertex2f(c, -a/2);
      glVertex2f(a/2, -c);
      glVertex2f(a/2, c);
      glVertex2f(c, a/2);
      glVertex2f(-c, a/2);
      glVertex2f(-a/2, c);
   glEnd();

   glPopMatrix(); //load initial settings
}

void drawA(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix();
   glTranslatef(x, y, z); //translates the whole alphabet

   for(int i=0; i<5; i++) //draws left line of the letter
   {
      drawPoint(-2*a, -3*a + a*i, 0.0, a);
   }

   drawPoint(-a, 2*a, 0.0, a);
   drawPoint(0.0, 3*a, 0.0, a);
   drawPoint(a, 3*a, 0.0, a);

   for(int i=0; i<7; i++)  //draws right line of the letter
   {
      drawPoint(2*a, -3*a+ a*i, 0.0, a);
   }

   for(int i=0; i<3; i++) //draw the horizontal line of the letter
   {
      drawPoint(-a+ a*i, -a, 0.0, a);
   }

   glPopMatrix(); //loads initial settings
}

void drawB(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix(); //saves initial settings
   glTranslatef(x, y, z); //translates the whole letter

   for(int i=0; i<7; i++) //draws left line of the letter
   {
      drawPoint(-2*a, -3*a+ i*a, 0.0, a);
   }

   for(int i=0; i<3; i++) //for switching between different horizontal lines
   {
      for(int j=0; j<3; j++) //for each horizontal line
      {
         drawPoint(-a+ j*a, -3*a+ 3*i*a, 0.0, a);
      }
   }

   drawPoint(2*a, 2*a, 0.0, a);
   drawPoint(2*a, a, 0.0, a);
   drawPoint(2*a, -a, 0.0, a);
   drawPoint(2*a, -2*a, 0.0, a);

   glPopMatrix(); //loads initial settings
}


void drawC(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix(); //loads initial settings
   glTranslatef(x, y, z); //translates the whole alphabet

    for(int i=0; i<5; i++) //draws left line of the letter
   {
      drawPoint(-2*a, -2*a+ i*a, 0.0, a);
   }

   for(int i=0; i<2; i++) //for switching between different horizontal lines
   {
      for(int j=0; j<3; j++) //for each horizontal line
      {
         drawPoint(-a+ j*a, -3*a+ 6*i*a, 0.0, a);
      }
   }

   drawPoint(2*a, -2*a, 0.0, a);
   drawPoint(2*a, 2*a, 0.0, a);

   glPopMatrix(); //loads initial settings
}

void drawD(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix(); //saves initial settings
   glTranslatef(x, y, z); //translates the whole alphabet
   for(int i=0; i<2; i++)
   {
      if(i==0)
         for(int j=0; j<7; j++)
         {
            drawPoint(-2*a, -3*a+ j*a, 0.0, a);
         }
      else
         for(int j=0; j<5; j++)
         {
	    drawPoint(2*a, -2*a+ j*a, 0.0, a);
         }
   }

   drawPoint(-a, 3*a, 0.0, a);
   drawPoint(-a, -3*a, 0.0, a);
   drawPoint(0.0, 3*a, 0.0, a);
   drawPoint(0.0, -3*a, 0.0, a);
   drawPoint(a, 3*a, 0.0, a);
   drawPoint(a, -3*a, 0.0, a);
  
   glPopMatrix(); //loads the initial settings
}

void drawE(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix(); //saves initial settings
   glTranslatef(x, y, z); //translates the whole letter

   for(int i=0; i<2; i++) //draws the top and bottom horizontal lines
   {
      for(int j=0; j<5; j++)
         drawPoint(-2*a+ j*a,-3*a+ 6*i*a, 0.0, a);
   }

   for(int i=0; i<4; i++) //draws the middle horizonatal line
      drawPoint(-2*a+ i*a, 0.0, 0.0, a);

   for(int i=0; i<5; i++) //draws the left vertical line
   {
      if(i==2)
         continue;
      drawPoint(-2*a, -2*a+ i*a, 0.0, a);
   }

   glPopMatrix(); //loads initial settings
}

void drawF(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix();
   glTranslatef(x, y, z);

   for(int i=0; i<2; i++) //draws two horizontal lines
      for(int j=0; j<5; j++)
      {
         if(i==1 && j==4)
            break;
      drawPoint(-2*a+ j*a, 3*a-i*3*a, 0.0, a); 
      }

   for(int i=0; i<6; i++) //draws the left vertical line
   {
      if(i==3)
         continue;
      drawPoint(-2*a, -3*a+ i*a, 0.0, a);
   }

   glPopMatrix(); //loads initial settings
}

void drawG(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix();
   glTranslatef(x, y, z);

   for(int i=0; i<5; i++)
      drawPoint(-2*a, -2*a+ i*a, 0.0, a);

   for(int i=0; i<2; i++)
      for(int j=0; j<3; j++)
         drawPoint(-a+ j*a, -3*a+ 6*i*a, 0.0, a);

   drawPoint(a, -a, 0.0, a);
   drawPoint(2*a, -2*a, 0.0, a);
   drawPoint(2*a, -a, 0.0, a);
   drawPoint(2*a, 2*a, 0.0, a);

   glPopMatrix();
}

void drawH(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix();
   glTranslatef(x, y, z);

   for(int i=0; i<2; i++)
      for(int j=0; j<7; j++)
         drawPoint(-2*a+ 4*i*a, -3*a+ j*a, 0.0, a);

   for(int i=0; i<3; i++)
      drawPoint(-a+ i*a, 0.0, 0.0, a);

   glPopMatrix();
}

void drawI(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix();
   glTranslatef(x, y, z);

   for(int i=0; i<5; i++)
      drawPoint(0.0, -2*a+ i*a, 0.0, a);

   for(int i=0; i<2; i++)
      for(int j=0; j<3; j++)
         drawPoint(-a+ j*a, -3*a+ 6*i*a, 0.0, a);

   glPopMatrix();
}

void drawJ(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix();
   glTranslatef(x, y, z);

   for(int i=0; i<6; i++)
      drawPoint(2*a, -2*a+ i*a, 0.0, a);

   for(int i=0; i<2; i++)
      for(int j=0; j<3; j++)
         drawPoint(-a+ j*a, -3*a+ 6*i*a, 0.0, a);

   drawPoint(-2*a, -2*a, 0.0, a);

   glPopMatrix();
}

void drawK(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix();
   glTranslatef(x, y, z);

   for(int i=0;i<7;i++)
      drawPoint(-2*a, -3*a+ i*a, 0.0, a);

   for(int i=0; i<4; i++)
      drawPoint(-a+i*a, i*a, 0.0, a);

   drawPoint(0.0, -a, 0.0, a);
   drawPoint(a, -2*a, 0.0, a);
   drawPoint(2*a, -3*a, 0.0, a);

   glPopMatrix();
}

void drawL(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix();
   glTranslatef(x, y, z);

   for(int i=0; i<7; i++)
      drawPoint(-2*a, -3*a+ i*a, 0.0, a);

   for(int i=0; i<4; i++)
      drawPoint(-a+i*a, -3*a, 0.0, a);

   glPopMatrix();
}

void drawM(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix();
   glTranslatef(x, y, z);

   for(int i=0; i<2; i++)
      for(int j=0; j<7; j++)
         drawPoint(-2*a+4*i*a, -3*a+ j*a, 0.0, a);

   drawPoint(-a, 2*a, 0.0, a);
   drawPoint(0.0, 0.0, 0.0, a);
   drawPoint(0.0, a, 0.0, a);
   drawPoint(a, 2*a, 0.0, a);

   glPopMatrix();
}

void drawN(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix();
   glTranslatef(x, y, z);

   for(int i=0; i<2; i++)
      for(int j=0; j<7; j++)
         drawPoint(-2*a+4*i*a, -3*a+ j*a, 0.0, a);
   
   drawPoint(-a, a, 0.0, a);
   drawPoint(0.0, 0.0, 0.0, a);
   drawPoint(a, -a, 0.0, a);

   glPopMatrix();
}

void drawO(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix();
   glTranslatef(x, y, z);

   for(int i=0; i<2; i++)
      for(int j=0; j<5; j++)
         drawPoint(-2*a+4*i*a, -2*a+ j*a, 0.0, a);

   for(int i=0; i<2; i++)
      for(int j=0; j<3; j++)
         drawPoint(-a+j*a, -3*a+ 6*i*a, 0.0, a);

   glPopMatrix();
}

void drawP(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix();
   glTranslatef(x, y, z);

   for(int i=0; i<7; i++)
      drawPoint(-2*a, -3*a+i*a, 0.0, a);

    for(int i=0; i<2; i++)
      for(int j=0; j<3; j++)
         drawPoint(-a+j*a, 3*i*a, 0.0, a);
    
   drawPoint(2*a, a, 0.0, a);
   drawPoint(2*a, 2*a, 0.0, a);

   glPopMatrix();
}

void drawQ(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix();
   glTranslatef(x, y, z);

   for(int i=0; i<2; i++)
      for(int j=0; j<3; j++)
         drawPoint(-a+j*a, -2*a+5*i*a, 0.0, a);

   for(int i=0; i<2; i++)
      for(int j=0; j<4; j++)
         drawPoint(-2*a+4*i*a, -a+j*a, 0.0, a);
   drawPoint(2*a, -3*a, 0.0, a);

   glPopMatrix();
}

void drawR(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix();
   glTranslatef(x, y, z);
   for(int i=0; i<7; i++)
      drawPoint(-2*a, -3*a+i*a, 0.0, a);

    for(int i=0; i<2; i++)
      for(int j=0; j<3; j++)
         drawPoint(-a+j*a, 3*i*a, 0.0, a);
    
   drawPoint(2*a, a, 0.0, a);
   drawPoint(2*a, 2*a, 0.0, a);
   drawPoint(0.0, -a, 0.0, a);
   drawPoint(a, -2*a, 0.0, a);
   drawPoint(2*a, -3*a, 0.0, a);

   glPopMatrix();
}

void drawS(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix();
   glTranslatef(x, y, z);

   for(int i=0; i<3; i++)
      for(int j=0; j<3; j++)
         drawPoint(-a+j*a, -3*a+3*i*a, 0.0, a);

   drawPoint(-2*a, -2*a, 0.0, a);
   drawPoint(-2*a, a, 0.0, a);
   drawPoint(-2*a, 2*a, 0.0, a);
   drawPoint(2*a, -2*a, 0.0, a);
   drawPoint(2*a, -a, 0.0, a);
   drawPoint(2*a, 2*a, 0.0, a);

   glPopMatrix();
}

void drawT(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix();
   glTranslatef(x, y, z);

   for(int i=0; i<6; i++)
      drawPoint(0.0, -3*a+i*a, 0.0, a);

   for(int i=0; i<5; i++)
      drawPoint(-2*a+ i*a, 3*a, 0.0, a);

   glPopMatrix();
}

void drawU(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix();
   glTranslatef(x, y, z);

   for(int i=0; i<2; i++)
      for(int j=0; j<6; j++)
         drawPoint(-2*a+4*i*a, -2*a+j*a, 0.0, a);

   for(int i=0; i<3; i++)
      drawPoint(-a+ i*a, -3*a, 0.0, a);

   glPopMatrix();
}

void drawV(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix();
   glTranslatef(x, y, z);

   for(int i=0; i<2; i++)
      for(int j=0; j<5; j++)
         drawPoint(-2*a+4*i*a, -a+j*a, 0.0, a);

   drawPoint(-a, -2*a, 0.0, a);
   drawPoint(a, -2*a, 0.0, a);
   drawPoint(0.0, -3*a, 0.0, a);

   glPopMatrix();
}

void drawW(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix();
   glTranslatef(x, y, z);

   for(int i=0; i<2; i++)
      for(int j=0; j<6; j++)
         drawPoint(-2*a+4*i*a, -2*a+j*a, 0.0, a);

   drawPoint(-a, -3*a, 0.0, a);
   drawPoint(a, -3*a, 0.0, a);
   drawPoint(0.0, -a, 0.0, a);
   drawPoint(0.0, -2*a, 0.0, a);

   glPopMatrix();
}

void drawX(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix();
   glTranslatef(x, y, z);

   for(int i=0; i<5; i++)
      drawPoint(-2*a+ i*a, -2*a+ i*a, 0.0, a);
   for(int i=0; i<5; i++)
      drawPoint(-2*a+ i*a, 2*a-i*a, 0.0, a);

   drawPoint(-2*a, 3*a, 0.0, a);
   drawPoint(-2*a, -3*a, 0.0, a);
   drawPoint(2*a, 3*a, 0.0, a);
   drawPoint(2*a, -3*a, 0.0, a);

   glPopMatrix();
}

void drawY(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix();
   glTranslatef(x, y, z);

   for(int i=0; i<6; i++)
      drawPoint(2*a, -2*a+i*a, 0.0, a);

   for(int i=0; i<2; i++)
      for(int j=0; j<3; j++)
         drawPoint(-a+j*a, -3*a+3*i*a, 0.0, a);

    for(int i=0; i<3; i++)
      drawPoint(-2*a, 3*a-i*a, 0.0, a);

   drawPoint(-2*a, -2*a, 0.0, a);

   glPopMatrix();
}

void drawZ(GLfloat x, GLfloat y, GLfloat z, GLfloat a)
{
   glPushMatrix();
   glTranslatef(x, y, z);

   for(int i=0; i<5; i++)
      drawPoint(-2*a+ i*a, 3*a, 0.0, a);
   for(int i=0; i<5; i++)
      drawPoint(-2*a+ i*a, -3*a, 0.0, a);
   for(int i=0; i<5; i++)
      drawPoint(-2*a+ i*a, -2*a+i*a, 0.0, a);

   glPopMatrix();
}

void writeLetter(char character, GLfloat x, GLfloat y, GLfloat z, GLfloat boxSize)
{
	switch(character)
	{
	case 'A':
		drawA(x, y, z, boxSize);
		break;
	case 'B':
		drawB(x, y, z, boxSize);
		break;
	case 'C':
		drawC(x, y, z, boxSize);
		break;
	case 'D':
		drawD(x, y, z, boxSize);
		break;
	case 'E':
		drawE(x, y, z, boxSize);
		break;
	case 'F':
		drawF(x, y, z, boxSize);
		break;
	case 'G':
		drawG(x, y, z, boxSize);
		break;
	case 'H':
		drawH(x, y, z, boxSize);
		break;
	case 'I':
		drawI(x, y, z, boxSize);
		break;
	case 'J':
		drawJ(x, y, z, boxSize);
		break;
	case 'K':
		drawK(x, y, z, boxSize);
		break;
	case 'L':
		drawL(x, y, z, boxSize);
		break;
	case 'M':
		drawM(x, y, z, boxSize);
		break;
	case 'N':
		drawN(x, y, z, boxSize);
		break;
	case 'O':
		drawO(x, y, z, boxSize);
		break;
	case 'P':
		drawP(x, y, z, boxSize);
		break;
	case 'Q':
		drawQ(x, y, z, boxSize);
		break;
	case 'R':
		drawR(x, y, z, boxSize);
		break;
	case 'S':
		drawS(x, y, z, boxSize);
		break;
	case 'T':
		drawT(x, y, z, boxSize);
		break;
	case 'U':
		drawU(x, y, z, boxSize);
		break;
	case 'V':
		drawV(x, y, z, boxSize);
		break;
	case 'W':
		drawW(x, y, z, boxSize);
		break;
	case 'X':
		drawX(x, y, z, boxSize);
		break;
	case 'Y':
		drawY(x, y, z, boxSize);
		break;
	case 'Z':
		drawZ(x, y, z, boxSize);
		break;
	default:
		break;
	}
}


void drawString(string s, GLfloat x, GLfloat y, GLfloat z, GLfloat boxSize, GLfloat spacing)
{
	for(int i=0; s[i]!=NULL; i++)
	{
		writeLetter(s[i], x+i*spacing, y, z, boxSize);
	}
}

#endif