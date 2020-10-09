/*
	Exercise 7: Make an RGB color chart

	Notes: Could be better but not not way to visualize a 3 dimensional cube of colors well.
*/

#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100,100 };

	Simple_window win{ tl, 800, 600, "Exercise 7" };

	Vector_ref<Graph_lib::Rectangle> vr;

	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j) {
			int red = 0 + 50 * i;
			int blue = 0 + 50 * j;
			int green = 0 + 50 * j;

			vr.push_back(new Graph_lib::Rectangle{ Point{i * 50, j * 50}, 50,50 });
			vr[vr.size() - 1].set_fill_color(Color{(unsigned char) red, (unsigned char)blue, (unsigned char)green}); // no idea about this nonsense
			vr[vr.size() - 1].set_color(Color::black);
			win.attach(vr[vr.size() - 1]);
		}

	win.wait_for_button();

}