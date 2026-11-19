/**
 * 【模板 17】折线穿越水平线的次数
 *
 * 【用途 / 适用场景】
 *   给定序列 a[0..n-1] 作为折线的 y 值，统计折线与水平线 y = level
 *   的“接触次数”：顶点恰好落在水平线上算一次；相邻两点分居水平线
 *   两侧（严格跨越）也算一次。
 *   典型题目：Polyline、统计经过某个阈值的次数、穿越次数。
 *
 * 【时间与空间复杂度】
 *   时间 O(n)，额外空间 O(1)。
 *
 * 【注意事项 / 边界条件】
 *   - 这是“按顶点/边计数”的约定：顶点在线上算一次，严格跨越算一次。
 *   - 若连续多个顶点都在水平线上，每个顶点都会各算一次；
 *     如果题目要求“一段平台只算一次”，需要额外合并连续等值段。
 *   - 若边恰好沿着水平线（a[i] == a[i+1] == level），本模板会算两次
 *     （两个顶点各一次），这不是几何意义上的“穿越”。
 *   - 空序列返回 0；单点序列只判断该点是否在线上。
 *   - level 与 a 的元素类型要一致，避免隐式转换。
 *
 * 【来源】ABC481 B - Polyline
 */

#include <bits/stdc++.h>
using namespace std;

int count_level_crossings(const vector<long long>& a, long long level) {
    int cnt = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        if (a[i] == level) ++cnt;  // 顶点落在水平线上

        if (i + 1 < (int)a.size()) {
            bool up_cross = (a[i] < level && a[i + 1] > level);
            bool down_cross = (a[i] > level && a[i + 1] < level);
            if (up_cross || down_cross) ++cnt;  // 严格跨越
        }
    }
    return cnt;
}
