#pragma once
#include<iostream>
#include"DoubleList_Easy.h"
using namespace std;
template<class T>
class Que 
{
private:
	T[] arr;
	int top;
	int lowest;
	int size;
	const int  limit;
public:
	Que(T l);
	void push(T value);
	T pop();
	int nextIndex(int i);
	bool isEmpty();

};

template<class T>
Que<T>::Que(T l) {
	arr = new T[l]; 
	top = 0; 
	lowest = 0; 
	size = 0; 
	limit = l; };


template<class T>
void Que<T>::push(T value) {
	if (size == limit)
		cout << "栈已经满了，不能再加了" << endl;
	else {
		size++;
		arr[top] = value;
		top = nextIndex(top);
	}
}

template<class T>
T Que<T>::pop() {
	if (size == 0) {
		cout << "队列已经为空!!!" << endl;
		return -1;
	}
	else { 
		size--;
		T temp = arr[lowest];
		lowest = nextIndex(lowest);
		return temp;
	}
}


template<class T>
int Que<T>::nextIndex(int i) {
	return i < (limit - 1) ? i + 1 : 0;
}

template<class T>
bool Que<T>::isEmpty() {
	return size;
}