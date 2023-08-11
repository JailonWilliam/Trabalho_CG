#ifndef CILINDRO_H
#define CILINDRO_H
#include <math.h>
#include <GL/glut.h>

void cilindro(float r, float h, int n){
    float angulo_triangulo = 2.0f * M_PI / n; // n representa a quantidade de setores
    int i; // indica qual setor

    glColor3ub(25.0f, 25.0f, 25.0f);
    glBegin(GL_TRIANGLES);

    for(i = 0; i < n; i++){ // dividindo a base do cilidro em trinagulos para fazer os setores do cilindro
        // Utilizando coordenadas polares, já que temos o angulo e o raio.
        // podemos dizer em qual ponto do circulo estamos.
        
        // LATETAL DO CILINDRO - 01
        glVertex3f(h/2.0f, 0.0f, 0.0f); // vertice central
        glVertex3f(h/2.0f, r * cos(i * angulo_triangulo),       r * sin(i * angulo_triangulo)); // multiplicando o angulo por i para definir os setores, se não daria o mesmo ponto
        glVertex3f(h/2.0f, r * cos((i + 1) * angulo_triangulo), r * sin((i + 1) * angulo_triangulo)); // pegando o ponto diante
    
        // LATERAL DO CILINDRO - 02
        glVertex3f(-h/2.0f, 0.0f, 0.0f); // vertice central
        glVertex3f(-h/2.0f, r * cos(i * angulo_triangulo),       r * sin(i * angulo_triangulo)); // multiplicando o angulo por i para definir os setores, se não daria o mesmo ponto
        glVertex3f(-h/2.0f, r * cos((i + 1) * angulo_triangulo), r * sin((i + 1) * angulo_triangulo)); // pegando o ponto diante
    
        // CASCA DO CILINDRO
        // Agora basta pegar os vertices das leterais e unir com as outras que ja foram definido
        glVertex3f( h/2.0f,  r * cos(i * angulo_triangulo),       r * sin(i * angulo_triangulo));
        glVertex3f( h/2.0f,  r * cos((i + 1) * angulo_triangulo), r * sin((i + 1) * angulo_triangulo));
        glVertex3f(-h/2.0f, r * cos((i + 1) * angulo_triangulo),  r * sin((i + 1) * angulo_triangulo));

        glVertex3f(-h/2.0f, r * cos(i * angulo_triangulo),       r * sin(i * angulo_triangulo)); 
        glVertex3f(-h/2.0f, r * cos((i + 1) * angulo_triangulo), r * sin((i + 1) * angulo_triangulo));
        glVertex3f( h/2.0f,  r * cos(i * angulo_triangulo),      r * sin(i * angulo_triangulo)); 
        
    }

    glEnd();

}


#endif
