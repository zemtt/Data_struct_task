#include<iostream>
using namespace std;

void MoveLeft(int a[], int len){
    int head = a[0];
    for(int i=0;i<len-1;i++){
        a[i] = a[i+1];
    }
    a[len-1] = head;
}

int main(){
    int n;
    while(1){
        cin>>n;
        if(!n)  break;
        int k[n];
        for(int i=0;i<n;i++)    cin>>k[i];
        int count;
        cin>>count;
        for(int i=0;i<count;i++)
            MoveLeft(k, n);
        int f=0;
        for(int i=0;i<n;i++){
            if(f)
                cout<<' ';
            else
                f=1;
            cout<<k[i];
        }
        cout<<endl;
    }
}
