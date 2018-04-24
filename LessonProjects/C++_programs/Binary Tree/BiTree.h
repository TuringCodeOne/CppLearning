#ifndef TREE_H
#define TREE_H


#include<iostream>
#include"Stack.h"
using namespace std;




/***         �����ඨ��           ***/
template<class T> class BiTree
{
public:
	Stack<T> S;

	/******              API�����ӿ�           *******/


	BiTree() { root = Creat(root); }								
	~BiTree() { Destroy(root); }
	void m_PreOrder() { PreOrder(root); }
	void m_InOrder() { InOrder(root); }
	void m_PostOrder() { PostOrder(root); }
	void m_leafcount() { cout << "������Ҷ����Ϊ��" << leafcount(root) << endl; }
	void m_hightree() { cout << "���������Ϊ��" << hightree(root) << endl; }
	void m_InNo_Order() { InNo_Order(root); }

private:
	BiNode<T> *root;
	BiNode<T> *Creat(BiNode<T> *bt);            //����
	void InNo_Order(BiNode<T> *bt);				//�ǵݹ�����
	void Destroy(BiNode<T> *bt);				//������
	void PreOrder(BiNode<T> *bt);				//ǰ��ݹ�
	void InOrder(BiNode<T> *bt);				//����ݹ�
	void PostOrder(BiNode<T> *bt);				//����ݹ�
	int leafcount(BiNode<T> *bt);				//Ҷ����
	int hightree(BiNode<T> *bt);				//���
};


template<class T> BiNode<T> *BiTree<T>::Creat(BiNode<T> *bt)
{
	T x;
	cin >> x;
	if (x == '#')
		bt = NULL;
	else
	{
		bt = new BiNode<T>;
		bt->data = x;
		bt->lchild = Creat(bt->lchild);
		bt->rchild = Creat(bt->rchild);
	}
	return bt;
}


template<class T> void BiTree<T>::Destroy(BiNode<T>* bt)
{
	if (bt != NULL)
	{
		Destroy(bt->lchild);
		Destroy(bt->rchild);
		delete bt;
	}
}


template<class T> void BiTree<T>::PreOrder(BiNode<T>* bt)
{
	if (bt != NULL) {
		cout << bt->data << " ";
		PreOrder(bt->lchild);
		PreOrder(bt->rchild);
	}
}


template<class T> void BiTree<T>::InOrder(BiNode<T>* bt)
{
	if (bt != NULL) {
		InOrder(bt->lchild);
		cout << bt->data << " ";
		InOrder(bt->rchild);
	}


}


template<class T> void BiTree<T>::PostOrder(BiNode<T>* bt)
{
	if (bt != NULL) {
		PostOrder(bt->lchild);
		PostOrder(bt->rchild);
		cout << bt->data << " ";
	}
}

template<class T> void BiTree<T>::InNo_Order(BiNode<T> *bt)
{
	BiNode<T> *p = bt;
	while (p || !S.isEmpty())
	{
		while (p)
		{
			S.Push(p);
			p = p->lchild;
		}
		S.Pop(&p);
		cout <<p->data<<" ";
		p = p->rchild;
	}
}

template<class T> int BiTree<T>::leafcount(BiNode<T> *bt)
{
	static int count = 0;
	if (bt != NULL)
	{
		if (bt->lchild == NULL && bt->rchild == NULL)
			count++;
		leafcount(bt->lchild);
		leafcount(bt->rchild);
	}
	return(count);
}

template<class T> int BiTree<T>::hightree(BiNode<T> *bt)
{
	int H, H1, H2;
	if (bt == NULL)
		H = 0;
	else {
		H1 = hightree(bt->lchild);
		H2 = hightree(bt->rchild);
		H = (H1 > H2 ? H1 : H2) + 1;
	}
	return H;
}





#endif
