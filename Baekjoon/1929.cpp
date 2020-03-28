/*
* https://www.acmicpc.net/problem/1929
*/

// ********************************* using sqrt() **********************************
#include <bits/stdc++.h>
using namespace std;

bool sosu(int num) {
    if (num == 1) return false;
    for (int i = 2; i <= sqrt(num); ++i)
        if (num % i == 0) return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;


    for (int i = M; i <= N; ++i) {
        if (sosu(i)) printf("%d\n", i);
    }
}

// ********************************** eratosthenes method 에라토스테네스의 체 **************************************
#include <bits/stdc++.h>
using namespace std;

int check[1000001];

bool sosu(int num) {
    for (int i = 2; i <= sqrt(num); ++i)
        if (num % i == 0) return false;
    return true;
}

void era(int n, int N) {
    int i = n;
    while (i < N) {
        i += n;
        check[i] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N, ct = 0;
    cin >> M >> N;


    check[1] = 1;
    for (int i = 2; i <= sqrt(N); ++i) {
        if (check[i] == 0 && sosu(i))
            era(i, N);
    }

    for (int i = M; i <= N; ++i) 
        if (check[i] == 0) printf("%d\n", i);
}
