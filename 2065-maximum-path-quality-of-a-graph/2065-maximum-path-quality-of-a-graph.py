class Solution:
    def maximalPathQuality(self, values: List[int], edges: List[List[int]], maxTime: int) -> int:
        n = len(values)
        graph = {i: [] for i in range(n)}  # Initialize graph(nodes 0~n-1)
        for u, v, time in edges:
            graph[u].append((v, time))  # Reverse the edge to make finding ancestors easier
            graph[v].append((u, time))

        def DFS(node, time, quality, visited):
            if time > maxTime:
                return 0
            # Include quality of the current node only if it's not visited
            new_quality = quality + values[node] if node not in visited else quality
            visited.add(node)
            max_quality = new_quality if node == 0 else 0 # Update max_quality if we are back at node 0
            for neighbor, n_time in graph[node]:
                max_quality = max(max_quality, DFS(neighbor, time + n_time, new_quality, visited.copy()))
            return max_quality

        # Start DFS from node 0
        return DFS(0, 0, 0, set())