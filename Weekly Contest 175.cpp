// 5332.Check If N and Its Double Exist
/*Given an array arr of integers, check if there exists two integers N and M such that N is the double of M ( i.e. N = 2 * M).

More formally check if there exists two indices i and j such that :

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]
 

Example 1:

Input: arr = [10,2,5,3]
Output: true
Explanation: N = 10 is the double of M = 5,that is, 10 = 2 * 5.
Example 2:

Input: arr = [7,1,14,11]
Output: true
Explanation: N = 14 is the double of M = 7,that is, 14 = 2 * 7.
Example 3:

Input: arr = [3,1,7,11]
Output: false
Explanation: In this case does not exist N and M, such that N = 2 * M.*/

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map <int,int> m;
        for(int i = 0; i < arr.size(); i++){
            m[arr[i]]++;
        }
        if(m[0] >= 2) return true;
        for(int j =0; j < arr.size(); j++){
            if(arr[j] != 0 && m.count(arr[j]*2) > 0) return true;
        }
        return false;
    }
};

//5333. Minimum Number of Steps to Make Two Strings Anagram
/*Given two equal-size strings s and t. In one step you can choose any character of t and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains the same characters with a different (or the same) ordering.

 

Example 1:

Input: s = "bab", t = "aba"
Output: 1
Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.
Example 2:

Input: s = "leetcode", t = "practice"
Output: 5
Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.
Example 3:

Input: s = "anagram", t = "mangaar"
Output: 0
Explanation: "anagram" and "mangaar" are anagrams. 
Example 4:

Input: s = "xxyyzz", t = "xxyyzz"
Output: 0
Example 5:

Input: s = "friend", t = "family"
Output: 4*/

class Solution {
public:
    int minSteps(string s, string t) {
        map <char, pair<int,int>> m1;
        int count = 0;
        if(s.size() == 0) return 0;
        for(int i = 0; i< s.size();i++){
            if(m1.count(s[i]) > 0){
                m1[s[i]].first++;
            }else{
                m1[s[i]] = make_pair(1,0);
            }
        }
        for(int j = 0; j < t.size(); j++){
            if(m1.count(t[j]) > 0){
                m1[t[j]].second++;
            }else{
                m1[t[j]] = make_pair(0,1);
            }
        }
        for(auto m : m1){
            if(m.second.first >= m.second.second){
                count += m.second.first - m.second.second;
            }
        }
        return count;
    }
};

