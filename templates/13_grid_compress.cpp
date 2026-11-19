/**
 * 【模板 13】网格去空行 / 空列（grid compression）
 *
 * 【用途 / 适用场景】
 *   删除网格中“没有任何目标标记”的整行和整列，并保持其余行列的相对顺序。
 *   典型题目：Grid Compression、稀疏矩阵压缩、只保留有内容的行列。
 *
 * 【时间与空间复杂度】
 *   时间 O(H * W)，额外空间 O(H + W)（不含输出）。
 *
 * 【注意事项 / 边界条件】
 *   - 网格必须为矩形；若各行长度不一致，需要先补齐或改用其他结构。
 *   - 空网格返回空；若所有行/列都没有目标标记，返回空。
 *   - 目标标记默认 '#'，可按题目改为 'o'、'1' 等。
 *   - 列压缩后每行长度相同；若原网格宽度为 0，直接返回空。
 *   - 若需要原地压缩，可先删列再删行，但 string 删除是 O(W)，整体仍 O(HW)。
 *
 * 【来源】ABC107 B - Grid Compression
 */

#include <bits/stdc++.h>
using namespace std;

vector<string> remove_empty_rows_cols(const vector<string>& grid,
                                     char mark = '#') {
    int h = (int)grid.size();
    if (h == 0) return {};
    int w = (int)grid[0].size();
    if (w == 0) return {};

    vector<char> row_has(h, 0), col_has(w, 0);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid[i][j] == mark) {
                row_has[i] = 1;
                col_has[j] = 1;
            }
        }
    }

    vector<string> res;
    for (int i = 0; i < h; ++i) {
        if (!row_has[i]) continue;
        string line;
        line.reserve(w);
        for (int j = 0; j < w; ++j) {
            if (col_has[j]) line.push_back(grid[i][j]);
        }
        res.push_back(std::move(line));
    }
    return res;
}
