#include <iostream>
#include <array>

using namespace std;

enum Tools {
    health_potion,
    torch,
    arrow,
    all_tools
};

int countTotalItems(array<int, Tools::all_tools> &tools) {
    return tools[Tools::health_potion] + tools[Tools::torch] + tools[Tools::arrow];
}

int main() {
    array<int, Tools::all_tools> tools{ 2, 5, 10 };

    cout << "Total number of elements: " << countTotalItems(tools) << "\n";
    cout << "Number of torch: " << tools[Tools::torch];

    return 0;
}

