/*
	Exercise 5: Draw a red 1/4-inch frame around a rectangle that is three-quarters the height of your screen and two-thirds the width.
*/

#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 0,0 };

	Simple_window win(tl, 1280, 680, "Exericse 5");

	int width = 2 *x_max() / 3  ;
	int height =  3*y_max() / 4 ;

	Graph_lib::Rectangle r{ Point(5,5), width, height };
	r.set_color(Color::black);
	
	// NOTE! Not really sure how to add the frame around the rectangle 
	

	win.attach(r);

	win.wait_for_button();
}