﻿#include <iostream>
using namespace std;

enum Color
{
	Black	= 0x00000000,
	White	= 0x00FFFFFF,
	Red		= 0x000000FF,
	Green	= 0x0000FF00,
	Blue	= 0x00FF0000,
	Yellow	= 0x0000FFFF,
	Orange	= 0x0000A5FF
};

class Shape
{
private:
	Color color;

public:
	Shape(Color color) : color(color) {}
	virtual double get_area() const = 0;
	virtual double get_perimeter() const = 0;
	virtual void draw() const = 0;
	virtual void info() const
	{
		cout << "Площадь фигуры: " << get_area() << endl;
		cout << "Периметр фигуры: " << get_perimeter() << endl;
		draw();
	}
};

class Square : public Shape
{
private:
	double side;
public:
	Square(double side, Color color) : Shape(color)
	{
		set_side(side);
	}
	double get_side() const
	{
		return side;
	}
	void set_side(double side)
	{
		this->side = side;
	}
	double get_area() const override
	{
		return side * side;
	}
	double get_perimeter() const override
	{
		return side * 4;
	}
	void draw() const override
	{
		for (int i = 0; i < side; ++i)
		{
			for (int j = 0; j < side; ++j)
			{
				cout << "* ";
			}
			cout << endl;
		}
		cout << endl;
	}
	void info() const override
	{
		cout << typeid(*this).name() << endl;
		cout << "Длина стороны квадрата: " << get_side() << endl;
		Shape::info();
	}
};

int main()
{
	setlocale(LC_ALL, "");

	Square square(5, Color::Red);

	cout << "Длина стороны квадрата: " << square.get_side() << endl;
	cout << "Площадь квадрата: " << square.get_area() << endl;
	cout << "Периметр квадрата: " << square.get_perimeter() << endl;
	square.draw();

	cout << "\n-------------------------\n";
	square.info();

	return 0;
}