#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "glut32.lib")

void InitGraphics(int argc, char *argv[]);


void SetTransformations();

void OnDisplay();
float C[10][3] = { { 0.572549019607843, 0.427450980392157, 0.490196078431373 }, { 0.180392156862745, 0.819607843137255, 0.341176470588235 }, { 1, 0.65, 0 }, { 0, 1, 0 }, { 0, 0, 1 }, { 0.5, 0, 0.5 }, { 1, 0, 1 }, { 1, 1, 1 }, { 1, 1, 0 }, { 1, 0, 0 } };
int c;
float fXPos, fYPos, fRot;
bool lflag = 0, rflag = 1, dflag = 0, uflag = 0;
int main(int argc, char* argv[])
{
	fXPos = fYPos = fRot = 0;
	InitGraphics(argc, argv);
	return 0;
}

void InitGraphics(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	//Create an 800x600 window with its top-left corner at pixel (100, 100)
	glutInitWindowPosition(100, 100); //pass (-1, -1) for Window-Manager defaults
	glutInitWindowSize(800, 600);
	glutCreateWindow("screensever");
	//OnDisplay will handle the paint event
	glutDisplayFunc(OnDisplay);
	// here is the setting of the idle function
	glutIdleFunc(OnDisplay);
	// here is the setting of the key function
	SetTransformations();

	glutMainLoop();
}
void SetTransformations() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}

void OnDisplay()
{

	glLoadIdentity();

	glClearColor(0, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	if (rflag){
		fRot += 0.05;
		if (fXPos < 65.0){
			fXPos += .025;
			fYPos += .025;
		}
		else{
			rflag = 0;
			uflag = 1;
			++c;
		}
	}
	else if (lflag){
		fRot += 0.05;
		if (fXPos > -65.0){
			fXPos -= .025;
			fYPos -= 0.0025;
		}
		else{
			lflag = 0;
			dflag = 1;
			++c;
		}
	}
	else if (uflag){
		fRot += 0.05;
		if (fYPos < 65.0){
			fYPos += .025;
			fXPos -= .0025;
		}
		else{
			uflag = 0;
			lflag = 1;
			++c;
		}
	}
	else if (dflag){
		fRot += 0.05;
		if (fYPos > -65.0){
			fYPos -= .025;
			fXPos += .025;
		}
		else{
			dflag = 0;
			rflag = 1;
			++c;
		}
	}
	glPushMatrix();
	glTranslatef(fXPos, fYPos, 0);
	glRotatef(fRot, 0, 0, 1);
	glBegin(GL_QUADS);
	glColor4fv(C[c % 10]);
	glVertex3f(-25, -25, 0);
	glVertex3f(25, -25, 0);
	glVertex3f(25, 25, 0);
	glVertex3f(-25, 25, 0);
	glEnd();

	glPopMatrix();

	glutSwapBuffers();

}