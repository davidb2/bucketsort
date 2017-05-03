#include "bucket.h"
#include <iostream>
#include <cmath>


// I encourage you to try with different radixes
#define NUM_BUCKETS 10


/**
 * finds the number of digits in the longest number
 * @param arr    the input array
 * @param size   the size of arr
 * @return       the length of the largest number
 */
int find_k(int * arr, int size) {
    int k = -1;
    for (int i = 0; i < size; i++) {
        // find max digits in the given base
        k = std::max(k, (int) (log(arr[i]) / log(NUM_BUCKETS)));
    }
    return k + 1;
}


/**
 * an in-place O(kn) sort 
 * @param  arr   the input array
 * @param  size  the size of arr
 */
void bucket_sort(int * arr, int size) {
    // stores buckets
    bucket buckets[NUM_BUCKETS];
    
    // greatest number of digits
    int k = find_k(arr, size);
    int lim = pow(NUM_BUCKETS, k);

    // iterate k times 
    for (int d = NUM_BUCKETS; d <= lim; d *= NUM_BUCKETS) {
        // push the number into their buckets
        for (int i = 0; i < size; i++) {
            buckets[arr[i] / d % NUM_BUCKETS].push(arr[i]);
        }
  
        int i = 0;
        // sequentially take them out of of their buckets in order
        for (int j = 0; j < NUM_BUCKETS; j++) {
            while (!buckets[j].empty()) {
                arr[i++] = buckets[j].pop();
            }
        }
    } 
}

/**
 * bucket sort - this version only works for non-negative integers
 *               but could easily be extended
 */
int main() {
    // get array size an allocate that block of mem on the heap
    int n; std::cin >> n;
    int * arr = new int[n];
    
    // take input
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    // sort
    bucket_sort(arr, n);
    
    // print sorted array
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    
    // nothing to see here
    delete[] arr;
    arr = NULL;
}
