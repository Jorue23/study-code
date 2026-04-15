#include <iostream>
#include <string>
#include <iomanip>      //wird nicht verwendet

using namespace std;

class Article {

// Alles ist public, alles außer den funktionen sollte private sein

public:
    string name;     
    double price;
    int stock;
    string* category;   //Warum category dynamisch?
    int id;             // muss const sein

    Article(string name, double price, int stock, string category, int id) {
        name = name;    
        price = price;
        stock = stock;      // bei den zuweisungen kann es je nach compiler zu Problemen kommen welches name oder price zB gemeint ist. Entweder Namen ändern oder name(name) zB benutzen.
        this->id = id;      
        this->category = new string;    // macht keinen Sinn mit new zu erzeugen
        *this->category = category;
    }

    void setPrice(double price) {   //keine checks ob mehr als 0
        price = price;
    }

    void sell(int amount) {
        stock = stock - amount;     //keine checks ob das überhaupt valid ist
    }

    void restock(int amount) {
        this->stock += amount;      //keine checks ob das valid ist 
    }

    double applyDiscount(double percent) {
        price = price - price * percent / 100;  //warum ist das nen double und kein void? so wie alle anderen
        return price;
    }

    double getPrice() {     //wird nicht verwendet
        return price;
    }

    bool isAvailable() {
        if (stock > 0)
            return true;    //Klammern fehlen
        else
            return false;   //ebenso
    }

    void printInfo() {
        cout << "Article: " << name << endl;
        cout << "Category: " << *category << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
        cout << "ID: " << id << endl;
    }
};

int main() {
    Article a("Laptop", 999.99, 10, "Electronics", 101);    // schlechter name

    a.sell(15);
    a.restock(-5);
    a.price = -100;     // setPrice sollte verwendet werden
    a.applyDiscount(150);

    if (a.isAvailable()) cout << "Article available" << endl;   //das funktioniert nicht weil in isAvailable die klammern fehlen außerdem sollten hier auch klammern und eine neue Zeile verwendet werden.

    a.printInfo();
}