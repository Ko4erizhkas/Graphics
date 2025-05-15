//#include <GL/glut.h>
//#include <stdlib.h>
//
///*  Initialize material property, light source, lighting model,
// *  and depth buffer.
// */
//void init(void)
//{
//    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat mat_shininess[] = { 50.0 };
//    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
//    GLfloat global_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
//    
//    GLfloat diffuse1[] = { 1.0, 0.0, 0.0, 1.0 };
//    GLfloat ambient1[] = { 1.0, 0.0, 0.0, 1.0 };
//    GLfloat specular1[] = { 1.0, 1.0, 1.0, 1.0 };
//    GLfloat light_position1[] = { 1.0, 2.0, 3.0, 0.0};
//
//
//    // Параметры прожектора (GL_LIGHT2)
//    GLfloat light2_position[] = { 1.0, 1.0, 6.0, 1.0};  // Позиция прожектора
//    GLfloat light2_diffuse[] = { 1.0, 1.0, 1.0};   // Белый свет
//    GLfloat light2_specular[] = { 1.0, 1.0, 1.0};  // Блики
//    GLfloat light2_ambient[] = { 0.0, 0.0, 1.0};   // Слабая фоновая составляющая
//    GLfloat spot_direction[] = {0.0, 0.0, -1.0};
//    GLfloat cutoff = 3.0f;
//    GLfloat exp = 2.0f;
//
//    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
//    glShadeModel(GL_SMOOTH);
//
//    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
//    
//    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
//
//
//    glEnable(GL_LIGHTING);
//   /* glEnable(GL_LIGHT0);
//
//    glEnable(GL_LIGHT1);
//    glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
//    glLightfv(GL_LIGHT1, GL_AMBIENT, ambient1);
//    glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuse1);
//    glLightfv(GL_LIGHT1, GL_SPECULAR, specular1);
//   */
//
//
//    glEnable(GL_LIGHT2);
//    glLightfv(GL_LIGHT2, GL_POSITION, light2_position);
//    glLightfv(GL_LIGHT2, GL_AMBIENT, light2_ambient);
//    glLightfv(GL_LIGHT2, GL_DIFFUSE, light2_diffuse);
//    glLightfv(GL_LIGHT2, GL_SPECULAR, light2_specular);
//    glLightfv(GL_LIGHT2,GL_SPOT_DIRECTION, spot_direction);
//    glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 25);
//    glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 2);
//
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_COLOR_MATERIAL);
//}
//
//void display(void)
//{
//    
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glColor3f(1.0, 0.0, 0.0);
//    glutSolidSphere(1.0, 50, 50);
//    glFlush();
//}
//
//void reshape(int w, int h)
//{
//    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    if (w <= h)
//        glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w,
//            1.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
//    else
//        glOrtho(-1.5 * (GLfloat)w / (GLfloat)h,
//            1.5 * (GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//}
//
//void keyboard(unsigned char key, int x, int y)
//{
//    switch (key) {
//    case 27:
//        exit(0);
//        break;
//    }
//}
//
//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(800, 800);
//    glutInitWindowPosition(100, 100);
//    glutCreateWindow(argv[0]);
//    init();
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//    glutKeyboardFunc(keyboard);
//    glutMainLoop();
//    return 0;
//}