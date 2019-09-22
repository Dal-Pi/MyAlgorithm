#if 1

//벨만-포드 알고리즘의 구현
#include <iostream>
#include <vector>
#include <limits>

using namespace std;
using DataType = int;

const DataType INF = numeric_limits<DataType>::infinity();

int V;
vector<vector<pair<int, DataType>>> adj;

//음수 사이클이 있을 때는 텅 빈 배열을 반환
vector<int> bellmanFord(int src) {
	//시작점을 제외한 모든 정점까지의 최단 거리 상한을 INF로 둔다.
	vector<DataType> upper(V, INF);
	upper[src] = 0;
	bool updated;

	for (int iter = 0; iter < V; ++iter) {
		updated = false;
		for (int here = 0; here < V; ++here) {
			for (int i = 0; i < adj[here][i].first; ++i) {
				int there = adj[here][i].first;
				DataType cost = adj[here][i].second;
				//(here, there) 간선을 따라 완화를 시도한다
				if (upper[there] > (upper[here] + cost)) {
					//완화에 성공
					upper[there] = upper[here] + cost;
					updated = true;
				}
			}
		}
		//모든 간선에 대해 완화가 실패했을 경우 V-1 번도 돌 필요 없이 곧장 종료한다
		if (!updated) break;
	}
	if (updated) upper.clear();
	return upper;
}


#endif