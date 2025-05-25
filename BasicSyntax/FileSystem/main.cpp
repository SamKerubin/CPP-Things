#include <fstream>
#include <filesystem>
#include <string>
#include <iostream>

/*
    To create/write in/read files you need to import standar library fstream,
    (for more specific usage, use <ifstream> for only reading and <ofstream> for only creating/writing)

    You may want to use also library filesystem to check if a file exists (and also many other things)

    To create a file, you do as follow:

    ofstream varName(file_path);

    And then, you can write inside that file (also it depends of what type of file you created)
    (Usually .txt, plain text files, etc.)

    varNamme << "CONTENT"

    Then, if you want to open a file to read its content, you do as follow:

    ifstram varName(file_path);

    Now, you only need to access its content with a string:

    string content;
    while(getline(readFile, content)) {} <- getline its a method from library <string>

    NOTE: its nothing about files, but searching about this i realised that you can make your own custom operators
    (+, -, *, /, %, &&, ||, ==, !, =, !=, etc)
*/

int main()
{
    if (!std::filesystem::exists("something.txt"))
    {
        std::ofstream file("something.txt");
        if (!file)
        {
            std::cerr << "Error creating file" << std::endl;
            return 1;
        }

        file << "Hello World! :3";
    }

    std::ifstream readFile("something.txt");
    if (!readFile)
    {
        std::cerr << "Error reading file" << std::endl;
        return 1;
    }

    std::string content;
    while(std::getline(readFile, content))
    {
        std::cout << content << std::endl;
    }

    readFile.close();
}
