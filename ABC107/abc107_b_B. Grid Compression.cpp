#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    if (!(cin >> H >> W)) return 0;

    vector<string> grid(H);
    for (int i = 0; i < H; ++i) {
        cin >> grid[i];
    }

    vector<int> row_keep(H, 0);
    vector<int> col_keep(W, 0);

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == '#') {
                row_keep[i] = 1;
                col_keep[j] = 1;
            }
        }
    }

    for (int i = 0; i < H; ++i) {
        if (row_keep[i] == 0) continue;
        for (int j = 0; j < W; ++j) {
            if (col_keep[j] == 0) continue;
            cout << grid[i][j];
        }
        cout << "\n";
    }

    return 0;
}