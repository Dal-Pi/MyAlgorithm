#if 0

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int C = 0;
	cin >> C;
	for (int testcase = 0; testcase < C; ++testcase)
	{
		string input;
		cin >> input;

		bool ret = true;
		stack<char> brackets;
		for (int i = 0; i < input.length(); ++i)
		{
			char target = input[i];
			if ((target == '(') || (target == '{') || (target == '['))
			{
				brackets.push(target);
				continue;
			}

			if (brackets.empty())
			{
				ret = false;
				break;
			}

			char open = brackets.top();
			brackets.pop();
			if ((open == '(') && (target != ')'))
			{
				ret = false;
				break;
			}
			if ((open == '{') && (target != '}'))
			{
				ret = false;
				break;
			}
			if ((open == '[') && (target != ']'))
			{
				ret = false;
				break;
			}
		}
		if (!brackets.empty())
			ret = false;

		cout << (ret ? "YES" : "NO") << endl;
	}

	return 0;
}

#endif