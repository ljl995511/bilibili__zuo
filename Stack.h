#pragma once
#include<iostream>
using namespace std;

template<class T>
class Stack
{
private:
	T* stk;//表示栈的数组
	int MAXN;//该栈的最大容量，一旦设置不可更改
	int TOP;//现在栈里面有多少容量
public:
	Stack(int vol);
	~Stack();
	bool isEmpty();
	bool isFull();
	int size();
	T topStack();
	bool pop();
	bool push(T index);
};

template<class T>
Stack<T>::Stack(int vol) {
	MAXN = vol;
	TOP = -1;
	stk = new T[MAXN];
}

template<class T>
Stack<T>::~Stack() {
	delete stk;
	MAXN = 0;
	TOP = -1;
}

template<class T>
bool Stack<T>::isEmpty() {
	return TOP == -1;
}

template<class T>
bool Stack<T>::isFull() {
	return TOP == (MAXN - 1);
}

template<class T>
int Stack<T>::size() {
	return TOP+1;
}

template<class T>
T Stack<T>::topStack() {
	if (isEmpty()) return -1;
	return stk[TOP];
}

template<class T>
bool Stack<T>::pop() {
	if (isEmpty()) {
		cout << "栈已经空了" << endl;
		return false;
	}
	else {
		cout << "已经弹出栈顶的 ： \"" << stk[TOP--] << " \"元素" << endl;
	}
}

template<class T>
bool Stack<T>::push(T index) {
	if (isFull()) {
		cout << "栈已经满了！！！" << endl;
		return false;
	}
	else {
		stk[++TOP] = index;
		cout << "元素\"" << index << "\"已经成功入栈" << endl;
		return true;
	}
}