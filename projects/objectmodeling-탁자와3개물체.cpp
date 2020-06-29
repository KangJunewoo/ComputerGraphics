/*
  * Computer Graphics Object Modeling
  * coded by 2016312924 강준우
*/

#include <Windows.h>
#include <gl/glut.h>

// smooth vs flat 결정. 기본값 smooth
int FlatShaded = 0;
// solid vs wire 결정. 기본값 solid
int WireFramed = 0;

// mouse movement 담아내는 변수들
int ViewX = 400, ViewY = 400;

void DrawWireTable() {
  /**
   * GL_LINES를 통해 사각형을 여러개 그리는 식으로 구현.
   * glNormal3f 함수로 조명을 자연스럽게 받도록 법선벡터를 설정하고
   * glVertex3f 8개로 각 좌표를 찍어 4개의 선을 만듦.
   * 그걸 5번 해서 테이블을 만듦.
   *
  */
  glBegin(GL_LINES);

  // 테이블 윗판
  glNormal3f(0.0, 1.0, 0.0);
  glVertex3f(-0.5, 0.0, -0.5);
  glVertex3f(0.5, 0.0, -0.5);
  glVertex3f(0.5, 0.0, -0.5);
  glVertex3f(0.5, 0.0, 0.5);
  glVertex3f(0.5, 0.0, 0.5);
  glVertex3f(-0.5, 0.0, 0.5);
  glVertex3f(-0.5, 0.0, 0.5);
  glVertex3f(-0.5, 0.0, -0.5);

  // 테이블 다리 1
  glNormal3f(0.0, 0.0, 1.0);
  glVertex3f(-0.5, -0.5, -0.5);
  glVertex3f(-0.4, -0.5, -0.5);
  glVertex3f(-0.4, -0.5, -0.5);
  glVertex3f(-0.4, 0.0, -0.5);
  glVertex3f(-0.4, 0.0, -0.5);
  glVertex3f(-0.5, 0.0, -0.5);
  glVertex3f(-0.5, 0.0, -0.5);
  glVertex3f(-0.5, -0.5, -0.5);

  // 테이블 다리 2
  glNormal3f(0.0, 0.0, 1.0);
  glVertex3f(0.4, -0.5, -0.5);
  glVertex3f(0.5, -0.5, -0.5);
  glVertex3f(0.5, -0.5, -0.5);
  glVertex3f(0.5, 0.0, -0.5);
  glVertex3f(0.5, 0.0, -0.5);
  glVertex3f(0.4, 0.0, -0.5);
  glVertex3f(0.4, 0.0, -0.5);
  glVertex3f(0.4, -0.5, -0.5);

  // 테이블 다리 3
  glNormal3f(0.0, 0.0, 1.0);
  glVertex3f(0.4, -0.5, 0.5);
  glVertex3f(0.5, -0.5, 0.5);
  glVertex3f(0.5, -0.5, 0.5);
  glVertex3f(0.5, 0.0, 0.5);
  glVertex3f(0.5, 0.0, 0.5);
  glVertex3f(0.4, 0.0, 0.5);
  glVertex3f(0.4, 0.0, 0.5);
  glVertex3f(0.4, -0.5, 0.5);

  // 테이블 다리 4
  glNormal3f(0.0, 0.0, 1.0);
  glVertex3f(-0.5, -0.5, 0.5);
  glVertex3f(-0.4, -0.5, 0.5);
  glVertex3f(-0.4, -0.5, 0.5);
  glVertex3f(-0.4, 0.0, 0.5);
  glVertex3f(-0.4, 0.0, 0.5);
  glVertex3f(-0.5, 0.0, 0.5);
  glVertex3f(-0.5, 0.0, 0.5);
  glVertex3f(-0.5, -0.5, 0.5);
  glEnd();
}

void DrawSolidTable() {
  /**
   * GL_QUADS를 통해 사각형을 여러개 그리는 식으로 구현.
   * glNormal3f 함수로 조명을 자연스럽게 받도록 법선벡터를 설정하고
   * glVertex3f 4개로 각 좌표를 찍어서 사각형을 만듦.
   * 그걸 5번 해서 테이블을 만듦.
   *
  */
  glBegin(GL_QUADS);
  
  // 테이블 윗판
  glNormal3f(0.0, 1.0, 0.0);
  glVertex3f(-0.5, 0.0, -0.5);
  glVertex3f(0.5, 0.0, -0.5);
  glVertex3f(0.5, 0.0, 0.5);
  glVertex3f(-0.5, 0.0, 0.5);

  // 테이블 다리 1
  glNormal3f(0.0, 0.0, 1.0);
  glVertex3f(-0.5, -0.5, -0.5);
  glVertex3f(-0.4, -0.5, -0.5);
  glVertex3f(-0.4, 0.0, -0.5);
  glVertex3f(-0.5, 0.0, -0.5);

  // 테이블 다리 2
  glNormal3f(0.0, 0.0, 1.0);
  glVertex3f(0.4, -0.5, -0.5);
  glVertex3f(0.5, -0.5, -0.5);
  glVertex3f(0.5, 0.0, -0.5);
  glVertex3f(0.4, 0.0, -0.5);

  // 테이블 다리 3
  glNormal3f(0.0, 0.0, 1.0);
  glVertex3f(0.4, -0.5, 0.5);
  glVertex3f(0.5, -0.5, 0.5);
  glVertex3f(0.5, 0.0, 0.5);
  glVertex3f(0.4, 0.0, 0.5);

  // 테이블 다리 4
  glNormal3f(0.0, 0.0, 1.0);
  glVertex3f(-0.5, -0.5, 0.5);
  glVertex3f(-0.4, -0.5, 0.5);
  glVertex3f(-0.4, 0.0, 0.5);
  glVertex3f(-0.5, 0.0, 0.5);

  glEnd();
}

void InitLight() {
  GLfloat mat_diffuse[] = { 0.5, 0.4, 0.3, 1.0 };
  GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
  GLfloat mat_shininess[] = { 15.0 };

  GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
  GLfloat light_ambient[] = { 0.3, 0.3, 0.3, 1.0 };
  GLfloat light_position[] = { -3, 6, 3.0, 0.0 };

  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);

  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

  glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
  glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void MyMouseMove(GLint X, GLint Y) {
  // 마우스 움직임 X, Y를 전역변수인 ViewX, ViewY에 할당
  ViewX = X; ViewY = Y;
  glutPostRedisplay();
}

void MyKeyboard(unsigned char key, int x, int y) {
  switch (key) {
    // Q, q가 눌렸다면 exit
  case 'q':
  case 'Q':
  case '\033':
    exit(0);
    break;

    // S, s가 눌렸다면 smooth-flat shademodel 전환
  case 'S':
  case 's':
    if (FlatShaded) {
      FlatShaded = 0;
      glShadeModel(GL_SMOOTH);
    }
    else {
      FlatShaded = 1;
      glShadeModel(GL_FLAT);
    }
    glutPostRedisplay();
    break;

    // W, w가 눌렸다면 solid-wire rendering 전환
  case 'W':
  case 'w':
    if (WireFramed) {
      WireFramed = 0;
    }
    else {
      WireFramed = 1;
    }
    glutPostRedisplay();
    break;
  }
}

void MyDisplay() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // centerx와 centery를 마우스 클릭위치에 따라 변하게 해,
  // 도형이 다양한 시점에서 보여질 수 있게 함.
  gluLookAt(0.0, 0.0, 0.0, ViewX * 0.05 - 15.0, 15.0 - ViewY * 0.05, -1.0, 0.0, 1.0, 0.0);


  /**
    * PushMatrix, PopMatrix를 활용해
    * 각각의 object에 대해 rotation 및 translation 적용.
    * WireFramed 값에 따라 solid / wire 렌더링 반영

    * Torus : y방향으로 0.05만큼 이동, x방향으로 90도만큼 회전,
    * Cone : x, z방향으로 0.4만큼 이동,  x방향으로 -90도만큼 회전
    * Teapot : y방향으로 0.15만큼 이동
  */

  if (WireFramed) {
    // wire torus
    glPushMatrix();
    glTranslatef(0.0, 0.05, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glutWireTorus(0.05, 0.45, 10, 10);
    glPopMatrix();

    // wire cone
    glPushMatrix();
    glTranslatef(0.4, 0.0, 0.4);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glutWireCone(0.1, 0.2, 10, 10);
    glPopMatrix();

    // wire teapot
    glPushMatrix();
    glTranslatef(0.0, 0.15, 0.0);
    glutWireTeapot(0.2);
    glPopMatrix();

    // 한땀한땀 그려낸 wire table
    DrawWireTable();
  }
  else {
    // solid torus
    glPushMatrix();
    glTranslatef(0.0, 0.05, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glutSolidTorus(0.05, 0.45, 10, 10);
    glPopMatrix();

    // solid cone
    glPushMatrix();
    glTranslatef(0.4, 0.0, 0.4);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glutSolidCone(0.1, 0.2, 10, 10);
    glPopMatrix();

    // solid teapot
    glPushMatrix();
    glTranslatef(0.0, 0.15, 0.0);
    glutSolidTeapot(0.2);
    glPopMatrix();

    // 한땀한땀 그려낸 solid table
    DrawSolidTable();
  }


  glFlush();

}

void MyReshape(int w, int h) {
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("2016312924 강준우 Object Modeling");
  glClearColor(0.4, 0.4, 0.4, 0.0);

  InitLight();
  glutDisplayFunc(MyDisplay);
  glutKeyboardFunc(MyKeyboard);
  glutMotionFunc(MyMouseMove);
  glutReshapeFunc(MyReshape);
  glutMainLoop();
  return 0;
}