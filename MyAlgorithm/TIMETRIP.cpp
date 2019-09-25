#if 0

#include <iostream>
#include <vector>
#include <limits>
#include <string>
#include <algorithm>

using namespace std;

using DataType = int;
const int MAX_V = 100;
const int INF = 987654321;

struct Edge {
	int node;
	DataType weight;
	Edge(int _node, DataType _weight) : node(_node), weight(_weight) {}
};

vector<vector<Edge>> adj;
bool reachable[MAX_V][MAX_V];

int V;

void floyd_reachable() {
	for (int i = 0; i < V; ++i)
		reachable[i][i] = true;
	for (int k = 0; k < V; ++k)
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V; ++j)
				if (reachable[i][j] || (reachable[i][k] && reachable[k][j]))
					reachable[i][j] = true;
}

int bellman2(int src, int target) {
	vector<int> upper(V, INF);
	upper[src] = 0;

	for (int iter = 0; iter < V - 1; ++iter) {
		for (int here = 0; here < V; ++here) {
			for (int i = 0; i < adj[here].size(); ++i) {
				int there = adj[here][i].node;
				int cost = adj[here][i].weight;
				//(here, there) ������ ���� ��ȭ�� �õ��Ѵ�
				upper[there] = min(upper[there], upper[here] + cost);
			}
		}
	}
	//���� ����Ŭ�� �ִ��� Ȯ���Ѵ�
	for (int here = 0; here < V; ++here) {
		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].node;
			int cost = adj[here][i].weight;
			//��ȭ�� �����Ѵٸ� here�� there ��� ���� ����Ŭ�� ��� �ִ�
			if (upper[there] > upper[here] + cost) {
				//�� ���� ����Ŭ�� �����ϴ� ��ΰ� �ִ°�?
				if (reachable[src][here] && reachable[here][target]) {
					return -(INF);
				}
			}
		}
	}
	return upper[target];
}

string getString(int n, int m) {
	if (abs(n) >= INF - m) return "INFINITY";
	return to_string(n);
}

int main() {
	int C = 0;
	cin >> C;
	for (int testcase = 0; testcase < C; ++testcase) {
		int W;
		cin >> V >> W;
		int a, b;
		DataType d;
		adj = vector<vector<Edge>>(V);
		for (int i = 0; i < V; ++i) {
			for (int j = 0; j < V; ++j) {
				reachable[i][j] = false;
			}
		}
		bool direct = false;
		DataType directW = INF;
		for (int i = 0; i < W; ++i) {
			cin >> a >> b >> d;
			if (a == 0 && b == 1) {
				direct = true;
				directW = d;
			}
			adj[a].push_back(Edge(b, d));
			reachable[a][b] = true;
		}
		DataType M = V * W * 1000;
		floyd_reachable();
		DataType min = bellman2(0, 1);
		for (int here = 0; here < V; ++here)
			for (int i = 0; i < adj[here].size(); ++i)
				adj[here][i].weight *= -1;
		DataType max = bellman2(0, 1);

		
		if (reachable[0][1]) {
			cout << getString(min, M) << " " << getString(-max, M) << endl;
		}
		else {
			cout << "UNREACHABLE" << endl;
		}
	}
	return 0;
}

#endif