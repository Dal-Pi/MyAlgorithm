#if 0

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main()
{
	int C = 0;
	cin >> C;
	for (int testcase = 0; testcase < C; ++testcase)
	{
		int N = 0;
		cin >> N;
		int ret = 0;

		vector<int> woods;
		int input = 0;
		for (int i = 0; i < N; ++i)
		{
			cin >> input;
			woods.push_back(input);
		}

		stack<int> remains;
		woods.push_back(0);
		for (int i = 0; i < woods.size(); ++i)
		{
			while (!remains.empty())
			{
				if (woods[remains.top()] < woods[i])
					break;
				int target = remains.top();
				remains.pop();

				int width = -1;
				if (remains.empty())
					width = i;
				else
					width = (i - remains.top()) - 1;

				ret = max(ret, (width * woods[target]));
			}
			remains.push(i);
		}
		cout << ret << endl;
	}

	return 0;
}

#endif