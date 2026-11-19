/**
 * 【模板 08】多关键字排序（保留原下标 / 稳定输出）
 *
 * 【用途 / 适用场景】
 *   按多个字段排序，并输出原始编号；或按“第二关键字、第一关键字”
 *   的优先级排序。
 *   典型题目：Guidebook（城市升序、分数降序、输出原编号）、
 *             排行榜、成绩表、按多个属性排序的记录。
 *
 * 【时间与空间复杂度】
 *   时间 O(n log n)，额外空间 O(1)（std::sort 的栈空间 O(log n)）。
 *
 * 【注意事项 / 边界条件】
 *   - 比较函数必须满足严格弱序：不能出现 a<b 和 b<a 同时为 true，
 *     相等时必须返回 false。
 *   - 多关键字排序一定要写完整的 tie-break（如 id 升序），
 *     否则相等元素的相对顺序未定义。
 *   - string 的 < 是按字节/字典序比较；需要自然数序（"2" < "10"）
 *     时要自定义比较。
 *   - 输出原编号时注意题目是 1-based 还是 0-based。
 *   - 若排序后还要去重，先排序再 unique，不要用 set 破坏原有下标。
 *
 * 【来源】
 *   ABC128 B - Guidebook
 *   APG4B EX22 - 3.02（按 pair 的第二关键字排序）
 */

#include <bits/stdc++.h>
using namespace std;

struct Record {
    string key1;  // 第一关键字：升序
    int key2;     // 第二关键字：降序
    int id;       // 原始下标（0-based）
};

void sort_records(vector<Record>& records) {
    sort(records.begin(), records.end(),
         [](const Record& a, const Record& b) {
             if (a.key1 != b.key1) return a.key1 < b.key1;   // 1st: 升序
             if (a.key2 != b.key2) return a.key2 > b.key2;   // 2nd: 降序
             return a.id < b.id;                             // tie-break
         });
}

// 用法：
// vector<Record> r(n);
// for (int i = 0; i < n; ++i) { cin >> r[i].key1 >> r[i].key2; r[i].id = i; }
// sort_records(r);
// for (auto& e : r) cout << e.id + 1 << '\n';  // 题目要求 1-based 时 +1
