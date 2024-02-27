class Solution:
    def minSwaps(self, s: str) -> int:
        balance = 0  # Current balance of brackets
        swaps = 0  # Total swaps needed

        for char in s:
            if char == '[':
                # If we encounter an opening bracket, increase balance
                balance += 1
            else:
                # If we encounter a closing bracket, decrease balance
                balance -= 1
                # If balance is negative, we have more closing than opening brackets
                if balance < 0:
                    # To balance, we must swap a closing with an opening bracket
                    # This effectively "moves" an opening bracket to the current position
                    # And we need one swap for each imbalance
                    swaps += 1
                    # After the swap, the balance is increased by 2 (closing becomes opening)
                    balance += 2

        return swaps