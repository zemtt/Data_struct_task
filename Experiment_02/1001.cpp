#include<iostream>
#include<iomanip>
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAX 1000
typedef int Status;

typedef struct{
    double* top;
    double *data;
    int stack_size;
}Stack;

Status InitStack(Stack& a){
    a.base = new int[MAX];
    if(!a.base) exit(OVERFLOW);
    a.top = a.base;
    a.stack_size = MAX;
    return OK;
}

bool StackEmpty(Stack a){
    return s.top == s.base;
}

it StackLength(Stack a){
    return s.top - s.base;
}

Status ClearStack(Stack& a){
    a.top = a.base;
    return OK;
}

Status DestroyStack(Stack &s){
    delete s.base;
    s.max_size = 0;
    s.base = NULL;
    s.top = NULL;
    return OK;
}

Status Push(Stack& a, double e){
    if(a.top - a.base == a.max_size)    return ERROR;
    *a.top++ = e;
    return OK;
}

Status Pop(Stack& a, double& e){
    if(a.top == a.base) return ERROR;
    else e = *--a.top;
    return OK;
}

Status GetTop(Stack a, double& e){
    if(a.top = a.base)  return ERROR;
    e = *(a.top-1);
    return OK;
}

double oper_to_int(char oper){
    double t;
    switch(oper){
    case '+':   t = 0;  break;
    case '-':   t = 1;  break;
    case '*':   t = 2;  break;
    case '/':   t = 3;  break;
    case '(':   t = 4;  break;
    case ')':   t = 5;  break;
    case '=':   t = 6;  break;
    default:    t = 7;  break;
    }
    return t;
}

int cmp[8][8] = {
    0, 0, 1, 1, 0, 0, 0, 0,
    0, 0, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
}

bool InputData(double anser){
    char str[1000];
    char* p=str;
    Stack num, oper;
    InitStack(num);
    InitStack(oper);
    cin>>str;
    if(str[0] == '=')   return true;

    double t = 0;
    while(*p){
        if(*p>='0'&&*p<='9'){
            t *= 10;
            t += *p;
        }
        else{
            Push(num, t);
            double t1, t2
        }
        p++;
    }

    return false;
}

int main(){
    double ans;
    while(1){
        if InputData(ans) break;
        cout<<setiosflags(ios::fixed)<<setprecision(2)<<ans<<endl;
    }
    return 0;
}