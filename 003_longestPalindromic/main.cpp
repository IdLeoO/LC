#include "main.hpp"
#include <iostream>
#include <map>
using namespace std;
// Normal solution
string Solution::longestPalindorme(string s){
    string result = "";
    for (int i = 0; i < s.size(); i++){
        // Even length palindorme 
        int rEven = 0;
        while (i + rEven < s.size() && i - rEven - 1 >= 0){
            char rightEven = s[i + rEven];
            char leftEven = s[i - rEven - 1];
            if (rightEven == leftEven){
                if (2 * rEven + 2 > result.length()){
                    result = s.substr(i - rEven - 1, 2 * rEven + 2);
                }
            }
            else{
                break;
            }
            rEven ++;
        }
        // Odd length palinorme
        int rodd = 0;
        while (i + rodd < s.size() && i - rodd >= 0){
            char rightOdd = s[i + rodd];
            char leftOdd = s[i-rodd];
            if (rightOdd == leftOdd){
                if (2 * rodd + 1 > result.length()){
                    result = s.substr(i - rodd, 2 * rodd + 1);
                }
            }
            else{
                break;
            }
            rodd ++;
        }
    }
    return result;
}

/* Manachar Algo
要在线性时间内找出字符串的最长回文子串，这个算法必须利用回文字符串和子回文字符串中观察
到的一些特点。

首先我们观察一下回文字符串可知，回文字符串都是对称的。而且如果一个长回文字符串的对称点
左面包含一个小的回文字符串，那么对称过去到右面也必然会包含一个小的回文字符串，比如
“dacabacad”这个字符串中，对称点b左面有一个回文字符串“aca”，右面也会对称出一个回文字
符串“aca”。

回文字符串边界的情况讨论
那么我们观察对称点左面出现的这个小回文字符串，这个字符串有三种情况：

情况1
如果左侧小回文字符串的左边界在大回文字符串的左边界之内，那么右面对称出的小回文字符串
也不会触碰到大回文字符串的右边界。

比如“dacaxacad”这个字符串，左侧的“aca”没有超过这个大回文字符串的左边界，那么右面
对称出的“aca”也不会超过右边界。

也就是说，在这种情况下，右面这个小回文字符串的长度与对称的小回文字符串的长度相等，绝
对不会超过这个大回文字符串。

情况2
如果左侧小回文字符串的左边界超过了大回文字符串的左边界，那这个右面对称出的小回文字符
串会正好触碰到大回文字符串的右边界，但是不会超出。

比如观察这个字符串“dcbabcdxdcbabce”。左侧的小回文字符串的边界超出了用下划线标出的
大回文字符串的左边界。对称过来的右侧的小回文字符串的边界会刚好卡在大回文字符串的右边
界。这是由于大回文字符串右边界之外的下一个字母（此处是“e”）绝对不是左边界的那个字母
“d”的对称，所以右边的小回文字符串延申到边界之后也无法继续延申下去了。

也就是说，在这种情况下，右面这个小回文字符串的右边界与大回文字符串的右边界相同，那么
这个小回文字符串的长度也绝对不会超过这个大回文字符串。

情况3
如果左侧小回文字符串的左边界正好卡在大回文字符串的左边界上，那么右面对称出的小回文字
符串有可能会继续延伸下去，超过大回文字符串的右边界。

比如观察这个字符串“abcdcbabcdxdcbabcdxdcb"，左边的小回文字符串的左边界正好卡在
大回文字符串的左边界上，那么对称过来的大回文字符串是有可能继续延申下去的。比如在这个
例子中，右面以“a”为对称点的小回文字符串一直能向右延申到整个字符串的结尾。

也就是说，在这种情况下，右面这个小回文字符串的右边界至少与大回文字符串的有边界相同，并
且有可能会延申。也就是说这个小回文字符串的长度可能会超过这个大回文字符串。

总结
我们考虑了左边的小回文字符串的边界与大回文字符串边界的三种情况，只有情况3，也就是正
好边界在同一位置的时候，右侧的小回文字符串的长度才有可能会超过大回文字符串，而其他两
种情况的话，我们可以跳过不去计算。

所以Manacher算法在先找到一个长回文字符串之后，可以选择性的跳过很多字母，无需一一
计算，与暴力循环相比极大了提升了算法的效率。


*/
int main(int argc, char* argv[]){
    string s = "aacabdkacaa";
    Solution sol;
    cout << sol.longestPalindorme(s) << endl;
}