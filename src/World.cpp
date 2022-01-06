#include "World.h"
#include "vibes.h"

World::World(int w, int h): m_width(w),m_height(h) {

  // initialisation of the grid representing the board
  for (int i = 0; i < m_height; i++) {
    std::vector<Cell> tmp;
    for (int j = 0; j < m_width; j++) {
      tmp.push_back(Cell(j,i));
    }
    m_grid.push_back(tmp);
  }

  // initialisation of Vibes
  vibes::beginDrawing();
  vibes::newFigure("World");
  vibes::setFigureProperties("World", vibesParams("x", 100, "y", 100, "width", 1000, "height", 500));
  vibes::axisLimits(0, m_width, 0, m_height);
}

World::~World(){
    vibes::endDrawing();
}

void World::set_alive(const std::vector<POSITION> &coords){
  /**
  *  set alive all cell dor the corresponding positions
  */
  for (auto it=coords.begin(); it!=coords.end(); it++){
    int x = it->first;
    int y = it->second;
    m_grid[y][x].set_alive();
  }
}
void World::set_dead(const std::vector<POSITION> &coords){
  /**
  *  set dead all cell for the corresponding positions
  */
  for (auto it=coords.begin(); it!=coords.end(); it++){
    int x = it->first;
    int y = it->second;
    m_grid[y][x].set_alive(false);
  }
}

void World::display() const{
  /**
  * Display all the cells of the world
  */
  vibes::clearFigure("World");
  for (size_t i = 0; i < m_height; i++) {
    for (size_t j = 0; j < m_width; j++) {
      m_grid[i][j].display();
    }
  }
}

void World::translate_coords(std::vector<POSITION> &coords, int x, int y){
  /**
  * translate coords of x and y (modifies coords)
  */
  for (auto it=coords.begin(); it!=coords.end(); it++){
    it->first += x;
    it->second += y;
  }
}

void World::live(){
  /**
  * Simulate one step of the Game of Life
  */
  std::vector<POSITION> to_kill; // Cells to kill
  std::vector<POSITION> to_revive; // Cells to be revived
  for (int y = 0; y < m_height; y++) {
    for (int x = 0; x < m_width; x++) {
      int S = 0;
      for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
          if (!(i==0 && j==0) && y+i>=0 && x+j>=0 && x+j<m_width && y+i <m_height){
            m_grid[y+i][x+j].alive() ? S++:true;
          }
        }
      }
      int E = m_grid[y][x].alive();
      ((S == 3) || (E == 1 && S == 2)) ? to_revive.push_back(POSITION(x,y)) : to_kill.push_back(POSITION(x,y));
    }
  }
  set_alive(to_revive);
  set_dead(to_kill);
}

void World::create_spaceship(int x, int y){
  /**
  * Create a spaceship in the desired initila position
  */
  std::vector<POSITION> spaceship = {{-1,0}, {-2,1}, {-0,2}, {-1,2}, {-2,2}};
  translate_coords(spaceship,x,y);
  set_alive(spaceship);
}

void World::create_cannon(int x, int y){
  std::vector<POSITION> cannon = {{ 1,5},{ 2,5},{ 1,6},{ 2,6},{35,3},{36,3},{35,4},{36,4},{13,3},{14,3},{12,4},{16,4},{11,5},{17,5},{11,6},{15,6},{17,6},{18,6},{11,7},{17,7},{12,8},{16,8},{13,9},{14,9},{25,1},{23,2},{25,2},{21,3},{22,3},{21,4},{22,4},{21,5},{22,5},{23,6},{25,6},{25,7}};
  translate_coords(cannon,x,y);
  set_alive(cannon);
}
