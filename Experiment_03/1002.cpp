#include<iostream>
#include<cstring>

using namespace std;

typedef struct BiThrNode{
    char data;
    struct BiThrNode *lchild, *rchild;
    int LTag, RTag;
}BiThrNode, *BiThrTree;

void CreatTree(BiThrNode *tree, char *str){
    if(!*str){

    }
    else{
        
    }
}

int main(){
    char str0[100], str1[100];
    BiThrTree tree0, tree1;
    while(1){
        cin>>str0;
        if(!strcmp(str0, "0"))  break;
        cin>>str1;
        CreatTree(tree0, str0);
        CreatTree(tree1, str1);       
    }
}