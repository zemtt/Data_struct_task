#include<iostream>
#include<cstring>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAX 1000
typedef int Status;

using namespace std;

typedef struct{
    char* top;
    char *base;
    int stack_size;
}Stack;

Status InitStack(Stack& a){
    a.base = new char[MAX];
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

Status Push(Stack& a, char e){
    if(a.top - a.base == a.stack_size)    return ERROR;
    *a.top++ = e;
    return OK;
}

Status Pop(Stack& a, char& e){
    if(a.top == a.base) return ERROR;
    else e = *--a.top;
    return OK;
}

Status GetTop(Stack a, char& e){
    if(a.top = a.base)  return ERROR;
    e = *(a.top-1);
    return OK;
}

bool IsHui(char* a){
    Stack t;
    InitStack(t);
    int len = strlen(a);
    char m;
    for(int i=0;i<len/2;i++){
        Push(t, a[i]);
    }
    for(int i=0;i<len/2;i++){
        Pop(t, m);
        if(m!=a[len-len/2 + i]) return false;
    }
    return true;
}

int main(){
    char str[1000];
    while(1){
        cin>>str;
        if(!strcmp(str,"0"))    break;
        if(IsHui(str))  cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;
    }
    return 0;
}
