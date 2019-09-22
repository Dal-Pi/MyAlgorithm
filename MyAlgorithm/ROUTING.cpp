#if 0

#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;
using DataType = double;

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

int N;

vector<vector<Edge>> adj;

vector<DataType> dijkstra(int src) {
	vector<DataType> dist(N, numeric_limits<DataType>::max());
	dist[src] = 1.0;
	priority_queue<Edge, vector<Edge>, EdgeGreater> pq;
	pq.push(Edge(src, 1.0));
	while (!pq.empty()) {
		DataType cost = pq.top().weight;
		int here = pq.top().node;
		pq.pop();

		if (dist[here] < cost) {
			continue;
		}
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].node;
			DataType nextDist = adj[here][i].weight * cost;

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
		int M;
		cin >> N >> M;
		adj = vector<vector<Edge>>(N);
		int a, b;
		DataType c;
		for (int i = 0; i < M; ++i) {
			cin >> a >> b >> c;
			adj[a].push_back(Edge(b, c));
			adj[b].push_back(Edge(a, c));
		}
		auto ret = dijkstra(0);
		cout << fixed << setprecision(10) << setfill('0') << ret[N - 1] << endl;
	}
	return 0;
}

#endif