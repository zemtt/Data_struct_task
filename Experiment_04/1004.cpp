#include<iostream>
#include<cstring>
using namespace std;

int MAP[20][20];
int MAP_A[20][20];

int main(){
    int n, m;
    
    while(1){
        cin>>n>>m;
        if(!n&&!m)  break;
        
        memset(MAP,0,sizeof(MAP));
        memset(MAP_A,0,sizeof(MAP));

        for(int i=0;i<m;i++){
            int j,k;
            cin>>j>>k;
            MAP[j-1][k-1] = 1;
        }

        int MAP_L[20][20];
        int MAP_LL[20][20];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                MAP_L[i][j] = MAP[i][j];
            }
        }

        for(int i=0;i<6;i++){
            memset(MAP_LL,0,sizeof(MAP_LL));
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    if(MAP_L[i][j]) MAP_A[i][j] = MAP_L[i][j];
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    for(int l=0;l<n;l++)
                        MAP_LL[i][j] += MAP_L[i][l] * MAP[l][[j];
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    MAP_L[i][j] = MAP_LL[i][j];
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<MAP[i][j]<<' ';
            }
            cout<<endl;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<MAP_A[i][j]<<' ';
            }
            cout<<endl;
        }
    }
}