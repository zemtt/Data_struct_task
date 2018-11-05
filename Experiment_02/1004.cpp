#include<iostream>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAX 1000

typedef int ELEMTYPE;
typedef int Status;

using namespace std;

typedef struct{
    ELEMTYPE *top;
    ELEMTYPE *base;
    int stack_size;
}Stack;

Status InitStack(Stack& a){
    a.base = new ELEMTYPE[MAX];
    if(!a.base) exit(OVERFLOW);
    a.top = a.base;
    a.stack_size = MAX;
    return OK;
}

bool StackEmpty(Stack a){
    return a.top == a.base;
}

int StackLength(Stack a){
    return a.top - a.base;
}

Status ClearStack(Stack& a){
    a.top = a.base;
    return OK;
}

Status DestroyStack(Stack &s){
    delete s.base;
    s.stack_size = 0;
    s.base = NULL;
    s.top = NULL;
    return OK;
}

Status Push(Stack& a, ELEMTYPE e){
    if(a.top - a.base == a.stack_size)    return ERROR;
    *a.top++ = e;
    return OK;
}

Status Pop(Stack& a, ELEMTYPE& e){
    if(a.top == a.base) return ERROR;
    else e = *--a.top;
    return OK;
}

Status GetTop(Stack a, ELEMTYPE& e){
    if(a.top = a.base)  return ERROR;
    e = *(a.top-1);
    return OK;
}

int main(){
    int k;
    int t, f;
    Stack m;
    InitStack(m);
    while(1){
        cin>>k;
        f = 0;
        if(!k)  break;
        for(int i=0;i<k;i++){
            cin>>t;
            if(f)   continue;
            if(t!=-1)
                Push(m,t);
            else{
                if(Pop(m,t))
                    cout<<t<<endl;
                else{
                    cout<<"POP ERROR"<<endl;
                    f=1;
                }
            }
        }
        ClearStack(m);
    }
}