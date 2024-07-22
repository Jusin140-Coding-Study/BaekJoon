#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;

	cin >> iN;
	cin >> iM;

	vector<vector<pair<int, int>>>	vecCities(iN + 1);
	vector<vector<pair<int, int>>>	vecReverse(iN + 1);
	vector<int>						vecInDegree(iN + 1);
	queue<int>						qSort;
	vector<int>						vecResult(iN + 1);

	int iDepart, iArrive, iTime;

	for (int i = 0; i < iM; ++i)
	{
		cin >> iDepart >> iArrive >> iTime;

		// 한 도시에서 갈 수 있는 도시와 소요 시간 저장
		vecCities[iDepart].push_back(make_pair(iArrive, iTime));
		// 한 도시에 올 수 있는 도시와 소요 시간 저장
		vecReverse[iArrive].push_back(make_pair(iDepart, iTime));
		// 연결된 에지 수 저장
		vecInDegree[iArrive]++;
	}

	int iStart, iEnd;

	cin >> iStart >> iEnd;

	qSort.push(iStart);

	int iCur;

	// 출발 도시부터 도착 도시까지 최대 소요 시간을 구하는 코드
	// 더 연결된 도시가 없으면 종료
	while (!qSort.empty())
	{
		// 다음 이동 도시
		iCur = qSort.front();
		qSort.pop();

		// 현재 도시에서 이동 가능한 모든 도시 순회
		for (pair<int, int> iNext : vecCities[iCur])
		{
			// 해당 도시에 연결된 에지 수 감소
			vecInDegree[iNext.first]--;
			// 출발 도시부터 해당 도시에 도달하기 까지의 소요시간 저장
			vecResult[iNext.first] = max(vecResult[iNext.first], vecResult[iCur] + iNext.second);

			// 더 이상 해당 도시로 연결된 도시가 없다면 다음 이동 도시 큐에 저장
			if (0 == vecInDegree[iNext.first])
				qSort.push(iNext.first);
		}
	}

	// 출발 도시부터 도착 도시까지 최대 소요 시간인 경우 거치는 도로의 개수를 구하는 코드
	// 임계 경로 배열을 가지고 되돌아가면서 탐색
	int iRoadCnt = 0;
	vector<bool>	vecVisited(iN + 1, false);

	qSort.push(iEnd);

	while (!qSort.empty())
	{
		iCur = qSort.front();
		qSort.pop();

		for (pair<int, int> iNext : vecReverse[iCur])
		{
			if (vecResult[iCur] == vecResult[iNext.first] + iNext.second)
			{
				iRoadCnt++;

				if (!vecVisited[iNext.first])
				{
					vecVisited[iNext.first] = true;
					qSort.push(iNext.first);

				}
			}
		}
	}

	cout << vecResult[iEnd] << '\n' << iRoadCnt;
}