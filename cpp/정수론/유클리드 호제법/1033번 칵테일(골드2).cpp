/*
* @title    : 1033번 칵테일(골드2)
* @content  : 유클리드 호제법
* @author   : 손동찬
* @date     : 240718
* @time     : 0ms
* @memory   : 2024 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

struct Data
{
	int Partner;
	int MyNum;
	int PartnerNum;
};

static long long GCD(long long A, long long B)
{
	long long iMax = max(A, B);
	long long iMin = min(A, B);

	while (iMax % iMin != 0)
	{
		long long Temp = iMin;
		iMin = iMax % iMin;
		iMax = Temp;
	}

	return iMin;
}

void DFS(int _iStartIndex, vector<vector<Data>>& _vecDatas, vector<bool>& _vecCheck, vector<long long>& _vecResult)
{
	_vecCheck[_iStartIndex] = true;

	for (int i = 0; i < _vecDatas[_iStartIndex].size(); ++i)
	{
		int num = _vecDatas[_iStartIndex][i].Partner;
		if (_vecCheck[num])
			continue;

		_vecResult[num] = _vecResult[_iStartIndex] * _vecDatas[_iStartIndex][i].PartnerNum / _vecDatas[_iStartIndex][i].MyNum;
		DFS(num, _vecDatas, _vecCheck, _vecResult);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<vector<Data>> vecDatas(N);
	vector<bool> vecCheck(N,false);
	vector<long long> vecResult(N, 0);
	long long LCM = 1;;


	for (int i = 0; i < N-1; ++i)
	{
		int iMy;
		Data MyData;
		cin >> iMy >> MyData.Partner >> MyData.MyNum >> MyData.PartnerNum;
		vecDatas[iMy].push_back(MyData);

		Data PartnerData = { iMy, MyData.PartnerNum,MyData.MyNum };
		vecDatas[MyData.Partner].push_back(PartnerData);

		LCM *= MyData.MyNum * MyData.PartnerNum / GCD(MyData.MyNum, MyData.PartnerNum);
	}

	vecResult[0] = LCM;
	DFS(0, vecDatas, vecCheck, vecResult);

	long long iGDC = vecResult[0];

	for (int i = 1; i < N; ++i)
		iGDC = GCD(iGDC, vecResult[i]);

	for (int i = 0; i < N; ++i)	
		cout << vecResult[i] / iGDC << " ";
	
	return 0;
}
