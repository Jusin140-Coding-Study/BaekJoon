/*
* @title    : 2775번 부녀회장이 될테야(브론즈1)
* @content  : 조합
* @author   : 손동찬
* @date     : 240805
* @time     : 0ms
* @memory   : 2020 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

int Binomial(int _iA, int _iB, vector<vector<int>>& _vecMemo)
{
	if (_vecMemo[_iA][_iB])
		return _vecMemo[_iA][_iB];
		 
	if (_iA == 0)
		return _iB;

	if (_iB == 1)
		return 1;

	return _vecMemo[_iA][_iB] = (Binomial(_iA - 1, _iB, _vecMemo) + Binomial(_iA, _iB-1, _vecMemo));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> vecMemo(15, vector<int>(15, 0));

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int a, b;
		cin >> a >> b;
		cout << Binomial(a, b, vecMemo) << "\n";
	}

	return 0;
}