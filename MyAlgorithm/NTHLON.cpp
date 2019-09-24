#if 0

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <limits>

using namespace std;
using DataType = int;
using QuePairType = pair<DataType, int>;
using AdjPairType = pair<int, DataType>;

int V;
const int START = 401;
const int INF = numeric_limits<int>::max();

vector<vector<pair<int, int>>> adj;

struct Edge {
	int node;
	DataType weight;
	Edge(int _node, DataType _weight) : node(_node), weight(_weight) {}
};

struct EdgeGreater {
	bool operator()(const Edge& lhs, const Edge& rhs) const
	{
		return lhs.weight > rhs.weight;
	}
};

vector<int> dijkstra(int src) {
	vector<DataType> dist(V, INF);
	dist[src] = 0;
	priority_queue<QuePairType, vector<QuePairType>, greater<QuePairType>> pq;
	pq.push(make_pair(0, src));
	while (!pq.empty()) {
		DataType cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) {
			continue;
		}
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			DataType nextDist = adj[here][i].second + cost;

			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(nextDist, there));
			}
		}
	}
	return dist;
}

int vertex(int delta) {
	return delta + 200;
}

int solve(const vector<int>& a, const vector<int>& b) {
	V = 402;
	//for (int i = 0; i < V; ++i)
	//	adj[i].clear();
	adj = vector<vector<pair<int, int>>>(410);
	for (int i = 0; i < a.size(); ++i) {
		int delta = a[i] - b[i];
		adj[START].push_back(make_pair(vertex(delta), a[i]));
	}
	//현재 차이
	for (int delta = -200; delta <= 200; ++delta) {
		//i번 종목을 뒤에 붙인다면?
		for (int i = 0; i < a.size(); ++i) {
			int next = delta + a[i] - b[i];
			//시간 차이의 절대값이 200을 넘는 정점은 만들 필요가 없다
			if (abs(next) > 200)
				continue;
			adj[vertex(delta)].push_back(make_pair(vertex(next), a[i]));
		}
	}
	vector<int> shortest = dijkstra(START);
	int ret = shortest[vertex(0)];
	if (INF == ret)
		return -1;
	return ret;
}

int main() {
	int C = 0;
	cin >> C;
	for (int testcase = 0; testcase < C; ++testcase) {
		int m;
		cin >> m;
		int a, b;
		vector<int> alist, blist;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b;
			alist.push_back(a);
			blist.push_back(b);
		}
		auto ret = solve(alist, blist);
		if (-1 == ret)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << ret << endl;
	}
	return 0;
}

#endif