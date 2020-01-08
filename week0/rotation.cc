#include <stdio.h>
#include <GL/glut.h>

GLfloat angle = 0.0f;

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void idle() {
   glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);     // To operate on Model-View matrix
    glLoadIdentity();               // Reset the model-view matrix

    glPushMatrix();                     
    glTranslatef(0.0f, -0.4f, 0.0f);
    glRotatef(angle, 1.0f, 2.0f, 3.0f);
    glBegin(GL_QUADS);
        glVertex2f(0.1, 0.1);
        glVertex2f(-0.2, 0.1);
        glVertex2f(-0.4, -0.2);
        glVertex2f(0.3, -0.2);
    glEnd();
    glPopMatrix();

    glPushMatrix();                     
    glTranslatef(-0.4, 0.4, 0.0);
    glRotatef(angle, 3.0f, 1.0f, 2.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.15, -0.1);
        glVertex2f(-0.15, -0.1);
        glVertex2f(0.0, 0.15);
    glEnd();
    glPopMatrix();

    glPushMatrix();                     
    glTranslatef(0.4, 0.4, 0.0);
    glRotatef(angle, 2.0f, 3.0f, 1.0f);
    glBegin(GL_POLYGON);
        glVertex2f(0.1, 0.0);
        glVertex2f(0.0, 0.1);
        glVertex2f(-0.1, 0.0);
        glVertex2f(-0.05, -0.1);
        glVertex2f(0.05, -0.1);
    glEnd();
    glPopMatrix();

    glutSwapBuffers();

    angle += 1.0f;
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutCreateWindow("Different shapes");
    glutInitWindowSize(480, 480);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    initGL();
    glutMainLoop();
    return 0;
}