
#include "patient.h"

Patient::Patient()
{
	name = "N/A", id = -1, heartRate = -1, respRate = -1, breathSounds = -1, 
		coughType = -1, coughSecretions = -1, coughEffective = -1; oxygenDevice = -1; 
		flowLPM = -1; percentOxygen = -1; difficulty = -1; chestXRay = -1, smoking = -1; 
		surgery = -1;	
}

Patient::Patient(string name)
{
	this->name = name;
}

void Patient::setPatientData(string newName, int newId, int newHR, int newRR, int newBS)
{
	name = newName;
	id = newId;
	heartRate = newHR;
	respRate = newRR;
	breathSounds = newBS;
}

void Patient::setPatientCough(int newCoughType, int newCoughSec, int newCoughEff)
{
	coughType = newCoughType;
	coughSecretions = newCoughSec;
	coughEffective = newCoughEff;
}

void Patient::setPatientDevice(int newDevice, int newFlowLPM, int newPercentO2)
{
	oxygenDevice = newDevice;
	flowLPM = newFlowLPM;
	percentOxygen = newPercentO2;
}

void Patient::setPatientOther(int newDifficulty, int newCXR, int newSmoking, int newSurgery)
{
	difficulty = newDifficulty;
	chestXRay = newCXR;
	smoking = newSmoking;
	surgery = newSurgery;
}

string Patient::getName()
{ return name; }

int Patient::getId()
{ return id; }

int Patient::getHeartRate()
{ return heartRate; }

int Patient::getRespRate()
{ return respRate; }

int Patient::getBreathSounds()
{ return breathSounds; }

int Patient::getCoughType()
{ return coughType; }

int Patient::getCoughSecretions()
{ return coughSecretions; }

int Patient::getCoughEffective()
{ return coughEffective; }

int Patient::getOxygenDevice()
{ return oxygenDevice; }

int Patient::getFlowLPM()
{ return flowLPM; }

int Patient::getPercentOxygen()
{ return percentOxygen; }

int Patient::getDifficulty()
{ return difficulty; }

int Patient::getChestXRay()
{ return chestXRay; }

int Patient::getSmoking()
{ return smoking; }

int Patient::getSurgery()
{ return surgery; }







