/**
 * 【模板 18】两数组配对和为定值（哈希表 O(n + m)）
 *
 * 【用途 / 适用场景】
 *   给定两个数组 A、B，统计有多少对 (x, y)（x 来自 A，y 来自 B）
 *   满足 x + y = target。重复元素按出现次数计重。
 *   典型题目：两数之和计数、配对方案数、A+B 问题。
 *
 * 【时间与空间复杂度】
 *   期望 O(n + m) 时间，O(m) 额外空间。
 *   最坏情况（哈希冲突）O(n * m)，需要严格保证时改用排序 + 双指针。
 *
 * 【注意事项 / 边界条件】
 *   - 统计的是“有序对”（先选 A 再选 B），不是同一数组内的无序对。
 *   - 重复元素按多重集计数：A 中两个相同值会分别与 B 中每个匹配值配对。
 *   - 结果可能达到 n*m，使用 long long。
 *   - target - x 可能溢出 long long；极端值范围下改用 __int128 或排序法。
 *   - 若要在同一个数组内统计 i < j 的对数，不能直接套用；
 *     应边遍历边查询（先查后插），并注意 target 为偶数时不要重复计数。
 *   - 若只需要判断是否存在，找到第一对即可提前返回。
 *
 * 【来源】APG4B EX17 - 2.02
 *   原代码是 O(N^2) 的暴力枚举；本模板给出等价的通用 O(N + M) 版本。
 */

#include <bits/stdc++.h>
using namespace std;

long long count_pairs_with_sum(const vector<long long>& a,
                               const vector<long long>& b,
                               long long target) {
    unordered_map<long long, long long> freq;
    freq.reserve(b.size() * 2 + 1);
    for (long long y : b) ++freq[y];

    long long ans = 0;
    for (long long x : a) {
        auto it = freq.find(target - x);
        if (it != freq.end()) ans += it->second;
    }
    return ans;
}

// 同一数组内统计 i < j 且 a[i] + a[j] = target 的对数。
long long count_pairs_in_one_array(const vector<long long>& a,
                                   long long target) {
    unordered_map<long long, long long> seen;
    seen.reserve(a.size() * 2 + 1);

    long long ans = 0;
    for (long long x : a) {
        auto it = seen.find(target - x);
        if (it != seen.end()) ans += it->second;
        ++seen[x];
    }
    return ans;
}
