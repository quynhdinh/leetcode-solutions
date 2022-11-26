class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if(k == 1){
            return n;
        }
        int res = 0;
        vector<pair<int, int>> intervals;
        for(int center = 0; center < n; center++){
            int l = center - 1;
            int r = center + 1;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r - l + 1 >= k) {
                   intervals.push_back({l, r});
                }
                l--;
                r++;
                res++;
            }
        }
        for(int c = 0; c < n  - 1; c++){
            if(s[c] == s[c + 1]){
                int c1 = c;
                int c2 = c + 1;
                while(c1 >= 0 && c2 < n && s[c1] == s[c2]){
                    if(c2 - c1 + 1 >= k) {
                        intervals.push_back({c1, c2});
                    }
                    c1--;
                    c2++;
                    res++;
                }
            }
        }
        if (intervals.size()== 0)  return 0;
        sort(intervals.begin(), intervals.end(), [&](const pair<int, int>& x, const pair<int, int>& y){
            return x.second < y.second;
        });
        int end = intervals[0].second;
        int count = 1;        
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].first > end) {
                end = intervals[i].second;
                count++;
            }
        }
        return count;
    }
};