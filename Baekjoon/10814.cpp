/*
* https://www.acmicpc.net/problem/10814
*/
#include <bits/stdc++.h>
using namespace std;

struct p {
    int age;
    string name;
    int idx;
};

// if stable_sort() is used, delete line 15, 16 
bool sorting(struct p& p1, struct p& p2) {
    if (p1.age == p2.age)
        return p1.idx < p2.idx;
    return p1.age < p2.age;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    vector<p> vec;
    cin >> N;

    vec.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> vec[i].age >> vec[i].name;
        vec[i].idx = i; 
    }

    sort(vec.begin(), vec.end(), sorting);

    for (int i = 0; i < N; ++i)
        printf("%d %s\n", vec[i].age, vec[i].name.c_str());
}
