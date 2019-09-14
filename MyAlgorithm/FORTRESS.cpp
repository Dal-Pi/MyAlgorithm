#if 0

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

int N = 0;
int x[101];
int y[101];
int r[101];
int longest = 0;

int sqr(int x) { return x * x; }
int sqrdist(int a, int b) { return sqr(y[a] - y[b]) + sqr(x[a] - x[b]); }
bool encloses(int a, int b)
{
	return (r[a] > r[b]) && (sqrdist(a, b) < sqr(r[a] - r[b]));
}
bool isChild(int parent, int child)
{
	if (!encloses(parent, child))
	{
		return false;
	}
	for (int i = 0; i < N; ++i)
	{
		if (i != parent && i != child && encloses(parent, i) && encloses(i, child))
		{
			return false;
		}
	}
	return true;
}
struct TreeNode
{
	vector<shared_ptr<TreeNode>> children;
};
using pTreeNode = shared_ptr<TreeNode>;

pTreeNode getTree(int root)
{
	pTreeNode ret = make_shared<TreeNode>();
	for (int i = 0; i < N; ++i)
	{
		if (isChild(root, i))
		{
			ret->children.push_back(getTree(i));
		}
	}
	return ret;
}

int height(pTreeNode root)
{
	vector<int> heights;
	for (int i = 0; i < root->children.size(); ++i)
	{
		heights.push_back(height(root->children[i]));
	}
	if (heights.empty())
		return 0;
	sort(begin(heights), end(heights));
	if (heights.size() >= 2)
	{
		longest = max(longest, 2 + heights[heights.size()- 2] + heights[heights.size() - 1]);
	}
	return heights.back() + 1;
}

int solve(pTreeNode root)
{
	longest = 0;
	int h = height(root);
	return max(longest, h);
}

int main()
{
	int C = 0;
	cin >> C;
	for (int testcase = 0; testcase < C; ++testcase)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> x[i] >> y[i] >> r[i];
		}

		auto tree = getTree(0);
		cout << solve(tree) << endl;
	}
	return 0;
}

#endif