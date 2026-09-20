/*
Program Name: Maximum Subarray Using Divide and Conquer
Program Description: Takes an integer array and finds the maximum possible
                     subarray sum using divide and conquer strategy
Program Creation Time: Sep 20th 4:40
Program Creator: Ashwath Raj | AP25110010712
*/

#include<iostream>
using namespace std;

int maxValue(int a,int b){
    return (a>b)?a:b;
}

int maxCrossingSum(int arr[],int low,int mid,int high){
    int sum=0;
    int leftSum=-1000000000;

    for(int i=mid;i>=low;i--){
        sum+=arr[i];
        if(sum>leftSum)
            leftSum=sum;
    }

    sum=0;
    int rightSum=-1000000000;

    for(int i=mid+1;i<=high;i++){
        sum+=arr[i];
        if(sum>rightSum)
            rightSum=sum;
    }

    return leftSum+rightSum;
}

int maxSubarray(int arr[],int low,int high){
    if(low==high)
        return arr[low];

    int mid=(low+high)/2;

    int left=maxSubarray(arr,low,mid);
    int right=maxSubarray(arr,mid+1,high);
    int cross=maxCrossingSum(arr,low,mid,high);

    return maxValue(maxValue(left,right),cross);
}

int main(void){
    int n;

    cout<<"Enter Size of Array: ";
    cin>>n;

    int arr[n];

    cout<<"Enter Array Elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Maximum Subarray Sum: "<<maxSubarray(arr,0,n-1)<<endl;

    return 0;
}
