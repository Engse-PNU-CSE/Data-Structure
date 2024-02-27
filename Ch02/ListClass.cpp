class Collection {
    public:
    virtual bool Add(E, e) = 0;
    virtual bool AddAll(E, Collection e) = 0;
    void Clear();
    bool Contains(Object o);
    virtual bool ContainsAll(Collection c) = 0;
    bool Equals(Object o);
    bool IsEmpty();
    bool Remove(Object 0);
    virtual bool RemoveAll(Collection c) = 0;
    virtual bool RetainAll(Collection c) = 0;
    int Size();
    virtual Object[] ToArray() = 0;
};

class List : public Collection {
    public:
    virtual bool Add(int index, T e) = 0;
    virtual bool AddAll(int index, Collection c) = 0;
    T get(int index);
    bool Remove(int index);
    int LastIndexxof(Object o) = 0;
    List<t> SubList(int fromIndex, int toIndex) = 0;
};