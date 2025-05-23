#include "add.h"
#include <iostream>

/*
    And last, in a main file (with only one main method overall)
    you include the header file and other things you need
    When compiled, it will search in the files that defined the methods inside the header
    and its going to use those bodies

    NOTE: COMPILE PROJECTS WITH CMAKE IF POSSIBLE, ITS EASIER AND QUICKER MOST OF THE TIME

    To compile a project with CMake you need to do as follow:

    CMakeLists.txt <- file that will hold the information of your project (directory)
*/

int main()
{
    std::cout << add(3, 5) << std::endl;

    return 0;
}