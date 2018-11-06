#include<iostream>
using namespace std;

int memo[1000][1000] = {0};

int akm(int m, int n){
	int ans;
    if(0); 
	else{
        if(m==0) ans = n+1;
        else if(n==0)   ans = akm(m-1,1);
        else    ans = akm(m-1,akm(m,n-1));
    }
    return ans;
}

int main(){
    int m,n;
    while(1){
        cin>>m>>n;
        if(!(m&&n)) break;
        cout<<akm(m,n)<<endl;
    }
    return 0;
}