#pragma once
#include "Vector.h"
#include <iostream>

template<class T>
class Matrix : public Vector<Vector<T>>{ //наследование от вектора
//поля все есть в Vector
using Vector<Vector<T>>::_array;
using Vector<Vector<T>>::_size;
using Vector<Vector<T>>::_startIndex;
public:
    Matrix(size_t n): Vector<Vector<T>>(n){ //n = количество векторов в матрице/ Вызвали конструктор родительского класса и создали массив векторов
        for(size_t i = 0; i < n; i++)
            _array[i] = Vector<T>(n-i, i);
    }
    Matrix(const Matrix& mt):Vector<Vector<T>>(mt) { }//констр копирования/ Вызвали из класса Вектор

    Matrix(const Vector<Vector<T>>& mt); //преобразование типа. Из вектора векторов в матрицу/ Также вызвать констр родительского класса

    Matrix& operator=(const Matrix& mt){
        _size = mt._size;
        _startIndex = mt._startIndex;
        for(size_t i = 0; i < _size; i++){
            _array[i] = mt._array[i];
        }
    } //присваивание
    Matrix operator+(const Matrix& mt){
        return Vector<Vector<T>>::operator+(mt);  //вызываем оператор из родительского класса
    }
    Matrix operator-(const Matrix& mt){
        return Vector<Vector<T>>::operator-(mt);
    }
    Matrix operator*(const Matrix& mt){
        Matrix res(_size);
        for (size_t i = 0; i < _size; i++){
            for (size_t j = 0; j < _size; j++){
                for (size_t k = 0; k < _size; k++){
                    res._array[i][j] += _array[i][k] * mt._array[k][j];
                }
            }
        }
        return res;
    } //как правильно воспользоваться стартИндексом

    
    //оператор ввода и вывода для отладки



};