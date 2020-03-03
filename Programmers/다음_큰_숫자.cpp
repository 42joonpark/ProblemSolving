/*
 https://programmers.co.kr/learn/courses/30/lessons/12911
 */
#include <bits/stdc++.h>
using namespace std;

int func(int num) {
	int ct = 0;
	if (num == 1) return 1;
	while (num > 1) {
		if (num % 2 == 1) ++ct;
		num /= 2;
	}
	return ct;
}

int solution(int n) {
	int answer = func(n);
	while (n <= 1e6) {
		++n;
		if (func(n) == answer)
			return n;
	}
}
