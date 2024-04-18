// Programmer: Erin Lee
// Student id: 1805820
// File: pShapes.cpp

// c++ libraries
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// c libraries
#include <cmath>     // sqrt and M_PI

#include "pShapes.h"

// function will round numbers to two decimal digits
ostream& roundingTwo(ostream& out)
{
  out.setf(ios::fixed);
  out.precision(2);
  return out;
}

// function will turn off rounding back to default
ostream& roundingOff(ostream& out)
{
  out.unsetf(ios::fixed);
  out.precision(6);
  return out;
}

// Square class implementation
// initializes length of square
Square::Square(const vector<string>& tokens) : length(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) {}

// member function will perform calculations for square and display results 
void Square::output(ostream& out) const
{
  // calculate area and perimeter
  double area = length * length;
  double perimeter = 4 * length;

  // display results to console or file
  out << "SQUARE side=" << length;
  out << roundingTwo << " area=" << area << " perimeter=" << perimeter << roundingOff << endl;
}

// assignment operator for square class
Square& Square::operator=(const Square& copyThis)
{
  // declare reference variable to host object
  Square& host = *this;
  
  // check if host is not same as parameter
  // if not, remove const factor from host dimensions and assign to parameter dimensions
  if (this!= &copyThis)
    const_cast<double&>(host.length) = copyThis.length;

  // return reference variable
  return host;
}

// Rectangle class implementation
// initializes length and width of rectangle
Rectangle::Rectangle(const vector<string>& tokens) : length(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0),
                                                     width(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) {}

// member function will perform calculations for rectangle and display results 
void Rectangle::output(ostream& out) const
{ 
  // calculate area and perimeter
  double area = length * width;
  double perimeter = 2 * (length + width);

  // display results to console or file
  out << "RECTANGLE length=" << length << " width=" << width;
  out << roundingTwo << " area=" << area << " perimeter=" << perimeter << roundingOff << endl;
}

// assignment operator for rectangle class
Rectangle& Rectangle::operator=(const Rectangle& copyThis)
{
  // declare reference variable to host object
  Rectangle& host = *this;

  // check if host is not same as parameter
  // if not, remove const factor from host dimensions and assign to parameter dimensions
  if (this != &copyThis)
  {
    const_cast<double&>(host.length) = copyThis.length;
    const_cast<double&>(host.width) = copyThis.width;
  }
  
  // return reference variable
  return host;
}

// Circle class implementation
// initializes radius of circle
Circle::Circle(const vector<string>& tokens) : radius(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) {}

// member function will perform calculations for circle and display results 
void Circle::output(ostream& out) const
{        
  // calculate area and perimeter
  double area = M_PI * radius * radius;
  double perimeter = 2 * M_PI * radius;

  // display results to console or file
  out << "CIRCLE radius=" << radius;
  out << roundingTwo << " area=" << area << " perimeter=" << perimeter << roundingOff << endl;
}

// assignment operator for circle class
Circle& Circle::operator = (const Circle& copyThis) 
{
  // declare reference variable to host object
  Circle& host = *this;

  // check if host is not same as parameter
  // if not, remove const factor from host dimensions and assign to parameter dimensions
  if (this != &copyThis) 
    const_cast<double&>(host.radius) = copyThis.radius;
  
  // return reference variable
  return host;
}

// Triangle class implementation
// initializes length of triangle
Triangle::Triangle(const vector<string>& tokens) : length(tokens.size() > 1 ? atof(tokens[1].c_str()) : 0) {}

// member function will perform calculations for triangle and display results 
void Triangle::output(ostream& out) const
{        
  // calculate area and perimeter
  double area = (sqrt(3) / 4) * length * length;
  double perimeter = 3 * length;

  // display results to console or file
  out << "TRIANGLE side=" << length;
  out << roundingTwo << " area=" << area << " perimeter=" << perimeter << roundingOff << endl;
}

// assignment operator for triangle class
Triangle& Triangle::operator = (const Triangle& copyThis) 
{
  // declare reference variable to host object
  Triangle& host = *this;

  // check if host is not same as parameter
  // if not, remove const factor from host dimensions and assign to parameter dimensions
  if (this != &copyThis)
    const_cast<double&>(host.length) = copyThis.length;  
  
  // return reference variable
  return host;
}

// member function will perform calculations for cube and display results 
void Cube::output(ostream& out) const
{
  // calculate surface area and volume
  double area = 6 * length * length;
  double volume = length * length * length;

  // display results to console or file
  out << "CUBE side=" << length;
  out << roundingTwo << " surface area=" << area << " volume=" << volume << roundingOff << endl;
}

// assignment operator for cube class
Cube& Cube::operator = (const Cube& copyThis) 
{
  // declare reference variable to host object
  Cube& host = *this;

  // check if host is not same as parameter
  // if not, remove const factor from host dimensions and assign to parameter dimension
  if (this != &copyThis) 
    const_cast<double&>(host.length) = copyThis.length;

  // return reference variable
  return host;
}

// member function will perform calculations for box and display results 
void Box::output(ostream& out) const
{
  // calculate surface area and volume
  double area = 2 * ((length * width) + (width * height) + (length * height));
  double volume = length * width * height;

  // display results to console or file
  out << "BOX length=" << length << " width=" << width << " height=" << height;
  out << roundingTwo << " surface area=" << area << " volume=" << volume << roundingOff << endl;
}

// assignment operator for box class
Box& Box::operator = (const Box& copyThis) 
{
  // declare reference variable to host object
  Box& host = *this;

  // check if host is not same as parameter
  // if not, remove const factor from host dimensions and assign to parameter dimension
  if (this != &copyThis) 
    {
      const_cast<double&>(host.length) = copyThis.length;
      const_cast<double&>(host.width) = copyThis.width;
      const_cast<double&>(host.height) = copyThis.height;
    }

  // return reference variable
  return host;
}

// member function will perform calculations for cylinder and display results 
void Cylinder::output(ostream& out) const
{
  // calculate surface area and volume
  double area = (2 * M_PI * radius * radius) + (2 * M_PI * radius * height);
  double volume = M_PI * radius * radius * height;

  // display results to console or file
  out << "CYLINDER radius=" << radius << " height=" << height;
  out << roundingTwo << " surface area=" << area << " volume=" << volume << roundingOff << endl;
}

// assignment operator for cylinder class
Cylinder& Cylinder::operator = (const Cylinder& copyThis) 
{
  // declare reference variable to host object
  Cylinder& host = *this;

  // check if host is not same as parameter
  // if not, remove const factor from host dimensions and assign to parameter dimensions
  if (this != &copyThis) 
  {
    const_cast<double&>(host.radius) = copyThis.radius;
    const_cast<double&>(host.height) = copyThis.height;
  }

  // return reference variable
  return host;
}

// member function will perform calculations for prism and display results 
void Prism::output(ostream& out) const
{
  // calculate surface area and volume
  double area = ((sqrt(3) / 2) * length * length) + (3 * length * height);
  double volume = (sqrt(3) / 4) * length * length * height;

  // display results to console or file
  out << "PRISM side=" << length << " height=" << height;
  out << roundingTwo << " surface area=" << area << " volume=" << volume << roundingOff << endl;
}

// assignment operator for prism class
Prism& Prism::operator = (const Prism& copyThis) 
{
  // declare reference variable to host object
  Prism& host = *this;
  
  // check if host is not same as parameter
  // if not, remove const factor from host dimensions and assign to parameter dimensions
  if (this != &copyThis) 
  {
    const_cast<double&>(host.length) = copyThis.length;
    const_cast<double&>(host.height) = copyThis.height;
  }

  // return reference variable
  return host;
}

// overloading operator displays Shape objects
ostream& operator<<(ostream& out, const Shape& s)
{
  s.output(out);
  return out;
}