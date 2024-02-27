class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        from collections import deque
        # edge list -> graph dictionary로 바꾸고 탐색
        graph = {i: [] for i in range(n)}  # Initialize graph(nodes 0~n-1)
        for s, t in edges:
            graph[s].append(t)  # Reverse the edge to make finding ancestors easier
            graph[t].append(s)

        visited = [False] * n
        # 주의해야 하는 케이스!!!
        if source == destination:
            return True

        q = deque([source])

        while q:
            curNode = q.popleft()
            visited[curNode] = True
            for neighbor in graph[curNode]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    q.append(neighbor)

                if neighbor == destination:
                    return True

        return False