/*
* https://programmers.co.kr/learn/courses/30/lessons/43162
*/
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int> >& computers, int y) 
{
    int curY;
    stack<int> s;
    s.push(y);
    
    while (!s.empty()) {
       	curY = s.top(); 
        s.pop();
        
        for (int i = 0; i < computers[curY].size(); ++i) {
            if (computers[curY][i] == 1) {
                computers[curY][i] = 0;
                computers[i][curY] = 0;
                s.push(i);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for (int i = 0; i < computers.size(); ++i) {
        for (int j = 0; j < computers[i].size(); ++j) {
            if (computers[i][j] == 1) {
                dfs(computers, i);
                answer++;
            }
        }
    }
    return answer;
}
