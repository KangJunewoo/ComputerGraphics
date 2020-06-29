#include <Windows.h>
#include <gl/glut.h>

//콜백함수 실행하는동안 값이 변경되야할 전역변수들
GLboolean IsSphere = true;

void MyDisplay() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.5,0.0,0.5);
  if(IsSphere){
    glutWireSphere(0.2,15,15);
  } else{
    glutWireTorus(0.1,0.3,40,20);
  }
  glFlush();
}

//특정 메뉴 선택시 display에 변화를 주는 콜백함수입니다.
void MyMainMenu(int entryID){
  //첫번째거 선택하면 sphere, 두번째거 선택하면 torus, 세번째거 선택하면 exit
  if(entryID==1){
    IsSphere=true;
  } else if(entryID==2){
    IsSphere=false;
  } else if(entryID==3){
    exit(0);
  }
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
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

  //여기서 메뉴를 만들고 콜백을 등록한 뒤, 1,2,3번에 각각 문자열을 부여합니다.
  GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
  glutAddMenuEntry("Draw Sphere", 1);
  glutAddMenuEntry("Draw Torus", 2);
  glutAddMenuEntry("ByeBye", 3);
  //오른쪽 클릭할때 만든 메뉴를 attach합니다.
  glutAttachMenu(GLUT_RIGHT_BUTTON);

  glutDisplayFunc(MyDisplay);
  glutMainLoop();
  return 0;
}