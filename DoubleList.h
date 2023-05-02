#pragma once
class DoubleList
{
public:
	struct DoubleNode {
		int value;
		DoubleNode* next;
		DoubleNode* last;
		DoubleNode(int data = 0, DoubleNode* nex = nullptr, DoubleNode* la = nullptr) :value(data), next(nex), last(la) {};
	};
private:
	int size;
	DoubleNode* head;
public:
	//默认构造函数
	DoubleList() { size = 0; head = nullptr; }
	//复制构造函数，创建一个和数组内容一样的链表
	DoubleList(int const index[], int n );
	//复制构造函数，创建一个和另一个双链表一样的链表
	DoubleList(const DoubleList& rhs);
	//填充构造函数，创建一个长度为n，每个节点值为value的链表
	DoubleList(int n, int value);
	//析构函数
	~DoubleList();
	//返回链表长度的函数
	int getSize();
	//返回链表某点指针的函数
	DoubleNode* advance(int pos)const;
	//往链表某点加东西
	void insert(int pos,int value);
	//往链表加东西（头插法）
	void insert_head(int value);
	//往链表里面加东西（尾插法）
	void insert_end(int value);
	//删除链表中某个节点的函数
	void remove(int pos);
	//返回某个节点的值
	int at(int pos)const;
	//改变链表中某个节点的值
	void modify(int pos, int newValue);
	//将节点中的所有值展示出来
	void disp()const;

	//双链表的反转
	void ReverseList_Double();



};

