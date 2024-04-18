// Programmer: Erin Lee
// Student id: 1805820
// File: pShapes.h

#ifndef PSHAPES_H
#define PSHAPES_H

// c++ libraries
#include <string>
#include <vector>
using namespace std;

// c libraries
#include <cstdlib>   // atof

// struct variable as base class
struct Shape
{
  // pure virtual and destructor function
  virtual void output(ostream&) const = 0;
  virtual ~Shape(){}
};

// derived class Square inherits from Shape
class Square : public Shape
{
  // public constructor, assignment operator, and member function
  public:
  Square(const vector<string>&);
  Square& operator=(const Square&);
  void output(ostream&) const;

  // declare protected variable
  protected:
  const double length;
};

// derived class Rectangle inherits from Shape
class Rectangle : public Shape
{
  // public constructor, assignment operator, and member function
  public:
  Rectangle(const vector<string>&);
  Rectangle& operator=(const Rectangle&);
  void output(ostream&) const;

  // declare protected variables
  protected:
  const double length;
  const double width;
};

// derived class Circle inherits from Shape
class Circle : public Shape
{
  // public constructor, assignment operator, and member function
  public:
  Circle(const vector<string>&);
  Circle& operator=(const Circle&);
  void output(ostream&) const;

  // declare protected variable
  protected:
  const double radius;
};

// derived class Triangle inherits from Shape
class Triangle : public Shape
{
  // public constructor, assignment operator, and member function
  public:
  Triangle(const vector<string>&);
  Triangle& operator=(const Triangle&);
  void output(ostream&) const;

  // declare protected variable
  protected:
  const double length;
};

// derived class Cube inherits from Square
class Cube : public Square
{
  // public constructor, assignment operator, and member function
  // call constructor of Square base class
  public:
  Cube(const vector<string>& tokens) : Square(tokens){}
  Cube& operator=(const Cube&);
  void output(ostream&) const;
};

// derived class Box inherits from Rectangle
class Box : public Rectangle
{
  // public constructor, assignment operator, and member function
  // call constructor of Rectangle base class
  // initializes height
  public:
  Box(const vector<string>& tokens) : Rectangle(tokens), height(tokens.size() > 3 ? atof(tokens[3].c_str()) : 0) {}
  Box& operator=(const Box&);
  void output(ostream&) const;

  // declare protected variable
  protected:
  const double height;
};

// derived class Cylinder inherits from Circle
class Cylinder : public Circle
{
  // public constructor, assignment operator, and member function
  // call constructor of Circle base class
  // initializes height
  public:
  Cylinder(const vector<string>& tokens) : Circle(tokens), height(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) {}
  Cylinder& operator=(const Cylinder&);
  void output(ostream&) const;

  // declare protected variable
  protected:
  const double height;
};

// derived class Prism inherits from Triangle
class Prism : public Triangle
{
  // public constructor, assignment operator, and member function
  // call constructor of Triangle base class
  // initializes height
  public:
  Prism(const vector<string>& tokens) : Triangle(tokens), height(tokens.size() > 2 ? atof(tokens[2].c_str()) : 0) {}
  Prism& operator=(const Prism&);
  void output(ostream&) const;

  // declare protected variable
  protected:
  const double height;
};

// overloading operator
ostream& operator<<(ostream&, const Shape&);

#endif