
#include "main.h"

int main()
{
	unsigned seed;
	const int SIZE = 20;
	Patient patient[SIZE];
	Treatment treatment[SIZE];
	int index = 0;
	int count = 0;
	string name;
	int id;
	int heartRate;
	int respRate;
	int breathSounds;
	int coughType;
	int coughSecretions;
	int coughEffective;
	int oxygenDevice;
	int flowLPM;
	int percentOxygen;
	int difficulty;
	int chestXRay;
	int smoking;
	int surgery;
	int score;
	string frequency;
	string treatment1;
	string treatment2;
	string treatment3;
	char nextPatient;
	
	seed = time(0);
	srand(seed);
	
	Patient patientNames[SIZE] = {Patient("Spiderman"), Patient("Iron Man"), 
								  Patient("Hulk"), Patient("Thor"), 
								  Patient("Captain America"), Patient("Scarlet Witch"),
								  Patient("Ant-Man"), Patient("Black Panther"), 
								  Patient("Doctor Strange"), Patient("Captain Marvel")};
	
	do
	{		
		cout << "\nPatient ID: ";
		id = generateRandom(555999, 555000);
		cout << id << endl;

		cout << "Name: ";
		name = patientNames[index].getName();
		cout << name << endl;
		
		cout << "Heart rate: ";
		heartRate = generateRandom(151, 49);
		cout << heartRate << endl;
		while(heartRate < 50 || heartRate > 150)
		{
			cout << "**Error: Enter a heart rate between 50 and 150, inclusive. ";
			heartRate = generateRandom(151, 49);
			cout << heartRate << endl;
		}
		
		cout << "Respiratory rate: ";
		respRate = generateRandom(41, 5);
		cout << respRate << endl;
		while(respRate < 6 || respRate > 40)
		{
			cout << "**Error: Enter a respiratory rate between 6 and 40, inclusive. ";
			respRate = generateRandom(41, 5);
			cout << respRate << endl;
		}
		
		cout << endl << "Breath sounds: " << endl;
		cout << "1) Clear" << endl;
		cout << "2) Diminished" << endl;
		cout << "3) Wheezing" << endl;
		cout << "4) Coarse" << endl;
		cout << "Enter choice: ";
		breathSounds = generateRandom(5, -1);
		cout << breathSounds << endl;
		while(breathSounds < 1 || breathSounds > 4)
		{
			cout << "**Error: Enter number between 1 and 4, inclusive. ";
			breathSounds = generateRandom(5, -1);
			cout << breathSounds << endl;
		}
		
		cout << endl << "Type of cough:" << endl;
		cout << "1) Strong nonproductive" << endl;
		cout << "2) Strong productive" << endl;
		cout << "3) Weak nonproductive" << endl;
		cout << "4) Weak productive" << endl;
		cout << "Enter choice: ";
		coughType = generateRandom(5, -1);
		cout << coughType << endl;
		while(coughType < 1 || coughType > 4)
		{
			cout << "**Error: Enter number between 1 and 4, inclusive. ";
			coughType = generateRandom(5, -1);
			cout << coughType << endl;
		}
		
		// Sets secretion clearance and cough effectiveness to -1
		coughSecretions = -1;
		coughEffective = -1;
		// Determines if patient needs treatment for congestion based on
		// their ability to clear secretions and cough effectively
		if(coughType != 1)
		{
			cout << "\nDoes patient have difficulty clearing secretions?\n";
			cout << "(Enter '1' for yes or '0' for no): ";
			coughSecretions = generateRandom(2,-1);
			cout << coughSecretions << endl;
			while(coughSecretions != 1 && coughSecretions != 0)
			{
				cout << "**Error (enter '1' for yes or '0' for no): ";
				coughSecretions = generateRandom(2,-1);
				cout << coughSecretions << endl;
			}
			
			if(coughType == 3 || coughType == 4)
			{
				cout << "\nDoes patient have an effective cough?\n";
				cout << "(Enter '1' for yes or '0' for no): ";
				coughEffective = generateRandom(2,-1);
				cout << coughEffective << endl;
				while(coughEffective != 1 && coughEffective != 0)
				{
					cout << "**Error (enter '1' for yes or '0' for no): ";
					coughEffective = generateRandom(2,-1);
					cout << coughEffective << endl;	
				}
			}
		}
		
		cout << endl << "Oxygen device:" << endl;
		cout << "1) None (on room air)" << endl;
		cout << "2) Nasal cannula" << endl;
		cout << "3) High flow nasal cannula" << endl;
		cout << "Enter choice: ";
		oxygenDevice = generateRandom(4,0);
		cout << oxygenDevice << endl;
		while(oxygenDevice < 1 || oxygenDevice > 3)
		{
			cout << "**Error: Enter number between 1 and 3, inclusive. ";
			oxygenDevice = generateRandom(4,0);
			cout << oxygenDevice << endl;
			
		}
		
		// Sets flowrate and percent oxygen to -1
		flowLPM = -1;
		percentOxygen = -1;
		// Determines how much oxygen the patient is receiving based on the patient's
		// nasal cannula flowrate or high flow nasal cannula oxygen percent
		if(oxygenDevice == 2)
		{
			cout << "\nNasal cannula flowrate (liters per minute): ";
			flowLPM = generateRandom(7, 0);
			cout << flowLPM << endl;
			while(flowLPM < 1 || flowLPM > 6)
			{
				cout << "**Error: Flow must be between 1 LPM and 6 LPM, inclusive.\n";
				cout << "Re-enter: ";
				flowLPM = generateRandom(7, 0);
				cout << flowLPM << endl;
			}
		}
		else if (oxygenDevice == 3)
		{
			cout << "\nPercentage of oxygen delivered by\n"
				<< "high flow nasal cannula: ";
			percentOxygen = generateRandom(101,20);
			cout << percentOxygen << endl;
			while(percentOxygen < 21 || percentOxygen > 100)
			{
				cout << "**Error: Oxygen must be between 21% and 100%, inclusive.\n";
				cout << "Re-enter: ";
				percentOxygen = generateRandom(101,20);
				cout << percentOxygen << endl;
			}
		}
		
		cout << endl << "Difficulty breathing: " << endl;
		cout << "1) No difficulty" << endl;
		cout << "2) Difficulty breathing with activity" << endl;
		cout << "3) Difficulty breathing at rest" << endl;
		cout << "4) Labored breathing with use of accessory muscles" << endl;
		cout << "Enter choice: ";
		difficulty = generateRandom(5,0);
		cout << difficulty << endl;
		while(difficulty < 1 || difficulty > 4)
		{
			cout << "**Error: Enter number between 1 and 4, inclusive. ";
			difficulty = generateRandom(5,0);
			cout << difficulty << endl;
		}
		
		cout << endl << "Chest x-ray interpretation:" << endl;
		cout << "1) Clear lungs" << endl;
		cout << "2) One lobe of lung collapsed" << endl;
		cout << "3) Two lobes of same lung collapsed" << endl;
		cout << "4) Lobes in both lungs collapsed" << endl;
		cout << "Enter choice: ";
		chestXRay = generateRandom(5,0);
		cout << chestXRay << endl;
		while(chestXRay < 1 || chestXRay > 4)
		{
			cout << "**Error: Enter number between 1 and 4, inclusive. ";
			chestXRay = generateRandom(5,0);
			cout << chestXRay << endl;
		}
		
		cout << endl << "Smoking history:" << endl;
		cout << "1) Never" << endl;
		cout << "2) Less than 10 years" << endl;
		cout << "3) Less than 20 years" << endl;
		cout << "4) Greater than or equal to 20 years" << endl;
		cout << "Enter choice: ";
		smoking = generateRandom(5,0);
		cout << smoking << endl;
		while(smoking < 1 || smoking > 4)
		{
			cout << "**Error: Enter number between 1 and 4, inclusive. ";
			smoking = generateRandom(5,0);
			cout << smoking << endl;
		}
		
		cout << endl << "Recent surgery:" << endl;
		cout << "1) No surgery" << endl;
		cout << "2) General surgery" << endl;
		cout << "3) Lower abdominal surgery" << endl;
		cout << "4) Upper abdominal or thoracic surgery" << endl;
		cout << "Enter choice: ";
		surgery = generateRandom(5,0);
		cout << surgery << endl;
		while(surgery < 1 || surgery > 4)
		{
			cout << "**Error: Enter number between 1 and 4, inclusive. ";
			surgery = generateRandom(5,0);
			cout << surgery << endl;
		}
		
		// Calls Patient member function to set patient information
		patient[index].setPatientData(name, id, heartRate, respRate, breathSounds);
		patient[index].setPatientCough(coughType, coughSecretions, coughEffective);
		patient[index].setPatientDevice(oxygenDevice, flowLPM, percentOxygen);
		patient[index].setPatientOther(difficulty, chestXRay, smoking, surgery);
		
		treatment[index].id = id;
		treatment[index].name = name;
		
		// Calls function to calculate score and assign score to Treatment array
		treatment[index].score = calcScore(respRate, breathSounds, coughType, oxygenDevice, 
			flowLPM, percentOxygen, difficulty, chestXRay, smoking, surgery);
		
		// Calls function to calculate frequency and assign frequency to Treatment aray
		treatment[index].frequency = calcFrequency(treatment, index);
		
		// Calls functions to determine treatments and assign treatments to Treatment array
		treatment[index].treatment1 = treatWheezing(breathSounds, smoking);
		treatment[index].treatment2 = treatCongestion(breathSounds, coughSecretions, 
										coughEffective);
		treatment[index].treatment3 = treatLowLungVolumes(breathSounds, chestXRay, surgery);
		
		// Increments 1 to index and count
		index++;
		count++;
		
		cout << "\nWould you like to assess another patient? \n";
		cout << "Enter 'Y' for yes or 'N' for no: ";
		cin >> nextPatient;
	
	} while(toupper(nextPatient) == 'Y');
	
	// Displays patient report and treatment plans
	printPatientData(patient, count);
	printTreatment(treatment, count);
	
	return 0;
}







