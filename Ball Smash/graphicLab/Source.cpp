#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>
#include <iostream>
#include <math.h>
#include <MMSystem.h>
using namespace std;

void InitGraphics(int argc, char *argv[]);
void SetTransformations();
//function to draw eclipse we rotate ,trabezat bleardo we beng
float C[4][3] = { { 0.180392156862745, 0.819607843137255, 0.341176470588235 }, { 1, 0.65, 0 }, { 1, 0, 1 }, { 1, 1, 0 } };
float x = .09,y = .10,yy = .01,fXPos, fYPos, fRot,fXPos1, fYPos1, fRot1,r, g, b;
int xx[20][4][2], c, lrIndex, ww, qqq, stop;
bool play = FALSE;
string message =  "Congratulation man You Win!!!";
string message1 = "Sorry You lose the game!!!";

void idle(){
	glutPostRedisplay();
}
void display(){
	r = (rand() % 8) / 5;
	g = (rand() % 8) / 5;
	b = (rand() % 8) / 5;
	glClearColor(0.0, 0.0, 0.3, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(r, g, b);
	glLineWidth(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 2000, 0, 2000);
	glPushMatrix();
	glTranslatef(50, 1000, 0); //Translates the character object with its axis of rotation
	if (stop != 76)
		message = message1;
	for (int i = 0; i < message.length(); i++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, message[i]);
	glPopMatrix();
	glutSwapBuffers();
}
void spe_key(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		if (lrIndex > -11)
			lrIndex -= 10;
		break;
	case GLUT_KEY_RIGHT:
		if (lrIndex <= 40)
			lrIndex += 10;
		break;
	case GLUT_KEY_UP:
		play = TRUE;
		break;
	default:
		break;
	}
}
void ellipsefull(float x, float y, float min_radius, float max_radius, float rotation_angle = 0){
	float PI = 3.14;
	float drawing_quality = 36; //# of triangles used to draw circle
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i <= drawing_quality; i++){
		glVertex2f(x + (max_radius * cos(i *  twicePi / drawing_quality)), y + (min_radius* sin(i * twicePi / drawing_quality)));
	}
	glVertex2f(x + (max_radius * cos(0)),y + (min_radius* sin(0)));
	glEnd();
}

void OnDisplay();
//find the point that have destroyed
//end game depend on nn var in case of nn reach to 76 destoryed point game is finshed
int findDestroyedBall(int x, int y, int xx[20][4][2]){
	for (int q = 0; q<4; q++)
	for (int i = 0; i<20; i++)
	if (xx[i][q][0] == x&&xx[i][q][1] == y){
		ww = i;
		qqq = q;
		++stop;
		return 0;
	}
	return 1;
}
// any point have a space this function make round of space to its value in array
int raoundx(float(x), int y){
	if (int(x)<72 && int(x) >= 64)
		y = 68;
	else if (int(x)<80 && int(x) >= 72)
		y = 76;
	else if (int(x)<88 && int(x) >= 80)
		y = 84;
	else  if (int(x)<96 && int(x) >= 88)
		y = 92;
	return y;
}
//any point have a space this function make round of space to its value in array
int raoundy(float x, int y){
	if (int(x)<3 && int(x) >= 0)
		y = 0;
	else if (int(x)<7 && int(x) >= 2)
		y = 5;
	else if (int(x)<12 && int(x) >= 7)
		y = 10;
	else if (int(x)<17 && int(x) >= 12)
		y = 15;
	else  if (int(x)<22 && int(x) >= 17)
		y = 20;
	else if (int(x)<27 && int(x) >= 22)
		y = 25;
	else if (int(x)<32 && int(x) >= 27)
		y = 30;
	else  if (int(x)<37 && int(x) >= 32)
		y = 35;
	else if (int(x)<42 && int(x) >= 37)
		y = 40;
	else if (int(x)<47 && int(x) >= 42)
		y = 45;
	else  if (int(x)<52 && int(x) >= 47)
		y = 50;
	else if (int(x)<57 && int(x) >= 52)
		y = 55;
	else if (int(x)<62 && int(x) >= 57)
		y = 60;
	else  if (int(x)<67 && int(x) >= 62)
		y = 65;
	else if (int(x)<72 && int(x) >= 67)
		y = 70;
	else if (int(x)<77 && int(x) >= 72)
		y = 75;
	else  if (int(x)<82 && int(x) >= 77)
		y = 80;
	else if (int(x)<87 && int(x) >= 82)
		y = 85;
	else if (int(x)<92 && int(x) >= 87)
		y = 90;
	else  if (int(x)<97 && int(x) >= 92)
		y = 95;
	else  if (int(x) <= 100 && int(x) >= 97)
		y = -1;
	return y;
}
int main(int argc, char* argv[]){
	fXPos1 = fYPos1 = fRot1 = 0;
	fXPos = fYPos = fRot = 0;
	//inizalize the array values with point direction
	for (int i = 92; i >= 68; i -= 8)
	for (int q = 95; q >0; q -=5){
		xx[(q / 5)][(i - 68) / 8][0] = q;
		xx[(q / 5)][(i - 68) / 8][1] = i;
	}
	InitGraphics(argc, argv);
	return 0;
}
void InitGraphics(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100); 
	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL Project");
	glutDisplayFunc(OnDisplay);
	glutIdleFunc(OnDisplay);
	glutSpecialFunc(spe_key);
	SetTransformations();
	glutMainLoop();
}
void SetTransformations() {
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 100, 0, 100);
	glMatrixMode(GL_MODELVIEW);
}
void OnDisplay(){
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	//speed increa
	if (play == TRUE){
		fYPos1 += y;
		fXPos1 += yy;
	}
	else
		fXPos1 = lrIndex-5;
	//condition to control of place that ball move in
	if (fYPos1>90 || fYPos1<0){
		y = -1 * y;
		//sndPlaySound(TEXT("crash.wav"), SND_ASYNC);
		if ((lrIndex + 10 < fXPos1 || lrIndex - 21 > fXPos1) && fYPos1<0){
			glutDisplayFunc(display);
			glutIdleFunc(idle);
			glutMainLoop();
			exit(0);
		}
	}
	if (fXPos1>60 || fXPos1<-40)
		yy = -1 * yy;
	//round fxpos and fypos to valuse that in array
	int zz = raoundy(fXPos1 + 40, 5);
	int zzz = raoundx(fYPos1 + 5, 8);
	//make value in array ==-1 to delete point that crusj with ball
	if (findDestroyedBall(zz, zzz, xx) == 0){
		xx[ww][qqq][0] = -1;
		xx[ww][qqq][1] = -1;
		y = y*-1;
	}
	if (stop == 76){
		glutDisplayFunc(display);
		glutIdleFunc(idle);
		glutMainLoop();
		exit(0);
	}
	//draw point that exit in array
	for (int i = 92; i >= 68; i -= 8)
	for (int q = 95; q >0; q -= 5){
		glPointSize(35);
		glBegin(GL_POINTS);
		glColor4fv(C[c++]);
		c %= 4;
		glVertex3f(xx[q / 5][(i - 68) / 8][0], xx[q / 5][(i - 68) / 8][1], 0);
		glEnd();
	}
	glBegin(GL_QUADS);
		glColor3f(0.674509803921569, 0.674509803921569, 0.674509803921569);
		glVertex2f(lrIndex + 20, 3);
		glVertex2f(lrIndex + 20, 5);
		glVertex2f(lrIndex + 50, 5);
		glVertex2f(lrIndex + 50, 3);
		glColor3f(0.823529411764706, 0.411764705882353, 0);
		glVertex2f(lrIndex + 20, 3);
		glVertex2f(lrIndex + 20, 5);
		glVertex2f(lrIndex + 22, 5);
		glVertex2f(lrIndex + 22, 3);
		glVertex2f(lrIndex + 50, 5);
		glVertex2f(lrIndex + 50, 3);
		glVertex2f(lrIndex + 48, 3);
		glVertex2f(lrIndex + 48, 5);
	glEnd();
	glPushMatrix();
		glTranslatef(fXPos1, fYPos1, 0);
		glColor3f(1, 0, 0);
		ellipsefull(40, 5, 1, 1, 0);
	glPopMatrix();
	glutSwapBuffers();
}