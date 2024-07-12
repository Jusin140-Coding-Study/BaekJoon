/*
* @title    : 2798번 블랙잭(브론즈2)
* @content  : 브루트 포스
* @author   : 손동찬
* @date     : 240709
* @time     : 0ms
* @memory   : 2020 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

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
	
	int iMax = 0;

	for (int i = 0; i < N - 2; ++i)
	{
		for (int j = i + 1; j < N - 1; ++j)
		{
			for (int k = j + 1; k < N ; ++k)
			{
				int iSum = v[i] + v[j] + v[k];
				if (iSum <= M) 
					iMax = max(iSum, iMax);
			}
		}
	}

	cout << iMax << "\n";

	return 0;
}