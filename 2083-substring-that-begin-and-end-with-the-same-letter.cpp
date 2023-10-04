/**
 *    created: 04.10.2023_09:15:23
**/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/tmp/debug.h"
#else
#define debug(...) 42
#endif

#define int long long

int solve(string s){
    unordered_map<char, int> cnt;
    int res = 0;
    for(char c: s) cnt[c]++;
    for(auto [x, c]: cnt){
        res += c;
        res += c * (c - 1) / 2;
    }
    return res;
    
}
int32_t main(){
    assert(solve("abcba") == 7);
    assert(solve("abacad") == 9);
    assert(solve("a") == 1);
    return 0;
}

