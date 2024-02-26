#include <iostream>
#include <string>
using namespace  std;

struct Actor{
    string name;
    unsigned long f;
};

class List{
private:
    struct Node{
        Actor *actor;
        Node *next = nullptr;
    };
    Node* head = nullptr;
public:

    bool actor_exists(string name, unsigned long  number) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->actor->name == name && temp->actor->f == number) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void add_actor(string name, unsigned long  number){
        if (actor_exists(name, number)) {
            cout <<  "NIE" << "\n";
        }else {
            Node *node = new Node();
            node->actor = new Actor();
            node->next = nullptr;
            node->actor->name = name;
            node->actor->f = number;

            if (head == nullptr) {
                head = node;
            } else {
                Node *temp = head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = node;
            }
            cout << "TAK" << "\n";
        }
    }

    void remove_actor(string name, unsigned long f) {
        if (actor_exists(name, f)) {
            if (head != nullptr && head->actor->f == f && head->actor->name == name) {
                Node *temp = head;
                head = head->next;
                delete temp->actor;
                delete temp;
                return;
            }

            Node *current = head;
            while (current->next != nullptr &&
                   (current->next->actor->f != f || current->next->actor->name != name)) {
                current = current->next;
            }

            if (current->next != nullptr) {
                Node *temp = current->next;
                current->next = current->next->next;
                delete temp->actor;
                delete temp;
            }
        }
    }

    void find_actor(unsigned long  p) {
        Node* foundActor = new Node();
        foundActor->actor = new Actor();
        foundActor->actor->f = 0;
        Node* temp = head;
        while (temp != nullptr) {
            if ((temp->actor->f > foundActor->actor->f && temp->actor->f <= p) || ( temp->actor->f <= p && temp->actor->f == foundActor->actor->f && temp->actor->name < foundActor->actor->name)) {
                foundActor = temp;
            }
            temp = temp->next;

        }

        if (foundActor->actor->f > 0) {
            cout << foundActor->actor->name << "\n";
            remove_actor(foundActor->actor->name,foundActor->actor->f);
        } else {
            cout << "NIE" << "\n";
        }
    }


};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    List list;
    unsigned long  n;
    cin >> n;
    for(int i = 0 ; i < n; i++){
        unsigned long  op;
        cin >> op;
        if( op == 1){
            string name;
            unsigned long  f;
            getline(cin, name);
            getline(cin, name );
            cin >> f;
            list.add_actor(name, f);
        }
        else if(op == 2){
            unsigned long  p;
            cin >> p;
            list.find_actor(p);
        }
    }

    return 0;
}
