/*
* @title    : 1920�� �� ã��(�ǹ�4)
* @content  : ����Ž��
* @author   : �յ���
* @date     : 240714
* @time     : 48 ms
* @memory   : 2412 KB
* @state    : �Ϸ�
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool BinarySearch(vector<int>& _vecNumData, int& _iTarget)
{
	int iStart = 0, iEnd = _vecNumData.size() - 1;

	while (iStart <= iEnd)
	{
		int iMiddleIndex = (iStart + iEnd) / 2;

		if (_vecNumData[iMiddleIndex] == _iTarget)
			return true;

		else if (_vecNumData[iMiddleIndex] > _iTarget)
			iEnd = iMiddleIndex - 1;

		else
			iStart = iMiddleIndex + 1;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;
	vector<int> vecNumData(N);
	for (int i = 0; i < N; ++i)
		cin >> vecNumData[i];
	sort(vecNumData.begin(), vecNumData.end());
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int iTarget;
		cin >> iTarget;	
		cout << BinarySearch(vecNumData, iTarget) << "\n";
	}

	return 0;
}