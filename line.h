#ifndef LINE_H
#define LINE_H

typedef struct line{
  int x0, y0;
  int x1, y1; 
  
  void setLine(const int x0, const int y0, const int x1, const int y1)
  {
    this->x0 = x0;
    this->y0 = y0;
    this->x1 = x1;
    this->y1 = y1;
  }
}Line;

#endif