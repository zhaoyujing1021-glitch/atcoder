/**
 * 【模板 02】最长连续相同字符段（longest run）
 *
 * 【用途 / 适用场景】
 *   统计字符串/序列中，某个目标值连续出现的最大长度。
 *   典型题目：最长连续 'R'、最长连续晴天、连续相同数字段等。
 *
 * 【时间与空间复杂度】
 *   时间 O(n)，额外空间 O(1)。
 *
 * 【注意事项 / 边界条件】
 *   - 空串返回 0。
 *   - 区分大小写；如果目标不区分大小写，先统一转换。
 *   - 若要求“最长连续段的值和长度”，可额外记录 best_start 或当前字符。
 *   - 若要求“最长连续子数组满足某种单调性”，不能直接套用，需要滑动窗口/双指针。
 *
 * 【来源】ABC479 B - Longest Rainy Streak
 */

#include <bits/stdc++.h>
using namespace std;

int longest_run(const string& s, char target) {
    int best = 0;
    int cur = 0;
    for (char c : s) {
        if (c == target) {
            ++cur;
            best = max(best, cur);
        } else {
            cur = 0;
        }
    }
    return best;
}

// 泛化版本：对任意可比较类型使用
template <class T>
int longest_run_generic(const vector<T>& a, const T& target) {
    int best = 0;
    int cur = 0;
    for (const T& x : a) {
        if (x == target) {
            ++cur;
            best = max(best, cur);
        } else {
            cur = 0;
        }
    }
    return best;
}
