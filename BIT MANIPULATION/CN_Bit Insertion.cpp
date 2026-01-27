#include <bits/stdc++.h>
using namespace std;

int bitInsertion(int x, int y, int a, int b)
{
    // Step 1: Create a mask to clear bits from A to B in X

    // Use long long to avoid undefined behaviour when shifting
    long long allOnes = ~0LL;

    // Left mask: 1s before position B
    long long leftMask = allOnes << (b + 1);

    // Right mask: 1s after position A
    long long rightMask = (1LL << a) - 1;

    // Combined mask: 1s everywhere except A to B
    long long mask = leftMask | rightMask;

    // Clear bits from A to B in X
    long long clearedX = x & mask;

    // Step 2: Shift Y to align it starting at position A
    long long shiftedY = (long long)y << a;

    // Step 3: Insert Y into X
    long long result = clearedX | shiftedY;

    return (int)result;
}
