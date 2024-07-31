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

	// 트리를 생성한다.
	for (int i = 0; i < N; ++i)
	{
		int iInput = 0;
		cin >> iInput;

		Node* pNode = new Node;

		// 루트 노드인 경우
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

	// 자신의 부모에게서 자신을 nullptr로 만든다.
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
			// 자식 노드의 개수가 0 이거나, 1개인데 걔가 nullptr인 경우, 리프노드로 간주
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

// 인덱스에 해당하는 노드의 자식들을 싹 다 nullptr로 만들어버림
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