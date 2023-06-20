#include<bits/stdc++.h>
using namespace std;

// Quick Sort
int partition(vector<int>& arr, int start, int end) {
    int ind = 0, pivot = arr[end], pivotind;
    vector<int> temp(end-start+1);
    for(int i = start; i<= end; i++) {
        if(arr[i] < pivot) {
            temp[ind] = arr[i];
            ind++;
        }
    }
    temp[ind] = pivot;
    ind++;
    for(int i = start; i < end; i++) {
        if(arr[i] > pivot) {
            temp[ind] = arr[i];
            ind++;
        }
    }

    ind = 0;
    for(int i = start; i <= end; i++) {
        if(arr[i] == pivot) {
            pivot = i;
        }
        arr[i] = temp[ind];
        ind++;
    }
    return pivot;
}

void quickSort(vector<int> &arr, int start , int end) {
    if(start < end) {
        int ind = partition(arr, start, end);
        quickSort(arr, start, ind-1);
        quickSort(arr, ind+1, end);
    }
    return;
}


// Merge Sort
void merge(vector<int> &arr, int left, int mid, int right) {
    int one = mid - left + 1;
    int two = right - mid;

    vector<int> leftarr(one), rightarr(two);
    for(int i = 0; i < one; i++) {
        leftarr[i] = arr[left + i];
    }
    for(int i = 0; i < two; i++) {
        rightarr[i] = arr[mid + 1 + i];
    }
    int indone = 0, indtwo = 0;
    int indmerge = left;

    while(indone < one && indtwo < two) {
        if(leftarr[indone] <= rightarr[indtwo]) {
            arr[indmerge] = leftarr[indone];
            indone++;
        } else {
            arr[indmerge] = rightarr[indtwo];
            indtwo++;
        }
        indmerge++;
    }
    
    while(indone < one) {
        arr[indmerge] = leftarr[indone];
        indone++;
        indmerge++;
    }

    while(indtwo < two) {
        arr[indmerge] = rightarr[indtwo];
        indtwo++;
        indmerge++;
    }
}

void mergeSort(vector<int> &arr, int begin, int end) {
    if(begin >= end) return;
    
    int mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

int ternarySearch(vector<int>& arr, int target) {
    int l = 0, r = arr.size()-1;
    while(r >= l) {
        int mid1 = l + (r-l)/3;
        int mid2 = r - (r-l)/3;
        if(arr[mid1] == target) {
            return mid1;
        }
        if(arr[mid2] == target) {
            return mid2;
        }
        if(target < arr[mid1]) r = mid1-1;
        else if(target > arr[mid2]) l = mid2+1;
        else {
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {5,12,7,1,13,2,23,11,18};
    cout<<"QuickSort"<<endl;
    for(int i=0;i<arr.size();i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    quickSort(arr, 0, arr.size()-1);
    for(int i=0;i<arr.size();i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<endl<<"MergeSort"<<endl;
    arr = {5,1,7,8,4,6,2,3,9,1,4,5,3,3,5};
    for(int i=0;i<arr.size();i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    mergeSort(arr, 0, arr.size()-1);
    for(int i=0;i<arr.size();i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<endl<<"Ternary Search"<<endl;
    arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    cout<<ternarySearch(arr, 13)<<endl;
    return 0;
}