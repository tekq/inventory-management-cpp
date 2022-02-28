#include <iostream>
#include <fstream>
#include <string>

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

void remove_item() {
    string name, empty_pos;
    cout << "item to remove name: ";
    cin >> name;

    for (int i = 0; i < inv_occupied_slots; i++) {
        if (inv[i] == name) {
            inv[i] = " ";
            empty_pos = i;
        }
    }

    // filter out empty slots
    for (int i = 0; i < inv_occupied_slots; i++) { 
        if (inv[i] == " ") {
            string tmp;
            tmp = inv[i + 2];
            inv[i] = inv[i + 1];
            inv[i + 1] = tmp;
            inv_occupied_slots--;
        }
    }
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
    if (scanned_inv_save == false) // necessary for inventory saving to work properly
        read_inv();

    string name;
    cout << "Simple Inventory\n";
    cout << "Press 'i' to check inventory or 'c' to create an item.\n";
    cout << "Inventory items: " << inv_occupied_slots << "\n";
    cout << endl;

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
        main();
    } else if (beggining_choice == "d") {
        remove_item();
        main();
    } else {
        main();
    }

    return 0;
}
