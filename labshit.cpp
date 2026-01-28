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

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[high]);
    return i+1;
}

int randomPartition(int arr[], int low, int high) {
    int randint = low + rand() % (high - low + 1);
    swap(arr[randint], arr[high]);  
    return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = randomPartition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* ===================== MERGESORT ===================== */

void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

/* ===================== COUNTING SORT ===================== */

void countingSort(vector<int>& arr)
{
    if (arr.empty()) return;

    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());

    int range = maxVal - minVal + 1;
    vector<int> count(range, 0);

    for (int num : arr)
        count[num - minVal]++;

    int index = 0;
    for (int i = 0; i < range; i++)
        while (count[i]--)
            arr[index++] = i + minVal;
}

/* ===================== RADIX SORT ===================== */

int getMax(const vector<int>& arr)
{
    return *max_element(arr.begin(), arr.end());
}

void countingSortRadix(vector<int>& arr, int exp)
{
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    arr = output;
}

void radixSort(vector<int>& arr)
{
    int maxVal = getMax(arr);

    for (int exp = 1; maxVal / exp > 0; exp *= 10)
        countingSortRadix(arr, exp);
}

/* ===================== BUCKET SORT ===================== */

void bucketSort(vector<int>& arr)
{
    if (arr.empty()) return;

    int maxVal = *max_element(arr.begin(), arr.end());
    int minVal = *min_element(arr.begin(), arr.end());

    int bucketCount = sqrt(arr.size());
    vector<vector<int>> buckets(bucketCount);

    double range = (double)(maxVal - minVal + 1) / bucketCount;

    for (int num : arr)
    {
        int index = (int)((num - minVal) / range);
        if (index == bucketCount) index--;
        buckets[index].push_back(num);
    }

    arr.clear();
    for (auto& bucket : buckets)
    {
        sort(bucket.begin(), bucket.end());
        for (int num : bucket)
            arr.push_back(num);
    }
}

int main() {
    srand(time(0));
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

    //for csv 
    
    // int id;
    // string name;
    // float score;
    
    // string line;
    // while (getline(file, line)) {
    //     stringstream ss(line);
    //     string temp;
    
    //     getline(ss, temp, ',');
    //     id = stoi(temp);
    
    //     getline(ss, name, ',');
    
    //     getline(ss, temp, ',');
    //     score = stof(temp);
    
    //     cout << id << " " << name << " " << score << endl;
    // }
}
