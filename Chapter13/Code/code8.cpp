/* Code from page 466*/

#include "Graph.h"
#include "Simple_window.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100,100 };

	Simple_window win{ tl, 600, 400, "Page 462" };

	Vector_ref<Graph_lib::Rectangle> vr;

	for(int i = 0; i < 16; ++i)
		for (int j = 0; j < 16; ++j) {
			vr.push_back(new Graph_lib::Rectangle{ Point{i * 20, j * 20}, 20,20 });
			vr[vr.size() - 1].set_fill_color(Color{ i * 16 + j });
			vr[vr.size() - 1].set_color(Color::black);
			win.attach(vr[vr.size() - 1]);
		}

	win.wait_for_button();
}