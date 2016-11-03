#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>

using namespace std;

//Called when a key is pressed
void handleKeypress(unsigned char key, //The key that was pressed
	int x, int y) {    //The current mouse coordinates
	switch (key) {
	case 27: //Escape key
		exit(0); //Exit the program
	}
}

//Initializes 3D rendering
void initRendering() {
	//Makes 3D drawing work when something is in front of something else
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	//Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective

	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

GLfloat angle1 = 0, angle2 = 360;
GLfloat scale = 0;
GLint counter = 0;

void drawTriangles(float a, float b, float c, float d, float red = 1.0, float green = 1.0, float blue = 1.0)
{
	glBegin(GL_TRIANGLES);
		glColor3f(red, green, blue);
		glVertex3f(a, b, -20.0f);
		glVertex3f(c, b, -20.0f);
		glVertex3f(a, d, -20.0f);
	glEnd();
}

void rotateTriangle(GLfloat angle, float around_x, float around_y, float move_me_about_x, float move_me_about_y )
{
	glTranslatef(around_x, around_y, 0);
	glTranslatef(move_me_about_x + around_x, move_me_about_y + around_y, 0);
	//glRotatef(angle, 0.0, 0.0, 1.0);
	glTranslatef(-move_me_about_x - around_x, -move_me_about_y - around_y, 0);
}

void drawOneTriangle(GLfloat angle, float around_x, float around_y, float move_me_about_x, float move_me_about_y, float a, float b, float c, float d, float red = 1.0, float green = 1.0, float blue = 1.0)
{
	GLfloat x_avg, y_avg;
	x_avg = (2 * a + c) / 3;
	y_avg = (2 * b + d) / 3;
	glPushMatrix();
		rotateTriangle(1.5*angle, around_x, around_y, x_avg, y_avg);
		drawTriangles(a, b, c, d, red, green, blue);
	glPopMatrix();
}

void drawScene() {

	//Clear information from last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective

	glPushMatrix();
		//rotateTriangle(-angle2, 0, 0, 0, 0);
		drawOneTriangle(angle1, scale, scale, 0.5, 0.5, 0, 0, 1, 1, 0, 0, 1);
		drawOneTriangle(angle1, -scale, scale, -0.5, 0.5, 0, 0, -1, 1, 0, 0, 1);
		drawOneTriangle(angle1, scale, -scale, 0.5, -0.5, 0, 0, 1, -1, 0, 0, 1);
		drawOneTriangle(angle1, -scale, -scale, -0.5, -0.5, 0, 0, -1, -1, 0, 0, 1);

		drawOneTriangle(-angle1, 2 * scale * 0.5, 2 * scale, 0.5, 1.5, 0, 1, 1, 2, 0, 1, 0);
		drawOneTriangle(-angle1, 2 * scale, 2 * scale * 0.5, 1.5, 0.5, 1, 0, 2, 1, 1, 0.7, 0);
		drawOneTriangle(-angle1, 2 * scale, -2 * scale * 0.5, 1.5, -0.5, 1, 0, 2, -1, 0, 1, 0);
		drawOneTriangle(-angle1, 2 * scale * 0.5, -2 * scale, 0.5, -1.5, 0, -1, 1, -2, 1, 0.7, 0);
		drawOneTriangle(-angle1, -2 * scale * 0.5, -2 * scale, -0.5, -1.5, 0, -1, -1, -2, 0, 1, 0);
		drawOneTriangle(-angle1, -2 * scale, -2 * scale * 0.5, -1.5, -0.5, -1, 0, -2, -1, 1, 0.7, 0);
		drawOneTriangle(-angle1, -2 * scale, 2 * scale * 0.5, -1.5, 0.5, -1, 0, -2, 1, 0, 1, 0);
		drawOneTriangle(-angle1, -2 * scale * 0.5, 2 * scale, -0.5, 1.5, 0, 1, -1, 2, 1, 0.7, 0);
	glPopMatrix();

	glPushMatrix();
		//rotateTriangle(1.5*angle2, 0, 0, 0, 0);
		drawOneTriangle(angle1, 3 * scale * 1 / 3, 3 * scale, 0.5, 2.5, 0, 2, 1, 3, 1, 0, 0);
		drawOneTriangle(angle1, 3 * scale * 2 / 3, 3 * scale * 2 / 3, 1.5, 1.5, 1, 1, 2, 2, 1, 1, 0);
		drawOneTriangle(angle1, 3 * scale, 3 * scale * 1 / 3, 2.5, 0.5, 2, 0, 3, 1, 1, 0, 1);
		drawOneTriangle(angle1, 3 * scale, -3 * scale * 1 / 3, 2.5, -0.5, 2, 0, 3, -1, 1, 0, 0);
		drawOneTriangle(angle1, 3 * scale * 2 / 3, -3 * scale * 2 / 3, 1.5, -1.5, 1, -1, 2, -2, 1, 1, 0);
		drawOneTriangle(angle1, 3 * scale * 1 / 3, -3 * scale, 0.5, -2.5, 0, -2, 1, -3, 1, 0, 1);
		drawOneTriangle(angle1, -3 * scale * 1 / 3, -3 * scale, -0.5, -2.5, 0, -2, -1, -3, 1, 0, 0);
		drawOneTriangle(angle1, -3 * scale * 2 / 3, -3 * scale * 2 / 3, -1.5, -1.5, -1, -1, -2, -2, 1, 1, 0);
		drawOneTriangle(angle1, -3 * scale, -3 * scale * 1 / 3, -2.5, -0.5, -2, 0, -3, -1, 1, 0, 1);
		drawOneTriangle(angle1, -3 * scale, 3 * scale * 1 / 3, -2.5, 0.5, -2, 0, -3, 1, 1, 0, 0);
		drawOneTriangle(angle1, -3 * scale * 2 / 3, 3 * scale * 2 / 3, -1.5, 1.5, -1, 1, -2, 2, 1, 1, 0);
		drawOneTriangle(angle1, -3 * scale * 1 / 3, 3 * scale, -0.5, 2.5, 0, 2, -1, 3, 1, 0, 1);
	glPopMatrix();
	glutSwapBuffers(); //Send the 3D scene to the screen
}

void update(int value)
{
	angle1 += 1.0f;
	angle2 -= 3.0f;
	//if (angle1 > 360.0f)
	//	angle1 -= 360.0f;
	if (angle2 < 0.0f)
		angle2 = 360.0f;

	counter++;
	if (counter <= 40)
	{
		scale += 0.01;
	}
	if (counter > 40)
	{
		scale -= 0.01;
	}
	if (counter == 80)
	{
		counter = 0;
	}
	cout << scale << endl;

	glutPostRedisplay();
	glutTimerFunc(35, update, 0);
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800); //Set the window size

	//Create the window
	glutCreateWindow("Stupid triangles");
	initRendering(); //Initialize rendering

	//Set handler functions for drawing, keypresses, and window resizes

	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0);

	glutMainLoop(); //Start the main loop.  glutMainLoop doesn't return.
	return 0; //This line is never reached
}