/*
* @title    : 2587�� ��ǥ��2(�����2)
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
#include <numeric>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> v(5);
	for (int i = 0; i < v.size(); ++i)
		cin >> v[i];

	int iSum = accumulate(v.begin(), v.end(), 0);
	sort(v.begin(), v.end());

	cout << iSum / 5.f << "\n" << v[2] << "\n";

	return 0;
}