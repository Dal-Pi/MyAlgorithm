#if 0

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//�׷����� ���� ����Ʈ ǥ��
vector<vector<int>> adj;
//�� ������ �߰� ����, -1�� �ʱ�ȭ�Ѵ�
vector<int> discovered;
//�� ������ ���������� ���θ� �����Ѵ�. false�� �ʱ�ȭ�Ѵ�
vector<bool> isCutVertex;
int counter = 0;

int findCutVertex(int here, bool isRoot)
{
	discovered[here] = counter++;
	int ret = discovered[here];

	int children = 0;
	for (int i = 0; i < adj[here].size(); ++i)
	{
		int there = adj[here][i];
		if (-1 == discovered[there])
		{
			//��Ʈ�� ��� ������ ������ ���ؼ��� �ڼ� ����Ʈ���� ������ ���ص־� �Ѵ�
			++children;
			//����Ʈ������ ������ �������� �� �� �ִ� ���� ���� ������ ��ȣ
			int subtree = findCutVertex(there, false);
			//�� ��尡 here ���Ͽ� �ִٸ� ���� ��ġ�� �������̴�
			if (!isRoot && subtree >= discovered[there])
				isCutVertex[there] = true;
			ret = min(ret, subtree);
		}
		else
		{
			ret = min(ret, discovered[there]);
		}
	}
	//��Ʈ�� ��쿡�� ������ ������ ����Ʈ���� ������ �Ǵ��Ѵ�.
	//�ڼ��� �ϳ��� ���ų� �ϳ��� ��쿡�� �������� �ƴϱ� ����
	if (isRoot)
		isCutVertex[here] = (children >= 2);
	return ret;
}


#endif