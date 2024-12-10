#pragma once
#include "Vector.h"
#include <iostream>

template<class T>
class Matrix : public Vector<Vector<T>>{ //наследование от вектора
//поля все есть в Vector
// using Vector<Vector<T>>::_array;
// using Vector<Vector<T>>::_size;
// using Vector<Vector<T>>::_startIndex;
public:
    Matrix(size_t n): Vector<Vector<T>>(n){ //n = количество векторов в матрице Вызвали конструктор родительского класса и создали массив векторов
        
        for(size_t i = 0; i < n; i++)
            this->_array[i] = Vector<T>(n, i);
    }
    Matrix(const Matrix& mt):Vector<Vector<T>>(mt) { }//констр копирования/ Вызвали из класса Вектор

    Matrix(const Vector<Vector<T>>& mt); //преобразование типа. Из вектора векторов в матрицу/ Также вызвать констр родительского класса

    Matrix& operator=(const Matrix& mt){
        this._size = mt._size;
        this._startIndex = mt._startIndex;
        for(size_t i = 0; i < this._size; i++){
            this->_array[i] = mt._array[i];
        }
    } //присваивание
    Matrix operator+(const Matrix& mt){
        Matrix<T> res(mt._size);
        for(size_t i = 0; i < mt._size; i++){
            res[i] = this->_array[i] + mt._array[i];
        }
        return res;
        //return Vector<Vector<T>>::operator+(mt);  //вызываем оператор из родительского класса
    }
    Matrix operator-(const Matrix& mt){
        return Vector<Vector<T>>::operator-(mt);
    }
    Matrix operator*(const Matrix& mt){
        Matrix res(this->_size);
        size_t size = this->_size;
        for(size_t i = 0; i < this->_size; i++){  //i-ый вектор(строка в матрице)
            //for(size_t j = 0; j < this->_size - this[i]._startIndex; j++){ //элемент вектора
            for(size_t j = 0; j < this->_size; j++){
                //for(size_t k = 0; k < this->_size - this[i]._startIndex; k++){
                for(size_t k = 0; k < j + 1; k++){
                    res[i][j] += this->_array[i][k] * mt._array[i + k][j - k];
                }
            }
        }
        return res;
    } //как правильно воспользоваться стартИндексом

    //    Matrix operator*(const Matrix& mt){
    //     Matrix res=Matrix(this->_size);
    //     size_t s=this->_size;
    //     for (size_t i=0;i<this->_size;i++){//строчки
    //         for (size_t j=0;j<s;j++){//столбцы
    //             for (size_t z=0;z<j+1;z++){
    //                 res[i][j]+=this->_array[i][z]*mt._array[i+z][j-z];

    //             }
                
    //         }
    //         s--;
    //     }
    //     return res;
    // }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matr){
        for(size_t i = 0; i < matr._size; i++){
            os << matr._array[i] << std::endl;
        }
        return os;
    }
    //оператор ввода и вывода для отладки



};