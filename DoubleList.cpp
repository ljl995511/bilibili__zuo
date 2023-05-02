#include "DoubleList.h"
#include<iostream>
using namespace std;

DoubleList::DoubleList(int const index[], int n)
{
	size = n;
	head = new DoubleNode;
	DoubleNode* now = head;
	//now->last = nullptr;
	for (int i = 0; i < n; i++){
		now->next = new DoubleNode(index[i], nullptr, now);
		now = now->next;
	}
}

DoubleList::DoubleList(const DoubleList& rhs)
{
	size = 0;
	head = new DoubleNode;
	DoubleNode* index = rhs.head->next;
	DoubleNode* result = head;
	while(index!=nullptr){
		result->next = new DoubleNode(index->value, nullptr, result);
		index = index->next;
		result = result->next;
		size++;
	}
}

DoubleList::DoubleList(int n, int value)
{
	size = 0;
	head = new DoubleNode;
	DoubleNode* index = head;
	for (int i = 0; i < n; i++) {
		index->next = new DoubleNode(value, nullptr, index);
		index = index->next;
		size++;
	}
}

DoubleList::~DoubleList()
{
	//DoubleNode* index = head;
	while (getSize()) {
		remove(1);
	}
	delete head;
}

int DoubleList::getSize()
{
	return size;
}

DoubleList::DoubleNode* DoubleList::advance(int pos)const
{
	DoubleNode* index = head;
	for (int i = 0; i < pos; i++) index = index->next;
	return index;
}

void DoubleList::insert(int pos, int value)
{
	DoubleNode* index = advance(pos);//定位到插入点
	DoubleNode* NewNode = new DoubleNode(value, index, index->last);//创建一个新的Node，前驱为插入点的前驱，后继为插入点
	index->last = NewNode;//改变插入点的前驱
	NewNode->last->next = NewNode;//改变插入点前的那个点的后继
	size++;
	
}

void DoubleList::insert_head(int value)
{
	DoubleNode* NewNode = new DoubleNode(value, head->next, head);
	head->next = NewNode;
	size++;
}

void DoubleList::insert_end(int value)
{
	DoubleNode* end = advance(size);
	DoubleNode* NewNode = new DoubleNode(value, nullptr, end);
	end->next = NewNode;
	size++;
}

void DoubleList::remove(int pos)
{
	DoubleNode* index = advance(pos);//advance函数返回的是目标节点
	DoubleNode* las = index->last;//las 指针指向应该删除的节点的前一节点
	las->next = index->next;
	if (index->next != nullptr) {
		index->next->last = las;
	}
	cout << size << " 号元素  : " << index->value << "已经删除 " << endl;
	delete index;
	size--;
}

int DoubleList::at(int pos) const
{
	DoubleNode* index = advance(pos);
	return index->value;
}

void DoubleList::modify(int pos, int newValue)
{
	DoubleNode* index = advance(pos);
	index->value = newValue;
}

void DoubleList::disp() const
{
	DoubleNode* index = head->next;
	while (index != nullptr) {
		cout << "该元素为： " << index->value << endl;
		index = index->next;
	}
}

void DoubleList::ReverseList_Double()
{
	DoubleNode* pre = nullptr;//设置一个前指针，指向正在操作的元素的前一个元素
	DoubleNode* nex = nullptr;//设置一个后指针，指向正在操作的元素的后一个元素
	DoubleNode* now = head->next;//设置now指针指向当前在操作的元素
	while (now != nullptr) {
		nex = now->next;//nex指针抓取当前正在操作的元素的后一个
		now->next = pre;//改变当前正在操作的元素的next指针，使其指向前一个
		now->last = nex;//改变当前正在操作的元素的last指针，使其指向后一个，实现后变前，前变后
		pre = now;//使前指针指向当前元素
		now = nex;//使当前指针跳向下一个元素，进而操作下一个元素
	}
	pre->last = head;//变换之后，使反转后的链表的第一个节点的前指针指向头节点
	head->next=pre;//使头节点的next指向变换后的链表的第一个节点，因为头节点不存储值
}
