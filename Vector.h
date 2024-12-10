#pragma once
#include <iostream>

template <class T>
class Vector{
protected:     
    T* _array;
    size_t _size;
    size_t _startIndex; //первый индекс с которого начинается вектор
public:
    //дефолт констр не нужен
    Vector(size_t size = 10){
        _size = size;
        _startIndex = 0;
        _array = new T[_size];
    }
    Vector(size_t size, size_t startIndex) {
        _size = size;
        _startIndex = startIndex;
        if (size == 0) {
            throw "Problems";
        }
        if (startIndex >= size) {
            throw "Start index";
        }
        _array = new T[_size]; 
        for (int i = 0; i < size; i++){
            _array[i] = 0;
        }
    }  //выделение памяти. Контроль стартИндекса. Размер ненулевой
    Vector(const Vector& tmp): _size(tmp._size), _startIndex(tmp._startIndex) {
        _array = new T[_size]; 
        for (size_t i = 0; i < _size; ++i) {
            _array[i] = tmp._array[i]; 
        }
    }
    Vector(Vector&& moved){
        _array = moved._array;
        _size = moved._size;
        _startIndex = moved._startIndex;
        moved._array = nullptr; 
        moved._size = 0;
        moved._startIndex = 0;
    } //констуктор перемещения. 

    ~Vector(){ //удалить память. занулить указатель
        delete [] _array; 
        _array = nullptr;
    }

    size_t GetSize() const{
        return _size;
    }
    size_t GetStartIndex() const{
        return _startIndex;
    }

    T& At(size_t pos){
        if (pos >= _size){
            throw "error1";
        }
        return _array[pos];
    }  //реализуем контроль доступа к элементам. Чтобы не ушло за рамки массива
    T& operator[](size_t pos){  //просто выводим
        return _array[pos];
    }

    Vector& operator=(const Vector& tmp){
        if (_size != tmp._size){
            delete [] _array;
            _array = new T[tmp._size];
        }
        _size = tmp._size;
        _startIndex = tmp._startIndex;
        for(size_t i = 0; i < _size; i++){
            _array[i] = tmp._array[i];
        }
        return *this;
    }
//со скаляром
    Vector operator+(const T& tmp){
        Vector result(*this);
        for (size_t i = 0; i < _size; ++i) {
            result._array[i] += tmp;
        }
        return result;
    }
    Vector operator-(const T& tmp){
        Vector result(*this);
        for (size_t i = 0; i < _size; ++i) {
            result._array[i] -= tmp;
        }
        return result;
    }
    Vector operator*(const T& tmp){
        Vector result(*this);
        for (size_t i = 0; i < _size; i++) {
            result._array[i] *= tmp;
        }
        return result;
    }

//вектор на вектор
    Vector operator+(const Vector& tmp){
        if (_size != tmp._size) 
            throw "Error";
        Vector<T> result = Vector<T>(_size, _startIndex);
        for (size_t i = 0; i < _size; ++i) {
            result._array[i] = _array[i] + tmp._array[i];
        }
        return result;

    }
    Vector operator-(const Vector& tmp){
        if (_size != tmp._size) 
            throw "Error";
        Vector<T> result = Vector<T>(_size, _startIndex);
        for (size_t i = 0; i < _size; ++i) {
            result._array[i] = _array[i] - tmp._array[i];
        }
        return result;
    }

    T operator* (const Vector* tmp){ //скалярное пр
        if (_size != tmp._size) 
            throw "Error";
        T res = 0;
        for (size_t i = _startIndex; i < _size; ++i) {
            res += _array[i] * tmp._array[i];
        }
        return res;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector& vect){
        os << "(";
        for(int i = 0; i < vect._size; i++){
            if(vect._startIndex > i)
                os << 0 << ", ";
            else{
                os << vect._array[i - vect._startIndex];
            if(i + 1 != vect._size + vect.GetStartIndex())
                os << ", ";
            }
        }
        os << ")";
        return os;
    }
    
    //операторы ввода и вывода
};