#pragma once
#include<iostream>
#include"DoubleList_Easy.h"
using namespace std;

template<class T>
class Stack_Double 
{
private:
	DoubleList_To_Queue_And_Stack<T> Stack_1;
public:
	Stack_Double(int max) :MAX(max) {};
	bool Add_Head(T value);
	T pop_Head();
	int size;
	int MAX;
	int getMax();
	int getSize();
	bool isEmpty();
};

template<class T>
bool Stack_Double<T>::Add_Head(T value) 
{
	if (size == max) {
		cout << "栈已经满了！！ " << endl;
		return false;
	}
	else {
		Stack_1.addFrom_Head(value);
		size++;
		return true;
	}
}

template<class T>
T Stack_Double<T>::pop_Head() {
	if (size == 0) {
		cout << "栈已经空了！！ " << endl;
		return -1;
	}
	else {
		size--;
		return Stack_1.popFrom_Head();
	}
}

template<class T>
int Stack_Double<T>::getMax()
{
	return MAX;
}


template<class T>
int Stack_Double<T>::getSize()
{
	return size;
}


template<class T>
bool Stack_Double<T>::isEmpty()
{
	return size;
};


