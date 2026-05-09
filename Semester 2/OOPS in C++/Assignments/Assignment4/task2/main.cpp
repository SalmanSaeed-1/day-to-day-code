#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

class Item {
protected:
    string name;
    string itemType;
    double basicPrice;
    int units;
    bool onSale;
    bool giftCard;

public:
    Item(string n = "", string type = "", double price = 0, int u = 1, bool sale = false, bool gift = false)
        : name(n), itemType(type), basicPrice(price), units(u), onSale(sale), giftCard(gift) {}

    virtual ~Item() {}

    void setName(string n) { name = n; }
    void setItemType(string t) { itemType = t; }
    void setBasicPrice(double p) { basicPrice = p; }

    string getName() const { return name; }
    string getItemType() const { return itemType; }
    double getBasicPrice() const { return basicPrice; }
    int getUnits() const { return units; }
    bool isOnSale() const { return onSale; }

    virtual Item* clone() const {
        return new Item(*this);
    }

    virtual double price() const {
        double unitPrice = onSale ? basicPrice * 0.75 : basicPrice;
        return unitPrice * units;
    }

    bool gift() const {
        return giftCard;
    }

    bool sameType(const Item& other) const {
        return itemType == other.itemType;
    }

    bool operator==(const Item& other) const {
        return name == other.name &&
               basicPrice == other.basicPrice &&
               itemType == other.itemType &&
               onSale == other.onSale;
    }

    friend ostream& operator<<(ostream& out, const Item& item) {
        out << item.name << " "
            << fixed << setprecision(2) << item.basicPrice << " "
            << item.units << " "
            << (item.onSale ? "Yes" : "No") << " "
            << (item.giftCard ? "Yes" : "No")
            << ", Price: " << fixed << setprecision(2) << item.price() << " Rs.";
        return out;
    }
};

class Egg : public Item {
public:
    Egg(double price, int u = 1, bool sale = false, bool gift = false)
        : Item("Egg", "Food", price, u, sale, gift) {}

    Item* clone() const override {
        return new Egg(*this);
    }
};

class Bread : public Item {
public:
    Bread(double price, int u = 1, bool sale = false, bool gift = false)
        : Item("Bread", "Food", price, u, sale, gift) {}

    Item* clone() const override {
        return new Bread(*this);
    }
};

class Pens : public Item {
public:
    Pens(double price, int u = 1, bool sale = false, bool gift = false)
        : Item("Pens", "Supplies", price, u, sale, gift) {}

    Item* clone() const override {
        return new Pens(*this);
    }
};

class Socks : public Item {
public:
    Socks(double price, int u = 1, bool sale = false, bool gift = false)
        : Item("Socks", "Clothes", price, u, sale, gift) {}

    Item* clone() const override {
        return new Socks(*this);
    }
};

class Cart {
private:
    Item** items;
    int count;

    void copyFrom(const Cart& other) {
        count = other.count;
        items = new Item*[count];
        for (int i = 0; i < count; i++)
            items[i] = other.items[i]->clone();
    }

    void clear() {
        for (int i = 0; i < count; i++)
            delete items[i];
        delete[] items;
        items = nullptr;
        count = 0;
    }

public:
    Cart() : items(nullptr), count(0) {}

    Cart(const Cart& other) {
        copyFrom(other);
    }

    ~Cart() {
        clear();
    }

    Cart& operator=(const Cart& other) {
        if (this != &other) {
            clear();
            copyFrom(other);
        }
        return *this;
    }

    bool Discount() const {
        int saleCount = 0;
        for (int i = 0; i < count; i++) {
            if (items[i]->isOnSale())
                saleCount++;
        }
        return saleCount >= 3;
    }

    double price() const {
        double total = 0;
        for (int i = 0; i < count; i++)
            total += items[i]->price();

        if (Discount())
            total *= 0.875; // 12.5% discount on full cart

        return total;
    }

    operator string() const {
        if (count == 0)
            return "Still no item in the cart\n";

        stringstream ss;
        for (int i = 0; i < count; i++)
            ss << *items[i] << "\n";
        ss << "Total Price: " << fixed << setprecision(2) << price() << " Rs.\n";
        return ss.str();
    }

    Cart& operator+=(const Item& item) {
        Item** temp = new Item*[count + 1];

        for (int i = 0; i < count; i++)
            temp[i] = items[i];

        temp[count] = item.clone();
        delete[] items;
        items = temp;
        count++;

        return *this;
    }

    Cart& operator-=(const Item& item) {
        int newCount = 0;

        for (int i = 0; i < count; i++) {
            if (!items[i]->sameType(item))
                newCount++;
        }

        Item** temp = new Item*[newCount];
        int index = 0;

        for (int i = 0; i < count; i++) {
            if (!items[i]->sameType(item)) {
                temp[index++] = items[i];
            } else {
                delete items[i]; // removing every item of that item type
            }
        }

        delete[] items;
        items = temp;
        count = newCount;

        return *this;
    }

    Cart operator+(const Item& item) const {
        Cart result(*this);
        result += item;
        return result;
    }

    Cart operator-(const Item& item) const {
        Cart result(*this);
        result -= item;
        return result;
    }

    friend ostream& operator<<(ostream& out, const Cart& cart) {
        if (cart.count == 0) {
            out << "Still no item in the cart\n";
        } else {
            out << "Cart Contains\n";
            for (int i = 0; i < cart.count; i++)
                out << *cart.items[i] << "\n";

            out << "Cart is Discounted: " << (cart.Discount() ? "Yes" : "No") << "\n";
            out << "Total Price: " << fixed << setprecision(2) << cart.price() << " Rs.\n";
        }
        return out;
    }
};

int main() {
    // example of non-sale item
    Bread p1(12, 3);
    cout << p1 << endl;

    // example of sale item
    Egg p2(15, 1, true);

    // example of sale item with gift card
    Socks p3(20, 2, true, true);

    Cart c1;
    c1 += p1; // add bread to cart
    c1 += p1;
    c1 += p2; // add eggs to cart
    c1 += p3; // add socks to cart
    cout << c1 << endl;

    c1 = c1 - p1; // delete all the units of type bread
    cout << c1 << endl;

    Cart c2;
    c2 = c1 + p2; // add item of type eggs
    cout << c2 << endl;

    // delete all the units of item type food from the cart
    c2 -= p2;
    cout << c2;

    return 0;
}
