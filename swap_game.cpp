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