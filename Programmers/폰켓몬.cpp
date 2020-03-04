/*
* https://programmers.co.kr/learn/courses/30/lessons/1845
*/
#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;
	map<int, int> m;
	
	for(auto& a : nums) {
		m[a]++;
	}

	answer = m.size();

	if (answer > nums.size() / 2)
		answer = nums.size() / 2;

	return answer;
}
