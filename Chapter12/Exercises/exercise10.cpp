/*
	Exercise 10: Draw the file diagram from section 12.8

	Note: I have chosen not to add the arrows for the sake of time.
*/

#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	Point tl{ 25,100 };

	Simple_window win{ tl, 800, 600, "Exercise 10" };

	// ===========================================================================================================================
	// point.h box

	Graph_lib::Rectangle p(Point{ 50,50 }, 125, 30);
	p.set_color(Color::black);
	p.set_fill_color(Color::dark_yellow);
	Text t1{ Point{55,65}, "struct Point{...};" };
	t1.set_color(Color::black);
	Text t2{ Point{50, 45}, "Point.h:" };
	t2.set_color(Color::black);

	win.attach(p);
	win.attach(t1);
	win.attach(t2);

	// ===========================================================================================================================
	//FLTK Headers

	Graph_lib::Rectangle fl1{ Point{350, 10}, 100,50 };
	fl1.set_color(Color::black);
	fl1.set_fill_color(Color::dark_yellow);
	Graph_lib::Rectangle fl2{ Point{355, 15}, 100,50 };
	fl2.set_color(Color::black);
	fl2.set_fill_color(Color::dark_yellow);
	Graph_lib::Rectangle fl3{ Point{360, 20}, 100,50 };
	fl3.set_color(Color::black);
	fl3.set_fill_color(Color::dark_yellow);

	Text t3{ Point{365, 40}, "FLTK headers" };
	t3.set_color(Color::black);

	win.attach(fl1);
	win.attach(fl2);
	win.attach(fl3);
	win.attach(t3);
	
	// ===========================================================================================================================
	// FLTK code

	Graph_lib::Rectangle fl4{ Point{650, 60}, 100,50 };
	fl4.set_color(Color::black);
	fl4.set_fill_color(Color::dark_yellow);
	Graph_lib::Rectangle fl5{ Point{655, 65}, 100,50 };
	fl5.set_color(Color::black);
	fl5.set_fill_color(Color::dark_yellow);
	Graph_lib::Rectangle fl6{ Point{660, 70}, 100,50 };
	fl6.set_color(Color::black);
	fl6.set_fill_color(Color::dark_yellow);

	Text t4{ Point{665, 90}, "FLTK code" };
	t4.set_color(Color::black);

	win.attach(fl4);
	win.attach(fl5);
	win.attach(fl6);
	win.attach(t4);

	// ===========================================================================================================================
	// Graph.h
	Graph_lib::Rectangle gh{ Point{50, 180}, 150, 65 };
	gh.set_color(Color::black);
	gh.set_fill_color(Color::dark_yellow);

	Text t5{ Point{55, 175}, "Graph.h" };
	t5.set_color(Color::black);
	Text t6{ Point{55, 195}, "// graphing interface:" };
	t6.set_color(Color::black);
	Text t7{ Point{55, 215}, "struct Shape {...};" };
	t7.set_color(Color::black);
	Text t8{ Point{55, 230}, "..." };
	t8.set_color(Color::black);

	win.attach(gh);
	win.attach(t5);
	win.attach(t6);
	win.attach(t7);
	win.attach(t8);


	// ===========================================================================================================================
	// Window.h

	Graph_lib::Rectangle wh{ Point{340,140}, 140, 65 };
	wh.set_color(Color::black);
	wh.set_fill_color(Color::dark_yellow);

	Text t9{ Point{345, 135}, "Window.h" };
	t9.set_color(Color::black);
	Text t10{ Point{345,155}, "// window interface:" };
	t10.set_color(Color::black);
	Text t11{ Point{345, 175}, "class Window {...}" };
	t11.set_color(Color::black);
	Text t12{ Point{345, 190}, "..." };
	t12.set_color(Color::black);


	win.attach(wh);
	win.attach(t9);
	win.attach(t10);
	win.attach(t11);
	win.attach(t12);
	

	// ===========================================================================================================================
	// window.cpp
	Graph_lib::Rectangle wc{ Point{200, 275}, 120, 30 };
	wc.set_color(Color::black);
	wc.set_fill_color(Color::dark_yellow);

	Text t13{ Point{205, 270}, "window.cpp:" };
	t13.set_color(Color::black);
	Text t14{ Point{205, 290}, "Window code" };
	t14.set_color(Color::black);

	win.attach(wc);
	win.attach(t13);
	win.attach(t14);

	// ===========================================================================================================================
	// GUI.h
	Graph_lib::Rectangle guh{ Point{460, 230}, 140, 60 };
	guh.set_color(Color::black);
	guh.set_fill_color(Color::dark_yellow);

	Text t15{ Point{465, 225}, "GUI.h:" };
	t15.set_color(Color::black);
	Text t16{ Point{465, 245}, "struct In_box {...};" };
	t16.set_color(Color::black);
	Text t17{ Point{465, 265}, "..." };
	t17.set_color(Color::black);

	win.attach(guh);
	win.attach(t15);
	win.attach(t16);
	win.attach(t17);


	// ===========================================================================================================================
	// GUI.cpp

	Graph_lib::Rectangle gucp{ Point{490, 330}, 100, 30 };
	gucp.set_color(Color::black);
	gucp.set_fill_color(Color::dark_yellow);

	Text t18{ Point{495, 325}, "GUI.cpp:" };
	t18.set_color(Color::black);
	Text t19{ Point{495, 345}, "GUI code" };
	t19.set_color(Color::black);

	win.attach(gucp);
	win.attach(t18);
	win.attach(t19);

	// ===========================================================================================================================
	// graph.cpp

	Graph_lib::Rectangle gcp{ Point{15,330}, 100, 30 };
	gcp.set_color(Color::black);
	gcp.set_fill_color(Color::dark_yellow);

	Text t20{ Point{20, 325}, "Graph.cpp:" };
	t20.set_color(Color::black);
	Text t21{ Point{20, 345}, "Graph code" };
	t21.set_color(Color::black);

	win.attach(gcp);
	win.attach(t20);
	win.attach(t21);

	// ===========================================================================================================================
	// Simple_window.h
	Graph_lib::Rectangle sw{ Point{225, 355}, 180, 65 };
	sw.set_color(Color::black);
	sw.set_fill_color(Color::dark_yellow);

	Text t22{ Point{230, 350}, "Simple_window.cpp:" };
	t22.set_color(Color::black);
	Text t23{ Point{230, 370}, "// window interface" };
	t23.set_color(Color::black);
	Text t24{ Point{230, 390}, "class Simple_window {...}" };
	t24.set_color(Color::black);
	Text t25{ Point{230, 410}, "..." };
	t25.set_color(Color::black);

	win.attach(sw);
	win.attach(t22);
	win.attach(t23);
	win.attach(t24);
	win.attach(t25);

	// ===========================================================================================================================
	// chapter12.cpp
	Graph_lib::Rectangle c12{ Point{65, 460}, 200, 65 };
	c12.set_color(Color::black);
	c12.set_fill_color(Color::dark_yellow);

	Text t26{ Point{70, 455}, "chapter12.cpp:" };
	t26.set_color(Color::black);
	Text t27{ Point{70, 475}, "#include \"Graph.h\"" };
	t27.set_color(Color::black);
	Text t28{ Point{70, 495}, "#include \"Simple_window.h\"" };
	t28.set_color(Color::black);
	Text t29{ Point{70, 505}, "int main() {...}" };
	t29.set_color(Color::black);

	win.attach(c12);
	win.attach(t26);
	win.attach(t27);
	win.attach(t28);
	win.attach(t29);

	// ===========================================================================================================================
	// Lines connect boxes

	Lines connector;
	connector.add(Point{ 125, 180 }, Point{ 125, 80 }); // graph to point
	connector.add(Point{ 125,180 }, Point{ 365,70 }); // graph to FLTK headers
	connector.add(Point{ 355,140 }, Point{ 160, 80 }); // Window.h to Point.h
	connector.add(Point{420, 140 }, Point{420, 70 }); // Window.h to FTLK Headers
	connector.add(Point{ 650, 85 }, Point{ 460, 50 }); // FLTK code to FLTK Headers
	connector.add(Point{ 560, 230 }, Point{ 475, 205 }); //GUI.h to Window.h
	connector.add(Point{ 560, 230 }, Point{ 450, 70 }); //GUI.h to FLTK headers
	connector.add(Point{ 300, 275 }, Point{ 380, 205 }); // Window.cpp to Window.h
	connector.add(Point{ 85, 330 }, Point{ 100, 245 }); //graph.cpp to graph.h
	connector.add(Point{ 395, 355}, Point{ 395, 205 }); // Simple_window.h to Window.h
	connector.add(Point{ 395, 355 }, Point{ 470, 290 }); // Simple_window to GUI.h
	connector.add(Point{ 580, 330 }, Point{ 560, 290 }); // GUI.cpp to GUI.h
	connector.add(Point{ 175, 460 }, Point{ 110, 245 }); // chapter12.cpp to graph.h
	connector.add(Point{ 175, 460 }, Point{ 245, 420 }); // chapter12.cpp to Simple_window.h
	connector.set_color(Color::black);

	win.attach(connector);

	win.wait_for_button();
	
}