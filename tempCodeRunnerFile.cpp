#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

int getMinTime(int n, vector<int>& cache) {
    // Edge case
    if (n == 0 || cache.empty()) return 0;
    
    // Arrays to track counts of cached and non-cached requests for each service
    vector<int> cached_count(n + 1, 0);
    vector<int> non_cached_count(n + 1, 0);
    
    int m = cache.size();
    
    // Calculate counts
    for (int i = 0; i < m; ++i) {
        int service = cache[i];
        if (i % 2 == 0) {
            cached_count[service]++;
        } else {
            non_cached_count[service]++;
        }
    }
    
    // Calculate minimum time
    int min_time = INT_MAX;
    for (int service = 1; service <= n; ++service) {
        int time = cached_count[service] * 1 + non_cached_count[service] * 2;
        min_time = min(min_time, time);
    }
    
    return min_time;
}

int main() {
    int n = 3;
    vector<int> cache = {1, 1, 3, 1, 1};
    int min_time = getMinTime(n, cache);
    cout<<"Minimum time to process all requests: " <<min_time<<endl; // Output should be 3
    return 0;
}