class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        graph = {i: [] for i in range(n)}  # Initialize graph(nodes 0~n-1)
        for s, t in edges:
            graph[t].append(s)  # Reverse the edge to make finding ancestors easier

        def DFS(v, visited, ancestors):
            for src in graph[v]:
                if src not in visited:
                    visited.add(src)
                    ancestors.add(src)
                    # 한층 위 src 노드로 재귀 탐색
                    DFS(src, visited, ancestors)

        result = [set() for _ in range(n)]  # Use set to avoid duplicates

        # 모든 노드를 순회
        for i in range(n):
            DFS(i, set(), result[i])

        # Convert each set in result to a sorted list
        return [sorted(list(ancestors)) for ancestors in result]