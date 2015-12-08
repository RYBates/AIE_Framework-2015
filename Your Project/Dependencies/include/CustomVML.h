#pragma once
#include <iostream>   //c++ standard library
#include <cmath>      //c++ library that allows the use of "sqrt" and "pow" math
using namespace std;

template<typename T>
class Vec2 //template class for 2D vectors
{
public:
	T x, y; //variables

	Vec2() //Default constructor
	{
		x, y = 0;
	}

	Vec2(T a, T b) //Custom constructor
	{
		x = a;
		y = b;
	}

	Vec2 operator+(const Vec2 &other) //overload operator for addition
	{
		T newX = x + other.x;
		T newY = y + other.y;
		return Vec2(newX, newY);
	}

	Vec2 operator-(const Vec2 &other) //overload operator for subtraction
	{
		T newX = x - other.x;
		T newY = y - other.y;
		return Vec2(newX, newY);
	}

	Vec2 operator*(const Vec2 &other) //overload operator for multiplication
	{
		T newX = x * other.x;
		T newY = y * other.y;
		return Vec2(newX, newY);
	}

	//float mag2 function. This function will compute the magnitude of 2D 
	//vectors
	double mag2()
	{
		return sqrtf(x * x + y * y);
	}

	//float nor2X, nor2Y, and nor2Z function(s). These functions will compute
	//the normalise of 2D vectors. The reason for 2 normalise functions, did
	//not work when put together
	double nor2X()
	{
		double nX = x / sqrtf(x * x + y * y);
		return nX;
	}

	double nor2Y() 
	{
		double nY = y / sqrtf(x * x + y * y);
		return nY;
	}

	//float dot2 function. This function will compute the dot product of 2D
	//vectors.
	double dot2()
	{
		double d2 = x + y;
		cout << d2 << endl;
		return d2;
	}

	//linear Interpolation
	Vec2 operator%(const Vec2 &other)
	{
		T newX = (x + (.5*(other.x - x)));
		T newY = (y + (.5*(other.y - y)));
		return Vec2(newX, newY);
	}

	void print2() //prints out x and y for 2D vectors
	{
		cout << x << ", " << y << endl;
	}
};

template<typename T>
class Vec3 //template class for 3D vectors
{
public:
	T x, y, z; //variables

	Vec3() //Default constructor
	{
		x, y, z = 0;
	}

	Vec3(T a, T b, T c) //Custom constructor
	{
		x = a;
		y = b;
		z = c;
	}

	Vec3 operator+(const Vec3 &other) //overload operator for addition
	{
		T newX = x + other.x;
		T newY = y + other.y;
		T newZ = z + other.z;
		return Vec3(newX, newY, newZ);
	}

	Vec3 operator-(const Vec3 &other) //overload operator for subtraction
	{
		T newX = x - other.x;
		T newY = y - other.y;
		T newZ = z - other.z;
		return Vec3(newX, newY, newZ);
	}

	Vec3 operator*(const Vec3 &other) //overload operator for multiplication
	{
		T newX = x * other.x;
		T newY = y * other.y;
		T newZ = z * other.z;
		return Vec3(newX, newY, newZ);
	}

	Vec3 operator/(const Vec3 &other) //overload operator for division (does 3D vector cross product)
	{
		T newX = (y * other.z) - (z * other.y);
		T newY = (z * other.x) - (x * other.z);
		T newZ = (x * other.y) - (y * other.x);
		return Vec3(newX, newY, newZ);
	}

	//float mag3 function. This function will compute the magnitude of 3D 
	//vectors
	double mag3()
	{
		return sqrtf(x * x + y * y + z * z);
	}

	//float nor3X, nor3Y, and nor3Z function(s). These functions will compute
	//the normalise of 3D vectors. The reason for 3 normalise functions, did
	//not work when put together
	double nor3X()
	{
		double nX = x / sqrtf(x * x + y * y + z * z);
		return nX;
	}

	double nor3Y()
	{
		double nY = y / sqrtf(x * x + y * y + z * z);
		return nY;
	}

	double nor3Z()
	{
		double nZ = z / sqrtf(x * x + y * y + z * z);
		return nZ;
	}

	//float dot3 function. This function will compute the dot product of 3D
	//vectors.
	double dot3()
	{
		double d3 = x + y + z;
		cout << d3 << endl;
		return d3;
	}

	//linear Interpolation 
	Vec3 operator%(const Vec3 &other)
	{
		T newX = (x + (.5*(other.x - x)));
		T newY = (y + (.5*(other.y - y)));
		T newZ = (z + (.5*(other.z - z)));
		return Vec3(newX, newY, newZ);
	}

	void print3() //prints out x, y and z for 3D vectors
	{
		cout << x << ", " << y << ", " << z << endl;
	}
};
template<typename T>
class Vec4
{
public:
	T R, G, B, A;

	Vec4()
	{
		R, G, B, A;
	}

	Vec4(T R, T G, T B, T A)
	{
		R = r;
		G = g;
		B = b;
		A = a;
	}

	void print4()
	{
		cout << r << "," << g << "," << b << "," << a << endl;
	}

	unsigned int r4H()
	{
		unsigned int rH = R >> 24;
		return rH;
	}

	unsigned int g4H()
	{
		unsigned int gH = (G >> 16) & 0x00FF;
		return gH;
	}

	unsigned int b4H()
	{
		unsigned int bH = (B >> 8) & 0x0000FF;
		return bH;
	}

	unsigned int a4H()
	{
		unsigned int aH = A & 0x000000FF;
		return aH;
	}
};