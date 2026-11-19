/**
 * 【模板 15】单字符通配符匹配（'*' 恰好匹配一个字符）
 *
 * 【用途 / 适用场景】
 *   判断两个等长字符串是否逐位匹配，其中模式串的 '*' 可以匹配任意一个
 *   字符，其他位置必须完全相同。
 *   典型题目：Wild Card、简单密码匹配、掩码匹配。
 *
 * 【时间与空间复杂度】
 *   时间 O(n)，额外空间 O(1)。
 *
 * 【注意事项 / 边界条件】
 *   - 长度必须相等；长度不同直接返回 false。
 *   - '*' 只匹配一个字符，不能匹配 0 个或多个字符；这不是 glob/regex。
 *   - 若模式串本身可能包含转义字符，需要额外的转义规则。
 *   - 区分大小写；若题目不区分，先把两边转成同一大小写。
 *   - 若 '*' 需要匹配任意长度（包括空串），应使用双指针贪心或 DP。
 *
 * 【来源】ABC476 B - Wild Card
 */

#include <bits/stdc++.h>
using namespace std;

bool match_single_wildcard(const string& s, const string& pattern,
                           char wildcard = '*') {
    if (s.size() != pattern.size()) return false;
    for (size_t i = 0; i < s.size(); ++i) {
        if (pattern[i] != wildcard && pattern[i] != s[i]) return false;
    }
    return true;
}
