#pragma once
#include <vector>
#include <algorithm>

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

// leetcode
class Solution {
public:

    vector<int> distributeCandies(int candies, int num_people);

    vector<vector<int>> findContinuousSequence(int target);

    int diameterOfBinaryTree(TreeNode* root) {};
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
int diameterOfBinaryTree(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int ans = 0;
    depth(root, ans);
    return ans;
}

