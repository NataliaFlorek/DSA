#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Monkey {
    char letter;
    int holders;
    vector<Monkey*> children;
};

void add_monkey(queue<Monkey*>& monkeyQueue, Monkey* monkey) {
    if (monkeyQueue.empty()) {
        monkeyQueue.push(monkey);
    } else {
        if (!monkeyQueue.empty() && monkeyQueue.front()->holders > 0) {
            monkeyQueue.front()->children.push_back(monkey);
            monkeyQueue.push(monkey);
            monkeyQueue.front()->holders--;
        } else {
            monkeyQueue.pop();
            if (!monkeyQueue.empty()) {
                monkeyQueue.front()->children.push_back(monkey);
                monkeyQueue.push(monkey);
                monkeyQueue.front()->holders--;
            }
        }
    }
}

void showMonkeys(Monkey* monkey) {
    if (monkey != nullptr) {
        cout << monkey->letter;
        for (Monkey* alternativeMonkey : monkey->children)
            showMonkeys(alternativeMonkey);
    }
    else
        return;
}

int main() {
    unsigned int K;
    cin >> K;
    if (K > 0) {
        Monkey* root = nullptr;
        for (int i = 0; i < K; i++) {
            queue<Monkey*> monkeyQueue;
            unsigned int N;
            cin >> N;
            if (N > 0) {
                for (int j = 0; j < N; j++) {
                    char letter;
                    int holders;
                    cin >> letter >> holders;
                    Monkey* monkey = new Monkey();
                    monkey->letter = letter;
                    monkey->holders = holders;
                    if (j == 0) {
                        root = monkey;
                    }
                    add_monkey(monkeyQueue, monkey);
                }
                showMonkeys(root);
                cout << endl;
            }
        }
    }
    return 0;
}
