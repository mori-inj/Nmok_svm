#include "data.h"

Data::Data(int n)
{
	size = n;
	data = vector < long double >(n);
}

void Data::draw(HDC hdc, COLORREF color)
{
	HPEN hPen, oldPen;
	hPen = CreatePen(PS_SOLID, 1, color);
	oldPen = (HPEN)SelectObject(hdc, hPen);

	for(int i = 0; i < size; i++)
	{
		MoveToEx(hdc, 400+100*(d1(i)+1)*cos(PI*2*i/size), 300+100*(d1(i)+1)*sin(PI*2*i/size), NULL);
		LineTo(hdc,400+100*(d1(i+1)+1)*cos(PI*2*(i+1)/size), 300+100*(d1(i+1)+1)*sin(PI*2*(i+1)/size));
	}

	SelectObject(hdc, oldPen);
	DeleteObject(hPen);
}


void Data::draw(HDC hdc, COLORREF color, int cy, int cx)
{
	HPEN hPen, oldPen;
	hPen = CreatePen(PS_SOLID, 1, color);
	oldPen = (HPEN)SelectObject(hdc, hPen);

	for(int i = 0; i < size; i++)
	{
		MoveToEx(hdc, cx+100*(d1(i)+1)*cos(PI*2*i/size), cy+100*(d1(i)+1)*sin(PI*2*i/size), NULL);
		LineTo(hdc,cx+100*(d1(i+1)+1)*cos(PI*2*(i+1)/size), cy+100*(d1(i+1)+1)*sin(PI*2*(i+1)/size));
	}

	SelectObject(hdc, oldPen);
	DeleteObject(hPen);
}