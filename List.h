#pragma once
#include<iostream>
using namespace std;

class linkedList{
public:
	struct Node {
		int value;
		Node* next;
		Node(int data = 0, Node* node = nullptr) :value(data), next(node) {};
	};
private:
	int size;
	Node* head;
public:
    //默认构造函数，构造一个逻辑为空的链表
    linkedList();
    //拷贝构造函数，构造一个逻辑上与参数内容相同的链表
    linkedList(const linkedList& rhs);
    //原生数组构造函数，构造一个内容与给定数组相同的链表
    linkedList(int const a[], int n);
    //填充构造函数，构造一个内容为n个value的链表
    linkedList(int n, int value);
    //析构函数，一定要自行实现，否则有内存泄漏
    ~linkedList();
    //无话可说
    int getSize()const { return size; }
    //增删查改
    void insert(int pos, int value);
    void remove(int pos);
    int at(int pos)const;
    void modify(int pos, int newValue);
    //void disp()const;

    //二分查找法，查找有序链表中是否有这个值，并将其删除
    bool removeValue(int val);
private:
    //辅助函数，返回指定位置的节点的指针
    Node* advance(int pos)const;
public:
    //赋值运算符重载
    //linkedList& operator = (const linkedList& rhs);
   // linkedList& operator += (const linkedList& rhs);
    //方括号运算符重载
    int& operator [] (int pos);
   // const int& operator [] (int pos)const;
    //int compareTo(const linkedList& rhs)const;
    friend ostream& operator <<(ostream& os,const linkedList& list);
    
    
    //单链表的反转
    void ReverseList_List();
};


