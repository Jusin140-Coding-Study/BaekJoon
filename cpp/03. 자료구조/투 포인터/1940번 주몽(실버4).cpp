/*
* @title    : 1940번 주몽(실버4)
* @content  :
* @author   : 손동찬
* @date     : 240709
* @time     : 0ms
* @memory   : 2200 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> v(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());
	
	int iCount = 0;
	int iFrontIndex = 0;
	int iBackIndex = N-1;
	
	while (iFrontIndex < iBackIndex)
	{
		if (v[iFrontIndex] + v[iBackIndex] > M)
			iBackIndex--;

		else if (v[iFrontIndex] + v[iBackIndex] < M)
			iFrontIndex++;

		else
		{
			iFrontIndex++;
			iBackIndex--;
			iCount++;
		}
	}

	cout << iCount << "\n";

	return 0;
}