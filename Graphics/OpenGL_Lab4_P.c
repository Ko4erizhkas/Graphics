//#include <windows.h>
//#include <GL/gl.h>
//#include <GL/glu.h>
//#include <GL/glut.h>
//
//
//float aspect = 0;
//
//GLfloat vertices[][3] = {
//    {-1.0, -1.0, -1.0}, 
//    {1.0, -1.0, -1.0},  
//    {1.0, 1.0, -1.0},   
//    {-1.0, 1.0, -1.0},  
//    {-1.0, -1.0, 1.0},  
//    {1.0, -1.0, 1.0},   
//    {1.0, 1.0, 1.0},    
//    {-1.0, 1.0, 1.0}    
//};
//
//GLfloat colors[][3] = {
//    {1.0, 0.0, 0.0}, // красный
//    {1.0, 1.0, 0.0}, // желтый
//    {0.0, 1.0, 0.0}, // зеленый
//    {0.0, 0.0, 1.0}, // синий
//    {1.0, 0.0, 1.0}, // фиолетовый
//    {0.0, 1.0, 1.0}  // голубой
//};
//
//
//void polygon(int a, int b, int c, int d, int col)
//{
//    glBegin(GL_QUADS);
//    glColor3fv(colors[col]);
//    glVertex3fv(vertices[a]);
//    glVertex3fv(vertices[b]);
//    glVertex3fv(vertices[c]);
//    glVertex3fv(vertices[d]);
//    glEnd();
//}
//
//void colorcube()
//{
//    
//    glViewport(400, 0, 400, 400);
//    polygon(0, 3, 2, 1, 0);
//    polygon(4, 7, 6, 5, 1);
//    polygon(3, 2, 6, 7, 2);
//    polygon(0, 4, 5, 1, 3);
//    polygon(0, 3, 7, 4, 4);
//    polygon(1, 5, 6, 2, 5);
//
//    glViewport(0, 400, 400, 400);
//    polygon(0, 3, 2, 1, 0);
//    polygon(4, 7, 6, 5, 1);
//    polygon(3, 2, 6, 7, 2);
//    polygon(0, 4, 5, 1, 3);
//    polygon(0, 3, 7, 4, 4);
//    polygon(1, 5, 6, 2, 5);
//
//    glViewport(400, 400, 400, 400);
//    polygon(0, 3, 2, 1, 0);
//    polygon(4, 7, 6, 5, 1);
//    polygon(3, 2, 6, 7, 2);
//    polygon(0, 4, 5, 1, 3);
//    polygon(0, 3, 7, 4, 4);
//    polygon(1, 5, 6, 2, 5);
//}
//
//void drawCube(int x, int y, int width, int height)
//{
//    glViewport(x, y, width, height);
//    polygon(0, 3, 2, 1, 0);
//    polygon(4, 7, 6, 5, 1);
//    polygon(3, 2, 6, 7, 2);
//    polygon(0, 4, 5, 1, 3);
//    polygon(0, 3, 7, 4, 4);
//    polygon(1, 5, 6, 2, 5);
//}
//
//void drawDimetric()
//{
//    glLoadIdentity();
//    gluLookAt(10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); 
//
//
//    glRotatef(22.208, 1.0, 1.0, 0.0);
//    glRotatef(20.705, 1.0, 1.0, 0.0);
//
//    drawCube(0,0,400,400);
//
//}
//void drawOrtho()
//{
//    glLoadIdentity();
//    gluLookAt(10.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); 
//
//    glMatrixMode(GL_MODELVIEW);
//    glRotatef(0.0, 1.0, 1.0, 1.0);
//    drawCube(0,400,400,400);
//}
//void drawPerspective()
//{
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    gluLookAt(10.0, 10.0, 10.0,
//        0.0, 0.0, 0.0,
//        0.0, 1.0, 0.0); 
//    drawCube(400,0,400,400);
//}
//void drawIsometric()
//{
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    gluLookAt(10.0, 0.0, 0.0,
//              0.0, 0.0, 0.0,
//              0.0, 1.0, 0.0);
//    glRotatef(35.264, 1.0, 0.0, 0.0);
//    glRotatef(-45, 0.0, 1.0, 0.0);
//
//    drawCube(400, 400, 400, 400);
//}
//
//void display()
//{
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//
//    drawDimetric();
//
//    drawOrtho();
//    
//    drawIsometric();
//
//    drawPerspective();
//
//    glutSwapBuffers();
//    glutPostRedisplay(); 
//}
//
//void init()
//{
//    glEnable(GL_DEPTH_TEST);
//    glClearColor(0.5, 0.5, 0.5, 1.0);
//    glShadeModel(GL_SMOOTH);
//}
//
//void reshape(int w, int h)
//{
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 0.1, 100.0);
//    glMatrixMode(GL_MODELVIEW);
//    aspect = (float)w / h;
//}
//
//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(800, 800);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow("Color Cube");
//
//    init();
//
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//
//    glutMainLoop();
//    return 0;
//}
