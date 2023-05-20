#include "std_lib_facilities.h"
#include "InsuranceContract.h"
#include "ContractDataBase.h"
#include "Utilities.h"

//------------------------------------------------------------------------------'

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	ContractDataBase db{};
	db.loadContracts("DataBase.txt");
	InsuranceContract contract{"Jonas Lie", InsuranceType::Car, 1000, 1242, ""};
	//You can test your code under here

	// cout << db.getContract(1234) << endl;
	// cout << db.numberOfInsuranceType(InsuranceType::Car) << endl;
	// cout << db.addContract("Test", InsuranceType::Car, 3000) << endl;
	// cout << db.getContract(1242) << endl;
	// db.saveContracts("testDatabase.txt");

	// cout << toGreek("Alle fugler sma de er") << endl;
	// vector<vector<string>> svada = loadSvada();
	// cout << svada.at(6).at(23) << endl;
	// cout << "yes" << endl;

	// vector<vector<string>> svada = loadSvada();
	// string svadaSentence = svadaGenerator(svada);
	// cout << svadaSentence;

	db.saveContracts("updatedDatabase.txt");
	
	return 0;
}

//------------------------------------------------------------------------------
