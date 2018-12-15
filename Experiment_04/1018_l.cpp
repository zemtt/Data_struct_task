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
        T->data = elem;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return true;
};

bool InOrder(BiTree T, int &max) {
    if (T == nullptr) {
        return true;
    }
    bool leftJudge = InOrder(T->lchild, max);
    if (!leftJudge || max >= T->data) {
        return false;
    }
    max = T->data;
    bool rightJudge = InOrder(T->rchild, max);
    return rightJudge;
}


int main(int argc, const char *argv[]) {
    BiTree T;
    while (CreateBiTree(T) && T) {
        int max = INT16_MIN;
        if (InOrder(T, max)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}