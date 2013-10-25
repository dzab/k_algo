#include <vector>
#include <algorithm>
using std::vector;

bool mynext_permutation(vector<int> &v, int begin, int end)
{ //要点:从后面找第一对相邻 *i <*ii, 
  //再从后面找第一个j, 使*i>*j, 交换*i,*j, reverse ii+1后所有元素
    if (begin<0||begin>v.size()||end<0||end>v.size()) return false; // invalid
    if (begin==end || begin+1==end) return false;  // less than one elem
    int i = end-1;
    for(;;) {
        int ii = i;
        --i;
        if (v[i] < v[ii]) {
            int j = end;
            while (v[i]>=v[--j]);
            std::swap(v[i],v[j]);
            int s = ii, e = end;
            while(s+1<e) std::swap(v[s++], v[--e]); 
            return true;
        }
        if (i == begin) { //已经到头
            while(begin+1 < end) std::swap(v[begin++], v[--end]);
            return false;
        }
    }
}

bool myprev_permutation(vector<int> &v, int begin, int end)
{
    if (begin<0||begin>v.size()||end<0||end>v.size()) return false;
    if (begin==end || begin+1==end) return false;  // less than one elem
    int i = end-1;
    for(;;) {
        int ii = i;
        --i;
        if (v[i] > v[ii]) {  // <--
            int j = end;
            while (v[i]<=v[--j]);  // <--
            std::swap(v[i],v[j]);
            int s = ii, e = end;
            while(s+1<e) std::swap(v[s++], v[--e]);
            return true;
        }
        if (i == begin) {
            while (begin+1 < end) std::swap(v[begin++], v[--end]);
            return false;
        }
    }
}

int main()
{
    vector<int> v = { 1,2,3};
    vector<int> v2 = v;
    do {
        std::for_each(v.begin(), v.end(), [](int a) { printf("%d ", a); });
        printf("\n");
    }while(std::next_permutation(v.begin(), v.end()));

    printf("--------------\n");
    do {
        std::for_each(v2.begin(), v2.end(), [](int a) { printf("%d ", a); });
        printf("\n");
    }while(mynext_permutation(v2, 0, v2.size()));

    printf("=============\n");
    int s = 0, e = v.size();
    while (s+1<e) { std::swap(v[s++], v[--e]); }
    s = 0; e = v2.size();
    while (s+1<e) { std::swap(v2[s++], v2[--e]); }
    do {
        std::for_each(v.begin(), v.end(), [](int a) { printf("%d ", a); });
        printf("\n");
    }while(std::prev_permutation(v.begin(), v.end()));

    printf("--------------\n");
    do {
        std::for_each(v2.begin(), v2.end(), [](int a) { printf("%d ", a); });
        printf("\n");
    }while(myprev_permutation(v2, 0, v2.size()));
        
        
    return 0;
    
}

