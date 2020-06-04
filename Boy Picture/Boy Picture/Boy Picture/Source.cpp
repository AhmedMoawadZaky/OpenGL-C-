#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <math.h>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")


void InitGraphics(int argc, char *argv[]);
void nos(GLfloat x, GLfloat y, GLfloat xr, GLfloat yr, GLint startangl, GLint endangle, GLfloat w);

void SetTransformations();

void OnDisplay();
void DrawspicaCircle(float radius, float xc, float yc);
void DrawCircle(float radius, float xc, float yc, int triangle);
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

	//Draw hafe circle in back with black color 
	glColor3f(0, 0, 0);
	DrawCircle(24, 0, -1, 360 / 2 + 1);
	/**********************************************************************************************************************/

	//Draw hafe circle in another color with reduis smaller than black one
	glColor3f(0, 0.956862745098039, 0.956862745098039);
	DrawCircle(22, 0, 0, 360 / 2 + 1);
	/**********************************************************************************************************************/

	//draw ithe nike by the seem way of the boady blak squre then anthour on with a deffrant color
	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(-4.8, 22.5);
	glVertex2f(-4.8, 28);
	glVertex2f(4.8, 28);
	glVertex2f(4.8, 22.5);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1, 0.701960784313725, 0.4);
	glVertex2f(-4, 22.95);
	glVertex2f(-4, 28);
	glVertex2f(4, 28);
	glVertex2f(4, 22.95);
	glEnd();
	/**********************************************************************************************************************/

	//draw right ears 
	glColor3f(0, 0, 0);
	DrawCircle(4, 17, 44, 360);
	glColor3f(1, 0.701960784313725, 0.4);
	DrawCircle(3, 17, 44, 360);
	//draw left ears 
	glColor3f(0, 0, 0);
	DrawCircle(4, -17, 44, 360);
	glColor3f(1, 0.701960784313725, 0.4);
	DrawCircle(3, -17, 44, 360);

	/**********************************************************************************************************************/
	//draw the head of the boy circle  with black color and Draw circle in another color with reduis smaller than black one
	glColor3f(0, 0, 0);
	DrawCircle(17, 0, 43, 360);

	glColor3f(1, 0.701960784313725, 0.4);
	DrawCircle(16, 0, 43, 360);

	/**********************************************************************************************************************/
	//draw the hear of the boy circle  with black color and Draw circle in another color with reduis smaller than black one
	glColor3f(0, 0, 0);
	DrawCircle(19, 0, 47, 360 / 2 + 1);
	glColor3f(0.674509803921569, 0.674509803921569, 0.674509803921569);
	DrawCircle(18, 0, 47, 360 / 2 + 1);

	/**********************************************************************************************************************/
	// ⁄œÌ· ⁄·Ì «·«·Ê«‰ ÃÊÂ «·Ê‘ Ê«·Ê«‰ «·‘⁄— ⁄·‘«‰ ﬂ ‰ ·Ê‰ «·‘⁄— ÃÂ ⁄·Ì «·Ê‘ Ê·Ê‰ «·Ê‘ ÃÂ ⁄·Ì ·Ê‰ «·‘⁄—
	glLineWidth(4);
	glBegin(GL_LINE_STRIP);
	glColor3f(0, 0, 0);
	glVertex2f(-18.5, 47.5);
	glVertex2f(-15, 47.5);
	glVertex2f(-13, 44);
	glVertex2f(-9, 52);
	glVertex2f(-1, 42);
	glVertex2f(-1, 49);
	glVertex2f(0.5, 46);
	glVertex2f(0.5, 50);
	glVertex2f(15, 45);
	glVertex2f(15, 48);
	glVertex2f(19, 47);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.674509803921569, 0.674509803921569, 0.674509803921569);
	glVertex2f(-15, 48.5);
	glVertex2f(-13, 45);
	glVertex2f(-9, 53);
	glVertex2f(-9, 53);
	glVertex2f(-1.4, 43);
	glVertex2f(-1, 50);
	glVertex2f(0.5, 51);
	glVertex2f(14.6, 45.7);
	glVertex2f(15, 50);
	glColor3f(1, 0.701960784313725, 0.4);
	glVertex2f(-13, 43);
	glVertex2f(-9, 51);
	glVertex2f(-1, 41);
	glVertex2f(0.5, 45);
	glVertex2f(1.5, 49);
	glVertex2f(15, 44);
	glEnd();

	/**********************************************************************************************************************/
	//«·⁄Ì‰ «·‘„«· 
	glColor3f(0, 0, 0);
	DrawCircle(4, -8, 40, 360 / 2 + 1);
	glColor3f(1, 0.701960784313725, 0.4);
	DrawCircle(3, -8, 40, 360 / 2 + 1);
	//«·⁄Ì‰ «·Ì„Ì‰ 
	glColor3f(0, 0, 0);
	DrawCircle(4, 8, 40, 360 / 2 + 1);
	glColor3f(1, 0.701960784313725, 0.4);
	DrawCircle(3, 8, 40, 360 / 2 + 1);
	/**********************************************************************************************************************/
	glColor3f(0, 0, 0);
	DrawspicaCircle(4, 0, 35);
	glColor3f(1, 0.701960784313725, 0.4);
	DrawspicaCircle(3, 0, 35);

	glutSwapBuffers();

}

void DrawCircle(float radius, float xc, float yc, int triangle){
	float DEG2RAD = 3.14159265 / 180;

	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(xc, yc, 0);
	for (int i = 0; i < triangle; i++)
	{
		float degInRad = i*DEG2RAD;
		glVertex2f(xc + radius*cos(degInRad), yc + radius*sin(degInRad));
	}
	glVertex2f(xc + radius*cos(0.0), yc + radius*sin(0.0));
	glEnd();
}
void DrawspicaCircle(float radius, float xc, float yc){
	float DEG2RAD = 3.14159265 / 180;

	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(xc, yc, 0);
	for (int i = 0; i < 360; i++)
	{
		float degInRad = i*DEG2RAD;
		if (i>180)
			glVertex2f(xc + radius*cos(degInRad), yc + radius*sin(degInRad));
	}
	glVertex2f(xc + radius*cos(0.0), yc + radius*sin(0.0));
	glEnd();
}
