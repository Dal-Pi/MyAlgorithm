#if 0

//unsolved

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
//�� ������ ������Ʈ ��ȣ
// ���� ������ ������Ʈ�� ���� �������� ������Ʈ ��ȣ�� ����.
vector<int> sccId;
vector<int> discovered;
vector<bool> finished;
stack<int> st;

int sccCounter = 0;
int vertexCounter;

//here�� ��Ʈ�� �ϴ� ����Ʈ������ ������ �������� ���� �� �ִ� �ּ��� �߰� ������ ��ȯ�Ѵ�
int scc(int here)
{
	int ret = discovered[here] = vertexCounter++;
	//here�� ���ÿ� �ִ´� here�� �ļյ��� ��� ���Ŀ� ����
	st.push(here);
	for (int i = 0; i < adj[here].size(); ++i)
	{
		int there = adj[here][i];
		//(here, there) �� Ʈ�� ������ ���
		if (-1 == discovered[there])
			ret = min(ret, scc(there));
		//(there, here) �� ������ ������ ��� ���� ������ �߰� ������ Ȯ���Ѵ�
		else if (discovered[there] < discovered[here] && finished[there])
			ret = min(ret, discovered[there]);
		//else ���� �׷����̹Ƿ� ���� ������ ������ �� �ִµ� 
		// �̴� ������ �����̶�� �����ϰ� ���� �� �����Ƿ� ���� (���� ������ �����Ѵ�)
	}

	//here�� ������ ������Ʈ�� ��Ʈ���� Ȯ���Ѵ�
	if (ret == discovered[here])
	{
		//here�� ��Ʈ�� �ϴ� ����Ʈ���� ���� �ִ� �������� ���� �ϳ��� ������Ʈ�� ���´�
		while (true)
		{
			int t = st.top();
			st.pop();
			sccId[t] = sccCounter;
			if (t == here) break;
		}
		++sccCounter;
	}

	finished[here] = true;
	return ret;
}

//tarjan�� scc�˰���
vector<int> tarjanSCC()
{
	sccId = discovered = vector<int>(adj.size(), -1);
	finished = vector<bool>(adj.size(), false);
	sccCounter = vertexCounter = 0;

	//��� ������ ���Ͽ� scc() ȣ��
	for (int i = 0; i < adj.size(); ++i)
		if (-1 == discovered[i])
			scc(i);
	return sccId;
}

bool disjoint(const pair<int, int>& x, const pair<int, int>& y)
{
	return x.second <= y.first || y.second <= x.first;
}

void makeGraph(const vector<pair<int, int>>& meetings)
{
	int vars = meetings.size();
	adj.clear();
	adj.resize(vars * 2);
	for (int i = 0; i < vars; i += 2)
	{
		int j = i + 1;
		adj[i * 2 + 1].push_back(j * 2);
		adj[j * 2 + 1].push_back(i * 2);
	}
	for (int i = 0; i < vars; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (!disjoint(meetings[i], meetings[j]))
			{
				adj[i * 2].push_back(j * 2 + 1);
				adj[j * 2].push_back(i * 2 + 1);
			}
		}
	}
}

vector<int> solve2SAT()
{
	int n = adj.size() / 2;
	vector<int> label = tarjanSCC();
	for (int i = 0; i < 2 * n; i += 2)
		if (label[i] == label[i + 1])
			return vector<int>();

	vector<int> value(2 * n, -1);
	vector<pair<int, int>> order;
	for (int i = 0; i < n * 2; ++i)
		order.push_back(make_pair(-label[i], i));
	sort(begin(order), end(order));

	for (int i = 0; i < n * 2; ++i)
	{
		int vertex = order[i].second;
		int variable = vertex / 2;
		bool isTrue = vertex % 2 == 0;
		if (value[variable] != -1)
			continue;
		value[variable] = !isTrue;
	}
	return value;
}

int main()
{
	int C = 0;
	cin >> C;
	for (int testcase = 0; testcase < C; ++testcase)
	{
		int N = 0;
		cin >> N;
		int a, b, c, d;
		vector<pair<int, int>> meetings;
		for (int i = 0; i < N; ++i)
		{
			cin >> a >> b >> c >> d;
			meetings.push_back(make_pair(a, b));
			meetings.push_back(make_pair(c, d));
		}
		makeGraph(meetings);
		auto values = solve2SAT();

		cout << endl;
	}
	return 0;
}

#endif