#include <Windows.h>
#include <gl/glut.h>

//콜백함수 실행하는동안 값이 변경되야할 전역변수들
GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;
GLfloat R = 0.5, G = 0.5, B = 0.5;

void MyDisplay() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(R,G,B);
  glBegin(GL_POLYGON);
    //좌표 4개를 상수가 아닌 전역변수로 두어 그때그때 변화할 수 있도록 함.
    glVertex3f(TopLeftX / 300.0, (300.0 - TopLeftY) / 300.0, 0.0);
    glVertex3f(TopLeftX / 300.0, (300.0 - BottomRightY) / 300.0, 0.0);
    glVertex3f(BottomRightX / 300.0, (300.0 - BottomRightY) / 300.0, 0.0);
    glVertex3f(BottomRightX / 300.0, (300.0 - TopLeftY) / 300.0, 0.0);
  glEnd();
  glFlush();
}

//클릭시의 콜백 실행.
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
  //왼쪽마우스버튼 딱 눌렀을때
  if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
    //초록색으로 하고 클릭한 그 순간의 좌표 저장
    R = 0; G = 1; B = 0;
    TopLeftX = X;
    TopLeftY = Y;
  }
  //왼쪽마우스버튼 뗐을때
  if (Button == GLUT_LEFT_BUTTON && State == GLUT_UP) {
    //파란색으로 하고 display 콜백 재실행
    R = 0; G = 0; B = 1;
    glutPostRedisplay();
  }
}

//마우스 움직일 때의 콜백함수
void MyMouseMove(GLint X, GLint Y) {
  BottomRightX = X;
  BottomRightY = Y;
  glutPostRedisplay();
}


int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize(300, 300);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("KangJunewoo Computer Graphics");
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
  glutDisplayFunc(MyDisplay);
  glutMouseFunc(MyMouseClick);
  glutMotionFunc(MyMouseMove);
  glutMainLoop();
  return 0;
}