#pragma once

//双向动态链表的简单实现，只有增加和删除
template<class T>
class DoubleList_To_Queue_And_Stack
{
public:
	struct Node {
		T value;
		Node* next;
		Node* last;
		Node(T data) { value = data; next = nullptr; last = nullptr; };
	};
private:
	Node* head;//设置头指针
	Node* tail;//设置尾指针
public:
	DoubleList_To_Queue_And_Stack() { head = nullptr; tail = nullptr; };
	void addFrom_Head(T value);
	void addFrom_Bottom(T value);
	T popFrom_Head();
	T popFrom_Bottom();
	~DoubleList_To_Queue_And_Stack() { while (head != nullptr) popFrom_Head(); };
};



//从头插入队列，头进尾出
template<class T>
void DoubleList_To_Queue_And_Stack<T>::addFrom_Head(T value) {
	Node* cur = new Node(value);
	if (head == nullptr) {
		head = cur;
		tail = cur;
	}
	else {
		cur->next = head;
		head->last = cur;
		head = cur;
	}
}



//从尾插入队列，尾进头出
template<class T>
void DoubleList_To_Queue_And_Stack<T>::addFrom_Bottom(T value) {
	Node* cur = new Node(value);
	if (head == nullptr)
	{
		head = cur;
		tail = cur;
	}
	else {
		tail->next = cur;
		cur->last = tail;
		tail = cur;
	}

}


//从头节点弹出
template<class T>
T DoubleList_To_Queue_And_Stack<T>::popFrom_Head() {
	/*if (head == nullptr)
		return nullptr;
	Node* temp = head;
	T val = new T(temp->value);
	if (head == tail)
		delete temp;
	else {
		head = head->next;
		delete temp
	}
	return T;*/
}


//从尾节点弹出
template<class T>
T DoubleList_To_Queue_And_Stack<T>::popFrom_Bottom() {
	/*if (head == nullptr)
		return -1;
	Node* temp = tail;
	T val = temp->value;
	if (head == tail)
		delete temp;
	else {
		tail=tail->last;
		delete temp
	}
	return T;*/
}