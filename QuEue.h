#pragma once
#include<iostream>
using namespace std;
//这是队列结构
template<class T>
class QuEue
{
public:
	struct Q {
		T value;
		Q* next;
		Q(T val=0, Q* q=nullptr) { value = val; next = q };
	};
private:
	Q* que_front;
	Q* que_back;
	int size;
public:
	QuEue() { que_front = new Q; que_back = new Q; size = 0; };
	T front();//返回队列中排在最前面的对象的引用
	T back();//返回队列中排在最后面的对象的引用
	bool push(const T& obj);//尾插法入队列
	bool pop();//从最前面出队列
	int geiSize();//返回队列的长度
	bool isEmpty();//返回队列是否为空
	~QuEue();
};

template<class T>
T QuEue<T>::front() {
	return que_front->value;
}

template<class T>
T QuEue<T>::back() {
	return que_back->value;
}

template<class T>
bool QuEue<T>::push(const T& obj) {
	if (isEmpty()) {
		que_front = que_back = new Q(obj);
		size++;
		return true;
	}
	else {
		Q* temp = new Q(obj,nullptr);
		que_back->next = temp;
		que_back = temp;
		size++;
		return true;
	}
}

template<class T>
bool QuEue<T>::pop() {
	if (isEmpty()) {
		cout << "已经全部弹出!!" <<endl;
			return false;
	}
	Q* temp = que_front;
	que_front = que_front->next;
	delete temp;
	size--;
	return true;
}

template<class T>
int QuEue<T>::geiSize() {
	return size;
}

template<class T>
bool QuEue<T>::isEmpty()
{
	if (size == 0)
		return true;
	else return false;
}

template<class T>
QuEue<T>::~QuEue()
{
	while (!isEmpty())
		pop();
}
