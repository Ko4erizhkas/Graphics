#include <windows.h>
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


static GLuint texName;
int widthT, heightT, nrChannels;
float x = 0.0f;
float y = 0.0f;
float z = 0.0f;
float R = 10.0f;
float cameraAngleY = 0.0f;
void loadTexture()
{
    unsigned char* data = stbi_load("WoodTexture.jpg", &widthT, &heightT, &nrChannels, 0);

    if (!data)
    {
        printf("Ошибка загрузки текстуры\n");
        return;
    }

    
    glGenTextures(1, &texName);
    glBindTexture(GL_TEXTURE_2D, texName);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, widthT, 
        heightT, GL_RGB, GL_UNSIGNED_BYTE, data);

    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    stbi_image_free(data);
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
void drawCubeTexture()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texName);
    glColor3f(1.0f,1.0f,1.0f);
    
    float size = 0.5f;

    glBegin(GL_QUADS);

    // Передняя грань (z = +size)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-size, -size, size);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(size, -size, size);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(size, size, size);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-size, size, size);

    // Задняя грань (z = -size)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(size, -size, -size);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-size, -size, -size);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-size, size, -size);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(size, size, -size);

    // Верхняя грань (y = +size)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-size, size, size);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(size, size, size);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(size, size, -size);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-size, size, -size);

    // Нижняя грань (y = -size)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-size, -size, -size);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(size, -size, -size);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(size, -size, size);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-size, -size, size);

    // Правая грань (x = +size)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(size, -size, size);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(size, -size, -size);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(size, size, -size);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(size, size, size);

    // Левая грань (x = -size)
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-size, -size, -size);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-size, -size, size);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-size, size, size);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-size, size, -size);

    glEnd();

    glDisable(GL_TEXTURE_2D);


    glDisable(GL_TEXTURE_2D);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(x + R * cos(cameraAngleY), 4.0f, z + R * sin(cameraAngleY), 0.0, 0.0, 0.0, 0.0f, 1.0f, 0.0f);

    drawCubeTexture();

    glutSwapBuffers();
    glutPostRedisplay();
}

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    loadTexture();
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 10.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
    glutInitWindowSize(800, 800);
    glutCreateWindow("Textured Quad"); 


    glutDisplayFunc(display); 
    glutReshapeFunc(reshape); 

    init();

    glutMouseFunc(mouseReg);
    glutMainLoop();
    return 0;
}