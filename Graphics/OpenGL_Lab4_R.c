#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glut.h>
#include <math.h>
#include <stdio.h>


float x = 0.0f;
float y = 0.0f;
float z = 0.0f;
float R = 10.0f;
float cameraAngleY = 0.0f;

GLfloat vertices[][3] = {
    {-1.0, -1.0, -1.0}, // 0
    {1.0, -1.0, -1.0},  // 1
    {1.0, 1.0, -1.0},   // 2
    {-1.0, 1.0, -1.0},  // 3
    {-1.0, -1.0, 1.0},  // 4
    {1.0, -1.0, 1.0},   // 5
    {1.0, 1.0, 1.0},    // 6
    {-1.0, 1.0, 1.0}    // 7
};

GLfloat colors[][3] = {
    {1.0, 0.0, 0.0}, // красный
    {1.0, 1.0, 0.0}, // желтый
    {0.0, 1.0, 0.0}, // зеленый
    {0.0, 0.0, 1.0}, // синий
    {1.0, 0.0, 1.0}, // фиолетовый
    {0.0, 1.0, 1.0}  // голубой
};


void polygon(int a, int b, int c, int d, int col)
{
    glBegin(GL_QUADS);
    glColor3fv(colors[col]);
    glVertex3fv(vertices[a]);
    glVertex3fv(vertices[b]);
    glVertex3fv(vertices[c]);
    glVertex3fv(vertices[d]);
    glEnd();
}



void mouseReg(int button, int state)
{

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
      {
        cameraAngleY -= 0.1f;
      }

    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        	{
        cameraAngleY += 0.1f;
        	}

}


void colorcube()
{
    
    // Передняя грань (z = -1)
    polygon(0, 3, 2, 1, 0);
    // Задняя грань (z = 1)
    polygon(4, 7, 6, 5, 1);
    // Верхняя грань (y = 1)
    polygon(3, 2, 6, 7, 2);
    // Нижняя грань (y = -1)
    polygon(0, 4, 5, 1, 3);
    // Левая грань (x = -1)
    polygon(0, 3, 7, 4, 4);
    // Правая грань (x = 1)
    polygon(1, 5, 6, 2, 5);

    
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
  
    gluLookAt(x + R*cos(cameraAngleY), 4.0f, z+R*sin(cameraAngleY), 0.0, 0.0, 0.0, 0.0f, 1.0f, 0.0f); // камера под углом

    colorcube();

    glutSwapBuffers();
    glutPostRedisplay(); // для анимации (если нужно)
}

void init()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.5, 0.5, 0.5, 1.0);
    glShadeModel(GL_SMOOTH);
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 0.1, 100.0); // исправлены near/far
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Color Cube");

    init();
    glutMouseFunc(mouseReg);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    glutMainLoop();
    return 0;
}