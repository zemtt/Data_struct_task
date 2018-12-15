#include<iostream>

using namespace std;

void Process(int a[], int n) {
    int low = 0, high = n - 1;
    while (low < high) {
        while (low < high && a[low] < 0) {
            low++;
        }
        while (low < high && a[high] > 0) {
            high--;
        }
        if (low < high) {
            swap(a[low], a[high]);
            low++;
            high--;
        }
    }
}

int main() {
    int n;
    while (cin >> n && n) {
        int b[n];
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        Process(b, n);
        cout << b[0];
        for (int i = 1; i < n; i++) {
            cout << " " << b[i];
        }
        cout << endl;
    }
    return 0;
}