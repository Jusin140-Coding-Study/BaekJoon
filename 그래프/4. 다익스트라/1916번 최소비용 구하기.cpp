#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int Dijkstra(vector<vector<pair<int, int>>>& vecCities, int iDepart, int iArrive);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iN, iM;

	cin >> iN >> iM;

	int iCity1, iCity2, iCost;

	vector<vector<pair<int, int>>> vecCities(iN + 1);

	for (int i = 0; i < iM; ++i)
	{
		cin >> iCity1 >> iCity2 >> iCost;
		vecCities[iCity1].push_back(make_pair(iCity2, iCost));
	}

	int iDepart, iArrive;

	cin >> iDepart >> iArrive;

	cout << Dijkstra(vecCities, iDepart, iArrive);

	return 0;
}

int Dijkstra(vector<vector<pair<int, int>>>& vecCities, int iDepart, int iArrive)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqCities;
	pqCities.push(make_pair(0, iDepart));

	vector<bool> vecVisited(vecCities.size() + 1, false);

	vector<int>	vecCost(vecCities.size() + 1, 1000000001);
	vecCost[iDepart] = 0;

	int iCurCity, iCurCost;

	while (!pqCities.empty())
	{
		iCurCity = pqCities.top().second;
		iCurCost = pqCities.top().first;
		pqCities.pop();

		if (vecVisited[iCurCity])
			continue;

		vecVisited[iCurCity] = true;

		for (pair<int, int> iNextCity : vecCities[iCurCity])
		{
			if (vecCost[iNextCity.first] > vecCost[iCurCity] + iNextCity.second)
			{
				vecCost[iNextCity.first] = vecCost[iCurCity] + iNextCity.second;
				pqCities.push(make_pair(iNextCity.second, iNextCity.first));
			}
		}
	}

	return vecCost[iArrive];
}