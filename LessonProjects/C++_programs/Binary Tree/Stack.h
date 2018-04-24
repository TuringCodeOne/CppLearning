#ifndef STACK_LINK
#define STACK_LINK


/**          树的节点  BiNode  模板定义        **/
template<typename T> struct BiNode
{
	T data;
	BiNode<T> *lchild, *rchild;
};


/**          链栈节点  LinkNode  模板定义        **/
template<typename T> struct LinkNode
{
	BiNode<T> *data;
	LinkNode<T> *next;
};


/**           栈的类定义                    **/
template<class T> class Stack
{
public:
	Stack() :top(NULL) {}
	~Stack();
	void Push( BiNode<T>*x);          //入栈
	void Pop(BiNode<T>**x);           //出栈
	bool isEmpty();                   //判断栈空
private:
	LinkNode<T> *top;                  //栈顶指针


};

template<class T> Stack<T>::~Stack()
{
	LinkNode<T> *ptr = NULL;
	while (top != NULL)     //循环释放栈节点空间  
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

