/*
* @title    : 1940�� �ָ�(�ǹ�4)
* @content  :
* @author   : �յ���
* @date     : 240709
* @time     : 0ms
* @memory   : 2200 KB
* @state    : �Ϸ�
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