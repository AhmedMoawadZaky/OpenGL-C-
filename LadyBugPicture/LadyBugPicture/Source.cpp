#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <math.h>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")


void InitGraphics(int argc, char *argv[]);
void nos(GLfloat x, GLfloat y, GLfloat xr, GLfloat yr, GLint startangl, GLint endangle, GLfloat w);
void noss(GLfloat x, GLfloat y, GLfloat xr, GLfloat yr, GLint startangl, GLint endangle, GLfloat w);

void SetTransformations();

void OnDisplay();

void DrawCircle(float radius, float xc, float yc);
void OnKeyPress(unsigned char key, int x, int y);

void OnSpecialKeyPress(int key, int x, int y);

float c1_value, c2_value;
bool c1_flag, c2_flag;

bool flag;
int main(int argc, char* argv[])
{
	c1_value = c2_value = 0;
	c1_flag = c2_flag = false;

	flag = 1;
	InitGraphics(argc, argv);
	return 0;
}

void InitGraphics(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	//Create an 800x600 window with its top-left corner at pixel (100, 100)
	glutInitWindowPosition(100, 100); //pass (-1, -1) for Window-Manager defaults
	glutInitWindowSize(800, 800);
	glutCreateWindow("Lab3");
	//OnDisplay will handle the paint event
	glutDisplayFunc(OnDisplay);
	// here is the setting of the idle function
	glutIdleFunc(OnDisplay);
	SetTransformations();
	glutMainLoop();
}

void SetTransformations() {
	//set up the logical coordinate system of the window: [-100, 100] x [-100, 100]
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}


void OnDisplay()
{
	// clear the transformation matrix
	glLoadIdentity();
	//set the background color to white
	glClearColor(1, 1, 1, 1);
	//fill the whole color buffer with the clear color
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0, 0, 0);
	nos(0, 0, 21, 21, 0, 180, 5);
	noss(0, 0, 21, 21, 0, 360, 5);


	DrawCircle(22, 0, -1);
	glColor3f(0, 0, 0);
	DrawCircle(21, 0, 0);
	float DEG2RAD = 3.14159265 / 180;
	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(0, 0, 0);
	for (int i = 0; i < 360; i++)
	{
		float degInRad = i*DEG2RAD;
		if (i>269)
			glVertex2f(21 * cos(degInRad), 21 * sin(degInRad));
	}
	glVertex2f(21 * cos(0.0), 21 * sin(0.0));

	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(41, 0, 0);
	for (int i = 0; i < 360; i++)
	{
		float degInRad = i*DEG2RAD;
		if (i >= 110 && i <= 250)
			glVertex2f(41 + 21 * cos(degInRad), 21 * sin(degInRad));
	}
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1, 1, 1);
	glVertex3f(41, 0, 0);
	for (int i = 0; i < 360; i++)
	{
		float degInRad = i*DEG2RAD;
		if (i >= 90 && i <= 270)
			glVertex2f(41 + 19 * cos(degInRad), 19 * sin(degInRad));
	}
	glEnd();
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glLineWidth(3);
	glVertex2f(-15.2, 14.8);
	glVertex2f(-22, 17.67766953);
	glVertex2f(-15.2, -14.8);
	glVertex2f(-22, -17.67766953);
	glEnd();

	glutSwapBuffers();

}

void DrawCircle(float radius, float xc, float yc){
	float DEG2RAD = 3.14159265 / 180;
	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(xc, yc, 0);
	for (int i = 0; i < 360 / 4 + 1; i++)
	{
		float degInRad = i*DEG2RAD;
		glVertex2f(xc + radius*cos(degInRad), yc + radius*sin(degInRad));
	}
	glVertex2f(xc + radius*cos(0.0), yc + radius*sin(0.0));
	glEnd();
}
void nos(GLfloat x, GLfloat y, GLfloat xr, GLfloat yr, GLint startangl, GLint endangle, GLfloat w){
	float pi = 3.14159265;
	int tr = 360;
	GLfloat toicpi = 2.0 * pi;
	glLineWidth(w);
	glBegin(GL_LINE_STRIP);
	glVertex2f(x, y);
	for (int i = 0; i <= tr; i++)
	if (i >= startangl&&i <= endangle)
		glVertex2f(-((-x) + xr*cos(i*toicpi / tr)), (y + yr*sin(i*toicpi / tr)));
	glEnd();
}
void noss(GLfloat x, GLfloat y, GLfloat xr, GLfloat yr, GLint startangl, GLint endangle, GLfloat w){
	float pi = 3.14159265;
	int tr = 360;
	GLfloat toicpi = 2.0 * pi;
	glLineWidth(w);
	glBegin(GL_LINE_STRIP);
	glVertex2f(x, y);
	for (int i = 0; i <= tr; i++)
	if (i >= startangl&&i <= endangle)
		glVertex2f(((x)+xr*cos(i*toicpi / tr)), (y + yr*sin(i*toicpi / tr)));
	glEnd();
}