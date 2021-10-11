/*
* https://www.acmicpc.net/problem/1449
*/
#include <bits/stdc++.h>
using namespace std;

int a[1001];
int main()
{
    int N, L, nextTape = 0, tape = 0;
    
    scanf("%d %d", &N, &L);

    for (int i = 0; i < N; ++i) 
        scanf("%d", &a[i]);

    sort(a, a + N);
    for (int i = 0; i < N; ++i) {
        int input = a[i];
        
        if (input > nextTape) {
            tape++;
            nextTape = input + (L - 1);
        }
    }
    printf("%d\n", tape);
}
