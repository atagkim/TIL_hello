#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct songunit {

    int songid;
    int songplays;
};

struct chartunit {
    
    bool check;
    int total;
    vector<songunit> songtable;
};

struct rankingunit {
    
    int total;
    string genresname;
};

bool rankingcmp(rankingunit a, rankingunit b) {
    if (a.total > b.total)
        return 1;
    else
        return 0;
}

bool songtablecmp(songunit a, songunit b) {

    if (a.songplays > b.songplays)
        return 1;
    else
        return 0;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, chartunit> chart;
    vector<rankingunit> ranking;
    
    string currentgenres;
    int currentnum;

    rankingunit inputranking;
    songunit inputsong;
 

    for (int i = 0; i < genres.size(); i++) {

        currentgenres = genres[i];
        currentnum = plays[i];

        chart[currentgenres].check = 0;
        chart[currentgenres].total += currentnum;

        inputsong.songid = i;
        inputsong.songplays = currentnum;

        chart[currentgenres].songtable.push_back(inputsong);
    }

    for (int i = 0; i < genres.size(); i++) {
                
        currentgenres = genres[i];

        if (chart[currentgenres].check == 0) {
            chart[currentgenres].check = 1;

            inputranking.genresname = currentgenres;
            inputranking.total = chart[currentgenres].total;

            ranking.push_back(inputranking);
        }
    }

    sort(ranking.begin(), ranking.end(), rankingcmp);

    for (int i = 0; i < ranking.size(); i++) {
        currentgenres = ranking[i].genresname;

        sort(chart[currentgenres].songtable.begin(), chart[currentgenres].songtable.end(), songtablecmp);

        for (int j = 0; j < chart[currentgenres].songtable.size(); j++) {

            answer.push_back(chart[currentgenres].songtable[j].songid);

            if (j == 1)
                break;
        }
        
    }

    return answer;
}

int main() {

    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };

    vector<int> answer = solution(genres, plays);

    for (int i = 0; i < answer.size(); i++) {
        printf("%d ", answer[i]);
    }

    return 0;
}