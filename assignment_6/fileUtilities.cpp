#include "fileUtilities.hpp"

void readInputAndWriteToFile(void)
{
    std::string userInput{""};
    std::string userString{""};
    std::filesystem::path fileName{"userInput.txt"};
    
    std::ofstream outputStream{fileName};
    if (!outputStream) {
        error("Can't open output file ", "userInput.txt");
    }

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
    std::string line{""};
    int counter{0};

    std::ifstream inputStream{fileToCopy};
    if (!inputStream) {
        error("Can't open input file ", fileToCopy);
    }

    std::ofstream outputStream{fileName};
    if(!outputStream) {
        error("Can't open output file ", "copy-" + fileToCopy);
    }

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
    if (!inputStream) {
        error("Can't open input file ", fileName);
    }

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