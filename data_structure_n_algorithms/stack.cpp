#include <iostream>
#include <cmath>
#include <cstring>
#include <stdlib.h>

#define MAXSIZE 100

using namespace std;

template<class type1>
class Stack
{
	private:
		type1* stk;
		int top;
	public:
		Stack(){
			top = -1;
			stk = new type1[MAXSIZE];
			}
		Stack(int size){
			top = -1;
			stk = new type1[size];
			}
		type1 Push(type1 element);
		void Pop();
		type1 Top_element();
		bool Is_empty();
};

template<class type1>
type1 Stack<type1>::Push(type1 element)
{
	top += 1;
	stk[top] = element;
}

template<class type1>
void Stack<type1>::Pop()
{
	top -= 1;
}

template<class type1>
type1 Stack<type1>::Top_element()
{
	return stk[top];
}

template<class type1>
bool Stack<type1>::Is_empty()
{
	if(top==-1)
	{
		return true;
	}
	else if(top>=0)
	{
		return false;
	}
}

int main(){
	
	Stack<int> s(10);
	for(int i=0;i<=8;i++)
	{
		if(s.Is_empty()) {cout << "empty!" << endl;}
		s.Push(i);
		cout << s.Top_element() << endl;
	}
	for(int i=0;i<5;i++) {s.Pop();cout << s.Top_element();}

	cout << sqrt(3) << endl;
	cout << "hello,world!" << endl;

	return 0;
}
