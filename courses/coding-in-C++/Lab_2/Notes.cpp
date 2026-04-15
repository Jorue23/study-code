#include <iostream>

using namespace std;

class Note {
    private:
        string* text;
    public:
        Note(string new_text) {
            text = new string;
            *text = new_text;
        }
        Note(Note &otherNode) {
            text = new string;
            *text = *otherNode.text;
        }
        ~Note() {
            delete text;
            text = nullptr;
            cout << "Memory freed!" << endl;
        }
        void display();
};

void Note::display() {
    cout << *text << endl;
}

int main() {
    Note myNote1("1+1=3!");
    Note myNote2(myNote1);

    myNote1.display();
    myNote2.display();

    return 0;

}

