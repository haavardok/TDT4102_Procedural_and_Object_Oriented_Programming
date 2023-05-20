#include "Utilities.h"

string toGreek(string sentence)
{
    // BEGIN: 2a

    // Write your answer to assignment 2a here, between the // BEGIN: 2a
    // and // END: 2a comments. Remove the code that is already there.

    string greekSentence{""};

    for (unsigned int i=0; i<sentence.size(); i++) {
        if (!isspace(sentence.at(i))) {
            greekSentence.push_back(sentence.at(i) + 2);
        } 
        else {
            greekSentence.push_back(sentence.at(i));
        }
    }

    return greekSentence;
    
    // END: 2a
}

vector<vector<string>> loadSvada()
{
    // BEGIN: 2b

    // Write your answer to assignment 2b here, between the // BEGIN: 2b
    // and // END: 2b comments. Remove the code that is already there.

    vector<string> groupVector;
    vector<vector<string>> svadaVector;

    ifstream ifs{"SvadaWords.txt"};
    if (!ifs) {
        error("Could not open SvadaWords.txt");
    }

    string line{""};

    while(getline(ifs, line)) {
        if (line == "||") {
            svadaVector.push_back(groupVector);
            groupVector.clear();
        }
        else {
            groupVector.push_back(line);
        }
    }
    svadaVector.push_back(groupVector);

    return svadaVector;

    // END: 2b
}

string svadaGenerator(vector<vector<string>> svadaVec)
{
    // BEGIN: 2c1

    // Write your answer to assignment 2c1 here, between the // BEGIN: 2c1
    // and // END: 2c1 comments. Remove the code that is already there.

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribRow(0,23);

    string svadaSentence{""};

    for (unsigned int i=0; i<7; i++) {
        svadaSentence = svadaSentence + svadaVec.at(i).at(distribRow(gen)) + " ";
    }
    
    return svadaSentence;

    // END: 2c1
}