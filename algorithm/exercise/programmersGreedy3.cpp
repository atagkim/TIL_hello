#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    
    char current, next;
    int length = number.length() - k;
    int count;

    for (int i = 0; i < number.size(); i++) {
       
        current = number[i];
        count = 1;

        if (k <= 0) {
            answer += current;
            continue;
        }

        if (i != number.size() - 1) {
           
            for (int j = i + 1; j < number.size(); j++) {

                if (count > k) {
                    answer += current;

                    break;
                }


                // count Ã¤¿ì±â
                next = number[j];

                if (next > current) {
                    i = j - 1;
                    k -= count;

                    break;
                }
                else {
                    // keep
                    count++;

                    if (j == number.size() - 1)
                        answer += current;
                }
            }

        }
        else {
            answer += current;
        }

    }

    if (k > 0) {
        answer = answer.substr(0, answer.length() - k);
    }

    return answer;
}

int main() {

    string number = "1231234";
    int k = 3;

    string answer = solution(number, k);

    printf("answer = %s\n", answer.c_str());
}