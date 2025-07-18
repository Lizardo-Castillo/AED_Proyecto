// Dibujo y eventos con GLUT
#ifndef INTERFAZ_GLUT_HPP
#define INTERFAZ_GLUT_HPP

void inicializarVentana(int argc, char** argv);
void display();
void reshape(int width, int height);

void drawCircle(float x, float y, float r);
void drawLine(float x1, float y1, float x2, float y2);

#endif
