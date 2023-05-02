#pragma once
#include<iostream>
#include"DoubleList_Stack.h"

//以两个栈实现求目前栈中最小值
template<class T>
class Two_Stack
{
private:
	Stack_Double<T> myStack;
	Stack_Double<T> minStack;
public:
	Two_Stack(){}
};

