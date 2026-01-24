#include <bits/stdc++.h> 
using namespace std;

int minTransactions(int k, vector<int> &arr) {
    int sum = 0;
    int size = arr.size();

    // Calculate total sum of balances
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    // If total cannot be equally divided, return -1
    if (sum % size != 0) {
        return -1;
    }

    int share = sum / size; // Target balance for each friend
    int excess = 0;         // Total extra money available to give

    // Check feasibility and count excess
    for (int i = 0; i < size; i++) {
        int diff = arr[i] - share;

        // Difference must be divisible by k
        if (abs(diff) % k != 0) {
            return -1;
        }

        // Count only positive differences (givers)
        if (diff > 0) {
            excess += diff;
        }
    }

    // Each transaction transfers k amount
    return excess / k;
}
