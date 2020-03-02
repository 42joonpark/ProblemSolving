/*
 https://programmers.co.kr/learn/courses/30/lessons/12905
 */

#include <bits/stdc++.h>
using namespace std;

int dy[3] = {0, -1, -1};
int dx[3] = {-1, -1, 0};
int solution(vector<vector<int>> board)
{
    int answer = 0;
   	int y, x, MIN, MAX = 1;
    bool isZero = true;

    // check if all values are 0
    for (y = 0; y < board.size(); ++y)
        for (x = 0; x < board[y].size(); ++x)
            if (board[y][x] == 1) isZero = false;

    if  (isZero) return 0;

   	for (y = 1; y < board.size(); ++y)
    {
        for (x = 1; x < board[y].size(); ++x)
        {
            if (board[y][x] >= 1)
            {
            	MIN = 1001;
       			for (int i = 0; i < 3; ++i)
         	   	{
         	       	MIN = min(board[y + dy[i]][x + dx[i]], MIN);
         	   	}
            	board[y][x] = MIN + 1;
           		MAX = max(board[y][x], MAX);
            }
        }
    }

    answer = MAX;
    return answer * answer;
}
