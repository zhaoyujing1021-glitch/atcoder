#include <bits/stdc++.h>
using namespace std;

int main() {
    string str1,str2;
    cin >> str1>>str2;
    if(str1.size()<str2.size()){
      cout << str2<< endl;
    }else{
      cout << str1<< endl;
    }
    
    return 0;
}