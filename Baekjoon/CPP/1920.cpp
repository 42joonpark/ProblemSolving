/*
* https://www.acmicpc.net/problem/1920
*/
#include <bits/stdc++.h>
using namespace std;

vector<int> vec;
bool my_binary_search(int left, int right, int value)
{
    int mid = (left + right) / 2;

    if (vec[mid] == value)
        return true;

    if (left < right) {
        if (vec[mid] > value)
            return my_binary_search(left, mid, value);
        else
            return my_binary_search(mid + 1, right, value);
    }

    return false;
}

int main()
{
    int N, M;

    cin >> N;
    vec.resize(N);

    for (int i = 0; i < N; ++i)
        scanf("%d", &vec[i]);

    sort(vec.begin(), vec.end());

    cin >> M;
    for (int i = 0; i < M; ++i) {
        int val;
        
        scanf("%d", &val);
        if (my_binary_search(0, N, val))
            printf("1\n");
        else printf("0\n");
    }
}
