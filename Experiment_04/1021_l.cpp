#include<iostream>

using namespace std;

typedef char TElemType;

typedef struct BiTNode {
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;


bool CreateBiTree(BiTree &T) {
    TElemType elem;
    cin >> elem;
    if (elem == '#') {
        T = nullptr;
    } else {
        T = new BiTNode;;
        if (T == nullptr)
            exit(0);
        T->data = elem;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return true;
};

int TreeDepth(BiTree T) {
    int h1, h2;
    if (T == nullptr) {
        return 0;
    } else {
        h1 = TreeDepth(T->lchild);
        h2 = TreeDepth(T->rchild);
        return (h1 < h2) ? h2 + 1 : h1 + 1;
    }
}


int main(int argc, const char *argv[]) {
    BiTree T;
    while (true) {
        CreateBiTree(T);
        if (T == nullptr) {
            break;
        }
        cout << TreeDepth(T) << endl;
    }
    return 0;
}