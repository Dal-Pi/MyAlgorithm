#if 0

#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;
using DateType = int;

//다익스트라의 최단 거리 알고리즘의 구현
const int MAX_V = 100;

int V = 10;

vector<pair<int, DateType>> adj[MAX_V];
vector<int> dijkstra(int src) {
	vector<DateType> dist(V, numeric_limits<DateType>::max());
	dist[src] = 0;
	priority_queue<pair<int, DateType>> pq;
	pq.push(make_pair(0, src));
	while (!pq.empty()) {
		DateType cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if (dist[here] < cost) {
			continue;
		}
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			DateType nextDist = adj[here][i].second + cost;

			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}

#endif