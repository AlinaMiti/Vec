#include <iostream>
#include "Matrix.h"
#include "Vector.h"

int main(){
    Vector<int> a = Vector<int>(5, 2);
    a[0] = 0;
    a[1] = 0;
    for(size_t i = 2; i < 5; i++){
        a[i] = 3;
    }
    
   


    return 0;
}