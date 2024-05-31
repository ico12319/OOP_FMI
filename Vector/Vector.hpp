#include <iostream>

template<class T>
class Vector{
    
private:
    T* data;
    size_t size;
    size_t capacity;
    
    void resize(size_t newCap);
    void move(Vector&& other);
    void copy(const Vector& other);
    void destroy();
    
public:
    Vector();
    Vector(const Vector<T>& other);
    Vector(Vector<T>&& other);
    Vector& operator=(const Vector<T>& other);
    Vector& operator=(Vector<T>&& other);
    ~Vector();
    
    void pushBack(const T& object);
    void popBack();
    void insert(size_t index,const T& obj);
    void remove(size_t index);
    size_t count() const;
    bool isEmpty() const;
    T& back() const;
    const T& operator[](size_t index) const;
    void clear();
    void print() const;
};

template<class T>
Vector<T>::Vector(){
    this->capacity = 8;
    this->data = new T[this->capacity];
    this->size = 0;
}

template<class T>
Vector<T>::Vector(const Vector& other){
    copy(other);
}

template<class T>
Vector<T>::Vector(Vector&& other){
    move(std::move(other));
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other){
    if(this!=&other){
        destroy();
        copy(other);
    }
    return *this;
}


template<class T>
void Vector<T>::copy(const Vector<T>& other){
    this->data = new T[other.capacity];
    for(int i = 0;i<other.size;i++)
        this->data[i] = other.data[i];
    this->size = other.size;
    this->capacity  = other.capacity;
}


template<class T>
void Vector<T>::move(Vector<T>&& other){
    this->data = other.data;
    other.data = nullptr;
    this->size = other.size;
    this->capacity = other.capacity;
    other.size = other.capacity = 0;
}

template<class T>
void Vector<T>::destroy(){
    delete[]data;
    data = nullptr;
}

template<class T>
Vector<T>::~Vector(){
    destroy();
}

template<class T>
void Vector<T>::resize(size_t newCap){
    T* tempArrr = new T[newCap];
    for(int i = 0;i<size;i++)
        tempArrr[i] = data[i];
    delete[]data;
    data = tempArrr;
    capacity = newCap;
}


template<class T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other){
    if(this!=&other){
        destroy();
        move(std::move(other));
    }
    return *this;
}

template<class T>
void Vector<T>::pushBack(const T& obj){
    if(size == capacity)
        resize(capacity * 2);
    data[size] = obj;
    size++;
}

template<class T>
void Vector<T>::popBack(){
    if(!isEmpty())
        size--;
}

template<class T>
void Vector<T>::remove(size_t index){
    if(index > size)
        throw std::invalid_argument("Out of bounds!");
    
    for(int i = index;i<size - 1;i++){
        data[i] = data[i+1];
    }
    
    size--;
}

template<class T>
size_t Vector<T>::count() const{
    return size;
}

template<class T>
bool Vector<T>::isEmpty() const{
    return (size == 0);
}

template<class T>
T& Vector<T>::back() const{
    if(!isEmpty())
        return data[size - 1];
}

template<class T>
const T& Vector<T>::operator[](size_t index) const{
    if(index > size)
        throw std::invalid_argument("Out of bounds");
    return data[index];
}

template<class T>
void Vector<T>::clear(){
    size = 0;
}

template<class T>
void Vector<T>::insert(size_t index, const T& obj){
    for (int i = size; i > index; i--){
        data[i] = data[i - 1];
    }
    data[index] = obj;
    size++;
    
}


template<class T>
void Vector<T>::print() const{
    for(int i = 0;i<size;i++)
        std::cout<<data[i]<<" ";
    std::cout<<std::endl;
}
