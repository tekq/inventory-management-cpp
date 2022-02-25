#include <iostream>

using namespace std;


int main() {
    string beggining_choice;
    string inv[1000];
    string name;
    int inv_occupied_slots;
    inv_occupied_slots = 0;
    cout << "Simple Inventory\n";
    cout << "Press 'i' to check inventory.\n";

    cin >> beggining_choice;

    while (beggining_choice == "i") {
        cout << "Inventory items: ";
        for (int i = 0; i < inv_occupied_slots; ++i) {
            cout << inv[i] << " ";
        }

        cout << "\n";

        cout << "create item name: ";
        cin >> name;
        inv[inv_occupied_slots] = name;
        inv_occupied_slots++;
    }

    return 0;
}
