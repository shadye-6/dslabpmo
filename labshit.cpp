//q1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

void printList(node *head) {
    node *cur = head;
    do {
        cout << cur->info << " ";
        cur = cur->next; 
    } while (cur != head);
}

int main() {
    node* head = nullptr;
    int i, n=0;
    int k; cin >> k;
    while (cin >> i && i != -1) {
        if (n==0) {
            head = new node();
            head->info = i; head->next = nullptr;
        } else {
            add(head, i);
        }
        n++;
    }
    k = k%n;
    //making circular
    node *cur = head; 
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = head;

    if (k==0) printList(head);
    else {
        for (int i=0; i<n-k; i++) {
            head = head->next;
        }
        printList(head);
    }
    cout <<"\n";
    return 0;
}

//q2
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    cur->next = temp;
    temp->prev = cur;
}

void deleteNode(node* &head, node* del) {
    if (del == head) {
        head = del->next; free(del);
    } else if (del->next == nullptr) {
        node* prev = del->prev;
        prev->next = nullptr; free(del);
    } else {
        node *prev = del->prev; node *next = del->next;
        prev->next = next; next->prev = prev; free(del);
    }
}

void printList(node *head) {
    node *cur = head;
    if (cur == nullptr) {cout << -1; return;}
    while (cur != nullptr) {
        cout << cur->info << " ";
        cur = cur->next;
    }
}

int main() {
    node* head = nullptr;
    int i, n=0;
    int k; cin >> k;
    while (cin >> i && i != -1) {
        if (n==0) {
            head = new node();
            head->info = i; head->next = nullptr; head->prev = nullptr;
        } else {
            add(head, i);
        }
        n++;
    }
    node *cur = head; 
    while (cur != nullptr) {
        if (cur->info == k) {
            node *temp = cur; cur = cur->next;
            deleteNode(head, temp);
        } else {
            cur = cur->next;
        }
    }

    printList(head);
    cout <<"\n";
    return 0;
}

/q3
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
    cur->next = temp;
    temp->prev = cur;
}

void printList(node *head) {
    node *cur = head;
    if (cur == nullptr) {cout << -1; return;}
    while (cur != nullptr) {
        cout << cur->info << " ";
        cur = cur->next;
    }
}

int main() {
    node* head1 = nullptr; node *head2 = nullptr; node *head = nullptr;
    int i, n1 = 0, n2 = 0, n=0;
    while (cin >> i && i != -1) {
        if (n1==0) {
            head1 = new node();
            head1->info = i; head1->next = nullptr; head1->prev = nullptr;
        } else {
            add(head1, i);
        }
        n1++;
    }
    while (cin >> i && i != -1) {
        if (n2==0) {
            head2 = new node();
            head2->info = i; head2->next = nullptr; head2->prev = nullptr;
        } else {
            add(head2, i);
        }
        n2++;
    }

    node *cur1 = head1;  node *cur2 = head2; node *cur = nullptr;
    while (cur1 != nullptr && cur2 != nullptr) {
        if (cur1->info < cur2->info) {
            if (n == 0) {
                head = cur1; cur = head;
            } else {
                cur->next = cur1; cur1->prev = cur; cur = cur->next;
            }
            cur1 = cur1->next;
        } else {
            if (n == 0) {
                head = cur2; cur = head;
            } else {
                cur->next = cur2; cur2->prev = cur; cur = cur->next;
            }
            cur2 = cur2->next;
        }
        n++;
    }
    while (cur1 != nullptr) {
        cur->next = cur1; cur1->prev = cur;
        cur = cur->next; cur1 = cur1->next;
    }

    while (cur2 != nullptr) {
        cur->next = cur2; cur2->prev = cur;
        cur = cur->next; cur2 = cur2->next;
    }


    printList(head);
    cout <<"\n";
    return 0;
}

//q4

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

void printList(node *head) {
    node *cur = head;
    do {
        cout << cur->info << " ";
        cur = cur->next; 
    } while (cur != head);
}

int main() {
    node* head = nullptr;
    int i, n=0;
    while (cin >> i && i != -1) {
        if (n==0) {
            head = new node();
            head->info = i; head->next = nullptr;
        } else {
            add(head, i);
        }
        n++;
    }
    //making circular
    node *cur = head; 
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = head;

    node *head1 = head, *head2 = nullptr;
    node *cur1 = head, *cur2 = nullptr;
    cur = head->next;

    for (int j = 1; j < n/2; j++) {
        cur1->next = cur; cur1 = cur1->next; cur = cur->next;
    }
    cur1->next = head1; 

    head2 = cur; cur2 = head2; cur = cur->next;
    for (int j = 1; j < (n+1)/2; j++) { 
        cur2->next = cur; cur2 = cur2->next; cur = cur->next;
    }
    cur2->next = head2; 

    printList(head1); 
    cout <<"\n";
    printList(head2);
    return 0;
}

//q6
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

void deleteNode(node *&head, node *del, node *prev) {
    if (del == head) {
        prev->next = del->next;
        head = del->next; delete del;
    } else {
        prev->next = del->next; delete del;
    }
}

void printList(node *head) {
    node *cur = head;
    do {
        cout << cur->info << " ";
        cur = cur->next; 
    } while (cur != head);
}

int main() {
    node* head = nullptr;
    int i, n=0;
    while (cin >> i && i != -1) {
        if (n==0) {
            head = new node();
            head->info = i; head->next = nullptr;
        } else {
            add(head, i);
        }
        n++;
    }
    int k; cin >> k;
    //making circular
    node *cur = head; 
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = head;

    node *prev = cur; cur = head;
    while (cur->next != cur) {
        for (int i=1; i<k; i++) {
            cur = cur->next; prev = prev->next;
        }
        deleteNode(head, cur, prev);
        cur = prev->next;
    }
    printList(head);
    cout <<"\n";
    return 0;
}

//q7
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    string name;
    int info;
    node* next;
};

void add(node *head, string name, int data) {
    node *temp = new node(); node *cur = head;
    temp->next = nullptr;
    temp->info = data; temp->name = name;
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = temp;
}

string deleteNode(node *&head, node *del, node *prev) {
    string temp = del->name;
    if (del == head) {
        prev->next = del->next;
        head = del->next; delete del;
    } else {
        prev->next = del->next; delete del;
    }
    return temp;
}

void printList(node *head) {
    node *cur = head;
    do {
        cout << cur->info << " ";
        cur = cur->next; 
    } while (cur != head);
}

int main() {
    node* head = nullptr;
    int k; cin >> k;
    string name; int time;
    for (int i=0; i<k; i++) {
        cin >> name >> time;
        if (i==0) {
            head = new node();
            head->name = name; head->info = time; head->next = nullptr;
        } else {
            add(head, name, time);
        }
    }
    //making circular
    node *cur = head; 
    while (cur->next != nullptr) {
        cur = cur->next;
    }
    cur->next = head;

    node *prev = cur; cur = head;
    while (cur->next != cur) {
        cur->info = cur->info - 5; 
        if (cur->info < 0) {cout << deleteNode(head, cur, prev) << " "; cur = prev->next;}
        else {cur = cur->next; prev = prev->next;}
    }

    cout << head->name;
    cout <<"\n";
    return 0;
}

//q8
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    string name;
    vector<string> names;
    node* next;
    node* prev;
};

int main() {
    node *head = nullptr; node *cur = nullptr;
    int n; cin >> n;
    bool found = false;
    string name, a;
    for (int i=0; i<n; i++) {
        cin >> name;
        if (i==0) {
            head = new node();
            head->next = nullptr; head->prev = nullptr;
            head->name = name;
            while (cin >> a && a != "-1") {
                head->names.push_back(a);
            }
            cur = head;
        } else {
            node *temp = new node();
            temp->next = nullptr; cur->next = temp; temp->prev = cur;
            temp->name = name;
            while (cin >> a && a != "-1") {
                temp->names.push_back(a);
            }
            cur = temp;
        }
    }
    string start, person; cin >> start >> person;
    node *x = head;
    while (x!= nullptr) {
        if (x->name == start) {break;}
        x = x->next;
    }

    //search forwards
    node *y = x;
    while (y!= nullptr) {
        for (string i : y->names) {
            if (i == person) {
                found = true; cout << y->name; break;
            }
        }
        y = y->next;
    }
    //search backwards
    y = x;
    while (y!=nullptr) {
        for (string i : y->names) {
            if (i == person) {
                found = true; cout << y->name; break;
            }
        }
        y = y->prev;
    }

    if (!found) cout << -1;
    cout <<"\n";
    return 0;
}

//q5
