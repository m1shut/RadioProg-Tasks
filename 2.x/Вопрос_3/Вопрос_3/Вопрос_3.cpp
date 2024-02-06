#include <iostream>
#include "io.h"

using namespace std;

int main() {
    int x = readNumber();
    int y = readNumber();

    writeAnswer(x + y);

    return 0;
}