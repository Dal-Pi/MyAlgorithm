#if 0

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

enum class RoomType : int
{
	UNWATCHED = 0,
	WATCHED = 1,
	INSTALLED = 2
};
int g = 0;
int installed = 0;

RoomType dfs(int here)
{
	visited[here] = true;
	map<RoomType, int> childrenMap;
	childrenMap[RoomType::UNWATCHED] = 0;
	childrenMap[RoomType::WATCHED] = 0;
	childrenMap[RoomType::INSTALLED] = 0;
	for (int i = 0; i < adj[here].size(); ++i)
	{
		int there = adj[here][i];
		if (!visited[there])
		{
			++childrenMap[dfs(there)];
		}
	}

	if (childrenMap[RoomType::UNWATCHED] > 0)
	{
		++installed;
		return RoomType::INSTALLED;
	}
	if (childrenMap[RoomType::INSTALLED] > 0)
	{
		return RoomType::WATCHED;
	}
	return RoomType::UNWATCHED;
}

int installCamera()
{
	visited = vector<bool>(g, false);
	installed = 0;
	for (int i = 0; i < adj.size(); ++i)
	{
		if (!visited[i] && dfs(i) == RoomType::UNWATCHED)
			++installed;
	}
	return installed;
}

int main()
{
	int C = 0;
	cin >> C;
	for (int testcase = 0; testcase < C; ++testcase)
	{
		int h = 0;
		cin >> g >> h;
		adj = vector<vector<int>>(g, vector<int>());
		int from = 0;
		int to = 0;
		for (int i = 0; i < h; ++i)
		{
			cin >> from >> to;
			adj[from].push_back(to);
			adj[to].push_back(from);
		}

		int ret = installCamera();
		cout << ret << endl;
	}
	return 0;
}

#endif