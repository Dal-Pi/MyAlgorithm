#if 1

//������ �����ϴ� dfs
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
			cout << "tree edge" << endl; // Ʈ�� ����
			dfs2(there);
		}
		else if (discovered[here] < discovered[there])
			cout << "forward edge" << endl; // ������ ���� (there�� here�� �ļ�)
		else if (false == finished[there])
			cout << "back edge" << endl; // ������ ���� (there�� here�� ����)
		else
			cout << "back edge" << endl; // ���� ����
	}
	finished[here] = true;
}

#endif