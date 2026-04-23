#include <iostream>
#include <limits>

using namespace std;


class DrinkBuilder {
    private:
        string name;
        int sugarAmount;
        int temperature = 60;
        bool withMilk;

        static constexpr int maxSugar = 5;
        static constexpr int maxTemperature = 70;
        static constexpr int defaultSugar = 2;
        static constexpr int defaultTemperature = 50;

    public:
        DrinkBuilder& setName(const std::string& newName) {
            name = newName;
            return *this;
        }

        DrinkBuilder& setSugar(int amount) {
            if (amount > maxSugar || amount < 0) {
                cout << "\nThe amount of sugar you entered was invalid. The amount will default to: " << defaultSugar << endl;
                sugarAmount = defaultSugar;
            }
            else {
                sugarAmount = amount;
            }
            return *this;
        }

        DrinkBuilder& setTemperature(int newTemperature) {
            if (newTemperature > maxTemperature || newTemperature < 0) {
                cout << "\nThe temperature you entered was invalid. The amount will default to: " << defaultTemperature << endl;
                temperature = defaultTemperature;
            }
            else {
                temperature = newTemperature;
            }
            return *this;
        }

        DrinkBuilder& setWithMilk(bool milk) {
            withMilk = milk;
            return *this;
        }
        
        void print() const {
            cout << "\nThis is your drink: " << endl;
            cout << "Drink: " << name << endl;
            cout << "Sugar: " << sugarAmount << endl;
            cout << "Temperature: " << temperature << endl;
            cout << "With milk: " << boolalpha << withMilk << endl;
        }
};

int main() {

    string inputName = "";
    int inputSugar = 0;
    int inputTemperature = 0;
    bool inputMilk = false;

    DrinkBuilder builder;

    while (true) {
        while (true) {
            cout << "\nPlease enter the name of your Drink." << endl;
            cin >> inputName;
            if (cin.fail() || inputName.empty()) {
                cout << "You did not enter a valid name. Please try again" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                break;
            }
        }
        cout << "Please enter the amount of sugar you want in your drink. It has to be between 0 and 5!" << endl;
        cin >> inputSugar;
        if (cin.fail()) {
            cout << "\nYou did not enter a valid amount of sugar. Please restart with making your drink" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cout  << "Please enter the temperature you want your drink to be. It has to be between 0 and 70." << endl;
        cin >> inputTemperature;
        if (cin.fail()) {
            cout << "\nYou did not enter a valid temperature. Please restart with making your drink" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        cout << "Please enter if you want milk added to your drink. (1 or 0)" << endl;
        cin >> inputMilk;
        if (cin.fail()) {
            cout << "\nYou did not enter a valid statement. Please restart with making your drink" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        builder.setName(inputName)
            .setSugar(inputSugar)
            .setTemperature(inputTemperature)
            .setWithMilk(inputMilk)
            .print();
        cout << "\nPress Enter to make another drink..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }
}