#include "fileUtilities.hpp"

void readInputAndWriteToFile(void)
{
    std::filesystem::path fileName{"userInput.txt"};
    std::ofstream outputStream{fileName};
    std::string userInput{""};
    std::string userString{""};

    std::cout << "Write words to store in file. Stop by writing 'quit'." << std::endl;

    while (1) {
        std::cout << "Enter word: ";
        std::cin >> userInput;
        if (userInput == "quit") {
            break;
        } 
        else {
        userString += userInput + "\n";
        }
    }
    outputStream << userString;
}

void makeFileCopyWithLineNumber(const std::string& fileToCopy)
{
    std::filesystem::path fileName{"copy-" + fileToCopy};
    std::ofstream outputStream{fileName};
    std::ifstream inputStream{fileToCopy};
    std::string line{""};
    int counter{0};

    while (std::getline(inputStream, line)) {
        counter++;
        outputStream << counter;
        outputStream << " " + line << std::endl;
    }
}

void letterStatisticsInFile(const std::string& fileName)
{
    std::ifstream inputStream{fileName};
}