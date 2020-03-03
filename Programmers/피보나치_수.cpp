/*
* https://programmers.co.kr/learn/courses/30/lessons/12945
*/
#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    long long int F[100001];
    F[1] = 1;
    F[2] = 1;

    for (int i = 3; i <= n; ++i) {
        F[i] = (F[i - 1] + F[i - 2]) % 1234567;
    }

    return F[n];
}
