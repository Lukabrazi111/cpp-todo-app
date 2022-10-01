#include <iostream>
#include <fstream>
#include <vector>

const std::string TEMP_FILE = "tmp.txt";

void addTodo(std::string &todoText) {
    std::ofstream oFile;

    std::cout << "Enter your todo:";
    std::cin.ignore(); // removes chars from input buffer
    std::getline(std::cin, todoText);

    oFile.open(TEMP_FILE, std::ios_base::app);
    oFile << todoText << "\n";

    if (oFile.is_open()) {
        system("clear");
        std::cout << "Todo added successfully!\n";
    }

    oFile.close();
}

void getTodos() {
    std::ifstream file(TEMP_FILE);

    std::vector<std::string> names;

    system("clear");
    std::cout << "Todo list:\n";
    std::cout << "==========================\n";
    if (file.is_open()) {
        std::string input;
        while (std::getline(file, input)) {
            names.push_back(input);
        }
        for (const std::string &name: names) {
            std::cout << name << "\n";
        }
    } else {
        std::cout << "Todo list is not found!";
    }

}

int main() {
    std::string todoText;
    char op;

    do {
        std::cout << "===========================" << std::endl;
        std::cout << "1. Add todo" << std::endl;
        std::cout << "2. Get list of todos" << std::endl;
        std::cout << "6. Save and exit" << std::endl;
        std::cout << "===========================" << std::endl;

        std::cout << "Enter an option:";
        std::cin >> op;

        switch (op) {
            case '1':
                system("clear");
                addTodo(todoText);
                break;
            case '2':
                getTodos();
                break;
            case '6':
                std::cout << "Bye!\n";
                break;
            default:
                system("clear");
                std::cout << "Please choose correct option!" << std::endl;
                break;
        }
    } while (op != '6');


    return 0;
}