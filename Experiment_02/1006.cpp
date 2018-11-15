#include<iostream>
#include<cstring>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAX 100000

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
    if(a.top <= a.base) return ERROR;
    else e = *--a.top;
    return OK;
}

Status GetTop(Stack a, ELEMTYPE& e){
    if(a.top = a.base)  return ERROR;
    e = *(a.top-1);
    return OK;
}

int main(){
    Stack t;
    InitStack(t);
    char str[1000];
    int len, m;
    int f;
    while(1){
        cin>>str;
        f=1;
        if(!strcmp(str, "0"))   break;
        len = strlen(str);
        for(int i=0;i<len;i++){
            if(str[i]=='I'||str[i]=='i'){
                Push(t, 1);
            }
            else if(str[i]=='O'){
                if(Pop(t, m)!=OK){
                    f=0;
                    break;
                }
            }
        }
        if(t.top!=t.base)   f = 0;
        if(f)   cout<<"TRUE"<<endl;
        else    cout<<"FALSE"<<endl;
        ClearStack(t);
    }
}
