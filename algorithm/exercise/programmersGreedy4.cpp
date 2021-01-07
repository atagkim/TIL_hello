#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool sortcmp(int a, int b) {
    if (a > b)
        return 1;
    else
        return 0;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    // init
    vector<int> person_by_weight;
    int current_person, remain;
    int boatcount = 0, currentboatnum;
    int personcount = 0, peoplesize = people.size();

    sort(people.begin(), people.end(), sortcmp);

    int max = people[0];
    for (int i = 0; i <= max; i++) {    
        person_by_weight.push_back(0);
    }

    for (int i = 0; i < people.size(); i++) {
        current_person = people[i];
        person_by_weight[current_person]++;
    }


    // boat count
    for (int i = 0; i < people.size(); i++) {
     
        current_person = people[i];     
        if (person_by_weight[current_person] <= 0)
            continue;
        
        person_by_weight[current_person]--;
        personcount++;
        remain = limit - current_person;

        for (int i = remain; i > 0; i--) {
            if (person_by_weight[i] > 0) {
                person_by_weight[i]--;
                personcount++;

                break;
            }
        }

        boatcount++;

        if (personcount >= peoplesize)
            break;
    }

  
    answer = boatcount;
    return answer;
}

int main() {

    vector<int> people = { 70,50,80,50 };
    int limit = 100;

    int answer = solution(people, limit);

    printf("answer = %d\n", answer);
}