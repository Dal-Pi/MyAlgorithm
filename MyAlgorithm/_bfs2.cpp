#if 0

//�ִ� ��θ� ����ϴ� �ʺ� �켱 Ž��
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<int> distances;
vector<int> parent;

//start���� ������ �׷����� �ʺ� �켱 Ž���ϰ� ���������� �� ����������
// �ִ� �Ÿ��� �ʺ� �켱 Ž�� ���д� Ʈ���� ����Ѵ�
// distances[i] = start�κ��� i������ �ִ� �Ÿ�
// parent[i] = �ʺ� �켱 Ž�� ���д� Ʈ������ i�� �θ��� ��ȣ. ��Ʈ�� ��� �ڱ��ڽ�
void bfs2(int start)
{
	distances = vector<int>(adj.size(), -1);
	parent = vector<int>(adj.size(), -1);
	//�湮�� ���� ����� �����ϴ� ť
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
			//ó�� ���� �����̸� �湮 ��Ͽ� �־� �ش�
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