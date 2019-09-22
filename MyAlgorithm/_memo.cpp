/*

인접 리스트를 만들 때 case마다 vector<vector<T>> adj(MAX) 를 할당해라. 이것은 힙에 들어간다
 vector<T> adj[MAX] 를 전역으로 놓으면 stack overflow가 나기 쉽다

방향이 없는 그래프를 구성할 때는 하나의 간선 입력을 (a, b), (b, a) 의 두 개의 데이터로 만들면 된다.

방향 그래프에서 오일러 서킷은 들어오고 나가는 횟수가 같아야 하므로
 모든 정점이 짝수점이어야만 존재한다.(홀수점이 하나만 있어도 오일러 서킷은 없음)
 (당연히 모든 정점이 하나의 컴포넌트에 포함되어 있을 때이다)

그래프에서 최단 경로 문제를 풀 때
 가중치가 없는 그래프는 DFS로 풀 수 있다. 
 최단 경로는 해당 정점을 처음 큐에 넣었을 때 시작점부터 해당 정점의 길이에 +1한 것이다.
 이 최단 경로는 너비 우선 스패닝 트리 위에서 찾아진다(bfs2)
 (이 때 최단 경로도 얻을 수 있다)
 가중치가 있는 그래프는 최단 경로 알고리즘을 써야 한다
 (경로가 아닌 최단 경로의 길이만 찾아 줌)

음수 간선이 있으면 음수 사이클이 생길 수 있으므로 최단경로를 찾을 수가 없다

다익스트라는 "한 정점"에서 다른 모든 정점까지의 최단 가중치 경로를 찾는 것으로
 탐색 후 얻는 스패닝 트리가 최단경로의 루트가 된다

벨만-포드 알고리즘도 "한 정점"에서 시작하는 최단 경로 찾기 알고리즘인데
 음수 간선을 통한 음수 사이클이 있는 경우에도 최단 경로를 찾을 수 있다.
 역시 탐색 후 얻는 스패닝 트리가 최단경로의 루트가 된다
*/


