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