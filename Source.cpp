#include <Windows.h>
#include <gl/glut.h>
#include <bits/stdc++.h>



// Global Variables

const int N = 380;
int vec[N], compares, exchanges;
std::string sortName;
char sort;



void initGL();
void display();
void visual(int* arr);
void visual(int* arr,std::string sortName);
void drawBitmapString(float x, float y, std::string s);


void initGL() {
	glClearColor(68.0/255.0f, 68.0 / 255.0f, 68.0 / 255.0f, 0.0f);
}


#include "algos.h"
void display() {

	visual(vec);	
}


void keyboardEvent(unsigned char c, int x, int y)
{
	if (c == 49)
	{
		drawBitmapString(700, 750, "Array Lenght: " + std::to_string(*(&vec + 1) - vec));
		visual(vec, "Insertion Sort");
		int arr[N];
		sortName = "Inserrtion Sort";
		compares = 0, exchanges = 0;
		for (int i = 0; i < N; i++)
			arr[i] = vec[i];
		insertionSort sort(arr, N);
		Sleep(10);
	}
	else if (c == 50)
	{

		drawBitmapString(700, 750, "Array Lenght: " + std::to_string(*(&vec + 1) - vec));
		visual(vec, "Selection Sort");
		int arr[N];
		sortName = "Selection Sort";
		compares = 0, exchanges = 0;
		for (int i = 0; i < N; i++)
			arr[i] = vec[i];
		selectionSort sort(arr, N);
		Sleep(10);
	}
}



/* 
	visual overloaded with only arr and (arr,comapres,exchanges)
*/ 

void visual(int* arr,std::string sortName) {
	glClear(GL_COLOR_BUFFER_BIT);
	drawBitmapString(700, 770, sortName);
	drawBitmapString(700, 740, "Number of Compares:" + std::to_string(compares));
	drawBitmapString(700, 720, "Number of Exchanges:" + std::to_string(exchanges));
	glColor3f(237.0/255.0f, 237.0/255.0f, 237.0/255.0f);
	for (int i = 0; i < N; i++) {
		glRecti(4 * i, 100, 4 * i + 3, 100 + arr[i]);
	}
	glFlush();
}

void visual(int* arr) {
glClear(GL_COLOR_BUFFER_BIT);
drawBitmapString(500, 750, "WELCOME TO SORTING VISUALIZER");
drawBitmapString(520, 730, "USAGE");
drawBitmapString(560, 700, "Press '1' to Insertion Sort.   Press '2' to Selection Sort.  Press '3' to Shell Sort");
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
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("Sorting Visualization");// name of window
	glutInitWindowPosition(0, 100); // your screen cordinate at which window will appear
	glutDisplayFunc(display); // call back function
	glutKeyboardFunc(keyboardEvent);
	initGL(); // initializing GL
	gluOrtho2D(0, 1536, 0, 864); // transforming clipping area to Viewport area
	glutMainLoop(); // infinite processing loop
	return 0;
}