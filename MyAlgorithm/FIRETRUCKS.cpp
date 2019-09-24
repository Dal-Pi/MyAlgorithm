#if 0

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

using DataType = int;

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

vector<vector<Edge>> adj;

int V;

vector<int> dijkstra(int src) {
	vector<int> dist = vector<int>(V + 1, numeric_limits<int>::max());
	dist[src] = 0;
	priority_queue<Edge, vector<Edge>, EdgeGreater> pq;
	pq.push(Edge(src, 0));

	while (!pq.empty()) {
		int cost = pq.top().weight;
		int here = pq.top().node;
		pq.pop();
		if (dist[here] < cost) {
			continue;
		}
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].node;
			int nextDist = adj[here][i].weight + cost;

			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(Edge(there, nextDist));
			}
		}
	}
	return dist;
}

int main() {
	int C = 0;
	cin >> C;
	for (int testcase = 0; testcase < C; ++testcase) {
		int E;
		int n, m;
		cin >> V >> E >> n >> m;
		adj = vector<vector<Edge>>(V + 1);
		int a, b, t;
		for (int i = 0; i < E; ++i) {
			cin >> a >> b >> t;
			adj[a - 1].push_back(Edge(b - 1, t));
			adj[b - 1].push_back(Edge(a - 1, t));
		}
		vector<int> fires;
		int input;
		for (int i = 0; i < n; ++i) {
			cin >> input;
			fires.push_back(input - 1);
		}
		vector<int> starts;
		for (int i = 0; i < m; ++i) {
			cin >> input;
			starts.push_back(input - 1);
		}
		for (auto start : starts) {
			adj[V].push_back(Edge(start, 0));
		}

		auto dist = dijkstra(V);
		int sum = 0;
		for (auto fire : fires) {
			sum += dist[fire];
		}
		cout << sum << endl;
	}
	return 0;
}

#endif