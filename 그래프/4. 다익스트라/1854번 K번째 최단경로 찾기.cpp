#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Node;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM, iK;
	cin >> iN >> iM >> iK;

	// 한 도시에서 다른 도시까지의 거리를 저장할 인접행렬
	vector<vector<int>> vecDist(iN + 1, vector<int>(iN + 1, 0));

	int iDepart, iArrive, iDist;

	for (int i = 0; i < iM; ++i)
	{
		cin >> iDepart >> iArrive >> iDist;

		vecDist[iDepart][iArrive] = iDist;
	}

	// (출발 도시로부터의 거리, 도시 번호)를 저장할 우선순위 큐 (거리가 짧은 순으로 정렬)
	priority_queue<Node, vector<Node>, greater<Node>> pqNode;
	pqNode.push(make_pair(0, 1));

	// 각 도시마다 K번째 최단 경로를 저장하기 위한 우선순위 큐
	vector<priority_queue<int>> pqDist(iN + 1);
	pqDist[1].push(0);

	Node nCurNode, nNextNode;

	while (!pqNode.empty())
	{
		nCurNode = pqNode.top();
		pqNode.pop();

		// 노드 개수만큼 반복
		for (int i = 1; i <= iN; ++i)
		{
			// 다음 노드와 현재 노드가 연결되어 있는지 확인
			if (vecDist[nCurNode.second][i] != 0)
			{
				// 각 도시의 최단 거리 배열에 저장된 경로가 K개보다 작은지 확인
				if (pqDist[i].size() < iK)
				{
					// 정보 삽입하고 큐에 해당 노드를 추가
					pqDist[i].push(nCurNode.first + vecDist[nCurNode.second][i]);
					pqNode.push(make_pair(nCurNode.first + vecDist[nCurNode.second][i], i));
				}
				// 최단 거리 큐의 마지막 값 > 이전 노드의 값 + 두 노드 사이의 에지 가중치인지 확인
				else if (pqDist[i].top() > nCurNode.first + vecDist[nCurNode.second][i])
				{
					// 해당 노드의 최단 거리 배열에 마지막 경로 삭제하고 새로 추가
					// 큐에 해당 노드 추가
					pqDist[i].pop();
					pqDist[i].push(nCurNode.first + vecDist[nCurNode.second][i]);
					pqNode.push(make_pair(nCurNode.first + vecDist[nCurNode.second][i], i));
				}
			}
		}
	}

	for (int i = 1; i <= iN; ++i)
	{
		// 도시마다 저장된 경로의 개수가 K개면 해당 값 출력, 아니면 -1 출력
		if (pqDist[i].size() == iK)
		{
			cout << pqDist[i].top() << '\n';
		}
		else
			cout << "-1\n";
	}

	return 0;
}