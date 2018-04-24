#ifndef STACK_LINK
#define STACK_LINK


/**          ���Ľڵ�  BiNode  ģ�嶨��        **/
template<typename T> struct BiNode
{
	T data;
	BiNode<T> *lchild, *rchild;
};


/**          ��ջ�ڵ�  LinkNode  ģ�嶨��        **/
template<typename T> struct LinkNode
{
	BiNode<T> *data;
	LinkNode<T> *next;
};


/**           ջ���ඨ��                    **/
template<class T> class Stack
{
public:
	Stack() :top(NULL) {}
	~Stack();
	void Push( BiNode<T>*x);          //��ջ
	void Pop(BiNode<T>**x);           //��ջ
	bool isEmpty();                   //�ж�ջ��
private:
	LinkNode<T> *top;                  //ջ��ָ��


};

template<class T> Stack<T>::~Stack()
{
	LinkNode<T> *ptr = NULL;
	while (top != NULL)     //ѭ���ͷ�ջ�ڵ�ռ�  
	{
		ptr = top->next;
		delete top;
		top = ptr;
	}
}

template<class T> void Stack<T>::Push(BiNode<T>*x)
{
	LinkNode<T> *ptr = new LinkNode<T>;
	ptr->data = x;
	ptr->next = top;
	top = ptr;
}

template<class T> void Stack<T>::Pop(BiNode<T>**x)
{
	LinkNode<T> *ptr = top->next;
	*x=top->data;
	delete top;
	top = ptr;
}

template<class T> bool Stack<T>::isEmpty()
{
	return top == NULL;
}



#endif

