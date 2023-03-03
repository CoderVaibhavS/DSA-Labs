#include <stdio.h>

void swap(int arr[], int pInd, int lo) {
    int temp = arr[pInd];
    arr[pInd] = arr[lo];
    arr[lo] = temp;
}

int part(int arr[], int lo, int hi, int pInd) {
    swap(arr, pInd, lo);
    int left, right, pivPos;
    int pivot = arr[lo]; // isolate pivot to the leftmost position
    left = lo + 1;
    right = hi;

    while(left < right) {
        for(; left <= hi && arr[left] <= pivot; left++);

        for(; arr[right] > pivot; right--);

        if(left < right) {
            swap(arr, left, right); // int the left partition element is greater and vice versa
            left++;
            right--;
        }
    }

    if(arr[left] < pivot && left <= hi) {
        pivPos = left;
    }
    else {
        pivPos = left-1;
    }
    swap(arr, lo, pivPos);

    return pivPos;
}

int qselect(int arr[], int n, int k) {
    int pivot, lo, hi, pInd;
    lo = 0;
    hi = n-1;
    pInd = part(arr, lo, hi, lo);
    if(k <= pInd)
        return qselect(arr, pInd, k);
    else if(k > pInd+1)
        return qselect(arr + pInd + 1, n - pInd - 1, k - pInd - 1);
    else
        return arr[pInd];
}

void closest_k_elem(int arr[], int n, int k) {
    int mid = n%2 == 0 ? n/2 : n/2+1;
    int lo = mid;
    int hi = mid;
    int ele = qselect(arr, n, mid);
    int l_ele, r_ele, m_ele = ele;
    printf("%d ", ele);
    k--;
    while(k--) {
        if(hi == n) {
            lo--;
            ele = qselect(arr, n, lo);
        }
        else if(lo == 1) {
            hi++;
            ele = qselect(arr, n, hi);
        }
        else {
            l_ele = qselect(arr, n, lo-1);
            r_ele = qselect(arr, n, hi+1);
            if(m_ele - l_ele >= r_ele - m_ele) {
                ele = r_ele;
                hi++;
            }
            else {
                ele = l_ele;
                lo--;
            }
        }
        printf("%d ", ele);
    }
    printf("\n");
}

int main() {

    int arr[5] = {1,3,5,7,9};
    closest_k_elem(arr, 5, 3);
}