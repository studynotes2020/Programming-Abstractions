#include <iostream>

using namespace std;

/*
    The function supposed to draw triangle recursively
    TODO: Implement DrawTriangle
*/

void DrawFractal(double x, double y, double w, double h) {
    DrawTriangle(x, y, w, h);
    if (w < 0.2 || h < 0.2) return;
    double halfH = h/2;
    double halfW = w/2;
    DrawFractal(x, y, halfW, halfH);  // left
    DrawFractal(x + halfW/2, y + halfH, halfW, halfH);  // top
    DrawFractal(x + halfW, y, halfW, halfH);  // right

}

