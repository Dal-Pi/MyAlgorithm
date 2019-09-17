#if 0

//�׷����� �ʺ� �켱 Ž��
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;

vector<int> bfs(int start)
{
	//�� ������ �湮 ����
	vector<bool> discovered(adj.size(), false);
	//�湮�� ���� ����� �����ϴ� ť
	queue<int> q;
	//������ �湮 ����
	vector<int> order;

	discovered[start] = true;
	q.push(start);
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		order.push_back(here);
		for (int i = 0; i < adj[here].size; ++i)
		{
			int there = adj[here][i];
			//ó�� ���� �����̸� �湮 ��Ͽ� �־� �ش�
			if (!discovered[there])
			{
				q.push(there);
				discovered[there] = true;
			}
		}
	}
	return order;
}

#endif