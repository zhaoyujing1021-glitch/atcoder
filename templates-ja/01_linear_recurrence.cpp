/**
 * 【テンプレート 01】2階線形漸化式（Fibonacci / Lucas 型）
 *
 * 【用途 / 適用場面】
 *   f(0) = f0, f(1) = f1, f(i) = f(i-1) + f(i-2) を満たす数列の第 n 項を求める。
 *   典型的な問題：Fibonacci 数、Lucas 数、階段の上り方の数、ウサギの繁殖など。
 *
 * 【時間・空間計算量】
 *   時間 O(n)、追加空間 O(1)。
 *
 * 【注意事項 / 境界条件】
 *   - n = 0 または n = 1 のときは初期値を直接返す。ループに入れてはいけない。
 *   - long long はおよそ F(92) までしか格納できない。n がそれより大きい場合は
 *     剰余版か __int128 を使う。
 *   - n が非常に大きい場合（例：1e18）は本テンプレートの対象外で、
 *     行列累乗が必要になる。
 *   - 剰余版は mod > 0 を要求する。mod が 1e18 に近いと (a + b) が
 *     オーバーフローする可能性があるため、事前に判定するか __int128 を使う。
 *   - 漸化式が f(i) = p*f(i-1) + q*f(i-2) の場合は、cur を
 *     p*prev1 + q*prev2 に変更し、乗算のオーバーフローに注意する。
 *
 * 【出典】ABC079 B - Lucas Number
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

// 使用例（Lucas 数：L(0)=2, L(1)=1）：
// long long ans = linear_recurrence_2(n, 2, 1);
