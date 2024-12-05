#include <iostream>

#include <vector>

#include <algorithm>

#include <numeric>

using namespace std;





int partition(vector<int>& arr, int low, int high) {



    int pivot = arr[high];



    int i = low - 1;



    for (int j = low; j < high; j++) {



        if (arr[j] <= pivot) {



            i++;



            swap(arr[i], arr[j]);



        }



    }



    swap(arr[i + 1], arr[high]);



    return i + 1;



}





void quickSort(vector<int>& arr, int low, int high) {



    if (low < high) {



        int pi = partition(arr, low, high);



        quickSort(arr, low, pi - 1);



        quickSort(arr, pi + 1, high);



    }



}





int minWasted(vector<int>& packages, vector<vector<int>>& boxes) {



    int n = packages.size();



    long long mod = 1e9 + 7;



    long long result = LLONG_MAX;





    quickSort(packages, 0, n - 1);



    for (auto& supplier : boxes) {





        quickSort(supplier, 0, supplier.size() - 1);



        if (supplier.back() < packages.back()) continue;



        long long waste = 0;



        int prevIdx = 0;



        for (int boxSize : supplier) {



            auto it = upper_bound(packages.begin() + prevIdx, packages.end(), boxSize);



            int idx = it - packages.begin();



            waste += (long long)boxSize * (idx - prevIdx) - accumulate(packages.begin() + prevIdx, packages.begin() + idx, 0LL);



            prevIdx = idx;



        }



        result = min(result, waste);



    }



    return result == LLONG_MAX ? -1 : result % mod;



}



int main() {



    vector<int> packages = {3, 5, 8, 10, 11, 12};



    vector<vector<int>> boxes = {{12}, {11, 9}, { 10, 5, 14}};



    cout << "Output: " << minWasted(packages, boxes) << endl;



    return 0;



} 

