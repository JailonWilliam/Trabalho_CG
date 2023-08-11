#ifndef DESENHO
#define DESENHO
#include <GL/glut.h>

void barreira(){
    glColor3ub(173.0f, 216.0f, 255.0f); // mesma cor do fundo da tela
    glBegin(GL_QUADS);
        glVertex3f(100.0f, 230.0f, 100.0f);
        glVertex3f(0.0f,   230.0f, 100.0f);
        glVertex3f(0.0f,   230.0f, 0.0f);
        glVertex3f(100.0f, 230.0f, 0.0f);
    glEnd();
}

void eixos(){
    glBegin(GL_LINES);

        //eixo x em vermelho
        glColor3f(1,0,0);
        glVertex3f(0,0,0);
        glVertex3f(100,0,0);
        
        //eixo -x em vermelho
        glColor3f(0.2,0,0);
        glVertex3f(0,0,0);
        glVertex3f(-100,0,0);
        
        ///////////////////////////

        //eixo y em verde
        glColor3f(0,1,0);
        glVertex3f(0,0,0);
        glVertex3f(0,100,0);


        //eixo -y em verde
        glColor3f(0,0.2,0);
        glVertex3f(0,0,0);
        glVertex3f(0,-100,0);
        
        /////////////////////////

        //eixo z em azul
        glColor3f(0,0,1);
        glVertex3f(0,0,0);
        glVertex3f(0,0,100);

        //eixo -z em azul
        glColor3f(0,0,0.2);
        glVertex3f(0,0,0);
        glVertex3f(0,0,-100);
    glEnd();
}

void grama(){  
    glBegin(GL_QUADS);
        glColor3ub(0.0, 150.0, 70.0);

        glVertex3f(200.0f, 100.0f, 0.0f);
        glVertex3f(-100.0f, 100.0f, 0.0f);
        glVertex3f(-100.0f, 0.0f, 0.0f);
        glVertex3f(200.0f, 0.0f, 0.0f);
    glEnd();
}

void pista(){
    glBegin(GL_QUADS);
        glColor3ub(40.0f, 40.0f, 40.0f);     
        
        glVertex3f(55.0f, 100.0f, 0.1f);
        glVertex3f(45.0f, 100.0f, 0.1f);
        glVertex3f(45.0f, 0.0f, 0.1f);
        glVertex3f(55.0f, 0.0f, 0.1f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(255.0f, 165.0f, 0.0f);     
        
        // Linha esquerda
        glVertex3f(54.8f, 100.0f, 0.2f);
        glVertex3f(54.3f, 100.0f, 0.2f);
        glVertex3f(54.3f, 0.0f, 0.2f);
        glVertex3f(54.8f, 0.0f, 0.2f);

        // Linha direita
        glVertex3f(45.7f, 100.0f, 0.2f);
        glVertex3f(45.2f, 100.0f, 0.2f);
        glVertex3f(45.2f, 0.0f, 0.2f);
        glVertex3f(45.7f, 0.0f, 0.2f);

    glEnd();
}

void linhas_centrais(float l1, float l2){
    glBegin(GL_QUADS);
        glColor3ub(255.0, 165.0, 70.0);

        // Linha 1
        glVertex3f(50.25, l1 + 60.0, 0.2);
        glVertex3f(49.75, l1 + 60.0, 0.2);
        glVertex3f(49.75, l2 + 60.0, 0.2);
        glVertex3f(50.25, l2 + 60.0, 0.2);


        // Linha 2
        glVertex3f(50.25, l1 + 40.0, 0.2);
        glVertex3f(49.75, l1 + 40.0, 0.2);
        glVertex3f(49.75, l2 + 40.0, 0.2);
        glVertex3f(50.25, l2 + 40.0, 0.2);

        // Linha 3
        glVertex3f(50.25, l1 + 20.0, 0.2);
        glVertex3f(49.75, l1 + 20.0, 0.2);
        glVertex3f(49.75, l2 + 20.0, 0.2);
        glVertex3f(50.25, l2 + 20.0, 0.2);

        // Linha 4
        glColor3f(1.0, 0.0, 1.0);
        glVertex3f(50.25, l1, 0.2);
        glVertex3f(49.75, l1, 0.2);
        glVertex3f(49.75, l2, 0.2);
        glVertex3f(50.25, l2, 0.2);
        glColor3ub(255.0, 165.0, 70.0);

        // linha 5
        glVertex3f(50.25, l1 - 20.0, 0.2);
        glVertex3f(49.75, l1 - 20.0, 0.2);
        glVertex3f(49.75, l2 - 20.0, 0.2);
        glVertex3f(50.25, l2 - 20.0, 0.2);

        // linha 6
        glVertex3f(50.25, l1 - 40.0, 0.2);
        glVertex3f(49.75, l1 - 40.0, 0.2);
        glVertex3f(49.75, l2 - 40.0, 0.2);
        glVertex3f(50.25, l2 - 40.0, 0.2);

    glEnd();
}

#endif