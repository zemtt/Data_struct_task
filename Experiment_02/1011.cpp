#include<iostream>
#include<cstring>
using namespace std;

int memo[1000][1000] = {0};

int akm(int m, int n){
	if(m==0){
		return n+1;
	}
	else if(m==1){
		return n+2;
	}
	else if(m==2){
		return 2*n+3;
	}
	else if(m==3){
		int t=1;
		for(int i=0;i<n+3;i++){
			t*=2;
		}
		return t-3;
	}
	else if(m==4){
		if(n==0)	return 13;
		else if(n==1)	return 65533;
	}
	else return 0;
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
