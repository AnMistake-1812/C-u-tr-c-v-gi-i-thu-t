
#include "Family.h"

// Du lieu gia pha mau
vector<Person> family = {
    { 1, "Cu To A", -1 },
    { 2, "Ong B", 1 },
    { 3, "Ba C", 1 },
    { 4, "Bo D", 2 },
    { 5, "Co E", 2 },
    { 6, "Chu F", 3 },
    { 7, "Con G", 4 },
    { 8, "Con H", 4 }
};

// Tim thanh vien theo ID
int findPerson(int id) {
    for (int i = 0; i < family.size(); i++) {
        if (family[i].id == id) {
            return i;
        }
    }

    return -1;
}

// Tim va in Cu to
void findAncestor() {
    cout << "\n=== TIM CU TO ===\n";

    for (int i = 0; i < family.size(); i++) {
        if (family[i].parentId == -1) {
            cout << "Cu to la: "
                << family[i].name << endl;
            return;
        }
    }

    cout << "Khong tim thay Cu to!\n";
}

// In danh sach con cai
void printChildren(int id) {
    cout << "\n=== DANH SACH CON CAI ===\n";

    bool found = false;

    for (int i = 0; i < family.size(); i++) {
        if (family[i].parentId == id) {
            cout << "- " << family[i].name << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Khong co con cai.\n";
    }
}

// In danh sach anh chi em
void printSiblings(int id) {
    int pos = findPerson(id);

    if (pos == -1) {
        cout << "Khong tim thay thanh vien!\n";
        return;
    }

    int parent = family[pos].parentId;

    if (parent == -1) {
        cout << "Thanh vien khong co anh chi em.\n";
        return;
    }

    cout << "\n=== DANH SACH ANH CHI EM ===\n";

    bool found = false;

    for (int i = 0; i < family.size(); i++) {
        if (family[i].parentId == parent &&
            family[i].id != id) {

            cout << "- " << family[i].name << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Khong co anh chi em.\n";
    }
}
