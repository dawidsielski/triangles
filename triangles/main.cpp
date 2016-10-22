/* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above notice and this permission notice shall be included in all copies
* or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/
/* File for "Basic Shapes" lesson of the OpenGL tutorial on
* www.videotutorialsrock.com
*/



#include <iostream>
#include <stdlib.h> //Needed for "exit" function

//Include OpenGL header files, so that we can use OpenGL
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

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

								 //Set the camera perspective
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0,                  //The camera angle
		(double)w / (double)h, //The width-to-height ratio
		1.0,                   //The near z clipping coordinate
		200.0);                //The far z clipping coordinate
}


GLfloat angle = 0, angle2 = 360;
//Draws the 3D scene
void drawScene() {

	//Clear information from last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective

	glPushMatrix();
	glRotatef(angle2, 0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES); //Begin triangle coordinates

	//glPushMatrix();
	//glRotatef(angle2, 0.0, 0.0, 1.0);
	cout << angle2 << " " << angle << endl;
	glColor3f(0.0f, 0.0f, 1.0f);
	//1
	glVertex3f(0.0f, 0.0f, -10.0f);
	glVertex3f(1.0f, 0.0f, -10.0f);
	glVertex3f(0.0f, 1.0f, -10.0f);

	//2
	glVertex3f(0.0f, 0.0f, -10.0f);
	glVertex3f(0.0f, -1.0f, -10.0f);
	glVertex3f(1.0f, 0.0f, -10.0f);

	//3
	glVertex3f(0.0f, 0.0f, -10.0f);
	glVertex3f(0.0f, -1.0f, -10.0f);
	glVertex3f(-1.0f, 0.0f, -10.0f);

	//4
	glVertex3f(0.0f, 0.0f, -10.0f);
	glVertex3f(-1.0f, 0.0f, -10.0f);
	glVertex3f(0.0f, 1.0f, -10.0f);
	//glPopMatrix();


	glColor3f(0.0f, 1.0f, 0.0f);
	//6
	glVertex3f(0.0f, 1.0f, -10.0f);
	glVertex3f(1.0f, 1.0f, -10.0f);
	glVertex3f(0.0f, 2.0f, -10.0f);

	//8
	glVertex3f(1.0f, 0.0f, -10.0f);
	glVertex3f(1.0f, -1.0f, -10.0f);
	glVertex3f(2.0f, 0.0f, -10.0f);

	//10
	glVertex3f(0.0f, -1.0f, -10.0f);
	glVertex3f(0.0f, -2.0f, -10.0f);
	glVertex3f(-1.0f, -1.0f, -10.0f);

	//12
	glVertex3f(-1.0f, 0.0f, -10.0f);
	glVertex3f(-2.0f, 0.0f, -10.0f);
	glVertex3f(-1.0f, 1.0f, -10.0f);



	glColor3f(1.0f, 0.7f, 0.0f);
	//9
	glVertex3f(0.0f, -1.0f, -10.0f);
	glVertex3f(0.0f, -2.0f, -10.0f);
	glVertex3f(1.0f, -1.0f, -10.0f);

	//5
	glVertex3f(0.0f, 1.0f, -10.0f);
	glVertex3f(-1.0f, 1.0f, -10.0f);
	glVertex3f(0.0f, 2.0f, -10.0f);

	//7
	glVertex3f(1.0f, 0.0f, -10.0f);
	glVertex3f(2.0f, 0.0f, -10.0f);
	glVertex3f(1.0f, 1.0f, -10.0f);

	//11
	glVertex3f(-1.0f, 0.0f, -10.0f);
	glVertex3f(-1.0f, -1.0f, -10.0f);
	glVertex3f(-2.0f, 0.0f, -10.0f);

	glColor3f(1.0f, 1.0f, 0.0f);
	//14
	glVertex3f(1.0f, 1.0f, -10.0f);
	glVertex3f(2.0f, 1.0f, -10.0f);
	glVertex3f(1.0f, 2.0f, -10.0f);

	//17
	glVertex3f(1.0f, -1.0f, -10.0f);
	glVertex3f(1.0f, -2.0f, -10.0f);
	glVertex3f(2.0f, -1.0f, -10.0f);
	 
	//20
	glVertex3f(-1.0f, -1.0f, -10.0f);
	glVertex3f(-1.0f, -2.0f, -10.0f);
	glVertex3f(-2.0f, -1.0f, -10.0f);

	//23
	glVertex3f(-1.0f, 1.0f, -10.0f);
	glVertex3f(-2.0f, 1.0f, -10.0f);
	glVertex3f(-1.0f, 2.0f, -10.0f);


	glColor3f(1.0f, 0.0f, 0.0f);
	//13
	glVertex3f(0.0f, 2.0f, -10.0f);
	glVertex3f(1.0f, 2.0f, -10.0f);
	glVertex3f(0.0f, 3.0f, -10.0f);

	//16
	glVertex3f(2.0f, 0.0f, -10.0f);
	glVertex3f(2.0f, -1.0f, -10.0f);
	glVertex3f(3.0f, 0.0f, -10.0f);

	//19
	glVertex3f(0.0f, -2.0f, -10.0f);
	glVertex3f(0.0f, -3.0f, -10.0f);
	glVertex3f(-1.0f, -2.0f, -10.0f);

	//22
	glVertex3f(-2.0f, 0.0f, -10.0f);
	glVertex3f(-3.0f, 0.0f, -10.0f);
	glVertex3f(-2.0f, 1.0f, -10.0f);


	glColor3f(1.0f, 0.0f, 1.0f);
	//15
	glVertex3f(2.0f, 0.0f, -10.0f);
	glVertex3f(3.0f, 0.0f, -10.0f);
	glVertex3f(2.0f, 1.0f, -10.0f);

	//18
	glVertex3f(0.0f, -2.0f, -10.0f);
	glVertex3f(0.0f, -3.0f, -10.0f);
	glVertex3f(1.0f, -2.0f, -10.0f);

	//21
	glVertex3f(-2.0f, 0.0f, -10.0f);
	glVertex3f(-2.0f, -1.0f, -10.0f);
	glVertex3f(-3.0f, 0.0f, -10.0f);

	//24
	glVertex3f(0.0f, 2.0f, -10.0f);
	glVertex3f(-1.0f, 2.0f, -10.0f);
	glVertex3f(0.0f, 3.0f, -10.0f);

	glEnd(); //End triangle coordinates
	glPopMatrix();

	glutSwapBuffers(); //Send the 3D scene to the screen
}

void update(int value)
{
	angle += 2.0f;
	angle2 -= 2.0f;
	if (angle>360.0f)
	{
		angle -= 360;
	}
	if (angle2< 0.0f)
	{
		angle2 = 360.0f;
	}
	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
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








