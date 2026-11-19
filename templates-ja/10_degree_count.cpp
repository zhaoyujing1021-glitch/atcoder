/**
 * 【テンプレート 10】無向グラフの次数カウント
 *
 * 【用途 / 適用場面】
 *   n 頂点 m 辺の無向グラフが与えられたとき、各頂点に接続する辺の数
 *   （次数）を数える。
 *   典型的な問題：Counting Roads、握手問題、各点に何本の道がつながるか。
 *
 * 【時間・空間計算量】
 *   時間 O(n + m)、追加空間 O(n)。
 *
 * 【注意事項 / 境界条件】
 *   - 自己ループ (u, u) では ++deg[u] が 2 回実行され、次数は +2 になる。
 *     問題によって自己ループを 1 と数える場合は u == v を分岐する。
 *   - 多重辺は辺ごとに加算する。自動的な重複除去は行わない。
 *   - 0-based 版は 0 <= u, v < n を要求する。1-based 版はサイズ n+1 の
 *     配列を返し、添字 0 は使わない。
 *   - グラフが非連結でも次数の統計には影響しない。ただし「全頂点が
 *     出現すること」を要求する場合は別途判定が必要。
 *   - 次数ではなく隣接リストが必要な場合は、テンプレート 12 か
 *     vector<vector<int>> を直接使う。
 *
 * 【出典】ABC061 B - Counting Roads
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> degree_count_0based(int n, const vector<pair<int, int>>& edges) {
    vector<int> deg(n, 0);
    for (auto [u, v] : edges) {
        ++deg[u];
        ++deg[v];
    }
    return deg;
}

vector<int> degree_count_1based(int n, const vector<pair<int, int>>& edges) {
    vector<int> deg(n + 1, 0);
    for (auto [u, v] : edges) {
        ++deg[u];
        ++deg[v];
    }
    return deg;
}
