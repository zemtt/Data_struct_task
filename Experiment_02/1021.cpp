#include<iostream>
#include<cstring>
using namespace std;

int memo[50000];

int main(){
    int m, n;
    while(1){
        cin>>m>>n;
        if(!m&&!n)  break;
        int f = 0;
        for(int i=0;i<m*n;i++){
            int k;
            cin>>k;
            if(memo[k]) f = 1;
            else    memo[k] = 1;
        }
        if(f)   cout<<"YES"<<endl;
        else    cout<<"NO"<<endl;
        memset(memo,0,50000);
    }
}
