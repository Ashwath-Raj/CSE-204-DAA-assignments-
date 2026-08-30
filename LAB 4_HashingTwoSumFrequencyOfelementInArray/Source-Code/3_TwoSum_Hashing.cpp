/*
Program Name: Two Sum Using Hashing
Program Description: Takes the inputs {array, array size, target} and
                     determines whether two elements have sum equal to target
Program Creation Time: Aug 27th 4:00
Program Creator: Ashwath Raj | AP25110010712
*/

#include<iostream>
#include<unordered_set>
using namespace std;

bool twoSum(int arr[],int n,int target){
	unordered_set<int> hash;

	for(int i=0;i<n;i++){
		int req=target-arr[i];

		if(hash.find(req)!=hash.end())
			return true;

		hash.insert(arr[i]);
	}

	return false;
}

int main(void){
	int n,target;

	cout<<"Enter Size of Array: ";
	cin>>n;

	int arr[n];

	for(int i=0;i<n;i++){
		cout<<"Enter Element "<<i+1<<": ";
		cin>>arr[i];
	}

	cout<<"Enter Target Value: ";
	cin>>target;

	if(twoSum(arr,n,target))
		cout<<"Two elements with the given sum exist!!"<<endl;
	else
		cout<<"No such pair exists!!"<<endl;

	return 0;
}