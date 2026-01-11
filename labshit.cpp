#include <bits/stdc++.h>
#include <fstream>
using namespace std;
using ll = long long;
#define pb push_back 
#define fi first
#define se second
#define vint vector<int> 
#define vll vector<ll>
#define vin(arr, n)vint arr(n);for(int i=0;i<(n);i++)cin>>arr[i];
#define vout(arr) do{for (auto i:(arr))cout<<i<<" ";cout << "\n";}while(0)

struct node {
    int data;
    node* left;
    node* right;
};

node* createNode(int val) {
    node* temp = new node;
    temp->left = nullptr;
    temp->right = nullptr;
    temp->data = val;
    return temp;
}

node* insertNode(node *cur, int val) {
    if (cur == nullptr) {
        return createNode(val);
    }
    if (val < cur->data) {
        cur->left = insertNode(cur->left, val);
    } else {
        cur->right = insertNode(cur->right, val);
    }
    return cur;
}

bool search(node* cur, int val) {
    if (cur == nullptr) return false;
    if (cur->data == val) return true;
    if (val < cur->data) {
        return search(cur->left, val);
    } else {
        return search(cur->right, val);
    }
}

node* findMin(node* cur) {
    while (cur && cur->left != nullptr) {
        cur = cur->left;
    }
    return cur;
}

node* findMax(node* cur) {
    while (cur && cur->right != nullptr) {
        cur = cur->right;
    }
    return cur;
}

node* deleteNode(node* cur, int val) {
    if (cur == nullptr) {return cur;}
    if (val < cur->data) {
        cur->left = deleteNode(cur->left, val);
    } else if (val > cur->data) {
        cur->right = deleteNode(cur->right, val);
    } else {
        if (cur->left == nullptr) {
            node* temp = cur->right;
            delete cur;
            return temp;
        } else if (cur->right == nullptr) {
            node* temp = cur->left;
            delete cur;
            return temp;
        } else {
            node* temp = findMin(cur->right);
            cur->data = temp->data;
            cur->right = deleteNode(cur->right, temp->data);
        }
    }
    return cur;
}

void pre(node* cur) {
    if (cur == nullptr) return;
    cout << cur->data << " ";
    pre(cur->left);
    pre(cur->right);
}

void post(node* cur) {
    if (cur == nullptr) return;
    post(cur->left);
    post(cur->right);
    cout << cur->data << " ";
}

void inord(node* cur) {
    if (cur == nullptr) return;
    inord(cur->left);
    cout << cur->data << " ";
    inord(cur->right);
}


int main() {
    ofstream file;
    file.open("name.txt");
    file << "text to be written\n";
    file.close();

    //line by line
    ifstream file2;
    file2.open("name.txt");
    string line;
    while(getline(file2, line)) {
        cout << line << endl;
    }
    file2.close();

    //word by word
    ifstream file3;
    file3.open("name.txt");
    string word;
    while (file3 >> word) {
        cout << word << "\n";
    }
    file3.close();
    // Mode	Meaning
    // ios::in	Read
    // ios::out	Write
    // ios::app	Append ofstream file("data.txt", ios::app);
    // ios::ate	Start at end
    // ios::trunc	Clear file
    // ios::binary	Binary mode
    // fstream file("data.txt", ios::in | ios::out);
}
