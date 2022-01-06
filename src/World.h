class World
{
  World(int w, int h);
  ~World();
  void set_alive(std::vector<std::pair<int,int>> coords);
  void display();
  void translate_coords(std::vector<std::pair<int,int>> coords, int x, int y);

  int m_width, m_height;

};