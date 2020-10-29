#include <iostream>
#include <fstream>
#define MAX_SIZE 100

using namespace std;

template <class T>
class GenStack {
    
private:
    T stack[MAX_SIZE];
    int size;
public:
    
    GenStack()
    {
        size = 0;
    }
    
    void push(T item)
    {
        if(size < MAX_SIZE)
        {
            stack[size] = item;
            size++;
        }
    }
    
    T pop()
    {
        if(size > 0)
        {
            size--;
            return stack[size];
        }
    }
    
    bool isEmpty()
    {
        return (size == 0);
    }
};