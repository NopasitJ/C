#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using std::map;
using std::set;
using std::string;
using std::vector;
using namespace std;
static bool isPalindome(long long n);

int main() {
    long long upper_limit = 1000000000LL;

    set<long long> square;
    for (long long a = 2; a < sqrt(upper_limit); ++a) {
        square.insert(a * a);
    }

    set<long long> cube;
    for (long long b = 2; b * b * b < upper_limit; ++b) {
        cube.insert(b * b * b);
    }

    map<long long, int> candidates;
    for (long long s : square) {
        for (long long c : cube) {
            if (isPalindome(s + c)) {
                ++candidates[s + c];
            }
        }
    }

    vector<long long> result;
    for (auto kv : candidates) {
        if (kv.second == 4) {
            result.push_back(kv.first);
        }
    }

    if (result.size() >= 5) {
        sort(result.begin(), result.end());
        cout << accumulate(result.begin(), result.begin() + 5, 0);
    }
}

static bool isPalindome(long long n) {
    string original = to_string(n);
    string reversed(original.rbegin(), original.rend());
    return original == reversed;
}