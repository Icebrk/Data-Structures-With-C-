#include <iostream>
using namespace std;

// Define Object as a double
typedef double Object;

// Standard swap function.
void my_swap(Object &lhs, Object &rhs){
    Object tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

// swap function template.
// Object: must have a copy constructor and operator=
template <class Object>
void swap_custom(Object &lhs, Object &rhs){
    Object tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

int main(){
    int x = 5;
    int y = 7;
    double a = 2;
    double b = 4;

    cout << "Before swap" << endl;
    cout << x << " " << y << endl;
    cout << a << " " << b << endl;

    my_swap(a, b); // Uses already instantiated my_swap with int
    swap_custom(x, y); // Instantiates swap_custom with double

    cout << "After swap" << endl;
    // Print the values after swap
    cout << x << " " << y << endl;
    cout << a << " " << b << endl;

    // swap (x, b); // Illegal: no match

    return 0;
}
