#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Line {

	long long x1, y1, x2, y2;

};

vector<Line> points;
vector<int> parent;
vector<int> counts;

int maxGroup;
int N;

int FindRoot(int _origin) {

	if (parent[_origin] == _origin)
		return _origin;

	return parent[_origin] = FindRoot(parent[_origin]);

}

bool IsOverlab(Line _l1, Line _l2) {

	if (min(_l1.x1, _l1.x2) <= max(_l2.x1, _l2.x2) && min(_l2.x1, _l2.x2) <= max(_l1.x1, _l1.x2)
		&& min(_l1.y1, _l1.y2) <= max(_l2.y1, _l2.y2) && min(_l2.y1, _l2.y2) <= max(_l1.y1, _l1.y2))
		return true;

	return false;

}

long long CCW(pair<long long, long long> _p1, pair<long long, long long> _p2, pair<long long, long long> _p3) {

	long long result =  (_p1.first * _p2.second + _p2.first * _p3.second + _p3.first * _p1.second) -
		(_p2.first * _p1.second + _p3.first * _p2.second + _p1.first * _p3.second);


	if (result < 0)
		return -1;
	else if (result > 0)
		return 1;

	return 0;

}

bool IsCross(Line _l1, Line _l2) {

	int result1 = CCW({ _l1.x1, _l1.y1 }, { _l1.x2, _l1.y2 }, { _l2.x1, _l2.y1 });
	int result2 = CCW({ _l1.x1, _l1.y1 }, { _l1.x2, _l1.y2 }, { _l2.x2, _l2.y2 });
	int result3 = CCW({ _l2.x1, _l2.y1 }, { _l2.x2, _l2.y2 }, { _l1.x1, _l1.y1 });
	int result4 = CCW({ _l2.x1, _l2.y1 }, { _l2.x2, _l2.y2 }, { _l1.x2, _l1.y2 });

	if (result1 * result2 == 0 && result3 * result4 == 0) {
		return IsOverlab(_l1, _l2);
	}

	if (result1 * result2 <= 0 && result3 * result4 <= 0) {
		return true;
	}

	return false;
}


int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	parent.resize(N);
	points.resize(N);
	counts.resize(N, 1);


	for (int i = 0; i < N; ++i) {

		cin >> points[i].x1 >> points[i].y1 >> points[i].x2 >> points[i].y2;
		parent[i] = i;
	}


	for (int i = 0; i < N - 1; ++i) {
		for (int j = i + 1; j < N; ++j) {

			if (IsCross(points[i], points[j])) {
				int root1 = FindRoot(i);
				int root2 = FindRoot(j);

				if (root1 != root2) {
					parent[root1] = root2;
					counts[root2] += counts[root1];
				}

			}
		}
	}

	int GroupNum = 0;


	for (int i = 0; i < N; ++i) {

		if (parent[i] == i)
			++GroupNum;

	}

	cout << GroupNum << "\n";
	cout << *max_element(counts.begin(), counts.end());

	return 0;


}