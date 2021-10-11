/*
* https://www.acmicpc.net/problem/1700
*/
#include <bits/stdc++.h>
using namespace std;

int C[101], R[101]; // C : number of left , R : input
bool P[101], temp[101];
int n, k, ct;

int main()
{
    cin >> n >> k;

    for (int i = 0; i < k; ++i) {
        cin >> R[i];
        C[R[i]]++;
    }

    for (int i = 0; i < k; ++i) {
        int code = R[i], toChange = -1;
        int hole = 0;

        
        C[code]--; // 개수 줄여주기

        if (P[code]) {
            continue;
        }

        for (int i = 1; i <= k; ++i)
            if (P[i]) hole++;
        if (hole < n) {
            P[code] = true;
            continue;
        }

        for (int t = 0; t < k; ++t) {
            if(P[t] && C[t] == 0) {
                toChange = t;
                break;
            }
        }

        if (toChange != -1) {
            P[toChange] = false;
            P[code] = true;
        }
        else {
            int tempCount = n;
            for (int t = 0; t < k; ++t)
                temp[t] = P[t];

            for (int t = i + 1; t < k; ++t) {
                int val = R[t];
                if (P[val] && temp[val]) {
                    tempCount--;
                    temp[val] = false;
                }

                if (tempCount == 0) {
                    toChange = val;
                    break;
                }
            }

            P[toChange] = false;
            P[code] = true;
        }
        ct++;
    }
    cout << ct;
}
