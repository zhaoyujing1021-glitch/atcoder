/**
 * 【模板 14】给网格加一圈边框
 *
 * 【用途 / 适用场景】
 *   在 H x W 的字符网格四周各加一行/一列指定字符，形成 (H+2) x (W+2)
 *   的新网格。
 *   典型题目：Picture Frame、输出带边框的图形、棋盘/迷宫外框。
 *
 * 【时间与空间复杂度】
 *   时间 O(H * W)，额外空间 O(H * W)（返回值）。
 *
 * 【注意事项 / 边界条件】
 *   - 网格必须为矩形；空网格返回空。
 *   - 边框是单个 char；若要加多字符边框，把 string sep 改成重复字符串。
 *   - 原网格宽度为 0 时仍会得到上下边框和左右边框。
 *   - 如果只是输出而不需要保存，可以直接逐行打印，省掉 O(HW) 内存。
 *   - 边框字符不要与原网格内容冲突（若后续要做连通块等处理）。
 *
 * 【来源】ABC062 B - Picture Frame
 */

#include <bits/stdc++.h>
using namespace std;

vector<string> add_border(const vector<string>& grid, char border = '#') {
    int h = (int)grid.size();
    if (h == 0) return {};
    int w = (int)grid[0].size();

    string sep(w + 2, border);
    vector<string> res;
    res.reserve(h + 2);
    res.push_back(sep);
    for (const string& row : grid) {
        res.push_back(string(1, border) + row + string(1, border));
    }
    res.push_back(sep);
    return res;
}
