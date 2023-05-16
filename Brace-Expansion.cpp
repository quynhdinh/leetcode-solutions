// have not submit this to OJ yet
vector<string> braceExpansion(string s){
    vector<vector<char>> groups;
    int i = 0;
    const int sz = (int)s.size();
    while(i < sz){
        if(s[i] == '{'){
            vector<char> group;
            int j = i + 1;
            while(s[j] != '}'){
                if(s[j] >= 'a' && s[j] <= 'z')
                    group.push_back(s[j]);
               j++;
             }
            i = j + 1;
            groups.push_back(group);
        } else if(s[i] >= 'a' && s[i] <= 'z'){
            groups.push_back({s[i]});
            i++;
        }
    }
    const int n = (int)groups.size();
    vector<string> res;
    stack<pair<int, string>> st({{-1, ""}});
    while(!st.empty()){
        auto [id, str] = st.top();
        st.pop();
        if (id + 1 < n) {
            for (char ch: groups[id + 1]) {
                string str2 = str + ch;
                st.push({id + 1, str2});
            }
        }
        if (id == n - 1) {
            res.push_back(str);
        }
    }
    sort(res.begin(), res.end());
    return res;
}
