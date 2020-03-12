/*
* https://programmers.co.kr/learn/courses/30/lessons/43105
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int Max = triangle[0][0];
    int L, R;
    
    for (int h = 1; h < triangle.size(); ++h)
    {
        for (int p = 0; p < triangle[h].size(); ++p)
        {
            L = R = 0;
            if (p - 1 >= 0) L = triangle[h - 1][p - 1];
            if (p < triangle[h - 1].size()) R = triangle[h - 1][p];
            
            triangle[h][p] += L < R ? R : L;
            
            Max = max(Max, triangle[h][p]);
        }
    }
    return Max;
}
