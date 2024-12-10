#include <iostream>
#include "Matrix.h"
#include "Vector.h"

int main(){
    Vector<int> a = Vector<int>(3);
    for(size_t i = 0; i < 3; i++){
        a[i] = 3;
    }
    Vector<int> c = Vector<int>(3, 1);
    for(size_t i = 0; i < 2; i++){
        c[i] = 3;
    }
    Vector<int> d = Vector<int>(3, 2);
    for(size_t i = 0; i < 1; i++){
        d[i] = 3;
    }
    Matrix<int> M(3);
    M[0] = a;
    M[1] = c;
    M[2] = d;

    Matrix<int> M2 = M;


    //Vector<int> b = a+5;
    std::cout << M * M2;

    
   


    return 0;
}