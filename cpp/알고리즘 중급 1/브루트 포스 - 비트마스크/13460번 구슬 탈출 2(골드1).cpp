/*
* @title    : 13460�� ���� Ż�� 2(���1)
* @content  : ���Ʈ ���� - ��Ʈ����ũ
* @author   : �յ���
* @date     : 240904
* @time     : 0 ms
* @memory   : 2024 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <queue>

using namespace std;

int N, M;
char board[10][10];
bool visited[10][10][10][10];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

struct State
{
    int rx, ry, bx, by, count;
};

pair<int, int> move(int x, int y, int dx, int dy) 
{
    while (board[x + dx][y + dy] != '#' && board[x][y] != 'O')
    {
        x += dx;
        y += dy;
    }
    return { x, y };
}

int bfs(int rx, int ry, int bx, int by) {
    queue<State> q;
    q.push({ rx, ry, bx, by, 0 });
    visited[rx][ry][bx][by] = true;

    while (!q.empty()) 
    {
        State cur = q.front();
        q.pop();

        // 10�� �̳��� �������� ���ϸ� ���з� ����
        if (cur.count >= 10) return -1;

        for (int i = 0; i < 4; i++) 
        {        
            pair<int, int> pR = move(cur.rx, cur.ry, dx[i], dy[i]);
            pair<int, int> pB = move(cur.bx, cur.by, dx[i], dy[i]);
            int nrx = pR.first, nry = pR.second, nbx = pB.first, nby = pB.second;

            if (board[nbx][nby] == 'O') continue; // �Ķ� ������ ������ ����
            if (board[nrx][nry] == 'O') return cur.count + 1; // ���� ������ ������ ����

            // �� ������ ���� ��ġ�� �ִ� ���, �� ���� ������ ������ �� ĭ �ڷ�
            if (nrx == nbx && nry == nby) 
            {
                if (abs(nrx - cur.rx) + abs(nry - cur.ry) > abs(nbx - cur.bx) + abs(nby - cur.by)) 
                {
                    nrx -= dx[i];
                    nry -= dy[i];
                }
                else 
                {
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }

            if (!visited[nrx][nry][nbx][nby]) 
            {
                visited[nrx][nry][nbx][nby] = true;
                q.push({ nrx, nry, nbx, nby, cur.count + 1 });
            }
        }
    }

    return -1;
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int rx, ry, bx, by;

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < M; j++) 
        {
            cin >> board[i][j];
            if (board[i][j] == 'R') 
            {
                rx = i;
                ry = j;
            }
            else if (board[i][j] == 'B') 
            {
                bx = i;
                by = j;
            }
        }
    }

    cout << bfs(rx, ry, bx, by) << '\n';
    return 0;
}