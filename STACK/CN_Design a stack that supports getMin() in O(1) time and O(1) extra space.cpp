#include <bits/stdc++.h>
using namespace std;

class SpecialStack {
public:
    stack<int> s;          // main stack to store elements (actual + encoded)
    int mini = INT_MAX;    // variable to store the current minimum element

    // Push operation
    void push(int data) {

        // If stack is empty, simply push the element
        // and update mini as the first element itself
        if (s.empty()) {
            s.push(data);
            mini = data;
        }
        else {
            // If the incoming data is smaller than current minimum
            // we need to store a modified (encoded) value
            // so that previous minimum can be recovered later
            if (data < mini) {

                // Encode the value before pushing
                // This ensures the stored value is always smaller than the new minimum
                int encodedValue = 2 * data - mini;

                s.push(encodedValue);

                // Update mini to the new minimum value
                mini = data;
            }
            else {
                // If data is greater than or equal to mini
                // push it normally
                s.push(data);
            }
        }
    }

    // Pop operation
    void pop() {

        // If stack is empty, nothing to pop
        if (s.empty()) {
            return;
        }

        int curr = s.top();
        s.pop();

        // If popped value is smaller than mini,
        // it means this value was an encoded value
        // and we must restore the previous minimum
        if (curr < mini) {

            // Decode the previous minimum using the formula
            // oldMin = 2 * currentMin - encodedValue
            int previousMin = 2 * mini - curr;

            // Update mini back to previous minimum
            mini = previousMin;
        }

        // If stack becomes empty after pop,
        // reset mini to INT_MAX to avoid stale minimum
        if (s.empty()) {
            mini = INT_MAX;
        }
    }

    // Returns the top element of the stack
    int top() {

        // If stack is empty, return -1
        if (s.empty()) {
            return -1;
        }

        int curr = s.top();

        // If the top element is an encoded value,
        // the actual top is the current minimum
        if (curr < mini) {
            return mini;
        }
        else {
            // Otherwise, top is the actual value
            return curr;
        }
    }

    // Returns the minimum element in the stack
    int getMin() {

        // If stack is empty, no minimum exists
        if (s.empty()) {
            return -1;
        }

        return mini;
    }
};
