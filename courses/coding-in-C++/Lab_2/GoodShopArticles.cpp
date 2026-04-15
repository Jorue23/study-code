#include <iostream>
#include <string>

using namespace std;

class Article {

private:
    string name;     
    double price;
    int stock;
    string category;
    const int id;

public:

    Article(string name, double price, int stock, string category, int id)
        : name(name), price(price), stock(stock), id(id), category(category) {
            if (price < 0.0) {
                price = 0.0;
            }
            if (stock < 0) {
                stock = 0;
            }
        }

    void setPrice(double newPrice) {
        if(newPrice < 0) {
            cout << "Invalid price please input a positive number!" << endl;
        }
        else {
            price = newPrice;
        }
    }

    void sell(int amount) {
        if(amount < 0) {
            cout << "Invalid amount to sell! Please enter positive number!" << endl;
        }
        else if(stock < amount) {
            cout << "Not enough stock!" << endl;
        }
        else {
            stock -= amount;
        }
    }

    void restock(int amount) {
        if(amount < 0) {
            cout << "Invalid amount to restock! Please enter a positive number!" << endl;
        }
        else {
            stock += amount;
        }
    }

    void applyDiscount(double percent) {
        if(percent > 100) {
            cout << "Invalid discount percentage! Please enter a number equal to or less then 100!" << endl;
        }
        else {
            price = price - price * percent / 100;
        }

    }

    bool isAvailable() {
        return stock > 0;
    }

    const void printInfo() {
        cout << "Article: " << name << endl;
        cout << "Category: " << category << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
        cout << "ID: " << id << endl;
    }
    // Destructor and Copy Constructor missing for category but it'll be changed
};

int main() {
    Article myArticle1("Laptop", 999.99, 10, "Electronics", 101);
    myArticle1.sell(15);
    myArticle1.restock(-5);
    myArticle1.setPrice(-100);
    myArticle1.applyDiscount(150);

    if (myArticle1.isAvailable()) {
        cout << "Article available" << endl;
    }

    myArticle1.printInfo();

    Article myArticle2 = myArticle1;
    myArticle2.setPrice(200);
    myArticle2.printInfo();

}