/*
Program Name: Fractional Knapsack Using Greedy Approach
Program Description: Takes the weight and value of items and finds the maximum
                     value that can be obtained using fractional knapsack
Program Creation Time: Sep 20th 5:00
Program Creator: Ashwath Raj | AP25110010712
*/

#include<iostream>
#include<algorithm>
using namespace std;

struct Item{
    int weight;
    int value;
    double ratio;
};

bool compare(Item a,Item b){
    return a.ratio>b.ratio;
}

double fractionalKnapsack(Item items[],int n,int capacity){
    sort(items,items+n,compare);

    double total=0;

    for(int i=0;i<n && capacity>0;i++){
        if(items[i].weight<=capacity){
            capacity-=items[i].weight;
            total+=items[i].value;
        }
        else{
            total+=(double)items[i].value/items[i].weight*capacity;
            capacity=0;
        }
    }

    return total;
}

int main(void){
    int n,capacity;

    cout<<"Enter Number of Items: ";
    cin>>n;

    Item items[n];

    cout<<"Enter Weight and Value of each item:"<<endl;
    for(int i=0;i<n;i++){
        cin>>items[i].weight>>items[i].value;
        items[i].ratio=(double)items[i].value/items[i].weight;
    }

    cout<<"Enter Knapsack Capacity: ";
    cin>>capacity;

    cout<<"Maximum Value: "<<fractionalKnapsack(items,n,capacity)<<endl;

    return 0;
}
