/*
* @title    : 1947번 선물 전달(골드3)
* @content  : 조합
* @author   : 손동찬
* @date     : 240806
* @time     :  ms
* @memory   :  KB
* @state    : 완료
*/
#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000000

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<long long> v(N + 1);

	v[1] = 0;
	v[2] = 1;

	for (int i = 3; i <= N; ++i)
		v[i] = ((i - 1) * (v[i - 1] + v[i - 2])) % MOD;
	
	cout << v[N];

	return 0;
} 