#if 0

#include <iostream>
#include <queue>

using namespace std;

struct RNG
{
	unsigned int seed;
	RNG() : seed(1983) {}
	unsigned int getNext()
	{
		unsigned int ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return (ret % 10000) + 1;
	}
};

int main()
{
	int C = 0;
	cin >> C;
	for (int testcase = 0; testcase < C; ++testcase)
	{
		int K = 0;
		int N = 0;
		cin >> K >> N;

		int ret = 0;
		RNG rng;
		queue<int> range;
		int rangeSum = 0;
		for (int i = 0; i < N; ++i)
		{
			int targetNum = rng.getNext();
			rangeSum += targetNum;
			range.push(targetNum);

			while (rangeSum > K)
			{
				rangeSum -= range.front();
				range.pop();
			}

			if (rangeSum == K)
				ret++;
		}
		cout << ret << endl;
	}

	return 0;
}

#endif