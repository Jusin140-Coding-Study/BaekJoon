/*
* @title    : 18870번 좌표 압축(실버2)
* @content  : 정렬
* @author   : 손동찬
* @date     : 240714
* @time     : 408 ms
* @memory   : 17652 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
	int iNum;
	int iIndex;
	int iCount;
};

bool CompareNum(const Data& a, const Data& b)
{
	return a.iNum < b.iNum;
}
bool CompareIndex(const Data& a, const Data& b)
{
	return a.iIndex < b.iIndex;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<Data> vecDatas(N);
	vector<int>	vResult(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> vecDatas[i].iNum;
		vecDatas[i].iIndex = i;
	}
	sort(vecDatas.begin(), vecDatas.end(), CompareNum);

	int iCount = 0;
	vecDatas[0].iCount = 0;
	for (int i = 1; i < vecDatas.size(); ++i)
	{
		if (vecDatas[i - 1].iNum < vecDatas[i].iNum)
			iCount++;

		vecDatas[i].iCount = iCount;
	}
	sort(vecDatas.begin(), vecDatas.end(), CompareIndex);

	for (auto& iter : vecDatas)
		cout << iter.iCount << " ";
	
	return 0;
}