#include <stdio.h>

int arr[100001];
int main()
{
    int idx;
    int k;

    idx = 0;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &arr[idx]);
        if (arr[idx] == 0)
        {
            if (idx > 0)
                --idx;
            arr[idx] = 0;
        }
        else
            idx++;
    }
    unsigned int rst = 0;
    for (int i = 0; arr[i] != 0; ++i)
        rst += arr[i];
    printf("%d",rst);
}
