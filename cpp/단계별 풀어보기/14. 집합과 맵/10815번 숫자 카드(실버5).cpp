/*
* @title    : 10815번 숫자 카드(실버5)
* @content  : 집합과 맵
* @author   : 손동찬
* @date     : 240714
* @time     : 416 ms
* @memory   : 23304 KB
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
	cin >> N;
	vector<int> vecDatas(N);
	for (int i = 0; i < N; i++)
		cin >> vecDatas[i];

	sort(vecDatas.begin(), vecDatas.end());
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int iNum;
		cin >> iNum;
		
		if (binary_search(vecDatas.begin(), vecDatas.end(), iNum) )
			cout << 1 << " ";
		else
			cout << 0 << " ";

		cout << *lower_bound(vecDatas.begin(), vecDatas.end(), iNum);
	}

	return 0;
}
//#include <iostream>
//#include <unordered_set>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	int N, M;
//	cin >> N;
//	unordered_set<int> usDatas;
//	for (int i = 0; i < N; i++)
//	{
//		int iNum;
//		cin >> iNum;
//		usDatas.insert(iNum);
//	}
//
//	cin >> M;
//	for (int i = 0; i < M; i++)
//	{
//		int iNum;
//		cin >> iNum;
//		if (usDatas.find(iNum) == usDatas.end())
//			cout << 0 << " ";
//		else
//			cout << 1 << " ";
//	}
//
//	return 0;
//}