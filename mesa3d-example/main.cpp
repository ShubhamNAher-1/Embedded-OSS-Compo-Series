/*
    Author - ShubhamNAher
    C++ code initializes an OpenGL context and renders a simple triangle on the screen
    Date:29-Oct-2024
*/

#include <GL/gl.h>
#include <GL/freeglut.h>

// Function to display a simple triangle
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f); // Red color
        glVertex2f(-0.5f, -0.5f);

        glColor3f(0.0f, 1.0f, 0.0f); // Green color
        glVertex2f(0.5f, -0.5f);

        glColor3f(0.0f, 0.0f, 1.0f); // Blue color
        glVertex2f(0.0f, 0.5f);
    glEnd();

    glFlush();
}

// Function to initialize OpenGL settings
void initOpenGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mesa3D Triangle Example");

    initOpenGL();

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
