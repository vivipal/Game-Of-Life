#ifndef __CELL_H__
#define __CELL_H__

#include <utility> // use std::pair

enum CellState {ALIVE, NEWLY_ALIVE, DEAD, NEWLY_DEAD};

typedef int STATE;
typedef std::pair<int,int> POSITION;

class Cell
{
  public :
    Cell(STATE state = DEAD);
    Cell(int x, int y, STATE state = DEAD);
    void display() const;
    void set_alive(bool new_state=true);
    bool alive() const;
    POSITION get_pos() const;
    STATE get_state() const;




  private :
    int m_x,m_y; // position of the cell
    STATE m_state; // status of the cell (true = alive | false = Dead)

};

#endif
