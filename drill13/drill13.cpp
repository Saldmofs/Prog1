//g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
#include "Simple_window.h"
#include "Graph.h"
int main()
{
    using namespace Graph_lib;
  Point tl {100,100};
  Simple_window win{tl,800,1000,"My window"};
  int x_size = 800;
  int y_size = 800;
  int x_grid = 100;
  int y_grid = 100;

  Lines grid;
  for(int x = x_grid; x <= x_size; x+=x_grid)
  {
    grid.add(Point{x,0},Point{x,y_size});
  }
  for(int y = y_grid; y <= y_size; y+=y_grid)
  {
    grid.add(Point{0,y},Point{x_size,y});
  }
  win.attach(grid);

  Vector_ref<Rectangle> vr;
  int a = 0;
  for (int i = 0; i<8; i++)
  {
   for (int j = 0; j<8; j++) 
   {
    vr.push_back(new Rectangle{Point{a,a},100,100});
    vr[vr.size()-1].set_fill_color(Color::red);
    win.attach(vr[vr.size()-1]);
   }
   a+=100;
  }
 
  win.wait_for_button();
  Image gitgud {Point{0,200},"giant400x400.jpg"};
  gitgud.set_mask(Point{0,0},200,200); 
  Image gitgud1 {Point{0,400},"giant400x400.jpg"};
  gitgud1.set_mask(Point{0,0},200,200); 
  Image gitgud2 {Point{0,600},"giant400x400.jpg"};
  gitgud2.set_mask(Point{0,0},200,200); 
  win.set_label("win2");
  win.attach(gitgud);
  win.attach(gitgud1);
  win.attach(gitgud2);
  win.wait_for_button();
  win.detach(gitgud);
  win.detach(gitgud1);
  win.detach(gitgud2);
  win.set_label("win3");
  win.wait_for_button();

  while(true){
    for(int i = 0; i < 701; i += 100)
    {
      for(int j = 0; j < 701; j += 100)
      {
        Image gitgud3{Point{j, i}, "giant400x400.jpg"};
        gitgud3.set_mask(Point(0, 0), 100, 100);
        win.attach(gitgud3);
        win.set_label("win4");
        win.wait_for_button();
      }
    }
  }
}