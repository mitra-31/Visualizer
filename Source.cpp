#include <Windows.h>
#include <gl/glut.h>
#include <bits/stdc++.h>
#include "algos.h"



// Global Variables

const int N = 380;
int vec[N], compares, exchanges;
std::string sortName;



void initGL();
void display();
void visual(int* arr);
void visual(int* arr, int compares, int exchanges);
void drawBitmapString(float x, float y, std::string s);


void initGL() {
	glClearColor(23.0/255.0f, 23.0 / 255.0f, 23.0 / 255.0f, 0.0f);
}


void display() {
	visual(vec,compares,exchanges);
	int arr[N];
	sortName = "selection sort";
	compares = 0, exchanges = 0;
	for (int i = 0; i < N; i++)
		arr[i] = vec[i];
	insertionSort sort(arr, N,compares,exchanges);
}



/* 
	visual overloaded with only arr and (arr,comapres,exchanges)
*/ 

void visual(int* arr,int comapres, int exchanges) {
	glClear(GL_COLOR_BUFFER_BIT);
	drawBitmapString(700, 770, sortName);
	drawBitmapString(700, 750, "Number of Compares:" + std::to_string(compares));
	drawBitmapString(700, 730, "Number of Exchanges:" + std::to_string(exchanges));
	glColor3f(1.0f, 0.0f, 0.0f);
	for (int i = 0; i < N; i++) {
		glRecti(4 * i, 100, 4 * i + 3, 100 + arr[i]);
	}
	glFlush();
}

void visual(int* arr) {
glClear(GL_COLOR_BUFFER_BIT);
drawBitmapString(500, 750, "WELCOME TO SORTING VISUALIZER");
drawBitmapString(520, 730, "USAGE");
drawBitmapString(540, 700, "Press 'A' to Start All Alogrithms");
drawBitmapString(560, 700, "Press '1' to Shell Sort");
glColor3f(237.0 / 255.0f, 237.0 / 255.0f, 237.0 / 255.0f);
for (int i = 0; i < N; i++) {
	glRecti(4 * i, 100, 4 * i + 3, 100 + arr[i]);
}
glFlush();
}


void drawBitmapString(float x, float y, std::string s)
{
	glColor3f(218.0f, 0.0f, 55.0f);
	glRasterPos2f(x, y);
	int length = s.size();
	for (int i = 0; i < length; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);
	}
}



// Main Function.

int main(int argc, char** argv)
{
	srand((unsigned)time(0));

	for (int i = 0; i < N; i++)
	{
		vec[i] = (rand() % 600);
	}

	glutInit(&argc, argv);
	glutInitWindowSize(1500, 864);
	glutCreateWindow("Sorting Visualization");// name of window
	glutInitWindowPosition(0, 100); // your screen cordinate at which window will appear
	glutDisplayFunc(display); // call back function
	initGL(); // initializing GL
	gluOrtho2D(0, 1536, 0, 864); // transforming clipping area to Viewport area
	glutMainLoop(); // infinite processing loop
	return 0;
}