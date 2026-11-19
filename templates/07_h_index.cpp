/**
 * 【模板 07】h-index（h 指数）
 *
 * 【用途 / 适用场景】
 *   给定每篇论文的引用数，求最大的 h，使得至少有 h 篇论文的引用数 >= h。
 *   典型题目：Citation、学术评价、阈值型“至少 k 个元素 >= k”问题。
 *
 * 【时间与空间复杂度】
 *   时间 O(n log n)（排序），额外空间 O(1)（原地排序）。
 *   若引用数范围很小，可用计数排序做到 O(n)。
 *
 * 【注意事项 / 边界条件】
 *   - 引用数应为非负整数；若可能为负，排序后逻辑仍然可用，
 *     但 h 不会超过 n。
 *   - h 的范围是 0..n，空数组返回 0。
 *   - 排序后从大到小扫描：citations[i] >= i+1 时 h 至少为 i+1。
 *   - 若题目定义是“至多 h 篇 >= h”或“恰好 h 篇”，需要改写判定。
 *
 * 【来源】ABC409 B - Citation
 */

#include <bits/stdc++.h>
using namespace std;

int h_index(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());

    int h = 0;
    for (int i = 0; i < (int)citations.size(); ++i) {
        if (citations[i] >= i + 1) {
            h = i + 1;
        } else {
            break;  // 后面的引用数只会更小
        }
    }
    return h;
}
