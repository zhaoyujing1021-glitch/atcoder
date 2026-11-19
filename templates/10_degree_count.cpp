/**
 * 【模板 10】无向图度数统计
 *
 * 【用途 / 适用场景】
 *   给定 n 个点和 m 条无向边，统计每个点相连的边数（度数）。
 *   典型题目：Counting Roads、握手问题、判断每个点连了几条路。
 *
 * 【时间与空间复杂度】
 *   时间 O(n + m)，额外空间 O(n)。
 *
 * 【注意事项 / 边界条件】
 *   - 自环 (u, u) 会被 ++deg[u] 执行两次，度数 +2；若题目把自环算作 1，
 *     需要单独判断 u == v。
 *   - 重边按边数分别累计，不自动去重。
 *   - 0-based 版本要求 0 <= u, v < n；1-based 版本返回大小为 n+1 的数组，
 *     下标 0 不使用。
 *   - 若图可能不连通，不影响度数统计；但若要求“每个点都出现”，要额外判断。
 *   - 若需要邻接表而不是度数，见模板 12 或直接 vector<vector<int>>。
 *
 * 【来源】ABC061 B - Counting Roads
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
