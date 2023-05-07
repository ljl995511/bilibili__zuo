#pragma once
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

struct Tree_node {
	int val;
	Tree_node* left;
	Tree_node* right;
};

/*�����������������*/
void creat_Tree(Tree_node*& root)
{
	int x;
	cin >> x;
	if (x == 0)root = nullptr;
	else {
		root = new Tree_node;
		root->val = x;
		creat_Tree(root->left);
		creat_Tree(root->right);
	}
}

/*���������һ���ж��ٽڵ�*/
int total_Tree(Tree_node* root)
{
	if (!root)
		return 0;
	else {
		return total_Tree(root->left) + total_Tree(root->right) + 1;
	}
}

//�������
void Ino_Traversal(const Tree_node* root)
{
	if (!root)
		return;
	else {
		Ino_Traversal(root->left);
		cout << root->val;
		Ino_Traversal(root->right);
	}
}

//�������
/*
* ����һ�������жԶ��������в������
* 1.���Ƚ���һ��ĸ��ڵ������
* 2.ֻҪ���в�Ϊ��һֱѭ��
* 3.
*/
void levelOrderBottom_(Tree_node* root, queue<Tree_node*>& que) {
	if (!root)
		return;
	que.push(root);
	while (!que.empty())
	{
		int size = que.size();
		cout << "�� " << (int)log2(size) + 1 << "�� �� ";
		for (int i = 0; i < size; i++) {
			Tree_node* p = que.front();
			cout << p->val; que.pop();
			if (p->left)
				que.push(p->left);
			if (p->right)
				que.push(p->right);
		}
		cout << endl;
	}
}

/*�����������¶��ϣ����Ҷ���Ĳ������
* �������������϶��£��������ҵı�����֪�����¶��ϣ��������ҵı����������Ĳ�������ķ�����
* ���ǵ����϶��µı�����ͨ��һ�������γɣ���˷�����ı���Ӧ��ͨ��һ������+һ��ջ��ʵ��
* ��������Ԫ�س��ӵ�ջ��Ȼ�������γ�ջ��ʵ���˶����������¶��ϣ������������
*/
void levelOrderBottom(Tree_node* root)
{
	if (!root) return;
	else {
		queue<Tree_node*>que;
		stack<Tree_node*>sta;
		que.push(root);
		while (!que.empty())
		{
			Tree_node* p = que.front(); que.pop();
			sta.push(p);
			if (p->left)
				que.push(p->left);
			if (p->right)
				que.push(p->right);
		}
		while (!sta.empty()) {
			cout << sta.top()->val;
			sta.pop();
		}
	}

}

//int main()
//{
//	Tree_node* MyStree = nullptr;
//	creat_Tree(MyStree);
//	cout << "���������������";
//	Ino_Traversal(MyStree);
//	cout << "���������������" << endl;
//	stack<Tree_node*> sta;
//	levelOrderBottom(MyStree);
//	cout << endl << "�ܽڵ�����" << total_Tree(MyStree) << endl;
//}