class MinStack {
private:
    stack<long long> s;   // Stack to store elements (normal + encoded)
    long long mini;       // Stores the current minimum

public:
    // Constructor
    MinStack() {
        mini = LLONG_MAX;
    }

    // Push operation
    void push(int val) {
        // Case 1: Stack is empty
        if (s.empty()) {
            s.push(val);
            mini = val;
        }
        // Case 2: Normal value, no change in minimum
        else if (val >= mini) {
            s.push(val);
        }
        // Case 3: New value is smaller than current minimum
        else {
            // Encode the value before pushing
            long long encoded = 2LL * val - mini;
            s.push(encoded);
            mini = val;   // Update new minimum
        }
    }

    // Pop operation
    void pop() {
        long long topVal = s.top();
        s.pop();

        // If encoded value is popped, restore previous minimum
        if (topVal < mini) {
            mini = 2LL * mini - topVal;
        }
    }

    // Top operation
    int top() {
        long long topVal = s.top();
        // If encoded, actual value is mini
        if (topVal < mini)
            return mini;
        return topVal;
    }

    // Get minimum element
    int getMin() {
        return mini;
    }
};
