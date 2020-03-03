/*
 * https://programmers.co.kr/learn/courses/30/lessons/12939
 */
#include <bits/stdc++.h>
using namespace std;

string solution(string s) {
	string answer = "";
	int MAX = INT_MIN, MIN = INT_MAX;
	string::const_iterator i, j;

	i = j = s.begin();

	while (i != s.end()) {
		while (*i == ' ') ++i;
		j = i;
		while (*j != ' ' && j != s.end()) ++j;
		string sub = string(i, j);
		int num = stoi(sub);
		MAX = max(MAX, num);
		MIN = min(MIN, num);

		i = j;
	}
	answer += (to_string(MIN) + " " + to_string(MAX));
	return answer;
}
