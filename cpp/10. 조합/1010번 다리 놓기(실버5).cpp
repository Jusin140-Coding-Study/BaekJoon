/*
* @title    : 1010번 다리 놓기(실버5)
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

	if (_iB == 0 || _iA == _iB)
		return 1;

	return _vecMemo[_iA][_iB] = Binomial(_iA-1, _iB-1, _vecMemo) + Binomial(_iA-1, _iB, _vecMemo);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> vecMemo(31, vector<int>(31, 0));
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int W, E;
		cin >> W >> E;
		cout << Binomial(E, W, vecMemo)<<"\n";
	}

	return 0;
}