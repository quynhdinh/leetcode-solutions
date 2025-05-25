class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        set<char> st;
        int n = words.size();
        map<char, set<char>> g;
        for(auto& word: words)
            for(auto& ch: word)
                st.insert(ch);
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++){
                // words[i] is smaller than words[j]
                for(int k = 0; k < min(words[i].size(), words[j].size()); k++){
                    if(words[i][k] == words[j][k]){
                        if(words[i].size() > words[j].size() && k == min(words[i].size(), words[j].size()) - 1)
                            return "";
                        continue;
                    }
                    g[words[i][k]].insert(words[j][k]);
                    break;
                }
            }
        map<int, int> in_degree;
        for(auto& c: st)
            for(auto& c2: g[c])
                in_degree[c2]++;
        queue<int> q;
        string res = "";
        for(auto& ch: st)
            if(in_degree[ch] == 0){
                q.push(ch);
                res += ch;
            }
        while(!q.empty()){
            auto fr = q.front();
            q.pop();
            for(auto nxt: g[fr])
                if(--in_degree[nxt] == 0){
                    q.push(nxt);
                    res += nxt;
                }
        }
        return (res.size() == st.size() ? res : "");
    }
};
