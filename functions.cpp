
#include "functions.h"

/*
Function: generateRandom
Purpose: generates random numbers within a specified number range
*/
int generateRandom(int max, int min)
{
	return (rand() % (max - min + 1)) + min;
}


/*
Function: calcScore
Purpose: calculates overall score for patient based on patient's vital signs,
	clinical presentation, cough, oxygen device and the amount of oxygen it's 
	delivering, smoking history, and surgical history
*/
int calcScore(int RR, int BS, int cough, int device, int LPM, int oxygen, int difficulty,
	int CXR, int smoking, int surgery)
{
	int score = 0;
	
	// Calculates score for respiratory rate
	if(RR <= 20)
	{
		RR = 0;
	}
	else if(RR <= 24)
	{
		RR = 1;
	}
	else if(RR <= 28)
	{
		RR = 2;
	}
	else
	{
		RR = 3;
	}
	
	// Calculates score for nasal cannula flowrate
	if(LPM <= 0)
	{
		LPM = 0;
	}
	else if(LPM <= 3)
	{
		LPM = 1;
	}
	else
	{
		LPM = 2;
	}
	
	// Calculates score for high flow nasal canulla oxygen percent
	if(oxygen == 21)
	{
		oxygen = 0;
	}
	else if(oxygen <= 30)
	{
		oxygen = 1;
	}
	else if(oxygen <= 40)
	{
		oxygen = 2;
	}
	else
	{
		oxygen = 3;
	}
	
	// Decrements 1 from remaining scores
	BS--, cough--, difficulty--, CXR--, smoking--, surgery--;
	
	// Calculates overall score based on patient's oxygen device and by
	// adding scores together
	if(device == 1)
	{
		score = (RR + BS + cough + difficulty + CXR + smoking + surgery);	
	}
	else if(device == 2)
	{
		score = (RR + BS + cough + LPM + difficulty + CXR + smoking + surgery);	
	}
	else
	{
		score = (RR + BS + cough + oxygen + difficulty + CXR + smoking + surgery);
	}
	
	return score;		
}

/*
Function: calcFrequency
Purpose: determines frequency of ordered treatments based on patient's calculated score
*/
string calcFrequency(Treatment treatment[], int i)
{
	string frequency;
	if(treatment[i].score <= 4)
	{
		treatment[i].frequency = "Not indicated or as needed";
	}
	else if(treatment[i].score <= 8)
	{
		treatment[i].frequency = "Every 12 hours (during day)";
	}
	else if(treatment[i].score <= 12)
	{
		treatment[i].frequency = "Every 6 hours (during day)";
	}
	else if(treatment[i].score <= 16)
	{
		treatment[i].frequency = "Every 4 hours (during day)";
	}
	else if(treatment[i].score <= 20)
	{
		treatment[i].frequency = "Every 6 hours (day & night)";
	}
	else
	{
		treatment[i].frequency = "Every 4 hours (day & night)";
	}
	
	return treatment[i].frequency;
}

/*
Function: treatWheezing
Purpose: determines if nebulizer treatments should be ordered if patient is presenting
with wheezing breath sounds or if patient is a long term smoker
*/
string treatWheezing(int BS, int smoking)
{
	string treatment;
	
	if(BS == 3 || smoking == 3 || smoking == 4)
	{
		treatment = "Nebulizer treatment";
	}
	else
	{
		treatment = "Not indicated";
	}
	
	return treatment;
}

/*
Function: treatCongestion
Purpose: determines if secretion clearance and/or cough assist therpy should be 
ordered based on the patient's cough or if their breath sounds are coarse
*/
string treatCongestion(int BS, int coughSec, int coughEff)
{
	string treatment;
	
	if(coughSec == 1 && coughEff == 0)
	{
		treatment = "Secretion clearance and cough assist therapy";
	}
	else if(coughSec == 1 && coughEff != 0)
	{
		treatment = "Secretion clearance therapy";
	}
	else if(coughSec != 1 && coughEff == 0)
	{
		treatment = "Cough assist therapy";
	}
	else if(BS == 4)
	{
		treatment = "Enourage deep breathing and coughing";
	}
	else
	{
		treatment = "Not indicated";
	}
		
	return treatment;
}

/*
Function: treatLowLungVolumes
Purpose: determines if lung expansion therapy should be ordered if patient has diminished
breath sounds, if they have a collapsed lung lobe on their chest x-ray, or if they
recently had surgery
*/
string treatLowLungVolumes(int BS, int CXR, int surgery)
{
	string treatment;
	
	if(BS == 2 || surgery == 3 || surgery == 4 || CXR != 1)
	{
		treatment = "Lung expansion therapy";
	}
	else
	{
		treatment = "Not indicated";
	}
	
	return treatment;
}

/*
Function: printPatientData
Purpose: diplays patient information, including patient's id, name, vital signs,
cough, oxygen device, oxygen setting, breathing effort, chest x-ray, smoking history,
and surgical history; displays "--" if data was not collected from patient
*/
void printPatientData(Patient patient[], int count)
{
	cout << "\nPatient Report:" << endl << endl;
	cout << "Patient ID          ";
	for(int i = 0; i < count; i++)
	{
		cout << setw(18) << patient[i].getId();
	}
	cout << "\nName                ";
	for(int i = 0; i < count; i++)
	{
		cout << setw(18) << patient[i].getName();
	}
	cout << "\nHeart Rate          ";
	for(int i = 0; i < count; i++)
	{
		cout << setw(18) << patient[i].getHeartRate();
	}
	cout << "\nRespiratory Rate    ";
	for(int i = 0; i < count; i++)
	{
		cout << setw(18) << patient[i].getRespRate();
	}
	cout << "\nBreath Sounds       ";
	for(int i = 0; i < count; i++)
	{
		cout << setw(18) << patient[i].getBreathSounds();
	}
	cout << "\nCough Type          ";
	for(int i = 0; i < count; i++)
	{
		cout << setw(18) << patient[i].getCoughType();
	}
	cout << "\nSecretions Difficult";
	for(int i = 0; i < count; i++)
	{
		if(patient[i].getCoughSecretions() == -1)
		{
			cout << setw(18) << "--";
		}
		else
		{
			cout << setw(18) << patient[i].getCoughSecretions();
		}
	}
	cout << "\nCough Effective     ";
	for(int i = 0; i < count; i++)
	{
		if(patient[i].getCoughEffective() == -1)
		{
			cout << setw(18) << "--";
		}
		else
		{
			cout << setw(18) << patient[i].getCoughEffective();
		}
	}
	cout << "\nOxygen Device       ";
	for(int i = 0; i < count; i++)
	{
		cout << setw(18) << patient[i].getOxygenDevice();
	}
	cout << "\nFlowrate in LPM     ";
	for(int i = 0; i < count; i++)
	{
		if(patient[i].getFlowLPM() == -1)
		{
			cout << setw(18) << "--";
		}
		else
		{
			cout << setw(18) << patient[i].getFlowLPM();
		}
	}
	cout << "\nPercent Oxygen      ";
	for(int i = 0; i < count; i++)
	{
		if(patient[i].getPercentOxygen() == -1)
		{
			cout << setw(18) << "--";
		}
		else
		{
			cout << setw(18) << patient[i].getPercentOxygen();
		}
	}
	cout << "\nBreathing Effort    ";
	for(int i = 0; i < count; i++)
	{
		cout << setw(18) << patient[i].getDifficulty();
	}
	cout << "\nChest X-Ray         ";
	for(int i = 0; i < count; i++)
	{
		cout << setw(18) << patient[i].getChestXRay();
	}
	cout << "\nSmoking             ";
	for(int i = 0; i < count; i++)
	{
		cout << setw(18) << patient[i].getSmoking();
	}
	cout << "\nSurgery             ";
	for(int i = 0; i < count; i++)
	{
		cout << setw(18) << patient[i].getSurgery();
	}
	cout << endl << endl;
}


/*
Function: printTreatment
Purpose: displays treatment plan for each patient, including the patient's id,
name, calculated score, frequency of treatments, and treatment types
*/
void printTreatment(Treatment treatment[], int count)
{
	cout << "\nTreatment Plan: " << endl << endl;
	for(int i = 0; i < count; i++)
	{
		cout << "Patient ID       " << treatment[i].id << endl;
		cout << "Name             " << treatment[i].name << endl;
		cout << "Score            " << treatment[i].score << endl;
		cout << "Order Frequency  " << treatment[i].frequency << endl;
		cout << "Treatment 1      " << treatment[i].treatment1 << endl;
		cout << "Treatment 2      " << treatment[i].treatment2 << endl;
		cout << "Treatment 3      " << treatment[i].treatment3 << endl;
		cout << endl;		
	}
}
