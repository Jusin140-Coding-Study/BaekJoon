#include <iostream>
#include <vector>
using namespace std;

struct Node
{
	int parentIndex = 0;
	int myIndex = 0;

	Node* parentNode = nullptr;
	vector<Node*> childNodes = {};
};

static vector<Node*> vecNodes;
void DFS(int index);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0; int Result = 0;
	cin >> N;

	vecNodes = vector<Node*>(N, nullptr);

	// Ʈ���� �����Ѵ�.
	for (int i = 0; i < N; ++i)
	{
		int iInput = 0;
		cin >> iInput;

		Node* pNode = new Node;

		// ��Ʈ ����� ���
		if (-1 == iInput)
		{
			pNode->parentIndex = -1;
			pNode->myIndex = i;
		}
		else
		{
			pNode->parentIndex = iInput;
			pNode->myIndex = i;
		}

		vecNodes[i] = pNode;
	}

	for (int i = 0; i < N; ++i)
	{
		if (-1 == vecNodes[i]->parentIndex) continue;

		vecNodes[i]->parentNode = vecNodes[vecNodes[i]->parentIndex];
		vecNodes[i]->parentNode->childNodes.push_back(vecNodes[i]);
	}

	int removeIndex = 0;
	cin >> removeIndex;

	DFS(removeIndex);

	// �ڽ��� �θ𿡰Լ� �ڽ��� nullptr�� �����.
	Node* pParent = vecNodes[removeIndex]->parentNode;
	if (nullptr != pParent)
	{
		for (int i = 0; i < pParent->childNodes.size(); ++i)
		{
			if (vecNodes[removeIndex] == pParent->childNodes[i])
				pParent->childNodes[i] = nullptr;
		}
	}
	vecNodes[removeIndex] = nullptr;

	for (int i = 0; i < N; ++i)
	{
		if (nullptr != vecNodes[i])
		{
			// �ڽ� ����� ������ 0 �̰ų�, 1���ε� �°� nullptr�� ���, �������� ����
			if (vecNodes[i]->childNodes.empty() ||
				(1 == vecNodes[i]->childNodes.size() && nullptr == vecNodes[i]->childNodes[0]))
			{
				++Result;
			}
		}
	}

	for (int i = 0; i < N; ++i)
		vecNodes[i] = nullptr;

	cout << Result;

	return 0;
}

// �ε����� �ش��ϴ� ����� �ڽĵ��� �� �� nullptr�� ��������
void DFS(int index)
{
	Node* pNode = vecNodes[index];

	for (int i = 0; i < pNode->childNodes.size(); ++i)
	{
		DFS(pNode->childNodes[i]->myIndex);

		vecNodes[pNode->childNodes[i]->myIndex] = nullptr;
		pNode->childNodes[i] = nullptr;
	}
}