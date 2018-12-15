#include <iostream>

using namespace std;

const int MAXSIZE = 100;
const int LENGTH = 13;

typedef struct Node {
    int datum;
    struct Node *next = nullptr;
} Node, *Np;

typedef struct HushList {
    Np list[MAXSIZE];
    int key_num;
} HushList;

int H(int key) {
    return key % 13;
}

void BInsert(Np &head, int tar) {
    Np t = head;
    while (t->next != nullptr) {
        t = t->next;
    }
    Np temp = new Node;
    temp->datum = tar;
    t->next = temp;
}

void showList(Np &head) {
    Np t = head;
    while (t->next != nullptr) {
        cout << ' ' << t->next->datum;
        t = t->next;
    }
    cout << endl;
}

bool initHushList(HushList &list) {
    cin >> list.key_num;
    if (list.key_num == 0) {
        return false;
    }
    for (auto &i : list.list) {
        i = new Node;
    }
    for (int i = 0; i < list.key_num; ++i) {
        int t;
        cin >> t;
        BInsert(list.list[H(t)], t);
    }
    return true;
}

void insertHush(HushList &l, int key) {
    BInsert(l.list[H(key)], key);
}

void showHush(HushList &l) {
    for (int i = 0; i < LENGTH; ++i) {
        cout << i;
        showList(l.list[i]);
    }
}

int main() {
    HushList l;
    while (initHushList(l)) {
        int key;
        cin >> key;
        insertHush(l, key);
        showHush(l);
    }
    return 0;
}