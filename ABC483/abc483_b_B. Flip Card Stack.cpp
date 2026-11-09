#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0, q = 0;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }

    for (int step = 0; step < q; ++step) {
        int k = 0;
        std::cin >> k;

        for (int i = 0; i < k; ++i) {
            a[i] = -a[i]; 
        }

        for (int i = 0; i < k / 2; ++i) {
            int temp = a[i];
            a[i] = a[k - 1 - i];
            a[k - 1 - i] = temp;
        }
    }

    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << endl;
    }

    return 0;
}