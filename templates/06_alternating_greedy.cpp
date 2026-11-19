/**
 * 【模板 06】交替取数最优（排序后轮流取最大）
 *
 * 【用途 / 适用场景】
 *   两人轮流从一堆数中取数，每次可取任意剩余元素，双方都希望自己的
 *   总和最大。求先手总分、后手总分或二者之差。
 *   典型题目：Card Game for Two、轮流拿石子/卡片、双方贪心取最大。
 *
 * 【时间与空间复杂度】
 *   时间 O(n log n)，额外空间 O(1)（若允许修改传入数组）。
 *   若不想修改原数组，需要 O(n) 拷贝。
 *
 * 【注意事项 / 边界条件】
 *   - 元素允许为负数；排序后奇偶位相减仍然成立。
 *   - 若规则是“每次只能从两端取”，不能用本模板，需要区间 DP。
 *   - 若规则是“每次只能取固定数量”或“有取数上限”，也不是本模型。
 *   - 返回差值可能为负，使用 long long。
 *
 * 【来源】ABC088 B - Card Game for Two
 */

#include <bits/stdc++.h>
using namespace std;

// 返回 {先手总分, 后手总分}
pair<long long, long long> alternating_pick_scores(vector<long long> a) {
    sort(a.begin(), a.end(), greater<long long>());

    long long first = 0, second = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        if (i % 2 == 0) {
            first += a[i];
        } else {
            second += a[i];
        }
    }
    return {first, second};
}

long long alternating_pick_difference(vector<long long> a) {
    auto [first, second] = alternating_pick_scores(std::move(a));
    return first - second;
}
