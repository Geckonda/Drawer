#pragma once
#define _WIN32_WINNT 0x0501
#include <conio.h>
#include <windows.h>
class Drawer
{
private:
	int width = 0;
	int height = 0;
	int oX = 0;
	int oY = 0;
	HWND window;
	HPEN pen;
	HBRUSH brush;

	void SetCenterX(int x) { this->oX = x / 2; }
	void SetCenterY(int y) { this->oY = y / 2; }

	void Rearrangement(int*, int*, int*, int*);
	void Rearrangement(int*, int*);
public:
	HDC context;
	void SetPen(COLORREF, int);
	//void SetBrush(HDC context, COLORREF, bool);
	void Line(int, int, int, int);
	void Point(int, int /*, COLORREF*/);
	void Axes();
	void DrawBorders();
	Drawer(HWND);
	//~Drawer();
	int GetWidth() { return this->width; }
	int GetHeight() { return this->height; }
	int GetOX() { return this->oX; }
	int GetOY() { return this->oY; }
};

