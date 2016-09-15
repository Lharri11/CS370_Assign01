// CS370 - Fall 2016
// Assign01 - DonQuixote

#ifdef OSX
	#include <GLUT/glut.h>
#else
	#include <GL/glut.h>
#endif
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>

#define DEG2RAD 0.017453

// Instance square - DO NOT MODIFY
GLfloat sqr[4][2] = {{1.0f,1.0f},{-1.0f,1.0f},{-1.0f,-1.0f},{1.0f,-1.0f}};

// Grass global variables
GLfloat grassClr[3] = { 0.0f, 0.5f, 0.1f };
GLfloat grassClr2[3] = { 0.0f, 0.9f, 0.0f };
GLfloat grassScale = 0.5;
// Sky global variables
GLfloat skyClr_B[3] = { 0.0f, 0.0f, 1.0f };
GLfloat skyClr_W[3] = { 1.0f, 1.0f, 1.0f };
GLfloat skyScale = 0.75;
// Sun global variables
GLfloat sunClr_Y[3] = { 1.0f, 1.0f, 0.5f };
GLfloat sunScale = 0.2;
GLfloat sunPos = 0.5;
// House global variables
GLfloat houseClr_B[3] = { 0.5f, 0.2f, 0.0f };
GLfloat houseClr_R[3] = { 1.0f, 0.0f, 0.0f };
GLfloat houseScale = 0.25;
// Fan global variables
GLfloat fanClr[3] = { 0.0f, 1.0f, 1.0f };



void display();
void render_Scene();
void keyfunc(unsigned char key, int x, int y);
void idlefunc();

int main(int argc, char* argv[])
{
	// Initialize GLUT
	glutInit(&argc, argv);

	// Initialize the window with double buffering and RGB colors
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	// Set the window size to 500x500 pixels
	glutInitWindowSize(500, 500);

	// Create window
	glutCreateWindow("Don Quixote");

	// Define callbacks
	glutDisplayFunc(display);

	// Set background color to white
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	// Begin event loop
	glutMainLoop();

	return 0;
}

// Display callback
void display()
{
	// Reset background
	glClear(GL_COLOR_BUFFER_BIT);

	// Render scene
	render_Scene();
		
	// Flush buffer
	glFlush();
	
	// Swap buffers
	glutSwapBuffers();
}

// Scene render function
void render_Scene()
{
	//Drawn: Sky, grass, and house
	glBegin(GL_QUADS);
		//Blue sky
		glColor3fv(skyClr_B);
		glVertex2fv(sqr[1]);
		glVertex2fv(sqr[0]);
		glColor3fv(skyClr_W);
		glVertex2f(sqr[3][0],sqr[3][1]*skyScale);
		glVertex2f(sqr[2][0], sqr[2][1]*skyScale);
		
		//Green grass
		glColor3fv(grassClr);
		glVertex2f(sqr[2][0], sqr[2][1]*grassScale);
		glVertex2f(sqr[3][0], sqr[3][1]*grassScale);
		glColor3fv(grassClr2);
		glVertex2fv(sqr[3]);
		glVertex2fv(sqr[2]);

		//Brown house
		glColor3fv(houseClr_B);
		glVertex2f(sqr[2][0] * houseScale, sqr[2][1] * houseScale);
		glVertex2f(sqr[3][0] * houseScale, sqr[3][1] * houseScale);
		glVertex2f(sqr[3][0] * houseScale, sqr[3][1] * (houseScale * 3));
		glVertex2f(sqr[2][0] * houseScale, sqr[2][1] * (houseScale * 3));
	glEnd();

	//Drawn: Roof and fan blades
	glBegin(GL_TRIANGLES);
		//Red roof
		glColor3fv(houseClr_R);
		glVertex2f(0.0, 0.15);
		glVertex2f(0.25, -0.25);
		glVertex2f(-0.25, -0.25);

		//Light blue fan blades (CCW)
		//Blade1
		glColor3fv(fanClr);
		glVertex2f(0.0, 0.15);
		glVertex2f(-0.15, 0.25);
		glVertex2f(-0.075, 0.30);
		//Blade2
		glColor3fv(fanClr);
		glVertex2f(0.0, 0.15);
		glVertex2f(0.15, 0.225);
		glVertex2f(0.17, 0.14);
		//Blade3
		glColor3fv(fanClr);
		glVertex2f(0.0, 0.15);
		glVertex2f(-0.02, -0.025);
		glVertex2f(-0.1, 0.010);
	glEnd();

	//Drawn: Sun
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i <= 100; i++) {
		double angle =  2* M_PI * i / 100;
		double x = cos(angle);
		double y = sin(angle);
		
		glColor3fv(sunClr_Y);
		glVertex2f(((x*sunScale)-sunPos), ((y*sunScale)+sunPos));
	}
	glEnd();
}

// Keyboard callback
void keyfunc(unsigned char key, int x, int y)
{
	// Quit with escape
	if (key == 27)
	{
		exit(0);
	}

	if(key == 32)
	{
		glClearColor(0.0f, 0.0f, 0.2f, 0.5f);
		glutPostRedisplay();
	}
}

// Idle callback
void idlefunc()
{

}