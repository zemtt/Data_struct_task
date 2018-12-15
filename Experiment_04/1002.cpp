#include<iostream>

using namespace std;

void Search(int r[], int low, int high, int key) {
    while (low < high) {
        if (r[high] < key && r[low] > key) {
            high--;
            low++;
        }
        while (low <= high && r[high] > key)
            high--;
        if (r[high] == key) {
            cout << high + 1 << " " << r[high] << endl;
            return;
        }
        while (low <= high && r[low] < key)
            low++;
        if (r[low] == key) {
            cout << low + 1 << " " << r[low] << endl;
            return;
        }
    }
    cout << "not find" << endl;
}

int main() {
    int n, key;
    while (cin >> n && n) {
        int r[n];
        for (int i = 0; i < n; i++) {
            cin >> r[i];
        }
        cin >> key;
        Search(r, 0, n - 1, key);
    }
    return 0;
}