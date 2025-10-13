//q1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int hashFunction(int key, int m) {
    return key % m;
}

void insertKey(int table[], int m, int key) {
    int i = hashFunction(key, m); int j = i;
    do {
        if (table[i] == -1 || table[i] == -2) {
            table[i] = key;
            return;
        }
        if (table[i] == key) return;
        i = (i + 1) % m;
    } while (i != j);
}

void deleteKey(int table[], int m, int key) {
    int i = hashFunction(key, m);int j = i;
    do {
        if (table[i] == -1) return;
        if (table[i] == key) {
            table[i] = -2;
            return;
        }
        i = (i + 1) % m;
    } while (i != j);
}

bool searchKey(int hashTable[], int tableSize, int key, int &probes) {
    int i = hashFunction(key, tableSize);int j = i; probes = 0;
    do {
        probes++;
        if (hashTable[i] == -1) return false; 
        if (hashTable[i] == key) return true;
        i = (i + 1) % tableSize;
    } while (i != j);
    return false;
}


int main() {
    int m; cin >> m;
    char s; int key;int table[m]; int probes = 0;
    for (int i=0; i<m; i++) table[i] = -1;
    while (true) {
        cin >> s >> key;
        if (s == 'I') {
            insertKey(table, m, key);
        } else if (s == 'D') {
            deleteKey(table, m, key);
        } else if (s == 'S') {
            if (searchKey(table, m, key, probes)) cout << "found " << probes << "\n";
            else cout << "not found " << probes << "\n";
            break;
        }
    }
    return 0;
}
//q2
#include <iostream>
using namespace std;
typedef long long ll;

struct node {
    int key;
    node* next;
};

int hashFunction(int key, int m) {
    return key % m;
}

void insertKey(node* table[], int m, int key) {
    int i = hashFunction(key, m); node* head = table[i];node* temp = head;
    while (temp != nullptr) {
        if (temp->key == key)
            return;
        temp = temp->next;
    }
    node* newnode = new node;
    newnode->key = key;newnode->next = head;
    table[i] = newnode;
}

void deleteKey(node* table[], int m, int key) {
    int i = hashFunction(key, m);
    node* curr = table[i];node* prev = nullptr;
    while (curr != nullptr) {
        if (curr->key == key) {
            if (prev == nullptr) table[i] = curr->next;
            else prev->next = curr->next;
            delete curr; return;
        }
        prev = curr; curr = curr->next;
    }
}

bool searchKey(node* table[], int m, int key) {
    int i = hashFunction(key, m); node* curr = table[i];
    while (curr != nullptr) {
        if (curr->key == key)return true;
        curr = curr->next;
    }
    return false;
}

int main() {
    int m;cin >> m;
    node* table[m];
    for (int i=0; i<m; i++) table[i] = nullptr;
    char s;int key;
    while (cin >> s >> key) {
        if (s == 'I') {
            insertKey(table, m, key);
        }  else if (s == 'D') {
            deleteKey(table, m, key);
        } else if (s == 'S') {
            bool found = searchKey(table, m, key);
            if (found) cout << "Found\n";
            else cout << "NotFound\n";
            break;
        }
    }
    return 0;
}

//q3
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s; cin >> s;
    int lastIndex[256];
    for (int i=0; i <256; i++)lastIndex[i] = -1;
    int maxsz = 0;int start = 0;
    for (int i = 0; i<s.length(); ++i) {
        char c = s[i];
        if (lastIndex[c] >= start) {
            start = lastIndex[c]+1;
        }
        lastIndex[c] = i; int sz = i-start + 1;
        if (sz > maxsz) maxsz = sz;
    }

    cout << maxsz << "\n";
    return 0;
}

//q4
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s; cin >> s;
    int roman[256] = {0}; 
    roman['I'] = 1; roman['V'] = 5;roman['X'] = 10; roman['L'] = 50; roman['C'] = 100; roman['D'] = 500; roman['M'] = 1000;
    int n = s.length();int result = 0;
    for (int i = 0; i < n; ++i) {
        int curr = roman[(char)s[i]]; int next = 0;
        if (i+1 < n) next = roman[(char)s[i+1]];
        if (curr < next)result -= curr;
        else result += curr;
    }
    cout << result << "\n";
    return 0;
}
//q5
