/**
 * 【模板 04】在线维护第 k 大（去重）
 *
 * 【用途 / 适用场景】
 *   逐个加入元素，随时查询当前“第 k 大的不同值”。
 *   典型题目：每次读入一个数后输出当前第三大值（不存在则不输出）。
 *
 * 【时间与空间复杂度】
 *   每次 add：O(log k)；查询 O(1)；额外空间 O(k)。
 *   整体 O(n log k)。
 *
 * 【注意事项 / 边界条件】
 *   - 相同值只算一次（去重）。若题目要求“不去重的第 k 大”，
 *     应改用 multiset 或按频次计数。
 *   - 当前不同值不足 k 个时 has_kth() 为 false，不能调用 kth_largest()。
 *   - k <= 0 时 add 为空操作，has_kth() 永远为 false。
 *   - 只保留最大的 k 个值：新值较小时会被立即丢弃，适合流式数据。
 *   - 若需要第 k 小，把 set 的比较方向反过来，或查询 rbegin。
 *
 * 【来源】ABC476 C - Third Largest Number
 */

#include <bits/stdc++.h>
using namespace std;

class TopKDistinct {
  public:
    explicit TopKDistinct(int k) : k_(k) {}

    void add(long long x) {
        if (k_ <= 0) return;
        if (values_.count(x)) return;  // 去重
        values_.insert(x);
        if ((int)values_.size() > k_) {
            values_.erase(values_.begin());  // 丢掉最小值
        }
    }

    bool has_kth() const { return (int)values_.size() == k_; }

    // 前置条件：has_kth() 为 true
    long long kth_largest() const { return *values_.begin(); }

    // 从大到小返回当前保留的至多 k 个值
    vector<long long> values_desc() const {
        return vector<long long>(values_.rbegin(), values_.rend());
    }

  private:
    int k_;
    set<long long> values_;
};

// 一次性版本：直接求整个数组的第 k 大不同值，不存在返回 false。
bool kth_largest_distinct(const vector<long long>& a, int k, long long& out) {
    TopKDistinct top(k);
    for (long long x : a) top.add(x);
    if (!top.has_kth()) return false;
    out = top.kth_largest();
    return true;
}
