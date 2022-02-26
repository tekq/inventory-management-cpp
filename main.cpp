#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <sstream>
#include <vector>

using namespace std;

string beggining_choice;
string inv[100];
int inv_occupied_slots = 0;
bool scanned_inv_save = false;

// read inventory from inv.sav
void read_inv() {
    int i = 0;
    ifstream inv_save("inv.sav");
    while (i < 100) {
        inv_save >> inv[i];
        if (inv[i] == "") {
            i = 100;
        }
        inv_occupied_slots++;
        i++;
    }
    scanned_inv_save = true;
    inv_occupied_slots--;
}

// save the current inventory
void save_inv() {
    ofstream inv_save("inv.sav");
    for (int i = 0; i < inv_occupied_slots; i++) {
        inv_save << inv[i] << " ";
    }

    inv_save << "\n";
    inv_save.close();
}

// Create an item in the inventory
void create_item() {
    string name;
    cout << "create item name: ";
    cin >> name;
    inv[inv_occupied_slots] = name;
    inv_occupied_slots++;
}

// Show inventory
void inv_menu() {
    cout << "Inventory items: ";
    for (int i = 0; i < inv_occupied_slots; ++i) {
        cout << inv[i] << " ";
    }
    cout << "\n";
}

int main() {
    if (scanned_inv_save == false)
        read_inv();

    string name;
    cout << "Simple Inventory\n";
    cout << "Press 'i' to check inventory or 'c' to create an item.\n";

    cin >> beggining_choice;

    if (beggining_choice == "i") {
        inv_menu();
        main();
    } else if (beggining_choice == "c") {
        create_item();
        main();
    } else if (beggining_choice == "s") {
        save_inv();
    } else if (beggining_choice == "q") {
        return 0;
    } else if (beggining_choice == "r") {
        read_inv();
    } else {
        main();
    }

    return 0;
}