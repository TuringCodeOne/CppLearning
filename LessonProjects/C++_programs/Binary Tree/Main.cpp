#include"BiTree.h"
#include<iostream>
using namespace std;

int main()
{
	cout << "������������";
	BiTree<char> *bitree = new BiTree<char>;  // ����һ�ö�����
	cout << "���������";
	bitree->m_PreOrder();                             // ǰ�����
	cout << endl;
	cout << "���������";
	bitree->m_InOrder();                              // �������
	cout << endl;
	cout << "���������";
	bitree->m_PostOrder();                            // �������
	cout << endl;
	bitree->m_leafcount();       //Ҷ����
	bitree->m_hightree();        //���
	cout << "����ǵݹ������";     
	bitree->m_InNo_Order();      //�ǵݹ��������
	cout << endl;           
	system("pause");
	return 0;
}