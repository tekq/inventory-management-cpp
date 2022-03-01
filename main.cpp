#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string beginning_choice;
string inv[100];
int inv_occupied_slots = 0;
bool scanned_inv_save = false;

// read inventory from inv.sav
void read_inv() {
    int i = 0;
    ifstream inv_save("inv.sav");
    while (i < 100) {
        inv_save >> inv[i];
        if (inv[i].empty()) {
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
    string name;
    cout << "item to remove name: ";
    cin >> name;

    for (int i = 0; i < inv_occupied_slots; i++) {
        if (inv[i] == name) { // remove items that are the same as the string "name"
            inv[i] = " ";
            break;
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
    if (!scanned_inv_save) // necessary for inventory saving to work properly
        read_inv();

    string name;
    cout << "Simple Inventory Example\n";
    cout << "Press 'h' for help.\n";
    cout << "Inventory items: " << inv_occupied_slots << "\n";
    cout << endl;

    cin >> beginning_choice;

    if (beginning_choice == "i" || beginning_choice == "I") { // show inventory
        inv_menu();
        main();
    } else if (beginning_choice == "c" || beginning_choice == "C") { // add a new item to the inventory
        create_item();
        main();
    } else if (beginning_choice == "s" || beginning_choice == "S") { // save the inventory to inv.sav
        save_inv();
    } else if (beginning_choice == "q" || beginning_choice == "Q") { // quit
        return 256;
    } else if (beginning_choice == "r" || beginning_choice == "R") { // read inventory again(might temporarily break the inventory)
        read_inv();
        main();
    } else if (beginning_choice == "d" || beginning_choice == "D") { // trigger removal of items
        remove_item();
        main();
    } else if (beginning_choice == "h" || beginning_choice == "H") { // example help message
        cout << "Example Help Message" << endl;
        cout << " h - print this menu\n i - show current inventory\n c - create item\n s - save inventory to inv.sav\n q - quit\n r - read inventory(may cause breakage)\n d - remove item\n";
        main();
    } else {
        main();
    }

    return 0;
}
