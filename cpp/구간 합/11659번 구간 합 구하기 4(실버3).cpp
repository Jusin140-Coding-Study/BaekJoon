/*
* @title    : 11659번 구간 합 구하기 4(실버3)
* @content  :
* @author   : 손동찬
* @date     : 240708
* @time     : 40 ms
* @memory   : 2916 KB
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

	vector<int> v = {0};
	int iSum = 0;

	for (int i = 0; i < N; ++i) {
		int iNum;
		cin >> iNum;
		iSum += iNum;
		v.push_back(iSum);
	}

	int iResult = 0;
	for (int i = 0; i < M; ++i) {
		int iStart, iEnd;
		cin >> iStart >> iEnd;
		cout << v[iEnd] - v[iStart - 1] << "\n";
	}
}