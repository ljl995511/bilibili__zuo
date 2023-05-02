#include "List.h"

linkedList::linkedList()
{
	size = 0;
	head = nullptr;
}

linkedList::linkedList(const linkedList& rhs)
{
	this->size = rhs.size;
	head = new Node;
	Node* q = head;
	Node* p = rhs.head;;
	for (p = p->next; p;p=p->next) {
		q->next = new Node(p->value, p->next);
		q = q->next;
	}
}

linkedList::linkedList(int const a[], int n)
{
	size = n;
	head = new Node;
	Node* q = head;
	for (int i = 0; i < n; i++) {
		q->next = new Node(a[i], nullptr);
		q = q->next;
	}
}

linkedList::linkedList(int n, int value)
{
	size = n;
	head = new Node;
	Node* p = head;
	for (int i = 0; i < size; i++) {
		p->next = new Node(value, nullptr);
		p = p->next;
	}
}

linkedList::~linkedList()
{
	while (getSize()) {
		remove(1);
	}
	delete head;
}

void linkedList::insert(int pos, int value)
{
	Node* p = advance(pos-1);
	Node* q = new Node(value, p->next);
	p->next = q;
	size++;
}

void linkedList::remove(int pos)
{
	Node* p = advance(pos-1);
	Node* q = p->next;
	//if(q->next!=)
	p->next = q->next;
	delete q;
	--size;
}

int linkedList::at(int pos) const
{
	return advance(pos)->value;
}

void linkedList::modify(int pos, int newValue){
	advance(pos)->value = newValue;
}



bool linkedList::removeValue(int val)
{
	Node* Head = head->next;//����һ���ֲ�����Headָ�������ͷ�ڵ�,��Ϊ����ͷ�ڵ�ֻ��һ���㣬����ָ��head��next
	while (Head != nullptr){
		if (Head->value != val)
			break;
		head->next = Head->next;
		delete Head;
		size--;
		Head = head->next;//��Ϊ���øú�����������������������������ж�ͷ�ڵ��ǲ��ǵ��ڸ�ֵ
					//ʹ�ø�ѭ��ʹ��Headָ��һֱ�����ƶ���ֱ�������ڸ�ֵ�Ľڵ�λ��
					//�� 1  1 1 1 1 1 1 2 3 4 5 6 ���������Ҫɾ��1���ֵ
					//����Ҫָ��ָ��2��λ��
	}
	Node* pre = head->next;
	Node* cur = head->next;
	while (cur != nullptr)
	{
		if (cur->value == val) {
			pre->next = cur->next;
			delete cur;
			size--;
			cur = pre->next;
			continue;
		}
		pre = cur;
		cur = cur->next;
	}
	return true;
}

linkedList::Node* linkedList::advance(int pos) const
{
	Node* p = head;
	for (int i = 0; i < pos; ++i) p = p->next;
	return p;
}

int& linkedList::operator [](int pos)
{
	return advance(pos)->value;
	// TODO: �ڴ˴����� return ���
}

void linkedList::ReverseList_List()
{
	Node* pre = nullptr;//һ��ǰָ�룬һ����ָ�룬�ֱ�ץȡ
	Node* nex = nullptr;
	Node* now = head->next;//��Ϊͷ�ڵ㲻�洢ֵ��ֻ�洢��һ��ָ��ĵ�ַ�����ͷ�ڵ㲻���뷴ת
	while (now != nullptr) {
		nex = now->next;//nexץȡ��ǰ����Ԫ�ص���һ���ڵ�
		now->next = pre;//����ǰԪ�ص�nextָ�뷴ת
		pre = now;//��pre���ڵ�ǰ�ڵ㣬�Ա���һ��ָ��ķ�ת
		now = nex;//ʹ��ǰָ��������һ���ڵ���в���
	}
	head ->next = pre;//���ʹͷָ��ָ��ת����ĵ�һ���ڵ�
}

ostream& operator<<(ostream& os, const linkedList& list)
{
	linkedList::Node* index = list.head->next;
	while (index != nullptr) {
		os << index->value << endl;;
		index = index->next;
	}
	return os;
}
