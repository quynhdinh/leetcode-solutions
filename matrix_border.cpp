/**
 *    created: 30.10.2024_15:49:50
**/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "/tmp/debug.h"
#else
#define debug(...) 42
#endif

// For this challenge you will be transposing rows and columns within an array.
/*
have the function MatrixBorder(strArr) read the strArr parameter being passed which will represent an NxN matrix filled with 1's and 0's. Your program should determine the number of swaps between two rows or two columns that must be made to change the matrix such that the border of the matrix contains all 1's and the inside contains 0's. The format of strArr will be: ["(n,n,n...)","(...)",...] where n represents either a 1 or 0. The smallest matrix will be a 3x3 and the largest will be a 6x6 matrix.

For example: if strArr is: ["(0,1,1)","(1,1,1)","(1,1,1)"] then you can swap the first two columns and then swap the first two rows to create a matrix with the 1's on the border and the 0 on the inside, therefore your program should output 2.
*/

/*
create a matrix based on the input string

simple solution would be to analyze the border rows and columns
as we traverse we check for any 0
if 0 is at a column border swap with a column that has all 1s
if 0 is at a row border swap with a row that all 1s

keep track of the number of swaps made
*/
int MatrixBorder(string strArr[], int size) {
    vector<string> matrix;
	int answer = 0;
	for (int r = 0; r < size; r++){
        string temp;
        for(auto ch: strArr[r])
            if(ch == '1' || ch == '0')
                temp += ch;
		matrix.push_back(temp);
	}
    int R = matrix.size(), C = matrix[0].size();
    assert(R == C);
    auto swapColumn = [&](int col){
        for (int c = 0; c < C; c++){
            if (c == col || c == 0 || c == C - 1)
                continue;
            else {
                bool valid = true;
                for (int r = 0; r < R; r++)
                    if (matrix[r][c] == '0'){
                        valid = false;
                        break;
                    }
                if (valid){
                    for (int r = 0; r < R; r++)
                        swap(matrix[r][col], matrix[r][c]);
                    return;
                }
            }
        }
    };
    
    auto swapRow = [&](int row){
        for (int x = 0; x < R; x++){
            if (x == row || x== 0 || x == R - 1){
                continue;
            } else {
                bool valid = true;
                for (int col = 0; col < C; col++)
                    if (matrix[x][col] == '0'){
                        valid = false;
                        break;
                    }
                if (valid){
                    swap(matrix[row], matrix[x]);
                    return;
                }
            }
        }
    };
	for (int row = 0; row < R; row++)
		for (int col = 0; col < C; col++)
			if (row == 0 || row == R - 1 || col == 0 || col == C - 1){
				if (matrix[row][col] == '0'){
					if (col == 0 || col ==C - 1){
						swapColumn(col);
						answer++;
					} else if (row == 0 || row == R- 1){
						swapRow(row);
						answer++;
					}
				}
			}

	return answer;
}

int main() {
	string A[] = { "(0,1,1)", "(1,1,1)", "(1,1,1)" };
	string B[] = { "(0,1,0,1)", "(1,1,1,1)", "(0,1,0,1)", "(1,1,1,1)" };

	cout << MatrixBorder(A, sizeof(A) / sizeof(A[0])) << endl; // 2
	cout << MatrixBorder(B, sizeof(B) / sizeof(B[0])) << endl; // 2
	return 0;
}