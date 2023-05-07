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

/*中序遍历创建二叉树*/
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

/*中序遍历看一共有多少节点*/
int total_Tree(Tree_node* root)
{
	if (!root)
		return 0;
	else {
		return total_Tree(root->left) + total_Tree(root->right) + 1;
	}
}

//中序遍历
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

//层序遍历
/*
* 利用一个链队列对二叉树进行层序遍历
* 1.首先将第一层的根节点入队列
* 2.只要队列不为空一直循环
* 3.
*/
void levelOrderBottom_(Tree_node* root, queue<Tree_node*>& que) {
	if (!root)
		return;
	que.push(root);
	while (!que.empty())
	{
		int size = que.size();
		cout << "第 " << (int)log2(size) + 1 << "层 ： ";
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

/*二叉树的自下而上，自右而左的层序遍历
* 根据以往的自上而下，自左向右的遍历可知：自下而上，自左向右的遍历是以往的层序遍历的反方向
* 考虑到自上而下的遍历是通过一个队列形成，因此反方向的遍历应该通过一个队列+一个栈来实现
* 将队列中元素出队到栈，然后再依次出栈就实现了二叉树的自下而上，自右向左遍历
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
//	cout << "中序遍历二叉树：";
//	Ino_Traversal(MyStree);
//	cout << "层序遍历二叉树：" << endl;
//	stack<Tree_node*> sta;
//	levelOrderBottom(MyStree);
//	cout << endl << "总节点数：" << total_Tree(MyStree) << endl;
//}