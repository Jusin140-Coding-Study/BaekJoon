/*
* @title    : 1414번 불우이웃돕기(골드3)
* @content  : 최소 신장 트리
* @author   : 손동찬
* @date     : 240725
* @time     : 0ms
* @memory   : 2164 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
	int Start;
	int End;
	int Weight;
	bool Used;
};

const bool compare(Data _A, Data _B)
{
	return _A.Weight < _B.Weight;
}

const int find(int _A, vector<int>& _vecNodes)
{
	if (_A == _vecNodes[_A])
		return _A;
	else
		return _vecNodes[_A] = find(_vecNodes[_A], _vecNodes);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<Data> vecDatas;
	vector<int> vecNodes(N);
	for (int i = 0; i < N; ++i)
		vecNodes[i] = i;

	for (int i = 0; i < N; ++i)
	{
		string a;
		cin >> a;
		for (int j = 0; j < a.size(); ++j)
		{
			Data d;

			if (isdigit(a[j])) continue;			
			else
			{
				if( 'a' <= a[j] && a[j] <= 'z')
					d.Weight = a[j] - 'a' + 1;
				else
					d.Weight = a[j] - 'A' + 27;
			}
			d.Start = i;
			d.End = j;
			d.Used = false;
			vecDatas.push_back(d);
		}
	}

	sort(vecDatas.begin(), vecDatas.end(), compare);

	int iCount = 0;
	for (int i = 0; i < vecDatas.size(); ++i)
	{
		int A = find(vecDatas[i].Start, vecNodes);
		int B = find(vecDatas[i].End, vecNodes);
		if (A == B) continue;
			
		vecNodes[A] = vecNodes[B];
		vecDatas[i].Used = true;
		++ iCount;
		if (iCount >= N-1) break;
	}

	if (iCount < N-1)
	{
		cout << "-1";
		return 0;
	}

	int iResult = 0;
	for (int i = 0; i < vecDatas.size(); ++i)
		if (!vecDatas[i].Used)
			iResult += vecDatas[i].Weight;

	cout << iResult;

	return 0;
}
