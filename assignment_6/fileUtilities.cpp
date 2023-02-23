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
    std::map<int, int> letterStatistics;
    std::ifstream inputStream{fileName};

    for (unsigned char letter = 'a'; inputStream >> letter;) {
        if (std::isalpha(letter)) {
            if (letterStatistics.count(std::tolower(letter))) {
                letterStatistics.at(std::tolower(letter))++;
            }
            else {
                letterStatistics.insert({tolower(letter),1});
            }
        }
    }

    for (const auto& [letter, statistics] : letterStatistics) {
        std::cout << static_cast<char>(letter) << ": " << statistics << "\t";
        if (letter % 3 == 0) {
            cout << "\n";
        }
    }
}