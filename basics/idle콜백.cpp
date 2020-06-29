#include <Windows.h>
#include <gl/glut.h>

//콜백함수 실행하는동안 값이 변경되야할 전역변수들
GLfloat Delta=0.0;

void MyDisplay() {
  glClear(GL_COLOR_BUFFER_BIT);
  //x좌표에 델타값을 싹 붙여서 조금씩 오른쪽으로 이동할 수 있도록 함.
  glBegin(GL_POLYGON);
    glColor3f(0.0,0.5,0.8);
    glVertex3f(-1.0+Delta,-0.5,0.0);
    glVertex3f(0.0+Delta,-0.5,0.0);
    glVertex3f(0.0+Delta,0.5,0.0);
    glVertex3f(-1.0+Delta,0.5,0.0);
  glEnd();
  //이 함수로 깜빡거림 없앰!
  glutSwapBuffers();
}

//idle 콜백함수. delta값을 0.001 늘린다!
void MyIdle(){
  Delta+=0.001;
  glutPostRedisplay();
}


int main(int argc, char** argv) {
  glutInit(&argc, argv);
  //glutSwapBuffers()를 이용하기 위해 displaymode에 GLUT_DOUBLE 추가
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowSize(300, 300);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("KangJunewoo Computer Graphics");
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
  
  glutDisplayFunc(MyDisplay);
  //idle함수 등록
  glutIdleFunc(MyIdle);
  glutMainLoop();
  return 0;
}