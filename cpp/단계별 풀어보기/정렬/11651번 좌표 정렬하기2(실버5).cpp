/*
* @title    : 11651�� ��ǥ �����ϱ�2(�ǹ�5)
* @content  : ����
* @author   : �յ���
* @date     : 240713
* @time     : 40 ms
* @memory   : 2804 KB
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

	int N;
	cin >> N;
	vector<pair<int, int>> v(N);

	for (int i = 0; i < N; ++i)
		cin >> v[i].second >> v[i].first;

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); ++i)
		cout << v[i].second << " " << v[i].first << "\n";

	return 0;
}