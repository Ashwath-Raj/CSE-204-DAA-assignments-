/*
Program Name: Queue Implementation Using Linked List
Program Description: Implements Queue operations using a Linked List
                     following the FIFO principle
Program Creation Time: Aug 21st 12:05
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

class Queue{
	ListNode *front,*rear;

public:
	Queue(){
		front=rear=nullptr;
	}

	void enqueue(int val){
		ListNode *temp=new ListNode(val);

		if(rear==nullptr){
			front=rear=temp;
			return;
		}

		rear->next=temp;
		rear=temp;
	}

	void dequeue(){
		if(front==nullptr){
			cout<<"Queue is empty!!"<<endl;
			return;
		}

		ListNode *temp=front;
		cout<<"Dequeued Element: "<<front->val<<endl;
		front=front->next;

		if(front==nullptr)
			rear=nullptr;

		delete temp;
	}

	void display(){
		ListNode *temp=front;

		cout<<"Queue: ";
		while(temp!=nullptr){
			cout<<temp->val<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
};

int main(void){
	Queue q;
	int n,val;

	cout<<"Enter Number of Elements: ";
	cin>>n;

	for(int i=0;i<n;i++){
		cout<<"Enter Element "<<i+1<<": ";
		cin>>val;
		q.enqueue(val);
	}

	cout<<"Queue After Enqueue: ";
	q.display();

	q.dequeue();

	cout<<"Queue After Dequeue: ";
	q.display();

	return 0;
}