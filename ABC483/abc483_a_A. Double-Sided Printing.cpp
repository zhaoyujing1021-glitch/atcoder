#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0;
    if (std::cin >> n) {
        if (n % 2 != 0) { 
            std::cout << n / 2 + 1 <<endl;
        } else {          
            std::cout << n / 2 <<endl;
        }
    }

    return 0;
}