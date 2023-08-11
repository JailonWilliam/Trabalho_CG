
#ifndef CARRO_G
#define CARRO_H
#include <GL/glut.h>
#include "Cilindro.h"

void janela(){
    glBegin(GL_TRIANGLES);
        glColor3ub(0.0, 0.0, 0.0);
        // Janela 1
        glVertex3f(-1.0, 1.0, 2.75);
        glVertex3f(-1.5, -2.5, 2.0);
        glVertex3f(-1.5, 2.5, 2.0);

        // Janela 2
        glVertex3f(1.0, 1.0, 2.75);
        glVertex3f(1.5, -2.5, 2.0);
        glVertex3f(1.5, 2.5, 2.0);
    glEnd();
}

void dianteira(){
    glBegin(GL_QUADS);
        // DIANTEIRA
        // superior
        glVertex3f( 1.0, 1.0, 2.75);
        glVertex3f(-1.0, 1.0, 2.75);
        glVertex3f(-1.5, -2.5, 2.0);
        glVertex3f( 1.5, -2.5, 2.0);
        
        // inferior 01
        glVertex3f( 1.5, -2.5, 2.0);
        glVertex3f(-1.5, -2.5, 2.0);
        glVertex3f(-1.5, -2.5, 1.0);
        glVertex3f( 1.5, -2.5, 1.0);
        
        // inferior 02
        glVertex3f( 1.5,  -2.5, 1.0);
        glVertex3f(-1.5,  -2.5, 1.0);
        glVertex3f(-1.25, -2.35, 0.5);
        glVertex3f( 1.25, -2.35, 0.5);
    glEnd();
}

void traseira(){
    glBegin(GL_QUADS);
        // TRASEIRA
        // superior
        glVertex3f(1.0, 1.0, 2.75);
        glVertex3f(-1.0, 1.0, 2.75);
        glVertex3f(-1.5, 2.5, 2.0);
        glVertex3f(1.5, 2.5, 2.0);
        
        // inferior 01
        glVertex3f( 1.5, 2.5, 2.0);
        glVertex3f(-1.5, 2.5, 2.0);
        glVertex3f(-1.5, 2.5, 1.0);
        glVertex3f( 1.5, 2.5, 1.0);
        
        
        // inferior 02
        glVertex3f( 1.5, 2.5, 1.0);
        glVertex3f(-1.5, 2.5, 1.0);
        glVertex3f(-1.25, 2.35, 0.5);
        glVertex3f( 1.25, 2.35, 0.5);
    glEnd();
}

void lateral_esq(){
    glBegin(GL_QUADS);
    // LATERAL ESQUERDA
        // part 01
        glVertex3f(-1.5, -1.875, 2.0);
        glVertex3f(-1.5, -2.5,   2.0);
        glVertex3f(-1.5, -2.5,   1.0);
        glVertex3f(-1.5, -1.875, 1.0);
        
        // L.E part 02
        glVertex3f(-1.5,  -1.875,   1.0);
        glVertex3f(-1.5,  -2.5,     1.0);
        glVertex3f(-1.25, -2.35,    0.5);
        glVertex3f(-1.25, -2.0375, 0.5);

        // L.E part 03
        glVertex3f(-1.5, 2.5,    2.0);
        glVertex3f(-1.5, -1.875, 2.0);
        glVertex3f(-1.5, -1.875, 1.0);
        glVertex3f(-1.5, 2.5,    1.0);

        // L.E part 04
        glVertex3f(-1.5,  1.1,  1.0);
        glVertex3f(-1.5, -1.1,  1.0);
        glVertex3f(-1.25, -0.87, 0.5);
        glVertex3f(-1.25,  0.87, 0.5);

        // L.E part 05
        glVertex3f(-1.5,  1.875,  1.0);
        glVertex3f(-1.5,  2.5,    1.0);
        glVertex3f(-1.25, 2.35,   0.5);
        glVertex3f(-1.25, 2.0375, 0.5);
    glEnd();
}

void lateral_dir(){
        glBegin(GL_QUADS);
        // TRASEIRA

        // LATERAL DIREITA
        // L.D part 01
        glVertex3f(1.5, -1.875, 2.0);
        glVertex3f(1.5, -2.5,   2.0);
        glVertex3f(1.5, -2.5,   1.0);
        glVertex3f(1.5, -1.875, 1.0);
        
        // L.D part 02
        glVertex3f(1.5,  -1.875,   1.0);
        glVertex3f(1.5,  -2.5,     1.0);
        glVertex3f(1.25, -2.35,    0.5);
        glVertex3f(1.25, -2.0375, 0.5);

        // L.D part 03
        glVertex3f(1.5, 2.5,    2.0);
        glVertex3f(1.5, -1.875, 2.0);
        glVertex3f(1.5, -1.875, 1.0);
        glVertex3f(1.5, 2.5,    1.0);

        // L.D part 04
        glVertex3f(1.5,  1.1,  1.0);
        glVertex3f(1.5, -1.1,  1.0);
        glVertex3f(1.25, -0.87, 0.5);
        glVertex3f(1.25,  0.87, 0.5);

        // L.D part 05
        glVertex3f(1.5,  1.875,  1.0);
        glVertex3f(1.5,  2.5,    1.0);
        glVertex3f(1.25, 2.35,   0.5);
        glVertex3f(1.25, 2.0375, 0.5);

        glEnd();

}

void rodas(){ 
    // utilizando cilindro.h para fazer as rodas
    // Roda 1
    glPushMatrix();
    glTranslated(-1.25, 1.45, 0.50);
    cilindro(0.5f, 0.8, 20);
    glPopMatrix();

    // Roda 2
    glPushMatrix();
    glTranslated(1.25, 1.45, 0.50);
    cilindro(0.5f, 0.8, 20);
    glPopMatrix();

    // Roda 3
    glPushMatrix();
    glTranslated(-1.25, -1.45, 0.50);
    cilindro(0.5f, 0.8, 20);
    glPopMatrix();

    // Roda 4
    glPushMatrix();
    glTranslated(1.25, -1.45, 0.50);
    cilindro(0.5f, 0.8, 20);
    glPopMatrix();
}

void carro(int modo, float r, float g, float b){
    glColor3ub(r, g, b);
    glPolygonMode(GL_FRONT_AND_BACK, modo);
    dianteira();
    traseira();
    lateral_dir();
    lateral_esq();
    rodas();
    janela();

}

#endif
