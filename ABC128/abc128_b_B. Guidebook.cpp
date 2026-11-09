#include <bits/stdc++.h>
using namespace std;

struct Restaurant {
    string city;
    int score;
    int id;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Restaurant> r(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i].city >> r[i].score;
        r[i].id = i + 1; 
    }

    sort(r.begin(), r.end(), [](const Restaurant& a, const Restaurant& b) {
        if (a.city != b.city) {
            return a.city < b.city;
        }
        return a.score > b.score; 
    });

    for (int i = 0; i < n; ++i) {
        cout << r[i].id << "\n";
    }

    return 0;
}