/*
* @title    : 14003번 가장 긴 증가하는 부분 수열 5(플래티넘5)
* @content  : 동적 계획법
* @author   : 손동찬
* @date     : 240810
* @time     : 180 ms
* @memory   : 17644 KB
* @state    : 완료
*/
#include <iostream>

using namespace std;

int Datas[1000001];
int Compare[1000001];
int Length[1000001];
int answer[1000001];

int BS(int L, int R, int now)
{
	int mid;

	while (L < R)
	{
		mid = (L + R) / 2;
		if (Compare[mid] < now)
			L = mid + 1;
		else
			R = mid;
	}

	return L;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> Datas[i];

	int Index = 0, MaxLength = 1;
	Compare[MaxLength] = Datas[1];
	Length[1] = 1;

	for (int i = 2; i <= N; ++i)
	{
		if (Compare[MaxLength] < Datas[i])
		{
			Compare[++MaxLength] = Datas[i];
			Length[i] = MaxLength;
		}
		else
		{
			Index = BS(1, MaxLength, Datas[i]);
			Compare[Index] = Datas[i];
			Length[i] = Index;
		}
	}

	cout << MaxLength << "\n";

	Index = MaxLength;

	int X = Compare[MaxLength] + 1;

	for (int i = N; i >= 1; --i)
		if (Length[i] == Index && Datas[i] < X)
		{
			answer[Index] = Datas[i];
			X = Datas[i];
			--Index;
		}
	
	for (int i = 1; i <= MaxLength; ++i)
		cout << answer[i] << " ";

	return 0;
}