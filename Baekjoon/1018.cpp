/*
* https://www.acmicpc.net/problem/1018
*/
#include <bits/stdc++.h>
using namespace std;

vector<string> board;
int H, W, m_min = INT_MAX;
int main()
{
     cin >> H >> W;
     board.resize(H + 1);
     for (int y = 0; y < H; ++y)
        cin >> board[y];

    for (int y = 0; y <= H - 8; ++y)
    {
        for (int x = 0; x <= W - 8; ++x)
        {
            bool B = true;
            for (int k = 0; k < 2; ++k)
            {
                int ct = 0; 
                if (k == 1) B = false;
                for (int i = 0; i < 8; ++i)
                {
                    for (int j = 0; j < 8; ++j)
                    {
                        if (B) {
                            if (board[y + i][x + j] == 'W')
                                ct++;
                        }
                        if (!B) {
                            if (board[y + i][x + j] == 'B')
                                ct++;
                        }
                        B = !B;
                    }
                    B = !B;
                }
                m_min = min(m_min, ct);
            } 
        }
    }

    cout << m_min;
}
