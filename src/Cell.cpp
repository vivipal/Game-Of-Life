#include "Cell.h"
#include "vibes.h"

Cell::Cell(STATE state) : m_x(0),m_y(0),m_state(state){

}

Cell::Cell(int x, int y,STATE state) : m_x(x),m_y(y),m_state(state){

}



void Cell::display() const{
  /**
  * Draw a square box ([x, x + 1] × [y, y + 1]) of the color according to its state
  * colors :
  *   alive -> blue
  *   newly alive -> green
  *   dead -> white
  *   newly dead -> red
  */
  char *color;
  if (m_state!=DEAD){ // dont display dead cells (waste of time)
    switch (m_state) {
      case ALIVE:
        color = "blue[blue]";
        break;
      case NEWLY_ALIVE:
        color = "green[green]";
        break;
      case NEWLY_DEAD:
        color = "red[red]";
        break;
    }
    vibes::drawBox(m_x,m_x+1,m_y+1,m_y,vibesParams("figure", "World",color));
  }
}

void Cell::set_alive(bool new_state){
  /**
  * Set the new state  for the cell
  * Default state is true
  */
  if (alive()){
    (new_state==true) ? (m_state = ALIVE) : (m_state = NEWLY_DEAD);
  }else{
    (!new_state) ? (m_state = DEAD) : (m_state = NEWLY_ALIVE);
  }
}

bool Cell::alive() const{
  /**
  * return the state of the cell
  */
  if (m_state==ALIVE || m_state==NEWLY_ALIVE){
    return true;
  }else{
    return false;
  }
}

POSITION Cell::get_pos() const{
  /**
  * return a POSITION (std::pair<int,int>) filled with the position of the cell
  */
  POSITION p;
  p.first = m_x;
  p.second = m_y;
  return p;
}

STATE Cell::get_state() const{
  /**
  * return the current state of the cell
  */
  return m_state;
}
