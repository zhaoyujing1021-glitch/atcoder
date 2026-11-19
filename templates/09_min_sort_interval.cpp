/**
 * 【模板 09】使数组有序所需的最小连续区间
 *
 * 【用途 / 适用场景】
 *   判断“只对一段连续子数组排序”能否让整个数组有序，并求出最小需要
 *   排序的区间长度。也可用于回答“长度不超过 k 的子数组排序后能否有序”。
 *   典型题目：Sort Subarray、最小排序区间、几乎有序数组判定。
 *
 * 【时间与空间复杂度】
 *   时间 O(n log n)（排序），额外空间 O(n)（保存有序副本）。
 *
 * 【注意事项 / 边界条件】
 *   - 数组已经有序时返回 {-1, -1}，长度为 0。
 *   - 重复元素不影响结论：比较的是值与排序后的副本。
 *   - 结论成立的原因：区间外 a[i] == sorted[i]，因此区间内的多重集
 *     与排序后一致，直接排序该区间即可。
 *   - k 为允许排序的最大长度；k >= 0。k = 0 时只有原数组已有序才为 true。
 *   - 若题目允许“交换任意两个元素”而不是“排序一个子数组”，模型不同。
 *
 * 【来源】ABC478 C - Sort Subarray
 */

#include <bits/stdc++.h>
using namespace std;

// 返回 {l, r}：最小需要排序的闭区间；已有序时返回 {-1, -1}。
pair<int, int> min_sort_interval(const vector<long long>& a) {
    int n = (int)a.size();
    vector<long long> sorted_a = a;
    sort(sorted_a.begin(), sorted_a.end());

    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] != sorted_a[i]) {
            if (l == -1) l = i;
            r = i;
        }
    }
    return {l, r};
}

bool can_sort_with_one_subarray(const vector<long long>& a, int k) {
    auto [l, r] = min_sort_interval(a);
    if (l == -1) return true;              // 已经有序
    return (r - l + 1) <= k;
}
