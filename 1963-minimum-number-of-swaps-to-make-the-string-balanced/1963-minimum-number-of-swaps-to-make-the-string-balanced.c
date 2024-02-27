int minSwaps(char* s) {
    int balance = 0; // Current balance of brackets
    int swaps = 0; // Total swaps needed
    int n = strlen(s); // Get the length of the string

    for (int i = 0; i < n; i++) {
        if (s[i] == '[') {
            // If we encounter an opening bracket, increase balance
            balance++;
        } else {
            // If we encounter a closing bracket, decrease balance
            balance--;
            // If balance is negative, we have more closing than opening brackets
            if (balance < 0) {
                // To balance, we must swap a closing with an opening bracket
                // This effectively "moves" an opening bracket to the current position
                // And we need one swap for each imbalance
                swaps++;
                // After the swap, the balance is increased by 2 (closing becomes opening)
                balance += 2;
            }
        }
    }

    return swaps;
}