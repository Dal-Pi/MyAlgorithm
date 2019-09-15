#if 0

#define USE_PQUEUE
#ifdef USE_TREAP

#include <iostream>
#include "treap.h"

using namespace std;
using namespace treap;
using NumNode = Node<int>;

struct RNG
{
	int seed;
	int a;
	int b;
	RNG(int _a, int _b) : seed(1983), a(_a), b(_b) {}
	int getNext()
	{
		int ret = seed;
		seed = ((seed * (long long)a) + b) % 20090711;
		return ret;
	}
};

int main()
{
	int C = 0;
	cin >> C;
	for (int testcase = 0; testcase < C; ++testcase)
	{
		int N;
		int a = 0;
		int b = 0;
		cin >> N >> a >> b;
		RNG rng(a, b);
		NumNode* root = nullptr;
		int ret = 0;
		for (int i = 1; i <= N; ++i)
		{
			root = insert(root, new NumNode(rng.getNext()));
			int median = kth(root, (i + 1) / 2)->key;
			ret = (ret + median) % 20090711;
		}
		cout << ret << endl;
	}
	return 0;
}
#endif

#ifdef USE_PQUEUE

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct RNG
{
	int seed;
	int a;
	int b;
	RNG(int _a, int _b) : seed(1983), a(_a), b(_b) {}
	int getNext()
	{
		int ret = seed;
		seed = ((seed * (long long)a) + b) % 20090711;
		return ret;
	}
};

int main()
{
	int C = 0;
	cin >> C;
	for (int testcase = 0; testcase < C; ++testcase)
	{
		int N;
		int a = 0;
		int b = 0;
		cin >> N >> a >> b;
		RNG rng(a, b);
		priority_queue<int, vector<int>, less<int>> maxHeap;
		priority_queue<int, vector<int>, greater<int>> minHeap;
		int ret = 0;
		for (int i = 1; i <= N; ++i)
		{
			int target = rng.getNext();
			if (maxHeap.size() == minHeap.size())
				maxHeap.push(target);
			else
				minHeap.push(target);

			if (!maxHeap.empty() && !minHeap.empty() && (minHeap.top() < maxHeap.top()))
			{
				int a = maxHeap.top();
				maxHeap.pop();
				int b = minHeap.top();
				minHeap.pop();
				maxHeap.push(b);
				minHeap.push(a);
			}
			ret = (ret + maxHeap.top()) % 20090711;
		}
		cout << ret << endl;
	}
	return 0;
}

#endif

#endif