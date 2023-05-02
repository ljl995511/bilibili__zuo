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
	//Ĭ�Ϲ��캯��
	DoubleList() { size = 0; head = nullptr; }
	//���ƹ��캯��������һ������������һ��������
	DoubleList(int const index[], int n );
	//���ƹ��캯��������һ������һ��˫����һ��������
	DoubleList(const DoubleList& rhs);
	//��乹�캯��������һ������Ϊn��ÿ���ڵ�ֵΪvalue������
	DoubleList(int n, int value);
	//��������
	~DoubleList();
	//���������ȵĺ���
	int getSize();
	//��������ĳ��ָ��ĺ���
	DoubleNode* advance(int pos)const;
	//������ĳ��Ӷ���
	void insert(int pos,int value);
	//������Ӷ�����ͷ�巨��
	void insert_head(int value);
	//����������Ӷ�����β�巨��
	void insert_end(int value);
	//ɾ��������ĳ���ڵ�ĺ���
	void remove(int pos);
	//����ĳ���ڵ��ֵ
	int at(int pos)const;
	//�ı�������ĳ���ڵ��ֵ
	void modify(int pos, int newValue);
	//���ڵ��е�����ֵչʾ����
	void disp()const;

	//˫����ķ�ת
	void ReverseList_Double();



};

