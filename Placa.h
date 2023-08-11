#ifndef PLACA_H
#define PLACA_H
#include <GL/glut.h>


void base(int mode){
    if (mode == GL_FILL){
        glColor3ub(30.0, 30.0, 30.0);
    }
    glBegin(GL_QUADS);
        // Lateral 1
        glVertex3f(-0.125, 0.125, 0.125);
        glVertex3f(0.125, 0.125, 0.125);
        glVertex3f(0.125, 0.125, 0.0);
        glVertex3f(-0.125, 0.125, 0.0);
            
        // Lateral 2
        glVertex3f(0.125, 0.125, 0.125);
        glVertex3f(0.125, -0.125, 0.125);
        glVertex3f(0.125, -0.125, 0.0);
        glVertex3f(0.125, 0.125, 0.0);

        // Lateral 3
        glVertex3f(-0.125, -0.125, 0.125);
        glVertex3f(0.125, -0.125, 0.125);
        glVertex3f(0.125, -0.125, 0.0);
        glVertex3f(-0.125, -0.125, 0.0);
        
        // Lateral 4
        glVertex3f(-0.125, 0.125, 0.125);
        glVertex3f(-0.125, -0.125, 0.125);
        glVertex3f(-0.125, -0.125, 0.0);
        glVertex3f(-0.125, 0.125, 0.0);

        // Lateral superior
        glVertex3f(-0.125, -0.125, 0.125);
        glVertex3f(0.125, -0.125, 0.125);
        glVertex3f(0.125, 0.125, 0.125);
        glVertex3f(-0.125, 0.125, 0.125);
    glEnd();
}

void poste_ferro(){
    glBegin(GL_QUADS);
        // Lateral 1
        glVertex3f(-0.0625, 0.0625, 1.8);
        glVertex3f( 0.0625, 0.0625, 1.8);
        glVertex3f( 0.0625, 0.0625, 0.125);
        glVertex3f(-0.0625, 0.0625, 0.125);
            
        // Lateral 2
        glVertex3f(0.0625,  0.0625, 1.8);
        glVertex3f(0.0625, -0.0625, 1.8);
        glVertex3f(0.0625, -0.0625, 0.125);
        glVertex3f(0.0625,  0.0625, 0.125);

        // Lateral 3
        glVertex3f(-0.0625, -0.0625, 1.8);
        glVertex3f( 0.0625, -0.0625, 1.8);
        glVertex3f( 0.0625, -0.0625, 0.125);
        glVertex3f(-0.0625, -0.0625, 0.125);
        
        // Lateral 4
        glVertex3f(-0.0625,  0.0625, 1.8);
        glVertex3f(-0.0625, -0.0625, 1.8);
        glVertex3f(-0.0625, -0.0625, 0.125);
        glVertex3f(-0.0625,  0.0625, 0.125);

        // Lateral superior
        glVertex3f(-0.0625, -0.0625, 1.8);
        glVertex3f( 0.0625, -0.0625, 1.8);
        glVertex3f( 0.0625,  0.0625, 1.8);
        glVertex3f(-0.0625,  0.0625, 1.8);
    glEnd();
}

void triangulo_placa(int mode){
    if (mode == GL_FILL){
        glColor3ub(255.0, 0.0, 0.0);
    }

    glBegin(GL_QUADS);  
        // Lateral 1
        glVertex3f(0.0, -0.0625, 2.2);
        glVertex3f(0.0, -0.125,  2.2);
        glVertex3f(0.5, -0.125,  1.5);
        glVertex3f(0.5, -0.0625, 1.5);
            
        // Lateral 2
        glVertex3f(0.0,  -0.0625, 2.2);
        glVertex3f(0.0,  -0.125,  2.2);
        glVertex3f(-0.5, -0.125,  1.5);
        glVertex3f(-0.5, -0.0625, 1.5);
        
        // Lateral 3
        glVertex3f(-0.5, -0.0625, 1.5);
        glVertex3f( 0.5, -0.0625, 1.5);
        glVertex3f( 0.5, -0.125,  1.5);
        glVertex3f(-0.5, -0.125,  1.5);
    glEnd();

    glBegin(GL_TRIANGLES);
        // Frente
        glVertex3f( 0.0, -0.0625, 2.2);
        glVertex3f( 0.5, -0.0625, 1.5);
        glVertex3f(-0.5, -0.0625, 1.5);
        
        // Trás
        glVertex3f( 0.0, -0.125, 2.2);
        glVertex3f( 0.5, -0.125, 1.5);
        glVertex3f(-0.5, -0.125, 1.5);
    glEnd();
}

void sinal_placa(){
    // Triangulo branco interno
    glColor3ub(255.0f, 255.0f, 255.0f);  
    glBegin(GL_TRIANGLES);
        glVertex3f( 0.0, -0.126, 2.1);
        glVertex3f( 0.4, -0.126, 1.54);
        glVertex3f(-0.4, -0.126, 1.54);
    glEnd();

    // Sinal dentro da placa
    glColor3ub(10.0f, 10.0f, 10.0f);  
    glBegin(GL_QUADS);
        glVertex3f( 0.05, -0.127, 2.0);
        glVertex3f(-0.05, -0.127, 2.0);
        glVertex3f(-0.05, -0.127, 1.7);
        glVertex3f( 0.05, -0.127, 1.7);
        
        glVertex3f( 0.05, -0.127, 1.65);
        glVertex3f(-0.05, -0.127, 1.65);
        glVertex3f(-0.05, -0.127, 1.57);
        glVertex3f( 0.05, -0.127, 1.57);
        
    glEnd();

    

}

void placa(int mode, float r, float g, float b){
    glPolygonMode(GL_FRONT_AND_BACK, mode);
    glColor3ub(r, g, b); // para linhas 3d
    poste_ferro();
    sinal_placa();

    // cores fixas
    triangulo_placa(mode);
    base(mode);

}




#endif