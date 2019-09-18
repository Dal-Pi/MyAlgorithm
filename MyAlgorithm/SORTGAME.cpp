#if 0

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

map<vector<int>, int> toSort;

void precalc(int n)
{
	vector<int> perm(n);
	for (int i = 0; i < n; ++i)
	{
		perm[i] = i;
	}
	queue<vector<int>> q;
	q.push(perm);
	toSort[perm] = 0;
	while (!q.empty())
	{
		auto here = q.front();
		q.pop();
		int cost = toSort[here];
		for (int i = 0; i < n; ++i)
		{
			for (int j = i + 2; j <= n; ++j)
			{
				reverse(begin(here) + i, begin(here) + j);
				if (toSort.count(here) == 0)
				{
					toSort[here] = cost + 1;
					q.push(here);
				}
				reverse(begin(here) + i, begin(here) + j);
			}
		}
	}
}

int solve(const vector<int>& perm)
{
	int n = perm.size();
	vector<int> fixed(n);
	for (int i = 0; i < n; ++i)
	{
		int smaller = 0;
		for (int j = 0; j < n; ++j)
		{
			if (perm[j] < perm[i])
				++smaller;
		}
		fixed[i] = smaller;
	}
	return toSort[fixed];
}

int main()
{
	int C = 0;
	cin >> C;
	for (int testcase = 0; testcase < C; ++testcase)
	{
		int N;
		cin >> N;
		vector<int> perm;
		int input = 0;
		for (int i = 0; i < N; ++i)
		{
			cin >> input;
			perm.push_back(input);
		}
		precalc(N);
		cout << solve(perm) << endl;
	}
	return 0;
}

#endif