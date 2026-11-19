/**
 * 【模板 03】频次统计三件套（去重计数 / 众数 / 奇频次求和）
 *
 * 【用途 / 适用场景】
 *   1) 统计不同元素个数（去重）；
 *   2) 求出现次数最多的元素（众数），并指定平局规则；
 *   3) 对所有出现奇数次的元素值求和。
 *   典型题目：镜饼种类数、Old Maid、最频繁值等。
 *
 * 【时间与空间复杂度】
 *   三个函数均为期望 O(n) 时间、O(n) 额外空间
 *   （unordered_map / unordered_set 的最坏情况为 O(n^2)，
 *     需要严格最坏保证时改用 map / set，时间变为 O(n log n)）。
 *
 * 【注意事项 / 边界条件】
 *   - 输入为空时：count_distinct 返回 0；mode 返回 false；
 *     sum_odd 返回 0。
 *   - 众数平局规则：本实现返回“最早达到最大频次的值”，
 *     即按首次出现的顺序决定，而不是值的大小。
 *   - 若题目要求“值最小/最大的众数”，需要在更新时额外比较值。
 *   - sum_odd 的结果可能超过 int，使用 long long。
 *   - 自定义 key 为 long long / string 时可直接替换模板参数。
 *
 * 【来源】
 *   ABC085 B - Kagami Mochi（去重计数）
 *   ABC473 B - Old Maid（奇频次求和）
 *   APG4B EX23 - 3.03（众数）
 */

#include <bits/stdc++.h>
using namespace std;

int count_distinct(const vector<long long>& a) {
    unordered_set<long long> seen;
    seen.reserve(a.size() * 2 + 1);
    for (long long x : a) seen.insert(x);
    return (int)seen.size();
}

// 返回 false 表示输入为空；否则通过 mode_value / mode_count 返回结果。
bool mode_first_occurrence(const vector<long long>& a,
                           long long& mode_value,
                           int& mode_count) {
    if (a.empty()) return false;

    unordered_map<long long, int> cnt;
    cnt.reserve(a.size() * 2 + 1);

    int best_cnt = 0;
    long long best_value = 0;
    for (long long x : a) {
        int c = ++cnt[x];
        // 只有严格大于才更新，因此平局时保留最早达到该频次的值。
        if (c > best_cnt) {
            best_cnt = c;
            best_value = x;
        }
    }

    mode_value = best_value;
    mode_count = best_cnt;
    return true;
}

long long sum_values_with_odd_frequency(const vector<long long>& a) {
    unordered_map<long long, int> cnt;
    cnt.reserve(a.size() * 2 + 1);
    for (long long x : a) ++cnt[x];

    long long sum = 0;
    for (const auto& [value, c] : cnt) {
        if (c % 2 != 0) sum += value;
    }
    return sum;
}

// 用法：
// int kinds = count_distinct(a);
// long long mode; int freq;
// if (mode_first_occurrence(a, mode, freq)) { ... }
// long long odd_sum = sum_values_with_odd_frequency(a);
