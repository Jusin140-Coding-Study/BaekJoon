/*
* @title    : 11050�� ���� ��� 1(�����1)
* @content  : ����
* @author   : �յ���
* @date     : 240805
* @time     : 0ms
* @memory   : 2020 KB
* @state    : �Ϸ�
*/
#include <iostream>

using namespace std;

int Binomial(int _iA, int _iB)
{
	if (_iB == 0 || _iA == _iB)
		return 1;

	return Binomial(_iA - 1, _iB - 1) + Binomial(_iA - 1, _iB);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	cout << Binomial(N, K);

	return 0;
}