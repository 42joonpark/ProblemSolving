/*
 * https://programmers.co.kr/learn/courses/30/lessons/12949
 */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size());
    for(int i = 0; i < answer.size(); ++i)
        answer[i].resize(arr2[0].size());
    for(int i = 0; i < answer.size(); ++i)
        for (int j = 0; j < answer[i].size(); ++j)
            answer[i][j] = 0;
    
    for (int y = 0; y < answer.size(); ++y) {
        for (int x = 0; x < answer[y].size(); ++x) {
            for (int i = 0; i < arr1[0].size(); ++i) {
                answer[y][x] += arr1[y][i] * arr2[i][x]; 
            }
        }
    }
    return answer;
}
