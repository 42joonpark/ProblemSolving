/*
https://programmers.co.kr/learn/courses/30/lessons/12909
*/
#include <bits/stdc++.h>
using namespace std;

bool solution(string s)
{
	int ct = 0;

	for (int i = 0; i < s.size(); ++i) {
		ct += s[i] == ')' ? -1 : 1;
		if (ct < 0) return false;
	}
	return ct == 0;
}
