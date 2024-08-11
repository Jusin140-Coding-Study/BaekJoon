/*
* @title    : 2162번 선분 그룹(플래티넘5)
* @content  : 기하
* @author   : 손동찬
* @date     : 240811
* @time     : 92 ms
* @memory   : 2216 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

typedef long long _long;

struct line
{
	_long X1;
	_long Y1;
	_long X2;
	_long Y2;
};

vector<line> Datas;
vector<int> Parents;

int CCW(_long _X1, _long _Y1, _long _X2, _long _Y2, _long _X3, _long _Y3)
{
	_long Result = (_X1 * _Y2 + _X2 * _Y3 + _X3 * _Y1) - (_X2 * _Y1 + _X3 * _Y2 + _X1 * _Y3);
	if (Result > 0) return 1;
	if (Result < 0) return -1;
	return 0;
}

bool isCross(_long _X1, _long _Y1, _long _X2, _long _Y2, _long _X3, _long _Y3, _long _X4, _long _Y4)
{
	int Result1 = CCW(_X1, _Y1, _X2, _Y2, _X3, _Y3);
	int Result2 = CCW(_X1, _Y1, _X2, _Y2, _X4, _Y4);
	int Result3 = CCW(_X3, _Y3, _X4, _Y4, _X1, _Y1);
	int Result4 = CCW(_X3, _Y3, _X4, _Y4, _X2, _Y2);
	
	
	if (Result1 == 0 && Result2 == 0 && Result3 == 0 && Result4 == 0)
	{
		if (min(_X1, _X2) <= max(_X3, _X4) && min(_X3, _X4) <= max(_X1, _X2) &&
			min(_Y1, _Y2) <= max(_Y3, _Y4) && min(_Y3, _Y4) <= max(_Y1, _Y2))
			return true;
		else
			return false;
	}
	else if ((Result1 * Result2 <= 0) && (Result3 * Result4 <= 0))
		return true;
	
	else return false;
}

int Find(int _iIndex)
{
	int i = _iIndex;
	while (Parents[i] >= 0)
		i = Parents[i];
	return i;
}

void Union(int _A, int _B)
{
	int ParentA = Find(_A);
	int ParentB = Find(_B);

	if (ParentA == ParentB)
		return;

	Parents[ParentA] += Parents[ParentB];
	Parents[ParentB] = ParentA;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	Parents.resize(N,-1);
	Datas.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> Datas[i].X1 >> Datas[i].Y1 >> Datas[i].X2 >> Datas[i].Y2;

		for (int j = 0; j < i; ++j)
		{
			if (isCross(Datas[i].X1, Datas[i].Y1, Datas[i].X2, Datas[i].Y2,
						Datas[j].X1, Datas[j].Y1, Datas[j].X2, Datas[j].Y2))
				Union(i, j);
		}
	}
	
	int ans = 0, res = 0;

	for(int i = 0; i <N; ++i)
		if (Parents[i] < 0)
		{
			++ans;
			res = min(res, Parents[i]);
		}

	cout << ans << "\n" << -res;

	return 0;
}