#include <GL/glut.h>  
#include "Trab_Desenhos.h"
#include "Carro.h"
#include "Placa.h"
#include "Cilindro.h"

// Aluno: Jailon William
// Matrícula: 499441

/////////////////////// Variáveis globais ////////////////////////////

// CARRO - jogador
float carX_J = 50.0; 

// CARRO - adversário
float carY_A1 = 2.0;
float carY_A2 = 102.0;

// CARRO - velocidade carro
float velCarJ = 0.0;
float velCarA = 0.2;

// Placa
float placaY1 = 5.0;
float placaY2 = 505.0;

// Camera
float eixoX = 50.0;
float eixoY = -10.0;
float eixoZ = 5.0;

// Linhas centrais
float l1 = 55.0;
float l2 = 45.0;

// Controle de camera
void tecladoASCII(unsigned char key, int x, int y){
    switch(key){
        case 'w':
            eixoY += 1.0f;
            break;
        case 's':
            eixoY -= 1.0f;
            break;
            
        case 'a':
            eixoX -= 1.0f;
            break;
        case 'd':
            eixoX += 1.0f;
            break;

        case 'z':
            eixoZ += 1.0f;
            break;
        case 'Z':
            eixoZ -= 1.0f;
            break;
        }
    glutPostRedisplay(); //Instrução que indica pra GLUT que o frame buffer deve ser atualizado
}

// controle do carro
void tecladoSpecial(int key, int x, int y){
    switch(key){
        case GLUT_KEY_LEFT: // carro indo pra esquerda
            if (carX_J > 47 && velCarJ != 0.0){
                carX_J -= 0.3;
                eixoX -= 0.3;
            }
            break;

        case GLUT_KEY_RIGHT: // carro indo pra direita
            if (carX_J < 53 && velCarJ != 0.0){
                carX_J += 0.3;
                eixoX += 0.3;
            }
            break;
            
        case GLUT_KEY_UP: // carro acelerando
            if (velCarJ < 0.5){
                velCarJ += 0.006;
            }
            
            break;
        case GLUT_KEY_DOWN: // carro freiando
            if (velCarJ > 0.0){
                velCarJ -= 0.020;
                if (velCarJ < 0.0){ // tratando para o carro n dar ré
                    velCarJ = 0.0;
                }
            }
            
            break;
        
        }
    glutPostRedisplay();
}

void inicio() {
    glClearColor(173.0f/255.0f, 216.0f/255.0f, 255.0f/255.0f, 1.0f); // fundo da tela                  
    glEnable(GL_DEPTH_TEST); //habilitando a remoção de faces que estejam atrás de outras (ocultas)
}

void desenhar() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // limpando frame buffer color e depth
    
    glMatrixMode(GL_MODELVIEW); // tipo de visualização

    glLoadIdentity();      

    gluLookAt(eixoX, eixoY, eixoZ, 50.0f, 230.0f, 0.0f, 0.0f, 0.0f, 1.0); 
    
    // eixos();

    /////////////////// PISTA E GRAMA //////////////////////////
    glPushMatrix();
    glScaled(1.0, 2.3, 1.0);

    grama();
    pista();
    linhas_centrais(l1, l2);
    
    glPopMatrix();

    ///////////////////////// CARROS ////////////////////////////
    
    // CARRO JOGADOR
    glPushMatrix();
    glTranslated(carX_J, 2.0, 0.1);
    glScaled(0.7, 0.7, 0.7);
    
    carro(GL_LINE, 0.0, 0.0, 0.0);
    carro(GL_FILL, 200.0, 200.0, 200.0);

    glPopMatrix();

    // CARRO ADVERSARIO - 01
    glPushMatrix();
    glTranslated(52.0, carY_A1, 0.1);
    glScaled(0.7, 0.7, 0.7);
    
    carro(GL_LINE, 50.0, 50.0, 50.0);
    carro(GL_FILL, 0.0, 200.0, 200.0);

    glPopMatrix();

    // CARRO ADVERSARIO - 02
    glPushMatrix();
    glTranslated(48.0, carY_A2, 0.1);
    glScaled(0.7, 0.7, 0.7);
    
    carro(GL_LINE, 50.0, 50.0, 50.0);
    carro(GL_FILL, 200.0, 200.0, 0.0);

    glPopMatrix();

    ///////////////////// PLACA //////////////////////

    // PLACA - 01
    glPushMatrix();
    glTranslated(56, placaY1, 0.0f);
    glScaled(1.5, 1.5, 2.0);

    placa(GL_LINE, 50.0, 50.0, 50.0);
    placa(GL_FILL, 200.0, 200.0, 200.0);
    
    glPopMatrix();

    // PLACA - 02
    glPushMatrix();
    glTranslated(44, placaY2, 0.0f);
    glScaled(1.5, 1.5, 2.0);

    placa(GL_LINE, 50.0, 50.0, 50.0);
    placa(GL_FILL, 200.0, 200.0, 200.0);
    
    glPopMatrix();


    barreira(); // tampa o fundo da pista
    glutSwapBuffers(); //
}

void timer(int){

    // Velocidade carro jogador
    if (velCarJ > 0.0){
        velCarJ -= 0.00055;

        if (velCarJ < 0.0){
            velCarJ = 0.0;
        }
    
        // movento de LINHAS
        l1 -= 1*velCarJ;
        l2 -= 1*velCarJ;

     
        if (l1 - 40 <= 0){ // loop da linha
            l1 += 20.0;
            l2 += 20.0;
        }

        // movimento de PLACAS
        placaY1 -= 1*velCarJ;
        placaY2 -= 1*velCarJ;

        // Placa 1
        if (placaY1 < -10.0){ // loop da placa
            placaY1 += 800;
        }
        // Placa 2
        if (placaY2 < -10.0){ // loop da placa
            placaY2 += 800;
        }
    }
    // velocidade carro adversário
    // Adversário 1
    carY_A1 += velCarA - velCarJ;        

    if (carY_A1 > 260.0){
        carY_A1 -= 260.0;
    }

    if (carY_A1 < -50){
        carY_A1 += 260.0;
    }
    
    // Adversário 2
    carY_A2 += velCarA - velCarJ;        

    if (carY_A2 > 260.0){
        carY_A2 -= 260.0;
    }

    if (carY_A2 < -50){
        carY_A2 += 260.0;
    }


    glutPostRedisplay();
    glutTimerFunc(1000 / 144, timer, 0); // 144 quadros por segundo
}

void reshape(GLsizei width, GLsizei height) {
   if (height == 0) height = 1; // tratamento da dimensão da tela                
   GLfloat aspect = (GLfloat)width / (GLfloat)height; // altura e largura da tela
 
   glViewport(0, 0, width, height); // Para recortar a tela
   
   glMatrixMode(GL_PROJECTION);  // definindo tipo de visualização
   glLoadIdentity();             
   
   gluPerspective(45.0f, aspect, 0.1f, 500.0f); // definindo a perspectiva
}

int main(int argc, char** argv) {
   
   glutInit(&argc, argv);

   glutInitDisplayMode(GLUT_MULTISAMPLE | GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize(640, 480);   
   glutInitWindowPosition(50, 50); 
   glutCreateWindow("Trabalho - 499441");
   glutTimerFunc(1000 / 144, timer, 0);
   
   inicio();

   glutDisplayFunc(desenhar);
   glutReshapeFunc(reshape);
   
   glutSpecialFunc(tecladoSpecial);
//    glutKeyboardFunc(tecladoASCII);

   glutMainLoop();

   return 0;
}