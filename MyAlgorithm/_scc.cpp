#if 1

//Ÿ���� ������ ������Ʈ �и� �˰����� ����
//(���� �׷������� �̷������)
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

#endif