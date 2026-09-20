/*
Program Name: Maximum and Minimum Using Divide and Conquer
Program Description: Takes an array as input and finds the maximum and minimum
                     elements using divide and conquer strategy
Program Creation Time: Sep 20th 4:30
Program Creator: Ashwath Raj | AP25110010712
*/

#include<iostream>
using namespace std;

struct Result{
    int max;
    int min;
};

Result findMaxMin(int arr[],int low,int high){
    Result r;

    if(low==high){
        r.max=r.min=arr[low];
        return r;
    }

    if(high==low+1){
        if(arr[low]>arr[high]){
            r.max=arr[low];
            r.min=arr[high];
        }
        else{
            r.max=arr[high];
            r.min=arr[low];
        }
        return r;
    }

    int mid=(low+high)/2;

    Result left=findMaxMin(arr,low,mid);
    Result right=findMaxMin(arr,mid+1,high);

    r.max=(left.max>right.max)?left.max:right.max;
    r.min=(left.min<right.min)?left.min:right.min;

    return r;
}

int main(void){
    int n;

    cout<<"Enter Size of Array: ";
    cin>>n;

    int arr[n];

    cout<<"Enter Array Elements: ";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    Result r=findMaxMin(arr,0,n-1);

    cout<<"Maximum Element: "<<r.max<<endl;
    cout<<"Minimum Element: "<<r.min<<endl;

    return 0;
}
