/*
	1. Make an 800-by-1000 Simple_window
	2. Put an 8-by-8 grid on the leftmost 800-by-800 part of that window (so that each square is 100 by 100)

*/

#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 50,50 };

	Simple_window win{ tl, 1000, 800, "Drill2" };

	int x_size = win.x_max();
	int y_size = win.y_max();
	int x_grid = 100;
	int y_grid = 100;

	Lines grid;
	for (int x = 0; x <= 800; x += x_grid) 
		grid.add(Point{ x, 0 }, Point{ x, 800 });
	for (int y = 0; y <= 800; y += y_grid) 
		grid.add(Point{ 0, y }, Point{ 800, y });

	grid.set_color(Color::black);
	win.attach(grid);

	win.wait_for_button();


}