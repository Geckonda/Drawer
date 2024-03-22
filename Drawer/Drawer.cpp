#include "Drawer.h"

Drawer::Drawer(HWND window) {
	this->window = window;
	context = GetDC(window);
	SetWindowPos(window, 0, 0, 0, 600, 600, SWP_SHOWWINDOW);
	RECT rect;
	GetWindowRect(window, &rect);
	width = rect.right + rect.right / 3;
	height = rect.bottom + rect.bottom/3;
	SetPen(RGB(255, 255, 255), 1);

	//Начало координат
	SetCenterX(width);
	SetCenterY(height);
	Sleep(100);
	DrawBorders();
}
//Drawer::~Drawer()
//{
//	DeleteObject(pen);
//	ReleaseDC(window, context);
//	DeleteDC(context);
//}
void Drawer::SetPen(COLORREF colour, int width)
{
	DeleteObject(pen);
	pen = CreatePen(PS_INSIDEFRAME, width, colour);
	SelectObject(context, pen);
}

/// <summary>
/// Рисует линию из одной точки в другую.
/// </summary>
/// <param name="context"></param>
/// <param name="x1">Начальная точка Х</param>
/// <param name="y1">Начальная точка Y</param>
/// <param name="x2">Конечная точка X</param>
/// <param name="y2">Конечная точка Y</param>
void Drawer::Line(int x1, int y1, int x2, int y2)
{
	Rearrangement(&x1, &y1, &x2, &y2);
	MoveToEx(context, x1, y1, NULL);
	LineTo(context, x2, y2);
}
void Drawer::Point(int x, int y/*, COLORREF col*/)
{
	Line(x, y, x, y);
	//Rearrangement(&x, &y);
	//SetPixel(dc, x, y, col);
}
void Drawer::Axes()
{
	Sleep(100);
	SetPen(RGB(255, 0, 0), 2);
	MoveToEx(context, 0, height / 2, NULL);
	LineTo(context, width - 1, height / 2);
	SetPen(RGB(0, 255, 0), 2);
	MoveToEx(context, width / 2, 0, NULL);
	LineTo(context, width / 2, height - 1);
	SetPen(RGB(255, 255, 255), 2);
}

void Drawer::DrawBorders()
{
	MoveToEx(context, 0, 0, NULL);
	LineTo(context, width, 0);

	MoveToEx(context, width, 0, NULL);
	LineTo(context, width, height);

	MoveToEx(context, width, height, NULL);
	LineTo(context, 0, height);

	MoveToEx(context, 0, height, NULL);
	LineTo(context, 0, 0);
}

void Drawer::Rearrangement(int* x1, int* y1, int* x2, int* y2)
{
	const byte multiplier = 10;
	*x1 = GetOX() + *x1 * multiplier;
	*x2 = GetOX() + *x2 * multiplier;
	*y1 = GetOY() - *y1 * multiplier;
	*y2 = GetOY() - *y2 * multiplier;
}

void Drawer::Rearrangement(int* x, int* y)
{
	*x = GetOX() + *x * 10;
	*y = GetOY() - *y * 10;
}