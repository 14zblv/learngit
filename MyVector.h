#ifndef __MYVECTOR__
#define __MYVECTOR__

#include <iostream>
#include <cassert>

using namespace std;

template<typename T>
class MyVector{
public:
    MyVector(int cap):_size(0),_capacity(cap){
	_data = new T[_capacity];
    }

    MyVector():MyVector(10){}

    ~MyVector(){
        delete[] _data;
    }

    void push_back(T e){
        if(_size == _capacity)
	    resize(2*_capacity);
	_data[_size++] = e;
    }

    T pop_back(){
	assert(_size > 0);
	T ret = _data[--_size];
	if(_size == _capacity/4)
	    resize(_capacity/2);
	return ret;
    }
    int size(){ return _size; }
    int capacity(){ return _capacity; }
private:
    T* _data;
    int _capacity;
    int _size;
    
    void resize(int newCapacity){
        assert(newCapacity >= _size);
	T *newData = new T[newCapacity];
	for(int i = 0; i < _size; i++)
	    newData[i] = _data[i];
	delete[] _data;
	_data = newData;
	_capacity = newCapacity;
    }
};


#endif //__MYVECTOR__
