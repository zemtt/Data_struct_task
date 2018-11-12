#include<iostream>
using namespace std;

int main(){
    int k;
    while(1){
        cin>>k;
        if(!k)  break;
        int la[k],lb[k];
        int ca=0, cb=0;
        for(int i=0;i<k;i++){
            int m;
            cin>>m;
            if(m>0)
                la[ca++] = m;
            else
                lb[cb++] = m;
        }
        for(int i=0;i<=cb;i++){
            la[ca+i] = lb[i];
        }
        int f = 0;
        for(int i=0;i<k;i++){
            if(f)   cout<<' ';
            else    f = 1;
            cout<<la[i];
        }
        cout<<endl;
    }
}
