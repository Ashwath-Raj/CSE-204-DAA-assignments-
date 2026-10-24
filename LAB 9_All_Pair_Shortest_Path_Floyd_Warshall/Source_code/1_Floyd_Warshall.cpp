/*
Program Name: All-Pair Shortest Path Using Floyd-Warshall Algorithm
Program Description: Finds shortest distances between every pair of vertices in a weighted directed graph.
Program Creation Time: Oct 24th, 2026
Program Creator: Ashwath Raj | AP25110010712
*/
#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

const int INF=1000000000;

int main(void){
    int V;
    cout<<"Enter Number of Vertices: ";
    cin>>V;

    vector<vector<int>> dist(V,vector<int>(V));
    cout<<"Enter Adjacency Matrix (-1 for no edge):"<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            int x;
            cin>>x;
            dist[i][j]=(i==j)?0:(x==-1?INF:x);
        }
    }

    for(int k=0;k<V;k++)
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                if(dist[i][k]!=INF && dist[k][j]!=INF &&
                   dist[i][k]+dist[k][j]<dist[i][j])
                    dist[i][j]=dist[i][k]+dist[k][j];

    cout<<"Shortest Distance Matrix:"<<endl;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(dist[i][j]==INF) cout<<setw(6)<<"INF";
            else cout<<setw(6)<<dist[i][j];
        }
        cout<<endl;
    }
    return 0;
}
