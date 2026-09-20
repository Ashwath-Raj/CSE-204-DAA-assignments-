/*
Program Name: Minimum Spanning Tree Using Kruskal's Algorithm
Program Description: Takes a weighted undirected graph as input and finds
                     its Minimum Spanning Tree using Kruskal's Algorithm
Program Creation Time: Sep 20th
Program Creator: Ashwath Raj | AP25110010712
*/

#include<iostream>
#include<algorithm>
using namespace std;

struct Edge{
    int u;
    int v;
    int weight;
};

bool compare(Edge a,Edge b){
    return a.weight<b.weight;
}

int findParent(int parent[],int node){
    if(parent[node]==node)
        return node;

    return parent[node]=findParent(parent,parent[node]);
}

void unionSet(int parent[],int rank[],int u,int v){
    u=findParent(parent,u);
    v=findParent(parent,v);

    if(u!=v){
        if(rank[u]<rank[v])
            parent[u]=v;
        else if(rank[u]>rank[v])
            parent[v]=u;
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
}

void kruskal(Edge edges[],int V,int E){
    sort(edges,edges+E,compare);

    int parent[V],rank[V];

    for(int i=0;i<V;i++){
        parent[i]=i;
        rank[i]=0;
    }

    int count=0,total=0;

    cout<<"Edges in Minimum Spanning Tree:"<<endl;

    for(int i=0;i<E && count<V-1;i++){
        int u=edges[i].u;
        int v=edges[i].v;

        if(findParent(parent,u)!=findParent(parent,v)){
            cout<<u<<" - "<<v<<" : "<<edges[i].weight<<endl;
            total+=edges[i].weight;
            unionSet(parent,rank,u,v);
            count++;
        }
    }

    cout<<"Minimum Cost: "<<total<<endl;
}

int main(void){
    int V,E;

    cout<<"Enter Number of Vertices: ";
    cin>>V;

    cout<<"Enter Number of Edges: ";
    cin>>E;

    Edge edges[E];

    cout<<"Enter Edges (Source Destination Weight):"<<endl;
    for(int i=0;i<E;i++)
        cin>>edges[i].u>>edges[i].v>>edges[i].weight;

    kruskal(edges,V,E);

    return 0;
}
