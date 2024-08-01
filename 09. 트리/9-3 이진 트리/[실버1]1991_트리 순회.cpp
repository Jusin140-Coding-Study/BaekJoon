#include <iostream>
#include <vector>
using namespace std;

static int BinaryTree[26][2];
void Front(int curNode);
void Center(int curNode);
void Back(int curNode);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		char Node, lChild, rChild;
		cin >> Node >> lChild >> rChild;

		if ('.' != lChild)
			BinaryTree[(Node - 'A')][0] = lChild - 'A';
		else
			BinaryTree[(Node - 'A')][0] = -1;

		if ('.' != rChild)
			BinaryTree[(Node - 'A')][1] = rChild - 'A';
		else
			BinaryTree[(Node - 'A')][1] = -1;
	}

	Front(0);
	cout << "\n";

	Center(0);
	cout << "\n";

	Back(0);
	cout << "\n";

	return 0;
}

// 전위 순회 : 부모->왼쪽->오른쪽
void Front(int curNode)
{
	if (-1 == curNode) return;

	cout << char(curNode + 'A');
	Front(BinaryTree[curNode][0]);
	Front(BinaryTree[curNode][1]);
}

// 중위 순회 : 왼쪽->부모->오른쪽
void Center(int curNode)
{
	if (-1 == curNode) return;

	Center(BinaryTree[curNode][0]);
	cout << char(curNode + 'A');
	Center(BinaryTree[curNode][1]);
}

// 후위 순회 : 왼쪽->오른쪽->부모
void Back(int curNode)
{
	if (-1 == curNode) return;

	Back(BinaryTree[curNode][0]);
	Back(BinaryTree[curNode][1]);
	cout << char(curNode + 'A');
}