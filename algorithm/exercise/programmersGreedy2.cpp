#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string object;
int objectlen;
int final_count = 987654321;

int absol(int input) {
    if (input < 0)
        return -1 * input;
    else
        return input;
}

void dfs(string current, int idx, int convertcount, int movecount) {

    int left, right;

    // 전체 체크
    if (current == object || movecount >= objectlen) {
        if(current == object)        
            if(final_count > movecount + convertcount)
                final_count = movecount + convertcount;

        return;
    }

    // 현재 idx 체크
    if (current[idx] == object[idx]) {
        // none
    }
    else {
        left = object[idx] - current[idx];
        left = absol(left);

        right = 26 - left;

        if (left < right) {
            convertcount += left;
        }
        else {
            convertcount += right;
        }

        current[idx] = object[idx];
    }

    // 전체 체크2
    if (current == object) {
        if (final_count > convertcount + movecount)
            final_count = convertcount + movecount;
        
        return;
    }
    
    if (idx - 1 < 0)
        dfs(current, objectlen - 1, convertcount, movecount + 1);
    else
       dfs(current, idx - 1, convertcount, movecount + 1);
    
    if (idx + 1 >= objectlen)
        dfs(current, 0, convertcount, movecount + 1);
    else
        dfs(current, idx + 1, convertcount, movecount + 1);


    return;
}

int solution(string name) {
    int answer = 0;
    
    // init
    string start;
    for (int i = 0; i < name.length(); i++) {
        start += "A";
    }

    object = name;
    objectlen = name.length();

    dfs(start, 0, 0, 0);
    
    answer = final_count;
    return answer;
}


int main() {

    string name = "JEROEN";

    int answer = solution(name);

    printf("answer = %d\n", answer);

}


