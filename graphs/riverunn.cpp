#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Castle{
public:
    int distance_between{};
    bool is_visited{};
    vector <int> connections;

    void BFS( int s, Castle castleArray[]);
};

void Castle::BFS( int s, Castle castleArray[]) {
    queue<long int> castleQueue;
    castleQueue.push(s);
    castleArray[s].is_visited = true;
    castleArray[s].distance_between = 0;
    while (!castleQueue.empty()) {
        int current = castleQueue.front();
        castleQueue.pop();

        for (int i = 0; i < castleArray[current].connections.size(); i++) {
            if (!castleArray[castleArray[current].connections[i]].is_visited) {
                castleArray[castleArray[current].connections[i]].is_visited = true;
                castleArray[castleArray[current].connections[i]].distance_between = castleArray[current].distance_between + 1;
                castleQueue.push(castleArray[current].connections[i]);
            }

        }
    }
}



int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);


    int n, m, s, d;
    cin >> n >> m >> s >> d;
    Castle *castleArray = new Castle[n + 1];
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        castleArray[a].connections.push_back(b);
        castleArray[b].connections.push_back(a);
    }



    castleArray[s].BFS(s, castleArray);
    int longestTimeThatBirdsWereFlying = 0;
    for(int i = 0; i < n; i++){
        if(castleArray[i].distance_between > longestTimeThatBirdsWereFlying){
            longestTimeThatBirdsWereFlying = castleArray[i].distance_between;
        }
    }

    int castleCounter = 0;
    for (int i = 0; i < n; i++) {
        if(castleArray[i].distance_between*2 <= d && castleArray[i].distance_between > 0){
            castleCounter++;
        }
    }
    cout << longestTimeThatBirdsWereFlying << " " << castleCounter;
    delete []castleArray;
    return 0;

}
