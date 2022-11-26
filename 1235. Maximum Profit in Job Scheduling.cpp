class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        for(int i=0; i<n; i++){
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end(), [&](vector<int> x, vector<int> y){
            return x[0] <= y[0];
        });
        vector<int> dp(n+1, 0);
        dp[n-1] = jobs[n-1][2];
        for(int i=n-1; i>=0; i--){
            int next = getNextJob(jobs, i, n);
            int incl = dp[next] + jobs[i][2];
            int excl = dp[i+1];
            dp[i] = max(incl, excl);
        }
        return dp[0];
    }
    int getNextJob(vector<vector<int>>& jobs, int idx, const int& n){
        int lo = idx+1, hi = n-1, ans = n;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;
            if(jobs[idx][1] <= jobs[mid][0])
            {
                ans = mid;
                hi = mid-1;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};