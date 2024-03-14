#include <iostream>
#include <unistd.h>

typeofdef double Object;

// Standard swap routing.
void swap(Object &lhs,Object rhs){
    Object tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}
