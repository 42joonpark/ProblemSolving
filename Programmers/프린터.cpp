/*
* https://programmers.co.kr/learn/courses/30/lessons/42587
*/
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, ct = 0;
    int MAX = 0;
   	queue<pair<int, int> > q;
    
    for (int i = 0; i < priorities.size(); ++i) {
        q.push(make_pair(i, priorities[i]));
        MAX = max(MAX, priorities[i]);
    }
   	
    while (!q.empty()) {
       	if (q.front().second == MAX) {
            ++ct;
            if (q.front().first == location) return ct;
            q.pop();
            
            queue<pair<int, int>  > temp = q;
            MAX = 0;
            while (!temp.empty()) {
                pair<int, int> t = temp.front();
                MAX = max(MAX, t.second);
                temp.pop();
            }
            
        } else {
            pair<int, int> temp = q.front();
            q.pop();
            q.push(make_pair(temp.first, temp.second));
        }
    }
}
