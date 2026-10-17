/*
Program Name: Huffman Coding Using Greedy Approach
Program Description: Builds an optimal Huffman tree, prints codes and calculates encoded size.
Program Creation Time: Oct 17th, 2026
Program Creator: Ashwath Raj | AP25110010712
*/
#include<iostream>
#include<queue>
#include<vector>
#include<string>
using namespace std;

struct Node{
    char ch;
    int freq,order;
    Node *left,*right;
    Node(char c,int f,int o):ch(c),freq(f),order(o),left(nullptr),right(nullptr){}
};
struct Compare{
    bool operator()(Node *a,Node *b)const{
        if(a->freq!=b->freq) return a->freq>b->freq;
        return a->order>b->order;
    }
};
void codes(Node *p,string s,int &bits){
    if(!p->left&&!p->right){
        cout<<p->ch<<" : "<<s<<endl;
        bits+=p->freq*(int)s.size();
        return;
    }
    codes(p->left,s+"0",bits);
    codes(p->right,s+"1",bits);
}
int main(void){
    char ch[]={'a','c','d','e','o','m','s','t','u'};
    int f[]={20,11,2,10,15,8,10,22,2},order=0,bits=0;
    priority_queue<Node*,vector<Node*>,Compare> q;
    for(int i=0;i<9;i++) q.push(new Node(ch[i],f[i],order++));
    cout<<"Huffman Merge Steps:"<<endl;
    while(q.size()>1){
        Node *l=q.top();q.pop();
        Node *r=q.top();q.pop();
        cout<<l->freq<<" + "<<r->freq<<" = "<<l->freq+r->freq<<endl;
        Node *p=new Node('$',l->freq+r->freq,order++);
        p->left=l;p->right=r;q.push(p);
    }
    cout<<"Huffman Codes:"<<endl;
    codes(q.top(),"",bits);
    cout<<"Encoded size: "<<bits*100<<" bits ("<<bits*100/8<<" bytes)"<<endl;
    return 0;
}
