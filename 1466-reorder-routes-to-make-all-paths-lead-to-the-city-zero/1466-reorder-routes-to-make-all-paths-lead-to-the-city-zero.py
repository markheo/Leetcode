class Solution:
    def dfs(self, v, visited): # v,i는 노드
        visited[v] = True
        # print(self.graph[v])
        for i, direction in self.graph[v]:
            if not visited[i]:
                if direction == 1:  # u -> v 방향이면, 방향 변경 필요
                    self.count += 1
                self.dfs(i, visited)
                
    def minReorder(self, n: int, connections: List[List[int]]) -> int:
        self.graph = [[] for _ in range(n)]
        
        # 간선 정보 입력 받기. u->v는 (v, 1), v->u는 (u, 0)으로 표현하여 방향성 표시
        for u, v in connections:
            self.graph[u].append((v, 1))  # u에서 v로 가는 방향
            self.graph[v].append((u, 0))  # v에서 u로 가는 방향 (반대 방향 간선)
        # print(self.graph)
        visited = [False] * n # 노드 갯수 n이 파라미터로 이미 주어짐
        self.count = 0  # 방향을 변경해야 하는 간선의 수 초기화
        self.dfs(0, visited)  # 0번 노드에서 시작하여 DFS 실행
        return self.count