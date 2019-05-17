#ifndef MYLIST_H
#define MYLIST_H

template <typename T>
class mylist
{
private:
    T* item;
    mylist<T>* next;
    mylist<T>* prev;
public:
    mylist();
    ~mylist();

    bool empty;

    T get(); const
    void set(T);

    T* next(); const
    T* prev(); const
    void push_back();
    void push_next();
    void pop();
    T* top(); const

    milist* operator =(milist<T>* current); const
    T* operator =(T* currentItem); const
};

#endif
