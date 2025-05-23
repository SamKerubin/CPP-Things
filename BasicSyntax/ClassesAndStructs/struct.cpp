#include <iostream>

/*
    Structs are basically the same as classes, but in this case,
    structs are lighter than classes

    And... thats it... I dont know what else i should say about structs
*/

struct Struct {
    int a;
    int b;

    Struct() { std::cout << "Creating struct" << std::endl; }
    ~Struct() { std::cout << "Deleting struct" << std::endl; }

    void showValues() { std::cout << "A: " << a << " B: " << b << std::endl; }
};

int main() {
    Struct struct1;
    struct1.a = 1;
    struct1.b = 2;
    struct1.showValues();

    Struct* struct2 = new Struct();
    struct2->a = 3;
    struct2->b = 4;
    struct2->showValues();

    delete struct2;

    return 0;
}
