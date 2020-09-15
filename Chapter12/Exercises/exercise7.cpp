/*
	Exercise 7: Draw a two-dimensional house seen from the front, the way a child would:
	             with a door, two windows, and a roof with a chimney. Feel free to add
				 details; maybe have "smoke" come out of the chimney.

	Notes: I know I could have added more details (window panes, and smoke); however I felt I had a good grasp on the concepts this exercise was testing.
*/

#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 100,100 };
	
	Simple_window win{ tl, 600,400, "Exercise 7" };
	
	// ===================================================================================================
	// Set the background

	Graph_lib::Rectangle sky{ Point(0,0), 600,300 };
	sky.set_fill_color(Color::cyan);

	Graph_lib::Rectangle grass{ Point(0,300), 600,100 };  // grass
	grass.set_fill_color(Color::green);

	// ===================================================================================================
	// Build the house

	//house walls
	Graph_lib::Rectangle walls{ Point(50,100), 300,200 }; 
	walls.set_fill_color(Color::dark_blue);

	// chimney
	Graph_lib::Rectangle chimney(Point(300, 50), 45, 50);
	chimney.set_fill_color(Color::black);

	// roof
	Graph_lib::Polygon roof;
	roof.add(Point(25, 100));
	roof.add(Point(375, 100));
	roof.add(Point(200, 25));
	roof.set_fill_color(Color::black);

	// windows
	Graph_lib::Rectangle window1{ Point(70,175), 50,50 };
	Graph_lib::Rectangle window2{ Point(280,175),50,50 };

	window1.set_fill_color(Color::white);
	window2.set_fill_color(Color::white);

	
	// door
	Graph_lib::Rectangle door{ Point(175, 200), 50, 100 };
	door.set_fill_color(Color::black);

	// door knob
	Graph_lib::Ellipse dknob{ Point(215, 250),5,3 };
	dknob.set_fill_color(Color::dark_yellow);

	// ===================================================================================================
	win.attach(sky);
	win.attach(grass);
	win.attach(walls);
	win.attach(chimney);
	win.attach(roof);
	win.attach(window1);
	win.attach(window2);
	win.attach(door);
	win.attach(dknob);
	win.wait_for_button();

}