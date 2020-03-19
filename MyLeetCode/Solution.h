#pragma once
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int depth(TreeNode* node, int& ans) {
    if (node == NULL) {
        return 0;
    }
    int leftDepth = depth(node->left, ans);
    int rightDepth = depth(node->right, ans);
    ans = max(ans, leftDepth + rightDepth);
    return max(leftDepth, rightDepth) + 1;
};

// 统计字符串中各个字符的个数
unordered_map<char, int> countOfCharactor(string S) {
    unordered_map<char, int> map;
    for (auto &&i : S)
    {
        map[i]++;
    }
    return map;
}

// leetcode
class Solution {
public:

    vector<int> distributeCandies(int candies, int num_people);

    vector<vector<int>> findContinuousSequence(int target);

    int diameterOfBinaryTree(TreeNode* root);
    
    bool canThreePartsEqualSum(vector<int>& A);

    string gcdOfStrings(string str1, string str2);
    
    string compressString(string S);

    int countCharacters(vector<string>& words, string chars);
    
    int longestPalindrome(string s);
};


// 1103. 分糖果 II https://leetcode-cn.com/problems/distribute-candies-to-people/
vector<int> Solution::distributeCandies(int candies, int num_people) {
    vector<int> result(num_people, 0);
    int current = 0;
    while (candies > 0) {
        int currentIndex = current % num_people;
        current++;
        int currentCandy = current > candies ? candies : current;
        result[currentIndex] += currentCandy;
        candies -= currentCandy;
    }
    return result;
}

// 面试题57 - II. 和为s的连续正数序列 https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/
vector<vector<int>> Solution::findContinuousSequence(int target) {
    vector<int> sequence;
    vector<vector<int>> result;
    int l = 1;
    int r = 2;
    while (l < r) {
        int sum = (l + r) * (r - l + 1) / 2;
        if (sum == target) {
            sequence.clear();
            for (int i = l; i <= r; i++) {
                sequence.push_back(i);
            }
            result.push_back(sequence);
            l++;
        }
        else if (sum < target) {
            r++;
        }
        else {
            l++;
        }
    }
    return result;
}

// 543. 二叉树的直径 https://leetcode-cn.com/problems/diameter-of-binary-tree/
int Solution::diameterOfBinaryTree(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int ans = 0;
    depth(root, ans);
    return ans;
}

// 1013. 将数组分成和相等的三个部分 https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum/
bool Solution::canThreePartsEqualSum(vector<int>& A) {
    int length = A.size();
    int sum = 0;
    for (auto &&i : A)
    {
        sum += i;
    }
    if (sum % 3 != 0) {
        return false;
    }
    int target = sum / 3;
    int index = 0;
    int cur = 0;
    while (index < length) {
        cur += A[index];
        if (cur == target) {
            break;
        }
        index++;
    }
    if (cur != target) {
        return false;
    }
    int j = length - 1;
    cur = 0;
    while (j > index + 1) {
        cur += A[j];
        if (cur == target) {
            return true;
        }
        j--;
    }
    return false;
}

// 1071. 字符串的最大公因子 https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/
string Solution::gcdOfStrings(string str1, string str2) {
    if (str1 + str2 != str2 + str1) {
        return "";
    }
    return str1.substr(0, gcd(str1.length(), str2.length()));
}

// 面试题 01.06. 字符串压缩 https://leetcode-cn.com/problems/compress-string-lcci/
string Solution::compressString(string S) {
    int len = S.length();
    if (len <= 0) {
        return S;
    }
    int count = 1;
    char current = S[0];
    string replaceResult = "";
    for (int i = 1; i < len; i++)
    {
        if (S[i] == current) {
            count++;
        }
        else {
            replaceResult += current + to_string(count);
            current = S[i];
            count = 1;
        }
    }
    replaceResult += current + to_string(count);
    if (replaceResult.length() < len) {
        return replaceResult;
    }
    return S;
}

// 1160. 拼写单词 https://leetcode-cn.com/problems/find-words-that-can-be-formed-by-characters/
int Solution::countCharacters(vector<string>& words, string chars) {
    int result = 0;
    auto charsMap = countOfCharactor(chars);
    for (auto &&word : words)
    {
        auto len = word.length();
        if (len <= chars.length()) {
            auto wordMap = countOfCharactor(word);
            bool valid = true;
            for (auto &&wCount : wordMap)
            {   
                if (charsMap[wCount.first] < wCount.second) {
                    valid = false;
                    break;
                };
            }
            if (valid) {
                cout << word << endl;
                result += len;
            }

        }
    }
    return result;
}

// 409. 最长回文串 https://leetcode-cn.com/problems/longest-palindrome/
int Solution::longestPalindrome(string s) {
    if (s.length() < 1) {
        return 0;
    }
    unordered_map map = countOfCharactor(s);
    int result = 0;
    for (auto &&item : map) {
        auto count = item.second;
        result += count / 2 * 2;
        if (count % 2 == 1 && result % 2 == 0) {
            result++;
        }
    }
    return result;
}

