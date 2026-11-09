#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >>n;
  vector<int> vec(n);
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  sort(vec.rbegin(), vec.rend());
  
  int alice_score = 0;
    int bob_score = 0;
    
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            alice_score += vec[i];
        } else {
            bob_score += vec[i];
        }
    }
    
    cout << alice_score - bob_score << endl;
  return 0;
}

