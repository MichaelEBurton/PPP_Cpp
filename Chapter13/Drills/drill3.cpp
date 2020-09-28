/*
	1. Make an 800-by-1000 Simple_window
	2. Put an 8-by-8 grid on the leftmost 800-by-800 part of that window (so that each square is 100 by 100)
	3. Make the eight squares on the diagonal starting from the top left corner red (use rectangle)
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

	Vector_ref<Graph_lib::Rectangle> vr;

	for(int i = 0; i < 900; i += 100)
	{
	  vr.push_back(new Graph_lib::Rectangle{ Point{i,i}, 100,100 });
	  vr[vr.size() - 1].set_fill_color(Color::red);
	  vr[vr.size() - 1].set_color(Color::black);
      win.attach(vr[vr.size() - 1]);
	}

	win.wait_for_button();


}