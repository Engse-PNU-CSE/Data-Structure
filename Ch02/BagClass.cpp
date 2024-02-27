#include <iostream>
#include <memory>
#include <iostream>

using namespace std;

#define MaxSize 100

template <class T>
class Bag
{
public:
    Bag(int bagCapacity = 10);
    ~Bag();
    bool IsFull();
    int Size() const;
    bool IsEmpty() const;
    virtual T &Pop() const;
    virtual void Push(const T &);

private:
    T *array;
    int capacity;
    int top;
};

template <class T>
Bag<T>::~Bag() {
    delete[] array;
}

template <class T>
Bag<T>::Bag(int bagCapacity) : capacity {
    if(capacity < 1) throw "New length must be >=0";
    array = new T[capacity];
    top = -1;
}

template <class T>
void ChangeSizeID(T*& a, const int oldSize, const int newSize) {
    if(newSize < 0) throw "New length must be >=0";
    T* temp = new T[newSize];
    int number = oldSize;

    if(oldSize > newSize) number = newSize;

    memcpy(temp, a, number);
    delete[] a;
    a = temp;
}

template <class T>
int Bag<T>::Size() const {
    return top + 1;
}

template <class T>
bool Bag<T>::IsEmpty() const {
    return top < 0;
}

template <class T>
void Bag<T>::Push(const T& x) {
    if(top == capacity - 1) {
        ChangeSizeID(array, capacity, 2*capacity);
        capacity *=2;
    }
    array[++top] = x;
}

template <class T>
T& Bag<T>::Pop() const {
    T retValue;

    if(IsEmpty()) throw "Bag is empty, cannot delete";
    int deletePos = top/2;
    retValue = array[deletePos];

    memcpy(array + deletePos, array + deletePos, top + 1);
    top--;
    return retValue;
}

template <class T>
inline bool Bag<T>::IsFull() {
    if(top == MaxSize -1) return true;
    else return false;
}

int main() {
    Bag<int> b(4);
    
    b.Push(3);
    b.Push(2);
    b.Push(5);
    b.Push(6);

    if(b.IsEmpty()) cout<<"Empty"<<endl;
    else cout<<"not Empty"<<endl;

    while(!b.IsEmpty()) {
 //       cout<<b<<endl;
        b.Pop();
    }
    system("pause");
    return 0;
}
