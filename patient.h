
#ifndef PATIENT_H
#define PATIENT_H

#include <string>

using std::string;

class Patient
{
	private:
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
		
	public:
		Patient();
		Patient(string);
		void setPatientData(string, int, int, int, int);
		void setPatientCough(int, int, int);
		void setPatientDevice(int, int, int);
		void setPatientOther(int, int, int, int);
		
		string getName();
		int getId();
		int getHeartRate();
		int getRespRate();
		int getBreathSounds();
		int getCoughType();
		int getCoughSecretions();
		int getCoughEffective();
		int getOxygenDevice();
		int getFlowLPM();
		int getPercentOxygen();
		int getDifficulty();
		int getChestXRay();
		int getSmoking();
		int getSurgery();
		
};

#endif // PATIENT_H
