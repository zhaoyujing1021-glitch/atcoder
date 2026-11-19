/**
 * 【模板 11】树上子树大小（迭代 DFS，避免递归爆栈）
 *
 * 【用途 / 适用场景】
 *   给定一棵以 root 为根的树（用 children 邻接表表示），求每个节点的
 *   子树大小（包含自身）。
 *   典型题目：组织汇报人数、树形 DP 前置、子树查询、重心/直径辅助。
 *
 * 【时间与空间复杂度】
 *   时间 O(n)，额外空间 O(n)（order 栈 + 结果数组）。
 *
 * 【注意事项 / 边界条件】
 *   - children 必须是“有向”的父子关系（父 -> 子），不能是含父节点的
 *     无向邻接表；若是无向图，先任选根并做一次 DFS 建父子关系。
 *   - 所有节点必须从 root 可达；不可达节点的大小会保持 0。
 *   - root 必须在 [0, n) 内。
 *   - 使用显式栈而不是递归，n 可达 2e5/1e6 也不会栈溢出。
 *   - 若只需求某个子树大小，可在后序阶段提前返回，但本模板一次求全部。
 *
 * 【来源】APG4B EX20 - 2.05（组织汇报人数）
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> subtree_sizes(const vector<vector<int>>& children, int root) {
    int n = (int)children.size();
    vector<int> order;
    order.reserve(n);

    // 先做一次前序遍历，得到“父在子前”的顺序。
    vector<int> st;
    st.push_back(root);
    while (!st.empty()) {
        int v = st.back();
        st.pop_back();
        order.push_back(v);
        for (int c : children[v]) st.push_back(c);
    }

    // 逆序累加，保证处理 v 时所有子节点已经算好。
    vector<int> sz(n, 0);
    for (int i = (int)order.size() - 1; i >= 0; --i) {
        int v = order[i];
        sz[v] = 1;  // 自身
        for (int c : children[v]) sz[v] += sz[c];
    }
    return sz;
}
