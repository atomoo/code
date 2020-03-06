// MyLeetCode.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    // 1103. 分糖果 II https://leetcode-cn.com/problems/distribute-candies-to-people/
    vector<int> distributeCandies(int candies, int num_people) {
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
    vector<vector<int>> findContinuousSequence(int target) {

    }
};

int main() {
    Solution sol;
    vector<int> result = sol.distributeCandies(11, 4);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ";";
    }
}
