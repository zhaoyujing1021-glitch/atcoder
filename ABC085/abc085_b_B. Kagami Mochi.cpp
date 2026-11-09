#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    set<int> d;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        d.insert(x);
    }
    cout << d.size() << endl;
    
    return 0;
}