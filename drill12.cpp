//g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
#include "Simple_window.h"
#include "Graph.h"

int main()
{
  using namespace Graph_lib;
  Point tl {100,100};
  Simple_window win{tl,600,400,"My window"};
  win.wait_for_button();

  Axis xa{Axis::x,Point{20,300},280,10,"x axis"};
  xa.set_color(Color::blue);
  win.attach(xa);
  win.set_label("My window #2");
  win.wait_for_button();

  Axis ya{Axis::y,Point{20,300},280,10,"y axis"};
  win.attach(ya);
  win.set_label("My window #3");
  win.wait_for_button();

  Function sine {sin,0,100,Point{20,150},1000,50,50};
  win.attach(sine);
  sine.set_style(Line_style(Line_style::dash,4));
  win.set_label("My window #4");
  win.wait_for_button();

  Polygon poly;
  poly.add(Point{300,200});
  poly.add(Point{350,100});
  poly.add(Point{400,200});
  poly.set_color(Color::red);
  poly.set_style(Line_style::dash);
  win.attach(poly);
  win.set_label("My window #5");
  win.wait_for_button();

  Rectangle r {Point{200,200},100,50};
  win.attach(r);
  win.set_label("My window #6");
  r.set_fill_color(Color::cyan);
  win.wait_for_button();

  Closed_polyline poly_rect;
  poly_rect.add(Point{100,50});
  poly_rect.add(Point{200,50});
  poly_rect.add(Point{200,100});
  poly_rect.add(Point{100,100});
  poly_rect.add(Point{50,75});
  poly_rect.set_fill_color(Color::green);
  win.attach(poly_rect);
  win.set_label("My window #7");
  win.wait_for_button();

  Text t{Point{300,50}, "Git Gud"};
  t.set_font_size(20);
  win.attach(t);
  win.set_label("My window #8");
  win.wait_for_button();

  Image ii{Point{0,0},"giant400x400.jpg"};
  ii.move(300,300);
  win.attach(ii);
  win.set_label("Git Gud");
  win.wait_for_button();

}
