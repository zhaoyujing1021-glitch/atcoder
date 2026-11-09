#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0; 

    vector<int> count(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        count[a]++;
        count[b]++;
    }

    for (int i = 1; i <= n; i++) {
        cout << count[i] << endl;
    }
    
    return 0;
}