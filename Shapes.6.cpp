// Programmer: Erin Lee
// Student id: 1805820
// File: Shapes.6.cpp

// c++ libraries
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#include "pShapes.h"

// function prototypes
void id();
vector<string> parseString(string);

int main()
{
  // function call for identification information
  id();

  // declare and initialize variables
  ifstream fin;     
  ofstream fout; 
  string line;
  vector<string> tokens;   
  vector<const Shape*> myBag;

  // open files
  fin.open("Shapes.input.txt");
  fout.open("Shapes.output.txt");

  // Check if input file is opened successfully
  if (!fin.good())
  {
    cout << "Input file failed to open." << endl;
    return 1;
  }
 
  // Check if output file is opened successfully
  if (!fout.good())
  {
    cout << "Output file failed to open." << endl;
    return 1;
  }

  // keep looping until end of file is reached
  while (!fin.eof())
  {
    // read each line from input file and call function to get tokens
    getline(fin, line);
    tokens = parseString(line);

    // will skip any empty lines from input file
    if (tokens.size() != 0)
    {
      // check if token is square
      if (tokens[0] == "SQUARE")
      {
        // dynamically allocate memory for a new square object using constructor 
        // store const read-only pointer object in bag
        // store 1 into different bag to represent square shape
        const Square* const s = new Square(tokens);
        myBag.push_back(s);
      }

      // check if token is rectangle
      else if (tokens[0] == "RECTANGLE")
      {
        // dynamically allocate memory for a new rectangle object using constructor 
        // store const read-only pointer object in bag
        // store 2 into different bag to represent rectangle shape
        const Rectangle* const r = new Rectangle(tokens);
        myBag.push_back(r);
      }

      // check if token is circle
      else if (tokens[0] == "CIRCLE")
      {
        // dynamically allocate memory for a new circle object using constructor 
        // store const read-only pointer object in bag
        // store 3 into different bag to represent circle shape
        const Circle* const c = new Circle(tokens);
        myBag.push_back(c);
      }

      // check if token is triangle
      else if (tokens[0] == "TRIANGLE")
      {
        // dynamically allocate memory for a new triangle object using constructor 
        // store const read-only pointer object in bag
        // store 4 into different bag to represent triangle shape
        const Triangle* const t = new Triangle(tokens);
        myBag.push_back(t);
      }

      // check if token is cube
      else if (tokens[0] == "CUBE")
      {
        // dynamically allocate memory for a new cube object using constructor 
        // store const read-only pointer object in bag
        // store 5 into different bag to represent cube shape
        const Cube* const c = new Cube(tokens);
        myBag.push_back(c);
      }

      // check if token is box           
      else if (tokens[0] == "BOX")
      {
        // dynamically allocate memory for a new box object using constructor 
        // store const read-only pointer object in bag
        // store 6 into different bag to represent box shape
        const Box* const b = new Box(tokens);
        myBag.push_back(b);
      }

      // check if token is cylinder      
      else if (tokens[0] == "CYLINDER")
      {
        // dynamically allocate memory for a new cylinder object using constructor 
        // store const read-only pointer object in bag
        // store 7 into different bag to represent cylinder shape
        const Cylinder* const c = new Cylinder(tokens);
        myBag.push_back(c);
      }

      // check if token is prism
      else if (tokens[0] == "PRISM")
      {
        // dynamically allocate memory for a new prism object using constructor 
        // store const read-only pointer object in bag
        // store 8 into different bag to represent prism shape
        const Prism* const p = new Prism(tokens);
        myBag.push_back(p);
      }

      // check if token is EOF      
      else if (tokens[0] == "EOF")
        break;

      // token does not match one of eight objects
      else
        cout << tokens[0] << " invalid object" << endl;
    }
  }

  // close input file
  fin.close();

  // keeps looping until all elements in bag have been output to console
  for (unsigned int i = 0; i < myBag.size(); i++)
  {
    cout << *myBag[i];
  }

  // keeps looping until all elements in bag have been output to file
  for (unsigned int i = 0; i < myBag.size(); i++)
  {
    fout << *myBag[i];
  }

  // keeps looping until all elements in bag have been deleted from memory
  for (unsigned int i = 0; i < myBag.size(); i++)
  {
    delete myBag[i]; 
  }

  // close output file
  fout.close();
}

// function will display identification information
void id()
{
  cout << "Programmer: Erin Lee" << endl;
  cout << "Programmer's ID: 1805820" << endl;
  cout << "File: " << __FILE__ << endl;
}

// function will take a string and create an array of tokens
vector<string> parseString(string str)
{
  stringstream s(str);
  istream_iterator<string> begin(s), end;
  return vector<string>(begin, end);
}

