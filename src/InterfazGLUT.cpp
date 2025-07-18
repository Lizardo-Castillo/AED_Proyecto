#include "../include/InterfazGLUT.h"
#include <GL/glut.h>
#include <cmath>

// Nodo simple
struct Punto {
    float x, y;
};

// Nodos manuales (sin grafo)
const int NUM_NODOS = 5;
Punto nodos[NUM_NODOS] = {
    {100, 100},
    {200, 150},
    {300, 100},
    {250, 250},
    {150, 300}
};

// Conexiones entre pares de índices
int conexiones[][2] = {
    {0, 1},
    {1, 2},
    {1, 3},
    {3, 4},
    {4, 0}
};
const int NUM_CONEXIONES = sizeof(conexiones) / sizeof(conexiones[0]);

void inicializarVentana(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Visualización de nodos");

    glClearColor(1.0, 1.0, 1.0, 1.0); // Fondo blanco
    //gluOrtho2D(0.0, 800.0, 0.0, 600.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);
    glMatrixMode(GL_MODELVIEW);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    gluOrtho2D(0.0, width, 0.0, height);
}

void display() {

    glLoadIdentity();  // reset modelo
    glClear(GL_COLOR_BUFFER_BIT);  // limpiar pantalla

    // Dibujar conexiones
    glColor3f(0.6f, 0.6f, 0.6f); // gris
    for (int i = 0; i < NUM_CONEXIONES; ++i) {
        int from = conexiones[i][0];
        int to = conexiones[i][1];
        drawLine(nodos[from].x, nodos[from].y, nodos[to].x, nodos[to].y);
    }

    // Dibujar nodos
    glColor3f(1.0f, 0.0f, 0.0f); // rojo
    for (int i = 0; i < NUM_NODOS; ++i) {
        drawCircle(nodos[i].x, nodos[i].y, 6.0f);
    }

    glutSwapBuffers();
    glFlush();  // asegurar que todo se dibuje
}

void drawCircle(float x, float y, float r) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 20; ++i) {
        float angle = 2.0f * 3.1416f * i / 20;
        glVertex2f(x + r * cos(angle), y + r * sin(angle));
    }
    glEnd();
}

void drawLine(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}
