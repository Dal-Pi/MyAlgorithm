#if 0

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printPostorder(vector<int>& preorder, vector<int>& inorder)
{
	if (preorder.empty() || inorder.empty())
		return;

	int root = preorder[0];
	int leftNodeCount = find(begin(inorder), end(inorder), root) - begin(inorder);
	
	vector<int> leftPreorder(begin(preorder) + 1, begin(preorder) + 1 + leftNodeCount);
	vector<int> rightPreorder(begin(preorder) + 1 + leftNodeCount, end(preorder));

	vector<int> leftInorder(begin(inorder), begin(inorder) + leftNodeCount);
	vector<int> rightInorder(begin(inorder) + 1 + leftNodeCount, end(inorder));

	printPostorder(leftPreorder, leftInorder);
	printPostorder(rightPreorder, rightInorder);

	cout << root << ' ';
}

int main()
{
	int C = 0;
	cin >> C;
	for (int testcase = 0; testcase < C; ++testcase)
	{
		int N;
		cin >> N;

		vector<int> preorder;
		vector<int> inorder;
		int input;
		for (int i = 0; i < N; ++i)
		{
			cin >> input;
			preorder.push_back(input);
		}
		for (int i = 0; i < N; ++i)
		{
			cin >> input;
			inorder.push_back(input);
		}
		printPostorder(preorder, inorder);
		cout << endl;
	}
	return 0;
}

#endif