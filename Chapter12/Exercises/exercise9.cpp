/*
	Exercise 9: Display an image on the screen, e.g., a photo of a friend. Label the image both with a title on the window and with a caption in the window.
*/

#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 25,25 };

	Simple_window win{ tl, 1280, 480, "Final rendezvous"};

	Image ii{ Point{0,0},"voyageurs.jpg" };
	Text t{ Point{25,300}, "The last day of my youth" };

	win.attach(ii);
	win.attach(t);

	

	win.wait_for_button();
}