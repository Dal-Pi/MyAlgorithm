#if 0

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_DISCS = 12;
const int MASK = 3;
int get(int state, int index)
{
	return (state >> (index * 2)) & MASK;
}

int set(int state, int index, int value)
{
	return (state & ~(MASK << (index * 2))) | (value << (index * 2));
}

int sgn(int x)
{
	if (!x)
		return 0;
	return x > 0 ? 1 : -1;
}

int absIncrease(int x)
{
	if (x < 0)
		return x - 1;
	else
		return x + 1;
}

int c[1 << (MAX_DISCS * 2)];

/*
//단방향 탐색 (시간초과)
int bfs(int discs, int begin, int end)
{
	if (begin == end)
		return 0;
	queue<int> q;
	memset(c, -1, sizeof(c));
	q.push(begin);
	c[begin] = 0;
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		int top[4]{ -1,-1,-1,-1 };
		//각 기둥에서 제일 위에 있는 원반의 번호를 계산한다
		for (int i = discs - 1; i >= 0; --i)
		{
			top[get(here, i)] = i;
		}

		//i번 기둥의 맨 위에 있는 원반을 j번 기둥으로 옮긴다.
		for (int i = 0; i < 4; ++i)
		{
			if (top[i] != -1)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (i != j && (top[j] == -1 || top[i] < top[j]))
					{
						int there = set(here, top[i], j);
						if (c[there] != -1)
							continue;
						c[there] = c[here] + 1;
						if (there == end)
							return c[there];
						q.push(there);
					}
				}
			}
		}
	}
	return -1;
}
*/

//양방향 탐색
int bfs(int discs, int begin, int end)
{
	if (begin == end)
		return 0;
	queue<int> q;
	memset(c, 0, sizeof(c));
	q.push(begin);
	c[begin] = 1;
	q.push(end);
	c[end] = -1;
	while (!q.empty())
	{
		int here = q.front();
		q.pop();
		int top[4] { -1,-1,-1,-1 };
		//각 기둥에서 제일 위에 있는 원반의 번호를 계산한다
		for (int i = discs - 1; i >= 0; --i)
		{
			top[get(here, i)] = i;
		}

		//i번 기둥의 맨 위에 있는 원반을 j번 기둥으로 옮긴다.
		for (int i = 0; i < 4; ++i)
		{
			if (top[i] != -1)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (i != j && (top[j] == -1 || top[i] < top[j]))
					{
						int there = set(here, top[i], j);
						if (c[there] == 0)
						{
							c[there] = absIncrease(c[here]);
							q.push(there);
						}
						else if (sgn(c[there]) != sgn(c[here]))
						{
							return abs(c[there]) + abs(c[here]) - 1;
						}
					}
				}
			}
		}
	}
	return -1;
}

int main()
{
	int C = 0;
	cin >> C;
	for (int testcase = 0; testcase < C; ++testcase)
	{
		int N;
		cin >> N;
		int begin = 0;
		for (int i = 0; i < 4; ++i)
		{
			int discCount = 0;
			cin >> discCount;
			int disc = 0;
			for (int j = 0; j < discCount; ++j)
			{
				cin >> disc;
				begin = set(begin, disc - 1, i);
			}
		}
		int end = 0;
		for (int i = 0; i < N; ++i)
		{
			end |= (MASK << (i * 2));
		}
		
		cout << bfs(N, begin, end) << endl;
	}
	return 0;
}

#endif