/*
	Exercise 6: Write a program that draws a class diagram like the one in section 12.6. It will
	            simplify matters if you start by defining a Box class that is a rectangle with a 
				text label.
*/

#include "Graph.h"
#include "Box.h"
#include "Simple_window.h"

using namespace Graph_lib;

namespace Graph_lib {

	struct Box_text : Shape {
		Box_text(Point pp, int ww, int hh, string ss);
		Box_text(Point x, Point y, string ss);
		void draw_lines() const;

		int height() const { return h; }
		int width() const { return w; }

	private:
		Point p;
		int w;
		int h;
		string s;
	};

	Box_text::Box_text(Point pp, int ww, int hh, string ss)
		:p{ pp }, w{ ww }, h{ hh }, s{ ss }
	{
		if (h <= 0 || w <= 0)
			error("Bad Box: non-positive side");
		add(p);
	}

	Box_text::Box_text(Point x, Point y, string ss)
		:p{ x }, w{ y.x - x.x }, h{ y.y - x.y }, s{ ss }
	{
		if (h <= 0 || w <= 0)
			error("Bad Box: non-positive side");
		add(x);
	}

	void Box_text::draw_lines() const 
	{	
		int t_increment = 11;
		if (fill_color().visibility())
		{
			fl_color(fill_color().as_int());
			fl_rectf(p.x, p.y, w, h);
			fl_draw(s.c_str(), p.x + 10, p.y + h/2);
		}
		
		if (color().visibility()) 
		{
			fl_color(color().as_int());
			fl_rect(p.x, p.y, w, h);
			fl_draw(s.c_str(), p.x + 10, p.y + h/2);
		}
	}
}

int main()

{
	Point tl{ 100,100 };

	Simple_window win{ tl, 600,400, "Exercise 6" };
	int length_per_char = 10; // how much space to allocate per a character

	//=========================================================================================================================
	// Top row

	vector<string> top_row = { "Window", " Line_style", "Color" };

	Vector_ref<Box_text> vtr;
	int top_x = 150; //starting x coord for first box
	int top_y = 100; // y coord for all boxes


	//Loop through the vector containing the strings and draw text boxes as well as arrows to shape box
	for (int i = 0; i < top_row.size(); ++i)
	{
		if (i > 0) top_x += top_row[i - 1].length() * length_per_char + 50;
		vtr.push_back(new Box_text(Point{ top_x,top_y }, top_row[i].length() * length_per_char, 35, top_row[i]));
		vtr[vtr.size() - 1].set_color(Color::black);
		vtr[vtr.size() - 1].set_fill_color(Color::yellow);
		win.attach(vtr[vtr.size() - 1]);
	}

	//=========================================================================================================================
	// Middle row

	Box_text sw{ Point{75, 250}, 135, 35, "Simple_Window"};
	sw.set_fill_color(Color::yellow);
	sw.set_color(Color::black);
	win.attach(sw);

	Line l{ Point{180, 250}, Point{180,135} };
	l.set_color(Color::black);
	win.attach(l);

	string sh_lab = "Shape";
	Box_text sh{ Point{250, 230}, 55, 35, sh_lab };
	sh.set_fill_color(Color::yellow);
	sh.set_color(Color::black);
	win.attach(sh);

	
	Box_text pp{ Point{345, 250}, 55, 35, "Point" };
	pp.set_fill_color(Color::yellow);
	pp.set_color(Color::black);
	win.attach(pp);


	//=========================================================================================================================
	// Bottom Row

	vector<string> bottom_row = { "Line", "Lines", "Polygon", "Axis", "Rectangle", "Text", "Image" }; //Text for box

	Vector_ref<Box_text> vbr;
	Lines bottom_to_shape;
	int bottom_x = 75; //starting x coord for first box
	int bottom_y = 350; // y coord for all boxes


	//Loop through the vector containing the strings and draw text boxes as well as arrows to shape box
	for (int i = 0; i < bottom_row.size(); ++i)
	{
		if (i > 0) bottom_x += bottom_row[i - 1].length()*length_per_char + 10;
		vbr.push_back(new Box_text(Point{ bottom_x,bottom_y }, bottom_row[i].length()*length_per_char, 35, bottom_row[i]));
		vbr[vbr.size() - 1].set_color(Color::black);
		vbr[vbr.size() - 1].set_fill_color(Color::yellow);
		win.attach(vbr[vbr.size() - 1]);

		bottom_to_shape.add(Point{ bottom_x + int(bottom_row[i].length() * length_per_char)/ 2, bottom_y }, Point{ 250 + 8 * i, 265 });

	}

	bottom_to_shape.set_color(Color::black);
	win.attach(bottom_to_shape);


	win.wait_for_button();
}