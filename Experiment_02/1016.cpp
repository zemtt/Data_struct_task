#include<iostream>
#include<cstring>
using namespace std;


int memo[100][3];
int f=0;

void FindOut(int in, int out){
    if(in == out-1){
        f=1;
        return;
    }
    for(int i = 0;i<3;i++){
        if(memo[in][i]){
			FindOut(memo[in][i]-1, out);
		}
    }
}

int main(){
    int n;
    int out;
    while(1){
        cin>>n;
        if(!n)  break;
        for(int i=0;i<n;i++){
            cin>>memo[i][0]>>memo[i][1]>>memo[i][2];
        }
        cin>>out;
        FindOut(0, out);
        if(f){
            cout<<"YES"<<endl;
            f=0;
        }
        else    cout<<"NO"<<endl;
    }
}
