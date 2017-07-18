#ifndef __DATA__
#define __DATA__

#include <Windows.h>
#include <math.h>
#include <vector>

#define PI 3.14159265358979

using namespace std;

class Data
{
private:
	int size;
	vector< long double > data;
public:
	Data() {};
	Data(int n);
	void set(int i, long double d) { data[i] = d; }
	long double d1(int idx){ return data[idx]; }
	void draw(HDC hdc, COLORREF color);
	void draw(HDC hdc, COLORREF color, int cy, int cx);
};

#endif