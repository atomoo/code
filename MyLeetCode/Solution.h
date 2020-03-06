#pragma once
#include <vector>

using namespace std;

// leetcode
class Solution {
public:

    vector<int> distributeCandies(int candies, int num_people);

    vector<vector<int>> findContinuousSequence(int target);
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

