/*
Program Name: Stack Implementation Using Linked List
Program Description: Implements Stack operations using a Linked List
                     following the LIFO principle
Program Creation Time: Aug 21st 10:00
Program Creator: Ashwath Raj | AP25110010712
*/

#include<iostream>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;

	ListNode():val(0),next(nullptr){}
	ListNode(int x):val(x),next(nullptr){}
	ListNode(int x,ListNode *next):val(x),next(next){}
};

class Stack{
	ListNode *top;

public:
	Stack(){
		top=nullptr;
	}

	void push(int val){
		ListNode *temp=new ListNode(val);
		temp->next=top;
		top=temp;
	}

	void pop(){
		if(top==nullptr){
			cout<<"Stack is empty!!"<<endl;
			return;
		}

		ListNode *temp=top;
		cout<<"Popped Element: "<<top->val<<endl;
		top=top->next;
		delete temp;
	}

	void display(){
		ListNode *temp=top;

		cout<<"Stack: ";
		while(temp!=nullptr){
			cout<<temp->val<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
};

int main(void){
	Stack s;
	int n,val;

	cout<<"Enter Number of Elements: ";
	cin>>n;

	for(int i=0;i<n;i++){
		cout<<"Enter Element "<<i+1<<": ";
		cin>>val;
		s.push(val);
	}

	cout<<"Stack After Push: ";
	s.display();

	s.pop();

	cout<<"Stack After Pop: ";
	s.display();

	return 0;
}