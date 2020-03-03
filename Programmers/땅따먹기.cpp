/*
* https://programmers.co.kr/learn/courses/30/lessons/12913
*/
#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;

    for (int i = 1; i < land.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (j != k) answer = max(answer, land[i-1][k]);
            }
            land[i][j] += answer;
            answer = 0;
        }
    }

    for (int i = 0; i < 4; i++)
        answer = max(answer, land[land.size() - 1][i]);

    return answer;
}
