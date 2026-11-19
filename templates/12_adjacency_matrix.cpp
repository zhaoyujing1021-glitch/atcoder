/**
 * 【模板 12】有向关系矩阵（邻接矩阵 / 胜负表）
 *
 * 【用途 / 适用场景】
 *   给定若干有序对 (u, v)，构造 n x n 的关系矩阵：
 *   mat[u][v] = 'o'，mat[v][u] = 'x'，其余为 '-'。
 *   典型题目：对战表、单向关系表、图的双向标记、矩阵形式的邻接关系。
 *
 * 【时间与空间复杂度】
 *   构造 O(n^2 + m) 时间，O(n^2) 空间。
 *
 * 【注意事项 / 边界条件】
 *   - n 较大（> 5000）时 O(n^2) 内存会爆；应改用邻接表。
 *   - 同一对点若同时给出 (u,v) 和 (v,u)，后写入会覆盖先写入；
 *     若题目保证每对只有一条有向边则无需处理。
 *   - 自环 (u,u) 会先写 'o' 再写 'x'，最终为 'x'；如需特殊处理请单独判断。
 *   - 输入通常是 1-based，记得先减 1。
 *   - 字符矩阵比 int 矩阵省内存；若需要权值，把 char 换成 int 并初始化 INF。
 *
 * 【来源】APG4B EX18 - 2.03
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

// 用法（输入为 1-based 时）：
// vector<pair<int,int>> edges;
// for (int i = 0; i < m; ++i) { int a, b; cin >> a >> b; edges.push_back({a-1, b-1}); }
// auto mat = build_adjacency_matrix(n, edges);
