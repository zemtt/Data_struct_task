#include <iostream>

using namespace std;

typedef struct Node {
    int data;
    struct Node *next;
} Node, *LinkList;

void Create(LinkList &L, int n) {
    LinkList p, rear;
    L = new Node;
    L->next = nullptr;
    rear = L;
    while (n--) {
        p = new Node;
        cin >> p->data;
        p->next = rear->next;
        rear->next = p;
        rear = p;
    }
}

void SelectSort(LinkList &L, int n) {
    LinkList p, q, e;
    for (p = L->next; p != nullptr; p = p->next) {
        q = p;
        for (e = q->next; e != nullptr; e = e->next) {
            if (e->data < q->data) {
                q = e;
            }
        }
        if (q != p) {
            swap(p->data, q->data);
        }
    }
}

int main() {
    int n;
    LinkList L;
    while (cin >> n && n) {
        Create(L, n);
        SelectSort(L, n);
        bool first = true;
        LinkList p = L->next;
        while (p) {
            if (first) {
                cout << p->data;
                first = false;
            } else {
                cout << " " << p->data;
            }
            p = p->next;
        }
        cout << endl;
    }
    return 0;
}