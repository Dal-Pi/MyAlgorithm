#if 0

//최단 경로를 계산하는 너비 우선 탐색
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> distances;
vector<int> parent;

//start에서 시작해 그래프를 너비 우선 탐색하고 시작점부터 각 정점까지의
// 최단 거리와 너비 우선 탐색 스패닝 트리를 계산한다
// distances[i] = start로부터 i까지의 최단 거리
// parent[i] = 너비 우선 탐색 스패닝 트리에서 i의 부모의 번호. 루트인 경우 자기자신
void bfs2(int start)
{
	distances = vector<int>(adj.size(), -1);
	parent = vector<int>(adj.size(), -1);
	//방문할 정점 목록을 유지하는 큐
	queue<int> q;
	distances[start] = 0;
	parent[start] = start;
	q.push(start);
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		for (int i = 0; i < adj[here].size; ++i)
		{
			int there = adj[here][i];
			//처음 보는 정점이면 방문 목록에 넣어 준다
			if (-1 == distances[there])
			{
				q.push(there);
				distances[there] = distances[here] + 1;
				parent[there] = here;
			}
		}
	}
}

#endif