#if 0

#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;
using DataType = int;
using QuePairType = pair<DataType, int>;
using AdjPairType = pair<int, DataType>;

//다익스트라의 최단 거리 알고리즘의 구현
const int MAX_V = 100;

int V = 10;

vector<vector<AdjPairType>> adj;
vector<int> dijkstra(int src) {
	vector<DataType> dist(V, numeric_limits<DataType>::max());
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

#endif