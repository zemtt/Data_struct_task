#include<iostream>

using namespace std;

void CounterSort(int a[], int b[], int n) {
    int i, j, c;
    for (i = 0; i < n; i++) {
        for (j = 0, c = 0; j < n; j++) {
            if (a[j] < a[i]) {
                c++;
            }
        }
        b[c] = a[i];
    }
}

int main() {
    int n;
    while (cin >> n && n) {
        int a[n], b[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        CounterSort(a, b, n);
        cout << b[0];
        for (int i = 1; i < n; i++) {
            cout << " " << b[i];
        }
        cout << endl;
    }
    return 0;
}