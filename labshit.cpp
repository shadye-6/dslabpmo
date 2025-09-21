//q1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int arr[1002], minVals[1002]; int top = -1, minTop = -1;

void pushmin(int val) {
    minTop++; minVals[minTop] = val;
}

void popmin(){
    minTop--;
}

void push(int val) {
    top++; arr[top] = val;
    if (minTop == -1 || val <= minVals[minTop]) {
        pushmin(val);
    }
}

int pop() {
    int val;
    if (top == -1) {
        return -101;
    }
    if (arr[top] == minVals[minTop]){
        popmin();
    }
    val = arr[top--];
    return val;
}

int main() {
    int n; cin >> n;
    int type, val;
    for (int i=0; i<n; i++) {
        cin >> type; 
        if (type == 1) {
            cin >> val; push(val);
        } else if (type == 2) {
            val = pop();
            if (val == -101) cout << "null\n"; 
            else cout << val << "\n";
        } else if (type == 3) {
            if (top == -1) cout << "null\n";
            else cout << arr[top] << "\n";
        } else if (type == 4) {
            if (minTop == -1) cout << "null\n";
            else cout << minVals[minTop] << "\n";
        }
    }
    return 0;
}

//q2
#include <bits/stdc++.h>
using namespace std;

int prec(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

char arr[1001];
int top = -1;

void push(char c) {
    arr[++top] = c;
}

void pop() {
    if (top >= 0) top--;
}

char peek() {
    if (top >= 0) return arr[top];
    return '\0';
}

bool empty() {
    return top == -1;
}

string infixToPostfix(const string &infix) {
    string postfix;

    for (char ch : infix) {
        if (isdigit(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (!empty() && peek() != '(') {
                postfix += peek();
                pop();
            }
            if (!empty()) pop(); 
        } else { 
            while (!empty() && prec(peek()) >= prec(ch)) {
                if (peek() == '(') break;
                postfix += peek();
                pop();
            }
            push(ch);
        }
    }

    while (!empty()) {
        postfix += peek();
        pop();
    }

    return postfix;
}

int main() {
    string infix; cin >> infix;
    string postfix = infixToPostfix(infix);
    cout << postfix << "\n";
    return 0;
}

//q3
#include <bits/stdc++.h>
using namespace std;

int arr[1001]; int top = -1;

void push(int x) {
    arr[++top] = x;
}

void pop() {
    if (top >= 0) top--;
}

int peek() {
    if (top >= 0) return arr[top];
    return INT_MIN; 
}

bool empty() {
    return top == -1;
}

pair<long long, int> evaluatePostfix(const string &postfix) {
    top = -1; 
    int maxStackSize = 0;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            push(ch - '0'); // convert char to int
            maxStackSize = max(maxStackSize, top + 1);
        } else { 
            if (top < 1) return {LLONG_MIN, maxStackSize};
            int b = peek(); pop();
            int a = peek(); pop();
            long long res = 0;

            switch (ch) {
                case '+': res = (long long)a + b; break;
                case '-': res = (long long)a - b; break;
                case '*': res = (long long)a * b; break;
                case '/': 
                    if (b == 0) return {LLONG_MIN, maxStackSize}; 
                    res = a / b; 
                    break;
                default: return {LLONG_MIN, maxStackSize}; 
            }
            push(res);
            maxStackSize = max(maxStackSize, top + 1);
        }
    }

    if (top != 0) return {LLONG_MIN, maxStackSize}; 
    return {peek(), maxStackSize};
}

int main() {
    string postfix; cin >> postfix;

    auto result = evaluatePostfix(postfix);
    if (result.first == LLONG_MIN) {
        cout << "Invalid\n";
    } else {
        cout << result.first << "\n";
    }
    cout << result.second << "\n";

    return 0;
}


//q4
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;

// Stack implementation using array
struct Stack {
    int arr[MAXN];
    int top = -1;

    void push(int x) {
        arr[++top] = x;
    }

    void pop() {
        if (top >= 0) top--;
    }

    int peek() {
        if (top >= 0) return arr[top];
        return -1;
    }

    bool empty() {
        return top == -1;
    }
};

struct QueueUsingStacks {
    Stack s1, s2;

    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.peek());
                s1.pop();
            }
        }
        if (s2.empty()) return -1; 
        int front = s2.peek();
        s2.pop();
        return front;
    }
};

int main() {
    int n;
    cin >> n;

    QueueUsingStacks q;

    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            q.enqueue(x);
        } else if (op == 2) {
            cout << q.dequeue() << "\n";
        }
    }

    return 0;
}

//q6
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
int heap[MAXN];
int sizeHeap = 0;

// Swap helper
void swap(int &a, int &b) { int t = a; a = b; b = t; }

// Heapify up (after insertion)
void heapifyUp(int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (heap[parent] <= heap[idx]) break;
        swap(heap[parent], heap[idx]);
        idx = parent;
    }
}

// Heapify down (after removing min)
void heapifyDown(int idx) {
    while (true) {
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;
        int smallest = idx;

        if (left < sizeHeap && heap[left] < heap[smallest]) smallest = left;
        if (right < sizeHeap && heap[right] < heap[smallest]) smallest = right;

        if (smallest == idx) break;
        swap(heap[idx], heap[smallest]);
        idx = smallest;
    }
}

// Insert element
void insert(int x) {
    heap[sizeHeap] = x;
    heapifyUp(sizeHeap);
    sizeHeap++;
}

// Get minimum
int getMin() {
    if (sizeHeap == 0) return -1;
    return heap[0];
}

// Remove minimum
void removeMin() {
    if (sizeHeap == 0) return;
    heap[0] = heap[sizeHeap - 1];
    sizeHeap--;
    heapifyDown(0);
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int op;
        cin >> op;

        if (op == 1) {
            int m;
            cin >> m;
            insert(m);
        } else if (op == 2) {
            cout << getMin() << "\n";
        } else if (op == 3) {
            removeMin();
        }
    }

    return 0;
}

//q8
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;

// Array-based stack
char arr[MAXN];
int top = -1;

void push(char c) { arr[++top] = c; }
void pop() { if (top >= 0) top--; }
char peek() { return top >= 0 ? arr[top] : '\0'; }
bool empty() { return top == -1; }

// Function to check if two brackets match
bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

string isBalanced(const string &s) {
    top = -1; // reset stack

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (empty() || !isMatching(peek(), ch)) return "NO";
            pop();
        }
    }

    return empty() ? "YES" : "NO";
}

int main() {
    string s;
    cin >> s;

    cout << isBalanced(s) << "\n";
    return 0;
}


