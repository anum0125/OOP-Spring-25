#include <iostream>
#include <cmath>
using namespace std;

class Shape 
{
    protected:
        string color;
        int borderThickness;
    public:
        Shape(string c, int b) : color(c), borderThickness(b) {}
        
        virtual void draw() = 0;  
        virtual double calculateArea() = 0;
        virtual double calculatePerimeter() = 0;
        
        virtual ~Shape() {}  
};


class Circle : public Shape
{
    private:
        double radius;
    public:
        Circle(double r, string c, int b) : Shape(c, b), radius(r) {}

        void draw() override 
        {
            cout << "Drawing Circle of radius " << radius << " and color " << color << endl;
        }

        double calculateArea() override 
        {
            return M_PI * radius * radius;
        }

        double calculatePerimeter()  override 
        {
            return 2 * M_PI * radius;
        }
};


class Rectangle : public Shape 
{
    private:
        double width, height;
    public:
        Rectangle(double w, double h, string c, int b) : Shape(c, b), width(w), height(h) {}

        void draw() override 
        {
            cout << "Drawing Rectangle of width " << width << " and height " << height << endl;
        }

        double calculateArea() override 
        {
            return width * height;
        }

        double calculatePerimeter() override 
        {
            return 2 * (width + height);
        }
};


class Triangle : public Shape 
{
    private:
        double a, b, c;  
    public:
        Triangle(double s1, double s2, double s3, string c, int b) : Shape(c, b), a(s1), b(s2), c(s3) {}

        void draw() override 
        {
            cout << "Drawing Triangle with sides " << a << ", " << b << ", and " << c << endl;
        }

        double calculateArea() override 
        {
            double s = (a + b + c) / 2;
            return sqrt(s * (s - a) * (s - b) * (s - c)); 
        }

        double calculatePerimeter()  override 
        {
            return a + b + c;
        }
};

int main() {
    Shape* shapes[] = 
    {
        new Circle(5, "red", 1),
        new Rectangle(4, 6, "blue", 2),
        new Triangle(3, 4, 5, "green", 1)
    };

    int size = sizeof(shapes) / sizeof(shapes[0]);  

    for (int i = 0; i < size; i++) 
    {
        Shape* shape = shapes[i]; 

        shape->draw();
        cout << "Area: " << shape->calculateArea() << endl;
        cout << "Perimeter: " << shape->calculatePerimeter() << endl;
        cout << "---------------------" << endl;

        delete shape;  
    }

    return 0;
}
