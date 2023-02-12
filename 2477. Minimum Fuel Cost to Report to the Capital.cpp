class Solution {
public:
    long long res;
    vector<vector<int>> edges;
    int div(int x, int y){
        return (x % y == 0 ? x / y : x / y + 1);
    }
    long long dfs(int node, int parent, int seats){
        int rep = 1;
        for(int& v: edges[node]){
            if(v != parent){
                rep += dfs(v, node, seats);
            }
        }
        if(node != 0){
            res += (long long)div(rep, seats);
        }
        return rep;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size() + 1;
        edges.resize(n);
        for(vector<int>& road: roads){
            edges[road[0]].push_back(road[1]);
            edges[road[1]].push_back(road[0]);
        }
        res = 0LL;
        dfs(0, -1, seats);
        return res;
    }
};
