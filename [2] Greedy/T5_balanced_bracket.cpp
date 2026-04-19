#include <bits/stdc++.h>
using namespace std;


/**
 * Leetcode: Valid Parentheses String
 * Given a string containing only three types of characters: '(', ')' and '*', check whether this string is a valid parentheses string. 
 * The '*' character can be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
 * 
 * Greedy approach:
 *     1. Use two stacks, one to keep track of the indices of open brackets and another to keep track of the indices of asterisks.
 *     2. Iterate through the string and for each character:
 *        - If it's an open bracket '(', push its index onto the open brackets stack. 
 *        - If it's a close bracket ')':
 *              - Try to match it with an open bracket from the open brackets stack. 
 *              - If the open brackets stack is empty, try to match it with an asterisk from the asterisks stack. 
 *              - If both stacks are empty, the string is invalid.
 *        - If it's an asterisk '*', push its index onto the asterisks stack.
 *    3. After processing all characters, if there are unmatched open brackets:
 *        - Try to match them with asterisks that can act as close brackets. 
 *        - If any open bracket cannot be matched with an asterisk that comes after it, the string is invalid.
 * Bonus: This can be solved with DP as well as two pointers approach. Try implementing those as well.
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
