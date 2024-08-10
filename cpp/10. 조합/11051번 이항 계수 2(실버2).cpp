/*
* @title    : 11051번 이항 계수 2(실버2)
* @content  : 조합
* @author   : 손동찬
* @date     : 240805
* @time     : 4 ms
* @memory   : 5996 KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

#define MOD 10007

int Binomial(int _iA, int _iB, vector<vector<int>>& _vecMemo)
{
	if (_vecMemo[_iA][_iB])
		return _vecMemo[_iA][_iB];

	if (_iB == 0 || _iA == _iB)
		return 1;

	return _vecMemo[_iA][_iB] = (Binomial(_iA - 1, _iB - 1, _vecMemo) + Binomial(_iA - 1, _iB, _vecMemo)) % MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	vector<vector<int>> vecMemo(1001, vector<int>(1001, 0));
	cout << Binomial(N, K, vecMemo);

	return 0;
}