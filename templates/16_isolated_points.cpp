/**
 * 【模板 16】排序后筛选“孤立点”（与最近邻距离 >= d）
 *
 * 【用途 / 适用场景】
 *   给定数轴上的 n 个点及其原始编号，找出所有与左右相邻点的距离都
 *   不小于 d 的点，并按原始编号升序输出。
 *   典型题目：Standing Outliers、异常点检测、稀疏点筛选。
 *
 * 【时间与空间复杂度】
 *   时间 O(n log n)（排序 + 结果排序），额外空间 O(n)。
 *
 * 【注意事项 / 边界条件】
 *   - 只与排序后的直接左右邻居比较；若题目要求“与任意点距离 >= d”，
 *     结论等价（最近点一定是相邻点）。
 *   - 端点只有一个邻居，只需检查存在的那一侧。
 *   - 距离严格小于 d 才判定为“不孤立”；距离恰好等于 d 仍算孤立。
 *   - 重复点距离为 0，若 d > 0 会互相排除；d = 0 时所有点都满足。
 *   - 返回的是 0-based 原始下标；题目要求 1-based 时统一 +1。
 *   - 若只需要个数而不需要编号，可省掉最后一次排序。
 *
 * 【来源】ABC477 B - Standing Outliers
 */

#include <bits/stdc++.h>
using namespace std;

vector<int> isolated_point_ids(const vector<long long>& x, long long d) {
    int n = (int)x.size();
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {
        if (x[i] != x[j]) return x[i] < x[j];
        return i < j;  // 相同值时按原下标，保证确定性
    });

    vector<int> res;
    for (int k = 0; k < n; ++k) {
        int i = ord[k];
        bool ok = true;
        if (k > 0 && x[i] - x[ord[k - 1]] < d) ok = false;
        if (k + 1 < n && x[ord[k + 1]] - x[i] < d) ok = false;
        if (ok) res.push_back(i);
    }

    sort(res.begin(), res.end());  // 按原始编号输出
    return res;
}
