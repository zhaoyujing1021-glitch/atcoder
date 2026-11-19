/**
 * 【模板 01】二阶线性递推（Fibonacci / Lucas 型）
 *
 * 【用途 / 适用场景】
 *   求满足 f(0) = f0, f(1) = f1, f(i) = f(i-1) + f(i-2) 的数列第 n 项。
 *   典型题目：Fibonacci 数、Lucas 数、爬楼梯方案数、兔子繁殖等。
 *
 * 【时间与空间复杂度】
 *   时间 O(n)，额外空间 O(1)。
 *
 * 【注意事项 / 边界条件】
 *   - n = 0 或 n = 1 时必须直接返回初值，不能进入循环。
 *   - long long 大约只能存到 F(92)；n 更大时请使用取模版本或 __int128。
 *   - n 极大（如 1e18）时本模板不适用，需要矩阵快速幂。
 *   - 取模版本要求 mod > 0；mod 接近 1e18 时 (a + b) 仍可能溢出，
 *     此时应先判断或使用 __int128。
 *   - 若递推式是 f(i) = p*f(i-1) + q*f(i-2)，只需把 cur 改成
 *     p*prev1 + q*prev2，并注意乘法溢出。
 *
 * 【来源】ABC079 B - Lucas Number
 */

#include <bits/stdc++.h>
using namespace std;

long long linear_recurrence_2(long long n, long long f0, long long f1) {
    if (n <= 0) return f0;
    if (n == 1) return f1;

    long long prev2 = f0;  // f(i-2)
    long long prev1 = f1;  // f(i-1)
    for (long long i = 2; i <= n; ++i) {
        long long cur = prev2 + prev1;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

long long linear_recurrence_2_mod(long long n, long long f0, long long f1,
                                  long long mod) {
    auto norm = [mod](long long x) {
        x %= mod;
        return x < 0 ? x + mod : x;
    };
    f0 = norm(f0);
    f1 = norm(f1);

    if (n <= 0) return f0;
    if (n == 1) return f1;

    long long prev2 = f0;
    long long prev1 = f1;
    for (long long i = 2; i <= n; ++i) {
        long long cur = (prev2 + prev1) % mod;
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

// 用法示例（Lucas 数：L(0)=2, L(1)=1）：
// long long ans = linear_recurrence_2(n, 2, 1);
