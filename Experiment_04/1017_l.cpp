#include <iostream>

using namespace std;

bool BinarySearch(int *a, int key, int low, int high) {
    if (low > high)
        return false;
    else {
        int mid = (low + high) / 2;
        if (a[mid] == key) {
            return true;
        } else if (key < a[mid]) {
            return BinarySearch(a, key, low, mid - 1);
        } else {
            return BinarySearch(a, key, mid + 1, high);
        }
    }
}

int main() {
    int n, key;
    while (cin >> n && n) {
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> key;
        if (BinarySearch(a, key, 0, n - 1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}