//#include <stdio.h>
//#include <gl/glut.h>
//#include <stdlib.h>
//#include <math.h>
//
//
//typedef struct{
//	float centerX, centerY; 
//	float radius;           
//	int valid;             
//} Circle;
//
//Circle circles[100];        
//int circleCount = 0;        
//int isDrawing = 0;     
//float startX, startY; 
//
//int windowHeight = 800;
//int windowWidth = 800;
//
//const int vertex = 100;
//
//void drawCircle(float x, float y, float R)
//{
//	glBegin(GL_LINE_LOOP);
//	glColor3f(1.0, 1.0, 0.0);
//	for (int i = 0; i < vertex; ++i)
//	{
//		float t = 2.0f * 3.14f * i / vertex;
//		glVertex2f(x + R * cos(t), y + R * sin(t));
//	}
//	glEnd();
//}
//void drawOnMouse(int button, int state, int x, int y)
//{
//	
//	float pixelY = windowHeight - y;
//
//	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//	{
//		if (!isDrawing)
//		{
//			
//			isDrawing = 1;
//			startX = x;
//			startY = pixelY;
//			circles[circleCount].centerX = x;
//			circles[circleCount].centerY = pixelY;
//			circles[circleCount].valid = 0; 
//			printf("Center (%.0f, %.0f)\n", circles[circleCount].centerX, circles[circleCount].centerY);
//		}
//		else
//		{
//			
//			float R = sqrt(pow(x - startX, 2) + pow(pixelY - startY, 2));
//			circles[circleCount].radius = R;
//			circles[circleCount].valid = 1; 
//			circleCount++;
//			isDrawing = 0;
//			printf("Radius %.0f pixels\n", R);
//		}
//		glutPostRedisplay(); 
//	}
//}
//void display(void)
//{
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	
//	for (int i = 0; i < circleCount; ++i)
//	{
//		if (circles[i].valid)
//		{
//			// Преобразуем экранные координаты (пиксели) в нормализованные координаты OpenGL
//			float aspect = (float)windowWidth / windowHeight;
//			float glCenterX, glCenterY, glRadius;
//			if (windowWidth >= windowHeight)
//			{
//				glCenterX = (2.0f * circles[i].centerX / windowWidth - 1.0f) * aspect;
//				glCenterY = 1.0f - 2.0f * circles[i].centerY / windowHeight;
//				glRadius = circles[i].radius * 2.0f * aspect / windowWidth;
//			}
//			else
//			{
//				glCenterX = 2.0f * circles[i].centerX / windowWidth - 1.0f;
//				glCenterY = (1.0f - 2.0f * circles[i].centerY / windowHeight) / aspect;
//				glRadius = circles[i].radius * 2.0f / windowHeight;
//			}
//			drawCircle(glCenterX, glCenterY, glRadius);
//		}
//	}
//
//	glutSwapBuffers();
//}
//void init(void)
//{
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glShadeModel(GL_FLAT);
//}
//
//void reshape(int w, int h)
//{
//	if (h == 0) h = 1;
//
//	glViewport(0, 0, w, h);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//
//	float aspect = (float)w / h;
//	if (w >= h)
//	{
//		// Если ширина больше высоты, расширяем горизонтальный диапазон
//		gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
//	}
//	else
//	{
//		// Если высота больше ширины, расширяем вертикальный диапазон
//		gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
//	}
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//int main(int argc, char** argv)
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(800, 800);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow(argv[0]);
//	init();
//
//	glutDisplayFunc(display);
//	glutReshapeFunc(reshape);
//
//	glutMouseFunc(drawOnMouse);
//
//	glutMainLoop();
//	return 0;
//}