#include <iostream>
#include <memory>

/*
    Usually you arent going to use primitive pointers, because they can cause memory leaks if not deleted
    So... Smart pointers are pointers that dont need to be deleted, they delete themselfs when required

    We got:

    Unique pointers:

    unique_ptr<type> ptr = make_unique<type>(v);

    As its name says, it creates a unique value of a pointer
    This is mostly a primitive pointer, but with the difference that this type deletes itself

    Shared pointers:

    shared_ptr<type> ptr = make_shared<type>(v);

    Its used to share memory addresses between two or more pointers,
    this type of pointer is able to track how many reference its making,
    if there are no active reference, then it deletes itself

    Weak pointers:

    Most of the time its used with shared pointers
    This type of pointer is able to make a weak reference to a variable,
    which means it doesnt keep its memory address alive, just uses it temporarily
    and then deletes itself

    Weak pointers needs a shared pointer to be initialized
    You can also use methods like:

    lock() <- returns the shared pointer asigned
    expired() <- returns if the pointer is still alive (true|false)
*/

int main()
{
    int var = 10;

    int var2 = 20;
    int var3 = 30;

    std::unique_ptr<int> ptr = std::make_unique<int>(var);

    std::shared_ptr<int> s_ptr = std::make_shared<int>(var2);
    std::shared_ptr<int> s_ptr2 = s_ptr;

    std::shared_ptr<int> s_ptr3 = std::make_shared<int>(var3);
    std::weak_ptr<int> w_ptr = s_ptr3;

    std::cout << *ptr << std::endl;
    std::cout << *s_ptr << " " << *s_ptr2 << std::endl;
    std::cout << *s_ptr3 << " " << *w_ptr.lock() << std::endl;

    return 0;
}