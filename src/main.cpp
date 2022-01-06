#include <iostream>

#include "Cell.h"
#include "vibes.h"
#include "World.h"

#include <unistd.h>

int main(int argc, char const *argv[]) {

  World W(80,40);
  W.create_spaceship(40,20);
  W.create_cannon(0,0);
  W.display();
  usleep(100000.);



  for (int t = 0; t < 1000; t++) {
    if(t==30){
      W.create_spaceship(60,2);
    }
    W.live();
    W.display();
    std::cout << "Step n°"<< t  << '\n';
    usleep(100000.);
  }






  return 0;
}
