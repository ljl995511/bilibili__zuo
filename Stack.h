#pragma once
#include<iostream>
using namespace std;

template<class T>
class Stack
{
private:
	T* stk;//��ʾջ������
	int MAXN;//��ջ�����������һ�����ò��ɸ���
	int TOP;//����ջ�����ж�������
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
		cout << "ջ�Ѿ�����" << endl;
		return false;
	}
	else {
		cout << "�Ѿ�����ջ���� �� \"" << stk[TOP--] << " \"Ԫ��" << endl;
	}
}

template<class T>
bool Stack<T>::push(T index) {
	if (isFull()) {
		cout << "ջ�Ѿ����ˣ�����" << endl;
		return false;
	}
	else {
		stk[++TOP] = index;
		cout << "Ԫ��\"" << index << "\"�Ѿ��ɹ���ջ" << endl;
		return true;
	}
}