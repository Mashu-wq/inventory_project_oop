#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Abstract base class representing a product
class Product {
protected:
    string name;
    int quantity;

public:
    // Virtual destructor for cleanup
    virtual ~Product() {}

    // Pure virtual function to display product details
    virtual void displayDetails() const = 0;

    // Pure virtual function to get the type of product
    virtual string getType() const = 0;

    // Getter and setter for product name
    string getName() const {
        return name;
    }

    void setName(const string& n) {
        name = n;
    }

    // Getter and setter for product quantity
    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int q) {
        quantity = q;
    }
};

// Class representing a product with price
class ProductWithPrice : public Product {
private:
    double price;

public:
    // Default constructor
    ProductWithPrice() {

        price = 0;
    }

    // Parameterized constructor
    ProductWithPrice(const string& n, int q, double p) {
        name = n;
        quantity = q;
        price = p;
    }

    // Getter and setter for product price
    double getPrice() const {
        return price;
    }

    void setPrice(double p) {
        price = p;
    }

    // Implementation of the displayDetails function
    void displayDetails() const override {
        cout << "Type: " << getType() << endl;
        cout << "Name: " << name << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Price: $" << price << endl;
    }

    // Implementation of the getType function
    string getType() const override {
        return "Product with Price";
    }
};

// Class representing a product with weight
class ProductWithWeight : public Product {
private:
    double weight;

public:
    // Default constructor
    ProductWithWeight() {
        weight = 0;
    }

    // Parameterized constructor
    ProductWithWeight(const string& n, int q, double w) {
        name = n;
        quantity = q;
        weight = w;
    }

    // Getter and setter for product weight
    double getWeight() const {
        return weight;
    }

    void setWeight(double w) {
        weight = w;
    }

    // Implementation of the displayDetails function
    void displayDetails() const override {
        cout << "Type: " << getType() << endl;
        cout << "Name: " << name << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Weight: " << weight << " kg" << endl;
    }

    // Implementation of the getType function
    string getType() const override {
        return "Product with Weight";
    }
};

// Class representing the inventory
class Inventory {
private:
    vector<Product*> products;

public:
    // Destructor to free memory
    ~Inventory() {
        for (const auto& product : products) {
            delete product;
        }
        products.clear();
    }

    // Function to add a product to the inventory
    void addProduct(Product* product) {
        products.push_back(product);
    }

    // Function to display the inventory
    void displayInventory() const {
        for (const auto& product : products) {
            product->displayDetails();
            cout << endl;
        }
    }

    // Function to save the inventory to a file
    void saveToFile(const string& filename) const {
        ofstream outputFile(filename);
        if (outputFile.is_open()) {
            for (const auto& product : products) {
                outputFile << product->getType() << endl;
                outputFile << product->getName() << endl;
                outputFile << product->getQuantity() << endl;

                // Check the type of the product and write additional details
                ProductWithPrice* pwp = dynamic_cast<ProductWithPrice*>(product);
                if (pwp) {
                    outputFile << pwp->getPrice() << endl;
                }

                ProductWithWeight* pww = dynamic_cast<ProductWithWeight*>(product);
                if (pww) {
                    outputFile << pww->getWeight() << endl;
                }

                outputFile << endl;
            }
            outputFile.close();
            cout << "Inventory saved to file." << endl;
        }
        else {
            cout << "Unable to open file." << endl;
        }
    }

    // Function to load the inventory from a file
    void loadFromFile(const string& filename) {
        ifstream inputFile(filename);
        if (inputFile.is_open()) {
            string type, name;
            int quantity;
            double price, weight;

            while (getline(inputFile, type)) {
                getline(inputFile, name);
                inputFile >> quantity;
                inputFile.ignore();  // Ignore newline character

                if (type == "Product with Price") {
                    inputFile >> price;
                    inputFile.ignore();  // Ignore newline character
                    ProductWithPrice* pwp = new ProductWithPrice(name, quantity, price);
                    addProduct(pwp);
                }
                else if (type == "Product with Weight") {
                    inputFile >> weight;
                    inputFile.ignore();  // Ignore newline character
                    ProductWithWeight* pww = new ProductWithWeight(name, quantity, weight);
                    addProduct(pww);
                }

                inputFile.ignore();  // Ignore blank line
            }

            inputFile.close();
            cout << "Inventory loaded from file." << endl;
        }
        else {
            cout << "Unable to open file." << endl;
        }
    }
};

int main() {
    Inventory inventory;
    int choice;

    do {
        cout << "Retail Inventory Management System" << endl;
        cout << "1. Add product with price" << endl;
        cout << "2. Add product with weight" << endl;
        cout << "3. Display inventory" << endl;
        cout << "4. Save inventory to file" << endl;
        cout << "5. Load inventory from file" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int quantity;
                double price;

                cout << "Enter product name: ";
                cin.ignore();  // Ignore newline character
                getline(cin, name);
                cout << "Enter quantity: ";
                cin >> quantity;
                cout << "Enter price: ";
                cin >> price;

                ProductWithPrice* product = new ProductWithPrice(name, quantity, price);
                inventory.addProduct(product);
                break;
            }
            case 2: {
                string name;
                int quantity;
                double weight;

                cout << "Enter product name: ";
                cin.ignore();  // Ignore newline character
                getline(cin, name);
                cout << "Enter quantity: ";
                cin >> quantity;
                cout << "Enter weight (kg): ";
                cin >> weight;

                ProductWithWeight* product = new ProductWithWeight(name, quantity, weight);
                inventory.addProduct(product);
                break;
            }
            case 3:
                inventory.displayInventory();
                break;
            case 4: {
                string filename;
                cout << "Enter filename to save inventory: ";
                cin >> filename;
                inventory.saveToFile(filename);
                break;
            }
            case 5: {
                string filename;
                cout << "Enter filename to load inventory: ";
                cin >> filename;
                inventory.loadFromFile(filename);
                break;
            }
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != 6);

    return 0;
}
