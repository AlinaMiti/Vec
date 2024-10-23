#include "iostream"

template <class T>
class Vector{
protected:     
    T* _array;
    size_t _size;
    size_t _startIndex; //первый индекс с которого начинается вектор
public:
    //дефолт констр не нужен
    Vector(size_t size, size_t startIndex);  //выделение памяти. Контроль стартИндекса. Размер ненулевой
    Vector(const Vector& tmp);
    Vector(Vector&& moved); //констуктор перемещения. РАЗОБРАТЬСЯ
    ~Vector(); //удалить память. занулить указатель

    size_t GetSize() const{
        return _size;
    }
    size_t GetStartIndex() const{
        return _startIndex;
    }

    T& At(size_t pos);  //реализуем контроль доступа к элементам. Чтобы не ушло за рамки массива
    T& operator[](size_t pos);  //просто выводим

    Vector& operator=(const Vector& tmp);

    Vector operator+(const T& tmp); //со скаляром
    Vector operator-(const T& tmp);
    Vector operator*(const T& tmp);

    Vector operator+(const Vector& tmp); //вектор на вектор
    Vector operator-(const Vector& tmp);

    T operator* (const Vector* tmp); //скалярное пр
    
    //операторы ввода и вывода
};