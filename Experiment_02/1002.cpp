#include<iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;

using namespace std;

typedef struct{
    int top[2], bot[2];
    int *data;
    int m;
}DblStack;

Status InitStack(DblStack& a, int max_size){
    a.data = new int[max_size];
    a.m = max_size;
    a.top[0] = 0;
    a.top[1] = a.m-1;
}

bool IsFull(DblStack a){
    return a.top[0]-a.top[1]>0;
}

bool IsEmpty(DblStack a, int i){
    if(i)
    	return a.top[i] == a.m-1;
    else
		return !bool(a.top[i]);
}

Status PushStack(DblStack& a, int i, int elem){
    if(IsFull(a))   return ERROR;
    if(i)
    	a.data[a.top[i]--] = elem;
    else
    	a.data[a.top[i]++] = elem;
    return OK;
}

Status PopStack(DblStack& a, int i, int& elem){
    if(IsEmpty(a,i))    return  ERROR;
    if(i)
    	elem = a.data[++a.top[i]];
    else
    	elem = a.data[--a.top[i]];
    return OK;
}

Status InputStack(DblStack& a, int la, int lb){
    int elem;
    for(int i=0;i<la;i++){
        cin>>elem;
        PushStack(a,0,elem);
    }   
    for(int i=0;i<lb;i++){
        cin>>elem;
        PushStack(a,1,elem);
    }
    return OK;
}

int main(){
    int len;
    int e[2], d[2];
    int t;
    while(1){
        cin>>len;
        if(!len)    break;
        DblStack m;
        InitStack(m,len);
        cin>>e[0]>>e[1]>>d[0]>>d[1];
        InputStack(m, e[0],e[1]);
        cout<<int(IsFull(m))<<endl;
        for(int i=0;i<d[0];i++){
            PopStack(m,0,t);
            cout<<t<<' ';
        }
        cout<<!IsEmpty(m,0)<<endl;
        for(int i=0;i<d[1];i++){
            PopStack(m,1,t);
            cout<<t<<' ';
        }
        cout<<!IsEmpty(m,1)<<endl;
    }
    return 0;
}
