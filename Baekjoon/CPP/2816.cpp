/*
* https://www.acmicpc.net/problem/2816
*/
#include <bits/stdc++.h>
using namespace std;

int one, zero;
int main()
{
    int N, dis, k1, k2;
    vector<string> str;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        string input;
        cin >> input;
        if (input == "KBS1") k1 = i;
        if (input == "KBS2") k2 = i;
        str.push_back(input);
    }

    if (k1 < k2) {
        for (int i = 0; i < k1; ++i) 
            printf("1");
        for (int i = 0; i < k1; ++i)
            printf("4");

        for (int i = 0; i < k2; ++i) 
            printf("1");
        for (int i = 1; i < k2; ++i)
            printf("4");
    }
    else {
        for (int i = 0; i < k1; ++i) 
            printf("1");
        for (int i = 0; i < k1; ++i)
            printf("4");

        for (int i = 0; i < k2 + 1; ++i) 
            printf("1");
        for (int i = 1; i < k2 + 1; ++i)
            printf("4");
    }
}
