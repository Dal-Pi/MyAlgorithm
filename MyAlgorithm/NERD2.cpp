#if 0

#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> coords;

bool isDominated(int x, int y)
{
	auto it = coords.lower_bound(x);
	if (end(coords) == it)
		return false;
	return y < it->second;
}

void removeDominated(int x, int y)
{
	auto it = coords.lower_bound(x);
	if (begin(coords) == it)
		return;
	--it;
	while (true)
	{
		if (it->second > y)
			break;

		if (begin(coords) == it)
		{
			coords.erase(it);
			break;
		}
		else
		{
			auto jt = it;
			--jt;
			coords.erase(it);
			it = jt;
		}
	}
}

int registered(int x, int y)
{
	if (isDominated(x, y))
		return coords.size();
	removeDominated(x, y);
	coords[x] = y;
	return coords.size();
}

int main()
{
	int C = 0;
	cin >> C;
	for (int testcase = 0; testcase < C; ++testcase)
	{
		coords.clear();
		int N;
		cin >> N;
		int countProblem = 0;
		int countNoodle = 0;
		int ret = 0;
		for (int i = 0; i < N; ++i)
		{
			cin >> countProblem >> countNoodle;
			ret += registered(countProblem, countNoodle);
		}
		cout << ret << endl;
	}
	return 0;
}

#endif