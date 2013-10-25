#include <cstdio>
#include <vector>
#include <algorithm>
using std::vector;
//FindSortedArrayRotation

//见STL源码剖析 
//1. 分块,递归;  
//2, reverse前段,reverse后段,reverse全部, 
//3. gcd(前段len,全部len), while(n--) {循环移动}
int gcd(int a, int b);
void RotateAtX(std::vector<int> &v, int x) {
    int n = v.size();
    int step = gcd(n, x);
    int temp;
    int idx1, idx2; 
    while (step--) {
        idx1 = step;
        idx2 = (step + x)%n;
        temp = v[step];
        while (idx2 != step) {
            v[idx1] = v[idx2];
            idx1 = idx2;
            idx2 = (idx2+x)%n;
        }
        v[idx1] = temp;
        std::for_each(v.begin(), v.end(), [](int a){printf("%d ", a);});
        printf("   step=%d\n", step+1);
    }
}

int gcd(int a, int b) {
    int r;
    if (a <= b) std::swap(a, b);
    while (b!=0) {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int FindPivot(std::vector<int> &v) {
    int low = 0;
    int high = v.size()-1;
    int mid;
    while (v[low] > v[high]) {
        mid = low + (high - low)/2;
        if (v[mid] > v[high]) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main()
{
    int A[10] = { 0 };
    for (int i = 0; i < 10; ++i) A[i] = i;
    vector<int> v(A, A+10);
    int x;
    printf("input X: ");
    scanf("%d", &x);
    RotateAtX(v, x);
    printf("After rotated at %d\n", x);
    std::for_each(v.begin(), v.end(), [](int a){ printf("%d ", a); });
    printf("\n");
    printf("\nDetected pivot at %d\n", FindPivot(v));
    return 0;
}



