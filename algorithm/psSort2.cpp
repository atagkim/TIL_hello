#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(int a, int b) {

    string tempa = to_string(a);
    string tempb = to_string(b);

    char chara[8];
    char charb[8];

    strcpy(chara, tempa.c_str());
    strcpy(charb, tempb.c_str());

    int idxa = 0, idxb = 0;
    int lena = strlen(chara), lenb = strlen(charb);
    while (idxa < lena && idxb < lenb) {

        char currenta = chara[idxa];
        char currentb = charb[idxb];

        if (currenta < currentb) {
            return 0;
        }
        else if (currentb < currenta) {
            return 1;
        }
        else {
            idxa++;
            idxb++;
        }
    }
    if (idxa < lena) {
        while (idxa < lena) {
            if (chara[idxa] > chara[0]) {
                return 1;
            }
            else if (chara[idxa] < chara[0]) {
                return 0;
            }
            else {
                idxa++;
            }
        }
    }
    else if (idxb < lenb) {
        while (idxb < lenb) {
            if (charb[idxb] > charb[0]) {
                return 0;
            }
            else if (charb[idxb] < charb[0]) {
                return 1;
            }
            else {
                idxb++;
            }
        }
    }
    return 1;
}

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), cmp);

    for (int i = 0; i < numbers.size(); i++) {
        string currentans = to_string(numbers[i]);
        answer += currentans;
    }

    return answer;
}