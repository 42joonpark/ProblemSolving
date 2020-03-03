#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
	int answer = 0, sum;
	for (int i = n; i >= sqrt(n); --i) {
		sum = n;
		for (int j = i; j >= 1; --j) {
			sum -= j;
			if (sum == 0) {
				answer++;
				break;
			}
			if (sum < 0)
				break;
		}
	}
    return answer;
}
