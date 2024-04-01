// C++ Program to Find Area of Rectangle
#include <iostream>
using namespace std;

int main(){
    int length, breadth, area;
    
    // Asking for input
    cout << "Enter the length of the rectangle: ";
    cin >> length;
    cout << "Enter the breadth of the rectangle: ";
    cin >> breadth;
    
    // Calculating area
    area = length * breadth;
    
    // Display output
    cout << "Area of Rectangle: " << area << endl ; 
    return 0;
}
