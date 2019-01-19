#include <iostream>

using namespace std;

class Polar 
{
private:
	double radius = 0;
	double angle =  0;

public:
	Polar() : radius(0), angle(0) {}
	Polar(double r, double angle) : radius(r), angle(angle){}

	double GetRadius()	{ return radius; }
	double GetAngle()	{ return angle; }

	void Print()
	{
		cout << "radius: " << radius << " angle: " << angle << endl;
	}
};

class Euclidean
{
private:
	double x = 0;
	double y = 0;

public:
	Euclidean() : x(0), y(0) {}
	Euclidean(double x, double y) : x(x), y(y){}

	Euclidean(Polar polar)
	{
		x = polar.GetRadius() * cos(polar.GetAngle());
		y = polar.GetRadius() * sin(polar.GetAngle());
	}

	operator Polar()
	{
		double radius = sqrt
		(
			x * x +
			y * y
		);

		double angle = atan2(y, y);

		return Polar(radius, angle);
	}

	Euclidean operator+(Euclidean e2)
	{
		return Euclidean(x + e2.x, y + e2.y);
	}

	void operator+=(Euclidean e2)
	{
		x += e2.x;
		y += e2.y;
	}

	double GetX() { return x; }
	double GetY() { return y; }

	void Print()
	{
		cout << "x: " << x << " y: " << y << endl;
	}
};

int main()
{
	Polar p(1.4142135623731, 0.78539816339745), p2;
	Euclidean e, e2(1, 1);

	e = p;
	e.Print();

	e2 += e;

	e2.Print();

	p2 = e2;
	p2.Print();

	Euclidean e3 = p2;
	e3.Print();
}