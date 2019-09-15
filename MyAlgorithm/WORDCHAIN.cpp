#if 0

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<string> graph[26][26];

vector<int> indegree;
vector<int> outdegree;

void makeGraph(const vector<string>& words)
{
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < 26; ++j)
			graph[i][j].clear();
	adj = vector<vector<int>>(26, vector<int>(26, 0));
	indegree = vector<int>(26, 0);
	outdegree = vector<int>(26, 0);

	for (int i = 0; i < words.size(); ++i)
	{
		int a = words[i][0] - 'a';
		int b = words[i][words[i].size() - 1] - 'a';
		graph[a][b].push_back(words[i]);
		adj[a][b]++;
		indegree[b]++;
		outdegree[a]++;
	}
}

void getEulerCircuit(int here, vector<int>& circuit)
{
	for (int there = 0; there < adj.size(); ++there)
	{
		while (adj[here][there] > 0)
		{
			adj[here][there]--;
			getEulerCircuit(there, circuit);
		}
	}
	circuit.push_back(here);
}

vector<int> getEulerTrailOrCircuit()
{
	vector<int> circuit;
	for (int i = 0; i < 26; ++i)
	{
		if (outdegree[i] == (indegree[i] + 1))
		{
			getEulerCircuit(i, circuit);
			return circuit;
		}
	}

	for (int i = 0; i < 26; ++i)
	{
		if (outdegree[i] > 0)
		{
			getEulerCircuit(i, circuit);
			return circuit;
		}
	}

	return circuit;
}

bool checkEuler()
{
	int plus1 = 0;
	int minus1 = 0;
	for (int i = 0; i < 26; ++i)
	{
		int diff = indegree[i] - outdegree[i];
		if (diff < -1 || 1 < diff)
			return false;
		if (diff == 1)
			plus1++;
		else if (diff == -1)
			minus1++;
	}
	return (plus1 == 1 && minus1 == 1) || (plus1 == 0 && minus1 == 0);
}

string solve(const vector<string>& words)
{
	makeGraph(words);
	if (!checkEuler())
		return "IMPOSSIBLE";
	auto circuit = getEulerTrailOrCircuit();
	if (circuit.size() != (words.size() + 1))
		return "IMPOSSIBLE";

	reverse(begin(circuit), end(circuit));
	string ret;
	for (int i = 1; i < circuit.size(); ++i)
	{
		int a = circuit[i - 1];
		int b = circuit[i];
		if (ret.size())
			ret += " ";
		ret += graph[a][b].back();
		graph[a][b].pop_back();
	}
	return ret;
}

int main()
{
	int C = 0;
	cin >> C;
	for (int testcase = 0; testcase < C; ++testcase)
	{
		int N;
		cin >> N;
		vector<string> words;
		string word;
		for (int i = 0; i < N; ++i)
		{
			cin >> word;
			words.push_back(word);
		}
		cout << solve(words) << endl;
	}
	return 0;
}

#endif