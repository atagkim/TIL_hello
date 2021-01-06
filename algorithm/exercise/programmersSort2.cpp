#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// a가 작으면 -1, b가 작으면 1, 같으면 0 리턴
int specialcmp(int a, int b) {

    string aa = to_string(a);
    string bb = to_string(b);

    string longer, shorter, converted, temp;
    int shorterid, longerid, whoislonger, maxlength, tempid;

    int checkvalue = strcmp(aa.c_str(), bb.c_str());

    if (aa.length() == bb.length()) {
        if (checkvalue > 0)
            return 1;
        else if (checkvalue < 0)
            return -1;
        else
            return 0;
    }

    else {

        if (aa.length() > bb.length()) {
            longer = aa;
            shorter = bb;
            longerid = 1;
            shorterid = 2;
        }
        else {
            longer = bb;
            shorter = aa;
            longerid = 2;
            shorterid = 1;
        }

        maxlength = longer.length();

        int idx = 1;
        while (1) {

            if (shorter.length() == 0) {
                return 0;
            }

            converted = longer.substr(0, shorter.length());

            whoislonger = strcmp(shorter.c_str(), converted.c_str());

            if (whoislonger < 0) {
                if (shorterid == 1)
                    return -1;
                else
                    return 1;

            }
            else if (whoislonger > 0) {
                if (longerid == 1)
                    return -1;
                else
                    return 1;
            }
            else {

                longer = longer.substr(shorter.length(), maxlength);

                if (longer.length() < shorter.length()) {

                    tempid = shorterid;
                    shorterid = longerid;
                    longerid = tempid;

                    temp = shorter;
                    shorter = longer;
                    longer = temp;

                }

            }

        }
    }

    // 여기 올 일 없음
    return -100;

}

bool numberscmp(int a, int b) {

    int checkvalue = specialcmp(a, b);

    if (checkvalue == 1)
        return 1;
    else
        return 0;
}


string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), numberscmp);

    if (numbers[0] == 0)
        answer = '0';

    else {
        for (int i = 0; i < numbers.size(); i++) {
            answer += to_string(numbers[i]);
        }
    }
    

    return answer;
}


int main() {

    vector<int> numbers = {222,22};

    string answer = solution(numbers);

    printf("%s", answer.c_str());

    return 0;
}