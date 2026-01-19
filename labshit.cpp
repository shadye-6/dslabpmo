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
