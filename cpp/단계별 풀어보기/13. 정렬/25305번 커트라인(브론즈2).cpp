/*
* @title    : 25305�� ĿƮ����(�����2)
* @content  : ����
* @author   : �յ���
* @date     : 240713
* @time     : 0ms
* @memory   : 2020 KB
* @state    : �Ϸ�
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

	int N, k;
	cin >> N >> k;
	vector<int> v(N);
	for (int i = 0; i < N; ++i)
		cin >> v[i];
	
	sort(v.rbegin(), v.rend());

	cout << v[k - 1] << "\n";

	return 0;
}