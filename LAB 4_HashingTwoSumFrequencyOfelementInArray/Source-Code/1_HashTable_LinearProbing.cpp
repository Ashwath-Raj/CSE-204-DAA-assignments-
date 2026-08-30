/*
Program Name: Hash Table Using Linear Probing
Program Description: Takes the inputs {keys, table size} and implements a
                     hash table using Linear Probing for collision handling
Program Creation Time: Aug 27th 3:10
Program Creator: Ashwath Raj | AP25110010712
*/

#include<iostream>
using namespace std;

class HashTable{
	int *table;
	int size;

public:
	HashTable(int n){
		size=n;
		table=new int[size];

		for(int i=0;i<size;i++)
			table[i]=-1;
	}

	void insert(int key){
		int idx=key%size;

		while(table[idx]!=-1)
			idx=(idx+1)%size;

		table[idx]=key;
	}

	void display(){
		cout<<"Hash Table:"<<endl;

		for(int i=0;i<size;i++)
			cout<<i<<" : "<<table[i]<<endl;
	}
};

int main(void){
	int size,n,key;

	cout<<"Enter Hash Table Size: ";
	cin>>size;

	HashTable ht(size);

	cout<<"Enter Number of Elements: ";
	cin>>n;

	for(int i=0;i<n;i++){
		cout<<"Enter Element "<<i+1<<": ";
		cin>>key;
		ht.insert(key);
	}

	ht.display();

	return 0;
}