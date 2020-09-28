/* Code from page 447*/

#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100,100 };

	Simple_window win{ tl, 600, 400, "Page 446" };

	Lines x;
	x.add(Point{100,100}, Point{200,100});
	x.add(Point{ 150,50 }, Point{ 150,150 });

	win.attach(x);

	win.wait_for_button();
}