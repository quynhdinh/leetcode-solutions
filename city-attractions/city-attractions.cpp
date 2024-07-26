/**
 *    created: 26.07.2024_15:07:33
**/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/algo/debug.h"
#else
#define debug(...) 42
#endif

/*
 * There are `n` attractions connected by `m` bidirectional roads end at `u` and `v`, each road takes some time `t` to travel
 * in each city there is an attraction with some `beauty` each attraction take some time `t` to see, you have some limited time `max_t`
 * output the maximum beauty you can visit during your time at the city
 * */
struct State{
    int node, beauty, time;
    vector<bool> visited;
    State(int n, int b, int t, vector<bool> v){
        node = n;
        beauty = b;
        time = t;
        visited = v;
    }
};
int findBestPath(int n, int m, int max_t, vector<int> &beauty, vector<int>  &u, vector<int> &v, vector<int> &time) {
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        g[u[i]].push_back({v[i], time[i]});
        g[v[i]].push_back({u[i], time[i]});
    }
    int ans = -1;
    vector<bool> visited(n, false);
    visited[0] = true;
    State s(0, beauty[0], 0, visited);
    queue<State> q({s});
    while (!q.empty()) {
        State state = q.front();
        q.pop();
        int curr_node = state.node;
        int beauty_till_now = state.beauty;
        int t = state.time;
        visited = state.visited;
        if (curr_node == 0) ans = max(ans, beauty_till_now);
        for (auto [adjacent_node, next_t]: g[curr_node]) {
            int new_beauty_value = beauty_till_now;
            int new_t = next_t + t;
            if (new_t <= max_t) {
                if (!visited[adjacent_node]) {
                    new_beauty_value += beauty[adjacent_node];
                    visited[adjacent_node] = true;
                }
                State new_state(adjacent_node, new_beauty_value, new_t, visited);
                q.push(new_state);
            }
        }
    }
    return ans;
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, max_t;
    cin >> n >> m >> max_t;
    vector<int> beauty(n), u(m), v(m), t(m);
    for (int i = 0; i < n; i++) cin >> beauty[i];
    for (int i = 0; i < m; i++) cin >> u[i];
    for (int i = 0; i < m; i++) cin >> v[i];
    for (int i = 0; i < m; i++) cin >> t[i];

    cout << findBestPath(n, m, max_t, beauty, u, v, t);
    return 0;
}
