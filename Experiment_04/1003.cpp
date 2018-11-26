#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int path_len[26][26];
    char path[26][26][26];
    int dict[256];
    char ch[26];
    int n, m;
    while(1){
        memset(path,100000,sizeof(path));
        memset(ch,0,sizeof(ch));

        cin>>n>>m;
        if(!(n&&m)) break;
        for(int i=0;i<n;i++){
            char t;
            cin>>t;
            dict[t] == i;
            ch[i] = t;
        }
        for(int i=0;i<m;i++){
            char ca, cb;
            cin>>ca>>cb>>path[dict[ca]][dict[cb]];
        }

    }
}