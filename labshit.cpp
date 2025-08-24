//q1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int convert(string a) {
    return stoi(a);
}

struct node {
    int info;
    node* next;
};

void add(node *head, int data) {
    node *temp = new node(); node *cur = head;
    temp->next = nullptr;
    temp->info = data;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = temp;
}

void printMiddle (node *head, int n) {
    node *cur = head;
    for (int i=0; i<n/2; i++) {
        cur = cur->next;
    }
    cout << cur->info << "\n";
}


int main() {
    node* head = nullptr;
    string i; int j, n=0;
    while (true) {
        cin >> i;
        if (i == "#") break;
        else {
            j = convert(i);
            if (n==0) {
                head = new node();
                head->info = j; head->next = nullptr;
            } else {
            add(head, j);
            }
            n++;
        }
    }
    printMiddle(head, n);
    return 0;
}

//q2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int convert(string a) {
    return stoi(a);
}

struct node {
    int info;
    node* next;
};

void add(node *head, int data) {
    node *temp = new node(); node *cur = head;
    temp->next = nullptr;
    temp->info = data;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = temp;
}

int main() {
    node* head = nullptr;
    string i; int j;
    int numMax = -1, maxFreq = 0;
    while (true) {
        cin >> i;
        if (i == "#") break;
        else {
            j = convert(i);
            if (head == nullptr) {
                head = new node();
                head->info = j; head->next = nullptr;
            } else {
                add(head, j);
            }
        }
    }

    node *cur = head; int curNum = 0 , curFreq = 0;
    while (cur != nullptr) {
        curNum = cur->info;
        while (cur != nullptr && cur->info == curNum) {
            curFreq++;
            cur = cur->next;
        }
        if (curFreq == maxFreq) {numMax = max(numMax, curNum);}
        else if (maxFreq < curFreq){
            maxFreq = curFreq; numMax = curNum;
        }
        curFreq = 0;
    }
    cout << numMax << "\n";
    return 0;
}

//q3
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int convert(string a) {
    return stoi(a);
}

struct node {
    int info;
    node* next;
};

void add(node *head, int data) {
    node *temp = new node(); node *cur = head;
    temp->next = nullptr;
    temp->info = data;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = temp;
    return;
}

void printList(node* head) {
    node* cur = head;
    while (cur != nullptr) {
        cout << cur->info << " ";
        cur = cur->next;
    }
}

int main() {
    node *head = nullptr;
    string i; int j;
    int numMax = -1, maxFreq = 0, n=0;
    while (true) {
        cin >> i;
        if (i == "#") break;
        else {
            j = convert(i);
            if (head == nullptr) {
                head = new node();
                head->info = j; head->next = nullptr; 
            } else {
                add(head, j);
            }
            n++;
        }
    }
    node* prev = nullptr; node* cur = head;
    while (cur != nullptr) {
        node* temp = cur->next;
        cur->next = prev;
        prev = cur;    
        cur = temp;            
    }
    head = prev;

    printList(head);
    cout << "\n";
    return 0;
}

//q4
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int convert(string a) {
    return stoi(a);
}

struct node {
    int info;
    node* next;
    node* prev;
};

void add(node *head, int data) {
    node *temp = new node(); node *cur = head;
    temp->next = nullptr;
    temp->info = data;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    temp->prev = cur;
    cur->next = temp;
    return;
}

void printList(node* head) {
    node* cur = head;
    while (cur != nullptr) {
        cout << cur->info << " ";
        cur = cur->next;
    }
}

int main() {
    node *head = nullptr;
    string i; int j;
    int numMax = -1, maxFreq = 0, n=0;
    while (true) {
        cin >> i;
        if (i == "#") break;
        else {
            j = convert(i);
            if (head == nullptr) {
                head = new node();
                head->info = j; head->next = nullptr; head->prev = nullptr;
            } else {
                add(head, j);
            }
            n++;
        }
    }
    node *first = head; node *last = head;
    while (last->next != nullptr) {
        last = last->next;
    }
    int maxSum = INT_MIN;
    for (int i=0; i<n/2; i++) {
        int sum = first->info + last->info;
        maxSum = max(sum, maxSum);
        first = first->next; last = last->prev;
    }

    cout << maxSum << "\n";
    return 0;
}

//q5, q8
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int convert(string a) {
    return stoi(a);
}

struct node {
    int info;
    node* next;
    // node* prev;
};

void add(node *head, int data) {
    node *temp = new node(); node *cur = head;
    temp->next = nullptr;
    temp->info = data;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    // temp->prev = cur;
    cur->next = temp;
    return;
}

node* reverseList(node *head, node *end) {
    node *prev = nullptr, *cur = head;
    while (cur != end) {
        node *temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
    }
    return prev; 
}

void printList(node* head) {
    node* cur = head;
    while (cur != nullptr) {
        cout << cur->info << " ";
        cur = cur->next;
    }
}

int main() {
    node *head = nullptr;
    string i;
    int n = 0;
    while (cin >> i && i != "#") {
        int val = stoi(i);
        if (!head) {
            head = new node{val, nullptr};
        } else {
            add(head, val);
        }
        n++;
    }

    int k; cin >> k; k = k%n;

    head = reverseList(head, nullptr);

    node *mid = head;
    for (int i = 0; i < k; i++) {
        mid = mid->next;
    }

    node* head1 = head; 
    node* newhead1 = reverseList(head1, mid);

    node* head2 = reverseList(mid, nullptr);

    head1->next = head2; head = newhead1; 

    printList(head);
    cout << "\n";
    return 0;
}

//q6
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int convert(string a) {
    return stoi(a);
}

struct node {
    int info;
    node* next;
    bool visited;
    // node* prev;
};

void add(node *head, int data) {
    node *temp = new node(); node *cur = head;
    temp->next = nullptr;
    temp->info = data;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    // temp->prev = cur;
    cur->next = temp; temp->visited = false;
    return;
}

void printList(node* head) {
    node* cur = head;
    while (cur != nullptr) {
        cout << cur->info << " ";
        cur = cur->next;
    }
}

int main() {
    node *head = nullptr;
    string i;
    int n = 0;
    while (cin >> i && i != "#") {
        int val = stoi(i);
        if (!head) {
            head = new node{val, nullptr};
        } else {
            add(head, val);
        }
        n++;
    }

    pair<int, int> vals; 
    for (int i=0; i<n; i++) {
        cin >> vals.first >> vals.second;
    }
    node *finder = head; node *tail = head;
    while (finder != nullptr) {
        if (finder->info == vals.second) {break;}
        else finder = finder->next;
    }
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = finder;

    node *start = nullptr; node *last = nullptr; node *cur = head;
    int sum = 0;
    
    while (cur->next != nullptr) {
        cur->visited = true;
        if (cur->next->visited == true) {
            start = cur->next; last = cur;
            break;
        } 
        cur = cur->next;
    }

    while (start != last) {
        sum++; 
        start = start->next;
    }
    cout << ((finder == nullptr) ? 0 : sum + 1);
    cout << "\n";
    return 0;
}

//q7
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int convert(string a) {
    return stoi(a);
}

struct node {
    int info;
    node* next;
    bool visited;
    // node* prev;
};

void add(node *head, int data) {
    node *temp = new node(); node *cur = head;
    temp->next = nullptr;
    temp->info = data;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    // temp->prev = cur;
    cur->next = temp; temp->visited = false;
    return;
}

void printList(node* head) {
    node* cur = head;
    while (cur != nullptr) {
        cout << cur->info << " ";
        cur = cur->next;
    }
}

int main() {
    //assuming n >= 2
    node *head = nullptr;
    string i;
    int n = 0;
    while (cin >> i && i != "#") {
        int val = stoi(i);
        if (!head) {
            head = new node{val, nullptr};
        } else {
            add(head, val);
        }
        n++;
    }

    node* headOdd = head; node* headEven = head->next;
    node* tailOdd = head; node* tailEven = head->next;

    while (tailOdd != nullptr && tailEven != nullptr) {
        tailOdd->next = tailEven->next; tailOdd = tailOdd->next;
        tailEven->next = tailOdd->next; tailEven = tailEven->next;
    }

    printList(headOdd);
    cout << " ";
    printList(headEven);;
    cout << "\n";
    return 0;
}

