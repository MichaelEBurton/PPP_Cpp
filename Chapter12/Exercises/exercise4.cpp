/*
	Exercise 4: Draw a 3-by-3 tic-tac-toe board of alternating white and red squares.

*/

#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	Point tl(100, 100);

	Simple_window win(tl, 600, 400, "Exercise 4");

	//=================================================================================================
	// Set up the board

	Graph_lib::Rectangle board(Point(150, 50), 300, 300);
	board.set_color(Color::black);
	board.set_fill_color(Color::white);

	//=================================================================================================
    // Draw the lines
	Lines borders;
	borders.add(Point(250, 50), Point(250, 350));
	borders.add(Point(350, 50), Point(350, 350));
	borders.add(Point(150, 150), Point(450, 150));
	borders.add(Point(150, 250), Point(450, 250));

	borders.set_color(Color::black);
	//=================================================================================================
	// Color red squares
	// white, red, white
	// red, white, red,
	// white, red, white

	Graph_lib::Rectangle r1(Point(250, 50), 100, 100);
	Graph_lib::Rectangle r2(Point(150, 150), 100, 100);
	Graph_lib::Rectangle r3(Point(350, 150), 100, 100);
	Graph_lib::Rectangle r4(Point(250, 250), 100, 100);
	r1.set_fill_color(Color::red);
	r2.set_fill_color(Color::red);
	r3.set_fill_color(Color::red);
	r4.set_fill_color(Color::red);

	//=================================================================================================
	win.attach(board);
	win.attach(borders);
	win.attach(r1);
	win.attach(r2);
	win.attach(r3);
	win.attach(r4);

	win.wait_for_button();

}