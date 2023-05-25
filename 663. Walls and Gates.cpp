// have not submit this to OJ yet because this is a locked problem
void wallsAndGates(vector<vector<int>> &rooms) {
    const int inf = (1 << 31) - 1;
    int R = rooms.size();
    int C = rooms[0].size();
    queue<pair<int, int>> gates;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (rooms[i][j] == 0) {
                gates.emplace(i, j);
            }
        }
    }
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
    while (!gates.empty()) {
        int sz = gates.size();
        for (int rep = 0; rep < sz; rep++) {
            auto [r, c] = gates.front();
            gates.pop();
            for (int dir = 0; dir < 4; dir++) {
                int r2 = r + dx[dir];
                int c2 = c + dy[dir];
                if (r2 >= 0 && c2 >= 0 && r2 < R && c2 < C && rooms[r2][c2] == inf) {
                    rooms[r2][c2] = rooms[r][c] + 1;
                    gates.emplace(r2, c2);
                }
            }
        }
    }
}
