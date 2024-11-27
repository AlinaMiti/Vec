#include "Vector.h"
#include <iostream>

template<class T>
class Matrix : public Vector<Vector<T>>{ //наследование от вектора
//поля все есть в Vector
public:
    Matrix(size_t n): Vector<Vector<T>>(n){ //n = количество векторов в матрице/ Вызвали конструктор родительского класса и создали массив векторов
        for(size_t i = 0; i < n; i++)
            _array[i] = Vector<T>(n-i, i);
    }
    Matrix(const Matrix& mt):Vector<Vector<T>>(mt) { }//констр копирования/ Вызвали из класса Вектор

    Matrix(const Vector<Vector<T>>& mt); //преобразование типа. Из вектора векторов в матрицу/ Также вызвать констр родительского класса

    Matrix& operator=(const Matrix& mt); //присваивание
    Matrix operator+(const Matrix& mt){
        return Vector<Vector<T>>::operator+(mt);  //вызываем оператор из родительского класса
    }
    Matrix operator-(const Matrix& mt){
        return Vector<Vector<T>>::operator-(mt);
    }
    Matrix operator*(const Matrix& mt); //как правильно воспользоваться стартИндексом

    //оператор ввода и вывода для отладки



};