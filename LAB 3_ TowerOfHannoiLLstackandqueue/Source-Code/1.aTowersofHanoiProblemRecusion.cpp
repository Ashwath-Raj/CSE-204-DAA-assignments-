/*
Program Name: Towers of Hanoi Using Recursion
Program Description: Takes the input {number of disks} and solves the Towers
                     of Hanoi Problem using recursive approach
Program Creation Time: Aug 20st 4:50
Program Creator: Ashwath Raj | AP25110010712
*/

#include<iostream>
using namespace std;

void towerOfHanoi(int n,char source,char aux,char dest);

int main(void){
	cout<<"======================================"<<endl;
	cout<<"TOWERS OF HANOI USING RECURSION"<<endl;
	cout<<"======================================"<<endl;

	int n;

	cout<<"Enter Number of Disks: ";
	cin>>n;

	if(n<=0){
		cout<<"Invalid Number of Disks!!"<<endl;
		return 0;
	}

	towerOfHanoi(n,'A','B','C');

	return 0;
}

void towerOfHanoi(int n,char source,char aux,char dest){
	if(n==1){
		cout<<"Move Disk 1 from "<<source<<" to "<<dest<<endl;
		return;
	}

	towerOfHanoi(n-1,source,dest,aux);
	cout<<"Move Disk "<<n<<" from "<<source<<" to "<<dest<<endl;
	towerOfHanoi(n-1,aux,source,dest);
}