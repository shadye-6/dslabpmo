as2
//q1
bool compare (string s1, string s2) {
    if (s1.size() == s2.size()) {
        for (int i=0; i<s1.size(); i++) {
            if (s1[i] == s2[i]) continue;
            else {
                return (s1[i] < s2[i]);
            }
        }
    } else {
        return (s1.size() < s2.size());
    }
    return true;
}

void merge (string *arr, int l1, int r1, int l2, int r2){
    int Lsize = r1-l1+1, Rsize = r2-l2+1;
    string L[Lsize], R[Rsize];
    for (int i=l1; i<=r1; i++) L[i-l1] = arr[i];
    for (int i=l2; i<=r2; i++) R[i-l2] = arr[i];

    int lit = 0, rit = 0, arrit = l1;
    while (lit < Lsize && rit < Rsize) {
        if (compare(L[lit], R[rit])) {
            arr[arrit++] = L[lit++];
        } else {
            arr[arrit++] = R[rit++];
        }
    }
    if (lit == Lsize) {
        while (rit < Rsize){
            arr[arrit++] = R[rit++];
        }
    }
    else if (rit == Rsize) {
        while (lit < Lsize) {
            arr[arrit++] = L[lit++];
        }
    }
    return;
}

void mergesort(string *arr, int l ,int r){
    if (l < r) {
        int mid = (l+r)/2;
        mergesort(arr, l, mid); mergesort(arr, mid+1, r);
        merge(arr, l, mid, mid+1, r);
    }
}

#include <iostream>
#include <string>
using namespace std;
#define ll long long
#include "functions.h"


int main() {
    int n; cin >> n;
    string arr[n];
    for (string &i : arr) cin >> i;

    mergesort(arr, 0, n-1); 
    for (string i : arr) cout << i << " ";
    cout << "\n";
    return 0;
}

//q2
#include <iostream>
using namespace std;
#define ll long long

int main() {
    int n, a; cin >> n;
    int arr[3] = {0, 0, 0};
    for (int i=0; i<n; i++) {
        cin >> a; arr[a]++;
    }
    
    while(arr[0]--) cout << 0 << " ";
    while(arr[1]--) cout << 1 << " ";
    while(arr[2]--) cout << 2 << " ";
    cout << "\n";
    return 0;
}

//q3
#include <iostream>
using namespace std;
#define ll long long

void merge (int *arr, int l1, int r1, int l2, int r2){
    int Lsize = r1-l1+1, Rsize = r2-l2+1;
    int L[Lsize], R[Rsize];
    for (int i=l1; i<=r1; i++) L[i-l1] = arr[i];
    for (int i=l2; i<=r2; i++) R[i-l2] = arr[i];

    int lit = 0, rit = 0, arrit = l1;
    while (lit < Lsize && rit < Rsize) {
        if (L[lit] < R[rit]) {
            arr[arrit++] = L[lit++];
        } else {
            arr[arrit++] = R[rit++];
        }
    }
    if (lit == Lsize) {
        while (rit < Rsize){
            arr[arrit++] = R[rit++];
        }
    }
    else if (rit == Rsize) {
        while (lit < Lsize) {
            arr[arrit++] = L[lit++];
        }
    }
    return;
}

void mergesort(int *arr, int l ,int r){
    if (l < r) {
        int mid = (l+r)/2;
        mergesort(arr, l, mid); mergesort(arr, mid+1, r);
        merge(arr, l, mid, mid+1, r);
    }
}

int main() {
    int n, a; cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) {
        cin >> arr[i]; arr[i] *= arr[i];
    }

    mergesort(arr, 0, n-1);
    for (int i : arr) cout << i << " ";
    cout << "\n";
    return 0;
}

//q8
#include <iostream>
using namespace std;
#define ll long long

bool compare (string s1, string s2) {
    int lenStr = 10;
    for (int i=6; i<10; i++) {
        if (s1[i] == s2[i]) continue;
        else return (s1[i] < s2[i]);
    }
    for (int i=3; i<5; i++) {
        if (s1[i] == s2[i]) continue;
        else return (s1[i] < s2[i]);
    }
    for (int i=0; i<2; i++) {
        if (s1[i] == s2[i]) continue;
        else return (s1[i] < s2[i]);
    }
    return true;
}

void merge (string *arr, int l1, int r1, int l2, int r2){
    int Lsize = r1-l1+1, Rsize = r2-l2+1;
    string L[Lsize], R[Rsize];
    for (int i=l1; i<=r1; i++) L[i-l1] = arr[i];
    for (int i=l2; i<=r2; i++) R[i-l2] = arr[i];

    int lit = 0, rit = 0, arrit = l1;
    while (lit < Lsize && rit < Rsize) {
        if (compare(L[lit], R[rit])) {
            arr[arrit++] = L[lit++];
        } else {
            arr[arrit++] = R[rit++];
        }
    }
    if (lit == Lsize) {
        while (rit < Rsize){
            arr[arrit++] = R[rit++];
        }
    }
    else if (rit == Rsize) {
        while (lit < Lsize) {
            arr[arrit++] = L[lit++];
        }
    }
    return;
}

void mergesort(string *arr, int l ,int r){
    if (l < r) {
        int mid = (l+r)/2;
        mergesort(arr, l, mid); mergesort(arr, mid+1, r);
        merge(arr, l, mid, mid+1, r);
    }
}

int main() {
    int n, a; cin >> n;
    string arr[n];
    for (string &i: arr) cin >> i;

    mergesort(arr, 0, n-1);

    for (string i : arr) cout << i << "\n";
    return 0;
}

//q5
#include <iostream>
using namespace std;
#define ll long long

int main() {
    int m, n; cin >> m >> n;
    int nums1[m+n], nums2[n];
    for (int &i : nums1) cin >> i;
    for (int &i : nums2) cin >> i;
    int r1 = m-1, r2 = n-1, r = n+m-1;
    while (r1 >= 0 && r2 >= 0) {
        if (nums1[r1] > nums2[r2]) {
            nums1[r--] = nums1[r1--];
        } else {
            nums1[r--] = nums2[r2--];
        }
    }
    if (r1 == -1) {
        while(r2 >= 0) {
            nums1[r--] = nums2[r2--];
        }
    }
    if (r2 == -1) {
        while (r1 >= 0) {
            nums1[r--] = nums1[r1--];
        }
    }
    for (int i : nums1) cout << i << " ";
    return 0;
}

//q7
#include <iostream>
using namespace std;
#define ll long long

int main() {
    int n; cin >> n;
    int arr[n]; 
    for (int &i : arr) cin >> i;
    int cur = arr[0]; int l=1;
    for (int i=0; i<n; i++) {
        if (arr[i] != cur) {
            cur = arr[i]; arr[l++] = cur;
        }
    }
    cout << l << "\n";
    return 0;
}

//q2
#include <iostream>
using namespace std;
#define ll long long

bool compare (string s11, string s12, string s21, string s22) {
    if (s12 == s22){
        int l =0; 
        while (l < s11.size() && l < s21.size()){
            if (s11[l] == s21[l]) {l++;}
            else {
                return (s11[l] < s21[l]);
            }
        }
        return (s11.size() < s21.size());
    } else {
        int l = 0;
        while (l < s12.size() && l < s22.size()){
            if (s12[l] == s22[l]) {l++;}
            else {
                return (s12[l] < s22[l]);
            }
        }
        return (s12.size() < s22.size());
    }

}

void merge (string *arr, string *arr2, int l1, int r1, int l2, int r2){
    int Lsize = r1-l1+1, Rsize = r2-l2+1;
    string L[Lsize], R[Rsize]; string L2[Lsize], R2[Rsize];

    for (int i=l1; i<=r1; i++) {L[i-l1] = arr[i]; L2[i-l1] = arr2[i];}
    for (int i=l2; i<=r2; i++) {R[i-l2] = arr[i]; R2[i-l2] = arr2[i];}

    int lit = 0, rit = 0, arrit = l1;
    while (lit < Lsize && rit < Rsize) {
        if (compare(L[lit], L2[lit], R[rit], R2[rit])) {
            arr[arrit] = L[lit]; arr2[arrit++] = L2[lit++];
        } else {
            arr[arrit] = R[rit]; arr2[arrit++] = R2[rit++];
        }
    }
    if (lit == Lsize) {
        while (rit < Rsize){
            arr[arrit] = R[rit]; arr2[arrit++] = R2[rit++];
        }
    }
    else if (rit == Rsize) {
        while (lit < Lsize) {
            arr[arrit] = L[lit]; arr2[arrit++] = L2[lit++];
        }
    }
    return;
}

void mergesort(string *arr, string *arr2, int l ,int r){
    if (l < r) {
        int mid = (l+r)/2;
        mergesort(arr, arr2, l, mid); mergesort(arr, arr2, mid+1, r);
        merge(arr, arr2, l, mid, mid+1, r);
    }
}

int main() {
    int n; cin >> n;
    string name[n], dept[n];
    for (int i=0; i<n; i++) cin >> name[i] >> dept[i];

    mergesort(name, dept, 0, n-1);

    for (int i=0; i<n; i++) {
        cout << name[i] <<  " " << dept[i] << "\n";
    }
    return 0;
}


