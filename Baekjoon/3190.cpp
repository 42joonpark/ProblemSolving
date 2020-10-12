// https://www.acmicpc.net/problem/3190
#include <bits/stdc++.h>
using namespace std;

struct point {
    int y, x;
};

struct snack {
    vector<point> body{{1, 1}};
};

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int N, K, L;
vector<point> apples;
vector<pair<int, char>> directions;
int main()
{
    cin >> N >> K;
    apples.resize(K);
    for (int i = 0; i < K; ++i) {
        cin >> apples[i].y >> apples[i].x;
    }

    cin >> L;
    directions.resize(L);
    for (int i = 0; i < L; ++i) {
        cin >> directions[i].first >> directions[i].second;
    }

    snack s;
    int count = 0, next = 1; // count time
    point tail{1, 1};
    while (true) {
        point head{s.body.front().y, s.body.front().x};

        // find direction for current count(time)
        if (!directions.empty()) {
            if (directions.front().first == count) {
                if (directions.front().second == 'D')
                    next = (next + 1) % 4;
                else {
                    next--;
                    if (next < 0) next = 3;
                }
                directions.erase(directions.begin());
            }
        }

        // move head
        s.body[0].y += dy[next];
        s.body[0].x += dx[next];

        // check for break conditions
        int y = s.body.front().y;
        int x = s.body.front().x;
        if (y < 1 || x < 1 || y > N || x > N)
            break;

        // check if head hits body
        bool fail = false;
        for (auto i = 1; i < s.body.size(); ++i) {
            if (y == s.body[i].y && x == s.body[i].x) {
                fail = true;
                break;
            }
        }
        if (fail)
            break;

        // check if apple exists on current position
        tail.y = s.body.back().y;
        tail.x = s.body.back().x;
        bool add_tail = false;
        for (auto i = 0; i < apples.size(); ++i) {
            if (s.body[0].y == apples[i].y &&
                s.body[0].x == apples[i].x) {
                    s.body.push_back(tail);
                    apples.erase(apples.begin() + i);
                    add_tail = true;
                }
        }

        for (auto i = s.body.size() - 1; i > 1; --i) {
            if (i == s.body.size() - 1 && add_tail)
                continue;
            s.body[i].y = s.body[i - 1].y;
            s.body[i].x = s.body[i - 1].x;
        }
        if (s.body.size() > 2) {
            s.body[1].y = head.y;
            s.body[1].x = head.x;
        }
        count++;
        // cout << "#" << count <<  " Head position: (" << s.body[0].y << ", " << s.body[0].x << "), (" << s.body.back().y << ", " << s.body.back().x << ")\n";
    }
    cout << ++count << endl;
}