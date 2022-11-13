// файл Global.cpp
////////////////////////////////////////
//Реализация глобальных функций
#include "stdafx.h"
#include "global.h"
#include <math.h>


CPoint Transform(const CPoint &point,
	       const CPoint &point0, double ang, int a, int b)
{
   CPoint res;
   	//Перевод в радианы
	ang=ang*atan(1.0)/45.0;
   res.x=(int)floor(point0.x+(point.x-point0.x)*cos(ang)-(point.y-point0.y)*sin(ang)+a+0.5);
   res.y=(int)floor(point0.y+(point.x-point0.x)*sin(ang)+(point.y-point0.y)*cos(ang)+b+0.5);
   return res;
};

double ZFunction(double x, double y)
{
	return (x*x+y*y)/10000;
}


CPoint GetMiddle(CPoint a1, CPoint a2, double l)
{
	return CPoint((l * a2.x + a1.x) / (l + 1) , (l * a2.y + a1.y) / (l + 1));
}

double GetLenght(CPoint a1, CPoint a2)
{
	return sqrt((a2.x - a1.x) * (a2.x - a1.x) + (a2.y - a1.y) * (a2.y - a1.y));
}

double angle(int x1, int y1, int x2, int y2)
{
	double t = (x1 * x2 + y1 * y2) / (sqrt((double)x1 * x1 + y1 * y1) * sqrt((double)x2 * x2 + y2 * y2));
	if (t < -1) t = -1;
	else if (t > 1) t = 1;
	return acos(t);
}
