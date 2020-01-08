#include <stdio.h>
#include <GL/glut.h>

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
        glVertex2f(0.1, -0.1);
        glVertex2f(-0.2, -0.1);
        glVertex2f(-0.4, -0.4);
        glVertex2f(0.3, -0.4);
    glEnd();

    glBegin(GL_TRIANGLES);
        glVertex2f(-0.2, 0.2);
        glVertex2f(-0.6, 0.2);
        glVertex2f(-0.4, 0.4);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex2f(0.2, 0.2);
        glVertex2f(0.1, 0.35);
        glVertex2f(0.3, 0.5);
        glVertex2f(0.5, 0.35);
        glVertex2f(0.4, 0.2);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Different shapes");
    glutInitWindowSize(480, 480);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    initGL();
    glutMainLoop();
    return 0;
}