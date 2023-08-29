class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        
        # Convert the 2D board into a 1D array.
        n = len(board)
        numbers = []
        for i in range(n - 1, -1, -1):
            if (n - 1 - i) % 2 == 0:  # Even rows
                numbers.extend(board[i])
            else:  # Odd rows
                numbers.extend(board[i][::-1])
        
        # BFS
        visited = set()
        queue = deque([(0, 0)])  # (position, steps)

        while queue:
            pos, steps = queue.popleft()

            # If we reach the end
            if pos == len(numbers) - 1:
                return steps

            for jump in range(1, 7):  # Simulate dice roll
                next_pos = pos + jump
                if next_pos >= len(numbers):
                    break

                # If there's a ladder or snake
                if numbers[next_pos] != -1:
                    next_pos = numbers[next_pos] - 1

                if next_pos not in visited:
                    visited.add(next_pos)
                    queue.append((next_pos, steps + 1))

        # If we can't reach the end
        return -1