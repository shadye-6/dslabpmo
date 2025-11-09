struct PriorityQueue {
    int heap[100005];
    int size = 0; 

    void heapifyUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] < heap[i]) {
                swap(heap[parent], heap[i]);
                i = parent;
            } else break;
        }
    }

    void heapifyDown(int i) {
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < size && heap[left] > heap[largest]) largest = left;
            if (right < size && heap[right] > heap[largest]) largest = right;

            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else break;
        }
    }

    void push(int val) {
        heap[size] = val;
        heapifyUp(size);
        size++;
    }

    void pop() {
        if (size == 0) {
            cout << "Heap is empty\n";
            return;
        }
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
    }

    int top() {
        if (size == 0) {
            cout << "Heap is empty\n";
            return -1;
        }
        return heap[0];
    }

    void printHeap() {
        for (int i = 0; i < size; i++) cout << heap[i] << " ";
        cout << "\n";
    }
};

    // ---------------------- STRUCT DEFINITION ----------------------
    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    // ---------------------- NODE CREATION ----------------------
    Node* createNode(int value) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    // ---------------------- INSERTION ----------------------
    Node* insert(Node* root, int value) {
        if (root == NULL)
            return createNode(value);

        if (value < root->data)
            root->left = insert(root->left, value);
        else if (value > root->data)
            root->right = insert(root->right, value);

        return root;
    }

    // ---------------------- SEARCH ----------------------
    bool search(Node* root, int key) {
        if (root == NULL)
            return false;
        if (root->data == key)
            return true;
        else if (key < root->data)
            return search(root->left, key);
        else
            return search(root->right, key);
    }

    // ---------------------- FIND MINIMUM ----------------------
    Node* findMin(Node* root) {
        while (root && root->left != NULL)
            root = root->left;
        return root;
    }

    // ---------------------- DELETE NODE ----------------------
    Node* deleteNode(Node* root, int key) {
        if (root == NULL)
            return NULL;

        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else {
            // Node found
            if (root->left == NULL) {
                Node* temp = root->right;
                free(root);
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                free(root);
                return temp;
            }

            // Node with two children: replace with inorder successor
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

int queue[MAX];
int front = -1, rear = -1;

bool isFull() {
    return (front == 0 && rear == MAX - 1) || (rear + 1 == front);
}

bool isEmpty() {
    return front == -1;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue Overflow\n";
        return;
    }

    if (front == -1) front = 0;  // first element
    rear = (rear + 1) % MAX;
    queue[rear] = value;
    cout << value << " enqueued.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue Underflow\n";
        return;
    }

    int value = queue[front];
    if (front == rear) {  // only one element
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }

    cout << value << " dequeued.\n";
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }

    cout << "Queue: ";
    int i = front;
    while (true) {
        cout << queue[i] << " ";
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    cout << "\n";
}
// ---------------------- DFS USING STACK ----------------------
void DFS(int graph[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    Stack s;
    initStack(s);

    push(s, start);
    visited[start] = 1;

    cout << "DFS Traversal: ";

    while (!isEmpty(s)) {
        int node = pop(s);
        cout << node << " ";

        // push unvisited adjacent nodes
        for (int i = n - 1; i >= 0; i--) { // reverse order for consistent output
            if (graph[node][i] == 1 && !visited[i]) {
                push(s, i);
                visited[i] = 1;
            }
        }
    }
    cout << "\n";
}

// ---------------------- BFS USING QUEUE ----------------------
void BFS(int graph[MAX][MAX], int n, int start) {
    int visited[MAX] = {0};
    Queue q;
    initQueue(q);

    enqueue(q, start);
    visited[start] = 1;

    cout << "BFS Traversal: ";

    while (!isQEmpty(q)) {
        int node = dequeue(q);
        cout << node << " ";

        // enqueue unvisited adjacent nodes
        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                enqueue(q, i);
                visited[i] = 1;
            }
        }
    }
    cout << "\n";
}
