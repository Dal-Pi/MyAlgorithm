#if 0

int V

//adj[u][v] : u���� v�� ���� ������ ����ġ. ������ ������ ���� ū ���� �ִ´�.
int adj[MAX_V][MAX_V];

void floyd() {
	for (int i = 0; i < V; ++i)
		adj[i][i] = 0;
	for (int k = 0; k < V; ++k)
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V; ++j)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}


void floyd_reachable() {
	for (int i = 0; i < V; ++i)
		reachable[i][i] = true;
	for (int k = 0; k < V; ++k)
		for (int i = 0; i < V; ++i)
			for (int j = 0; j < V; ++j)
				if (reachable[i][j] || (reachable[i][k] && reachable[k][j]))
					reachable[i][j] = true;
}

#endif