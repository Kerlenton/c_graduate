#include <stdio.h>

typedef int (*cmp_t)(const void *lhs, const void *rhs);

void *cbsearch(const void *key, const void *base, int num, int size, cmp_t cmp) {
    int low = 0, high = num - 1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        const void *mid_element = (const char *)base + mid * size;
        int cmp_result = cmp(key, mid_element);
        
        if (cmp_result == 0) {
            return (void *)mid_element;
        } else if (cmp_result < 0) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return NULL;
}
