#include "ContractDataBase.h"

InsuranceContract ContractDataBase::getContract(int id)
{
    // BEGIN: 1b

    // Write your answer to assignment 1b here, between the // BEGIN: 1b
    // and // END: 1b comments. Remove the code that is already there.

    for (unsigned int i=0; i<contracts.size(); i++) {
        if (contracts.at(i).getId() == id) {
            return contracts.at(i);
        }
    }

    // END: 1b

    // Returning an empty contract if no contract with the given id is found.
    return InsuranceContract{};
}

int ContractDataBase::numberOfInsuranceType(InsuranceType type)
{
    // BEGIN: 1c

    // Write your answer to assignment 1c here, between the // BEGIN: 1c
    // and // END: 1c comments. Remove the code that is already there.

    (void)type;
    return 0;

    // END: 1c
}

int ContractDataBase::addContract(string holderName, InsuranceType insType, int value)
{
    // BEGIN: 1d 

    // Write your answer to assignment 1d here, between the // BEGIN: 1d
    // and // END: 1d comments. Remove the code that is already there.

    (void)holderName;
    (void)insType;
    (void)value;
    return 0;

    // END: 1d
}

void ContractDataBase::saveContracts(string filename)
{
    // BEGIN: 1e

    // Write your answer to assignment 1e here, between the // BEGIN: 1e
    // and // END: 1e comments. Remove the code that is already there.

    (void)filename;

    // END: 1e
}

void ContractDataBase::loadContracts(string filename)
{
    ifstream inFile{filename};
    if (!inFile)
    {
        error("Couldn't open file: ", filename);
    }

    string line;
    while (getline(inFile, line))
    {
        stringstream ss{line};
        char seperator;

        string holderName;
        getline(ss, holderName, ',');

        string insType;
        getline(ss, insType, ',');

        int value;
        ss >> value;
        ss >> seperator;

        int id;
        ss >> id;
        ss >> seperator;

        string insuranceText;
        getline(ss, insuranceText, ',');

        contracts.push_back({holderName, stringToInsuranceType.at(insType), value, id, insuranceText});
    }
}
