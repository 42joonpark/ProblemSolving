/*
 * https://programmers.co.kr/learn/courses/30/lessons/12951
 */
#include <bits/stdc++.h>
using namespace std;

/*
string solution(string s) {
    string answer = "";
    string::iterator i, j;
    
    i = s.begin();
    j = s.begin();
    while (i != s.end()) {
        while (*i == ' ') ++i;
        answer += string(j, i);
        j = i;
        while (*j != ' ' && j != s.end()) ++j;
        string temp(i, j);
        
        if (isalpha(temp[0]))
            temp[0] = toupper(temp[0]);
        
        for (int k = 1; k < temp.size(); ++k)
            if (isalpha(temp[k]))
                temp[k] = tolower(temp[k]);
        
        i = j;
        answer += temp;
    }
    return answer;
}
*/

string solution(string s) {
    string answer = "";
    answer += toupper(s[0]);
    for (int i = 1; i < s.size(); ++i)
        answer += s[i - 1] == ' ' ? toupper(s[i]) : tolower(s[i]);
    
    return answer;
}
