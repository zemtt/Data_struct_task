#include<iostream>
using namespace std;

void insert(char*s,char*t,int pos){
    char c[1000];
    char *ps = s, *pt = t;
    int p=0;
    while(p<pos-1){
        c[p++] = *(ps++);
    }
    while(*pt){
        c[p++] = *(pt++);
    }
    while(*ps){
        c[p++] = *(ps++);
    }
    for(int i=0;i<p;i++){
        s[i] = c[i];
    }
    s[p] = '\0';
}

int main(){
    int pos;
    char a[1000];
    char b[1000];
    while(1){
        cin>>pos;
        if(!pos)    break;
        cin>>a>>b;
        insert(a, b, pos);
        cout<<a<<endl;
    }
}
