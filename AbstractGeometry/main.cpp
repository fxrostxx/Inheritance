#include <iostream>
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

const double PI = 3.14;

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
	Square(double side = 0, Color color = Color::Black) : Shape(color)
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
	virtual double get_area() const override
	{
		return side * side;
	}
	virtual double get_perimeter() const override
	{
		return side * 4;
	}

	virtual void draw() const override
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
	 virtual void info() const override
	{
		cout << typeid(*this).name() << endl;
		cout << "Длина стороны квадрата: " << get_side() << endl;
		Shape::info();
	}
};

class Cube : public Square
{
public:
	Cube(double side, Color color) : Square(side, color) {};

	double get_area() const override
	{
		return Square::get_area() * 6;
	}
	double get_perimeter() const override
	{
		return Square::get_perimeter() * 3;
	}
	double get_volume() const
	{
		return Square::get_area() * get_side();
	}

	void draw() const override
	{
		cout << endl;
	}
	void info() const override
	{
		Square::info();
		cout << "Объем куба: " << get_volume() << endl;
	}
};

class Rectangle : public Shape
{
private:
	double height;
	double width;

public:
	Rectangle(double height, double width, Color color) : Shape(color), height(height), width(width) {}

	void set_height(double height)
	{
		this->height = height;
	}
	double get_height() const
	{
		return height;
	}
	void set_width(double width)
	{
		this->width = width;
	}
	double get_width() const
	{
		return width;
	}
	virtual double get_area() const override
	{
		return height * width;
	}
	virtual double get_perimeter() const override
	{
		return (2 * height) + (2 * width);
	}

	virtual void draw() const override
	{
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				cout << "* ";
			}
			cout << endl;
		}
		cout << endl;
	}
	virtual void info() const override
	{
		cout << typeid(*this).name() << endl;
		cout << "Высота прямоугольника: " << get_height() << endl;
		cout << "Ширина прямоугольника: " << get_width() << endl;
		Shape::info();
	}
};

class Parallelepiped : public Rectangle
{
private:
	double length;

public:
	Parallelepiped(double height, double width, double length, Color color)
		: Rectangle(height, width, color), length(length) {}

	void set_length(double length)
	{
		this->length = length;
	}
	double get_length() const
	{
		return length;
	}
	double get_area() const override
	{
		return 2 * (get_height() * get_width() + get_height() * length + get_width() * length);
	}
	double get_perimeter() const override
	{
		return 4 * (get_height() + get_width() + length);
	}
	double get_volume() const
	{
		return Rectangle::get_area() * length;
	}

	void draw() const override
	{
		cout << endl;
	}
	void info() const override
	{
		Rectangle::info();
		cout << "Длина параллелепипеда: " << length << endl;
		cout << "Объем параллелепипеда: " << get_volume() << endl;
	}
};

class Triangle : public Shape
{
private:
	double side1;
	double side2;
	double side3;

public:
	Triangle(double side1, double side2, double side3, Color color) : Shape(color)
	{
		if (side1 + side2 > side3 && side2 + side3 > side1 && side1 + side3 > side2)
		{
			set_side1(side1);
			set_side2(side2);
			set_side3(side3);
		}
		else
		{
			set_side1(0);
			set_side2(0);
			set_side3(0);
		}
	}

	void set_side1(double side1)
	{
		this->side1 = side1;
	}
	double get_side1() const
	{
		return side1;
	}
	void set_side2(double side2)
	{
		this->side2 = side2;
	}
	double get_side2() const
	{
		return side2;
	}
	void set_side3(double side3)
	{
		this->side3 = side3;
	}
	double get_side3() const
	{
		return side3;
	}
	double get_area() const override
	{
		double halfperimeter = get_perimeter() / 2;
		return sqrt(halfperimeter * (halfperimeter - side1) * (halfperimeter - side2) * (halfperimeter - side3));
	}
	double get_perimeter() const override
	{
		return side1 + side2 + side3;
	}

	void draw() const override
	{
		cout << endl;
	}
	void info() const override
	{
		cout << typeid(*this).name() << endl;
		cout << "Длина 1 стороны треугольника: " << get_side1() << endl;
		cout << "Длина 2 стороны треугольника: " << get_side2() << endl;
		cout << "Длина 3 стороны треугольника: " << get_side3() << endl;
		Shape::info();
	}
};

class Circle : public Shape
{
private:
	double radius;

public:
	Circle(double radius, Color color) : Shape(color), radius(radius) {}

	void set_radius(double radius)
	{
		this->radius = radius;
	}
	double get_radius() const
	{
		return radius;
	}
	virtual double get_area() const override
	{
		return PI * radius * radius;
	}
	virtual double get_perimeter() const override
	{
		return 2 * PI * radius;
	}

	virtual void draw() const override
	{
		cout << endl;
	}
	virtual void info() const override
	{
		cout << typeid(*this).name() << endl;
		cout << "Радиус круга: " << get_radius() << endl;
		Shape::info();
	}
};

class Sphere : public Circle
{
public:
	Sphere(double radius, Color color) : Circle(radius, color) {}

	double get_area() const override
	{
		double perimeter = Circle::get_perimeter();
		return perimeter * perimeter / PI;
	}
	double get_perimeter() const override
	{
		return Circle::get_perimeter(); // Длина экватора
	}
	double get_volume() const
	{
		return 4 * PI * get_radius() * get_radius() * get_radius() / 3;
	}

	void draw() const override
	{
		cout << endl;
	}
	void info() const override
	{
		Circle::info();
		cout << "Объем шара: " << get_volume() << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "");

	Square square(5, Color::Red);
	square.info();

	Cube cube(5, Color::Orange);
	cube.info();

	Rectangle rectangle(5, 10, Color::Blue);
	rectangle.info();

	Parallelepiped parallelepiped(5, 10, 6, Color::Red);
	parallelepiped.info();

	Triangle triangle(5, 8, 10, Color::Black);
	triangle.info();

	Circle circle(10, Color::Green);
	circle.info();

	Sphere sphere(10, Color::Yellow);
	sphere.info();

	return 0;
}