#include "SerialPort.h" 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

using std::cout;
using std::endl;

char *port_name = "\\\\.\\COM6";

//String for incoming data
char incomingData[300];
SerialPort arduino(port_name);

// camera movement 


int l = 25;
int s = 5;
int t = 20;
int haraka1 = 0;
int haraka2 = 0;
int haraka3 = 0;
int haraka4 = 0;
int wrist = 0;

float aspect = float(1024) / float(768);

float spin = 0.0;
bool rotating = false;

double prespective[] = { 0, 0, 1 };
double mid[] = { 0, 0, 0 };
double up[] = { 0, 1, 0 };


void see(double a[], double b[], double c[])
{
	c[0] = a[1] * b[2] - a[2] * b[1];
	c[1] = a[2] * b[0] - a[0] * b[2];
	c[2] = a[0] * b[1] - a[1] * b[0];
}

void normfunction(double a[])
{
	double norm;
	norm = a[0] * a[0] + a[1] * a[1] + a[2] * a[2];
	norm = sqrt(norm);
	a[0] /= norm;
	a[1] /= norm;
	a[2] /= norm;
}

void rotatePoint(double a[], double func, double p[])
{

	double func2[3];
	func2[0] = p[0];
	func2[1] = p[1];
	func2[2] = p[2];

	func2[0] = -a[2] * p[1] + a[1] * p[2];
	func2[1] = a[2] * p[0] - a[0] * p[2];
	func2[2] = -a[1] * p[0] + a[0] * p[1];

	func2[0] *= sin(func);
	func2[1] *= sin(func);
	func2[2] *= sin(func);

	func2[0] += (1 - cos(func))*(a[0] * a[0] * p[0] + a[0] * a[1] * p[1] + a[0] * a[2] * p[2]);
	func2[1] += (1 - cos(func))*(a[0] * a[1] * p[0] + a[1] * a[1] * p[1] + a[1] * a[2] * p[2]);
	func2[2] += (1 - cos(func))*(a[0] * a[2] * p[0] + a[1] * a[2] * p[1] + a[2] * a[2] * p[2]);

	func2[0] += cos(func)*p[0];
	func2[1] += cos(func)*p[1];
	func2[2] += cos(func)*p[2];

	p[0] = func2[0];
	p[1] = func2[1];
	p[2] = func2[2];

}




void Up()
{
	double speed = 3.1415 / 8;
	double rot_axis[3];
	double look[3];

	look[0] = -prespective[0];
	look[1] = -prespective[1];
	look[2] = -prespective[2];

	see(look, up, rot_axis);

	normfunction(rot_axis);

	rotatePoint(rot_axis, -speed, prespective);

	rotatePoint(rot_axis, -speed, up);

}

void get(unsigned char key, int x, int y)
{

	if (arduino.isConnected()) cout << "Connected" << endl;

	if (arduino.isConnected()) {
		//Check if data has been read or not
		arduino.readSerialPort(incomingData, 300);

		cout << (incomingData[0]) << endl;     // print data 

		Sleep(10);
	}

	switch (incomingData[0]) {



	case 'A':
		if (haraka1 < t) {
			haraka1 = (haraka1 + s) % l;
		}
		glutPostRedisplay();
		break;
	case 'a':
		if (haraka1 > 0) {
			haraka1 = (haraka1 - s) % l;
		}
		glutPostRedisplay();
		break;

	case 'B':
		if (haraka2 < t) {
			haraka2 = (haraka2 + s) % l;
		}
		glutPostRedisplay();
		break;
	case 'b':
		if (haraka2 > 0) {
			haraka2 = (haraka2 - s) % l;
		}
		glutPostRedisplay();
		break;

	case 'C':
		if (haraka3 < t) {
			haraka3 = (haraka3 +s) % l;
		}
		glutPostRedisplay();
		break;
	case 'c':
		if (haraka3 > 0) {
			haraka3 = (haraka3 - s) % l;
		}
		glutPostRedisplay();
		break;

	case 'D':
		if (haraka4 < t) {
			haraka4 = (haraka4 + s) % l;
		}
		glutPostRedisplay();
		break;





	case 'd':
		if (haraka4 > 0) {
			haraka4 = (haraka4 - s) % l;
		}
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

void display(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	////wrist
	glTranslatef(-4.0, 0.0, -8.0);
	gluLookAt(prespective[0], prespective[1], prespective[2], mid[0], mid[1], mid[2], up[0], up[1], up[2]);
	glTranslatef(2.0, 0.0, 0.0);
	glRotatef((GLfloat)wrist, 0.0, 1.0, 0.0);
	glColor3f(1, 2, 3);
	glPushMatrix();
	glScalef(4.0, 3.0, 1.0);
	glutWireCube(1.0);
	glPopMatrix();

	//harahka1
	glPushMatrix();
	//glPushMatrix(); 
	glTranslatef(3.0, -0.85, 0.0);
	glRotatef((GLfloat)haraka2, 0.0, 1.0, 0.0);
	glColor3f(1, 2, 3);
	glPushMatrix();                             
	glScalef(2.0, 0.3, 0.3);
	glutWireCube(1.0);
	glPopMatrix();

	//haraka2
	glTranslatef(2.0, 0.0, 0.0);
	glRotatef((GLfloat)haraka1, 0.0, 1.0, 0.0);
	glColor3f(1, 2, 3);
	//glPushMatrix();                            
	glScalef(2.0, 0.3, 0.3);
	glutWireCube(1.0);
	//glPopMatrix();
	glPopMatrix(); 





	//haraka3
	glTranslatef(3.0, 0.6, 0.0);
	glRotatef((GLfloat)haraka4, 0.0, 1.0, 0.0);
	glColor3f(1, 2, 3);
	glPushMatrix();                         
	glScalef(2.0, 0.3, 0.3);
	glutWireCube(1.0);
	glPopMatrix();                         
	                         


	//haraka4
	//glPushMatrix();                     
	glTranslatef(2.0, 0.0, 0.0);
	glRotatef((GLfloat)haraka3, 0.0, 1.0, 0.0);
	glColor3f(1, 2, 3);
	//glPushMatrix();                   
	glScalef(2.0, 0.3, 0.3);
	glutWireCube(1.0);
	glPopMatrix();                      

	glFlush();
	glutSwapBuffers();
}

void rotate(int key, int x, int y)
{
	switch (key)
	{

	case GLUT_KEY_UP:  Up(); break;
	}

	glutPostRedisplay();
}


int main(void)
{
	glutInitWindowSize(1024, 768);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("TASK 4");

	glMatrixMode(GL_PROJECTION);
	gluPerspective(60, aspect, 0, 10);
	glutKeyboardFunc(get);

	glutDisplayFunc(display);

	glutSpecialFunc(rotate);

	glutMainLoop();

	return 0;


}
