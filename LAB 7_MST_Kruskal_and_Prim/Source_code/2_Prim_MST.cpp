/*
Program Name: Minimum Spanning Tree Using Prim's Algorithm
Program Description: Takes a weighted undirected graph as input and finds
                     its Minimum Spanning Tree using Prim's Algorithm
Program Creation Time: Sep 20th
Program Creator: Ashwath Raj | AP25110010712
*/

#include<iostream>
#include<climits>
using namespace std;

int findMin(int key[],bool visited[],int V){
    int minValue=INT_MAX;
    int index=-1;

    for(int i=0;i<V;i++){
        if(!visited[i] && key[i]<minValue){
            minValue=key[i];
            index=i;
        }
    }

    return index;
}

void prim(int graph[][10],int V){
    int parent[V],key[V];
    bool visited[V]={false};

    for(int i=0;i<V;i++){
        key[i]=INT_MAX;
        parent[i]=-1;
    }

    key[0]=0;

    for(int i=0;i<V-1;i++){
        int u=findMin(key,visited,V);

        visited[u]=true;

        for(int v=0;v<V;v++){
            if(graph[u][v] && !visited[v] && graph[u][v]<key[v]){
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
    }

    int total=0;

    cout<<"Edges in Minimum Spanning Tree:"<<endl;

    for(int i=1;i<V;i++){
        cout<<parent[i]<<" - "<<i<<" : "<<graph[i][parent[i]]<<endl;
        total+=graph[i][parent[i]];
    }

    cout<<"Minimum Cost: "<<total<<endl;
}

int main(void){
    int V;

    cout<<"Enter Number of Vertices: ";
    cin>>V;

    int graph[10][10]={0};

    cout<<"Enter Adjacency Matrix:"<<endl;
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            cin>>graph[i][j];

    prim(graph,V);

    return 0;
}
