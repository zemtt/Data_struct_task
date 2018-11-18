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

Status EnQueue(Queqe &q, int e, int f){
    if(f){
        if(q.tag) return ERROR;
        q.data[q.rear] = e;
        q.rear = (q.rear+1)%q.len;
        if(q.rear == q.front)   q.tag = 1;
        return OK;
    }
    else{
        if(q.tag) return ERROR;
        q.data[q.front] = e;
        q.front = (q.front+q.len-1)%q.len;
        if(q.rear == q.front)   q.tag = 1;
        return OK;
    }
}

Status DeQueqe(Queqe &q, int &e, int f){
    if(q.tag==0&&q.front == q.rear)   return ERROR;
    if(f){
        if(q.tag)   q.tag = 0;
        e = q.data[q.front];
        q.front = (q.front+1)%q.len;
        return OK;
    }
    else{
        if(q.tag)   q.tag = 0;
        e = q.data[q.rear];
        q.rear = (q.rear+q.len-1)%q.len;
        return OK;
    }
}

int main(){
    int n, t, f;
    Queqe a;
    while(1){
        cin>>n;
        if(!n)  break;
        f=0; 
        InitQueqe(a, n);
        for(int i=0;i<n;i++){
            cin>>t;
            EnQueue(a, t, 1);
        }
        while(a.tag!=0||a.rear!=a.front){
            if(f)   cout<<' ';
            else    f=1;
            DeQueqe(a, t, 1);
            cout<<t;
        }
        cout<<endl;
        QueqeClear(a);
    }
}
