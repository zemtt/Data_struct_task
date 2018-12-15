#include <iostream>

using namespace std;

void ssort(char r[], int n) {
    int i = 0, j = 0, k1 = n - 1, k2 = n - 1;
    char t;
    while (j < k1) {
        while (r[k1] == 'B') {
            k1--;
            k2--;
        }
        while (r[i] == 'R') {
            i++;
            j++;
        }
        if (r[j] == 'B') {
            t = r[i];
            r[i] = r[k2];
            r[k2] = t;
            while (r[i] == 'R') {
                i++;
                j++;
            }
            while (r[k1] == 'B') {
                k1--;
                k2--;
            }
        } else if (r[k1] == 'R') {
            t = r[i];
            r[i] = r[k2];
            r[k2] = t;
            while (r[i] == 'R') {
                i++;
                j++;
            }
            while (r[k1] == 'B') {
                k1--;
                k2--;
            }
        } else {
            while (r[j] == 'W') {
                j++;
            }
            if (j >= k1)
                break;
            if (r[j] == 'R') {
                t = r[j];
                r[j] = r[i];
                r[i] = t;
                i++;
            } else {
                t = r[k2];
                r[k2] = r[j];
                r[j] = t;
                k2--;
            }
        }
    }
}

int main() {
    int n;
    while (cin >> n && n) {
        char a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ssort(a, n);
        cout << a[0];
        for (int i = 1; i < n; i++) {
            cout << " " << a[i];
        }
        cout << endl;
    }
    return 0;
}