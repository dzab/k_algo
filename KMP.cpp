#include <cstdio>
#include <string>
#include <vector>

void preKMP(const std::string &pattern, std::vector<int> &next)
{
    int i = 0;
    int j = next[0] = -1;
    int n = pattern.size();
    while (i < n) {
        while (j > -1 && pattern[i] != pattern[j]) {
            j = next[j];
        }
        ++i; ++j;
        if (pattern[i] == pattern[j]) 
            next[i] = next[j];  // if you mismatch j, you will also mismatch next[j]
        else 
            next[i] = j;
    }
}

int KMP(const std::string &str, const std::string &pattern)
{
    std::vector<int> next(pattern.size());
    preKMP(pattern, next);

    int i = 0; int j = 0;
    int n = str.size();
    while (i < n) {
        while (j > -1 && str[i] != pattern[j]) {
            j = next[j];
        }
        ++i; ++j;
        if (j >= pattern.size()) {
            return i-j;
        }
    }
}

int main()
{
    std::string str("abcdfgfadfa");
    std::string pattern("dfa");
    printf("%d", KMP(str, pattern));
    return 0;
}
