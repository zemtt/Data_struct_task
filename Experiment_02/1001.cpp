#include<iostream>
#include<cstdlib>
#include<cstring>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAX 1000
typedef int Status;
typedef double ELEMTYPE;

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

bool isSign(char a){
    return a!='+'&&a!='-'&&a!='*'&&a!='/'&&a!='('&&a!=')'&&a!='='
}

int main(){
    char str[1000];
    int f;
    while(1){
        cin>>str;
        if(srtcmp(str,"=")) break;
        for(char* a=str;*a;a++){
            if
        }
    }
    return 0;
}