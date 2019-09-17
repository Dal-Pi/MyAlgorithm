#if 1

//타잔의 강결합 컴포넌트 분리 알고리즘의 구현
//(방향 그래프에서 이루어진다)
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
//각 정점의 컴포넌트 번호
// 같은 강결합 컴포넌트에 속한 정점들의 컴포넌트 번호가 같다.
vector<int> sccId;
vector<int> discovered;
vector<bool> finished;
stack<int> st;

int sccCounter = 0;
int vertexCounter;

//here를 루트로 하는 서버트리에서 역방향 간선으로 닿을 수 있는 최소의 발견 순서를 반환한다
int scc(int here)
{
	int ret = discovered[here] = vertexCounter++;
	//here를 스택에 넣는다 here의 후손들은 모두 이후에 들어간다
	st.push(here);
	for (int i = 0; i < adj[here].size(); ++i)
	{
		int there = adj[here][i];
		//(here, there) 가 트리 간선인 경우
		if (-1 == discovered[there])
			ret = min(ret, scc(there));
		//(there, here) 가 역방향 간선인 경우 선조 정점의 발견 순서를 확인한다
		else if (discovered[there] < discovered[here] && finished[there])
			ret = min(ret, discovered[there]);
		//else 방향 그래프이므로 교차 간선이 존재할 수 있는데 
		// 이는 역방향 간선이라고 오판하게 만들 수 있으므로 유의 (교차 간선을 무시한다)
	}
	
	//here가 강결합 컴포넌트의 루트인지 확인한다
	if (ret == discovered[here])
	{
		//here를 루트로 하는 서브트리에 남아 있는 정점들을 전부 하나의 컴포넌트로 묶는다
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

//tarjan의 scc알고리즘
vector<int> tarjanSCC()
{
	sccId = discovered = vector<int>(adj.size(), -1);
	finished = vector<bool>(adj.size(), false);
	sccCounter = vertexCounter = 0;

	//모든 정점에 대하여 scc() 호출
	for (int i = 0; i < adj.size(); ++i)
		if (-1 == discovered[i])
			scc(i);
	return sccId;
}

#endif