#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class Clothing {
public:
    string item, color, fabric, category;

    Clothing(string i, string c, string f, string cat) {
        item = i;
        color = c;
        fabric = f;
        category = cat;
    }
};

class Wardrobe {
private:
    vector<Clothing> clothes;

public:
    void addClothing() {
        string item, color, fabric, category;

        cout << "\nEnter clothing item: ";
        getline(cin, item);

        cout << "Enter color: ";
        getline(cin, color);

        cout << "Enter fabric type: ";
        getline(cin, fabric);

        cout << "Enter category (Top/Bottom/Other): ";
        getline(cin, category);

        if (item.empty() || color.empty() ||
            fabric.empty() || category.empty()) {
            cout << "Please enter all details.\n";
            return;
        }

        clothes.push_back(
            Clothing(item, color, fabric, category)
        );

        cout << "\nClothing item added successfully!\n";
    }

    void viewWardrobe() {
        cout << "\n===== WARDROBE ITEMS =====\n";

        if (clothes.empty()) {
            cout << "Wardrobe is empty.\n";
            return;
        }

        for (int i = 0; i < clothes.size(); i++) {
            cout << "\nItem " << i + 1 << endl;
            cout << "Name: " << clothes[i].item << endl;
            cout << "Color: " << clothes[i].color << endl;
            cout << "Fabric: " << clothes[i].fabric << endl;
            cout << "Category: " << clothes[i].category << endl;
        }
    }

    void findMatchingClothes() {
        cout << "\n===== MATCHING CLOTHES =====\n";

        bool found = false;

        for (int i = 0; i < clothes.size(); i++) {
            for (int j = i + 1; j < clothes.size(); j++) {
                if (clothes[i].category != clothes[j].category) {
                    cout << clothes[i].item << " (" 
                         << clothes[i].color << ") + "
                         << clothes[j].item << " ("
                         << clothes[j].color << ")\n";
                    found = true;
                }
            }
        }

        if (!found) {
            cout << "No matching combinations found.\n";
        }
    }

    void outfitSuggestions() {
        cout << "\n===== OUTFIT SUGGESTIONS =====\n";

        bool found = false;

        for (int i = 0; i < clothes.size(); i++) {
            for (int j = 0; j < clothes.size(); j++) {
                if (clothes[i].category == "Top" &&
                    clothes[j].category == "Bottom") {

                    cout << clothes[i].item << " (" 
                         << clothes[i].color << ") + "
                         << clothes[j].item << " ("
                         << clothes[j].color << ")\n";

                    found = true;
                }
            }
        }

        if (!found) {
            cout << "Add at least one Top and one Bottom.\n";
        }
    }
};

int main() {
    Wardrobe w;
    int choice;

    do {
        cout << "\n===== MODULAR WARDROBE & FABRIC PAIRING ENGINE =====\n";
        cout << "1. Add Clothing Item\n";
        cout << "2. View Wardrobe Items\n";
        cout << "3. Find Matching Clothes\n";
        cout << "4. Get Outfit Suggestions\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                w.addClothing();
                break;
            case 2:
                w.viewWardrobe();
                break;
            case 3:
                w.findMatchingClothes();
                break;
            case 4:
                w.outfitSuggestions();
                break;
            case 5:
                cout << "Thank you for using Wardrobe Engine!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
