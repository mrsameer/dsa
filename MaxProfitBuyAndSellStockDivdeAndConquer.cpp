#include <iostream>

int findMin(int a[], int i, int u);
int findMax(int a[], int i, int u);

int maxSubArray(int a[], int l, int u) {
   if (u == l) {
       // one element in the array
       return 0;
   } else if (u == l + 1) {
       // two elements in the array
       return std::max(a[u] - a[l], 0);  // doing max to avoid short sell of stock
   }
   int mid = (l + u) / 2 ;
   int m1 = maxSubArray(a, l, mid);
   int m2 = maxSubArray(a, mid + 1, u);
   int y1 = findMax(a, mid + 1, u);
   int x1 = findMin(a, l, mid);
   return std::max({m1, m2, y1 - x1});
}

int findMin(int a[], int l, int u) {
    int ans = INT32_MAX;
    for (int i = l; i <= u; ++i) {
        ans = std::min(a[i], ans);
    }
    return ans;
}

int findMax(int a[], int l, int u) {
    int ans = INT32_MIN;
    for (int i = l; i <= u; ++i) {
        ans = std::max(a[i], ans);
    }
    return ans;
}

int main() {
    int n;
    std::cout << "Enter the n: " << std::endl;
    std::cin >> n;

    std::cout << "Enter the " << n << " integers: ";
    int a[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::cout << maxSubArray(a, 0, n - 1) << std::endl;
    return 0;
}
