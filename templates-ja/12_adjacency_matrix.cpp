/**
 * 【テンプレート 12】有向関係の行列（隣接行列 / 勝敗表）
 *
 * 【用途 / 適用場面】
 *   複数の順序対 (u, v) が与えられたとき、n x n の関係行列を構築する：
 *   mat[u][v] = 'o'、mat[v][u] = 'x'、それ以外は '-'。
 *   典型的な問題：対戦表、片方向の関係表、グラフの双方向マーク、
 *   行列形式の隣接関係。
 *
 * 【時間・空間計算量】
 *   構築 O(n^2 + m) 時間、O(n^2) 空間。
 *
 * 【注意事項 / 境界条件】
 *   - n が大きい（5000 超）と O(n^2) のメモリで破綻する。隣接リストを使う。
 *   - 同じペアに (u, v) と (v, u) の両方が与えられた場合、後から書いた
 *     方が優先される。問題が各ペア 1 方向だけを保証するなら処理不要。
 *   - 自己ループ (u, u) は 'o' の後に 'x' を書くため、最終的に 'x' になる。
 *     特別扱いが必要なら個別に分岐する。
 *   - 入力は通常 1-based なので、先に 1 を引く。
 *   - 文字行列は int 行列よりメモリ効率がよい。重みが必要な場合は
 *     char を int に変え、INF で初期化する。
 *
 * 【出典】APG4B EX18 - 2.03
 */

#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> build_adjacency_matrix(
    int n, const vector<pair<int, int>>& directed_edges) {
    vector<vector<char>> mat(n, vector<char>(n, '-'));
    for (auto [u, v] : directed_edges) {
        mat[u][v] = 'o';
        mat[v][u] = 'x';
    }
    return mat;
}

// 使用例（入力が 1-based の場合）：
// vector<pair<int,int>> edges;
// for (int i = 0; i < m; ++i) { int a, b; cin >> a >> b; edges.push_back({a-1, b-1}); }
// auto mat = build_adjacency_matrix(n, edges);
