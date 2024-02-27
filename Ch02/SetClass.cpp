#include <iostream>
#include <memory>
#include <iostream>

using namespace std;

#define MaxSize 100

template <class T>
class Set
{
public:
    Set(int bagCapacity = 10);
    ~Set();
    bool IsFull();
    int Size() const;
    bool IsEmpty;
    virtual T &Pop() const;
    virtual void Push(const T &);

private:
    T data[MaxSize];
    int capacity;
    int top;
};
