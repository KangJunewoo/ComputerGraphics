#include <Windows.h>
#include <gl/glut.h>

//콜백함수
void MyDisplay() {
  //color값 초기화
  glClear(GL_COLOR_BUFFER_BIT);
  //뷰포트 설정. 윈도우 크기에 영향을 안받도록! 순서대로 x, y, width, height
  glViewport(0, 0, 300, 300);
  //색깔 설정.
  glColor3f(1.0, 1.0, 1.0);
  
  //glBegin부터 glEnd까지 polygon을 정의하겠다!
  //-1.0~1.0 사이의 값을 가질 수 있지.
  glBegin(GL_POLYGON);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
  glEnd();

  //지금까지의 명령어를 모두 프로세스에 전달하겠다! 역시 맨마지막에 나오는 코드.
  glFlush();
}

//모두 glut 함수.
int main(int argc, char** argv) {
  //말그대로 glut init.
  glutInit(&argc, argv);
    //기본칼라모드는 RGB로 하겠다
    glutInitDisplayMode(GLUT_RGB);
    //윈도우 크기는 300 * 300으로 하고
    glutInitWindowSize(300, 300);
    //윈도우 좌표의 (0,0) 즉 윈도우창을 맨왼쪽맨위에 띄우겠다.
    glutInitWindowPosition(0, 0);
  
  //다음의 타이틀로 새로운 윈도우를 만들어라!
  glutCreateWindow("Sample Drawing by KangJunewoo");
  //배경색 설정. R G B 알파값.
  glClearColor(0.0, 0.0, 0.0, 1.0);
  
  
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
  
  
  
  //display 이벤트의 콜백함수로 MyDisplay를 등록하겠다
  glutDisplayFunc(MyDisplay);

  //항상 이걸로 끝나야함.
  glutMainLoop();
  return 0;
}