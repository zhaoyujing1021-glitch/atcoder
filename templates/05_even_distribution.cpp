/**
 * 【模板 05】商余均分（把 total 尽量平均地分给 groups 组）
 *
 * 【用途 / 适用场景】
 *   把 total 个物品分给 groups 个组，要求任意两组数量之差不超过 1。
 *   典型题目：分葡萄、按行分配、均摊负载、页码分配等。
 *
 * 【时间与空间复杂度】
 *   时间 O(groups)，额外空间 O(groups)（返回值本身）。
 *
 * 【注意事项 / 边界条件】
 *   - groups 必须 > 0；total 可以为负（使用向下取整语义）。
 *   - 前 total % groups 组多拿 1 个，其余组少拿 1 个。
 *   - 若题目要求“多出来的给后几组”，把 i < r 改成 i >= groups - r。
 *   - 只返回每组的数量；若需要具体分配方案，可在同一循环里生成。
 *   - total 很大时注意 long long。
 *
 * 【来源】ABC478 A - Grapes
 */

#include <bits/stdc++.h>
using namespace std;

vector<long long> distribute_evenly(long long total, int groups) {
    assert(groups > 0);

    // C++ 的 / 和 % 向 0 截断；这里先规范化为向下取整。
    long long q = total / groups;
    long long r = total % groups;
    if (r < 0) {
        r += groups;
        --q;
    }

    vector<long long> res(groups, q);
    for (int i = 0; i < (int)r; ++i) ++res[i];
    return res;
}

// 用法：auto cnt = distribute_evenly(b, a);  // 第 i 组得到 cnt[i] 个
