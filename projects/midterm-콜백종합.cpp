/*
  * Computer Graphics 중간과제
  * coded by 강준우
*/


#include <Windows.h>
#include <gl/glut.h>


// 0~6 : cube, sphere, torus, cone, tetrahedron, icosahedron, teapot
GLint shape = 0;

// 0~3 : red, green, blue, gray
GLint color = 0;

// 마우스 드래그 때 회색으로 표시될 동안, 원래 색상을 임시 저장.
GLint color_temp = 0;

// true : solid / false : wireframe
GLboolean rendering_solid = true;

// true : move / false : stop
GLboolean animation_move = false;

// move 효과를 드래그하는 동안엔 적용하면 안되므로 선언.
GLboolean dragging = false;

// for animation
GLfloat delta = 0.0;

// start for click-down, end for click-up
GLint start_x=0, start_y=0, end_x=600, end_y=600;


// 마우스 클릭시 실행될 콜백함수
void callback_mouseclick(GLint button, GLint state, GLint x, GLint y);
// 마우스 드래그시 실행될 콜백함수
void callback_mousemove(GLint x, GLint y);
// 기본 디스플레이 함수
void display();
// 애니메이션으로 도형이 움직이게 하는 함수
void moving();

// 메인메뉴와 서브메뉴 4개
void mainmenu(int id);
void submenu_shape(int id);
void submenu_color(int id);
void submenu_rendering(int id);
void submenu_animation(int id);

void callback_mouseclick(GLint button, GLint state, GLint x, GLint y) {
  // 왼쪽마우스버튼 클릭상태이면 색상 회색으로 바꾸고 좌표값 저장.
  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    color = 3;
    dragging = true;
    start_x = x;
    start_y = y;
    glutPostRedisplay();
  }

  // 왼쪽마우스버튼 뗀 상태이면 원래색상 복귀시키고 좌표값 저장
  if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
    color = color_temp;
    dragging = false;
    end_x = x;
    end_y = y;
    glutPostRedisplay();
  }
}

void callback_mousemove(GLint x, GLint y) {
  // 마우스가 움직이는 동안 거치는 좌표 저장
  end_x = x;
  end_y = y;
  glutPostRedisplay();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  // 뷰포트 설정. 델타만큼 x값을 늘리고, 크기는 드래그한 범위에 따라 커지거나 작아짐.
  glViewport(delta, 0, end_x-start_x, end_y-start_y);
  
  // color 서브메뉴에서 지정한 id에 따라 색상 결정
  switch (color) {
  case 0: glColor3f(1.0, 0.0, 0.0); break;
  case 1: glColor3f(0.0, 1.0, 0.0); break;
  case 2: glColor3f(0.0, 0.0, 1.0); break;
  case 3: glColor3f(0.5, 0.5, 0.5); break;
  }

  // rendering 서브메뉴, shape 서브메뉴에서 지정한 값에 따라 solid/wire 및 shape 결정
  if (rendering_solid) {
    switch (shape) {
    case 0: glutSolidCube(0.5); break;
    case 1: glutSolidSphere(0.5, 10, 15); break;
    case 2: glutSolidTorus(0.5, 0.3, 10, 15); break;
    case 3: glutSolidCone(0.5, 0.8, 15, 20); break;
    case 4: glutSolidTetrahedron(); break;
    case 5: glutSolidIcosahedron(); break;
    case 6: glutSolidTeapot(0.5); break;
    }
  }
  else {
    switch (shape) {
    case 0: glutWireCube(0.5); break;
    case 1: glutWireSphere(0.5, 10, 15); break;
    case 2: glutWireTorus(0.5, 0.3, 10, 15); break;
    case 3: glutWireCone(0.5, 0.8, 15, 20); break;
    case 4: glutWireTetrahedron(); break;
    case 5: glutWireIcosahedron(); break;
    case 6: glutWireTeapot(0.5); break;
    }
  }


  glFlush();
  // 깜빡거림 방지 함수
  glutSwapBuffers();
}

void moving() {
  // animation_move가 true이고 dragging 상태가 아니면, 델타값 증가로 애니메이션 효과 적용
  if (animation_move && !dragging) {
    delta += 0.02;
    glutPostRedisplay();
  }
}

void mainmenu(int id) {
  // 서브메뉴가 들어갈 메인함수.
}

void submenu_shape(int id) {
  // id에 따라 shape을 정해주고, 좌표값을 초기화해준 뒤 반영.
  shape = id;
  start_x = 0; start_y = 0; end_x = 600; end_y = 600;
  glutPostRedisplay();
}

void submenu_color(int id) {
  // id값에 따라 color값과 color_temp값을 정해주고 반영
  color = id; color_temp = id;
  glutPostRedisplay();
}

void submenu_rendering(int id) {
  // id값에 따라 t/f 값 정한 뒤 반영
  if (id == 0) rendering_solid = true;
  else rendering_solid = false;
  glutPostRedisplay();
}

void submenu_animation(int id) {
  // id값에 따라 값 정한 뒤 반영
  if (id == 1) animation_move = false;
  else animation_move = true;
  glutPostRedisplay();
}

int main(int argc, char** argv) {
  // 초기 환경설정
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("KangJunewoo CG Midterm Assignment");
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

  // shape, rendering, color, animation 서브메뉴에 각각의 메뉴 등록
  GLint submenu_shape_id = glutCreateMenu(submenu_shape);
  glutAddMenuEntry("Cube", 0);
  glutAddMenuEntry("Sphere", 1);
  glutAddMenuEntry("Torus", 2);
  glutAddMenuEntry("Cone", 3);
  glutAddMenuEntry("Tetrahedron", 4);
  glutAddMenuEntry("Icosahedron", 5);
  glutAddMenuEntry("Teapot", 6);
  
  GLint submenu_rendering_id = glutCreateMenu(submenu_rendering);
  glutAddMenuEntry("Solid", 0);
  glutAddMenuEntry("Wireframe", 1);

  GLint submenu_color_id = glutCreateMenu(submenu_color);
  glutAddMenuEntry("Red", 0);
  glutAddMenuEntry("Green", 1);
  glutAddMenuEntry("Blue", 2);

  GLint submenu_animation_id = glutCreateMenu(submenu_animation);
  glutAddMenuEntry("Move", 0);
  glutAddMenuEntry("Stop", 1);


  // 위의 처리를 거친 네 개의 서브메뉴를 메인메뉴에 등록
  GLint mainmenu_id = glutCreateMenu(mainmenu);
  glutAddSubMenu("Shape", submenu_shape_id);
  glutAddSubMenu("Rendering", submenu_rendering_id);
  glutAddSubMenu("Color", submenu_color_id);
  glutAddSubMenu("Animation", submenu_animation_id);
  // 오른쪽 클릭시 메인메뉴가 나오도록 설정
  glutAttachMenu(GLUT_RIGHT_BUTTON);

  // glut에 지금까지 설정한 함수 모두 등록
  glutDisplayFunc(display);
  glutMouseFunc(callback_mouseclick);
  glutMotionFunc(callback_mousemove);
  glutIdleFunc(moving);
  
  //실행
  glutMainLoop();
  return 0;
}