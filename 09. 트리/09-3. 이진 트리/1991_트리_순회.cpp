#include <iostream>
#include <vector>

using namespace std;


void Preorder(int cur);
void Inorder(int cur);
void Postorder(int cur);

int N;
vector<pair<int, int>> nodes;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	nodes.resize(N + 1);

	for (int i = 1; i <= N; ++i) {
		char parent;
		char f, s;
		cin >> parent >> f >> s;

		nodes[parent - 'A' + 1] = { f - 'A' + 1 , s - 'A' + 1 };

	}

	Preorder(1);
	cout << "\n";
	Inorder(1);
	cout << "\n";
	Postorder(1);

	return 0;
}


void Preorder(int cur) {

	if (-18 == cur)
		return;

	cout << (char)(cur + 'A' - 1);
	Preorder(nodes[cur].first);
	Preorder(nodes[cur].second);

};

void Inorder(int cur) {

	if (-18 == cur)
		return;

	Inorder(nodes[cur].first);
	cout << (char)(cur + 'A' - 1);
	Inorder(nodes[cur].second);
};

void Postorder(int cur) {

	if (-18 == cur)
		return;

	Postorder(nodes[cur].first);
	Postorder(nodes[cur].second);
	cout << (char)(cur + 'A' - 1);
};

