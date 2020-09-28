/* Code from page 454*/

#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100,100 };

	Simple_window win{ tl, 600, 400, "Page 446" };

	int x_size = win.x_max();
	int y_size = win.y_max();
	int x_grid = 80;
	int y_grid = 40;

	Lines grid;
	for (int x = x_grid; x < x_size; x += x_grid)
		grid.add(Point{ x,0 }, Point{ x, y_size });
	for (int y = y_grid; y < y_size; y += y_grid)
		grid.add(Point{ 0, y }, Point{ x_size, y });

	grid.set_color(Color::red);
	grid.set_style(Line_style{ Line_style::dash, 2 });

	win.attach(grid);

	win.wait_for_button();
}