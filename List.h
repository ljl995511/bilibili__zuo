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
    //Ĭ�Ϲ��캯��������һ���߼�Ϊ�յ�����
    linkedList();
    //�������캯��������һ���߼��������������ͬ������
    linkedList(const linkedList& rhs);
    //ԭ�����鹹�캯��������һ�����������������ͬ������
    linkedList(int const a[], int n);
    //��乹�캯��������һ������Ϊn��value������
    linkedList(int n, int value);
    //����������һ��Ҫ����ʵ�֣��������ڴ�й©
    ~linkedList();
    //�޻���˵
    int getSize()const { return size; }
    //��ɾ���
    void insert(int pos, int value);
    void remove(int pos);
    int at(int pos)const;
    void modify(int pos, int newValue);
    //void disp()const;

    //���ֲ��ҷ������������������Ƿ������ֵ��������ɾ��
    bool removeValue(int val);
private:
    //��������������ָ��λ�õĽڵ��ָ��
    Node* advance(int pos)const;
public:
    //��ֵ���������
    //linkedList& operator = (const linkedList& rhs);
   // linkedList& operator += (const linkedList& rhs);
    //���������������
    int& operator [] (int pos);
   // const int& operator [] (int pos)const;
    //int compareTo(const linkedList& rhs)const;
    friend ostream& operator <<(ostream& os,const linkedList& list);
    
    
    //������ķ�ת
    void ReverseList_List();
};


