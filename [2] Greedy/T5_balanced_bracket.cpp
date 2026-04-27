#include <bits/stdc++.h>
using namespace std;


/**
 * Valid Parentheses String (Leetcode 678):
 * Given a string of '(', ')', and '*', determine if it is a valid parenthesis sequence.
 * '*' is a wildcard — it may be treated as '(', ')', or an empty string. A sequence is
 * valid if every '(' has a matching ')' in correct nesting order.
 *
 * Alternatives: Two-pointer range tracking in O(n) O(1) space — maintain [lo, hi] as the
 *               range of possible open-bracket counts; valid iff lo == 0 at the end and hi
 *               never goes negative. DP with state (index, open_count) in O(n²) time and
 *               space — correct but wasteful. Recursive memoization — equivalent to DP.
 * 
 * Variations:
 *     1. Multiple wildcard types — '*' can also represent any bracket pair (extend wildcard
 *        stack logic; two-pointer range approach generalizes cleanly)
 *     2. Minimum insertions to make string valid (greedy count of unmatched opens and
 *        closes after a single left-to-right pass)
 *     3. Minimum number of bracket reversals to make string valid (convert to reduced
 *        sequence, count mismatched pairs; O(n) greedy)
 *     4. Longest valid parenthesis substring (DP or stack tracking last invalid index)
 *     5. k distinct wildcard characters each with different substitution rules (model as
 *        range DP; greedy no longer sufficient)
 */

bool checkValidString(string s) {
    stack<int> open_brackets;
    stack<int> asterisks;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            open_brackets.push(i);

        else if (s[i] == ')') {
            // Try to match with an open bracket first
            if (!open_brackets.empty())
                open_brackets.pop();

            // If no open bracket is available, try to match with an asterisk which can act as an open bracket
            else if (!asterisks.empty())
                asterisks.pop();

            // If neither is available, the string is invalid
            else
                return false;
        }

        else
            asterisks.push(i);
    }

    // If there are unmatched open brackets, try to match them with asterisks that can act as close brackets
    while(!open_brackets.empty())
    {
        // Get the index of the current open bracket, which is the last unmatched open bracket in the stack
        int curr_open_at = open_brackets.top();
        open_brackets.pop();

        // Get the index of the nearest asterisk that can act as a close bracket for the current open bracket
        int nearest_star_at = -1;
        if (!asterisks.empty()) {
            nearest_star_at = asterisks.top();
            asterisks.pop();
        }

        // If the nearest asterisk is before the current open bracket, the string is invalid
        if (nearest_star_at < curr_open_at)
            return false;
    }
    return true;
}
