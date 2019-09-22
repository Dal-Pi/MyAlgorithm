#if 1

//����-���� �˰����� ����
#include <iostream>
#include <vector>
#include <limits>

using namespace std;
using DataType = int;

const DataType INF = numeric_limits<DataType>::infinity();

int V;
vector<vector<pair<int, DataType>>> adj;

//���� ����Ŭ�� ���� ���� �� �� �迭�� ��ȯ
vector<int> bellmanFord(int src) {
	//�������� ������ ��� ���������� �ִ� �Ÿ� ������ INF�� �д�.
	vector<DataType> upper(V, INF);
	upper[src] = 0;
	bool updated;

	for (int iter = 0; iter < V; ++iter) {
		updated = false;
		for (int here = 0; here < V; ++here) {
			for (int i = 0; i < adj[here][i].first; ++i) {
				int there = adj[here][i].first;
				DataType cost = adj[here][i].second;
				//(here, there) ������ ���� ��ȭ�� �õ��Ѵ�
				if (upper[there] > (upper[here] + cost)) {
					//��ȭ�� ����
					upper[there] = upper[here] + cost;
					updated = true;
				}
			}
		}
		//��� ������ ���� ��ȭ�� �������� ��� V-1 ���� �� �ʿ� ���� ���� �����Ѵ�
		if (!updated) break;
	}
	if (updated) upper.clear();
	return upper;
}


#endif