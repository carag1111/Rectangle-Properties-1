#include <iostream>
#include <limits> //Require for numeric_limits

// Fuction decalrations (prototypes)
double getLength_Width(double& length, double& width);
double calcPerimeter(double length, double width);
double calcArea(double length, double width);
void displayProperties(double perimeter, double area);

int main() {
  //Main driver of the program. It repeatedly gets the length and width of a rectangle, calculates its perimeter and area, and displays the results until the user decides if they want another reclangle, and the loop continues until the user decides to stop.

std::cout << "Welcome to the Rectangle Properties Program!" << std::endl;

  while (true) {
//Get validated length and width
double length,width;
  if (getLength_Width(length, width) == -1) {
    break; //Exit if input is invalid or user decides to stop
  }

//Calculate perimeter and area
  double perimeter = calcPerimeter(length, width);
  double area = calcArea(length, width);

  //Display results
  displayProperties(perimeter, area);

//Ask if uder wants another rectangle
char repeat;
std::cout << "Would you like to calculate the properties of another rectangle? (y/n): ";
std::cin >> repeat;
repeat = tolower(repeat); //Convert to lowercase for easier comparison

if (repeat != 'y') {
  std::cout << "Thank you for using the Rectangle Properties Program!" << std::endl;
  break; //Exit loop if user does not want another rectangle
}
  }
std::cout << "Goodbye!" << std::endl;
return 0;
}

double getLength_Width(double& length, double& width) {
  //Promts the user to enter the length and width of a retangle and validates the input to ensure it is positive and numeric.

  while (true) {
    std::cout << "Enter the length of the rectangle (>0): ";
    std::cin >> length;

  // Input validation
    if (std::cin.fail() || length <= 0) {
      std::cout << "Invalid input. Length must be greater than 0." << std::endl;
      std::cin.clear(); //Clear the error flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Discard invalid input
      continue;
}
std::cout << "Enter the width of the rectangle (>0): ";
std::cin >> width;

//Input validation
if (std::cin.fail() || width <= 0) {
  std::cout << "Invalid input. Width must be greater than 0." << std::endl;
  std::cin.clear(); //Clear the error flag
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Discard invalid input
  continue;
}
return 0; //Indicates successful input
  }
}
double calcPerimeter(double length, double width) {
  //Calculates and returns the perimeter of a rectangle given its length and width.
  return 2 * (length + width);
  }

double calcArea(double length, double width) {
  //Calculates and returns the area of a rectangle given its length and width.
  return length * width;
}

void displayProperties(double perimeter, double area) {
  //Displays the perimeter and area of a rectangle.
  std::cout << "\nRectangle Properties:" << std::endl;
  std::cout << "Perimeter: " << perimeter << std::endl;
  std::cout << "Area: " << area << std::endl;
}

