#include "Framework/DrawingWindow.h"
#include "Framework/Transform2D.h"
#include "Framework/Line2D.h"
#include "Framework/Rectangle2D.h"
#include "Framework/Circle2D.h"
#include "Framework/Polygon2D.h"
#include <iostream>

using namespace std;
float pas=0;

//Declarari globale
//se adauga o linie la obiectele din scena
Line2D *line = new Line2D(Point2D(0, 0), Point2D(0, 9), Color(1, 0, 1));

// se adauga un patrat
Rectangle2D *rectangle = new Rectangle2D(Point2D(2, 1), 10, 10);

// se adauga un cerc
Circle2D *circle = new Circle2D(Point2D(-5, -5), 10);

// se adauga un poligon
Polygon2D *polygon = new Polygon2D();

//functia care permite adaugarea de obiecte
void DrawingWindow::init()
{

	
	addObject2D(line);	
	
	addObject2D(rectangle);
		
	addObject2D(circle);

	polygon->addPoint(Point2D(2, -2));
	/*polygon->addPoint(Point2D(2,  2));*/
	polygon->addPoint(Point2D(-2,  2));
	polygon->addPoint(Point2D(-2, -2));
	
	addObject2D(polygon);

	

	

}

float counter = 0;

void Rotestepatratul(Rectangle2D *ob, float i){

	//mut obiecct in origine
	Transform2D::loadIdentityMatrix();
	Transform2D::translateMatrix(-10,-10);
	Transform2D::applyTransform(ob);

	//rotesc obiectu
	Transform2D::loadIdentityMatrix();
	Transform2D::rotateMatrix(i);
	Transform2D::applyTransform(ob);

	//mut inapoi
	Transform2D::loadIdentityMatrix();
	Transform2D::translateMatrix(10,10);
	Transform2D::applyTransform(ob);
}

//functia care permite animatia
double counterlinie = 0;
double counterpoly = 0;
bool ok = true;
bool ok2 = true;
void DrawingWindow::onIdle()
{
		//mut obiecct in origine
		Transform2D::loadIdentityMatrix();
		Transform2D::translateMatrix(-10, -10);
		//rotesc obiectu
		Transform2D::rotateMatrix(counter);
		//mut inapoi
		Transform2D::translateMatrix(10, 10);
		Transform2D::applyTransform(rectangle);

		counter = counter + 0.1;
		if (counter >= 3.14 * 2) counter -= 3.14 * 2;

////////////////////////////////////////////////////////////////
		Transform2D::loadIdentityMatrix();
		Transform2D::translateMatrix(-10, 0);
		Transform2D::applyTransform(line);

		//if (counterlinie < 10 && ok)
		//	counterlinie += 0.1;

		//if (counterlinie == 10) {
		//	ok = false;
		//	counterlinie = 0;
		//}

		//if (counterlinie > -10 && !ok)
		//	counterlinie -= 0.1;

		//if (counterlinie == -10){
		//	ok = true;
		//	counterlinie = 0;
		//}
////////////////////////////////////////////////////////////////
		//Transform2D::loadIdentityMatrix();
		//Transform2D::scaleMatrix(counterpoly, counterpoly);
		//Transform2D::applyTransform(polygon);


		//if (counterpoly < 10 && ok)
		//	counterpoly += 0.1;

		//if (counterpoly == 10) {
		//	ok = false;
		//	counterpoly = 0;
		//}

		//if (counterpoly > -10 && !ok)
		//	counterpoly -= 0.1;

		//if (counterpoly == -10){
		//	ok = true;
		//	counterpoly = 0;
		//}

}

//functia care defineste ce se intampla cand se apasa pe tastatura
void DrawingWindow::onKey(unsigned char key)
{
	switch(key)
	{
		case 27 : exit(0);
	}

}

//functia care defineste ce se intampla cand se da click pe mouse
void DrawingWindow::onMouse(int button,int state,int x, int y)
{
	
}


int main(int argc, char** argv)
{
	//creare fereastra
	DrawingWindow dw(argc, argv, 600, 600, 200, 100, "Laborator EGC");
	//se apeleaza functia init() - in care s-au adaugat obiecte
	dw.init();
	//se intra in bucla principala de desenare - care face posibila desenarea, animatia si procesarea evenimentelor
	dw.run();
	return 0;

}