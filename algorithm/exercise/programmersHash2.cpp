#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;

    unordered_map<string, bool> prefixtable;
    int wordlength, booksize = phone_book.size();
    string current;

    for (int i = 0; i < booksize; i++) {
        prefixtable[phone_book[i]] = 1;
    }

    for (int i = 0; i < booksize; i++) {
        wordlength = phone_book[i].length();
        current.clear();

        for (int j = 0; j < wordlength - 1; j++) {
                
            current += phone_book[i][j];

            if (prefixtable[current] == 1)
                return 0;
        }
    }

    return 1;
}


int main() {

    vector<string> phone_book = { "119","97674223","1195524421" };

    bool answer = solution(phone_book);

    if (answer)
        printf("true");
    else
        printf("false");
	
}