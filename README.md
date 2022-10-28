# RespEvalTreatProtocol

RespEvalTreatProtocol is a C++ application that generates the type and frequency of beathing treatments for a number of patients based on 
their clinical symptoms and medical history



## What I learned

- Implementing classes, structures, and functions in an object-based program

- Utilizing a random number generator to generate random numbers within a specified range

- Separating interface from implementation

- Validating input and formatting output



## How It Works

- After running the application, a patient's ID, vital signs, clinical symptoms, oxygen device, and medical history are displayed

- For each respiratory condition, the patient is scored using a random number generator and error messages are presented if the random number 
falls out of range

- The total score for each patient is used to determine the type of breathing treatments they will receive and how frequent they will receive them

- If the user types 'Y' or 'y', a different patient is presented with a new set of respiratory conditions

- If the user types anything other than 'Y' or 'y', the scores of every assessed patient are printed in a formatted table and their 
individual treatment plans are displayed underneath the table


![PatientAssessment](https://user-images.githubusercontent.com/104407388/198703432-5ade1dae-dfc5-4302-b400-7f7863ef828b.jpg)

![PatientReport](https://user-images.githubusercontent.com/104407388/198703444-873acf47-0fc4-4117-a9ce-e7e84ff1adc1.jpg)
