#include<iostream>
#include<cstring>
using namespace std;

void Save(char *a,char *b, int k){
    if(k){
        Save(a,b+1,k-1);
        *b = *(a+k);
    }
    else{
        *b = *a;
    }
}

int main(){
    char str[100];
    while(1){
        cin>>str;
        if(!strcmp(str,"0"))    break;
        char str_1[100];
        Save(str, str_1, strlen(str)-1);
        cout<<str_1<<endl;
        memset(str_1,0,100);
    }
}
