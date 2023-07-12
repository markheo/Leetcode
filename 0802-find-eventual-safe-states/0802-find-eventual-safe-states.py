class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        WHITE, GRAY, BLACK = 0, 1, 2  # not visited, visiting, visited
        color = [WHITE] * len(graph)
        safe = []

        def dfs(node):
            if color[node] != WHITE:
                return color[node] == BLACK  # safe if visited

            color[node] = GRAY  # mark as visiting
            for adj in graph[node]:
                if not dfs(adj):  # if there is a node which cannot reach to a terminal node
                    return False  # it is not safe
            color[node] = BLACK  # mark as visited
            safe.append(node)
            return True  # safe

        for i in range(len(graph)):
            dfs(i)

        return sorted(safe)
        
        
        # l = len(graph)
        # term = [i for i in range(l) if graph[i] == []]
        # safe = term[:]
        # def safeNodes_help(node:int, adj:List[int]):
        #     if adj == []:
        #         return
        #     for i in range(len(adj)):
        #         if adj[i] not in safe:
        #             break
        #         if i == len(adj)-1 and adj[i] in safe and node not in safe:
        #             safe.append(node)
        # for _ in range(l-len(term)):            
        #     for i, adj in enumerate(graph):
        #         safeNodes_help(i, adj)
        # return sorted(safe)
        
        
        
#         l = len(graph)
#         term = [i for i in range(l) if graph[i] == []]
#         safe = term[:]
#         visited = [False] * l

#         def dfs(node):
#             if visited[node]:
#                 return node in safe
#             visited[node] = True
#             if all(dfs(adj) for adj in graph[node]):
#                 safe.append(node)
#                 return True
#             return False

#         nodes = [idx for idx in range(l) if idx not in term]
#         for node in nodes:
#             dfs(node)

#         return sorted(list(set(safe)))
        
        
        # l = len(graph)
        # nodes = [idx for idx in range(l)]
        # terminal = []
        # for idx in range(l):
        #     if graph[idx] == []:
        #         terminal.append(idx)
        # ans = terminal[:]
        # nodes = sorted(list(set(nodes) - set(ans)))
        # for _ in range(len(nodes)):
        #     nodes = sorted(list(set(nodes) - set(ans)))
        #     for idx in nodes:
        #         target = graph[idx]
        #         if len(set(target) - set(ans)) == 0 and idx not in ans:
        #             ans.append(idx)
        # return sorted(ans)        
        
        
        
        # l = len(graph)
        # terminal = []
        # dct = {}
        # for idx in range(l):
        #     dct[idx] = graph[idx]
        #     if graph[idx] == []:
        #         terminal.append(idx)
        # safe = []
        # for idx in range(l):
        #     s1 = set(dct[idx])
        #     s2 = set(terminal)
        #     if len(s1-s2) == 0:
        #         safe.append(idx)
        # for _ in range(l):
        #     for idx in range(l):
        #         s1 = set(dct[idx])
        #         s2 = set(safe)
        #         if len(s1-s2) == 0 and idx not in safe:
        #             safe.append(idx)
        # return sorted(safe)