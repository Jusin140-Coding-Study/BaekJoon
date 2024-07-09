/*
* @title    : 1253번 좋다(골드4)
* @content  :
* @author   : 손동찬
* @date     : 240709
* @time     : 12 ms
* @memory   : 2020 KB
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

	int N;
	cin >> N;
	vector<int> v(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> v[i];

	sort(v.begin(), v.end());

	int iCount = 0;

	for (int i = 0; i < N ; ++i)
	{
		int iFrontIndex = 0, iBackIndex = N - 1;

		while (iFrontIndex < iBackIndex)
		{
			if (v[iFrontIndex] + v[iBackIndex] < v[i])
				iFrontIndex++;

			else if (v[iFrontIndex] + v[iBackIndex] > v[i])
				iBackIndex--;

			else
			{
				if (iFrontIndex != i && iBackIndex != i)
				{
					iCount++;
					break;
				}
				else if (iFrontIndex == i)
					iFrontIndex++;

				else if (iBackIndex == i)
					iBackIndex--;
			}
		}
	}

	cout << iCount << "\n";

	return 0;
}