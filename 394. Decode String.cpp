class Solution {
public:
    string solve(int start, int end, string s, vector<int> mp){
        string res;
        int i = start;
        while(i <= end){
            if(s[i] >= '0' && s[i] <= '9'){
                int repeat = s[i] - '0';
                int j = i + 1;
                while(s[j] >= '0' && s[j] <= '9'){
                    repeat = repeat * 10 + s[j] - '0';
                    j++;
                }
                string child = solve(j + 1, mp[j] - 1, s, mp);
                for(int rep = 0; rep < repeat; rep++){
                    res += child;
                }
                i = mp[j] + 1;
            } else {
                res += s[i];
                i++;
            }
        }
        return res;
    }
    string decodeString(string s) {
        int n = s.size();
        vector<int> mp(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(s[i] == '['){
                st.push(i);
            } else if(s[i] == ']'){
                int tp = st.top();
                st.pop();
                mp[tp] = i;
                mp[i] = tp;
            }
        }
        return solve(0, n - 1, s, mp);
    }
};