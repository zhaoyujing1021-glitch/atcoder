# AtCoder 算法模板库

## 0. 总览

- 原始代码：**51 份**（`.cpp` 与 `.c` 混放，均已 AC）。
- 整理结果：**18 个可复用模板**，由其中 **21 份**代码归纳/合并而来。
- 其余 **30 份**属于入门语法、A 题特判或题目特定暴力/模拟，统一记录在
  [`NOT_TEMPLATES.md`](./NOT_TEMPLATES.md)，不强行抽象成模板。
- 所有模板统一为 **C++17**，使用 `#include <bits/stdc++.h>`（AtCoder 的
  GCC 环境可直接使用；若需跨编译器，请替换为标准头文件）。
- 每个模板文件顶部都写明了【用途 / 适用场景】【时间与空间复杂度】
  【注意事项 / 边界条件】，并标注来源题目。

> 约定：除特别说明外，下标均为 **0-based**；若题目输入是 1-based，
> 读入后统一减 1（模板 10 额外提供了 1-based 版本）。
> “空间”列默认不含输入/输出本身占用的内存。

---

## 1. 按用途快速查找

| 如果你的题目是…… | 使用模板 |
|---|---|
| 求 Fibonacci / Lucas / 递推数列第 n 项 | [01 二阶线性递推](#01) |
| 最长连续 `'R'`、最长连续相同字符 | [02 最长连续段](#02) |
| 统计种类数、众数、出现奇数次的元素和 | [03 频次统计](#03) |
| 每次加入一个数，查询当前第 k 大（去重） | [04 在线第 k 大](#04) |
| 把总数尽量平均地分给若干组 | [05 商余均分](#05) |
| 两人轮流取数、双方都取最大、求得分差 | [06 交替取数最优](#06) |
| h-index、“至少有 h 篇论文引用 >= h” | [07 h 指数](#07) |
| 多关键字排序、排行榜、输出原编号 | [08 多关键字排序](#08) |
| 只排序一段子数组能否使整个数组有序 | [09 最小排序区间](#09) |
| 统计每个点的度数 / 每个点连几条边 | [10 无向图度数](#10) |
| 求树上每个节点的子树大小 | [11 子树大小](#11) |
| 构造 n×n 的关系矩阵 / 对战表 | [12 关系矩阵](#12) |
| 删除网格中的空行、空列 | [13 网格压缩](#13) |
| 给网格四周加一圈边框 | [14 网格加边框](#14) |
| 逐位匹配，`'*'` 匹配任意一个字符 | [15 单字符通配符](#15) |
| 找与左右邻居距离都 >= d 的“孤立点” | [16 孤立点筛选](#16) |
| 统计折线穿越水平线的次数 | [17 折线穿越计数](#17) |
| 统计两数之和等于 target 的配对数 | [18 配对和为定值](#18) |

---

## 2. 汇总目录

### 2.1 序列、递推与统计

| 编号 | 模板文件 | 用途 | 时间 | 空间 | 来源 |
|---|---|---|---|---|---|
| <a id="01"></a>01 | [`01_linear_recurrence.cpp`](./01_linear_recurrence.cpp) | 二阶线性递推（Fibonacci/Lucas 型）第 n 项，含取模版 | O(n) | O(1) | ABC079 B |
| <a id="02"></a>02 | [`02_longest_run.cpp`](./02_longest_run.cpp) | 最长连续相同字符段 | O(n) | O(1) | ABC479 B |
| <a id="03"></a>03 | [`03_frequency_stats.cpp`](./03_frequency_stats.cpp) | 去重计数 / 众数 / 奇频次元素求和 | 期望 O(n) | O(n) | ABC085 B、ABC473 B、APG4B EX23 |
| <a id="04"></a>04 | [`04_top_k_distinct.cpp`](./04_top_k_distinct.cpp) | 在线维护第 k 大（去重） | 每次 O(log k) | O(k) | ABC476 C |
| <a id="05"></a>05 | [`05_even_distribution.cpp`](./05_even_distribution.cpp) | 商余均分，任意两组差不超过 1 | O(groups) | O(groups) | ABC478 A |
| <a id="06"></a>06 | [`06_alternating_greedy.cpp`](./06_alternating_greedy.cpp) | 交替取数最优，返回双方总分/差值 | O(n log n) | O(1) | ABC088 B |
| <a id="07"></a>07 | [`07_h_index.cpp`](./07_h_index.cpp) | h-index | O(n log n) | O(1) | ABC409 B |
| <a id="18"></a>18 | [`18_pair_sum_count.cpp`](./18_pair_sum_count.cpp) | 两数组/单数组配对和为定值的计数 | 期望 O(n + m) | O(m) | APG4B EX17（原为 O(N²) 暴力，已升级） |

### 2.2 排序、区间与阈值

| 编号 | 模板文件 | 用途 | 时间 | 空间 | 来源 |
|---|---|---|---|---|---|
| <a id="08"></a>08 | [`08_multikey_sort.cpp`](./08_multikey_sort.cpp) | 多关键字排序，保留原下标 | O(n log n) | O(1) | ABC128 B、APG4B EX22 |
| <a id="09"></a>09 | [`09_min_sort_interval.cpp`](./09_min_sort_interval.cpp) | 最小需要排序的连续区间 / 长度 <= k 判定 | O(n log n) | O(n) | ABC478 C |
| <a id="16"></a>16 | [`16_isolated_points.cpp`](./16_isolated_points.cpp) | 排序后筛选“与最近邻距离 >= d”的点 | O(n log n) | O(n) | ABC477 B |
| <a id="17"></a>17 | [`17_level_crossing.cpp`](./17_level_crossing.cpp) | 折线穿越水平线的次数 | O(n) | O(1) | ABC481 B |

### 2.3 图与树

| 编号 | 模板文件 | 用途 | 时间 | 空间 | 来源 |
|---|---|---|---|---|---|
| <a id="10"></a>10 | [`10_degree_count.cpp`](./10_degree_count.cpp) | 无向图度数统计（0-based / 1-based） | O(n + m) | O(n) | ABC061 B |
| <a id="11"></a>11 | [`11_subtree_size.cpp`](./11_subtree_size.cpp) | 树上子树大小，迭代 DFS 防爆栈 | O(n) | O(n) | APG4B EX20 |
| <a id="12"></a>12 | [`12_adjacency_matrix.cpp`](./12_adjacency_matrix.cpp) | 有向关系矩阵（`o` / `x` / `-`） | O(n² + m) | O(n²) | APG4B EX18 |

### 2.4 网格与字符串

| 编号 | 模板文件 | 用途 | 时间 | 空间 | 来源 |
|---|---|---|---|---|---|
| <a id="13"></a>13 | [`13_grid_compress.cpp`](./13_grid_compress.cpp) | 删除无标记的空行、空列 | O(HW) | O(H + W) | ABC107 B |
| <a id="14"></a>14 | [`14_grid_frame.cpp`](./14_grid_frame.cpp) | 给网格加一圈边框 | O(HW) | O(HW) | ABC062 B |
| <a id="15"></a>15 | [`15_single_wildcard_match.cpp`](./15_single_wildcard_match.cpp) | 单字符通配符逐位匹配 | O(n) | O(1) | ABC476 B |

---

## 3. 使用方式

每个 `.cpp` 都是**可直接复制进题解的独立函数/结构体**，没有 `main()`，
也不会读取输入。典型用法：

```cpp
#include <bits/stdc++.h>
using namespace std;

// 把模板文件中的函数/结构体粘贴到这里

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (auto& x : a) cin >> x;

    long long ans = sum_values_with_odd_frequency(a);  // 以模板 03 为例
    cout << ans << '\n';
}
```

### 编译检查

本目录下所有模板已用 GCC 14.2（`-std=c++17 -Wall -Wextra`）做过语法编译检查：

```powershell
Get-ChildItem templates\*.cpp | ForEach-Object {
    g++ -std=c++17 -Wall -Wextra -c $_.FullName -o "$env:TEMP\template_check.o"
}
```

> 在 Bash 下可改为：
> `for f in templates/*.cpp; do g++ -std=c++17 -Wall -Wextra -c "$f" -o /dev/null || break; done`

---

## 4. 通用注意事项

1. **溢出**：涉及累加、乘积、方案数时优先 `long long`；模数接近
   `1e18` 时加法也可能溢出，必要时用 `__int128`。
2. **下标**：模板默认 0-based。题目输入 1-based 时，读入后减 1；
   输出原始编号时记得加回 1。
3. **哈希复杂度**：`unordered_map` / `unordered_set` 是期望 O(1)，
   最坏 O(n)。需要严格最坏保证时改用 `map` / `set`（多一个 log）。
4. **递归深度**：模板 11 已改为显式栈；其他递归解法在 n 较大时要注意
   栈溢出，必要时改迭代或手动扩栈。
5. **比较器**：多关键字排序的比较器必须满足严格弱序，相等时返回
   `false`，并写完整的 tie-break。
6. **空输入**：所有模板都处理了空数组/空串；但调用前仍应确认题目是否
   保证 n >= 1。
7. **题意差异**：模板只覆盖“这一类”模型。例如模板 06 是“任意取数”，
   不是“只能从两端取”；模板 15 的 `'*'` 只匹配一个字符，不是 glob。
   使用前先确认规则一致。

---

## 5. 未纳入模板的代码

以下 30 份代码没有通用模板价值，已按“入门语法 / A 题特判 /
题目特定暴力或模拟”分类说明，并给出可借鉴点：

- [`NOT_TEMPLATES.md`](./NOT_TEMPLATES.md)

其中特别标注了两份“看似可模板化、实则题目特定”的代码：

- **ABC478 B - Topping**：三重循环 O(N³) 暴力，依赖 N 很小的约束。
- **ABC483 B - Flip Card Stack**：前缀取反 + 前缀翻转的朴素模拟，
  单次 O(k)，总 O(nq)；大规模数据需要隐式 Treap 等数据结构。
