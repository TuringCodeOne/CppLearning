#include"BiTree.h"
#include<iostream>
using namespace std;

int main()
{
	cout << "建立二叉树：";
	BiTree<char> *bitree = new BiTree<char>;  // 创建一棵二叉树
	cout << "先序遍历：";
	bitree->m_PreOrder();                             // 前序遍历
	cout << endl;
	cout << "中序遍历：";
	bitree->m_InOrder();                              // 中序遍历
	cout << endl;
	cout << "后序遍历：";
	bitree->m_PostOrder();                            // 后序遍历
	cout << endl;
	bitree->m_leafcount();       //叶子数
	bitree->m_hightree();        //深度
	cout << "中序非递归遍历：";     
	bitree->m_InNo_Order();      //非递归中序遍历
	cout << endl;           
	system("pause");
	return 0;
}