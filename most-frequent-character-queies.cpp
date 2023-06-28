#include <bits/stdc++.h>

using namespace std;

//debug
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#define int long long

void test_case(){
	string s; cin>>s;
	int n = s.size();
	vector<vector<int>> prefix(26, vector<int>(n));
	for(int i = 0; i < 26; i++){
		vector<int> tmp(n);
		for(int j = 0; j < n; j++){
			if(s[j] - 'a' == i){
				tmp[j] = 1;
			}
		}
		prefix[i][0] = tmp[0];
		for(int j = 1; j < n; j++){
			prefix[i][j] = prefix[i][j - 1] + tmp[j];
		}
	}
	auto get = [](const vector<int>& pref, int l, int r){
		return (l == 0 ? pref[r] : pref[r] - pref[l - 1]);
	};
	int Q; cin>>Q;
	for(int i = 0; i < Q; i++){
		int l, r; cin>>l>>r;
		int best_freq = 0;
		int char_index = 0;
		for(int j = 0; j < 26; j++){
			int freq = get(prefix[j], l, r);
			if(freq > best_freq){
				best_freq = freq;
				char_index = j;
			}	
		}
		cout<<char(char_index + 'a')<<'\n';
	}
}
int32_t main() {
	int T; cin>>T;
	while(T--){
		test_case();
	}
    return 0;
}
