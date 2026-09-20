/*
Program Name: Strassen's Matrix Multiplication
Program Description: Takes two square matrices and multiplies them using
                     Strassen's divide and conquer matrix multiplication
Program Creation Time: Sep 20th 4:50
Program Creator: Ashwath Raj | AP25110010712
*/

#include<iostream>
using namespace std;

void add(int A[4][4],int B[4][4],int C[4][4],int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j]=A[i][j]+B[i][j];
}

void sub(int A[4][4],int B[4][4],int C[4][4],int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j]=A[i][j]-B[i][j];
}

void strassen(int A[4][4],int B[4][4],int C[4][4],int n){
    if(n==1){
        C[0][0]=A[0][0]*B[0][0];
        return;
    }

    int m=n/2;

    int A11[4][4]={0},A12[4][4]={0},A21[4][4]={0},A22[4][4]={0};
    int B11[4][4]={0},B12[4][4]={0},B21[4][4]={0},B22[4][4]={0};
    int P1[4][4]={0},P2[4][4]={0},P3[4][4]={0},P4[4][4]={0};
    int P5[4][4]={0},P6[4][4]={0},P7[4][4]={0};
    int X[4][4]={0},Y[4][4]={0};

    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++){
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+m];
            A21[i][j]=A[i+m][j];
            A22[i][j]=A[i+m][j+m];

            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+m];
            B21[i][j]=B[i+m][j];
            B22[i][j]=B[i+m][j+m];
        }

    add(A11,A22,X,m);
    add(B11,B22,Y,m);
    strassen(X,Y,P1,m);

    add(A21,A22,X,m);
    strassen(X,B11,P2,m);

    sub(B12,B22,Y,m);
    strassen(A11,Y,P3,m);

    sub(B21,B11,Y,m);
    strassen(A22,Y,P4,m);

    add(A11,A12,X,m);
    strassen(X,B22,P5,m);

    sub(A21,A11,X,m);
    add(B11,B12,Y,m);
    strassen(X,Y,P6,m);

    sub(A12,A22,X,m);
    add(B21,B22,Y,m);
    strassen(X,Y,P7,m);

    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++){
            C[i][j]=P1[i][j]+P4[i][j]-P5[i][j]+P7[i][j];
            C[i][j+m]=P3[i][j]+P5[i][j];
            C[i+m][j]=P2[i][j]+P4[i][j];
            C[i+m][j+m]=P1[i][j]-P2[i][j]+P3[i][j]+P6[i][j];
        }
}

int main(void){
    int n;

    cout<<"Enter Matrix Size (2 or 4): ";
    cin>>n;

    int A[4][4]={0},B[4][4]={0},C[4][4]={0};

    cout<<"Enter First Matrix:"<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>A[i][j];

    cout<<"Enter Second Matrix:"<<endl;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>B[i][j];

    strassen(A,B,C,n);

    cout<<"Result Matrix:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<C[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
