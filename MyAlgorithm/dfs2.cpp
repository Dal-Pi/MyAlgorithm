#if 1

//간선을 구분하는 dfs
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> discovered;
vector<bool> finished;
int counter = 0;

void dfs2(int here)
{
	discovered[here] = counter++;

	for (int i = 0; i < adj[here].size(); ++i)
	{
		int there = adj[here][i];
		if (-1 == discovered[there])
		{
			cout << "tree edge" << endl; // 트리 간선
			dfs2(there);
		}
		else if (discovered[here] < discovered[there])
			cout << "forward edge" << endl; // 순방향 간선 (there는 here의 후손)
		else if (false == finished[there])
			cout << "back edge" << endl; // 역방향 간선 (there는 here의 선조)
		else
			cout << "back edge" << endl; // 교차 간선
	}
	finished[here] = true;
}

#endif