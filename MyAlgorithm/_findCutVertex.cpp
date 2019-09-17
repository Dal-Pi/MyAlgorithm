#if 0

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//그래프의 인접 리스트 표현
vector<vector<int>> adj;
//각 정점의 발견 순서, -1로 초기화한다
vector<int> discovered;
//각 정점이 절단점인지 여부를 저장한다. false로 초기화한다
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
			//루트인 경우 절단점 판정을 위해서는 자손 서브트리의 개수를 구해둬야 한다
			++children;
			//서브트리에서 역방향 간선으로 갈 수 있는 가장 높은 정점의 번호
			int subtree = findCutVertex(there, false);
			//그 노드가 here 이하에 있다면 현재 위치는 절단점이다
			if (!isRoot && subtree >= discovered[there])
				isCutVertex[there] = true;
			ret = min(ret, subtree);
		}
		else
		{
			ret = min(ret, discovered[there]);
		}
	}
	//루트인 경우에는 절단점 판정은 서브트리의 개수로 판단한다.
	//자손이 하나도 없거나 하나인 경우에는 절단점이 아니기 때문
	if (isRoot)
		isCutVertex[here] = (children >= 2);
	return ret;
}


#endif