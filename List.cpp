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
	Node* Head = head->next;//设置一个局部变量Head指向链表的头节点,因为链表头节点只是一个点，所有指向head的next
	while (Head != nullptr){
		if (Head->value != val)
			break;
		head->next = Head->next;
		delete Head;
		size--;
		Head = head->next;//因为调用该函数的链表属于有序链表，因此首先判断头节点是不是等于该值
					//使用该循环使得Head指针一直往后移动，直到不等于该值的节点位置
					//如 1  1 1 1 1 1 1 2 3 4 5 6 链表中如果要删除1这个值
					//则需要指针指到2的位置
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
	// TODO: 在此处插入 return 语句
}

void linkedList::ReverseList_List()
{
	Node* pre = nullptr;//一个前指针，一个后指针，分别抓取
	Node* nex = nullptr;
	Node* now = head->next;//因为头节点不存储值，只存储下一个指针的地址，因此头节点不参与反转
	while (now != nullptr) {
		nex = now->next;//nex抓取当前操作元素的下一个节点
		now->next = pre;//将当前元素的next指针反转
		pre = now;//令pre等于当前节点，以便下一个指针的反转
		now = nex;//使当前指针跳向下一个节点进行操作
	}
	head ->next = pre;//最后使头指针指向反转链表的第一个节点
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
