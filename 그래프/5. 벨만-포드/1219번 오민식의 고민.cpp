#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> Edge;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iN, iM;
    int iDepart, iArrive;

    cin >> iN >> iDepart >> iArrive >> iM;

    int iCity1, iCity2, iCost;

    vector<Edge> vecEdges(iM);

    long MAX = 10000000 * (iM + iN + 1);
    long MIN = -10000000 * (iM + iN + 1);

    // 에지리스트에 에지 데이터 저장
    for (int i = 0; i < iM; ++i)
    {
        cin >> iCity1 >> iCity2 >> iCost;

        vecEdges[i] = make_tuple(iCity1, iCity2, iCost);
    }

    vector<long> vecEarn(iN);

    // 각 도시에서 벌 수 있는 돈 저장
    for (int i = 0; i < iN; ++i)
    {
        cin >> vecEarn[i];
    }

    // 최소값으로 배열 초기화
    vector<long> vecResult(iN, MIN);

    // 시작 도시 결과값에 시작 도시 방문 시 벌 수 있는 돈 저장
    vecResult[iDepart] = vecEarn[iDepart];

    Edge iCurEdge;

    // N - 1번 반복X 양수 사이클이 전파되도록 충분히 큰 수로 반복
    for (int iOuter = 0; iOuter <= iN + 50; ++iOuter)
    {
        // 에지 수 만큼 반복
        for (int iInner = 0; iInner < iM; ++iInner)
        {
            iCurEdge = vecEdges[iInner];

            int iStart = get<0>(iCurEdge);
            int iEnd = get<1>(iCurEdge);
            int iMoney = get<2>(iCurEdge);

            // 시작 도시가 방문한 적 없는 도시일 때는 업데이트하지 않음
            if (vecResult[iStart] == MIN)
                continue;

            // 시작 도시가 양수 사이클과 연결된 도시일 때 도착 도시도 양수 사이클과 연결된 도시로 업데이트
            else if (vecResult[iStart] == MAX)
                vecResult[iEnd] = MAX;

            // 도착 도시값 < 시작 도시값 + 도착 도시 수업 - 에지 가중치 일 때 더 많이 벌 수 있는 새로운 경로로 도착한 것이므로 값 업데이트
            else if (vecResult[iEnd] < vecResult[iStart] + vecEarn[iEnd] - iMoney)
            {
                vecResult[iEnd] = vecResult[iStart] + vecEarn[iEnd] - iMoney;

                if (iOuter >= iN - 1)
                    vecResult[iEnd] = MAX;
            }
        }
    }

    if (vecResult[iArrive] == MIN)
        cout << "gg\n";

    else if (vecResult[iArrive] == MAX)
        cout << "Gee\n";

    else
        cout << vecResult[iArrive] << '\n';

    return 0;
}