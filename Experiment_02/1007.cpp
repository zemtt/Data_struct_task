#include<iostream>
#include<cstring>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

using namespace std;

typedef struct LNode{
	int elem;
	struct LNode* next;
}LNode;

typedef struct Queqe{
    LNode *front;
    LNode *rear;
}Queqe;

Status InitQueqe(Queqe& q ,int len){
    LNode *p;
    q.front = new LNode;
    p = q.front;
    for(int i=0;i<len;i++){
        p->next = new LNode;
        p = p->next;
    }
    p->next = q.front;
    q.rear = q.front;
    return OK; 
}

bool Empty(Queqe q){
    return q.front->next == q.rear;
}

bool Full(Queqe q){
    return q.rear->next == q.front;
}

Status QueqeInsert(Queqe& q, int elem){
    if(Full(q)) return ERROR;
    q.rear->elem = elem;
    q.rear = q.rear->next;
    return OK;
}

Status QueqeClear(Queqe& q){
    LNode *p = q.front;
    LNode *t;
    do{
        t = p;
        p = p->next;
        delete t;
    }while(p!=q.front);
}

void PrintQueqe(Queqe q){
    int f=0;
    for(LNode *p = q.front;p!=q.rear;p=p->next){
        cout<<p->elem<<' ';
    }
}

int main(){
    int m,n;
    Queqe a;
    int t;
    while(1){
        cin>>n>>m;
        if(!n&&!m)  break;
        InitQueqe(a, m);
        for(int i=0;i<n;i++){
            cin>>t;
            QueqeInsert(a, t);
        }
	    PrintQueqe(a);
	    if(n<=m)    cout<<'0'<<endl;
	    else    cout<<'1'<<endl;
	    QueqeClear(a);
    }
}
