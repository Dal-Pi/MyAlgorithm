#if 0

#include <iostream>
#include <list>

using namespace std;

int main()
{
	int C = 0;
	cin >> C;
	for (int testcase = 0; testcase < C; ++testcase)
	{
		int N = 0;
		int K = 0;
		cin >> N >> K;

		list<int> memberList;
		for (int i = 1; i <= N; ++i)
		{
			memberList.push_back(i);
		}

		auto targetMember = memberList.begin();
		while (memberList.size() > 2)
		{
			targetMember = memberList.erase(targetMember);
			if (memberList.end() == targetMember)
			{
				targetMember = memberList.begin();
			}
			for (int i = 0; i < K - 1; ++i)
			{
				targetMember++;
				if (memberList.end() == targetMember)
				{
					targetMember = memberList.begin();
				}
			}
		}

		for (auto member : memberList)
		{
			cout << member << " ";
		}
		cout << endl;
	}

	return 0;
}

#endif