#if 0

#include <iostream>
#include "Treap.h"

using namespace std;
using namespace treap;
using NumNode = Node<int>;

int main()
{
	int C = 0;
	cin >> C;
	for (int testcase = 0; testcase < C; ++testcase)
	{
		int N = 0;
		cin >> N;
		int shifted[50002];
		int A[50002];
		for (int i = 1; i <= N; ++i)
		{
			cin >> shifted[i];
		}

		NumNode* candidates = nullptr;
		for (int i = 1; i <= N; ++i)
		{
			candidates = insert(candidates, new NumNode(i));
		}

		for (int i = N; i > 0; --i)
		{
			int larger = shifted[i];
			NumNode* k = kth(candidates, i - larger);
			A[i] = k->key;
			candidates = erase(candidates, k->key);
		}

		for (int i = 1; i <= N; ++i)
		{
			cout << A[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}

#endif