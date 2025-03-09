#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>
#include <cmath>
#include <string>
#include <stack>
#include <unordered_map>
#include <utility>
#include <algorithm>

// ################ Burrows-Wheeler-Transformation - https://www.codewars.com/kata/54ce4c6804fcc440a1000ecb ################

std::pair<std::string, int> encode(const std::string &s) {
    if (s.empty()) return { "", 0 };
    
    std::string temp = s;
    std::vector<std::string> res = { s };
    
    for (size_t i = 1; i < s.size(); ++i) {
        std::rotate(temp.begin(), temp.end() - 1, temp.end());
        res.push_back(temp);
    }
    
    std::sort(res.begin(), res.end());
    
    int position = -1;
    std::string last_col;
    for (size_t i = 0; i < res.size(); i++) {
        last_col += res[i].back();
        if (res[i] == s) {
            position = i;
        }
    }
    
    return std::make_pair(last_col, position);
}

std::string decode(const std::string &last_col, int primary_index) {
    int n = last_col.size();
    
    std::string F = last_col;
    std::sort(F.begin(), F.end());
    
    std::vector<int> first_occ(256, 0);
    for (int i = 0; i < n; ++i) {
        if (i == 0 || F[i] != F[i - 1])
        first_occ[F[i]] = i;
    }
    
    std::vector<int> T(n);
    std::vector<int> occ(256, 0);
    for (int i = 0; i < n; ++i) {
        char c = last_col[i];
        occ[c]++;
        T[i] = first_occ[c] + occ[c] - 1;
    }
    
    std::string res;
    res.reserve(n);
    int i = primary_index;
    for (int j = 0; j < n; ++j) {
        res.push_back(last_col[i]);
        i = T[i];
    }
    std::reverse(res.begin(), res.end());
    return res;
}

// ################ Counting Change Combinations - https://www.codewars.com/kata/541af676b589989aed0009e7 ################

unsigned long long countChange(const unsigned int money, const std::vector<unsigned int>& coins) {
    std::vector<unsigned long long> dp(money + 1, 0);
    dp[0] = 1;
    
    for (const unsigned int coin : coins) {
        for (unsigned int amount = coin; amount <= money; ++amount) {
            dp[amount] += dp[amount - coin];
        }
    }
    
    return dp[money];
}

// ################ Number of trailing zeros of N! - https://www.codewars.com/kata/52f787eb172a8b4ae1000a34 ################

long zeros(long n) {
    int k = 1;
    int res = 0;
    
    while (pow(5, k) <= n) {
        res += floor(n / pow(5, k));
        k++;
    }
    return res;
}

// ################ Snail - https://www.codewars.com/kata/521c2db8ddc89b9b7a0000c1 ################

std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {
    std::vector<int> res;
    int top = 0, left = 0;
    int bottom = snail_map.size() - 1, right = snail_map.size() - 1;
    
    
    if (snail_map.empty() || snail_map[0].empty()) {
        return res;
    }
    
    if (top == bottom && left == right) {
        res.push_back(snail_map[top][left]);
        return res;
    }
    
    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; i++) {
            res.push_back(snail_map[top][i]);
        }
        top++;
        
        for (int i = top; i <= bottom; i++) {
            res.push_back(snail_map[i][right]);
        }
        right--;
        
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                res.push_back(snail_map[bottom][i]);
            }
            bottom--;
        }
        
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                res.push_back(snail_map[i][left]);
            }
            left++;
        }
    }
    
    return res;
}

// ################ Playing with digits - https://www.codewars.com/kata/5552101f47fc5178b1000050 ################

class DigPow
{
    public:
    static int digPow(int n, int p) {
        int sum = 0;
        
        std::string s = std::to_string(n);
        
        for (char c : s) {
            sum += pow(c - '0', p);
            p++;
        }
        if (sum % n != 0) return -1;
        return sum / n;
    }
};

// ################ Find The Parity Outlier - https://www.codewars.com/kata/5526fc09a1bbd946250002dc ################

int FindOutlier(std::vector<int> arr)
{ 
    int majorityEven = 0;
    
    for (int i = 0; i < 3; i++) {
        if (arr[i] % 2 == 0) majorityEven++;
    }
    
    bool isEven = majorityEven >= 2;
    for (int el : arr) {
        if ((el % 2 == 0) != isEven) {
            return el;
        }
    }
    return -1;
}

// ################ Two Sum - https://www.codewars.com/kata/52c31f8e6605bcc646000082 ################

std::pair<std::size_t, std::size_t> two_sum(const std::vector<int>& numbers, int target) {  
    std::unordered_map<int, int> map;
    for (std::size_t i = 0; i < numbers.size(); i++) {
        auto it = map.find(target - numbers[i]);
        if (it != map.end()) {
            return { it->second, i };
        } else {
            map.insert({ numbers[i], i });
        }
    }
    
    return {0, 0};
}

// ################ Does my number look big in this? = https://www.codewars.com/kata/5287e858c6b5a9678200083c ################

bool narcissistic(int value) {
    int sum = 0;
    int temp = value;
    
    int digits = 0;
    while (temp > 0) {
        temp /= 10;
        digits++;
    }
    
    temp = value;
    while (temp > 0) {
        int currDigit = temp % 10;
        sum += pow(currDigit, digits);
        temp /= 10;
    }
    
    return sum == value;
}

// ################ Simple Pig Latin - https://www.codewars.com/kata/520b9d2ad5c005041100000f ################

std::string pig_it(std::string str)
{
    std::stringstream ss(str);
    std::string word, res;
    
    while (ss >> word) {
        if (word.length() == 1 && !std::isalpha(word[0])) {
            res += word;
        }
        else {
            std::string modified_word = word.substr(1) + word[0] + "ay";
            res += modified_word;
        }
        
        if (ss.peek() != EOF) {
            res += " ";
        }
    }
    return res;
}

// ################ Build Tower - https://www.codewars.com/kata/576757b1df89ecf5bd00073b ################

std::vector<std::string> towerBuilder(unsigned nFloors) {
    int width = (2 * nFloors) - 1;
    std::vector<std::string> res;
    
    for (int i = 1; i <= nFloors; i++) {
        int stars = 2 * i - 1;
        int spaces = (width - stars) / 2;
        res.push_back(std::string(spaces, ' ') + std::string(stars, '*') + std::string(spaces, ' '));
    }
    
    return res;
}

// ################ Build a pile of Cubes - https://www.codewars.com/kata/5592e3bd57b64d00f3000047 ################

class ASum
{
    public:
    static long long findNb(long long m) {
        long long n = 1;
        long long sum = 0;
        
        while (sum < m) {
            sum += n * n * n;
            
            if (sum == m) return n;
            n++;
        }
        return -1;
    }
};

// ################ Delete occurrences of an element if it occurs more than n times - https://www.codewars.com/kata/554ca54ffa7d91b236000023 ################

std::vector<int> deleteNth(std::vector<int> arr, int n)
{
    std::vector<int> res;
    std::map<int, int> repeats = {};
    
    for (int el : arr) {
        if (!repeats[el]) {
            repeats.insert_or_assign(el, 1);
        }
        else if (repeats[el] == n) {
            continue;
        }
        else {
            repeats[el] += 1;
        }
        res.push_back(el);
    }
    return res;
}

// ################ Delete occurrences of an element if it occurs more than n times - https://www.codewars.com/kata/554ca54ffa7d91b236000023 ################

std::vector<int> deleteNth(std::vector<int> arr, int n)
{
    std::vector<int> res;
    std::map<int, int> repeats = {};
    
    for (int el : arr) {
        if (!repeats[el]) {
            repeats.insert_or_assign(el, 1);
        }
        else if (repeats[el] == n) {
            continue;
        }
        else {
            repeats[el] += 1;
        }
        res.push_back(el);
    }
    return res;
}

// ################ Valid Braces - https://www.codewars.com/kata/5277c8a221e209d3f6000b56 ################

bool valid_braces(const std::string &braces) 
{
    if (braces.size() < 2) return false;
    
    std::stack<char> bracesStack;
    std::unordered_map<char, char> matchingBraces = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };
    
    for (char c : braces) {
        if (!matchingBraces.count(c)) {
            bracesStack.push(c);
            continue;
        }
        
        if (bracesStack.empty() || bracesStack.top() != matchingBraces[c]) return false;
        bracesStack.pop();
    }
    return bracesStack.empty();
}

// ################ Shortest Word - https://www.codewars.com/kata/57cebe1dc6fdc20c57000ac9 ################

int find_short(std::string str)
{
    int len = 0;
    std::istringstream iss(str);
    std::string word;
    
    while (iss >> word) {
        if (len == 1) break;
        
        if (len == 0 || word.size() < len) {
            len = word.size();
        }
    }
    return len;
}

// ################ Unique In Order - https://www.codewars.com/kata/54e6533c92449cc251001667 ################

template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable){
    std::vector<T> res;
    for (T el : iterable) {
        if (res.empty() || res.back() != el) {
            res.push_back(el);
        }
    }
    return res;
}
std::vector<char> uniqueInOrder(const std::string& iterable){
    return uniqueInOrder(std::vector<char>(iterable.begin(), iterable.end()));
}

// ################ Sum of Digits / Digital Root - Sum of Digits / Digital Root ################
int sum_all_digits(int n)
{
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int digital_root(int n)
{
    n = sum_all_digits(n);
    if (n >= 10) return digital_root(n);
    return n;
}

// ################ Convert string to camel case - https://www.codewars.com/kata/517abf86da9663f1d2000003 ################

std::string to_camel_case(std::string text) {
    for (int i = 0; i < int(text.size()); i++) {
        if (text[i] != '_' && text[i] != '-') {
            continue;
        }
        text[i+1] = std::toupper(text[i+1]);
        text.erase(i, 1);
    }
    
    return text;
}

// ################ Turkish Numbers, 0-99 - https://www.codewars.com/kata/5ebd53ea50d0680031190b96 ################

std::string getTurkishNumber(unsigned int n) {
    std::vector<std::string> units = {"sıfır", "bir", "iki", "üç", "dört", "beş", "altı", "yedi", "sekiz", "dokuz"};
    std::vector<std::string> tens = {"", "on", "yirmi", "otuz", "kırk", "elli", "altmış", "yetmiş", "seksen", "doksan"};
    
    unsigned int ten_part = n / 10;
    unsigned int unit_part = n % 10;
    
    if (ten_part == 0) {
        return units[unit_part];
    } else if (unit_part == 0) {
        return tens[ten_part];
    } else {
        return tens[ten_part] + " " + units[unit_part];
    }
}
