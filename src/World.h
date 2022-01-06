#ifndef __WORLD_H__
#define __WORLD_H__

#include "Cell.h"
#include <vector>


class Cell;

typedef std::vector<std::vector<Cell>> GRID;

class World
{
  public:
    World(int w, int h);
    ~World();
    void set_alive(const std::vector<POSITION> &coords);
    void set_dead(const std::vector<POSITION> &coords);
    void display() const;
    void translate_coords(std::vector<POSITION> &coords, int x, int y);
    void live();
    void create_spaceship(int x, int y);
    void create_cannon(int x, int y);




  private :
    int m_width, m_height;
    GRID m_grid;


};


#endif
