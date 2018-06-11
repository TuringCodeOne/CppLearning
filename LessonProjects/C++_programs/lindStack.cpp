#include<iostream>
#include<iostream>
#include<string>
using namespace std;






/**         链栈结点定义  LinkNode         **/
template<typename T> struct LinkNode
{
	T data;
	LinkNode<T> *next;
};


/**           链栈类模板定义                   **/
template<class T> class Stack
{
public:
	Stack() :top(NULL) {}
	~Stack();
	void Push(T x);          //入栈
	T Pop();           //出栈
	bool isEmpty();                   //判断栈空
	T top() const;
private:
	LinkNode<T> *top;                  //栈顶指针


};

template<class T> Stack<T>::~Stack()
{
	LinkNode<T> *ptr = NULL;
	while (top != NULL)     
	{
		ptr = top->next;
		delete top;
		top = ptr;
	}
}

template<class T> void Stack<T>::Push(T x)
{
	LinkNode<T> *ptr = new LinkNode<T>;
	ptr->data = x;
	ptr->next = top;
	top = ptr;
}

template<class T> T Stack<T>::Pop()
{
	LinkNode<T> *ptr = top->next;
	T x = top->data;
	delete top;
	return x;
}

template<class T> bool Stack<T>::isEmpty()
{
	return top == NULL;
}

template<class T> T Stack<T>::top() {
	return top->data;
}

int main()
{
	Stack<char> sta_char;
	sta_char.Push('T');
	cout << sta_char.Pop();
	cout << endl;
	Stack<string> sta_string;
	sta_string.Push("Tsing");
	cout << sta_string.Pop();
	sta_char.~Stack();
	sta_string.~Stack();
	return 0;
}

