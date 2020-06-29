#include <Windows.h>
#include <gl/glut.h>

//전역변수를 활용해, 초기 RGB값을 모두 0.5로 세팅했습니다.
GLint R=0.5;
GLint G=0.5;
GLint B=0.5;

void MyDisplay(){
  glClear(GL_COLOR_BUFFER_BIT);
  //상수값이 아닌, RGB값으로 사각형의 컬러를 적용했습니다.
  glColor3f(R, G, B);
  glBegin(GL_POLYGON);
    glVertex3f(-0.5,-0.5,0.0);
    glVertex3f(0.5,-0.5,0.0);
    glVertex3f(0.5,0.5,0.0);
    glVertex3f(-0.5,0.5,0.0);
  glEnd();
  glFlush();
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y){
  switch (KeyPressed)
  {
  //r, g, b가 눌리는 순간
  // 1) RGB값을 해당 키에 맞는 색깔로 변경하고
  // 2) glutPostRedisplay 함수로 display 콜백함수를 재호출합니다.
  // 3) 그러면 사각형 색깔이 변하게 되겠죠!
  case 'r':
    R=1;G=0;B=0;
    glutPostRedisplay();
    break;

  case 'g':
    R=0;G=1;B=0;
    glutPostRedisplay();
    break;

  case 'b':
    R=0;G=0;B=1;
    glutPostRedisplay();
    break;
  
  case 'Q':
    exit(0);
    break;
  
  case 'q':
    exit(0);
    break;

  case 27:
    exit(0);
    break;
  }
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowSize(300,300);
  glutInitWindowPosition(0,0);
  glutCreateWindow("KangJunewoo Computer Graphics");
  glClearColor(1.0,1.0,1.0,1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0,1.0,-1.0,1.0,-1.0,1.0);
  glutDisplayFunc(MyDisplay);
  glutKeyboardFunc(MyKeyboard);
  glutMainLoop();
  return 0;
}