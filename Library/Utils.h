#ifndef __UTILS_H__
#define __UTILS_H__

template <class T>
bool operator ==(T& t1, T& t2) {
    return t1 == t2;
}

template <class T>
class ConstVectorIt {
private:
    T* cur;
public:
    ConstVectorIt() {}
    ConstVectorIt(T* ob) :cur(ob) {}

    int operator !=(const ConstVectorIt&) const;
    int operator ==(const ConstVectorIt&) const;
     T& operator *();
     T* operator ->();
    ConstVectorIt& operator ++();
    ConstVectorIt operator ++(int);
};

template <class T>
class Vector
{
    friend class ConstVectorIt<T>;
    T* data;
    int size;
    int cap;
public:
    Vector(int = 1);
    Vector(Vector&);
    Vector operator=(const Vector&);
    bool operator==(const Vector&);
    int Capacity() const;
    int Size() const;
    typedef ConstVectorIt<T> const_iterator;
    const_iterator begin() const;
    const_iterator end() const;
    T& operator [](int);
    bool operator==(int);
    void push_back(T);
    void clear();
    void create(const int& i);
    void erase(int i);
    void resize(const int& n);
    ~Vector<T>(void);

};

template <class  T>
Vector<T>::Vector(int n)
{
    create(n);
}

template <class  T>
Vector<T>::~Vector(void)
{
    delete[] data;
}

template <class  T>
int Vector<T>::Size(void) const
{
    return size;
}
template <class T>
typename Vector<T>::const_iterator Vector<T>::begin() const {
    return ConstVectorIt<T>(&data[0]);
}
template <class T>
typename Vector<T>::const_iterator Vector<T>::end() const {
    return ConstVectorIt<T>(&data[size - 1]);
}
template <class  T>
T& Vector<T>::operator[](int i)
{
    return data[i];
}

template<class T>
bool Vector<T>::operator==(int)
{
    return false;
}

template <class T>
Vector<T> Vector<T>::operator=(const Vector& a)
{
    size = a.size;
    for (int i = 0; i != a.size; ++i) {
        this->data[i] = a.data[i];
    }
    return *this;
}

template <class T>
bool Vector<T>::operator==(const Vector& v)
{
    if (this->size == v.size)
    {
        for (int i = 0; i < this->size; i++)
        {
            if (this->data[i] != v.data[i])
                return false;
        }
        return true;
    }
    else {
        return  false;
    }
}

template <class T>
Vector<T>::Vector(Vector& a) {
    this->size = a.size;
    for (int i = 0; i != a.size; ++i) {
        this->data[i] = a.data[i];
    }
}

template <class T>
void Vector<T>::push_back(T val) {
    T* newdata;
    if (size > cap) {
        cap = cap * 2;
        newdata = new T[cap];
        for (int i = 0; i < size; i++)
            newdata[i] = data[i];
        delete[] data;
        data = newdata;
    }
    data[size] = val;
    size++;
}

template <class  T>
int Vector<T>::Capacity() const
{
    return cap;
}

template <class  T>
void Vector<T>::erase(int i)
{
    T* newdata = new T[cap];
    bool f = false;

    for (int j = 0; j < this->size; j++)
    {
        if (data[j] == data[i])
        {
            f = true;
        }
        if (f)
        {
            newdata[j - 1] = this->data[j];
        }
        else {
            newdata[j] = this->data[j];
        }
    }
    this->size -= 1;
    delete[] this->data;
    this->data = newdata;
}

template <class  T>
void Vector<T>::resize(const int& n)
{
    T* newdata = new T[n];
    this->cap = n;
    this->size = n > this->size ? this->size : n;
    for (int i = 0; i < this->size; i++)
    {
        newdata[i] = this->data[i];
    }
    delete[] this->data;
    this->data = newdata;
}


template <class  T>
void Vector<T>::clear()
{
    delete[] this->data;
    this->size = 0;
    this->cap = 1;
    this->data = new T[1];
}

template <class  T>
void Vector<T>::create(const int& i) {
    if (this->data)
        delete[] data;
    size = 0;
    cap = i;
    data = new T[i];
}
template<class T>
int ConstVectorIt<T>::operator !=(const ConstVectorIt& it) const {
    return cur != it.cur;
}
template <class T>
int ConstVectorIt<T>::operator ==(const ConstVectorIt<T>& it) const {
    return cur == it.cur;
}
template <class T>
 T& ConstVectorIt<T>::operator *() {
    return *cur;
}
template <class T>
 T* ConstVectorIt<T>::operator ->() {
    return &*cur;
}
template <class T>
ConstVectorIt<T>& ConstVectorIt<T>::operator ++() {
    ++cur;
    return *this;
}
template <class T>
ConstVectorIt<T> ConstVectorIt<T>::operator ++(int) {
    ConstVectorIt<T> res(*this);
    ++cur;
    return res;
}

#endif

