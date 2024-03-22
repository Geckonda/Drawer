#include <iostream>
#include "Drawer.h"
#include <windows.h>
#include <math.h>

using namespace std;


const int nSize = 40;
void PseudoEllips(Drawer drawer)
{
    //έλλθορ
    const int n = 120;
    const int radius = n * 10;
    const int step = 1;
    for (int i = -n; i < n; i+=step)
    //for (float i = -n; i < n; i += 0.1f)
    {
        double x = pow(i, 2);
        double x2 = pow(i + step, 2);
        int r = sqrt(radius - x);
        int r2 = sqrt(radius - x2);
        if (r < 0 && r2 < 0)
            continue;

        //Sleep(1);

        drawer.SetPen(RGB(255, 223, 0), 3);
        drawer.Line(i, r, i + step, r2);
        drawer.Line(i, -r, i + step, -r2);
    }

}
void Rhombus(Drawer drawer)
{
    drawer.SetPen(RGB(25, 57, 33), 6);
    drawer.Line(-5, 0, 0, 5);
    drawer.Line(-5, 0, 0, -5);
    drawer.Line(0, 5, 5, 0);
    drawer.Line(0, -5, 5, 0);
}
void Hyperbola(Drawer drawer)
{
    for (int i = -nSize + 1; i < nSize; i++)
        //for (float i = -nSize; i < nSize; i += 0.1f)
    {
        if (i != 0 && i - 1 != 0) {
            drawer.SetPen(RGB(65, 103, 225), 5);
            drawer.Line(i - 1, (20 / (i - 1)), i, (20 / i));
        }
    }
}
void Parabola(Drawer drawer)
{
    for (int i = -nSize + 1; i < nSize; i++)
    {
        Sleep(1);
        drawer.Line(i - 1, pow(i - 1, 2), i, pow(i, 2));
    }
}
void Spoke(Drawer drawer, int x, int y)
{
    drawer.Line(x, y, -x, -y);
}

int main()
{
    setlocale(LC_ALL, "");
    Drawer drawer(GetConsoleWindow());
    //drawer.Axes();

    drawer.SetPen(RGB(153, 102, 204), 1);
    int x = 0, y = 30;
    bool reverse = false;
    while (true)
    {
        PseudoEllips(drawer);
        Spoke(drawer, x, y);
        //Sleep(100);
        system("CLS");
        if (!reverse)
        {
            if (++x > 30)
                reverse = !reverse;
        }
        else {
            if (--x <= 0) {
                reverse = !reverse;
                x = 0;
            }
        }
        y >= -30 ? y-- : y = 30;
    }
    //Sleep(100);
    //drawer.SetPen(RGB(3, 102, 77), 2);
    //Hyperbola(drawer);
    //drawer.SetPen(RGB(83, 152, 77), 2);
    //Parabola(drawer);
    //Rhombus(drawer, drawer.context);
    cin.get();
}
