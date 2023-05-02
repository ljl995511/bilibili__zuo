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
	DoubleNode* index = advance(pos);//��λ�������
	DoubleNode* NewNode = new DoubleNode(value, index, index->last);//����һ���µ�Node��ǰ��Ϊ������ǰ�������Ϊ�����
	index->last = NewNode;//�ı������ǰ��
	NewNode->last->next = NewNode;//�ı�����ǰ���Ǹ���ĺ��
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
	DoubleNode* index = advance(pos);//advance�������ص���Ŀ��ڵ�
	DoubleNode* las = index->last;//las ָ��ָ��Ӧ��ɾ���Ľڵ��ǰһ�ڵ�
	las->next = index->next;
	if (index->next != nullptr) {
		index->next->last = las;
	}
	cout << size << " ��Ԫ��  : " << index->value << "�Ѿ�ɾ�� " << endl;
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
		cout << "��Ԫ��Ϊ�� " << index->value << endl;
		index = index->next;
	}
}

void DoubleList::ReverseList_Double()
{
	DoubleNode* pre = nullptr;//����һ��ǰָ�룬ָ�����ڲ�����Ԫ�ص�ǰһ��Ԫ��
	DoubleNode* nex = nullptr;//����һ����ָ�룬ָ�����ڲ�����Ԫ�صĺ�һ��Ԫ��
	DoubleNode* now = head->next;//����nowָ��ָ��ǰ�ڲ�����Ԫ��
	while (now != nullptr) {
		nex = now->next;//nexָ��ץȡ��ǰ���ڲ�����Ԫ�صĺ�һ��
		now->next = pre;//�ı䵱ǰ���ڲ�����Ԫ�ص�nextָ�룬ʹ��ָ��ǰһ��
		now->last = nex;//�ı䵱ǰ���ڲ�����Ԫ�ص�lastָ�룬ʹ��ָ���һ����ʵ�ֺ��ǰ��ǰ���
		pre = now;//ʹǰָ��ָ��ǰԪ��
		now = nex;//ʹ��ǰָ��������һ��Ԫ�أ�����������һ��Ԫ��
	}
	pre->last = head;//�任֮��ʹ��ת�������ĵ�һ���ڵ��ǰָ��ָ��ͷ�ڵ�
	head->next=pre;//ʹͷ�ڵ��nextָ��任�������ĵ�һ���ڵ㣬��Ϊͷ�ڵ㲻�洢ֵ
}
