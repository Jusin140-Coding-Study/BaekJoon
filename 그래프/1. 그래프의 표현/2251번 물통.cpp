#include <iostream>
#include <queue>
using namespace std;

void BFS(bool* arrResult, int* arrNow);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool   arrResult[201] = { false };
    int    arrNow[3];

    cin >> arrNow[0] >> arrNow[1] >> arrNow[2];

    BFS(arrResult, arrNow);

    for (int i = 0; i < 201; ++i)
    {
        if (arrResult[i])
            cout << i << ' ';
    }
}

void BFS(bool* arrResult, int* arrNow)
{
    int    arrSender[] = { 0, 0, 1, 1, 2, 2 };
    int    arrReceiver[] = { 1, 2, 0, 2, 0, 1 };
    bool   arrVisited[201][201] = { false };

    arrVisited[0][0] = true;
    arrResult[arrNow[2]] = true;

    queue<pair<int, int>> qAB;
    qAB.push(make_pair(0, 0));


    while (!qAB.empty())
    {
        pair<int, int> p = qAB.front();
        qAB.pop();
        int A = p.first;
        int B = p.second;
        int C = arrNow[2] - A - B;

        for (int i = 0; i < 6; ++i)
        {
            int arrNext[] = { A, B, C };
            arrNext[arrReceiver[i]] += arrNext[arrSender[i]];
            arrNext[arrSender[i]] = 0;

            if (arrNext[arrReceiver[i]] > arrNow[arrReceiver[i]])
            {
                arrNext[arrSender[i]] = arrNext[arrReceiver[i]] - arrNow[arrReceiver[i]];
                arrNext[arrReceiver[i]] = arrNow[arrReceiver[i]];
            }

            if (!arrVisited[arrNext[0]][arrNext[1]])
            {
                arrVisited[arrNext[0]][arrNext[1]] = true;

                qAB.push(make_pair(arrNext[0], arrNext[1]));

                if (arrNext[0] == 0)
                    arrResult[arrNext[2]] = true;
            }
        }
    }
}