#include<iostream>
#include<cstring>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

using namespace std;

typedef struct Queqe{
    int *data;
    int tag;
    int front, rear;
    int len;
}Queqe;

Status InitQueqe(Queqe &q, int len){
    q.len = len;
    q.data = new int[len];
    q.tag = 0;
    q.front = 0;
    q.rear = 0;
}

Status QueqeClear(Queqe &q){
    delete q.data;
}

Status EnQueue(Queqe &q, int e){
    if(q.tag) return ERROR;
    q.data[q.rear] = e;
    q.rear = (q.rear+1)%q.len;
    if(q.rear == q.front)   q.tag = 1;
    return OK;
}

void PrintQueqe(Queqe q){
    int i = q.front;
    int f=1, ff=0;
    while(1){
        if(i==q.rear){
            if(f&&q.tag)   f=0;
            else    break;
        }
        if(ff)  cout<<' ';
        else    ff = 1;
        cout<<q.data[i];
        i = (i+1)%q.len;
    }
    cout<<endl;
}

int main(){
    int n, t;
    Queqe a;
    while(1){
        cin>>n;
        if(!n)  break;
        InitQueqe(a, n);
        for(int i=0;i<n;i++){
            cin>>t;
            EnQueue(a, t);
        }
        PrintQueqe(a);
        QueqeClear(a);
    }
}
