/*
Program Name: Towers of Hanoi Without Recursion
Program Description: Takes the input {number of disks} and solves the Towers
                     of Hanoi Problem using iterative approach
Program Creation Time: Aug 20st 03:15
Program Creator: Ashwath Raj | AP25110010712
*/

#include<iostream>
#include<stack>
using namespace std;

void moveDisk(stack<int>& a,stack<int>& b,char x,char y){
	int d1=a.empty()?0:a.top();
	int d2=b.empty()?0:b.top();

	if(d1==0){
		a.push(d2);
		b.pop();
		cout<<"Move Disk "<<d2<<" from "<<y<<" to "<<x<<endl;
	}
	else if(d2==0){
		b.push(d1);
		a.pop();
		cout<<"Move Disk "<<d1<<" from "<<x<<" to "<<y<<endl;
	}
	else if(d1<d2){
		b.push(d1);
		a.pop();
		cout<<"Move Disk "<<d1<<" from "<<x<<" to "<<y<<endl;
	}
	else{
		a.push(d2);
		b.pop();
		cout<<"Move Disk "<<d2<<" from "<<y<<" to "<<x<<endl;
	}
}

int main(void){
	cout<<"======================================"<<endl;
	cout<<"TOWERS OF HANOI WITHOUT RECURSION"<<endl;
	cout<<"======================================"<<endl;

	int n;
	cout<<"Enter Number of Disks: ";
	cin>>n;

	if(n<=0){
		cout<<"Invalid Number of Disks!!"<<endl;
		return 0;
	}

	stack<int> source,aux,dest;

	for(int i=n;i>=1;i--)
		source.push(i);

	int moves=(1<<n)-1;

	for(int i=1;i<=moves;i++){
		if(n%2==1){
			if(i%3==1)
				moveDisk(source,dest,'A','C');
			else if(i%3==2)
				moveDisk(source,aux,'A','B');
			else
				moveDisk(aux,dest,'B','C');
		}
		else{
			if(i%3==1)
				moveDisk(source,aux,'A','B');
			else if(i%3==2)
				moveDisk(source,dest,'A','C');
			else
				moveDisk(aux,dest,'B','C');
		}
	}

	return 0;
}