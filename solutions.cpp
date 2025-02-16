#include <iostream>
#include <sstream>
#include <vector>
#include <cctype>
#include <cmath>
#include <string>
#include <stack>
#include <unordered_map>

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

// ################  ################