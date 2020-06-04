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
void DrawCircle(float radius, float xc, float yc);
void OnKeyPress(unsigned char key, int x, int y);

void OnSpecialKeyPress(int key, int x, int y);

void DrawEllipse(float minRad, float majRad, float xc, float yc){
	float PI = 3.14159265;
	int triangleAmount = 60;
	GLfloat twicePi = 2.0 * PI;
	glBegin(GL_POLYGON);
	for (int i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			xc + (minRad* cos(i *  twicePi / triangleAmount)),
			yc + (majRad * sin(i * twicePi / triangleAmount))
			);
	}
	glEnd();
}
int main(int argc, char* argv[]){

	InitGraphics(argc, argv);
	return 0;
}

void InitGraphics(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	//Create an 800x600 window with its top-left corner at pixel (100, 100)
	glutInitWindowPosition(100, 100); //pass (-1, -1) for Window-Manager defaults
	glutInitWindowSize(800, 800);
	glutCreateWindow("Monkey");
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

	//ÑÓã ÇáÇÐä æÇÍÏå ÈíÌ æÑÇ æÞÏÇãåÇ æÇÍÏå ÊÇäíå Èáæä ãÎÊáÝ æ ÈäÕÝ ÞØÑ ÇÞá ãäå 
	glColor3f(1, 0.803921568627451, 0.607843137254902);
	DrawCircle(9.5, -31, 20);//ÇáÇÐä ÇáíÓÑí 
	DrawCircle(9.5, 31, 20);//ÇáÇÐä Çáíãäí

	glColor3f(1, 0.615686274509804, 0.435294117647059);
	DrawCircle(5.5, -31, 20);//ÇáÇÐä ÇáíÓÑí ãä ÇáÏÇÎá
	DrawCircle(5.5, 31, 20);//ÇáÇÐä Çáíãäí ä ÇáÏÇÎá

	/**********************************************************************************************************************/
	//ÏÇÆÑå ÇáæÌå
	glColor3f(0.403921568627451, 0.203921568627451, 0.203921568627451);
	DrawCircle(30, 0, 20);

	//ÇáÔÚÑ
	glBegin(GL_TRIANGLES);
	glVertex2f(-9, 48);
	glVertex2f(9, 59);
	glVertex2f(2, 49);
	glVertex2f(1, 49);
	glVertex2f(10, 55);
	glVertex2f(10, 47);
	glVertex2f(7, 47);
	glVertex2f(16, 50);
	glVertex2f(16, 45);
	glEnd();

	/**********************************************************************************************************************/
	glColor3f(1, 0.803921568627451, 0.607843137254902);
	DrawCircle(18, 0, 0);  //ÏÇÆÑå ÇáÐÞä 
	DrawCircle(13, -11, 25); //ÏÇÆÑå ÇáÚíä ÇáíÓÑí 
	DrawCircle(13, 11, 25); //ÏÇÆÑå ÇáÚíä Çáíãäí 

	glColor3f(1, 0.615686274509804, 0.435294117647059);
	DrawCircle(8, -11, 25); //ÑÓã ÏÇÆÑå ÇáÚíä ÇáíÓÑí ÇÕÛÑ Ýí äÕÝ ÇáÞØÑ ß ÍÏæÏ ááÞÑÇäíå
	DrawCircle(8, 11, 25); //ÑÓã ÏÇÆÑå ÇáÚíä Çáíãäí ÇÕÛÑ Ýí äÕÝ ÇáÞØÑ ß ÍÏæÏ ááÞÑÇäíå

	glColor3f(0.258823529411765, 0, 0);
	DrawCircle(5, -11, 25); //ÞÑäíå ÇáÚíä ÇáíÓÑí 
	DrawCircle(5, 11, 25); //ÞÑäíå ÇáÚíä Çáíãäí 

	glColor3f(0.827450980392157, 0.662745098039216, 0.662745098039216);
	DrawCircle(4, -11, 25);
	DrawCircle(4, 11, 25);

	glColor3f(0.258823529411765, 0, 0);
	DrawCircle(4, -10.5, 25.5);
	DrawCircle(4, 11.5, 25.5);
	glColor3f(1, 1, 1);
	DrawCircle(2, -9, 26); //áãÚÇä ÏÇÎá ÞÑäíå ÇáÚíä ÇáíÓÑí 
	DrawCircle(2, 13, 26); //áãÚÇä ÏÇÎá ÞÑäíå ÇáÚíä Çáíãäí 
	/**********************************************************************************************************************/
	//ÇáÝã
	glColor3f(1, 0.615686274509804, 0.435294117647059);
	DrawEllipse(3.5, 4.5, 0, -5);
	//ÇáÇäÝ
	DrawEllipse(7, 1.5, 0, 10);
	/**********************************************************************************************************************/

	glutSwapBuffers();

}

void DrawCircle(float radius, float xc, float yc){
	float DEG2RAD = 3.14159265 / 180;

	glBegin(GL_TRIANGLE_FAN);

	glVertex3f(xc, yc, 0);
	for (int i = 0; i < 360; i++)
	{
		float degInRad = i*DEG2RAD;
		glVertex2f(xc + radius*cos(degInRad), yc + radius*sin(degInRad));
	}
	glVertex2f(xc + radius*cos(0.0), yc + radius*sin(0.0));
	glEnd();
}
