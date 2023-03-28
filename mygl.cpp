#include "definitions.h"
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <vector>
#include "line.h"
#include "mygl.h"

using namespace std;

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
  std::vector<int> color;
  //rgb(0, 255, 255, 255) = aqua
  color.push_back(0);
  color.push_back(255);
  color.push_back(255);
  color.push_back(255);

  Line l1, l2, l3;
  l1.setLine(0, 0, 400, 200);
  l2.setLine(0, 0, 100, 300);
  l3.setLine(100, 300, 400, 200);

  //*************************************************************************
  // Chame aqui as funções do mygl.h
  //*************************************************************************
  DrawTriangle(l1, l2, l3, color);

}

void PutPixel(int x, int y, std::vector<int>& color) {
  FBptr[(4*x+0) + (4*y*IMAGE_WIDTH)] = color.at(0);
  FBptr[(4*x+1) + (4*y*IMAGE_WIDTH)] = color.at(1);
  FBptr[(4*x+2) + (4*y*IMAGE_WIDTH)] = color.at(2);
  FBptr[(4*x+3) + (4*y*IMAGE_WIDTH)] = color.at(3);
}

void DrawLine(Line line, std::vector<int>& color)
{
  int x0 = line.x0;
  int y0 = line.y0;
  int x1 = line.x1;
  int y1 = line.y1;

  int dx = x1-x0;
  int dy = y1-y0;
  int d;

  int incr_e;
  int incr_ne;
  int x = x0;
  int y = y0;

  int ranged = 0;
  int aux = 0;
  PutPixel(x,y, color);

  //0º a 90º
  if(dx > 0 && dy > 0) {
    //0º a 45º
    if(abs(dx) > abs(dy)) {
      d = 2*dy-dx;
      incr_e = 2 * dy;
      incr_ne = 2 * (dy-dx);

      ranged = x1-x;
      while(x < x1) {
        if(d < 0) {
          d += incr_e;
          x++;
        } else {
          d += incr_ne;
          x++;
          y++;
        }
        PutPixel(x, y, color);
        aux++;
      }
    }
    //45º a 90º
    else {
      d = dy-2*dx;
      incr_e = 2*(dy-dx);
      incr_ne = -2*dx;

      ranged = abs(y1) - abs(y0);
      while(abs(y) < abs(y1)) {
        if(d < 0) {
          d += incr_e;
          x++;
          y++;
        } else {
          d += incr_ne;
          y++;
        }
        PutPixel(x, y, color);
        aux++;
      }
    }
  }
  //90º a 180º
  else if(dx < 0 && dy > 0) {
    //90º a 135º
    if(abs(dy) > abs(dx)) {
      d = dy+2*dx;
      incr_e = 2*dx;
      incr_ne = 2*(dy+dx);

      ranged = abs(y1) - abs(y);
      while(abs(y) < abs(y1)) {
        if(d < 0) {
          d += incr_ne;
          y1--;
        } else {
          d += incr_e;
          y1--;
          x1++;
        }
        PutPixel(x1, y1, color);
        aux++;
      }
    } else {
      d = 2*dy+dx;
      incr_e = 2*(dy+dx);
      incr_ne = 2*dy;

      ranged = abs(x) - abs(x1);
      while(abs(x1) < abs(x)) {
        if(d < 0) {
          d += incr_ne;
          x1++;
        } else {
          d += incr_e;
          x1++;
          y1--;
        }
        PutPixel(x1, y1, color);
        aux++;
      }
    }
  }
  //180º a 270º
  else if(dx < 0 && dy < 0) {
    int x0 = line.y1;
    int y0 = line.x1;
    int x1 = line.y0;
    int y1 = line.x1;

    Line l;
    l.setLine(x0, y0, x, y1);

    DrawLine(l, color);
  }
  //270º a 360º
  else {
    //dx > 0 dy < 0
    // std::cout << "DRIBE DO RONADINHO2" << '\n';
    // x0 = vertex.getx1();
    // y0 = vertex.gety1();
    // x1 = vertex.getX1();
    // y1 = vertex.gety0();
    int x0 = line.x1;
    int y0 = line.y1;
    int x1 = line.x0;
    int y1 = line.y0;

    Line l;
    l.setLine(x0, y0, x, y1);

    DrawLine(l, color);
  }
}

void DrawTriangle(Line l1, Line l2, Line l3, std::vector<int>& color) {
  DrawLine(l1, color);
  DrawLine(l2, color);
  DrawLine(l3, color);
}