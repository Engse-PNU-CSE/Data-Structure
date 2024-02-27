#include <string>

using namespace std;

template <typename T>

class ArrayList : public List {
    T* data;
    int capacity;
    int length;

    public:
    ArrayList() {}
    ArrayList(int bufferSize = 10) {}
    ~ArrayList() {}
    int Size() {}
    T& Get(int index) {}
    int IndexOf(T value) {}
    T& operator [](int index) {}
    void Set(int index, T value) {}

    bool Add(T value, 'E') {}
    bool Add(int index, T value) {}
    bool AddAll(int index, ArrayList c) {}
    bool Remove(T value) {}
    T Remove(int index) {}
    void Clear() {}
    bool Contains(T value) {}
};