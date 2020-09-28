/* Code from page 446*/

#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100,100 };

	Simple_window win{ tl, 600, 400, "Page 446" };

	Line horizontal{ Point{100,100}, Point{200,100} };
	Line vertical{ Point{ 150,50 }, Point{ 150,150 } };

	win.attach(horizontal);
	win.attach(vertical);

	win.wait_for_button();
}