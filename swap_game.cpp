#include<bits/stdc++.h>
using namespace std;

bool check(const vector<vector<int>>& board){
  int R = size(board), C = size(board[0]);
  vector<int> temp;
  for(int r = 0; r < R; r++){
    for(int c = 0; c < C; c++){
      temp.push_back(board[r][c]);
    }
  }
  for(int r = 1; r <= R * C - 1; r++){
    if(temp[r - 1] != r){
      return false;
    }
  }
  return true;
}
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const char dirs[4] = {'D', 'R', 'U', 'L'};
int main() {
  vector<vector<int>> grid = {{0, 1, 3}, {4, 2, 5}, {7, 8, 6}};
  vector<vector<int>> grid2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
  assert(check(grid) == false);
  assert(check(grid2) == true);
  int R = size(grid), C = size(grid[0]);
  auto inside = [&](int r, int c){
    return r >= 0 && r < C && c >= 0 && c < C;
  };
  queue<pair<string, vector<vector<int>>>> st;
  set<vector<vector<int>>> vis;
  vis.insert(grid);
  st.push({"", grid});
  while(!st.empty()){
    auto [cur_dir, tp] = st.front();
    if(check(tp)){
        cout<<cur_dir<<'\n';
        return 0;
    }
    st.pop();
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            if(tp[r][c] == 0){
                for(int dir = 0; dir < 4; dir++){
                    int r2 = dx[dir] + r;
                    int c2 = dy[dir] + c;
                    if(inside(r2, c2)){
                        vector<vector<int>> next_grid = tp;
                        string next_dir = cur_dir + dirs[dir];
                        swap(next_grid[r2][c2], next_grid[r][c]);
                        if(!vis.count(next_grid)){
                            vis.insert(next_grid);
                            st.push({next_dir, next_grid});
                        }
                    }
                }
            }
        }
    }
  }
  assert(false);
  return 0;
}
/*
{0, 1, 3}, 
{4, 2, 5}, 
{7, 8, 6}

{1, 0, 3}, 
{4, 2, 5}, 
{7, 8, 6}

{1, 2, 3}, 
{4, 0, 5}, 
{7, 8, 6}

{1, 2, 3}, 
{4, 5, 0}, 
{7, 8, 6}

{1, 2, 3}, 
{4, 5, 6}, 
{7, 8, 0}

*/

// faster solution, packing zero position in BFS state!
#include<bits/stdc++.h>
using namespace std;
bool check(const vector<vector<int>>& grid){
    int R = size(grid), C = size(grid[0]);
    int need = 1;
    for(int r = 0; r < R; r++){
        for(int c = 0; c < C; c++){
            if(r == R - 1 && c == C - 1){
                return grid[r][c] == 0;
            }
            if(grid[r][c] == need){
                need++;
            } else {
                return false;
            }
        }
    }
    assert(false);
}
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const char dirs[4] = {'D', 'R', 'U', 'L'};
struct State{
    string state;
    vector<vector<int>> grid;
    int xZero, yZero;
    State(string _state, vector<vector<int>> _grid, int _xZero, int _yZero){
        xZero = _xZero;
        yZero = _yZero;
        grid = _grid;
        state = _state;
    }
};
int main(){
    vector<vector<int>> grid = {{0, 1, 3}, {4, 2, 5}, {7, 8, 6}};
    vector<vector<int>> grid2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    assert(check(grid) == false);
    assert(check(grid2) == true);
    int R = size(grid), C = size(grid[0]);
    auto inside = [&](int r, int c){
        return r >= 0 && r < R && c >= 0 && c < C;
    };
    int x = -1, y = -1;
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            if(grid[r][c] == 0)
                x = r, y = c;
    assert(x != -1 && y != -1);
    assert(grid[x][y] == 0);
    set<vector<vector<int>>> vis;
    vis.insert(grid);
    State init("", grid, x, y);
    queue<State> q({init});
    while(!q.empty()){
        State state = q.front();
        q.pop();
        if(check(state.grid)){
            cout<<state.state<<'\n';
            return 0;
        }
        assert(state.grid[state.xZero][state.yZero] == 0);
        for(int dir = 0; dir < 4; dir++){
            int r2 = dx[dir] + state.xZero;
            int c2 = dy[dir] + state.yZero;
            if(inside(r2, c2)){
                vector<vector<int>> next_grid = state.grid;
                swap(next_grid[r2][c2], next_grid[state.xZero][state.yZero]);
                if(!vis.count(next_grid)){
                    string next_dir = state.state + dirs[dir];
                    assert(next_grid[r2][c2] == 0);
                    State next_state(next_dir, next_grid, r2, c2);
                    q.push(next_state);
                    vis.insert(next_grid);
                }
            }
        }
    }
    assert(false);
    return 0;
}