#ifndef _MYGL_H_
#define _MYGL_H_
#endif

#include "definitions.h"
#include "line.h"
#include <vector>

//-----------------------------------------------------------------------------
void MyGlDraw(void);

//*****************************************************************************
// Defina aqui as suas funções gráficas
//*****************************************************************************

void PutPixel(int x, int y, std::vector<int>& color);
void DrawLine(Line line, std::vector<int>& color);
void DrawTriangle(Line l1, Line l2, Line l3, std::vector<int>& color);