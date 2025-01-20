#include <iostream>
#include <GL/glut.h>// (u otras líneas, dependiendo del // sistema que usemos 
#include <math.h>
#define PI 3.14159265f
//#include<windows.h>
#include <stdlib.h>
#include<stdio.h>

GLint i;
GLfloat giro_luna = -15;
GLfloat ax = 0, bx = 0, cx = 0, dx = 0;
GLfloat giro = 0.0;

void init(void)
{

	glClearColor(0.64, 0.64, .64, 0.0);
	//para borrar los búferes de color
	// Establece el color de la ventana de visualización

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000.0, 0.0, 500.0);//espacio visualizar
	//// Establece los parámetros de proyección.
}

///=================///
///TODO EL MODELO   ///
///=================///

///*** modelo para dibujar circulos***///
//--------------------------------------------------------
void circulo(GLdouble rad) {
	GLint points = 50;//puntos
	GLdouble delTheta = (2.0 * PI) / (GLdouble)points;
	GLdouble theta = 1.0;
	glBegin(GL_POLYGON);//tipo figura
	{
		for (i = 0; i <= 50; i++, theta += delTheta)//50 vertx
		{
			//Especifica un vértice.
			glVertex2f(rad * cos(theta), rad * sin(theta));
		}
	}
	glEnd();
}
//--------------------------------------------------------

/// *** MODELO DEL SOL **/// tamano,ubicacion
//--------------------------------------------------------
void modelo_sol() {
	glPushMatrix();//empujar 
	glTranslatef(500, 100, 0);//Alejamos el cuadrado del observador
	circulo(90);//tamano sol
	glPopMatrix();//emerger
}
//--------------------------------------------------------

/// *** MODELO DE MOVIMIENTO DE LUNA **/
		//dar mov al sol hacia arriba(rotacion) 
//--------------------------------------------------------
void modelo_mov_Luna() {
	glPushMatrix();//empujar
	//multiplica la matriz actual por una matriz de rotación.
	//angulo,VECTX,VECTY,VECTZ
	glRotatef(-giro_luna, 0, 0, -.009);//rotacion
	//si es +.009 baja el sol
	modelo_sol();
	glPopMatrix();//emerjer
}
//--------------------------------------------------------

/// *** ARMANDO MODELO DE NUBES **///
		//Armando nubes
//--------------------------------------------------------
//mediana
void nube_modelo_uno() {
	
	glColor3f(.89, .89, .89);
	//ARRIBA IZQ
	glPushMatrix();
	glTranslatef(320, 210, 0);//matriz de traslación.
	circulo(15);
	glPopMatrix();

	///CIMA

	glPushMatrix();
	glTranslatef(340, 225, 0);
	circulo(16);
	glPopMatrix();

	///DERECHO

	glPushMatrix();
	glTranslatef(360, 210, 0);
	circulo(16);
	glPopMatrix();


	//RELLENO MEDIO

	glPushMatrix();
	glTranslatef(355, 210, 0);
	circulo(16);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(350, 210, 0);
	circulo(16);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(345, 204, 0);
	circulo(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(340, 204, 0);
	circulo(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(335, 204, 0);
	circulo(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(330, 204, 0);
	circulo(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(325, 204, 0);
	circulo(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(320, 204, 0);
	circulo(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(315, 204, 0);
	circulo(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(310, 204, 0);
	circulo(10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(305, 204, 0);
	circulo(10);
	glPopMatrix();

	///****RELLENO FIN****

}
//pequena
void nube_modelo_dos() {
	
	glColor3f(.89, .89, .89);

	///PARTE IZQUIERDA
	glPushMatrix();
	glTranslatef(305, 205, 0);
	circulo(10);
	glPopMatrix();

	///CIMA


	glPushMatrix();
	glTranslatef(320, 210, 0);
	circulo(15);
	glPopMatrix();

	///Right_Part//PARTE DERECHA

	glPushMatrix();
	glTranslatef(334, 207, 0);
	circulo(10);
	glPopMatrix();

	///Bottom_Part//PARTE DE ABAJO

	glPushMatrix();
	glTranslatef(320, 207, 0);
	circulo(10);
	glPopMatrix();



}
//grande
void nube_modelo_tres() {
	
	glColor3f(.89, .89, .89);

	///PARTE IZQ
	glPushMatrix();
	glTranslatef(300, 200, 0);
	circulo(15);
	glPopMatrix();

	///ARRIBA IZQ

	glPushMatrix();
	glTranslatef(320, 210, 0);
	circulo(15);
	glPopMatrix();

	///CIMA

	glPushMatrix();
	glTranslatef(340, 220, 0);
	circulo(16);
	glPopMatrix();

	///ARRIBA DERECHA

	glPushMatrix();
	glTranslatef(360, 210, 0);
	circulo(15);
	glPopMatrix();

	//PARTE IZQ

	glPushMatrix();
	glTranslatef(380, 200, 0);
	circulo(15);
	glPopMatrix();

	//ABAJO DERECHA

	glPushMatrix();
	glTranslatef(360, 190, 0);
	circulo(20);
	glPopMatrix();

	//ABAJO IZQ

	glPushMatrix();
	glTranslatef(320, 190, 0);
	circulo(20);
	glPopMatrix();

	//FONDO

	glPushMatrix();
	glTranslatef(340, 190, 0);
	circulo(20);
	glPopMatrix();




	///****FIN LLENAR****

}
//--------------------------------------------------------


//--------------------------------------------------------

///*** ARMANDO MODELO CIRCO
//--------------------------------------------------------
void Circo() {

	/// CUERPO
	glBegin(GL_POLYGON);
	//glColor3f(.990, 0.0, 0.0);
	glColor3f(.40, .40, .0);
	glVertex2i(295, 140);
	glVertex2i(585, 140);
	glVertex2i(585, 0);
	glVertex2i(295, 0);
	glEnd();

	//telones rojos entrada
	glBegin(GL_TRIANGLES);
	//glColor3f(.990, 0.0, 0.0);
	glColor3f(1.0, .0, .0);
	glVertex2i(440, 140);
	glVertex2i(410, 0);
	glVertex2i(390, 0);
	glEnd();
	glBegin(GL_TRIANGLES);
	//glColor3f(.990, 0.0, 0.0);
	glColor3f(1.0, .0, .0);
	glVertex2i(440, 140);
	glVertex2i(490, 0);
	glVertex2i(470, 0);
	glEnd();
	//puerta negra
	glBegin(GL_TRIANGLES);
	//glColor3f(.990, 0.0, 0.0);
	glColor3f(.0, .0, .0);
	glVertex2i(440, 140);
	glVertex2i(470, 0);
	glVertex2i(410, 0);
	glEnd();

	//carpa TECHO
	glBegin(GL_POLYGON);
	//glColor3f(.990, 0.0, 0.0);
	glColor3f(0.70, 0.20, 0.25);
	glVertex2i(430, 250);
	glVertex2i(450, 250);
	glVertex2i(615, 140);
	glVertex2i(275, 140);
	glEnd();

	//palo bandera
	glBegin(GL_TRIANGLES);
	//glColor3f(.990, 0.0, 0.0);
	glColor3f(.0, .0, .0);
	glVertex2i(440, 290);
	glVertex2i(450, 250);
	glVertex2i(430, 250);
	glEnd();

	//bandera
	glBegin(GL_TRIANGLES);
	//glColor3f(.990, 0.0, 0.0);
	glColor3f(1.0, .0, .0);
	glVertex2i(440, 305);
	glVertex2i(480, 297);
	glVertex2i(440, 290);
	glEnd();


	//banderines volteados
	glBegin(GL_TRIANGLES);
	//glColor3f(.990, 0.0, 0.0);
	glColor3f(1.0, .49, .0);//NARANJA
	glVertex2i(275, 140);
	glVertex2i(325, 140);
	glVertex2i(300, 120);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(.990, 0.0, 0.0);
	glColor3f(.0, .19, .56);//AZUL
	glVertex2i(325, 140);
	glVertex2i(375, 140);
	glVertex2i(350, 120);
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(.990, 0.0, 0.0);
	glColor3f(1.0, .0, .0);//ROJO
	glVertex2i(375, 140);
	glVertex2i(425, 140);//+50
	glVertex2i(400, 120);//50
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(.990, 0.0, 0.0);
	glColor3f(1.0, .49, .0);//NARANJA
	glVertex2i(425, 140);
	glVertex2i(475, 140);//+50
	glVertex2i(450, 120);//50
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(.990, 0.0, 0.0);
	glColor3f(.0, .19, .56);//AZUL
	glVertex2i(475, 140);
	glVertex2i(525, 140);//+50
	glVertex2i(500, 120);//50
	glEnd();

	glBegin(GL_TRIANGLES);
	//glColor3f(.990, 0.0, 0.0);
	glColor3f(1.0, .0, .0);
	glVertex2i(525, 140);
	glVertex2i(575, 140);//+50
	glVertex2i(550, 120);//50
	glEnd();
	glBegin(GL_TRIANGLES);

	//glColor3f(.990, 0.0, 0.0);
	glColor3f(1.0, .49, .0);//NARANJA
	glVertex2i(575, 140);
	glVertex2i(613, 140);//+50
	glVertex2i(600, 120);//50
	glEnd();

} //circo
//--------------------------------------------------------

///*** ARMANDO MODELO CAMPO ***///
//--------------------------------------------------------
//pista y pasto
void Cesped() {
	//cesped 1
	glBegin(GL_POLYGON);
	glColor3f(.07, .58, .13);
	glVertex2i(0, 68);
	glVertex2i(0, 70);
	glVertex2i(1000, 70);
	glVertex2i(1000, 68);
	glEnd();

	//cesped 2
	glBegin(GL_POLYGON);
	glColor3f(.07, .58, .13);
	glVertex2i(0, 0);
	glVertex2i(0, 68);
	glVertex2i(1000, 68);
	glVertex2i(1000, 0);
	glEnd();

	//pista 
	glBegin(GL_POLYGON);
	glColor3f(.36, .36, .36);
	glVertex2i(0, 6);
	glVertex2i(0, 62);
	glVertex2i(1000, 62);
	glVertex2i(1000, 6);
	glEnd();

	//marcas de carretera
	//pista 

	glBegin(GL_POLYGON);
	glColor3f(0.90, .90, .90);
	glVertex2i(8, 40);//38+15
	glVertex2i(38, 40);//15
	glVertex2i(38, 32);
	glVertex2i(8, 32);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.533, .293, .0);
	glVertex2i(53, 40);//38+15
	glVertex2i(83, 40);//15
	glVertex2i(83, 32);
	glVertex2i(53, 32);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.533, .293, .0);
	glVertex2i(98, 40);
	glVertex2i(128, 40);
	glVertex2i(128, 32);
	glVertex2i(98, 32);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.533, .293, .0);
	glVertex2i(143, 40);
	glVertex2i(173, 40);
	glVertex2i(173, 32);
	glVertex2i(143, 32);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.533, .293, .0);
	glVertex2i(188, 40);//38+15
	glVertex2i(218, 40);//15
	glVertex2i(218, 32);
	glVertex2i(188, 32);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.533, .293, .0);
	glVertex2i(233, 40);//38+15
	glVertex2i(263, 40);//15
	glVertex2i(263, 32);
	glVertex2i(233, 32);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.533, .293, .0);
	glVertex2i(278, 40);//38+15
	glVertex2i(308, 40);//15
	glVertex2i(308, 32);
	glVertex2i(278, 32);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.533, .293, .0);
	glVertex2i(323, 40);//38+15
	glVertex2i(353, 40);//15
	glVertex2i(353, 32);
	glVertex2i(323, 32);
	glEnd();
	glBegin(GL_POLYGON);
	//glColor3f(0.533, .293, .0);
	glVertex2i(368, 40);//38+15
	glVertex2i(398, 40);//15
	glVertex2i(398, 32);
	glVertex2i(368, 32);
	glEnd();
	glBegin(GL_POLYGON);
	//	glColor3f(0.533, .293, .0);
	glVertex2i(413, 40);//38+15
	glVertex2i(443, 40);//15
	glVertex2i(443, 32);
	glVertex2i(413, 32);
	glEnd();
	glBegin(GL_POLYGON);
	//glColor3f(0.533, .293, .0);
	glVertex2i(458, 40);//38+15
	glVertex2i(488, 40);//15
	glVertex2i(488, 32);
	glVertex2i(458, 32);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.533, .293, .0);
	glVertex2i(503, 40);//38+15
	glVertex2i(533, 40);//15
	glVertex2i(533, 32);
	glVertex2i(503, 32);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.533, .293, .0);
	glVertex2i(548, 40);//38+15
	glVertex2i(578, 40);//15
	glVertex2i(578, 32);
	glVertex2i(548, 32);
	glEnd();
	glBegin(GL_POLYGON);
	//glColor3f(0.533, .293, .0);
	glVertex2i(593, 40);//38+15
	glVertex2i(623, 40);//15
	glVertex2i(623, 32);
	glVertex2i(593, 32);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.533, .293, .0);
	glVertex2i(638, 40);//38+15
	glVertex2i(668, 40);//15
	glVertex2i(668, 32);
	glVertex2i(638, 32);
	glEnd();
	glBegin(GL_POLYGON);
	//glColor3f(0.533, .293, .0);
	glVertex2i(683, 40);//38+15
	glVertex2i(713, 40);//15
	glVertex2i(713, 32);
	glVertex2i(683, 32);
	glEnd();
	glBegin(GL_POLYGON);
	//glColor3f(0.533, .293, .0);
	glVertex2i(728, 40);//38+15
	glVertex2i(758, 40);//15
	glVertex2i(758, 32);
	glVertex2i(728, 32);
	glEnd();
	glBegin(GL_POLYGON);
	//glColor3f(0.533, .293, .0);
	glVertex2i(773, 40);//38+15
	glVertex2i(803, 40);//15
	glVertex2i(803, 32);
	glVertex2i(773, 32);
	glEnd();
	glBegin(GL_POLYGON);
	//glColor3f(0.533, .293, .0);
	glVertex2i(818, 40);//38+15
	glVertex2i(848, 40);//15
	glVertex2i(848, 32);
	glVertex2i(818, 32);
	glEnd();
	glBegin(GL_POLYGON);
	//glColor3f(0.533, .293, .0);
	glVertex2i(863, 40);//38+15
	glVertex2i(893, 40);//15
	glVertex2i(893, 32);
	glVertex2i(863, 32);
	glEnd();
	glBegin(GL_POLYGON);
	//glColor3f(0.533, .293, .0);
	glVertex2i(908, 40);//38+15
	glVertex2i(938, 40);//15
	glVertex2i(938, 32);
	glVertex2i(908, 32);
	glEnd();

	glBegin(GL_POLYGON);
	//glColor3f(0.533, .293, .0);
	glVertex2i(953, 40);//38+15
	glVertex2i(983, 40);//15
	glVertex2i(983, 32);
	glVertex2i(953, 32);
	glEnd();
	glBegin(GL_POLYGON);
	///glColor3f(0.533, .293, .0);
	glVertex2i(998, 40);//38+15
	glVertex2i(1028, 40);//15
	glVertex2i(1028, 32);
	glVertex2i(998, 32);
	glEnd();
}
//--------------------------------------------------------
//ARMANDO VEHICULO
//--------------------------------------------------------
void AutoModelo() {
	//Auto
	//Auto

	glBegin(GL_POLYGON);
	glColor3f(0.533, .293, .0);
	glVertex2i(0, 59);
	glVertex2i(60, 59);
	glVertex2i(60, 50);
	glVertex2i(0, 50);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.533, 0.293, .0);
	glVertex2i(27, 69);
	glVertex2i(37, 69);
	glVertex2i(45, 59);
	glVertex2i(14, 59);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(.0, .0, .0);
	glVertex2i(27, 59);
	glVertex2i(27, 69);
	glEnd();
	//finAuto
	//--------------------------------------------------------
}
void BusModelo() {
	//BUS

	glBegin(GL_POLYGON);
	glColor3f(0.0, .293, 1.0);
	glVertex2i(0, 45);
	glVertex2i(65, 45);
	glVertex2i(65, 33);
	glVertex2i(0, 33);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.533, 0.293, .0);
	glVertex2i(0, 33);
	glVertex2i(65, 33);
	glVertex2i(65, 19);
	glVertex2i(0, 19);
	glEnd();
	///venntaas
	glBegin(GL_POLYGON);
	glColor3f(.0, 0.293, .0);
	glVertex2i(59, 41);
	glVertex2i(65, 41);
	glVertex2i(65, 29);
	glVertex2i(59, 29);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(.0, 0.293, .0);
	glVertex2i(6, 41);
	glVertex2i(26, 41);
	glVertex2i(26, 30);
	glVertex2i(6, 30);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(.0, 0.293, .0);
	glVertex2i(56, 41);
	glVertex2i(36, 41);
	glVertex2i(36, 30);
	glVertex2i(56, 30);
	glEnd();
	//linea divisora
	glBegin(GL_POLYGON);
	glColor3f(.0, .0, .0);
	glVertex2i(0, 34);
	glVertex2i(65, 34);
	glVertex2i(65, 33);
	glVertex2i(0, 33);
	glEnd();
}
//--------------------------------------------------------
///*** ARMANDO MODELO ARBOL ***///
		//Con circulos y triangulos
//--------------------------------------------------------
//arbol bola grande
void Arbol_modelo_uno() {

	//bola arbol
	glPushMatrix();
	glTranslatef(110, 110, 0);
	circulo(15);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(110, 100, 0);
	circulo(15);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(100, 100, 0);
	circulo(15);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(110, 110, 50);
	circulo(15);
	glPopMatrix();

	//palo arbol
	glBegin(GL_POLYGON);

	glColor3f(0.38, 0.21, 0.26);
	glVertex2f(100, 70);
	glVertex2f(100, 90);//arreglado
	glVertex2f(111, 90);
	glVertex2f(111, 70);

	glEnd();

}

//arbol bola chiquito
void Arbol_modelo_dos() {

	//bola chiquito
	glPushMatrix();
	glTranslatef(130, 130, 0);
	circulo(5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(125, 126, 0);
	circulo(5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(135, 126, 0);
	circulo(5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(130, 125, 0);
	circulo(5);
	glPopMatrix();
	//palo
	glBegin(GL_POLYGON);
	glColor3f(0.38, 0.21, 0.26);
	glVertex2f(129, 110);
	glVertex2f(129, 124);
	glVertex2f(131, 124);
	glVertex2f(131, 110);

	glEnd();
}

//arbol chiquito punta
void Arbol_modelo_tres() {

	//punta arbol triangulo
	glBegin(GL_POLYGON);

	glVertex2f(125, 123);//125
	glVertex2f(133, 150);
	glVertex2f(141, 123);//141

	glEnd();

	//palo
	glBegin(GL_POLYGON);
	glColor3f(0.38, 0.21, 0.26);
	glVertex2f(132, 110);
	glVertex2f(132, 124);
	glVertex2f(134, 124);
	glVertex2f(134, 110);

	glEnd();
}
//--------------------------------------------------------
/// ARMANDO SOPORTE DE MOLINO
//--------------------------------------------------------
void Molino_soporte() {
	//palo
	glColor3f(0.38, 0.41, 0.36);
	glBegin(GL_POLYGON);
	glVertex2i(375, 100);
	glVertex2i(380, 240);
	glVertex2i(384, 240);
	glVertex2i(390, 100);
	glEnd();
}
//--------------------------------------------------------
///***ARMANDO MODELO ASPAS DE MOLINO
//--------------------------------------------------------
void Molino_aspas() {
	///pala uno
	glPushMatrix();
	glRotatef(giro, 0, 0, 90);
	glBegin(GL_POLYGON);
	glVertex2i(-5, 0);
	glVertex2i(-85, -36);
	glVertex2i(-83, -37);
	glVertex2i(-3, -8);
	glEnd();
	glPopMatrix();

	///pala dos
	glPushMatrix();
	glRotatef(giro, 0, 0, 90);
	glBegin(GL_POLYGON);
	glVertex2i(0, 5);
	glVertex2i(45, 70);
	glVertex2i(50, 73);
	glVertex2i(5, 0);
	glEnd();
	glPopMatrix();

	///pala tres
	glPushMatrix();
	glRotatef(giro, 0, 0, 90);// matriz de rotación.
	glBegin(GL_POLYGON);
	glVertex2i(68, -78);
	glVertex2i(0, 0);
	glVertex2i(5, 5);
	glVertex2i(70, -77);
	glEnd();
	glPopMatrix();
}
//--------------------------------------------------------
//UNIENDO PIEZAS DE MOLINO
//--------------------------------------------------------
void Molino() {

	glColor3f(0.38, 0.41, 0.36);
	glPushMatrix();//empujar	
	Molino_soporte();//soporte molino
	glPopMatrix();//emerger

	///motor molino
	glColor3f(0.11, 0.23, 0.36);
	glPushMatrix();
	glTranslatef(380, 250, 0);
	circulo(10);
	glPopMatrix();

	///aspas de molino
	glColor3f(0.11, 0.23, 0.36);
	glPushMatrix();
	glTranslatef(380, 251, 0);
	Molino_aspas();
	glPopMatrix();
}
//--------------------------------------------------------
//UNIENDO PIEZAS DE AUTO
//--------------------------------------------------------
void Auto() {
	glColor3f(0.38, 0.41, 0.36);
	glPushMatrix();//empujar	
	AutoModelo();//
	glPopMatrix();//emerger

	///RUEDAS

	//lantas
	//delantera
	glColor3f(.0, .0, .0);
	glPushMatrix();
	glTranslatef(40, 48, 0);
	circulo(8);
	glPopMatrix();

	//trasera
	glColor3f(.0, .0, .0);
	glPushMatrix();
	glTranslatef(15, 48, 0);
	circulo(8);
	glPopMatrix();

	///AROS
	//DELANTERO
	glColor3f(1.0, 1.0, 1.0);

	glPushMatrix();
	glTranslatef(40, 48, 0);
	circulo(4);
	glPopMatrix();
	//TRASERO
	glColor3f(.0, 1.0, 1.0);

	glPushMatrix();
	glTranslatef(15, 48, 0);
	circulo(4);
	glPopMatrix();

}
void Bus() {
	glColor3f(0.38, 0.41, 0.36);
	glPushMatrix();//empujar	
	BusModelo();//
	glPopMatrix();//emerger

	///RUEDAS
	//lantas
		//delantera
	glPushMatrix();
	glTranslatef(40, 20, 0);
	circulo(9);
	glPopMatrix();

	//trasera
	glPushMatrix();
	glTranslatef(15, 20, 0);
	circulo(9);
	glPopMatrix();

	///AROS
	//aro peq de llanta trasera

	glColor3f(.0, 1.0, 1.0);

	glPushMatrix();
	glTranslatef(15, 20, 0);
	circulo(4);
	glPopMatrix();


	//aro pequeno de llanta delantera
	glColor3f(1.0, 1.0, 1.0);

	glPushMatrix();
	glTranslatef(40, 20, 0);
	circulo(4);
	glPopMatrix();


}
//--------------------------------------------------------
//BBBBBBBBBBBBBBBBB FIN ARMADO BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
			///*** OBJETOS PARA LA IMAGEN
//--------------------------------------------------------
///*** Luna ***///
void Luna() {
	glColor3f(1.0, 1.0, 1.0);//color del sol
	glPushMatrix();//	empujar 
	modelo_mov_Luna();
	glPopMatrix();//emerger
}
// medianas
///*** nube uno modelo un0 ***///
void Nube_uno() {
	glPushMatrix();//empujar
	glTranslatef(cx, 220, 0);//mov nube
	nube_modelo_uno();
	glPopMatrix();//emerger

}
///*** nube dos modelo dos ***///
void Nube_dos() {
	glPushMatrix();
	glTranslatef(bx + 100, 150, 0);//bx
	nube_modelo_uno();
	glPopMatrix();
}
///*** nube tres modelo dos ***///
//pequena
void Nube_tres() {
	glPushMatrix();
	glTranslatef(ax - 80, 200, 0);
	nube_modelo_dos();
	glPopMatrix();

}
///*** nube cuatro modelo dos ***///
void Nube_cuatro() {
	glPushMatrix();
	glTranslatef(dx + 300, 200, 0);
	nube_modelo_dos();
	glPopMatrix();

}
///*** nube cinco modelo tres ***///
//grandes
void Nube_cinco() {

	glPushMatrix();
	glTranslatef(ax - 300, 220, 0);
	nube_modelo_tres();
	glPopMatrix();
}
void Nube_seis() {

	glPushMatrix();
	glTranslatef(cx - 400, 210, 0);
	nube_modelo_tres();
	glPopMatrix();
}
/// Circo
void Circo_uno() {
	glPushMatrix();
	glTranslatef(0, 0, 0);//x,y,z
	Circo();
	glPopMatrix();
}
//bola grande
void Arbol_uno() {
	glColor3f(0.533, 1.293, 0.0);//color verde bola
	glPushMatrix();
	glTranslatef(0, 0, 0);
	Arbol_modelo_uno();
	glPopMatrix();
}
void Arbol_dos() {
	glColor3f(0.533, 1.293, .0);
	glPushMatrix();
	glTranslatef(680, 0, 0);
	Arbol_modelo_uno();
	glPopMatrix();
}
//bola chiqui
void Arbol_cinco() {
	glColor3f(0.533, 1.293, .0);
	glPushMatrix();
	glTranslatef(8, -40, 0);
	Arbol_modelo_dos();
	glPopMatrix();
}
void Arbol_seis() {
	glColor3f(0.533, 1.293, .0);
	glPushMatrix();
	glTranslatef(800, -40, 0);
	Arbol_modelo_dos();
	glPopMatrix();
}
//punta chiquito
void Arbol_diez() {
	glColor3f(0.533, 1.293, .0);
	glPushMatrix();
	glTranslatef(-68, -40, 0);
	Arbol_modelo_tres();
	glPopMatrix();
}
void Arbol_once() {
	glColor3f(0.533, 1.293, .0);
	glPushMatrix();
	glTranslatef(700, -40, 0);
	Arbol_modelo_tres();
	glPopMatrix();
}
void Molino_uno() {
	glColor3f(0.11, 0.23, 0.36);
	glPushMatrix();
	glTranslatef(-200, -50, 0);
	Molino();
	glPopMatrix();
}
void Molino_dos() {
	glColor3f(0.11, 0.23, 0.36);
	glPushMatrix();
	glTranslatef(500, -70, 0);
	Molino();
	glPopMatrix();

}
void Molino_tres() {
	glColor3f(0.11, 0.23, 0.36);
	glPushMatrix();
	glTranslatef(300, -90, 0);
	Molino();
	glPopMatrix();

}
void Auto_uno() { //auto mov
	glPushMatrix();
	glTranslatef(bx - 5, 0, 0);
	Auto();
	glPopMatrix();
}
void Bus_uno() {
	glPushMatrix();
	glTranslatef(cx - 5, 0, 0);
	Bus();
	glPopMatrix();
}//bus mov
//--------------------------------------------------------
							///FIN OBJETOS PARA LA IMAGEN
///BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB///
/// 
			//     VISUALIZACION DE OBJETOS 
			///===============================
//--------------------------------------------------------
void display(void)//dibujar
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(.0, 0.0, 1.0);

	///*** objeto capa ***///
	Luna();

	Molino_tres();

	Nube_tres();
	Nube_cuatro();
	Molino_uno();
	Molino_dos();


	Circo_uno();//circo

	Nube_uno();

	//bola grande
	Arbol_uno();
	Arbol_dos();

	//bola chiq
	Arbol_cinco();
	Arbol_seis();

	//punta chiq
	Arbol_diez();
	Arbol_once();


	Nube_dos();
	Nube_cinco();
	Nube_seis();
	Cesped();

	Auto_uno();
	Bus_uno();
	glFlush();
}
///========================///
///*** velocidad y movuimiento ***///
///========================///
///*** mivimiento de sol ***///
void sol_mov() {
	giro_luna = giro_luna + .0008; //velocidad mov
}
//mov nubes,aspas,para que vuelvan a pasar
void mov_derecha() {

	sol_mov();

	giro = giro + .1;//velocidad aspas molino
	ax = ax + .05;//vel nube grande y peq
	bx = bx + .08;//vel nube mediana 
	cx = cx + .10;// vel nube grande mediana
	dx = dx + .15;//nube peq

	//para que vuelvan a pasar nubes
	if (cx > 1000) {
		cx = -300;
	}
	if (bx > 1000) {
		bx = -400;

	}
	if (cx > 1000) {
		cx = -400;

	}
	if (dx > 1000) {
		dx = -500;

	}


	glutPostRedisplay();
	//marca la ventana actual como que necesita ser remostrada.
}
//--------------------------------------------------------
//MOUSE
//--------------------------------------------------------
void mouse(int key, int state, int x, int y) {
	switch (key)
	{
	case GLUT_LEFT_BUTTON://si presiona boton izq mouse 
		if (state == GLUT_DOWN)//si se pulso el boton
		{//GLUT_UP o GLUT_DOWN, según si se ha pulsado/soltado
			glutIdleFunc(mov_derecha);
			//función que se activa cuando no hacemos NADA
		}
		break;
	case GLUT_MIDDLE_BUTTON://si presiona boton enmedio

		if (state == GLUT_DOWN)//si se pulso el boton
		{
			glutIdleFunc(sol_mov);
			//función que se activa cuando no hacemos NADA
		}
		break;

	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
		{
			glutIdleFunc(NULL);
		}
		break;
	}
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(60, 60);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Circo en la Noche");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutMainLoop();
}

