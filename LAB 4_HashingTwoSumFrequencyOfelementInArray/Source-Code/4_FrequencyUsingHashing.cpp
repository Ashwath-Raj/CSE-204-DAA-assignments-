/*
Program Name: Frequency of Elements Using Hashing
Program Description: Takes an integer array and uses hashing to find the
                     frequency of every distinct element
Program Creation Time: Aug 27th 4:20
Program Creator: Ashwath Raj | AP25110010712
*/

#include<iostream>
#include<unordered_map>
using namespace std;

void findFrequency(int arr[],int n){
	unordered_map<int,int> freq;

	for(int i=0;i<n;i++)
		freq[arr[i]]++;

	cout<<"Element Frequency:"<<endl;

	for(auto x:freq)
		cout<<x.first<<" : "<<x.second<<endl;
}

int main(void){
	int n;

	cout<<"Enter Size of Array: ";
	cin>>n;

	int arr[n];

	for(int i=0;i<n;i++){
		cout<<"Enter Element "<<i+1<<": ";
		cin>>arr[i];
	}

	findFrequency(arr,n);

	return 0;
}