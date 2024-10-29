#include <iostream>

template <class T>
class Vector{
protected:     
    T* _array;
    size_t _size;
    size_t _startIndex; //первый индекс с которого начинается вектор
public:
    //дефолт констр не нужен
    Vector(size_t size, size_t startIndex): _size(size), _startIndex(startIndex) {
        if (size == 0) {
            throw "Problems";
        }
        if (startIndex >= size) {
            throw "Start index huita";
        }
        _array = new T[size]; 
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
    } //констуктор перемещения. РАЗОБРАТЬСЯ

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

    T& At(size_t pos);  //реализуем контроль доступа к элементам. Чтобы не ушло за рамки массива
    T& operator[](size_t pos);  //просто выводим

    Vector& operator=(const Vector& tmp);
//со скаляром
    Vector operator+(const T& tmp){
        for(size_t i = _startIndex; i < _size; i++){
            _array[i] += tmp;
        }
    }
    Vector operator-(const T& tmp){
        for(size_t i = _startIndex; i < _size; i++){
            _array[i] -= tmp;
        }
    }
    Vector operator*(const T& tmp){
        for(size_t i = _startIndex; i < _size; i++){
            _array[i] *= tmp;
        }
    }

//вектор на вектор
    Vector operator+(const Vector& tmp){
        if(_size != tmp._size)
            throw "size ne rawno";
        if(_startIndex > tmp._startIndex)
            size_t index = _startIndex;
        else size_t index = tmp._startIndex;

        for(size_t i = index; i < _size; i++)
            _array[i] += tmp[i];
    }
    Vector operator-(const Vector& tmp){
        if(_size != tmp._size)
            throw "size ne rawno";
        if(_startIndex > tmp._startIndex)
            size_t index = _startIndex;
        else size_t index = tmp._startIndex;

        for(size_t i = index; i < _size; i++)
            _array[i] -= tmp[i];
    }

    T operator* (const Vector* tmp){ //скалярное пр
        if(_size != tmp._size)
            throw "size ne rawno";
        if(_startIndex > tmp._startIndex)
            size_t index = _startIndex;
        else size_t index = tmp._startIndex;

        T res = 0;

        for(size_t i = index; i < _size; i++){
            res += _array[i] * tmp[i];
        }

        return res;
    }
    
    //операторы ввода и вывода
};