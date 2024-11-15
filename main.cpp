#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// struct for patient
struct patient_record
{
    int id;
    string name;
    int age;
    char gender;
    string diagnoses;
};

// struct for doctors
struct doctor_record
{
    int id;
    string name;
    string specialization;
};

// global variable that defines patient and doctor limit for our system...
const int max_patients = 100;
const int max_doctors = 25;

// function prototyping
int Menu();
void ADDPATIENTS(patient_record patient[], int &count); // pass count by reference
void DISPLAYPATIENTS(patient_record patients[], int count);
void ADDDOCTORS(doctor_record doctor[], int &counter); // pass counter by reference
void DISPLAYDOCTORS(doctor_record doctor[], int counter);

// main function
int main()
{
    // declaring variables for struct patient_record
    patient_record patient[max_patients];
    doctor_record doctor[max_doctors];
    int patient_count = 0;
    int doctor_count = 0;

    // switch case
    int option;
    do
    {
        option = Menu();
        switch (option)
        {
        case 1:
            if (patient_count < max_patients)
            {
                ADDPATIENTS(patient, patient_count);
                cout << "\nPatient added successfully..." << endl;
            }
            else
            {
                cout << "\nPatient limit has reached....." << endl;
            }
            break;
        case 2:

            DISPLAYPATIENTS(patient, patient_count);

            break;
        case 3:
            if (doctor_count < max_doctors)
            {
                ADDDOCTORS(doctor, doctor_count);
                cout << "\nDoctor added successfully..." << endl;
            }
            else
            {
                cout << "\nDoctor limit has reached..." << endl;
            }
            break;
        case 4:
            
                DISPLAYDOCTORS(doctor, doctor_count);
            
            
            break;
        case 5:
            cout << "EXITING..." << endl;
            return 0;
        default:
            cout << "Enter Valid option.." << endl;
            break;
        }
    } while (option != 5);

    return 0;
}

// function definitions
// for displaying menu
int Menu()
{
    int choice;
    cout << "Hospital Management System" << endl;
    cout << "1. Add a new patient" << endl;
    cout << "2. Display all patients" << endl;
    cout << "3. Add a new doctor" << endl;
    cout << "4. Display all doctors" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    return choice;
}

// for adding patients
void ADDPATIENTS(patient_record patient[], int &count)
{
    ofstream file;
    string PatientFileName = "patient.txt";
    file.open(PatientFileName, ios::app);
    cout << "\nREGISTERING PATIENT: " << endl;
    cout << "ID: ";
    cin >> patient[count].id;
    file << patient[count].id << endl;
    cout << "NAME: ";
    cin.ignore();
    getline(cin, patient[count].name);
    file << patient[count].name << endl;
    cout << "\nAGE: ";
    cin >> patient[count].age;
    file << patient[count].age << endl;
gender:
    cout << "\nGENDER: (F/M) ";
    cin >> patient[count].gender;
    file << patient[count].gender << endl;
    if (patient[count].gender != 'f' && patient[count].gender != 'm' && patient[count].gender != 'F' && patient[count].gender != 'M')
    {
        cout << "\nINVALID GENDER OPTION" << endl;
        goto gender;
    }
    cout << "DIAGNOSES: ";
    cin.ignore();
    getline(cin, patient[count].diagnoses);
    file << patient[count].diagnoses << endl;

    file.close();
    // incrementing counter after each patient is added
    count++;
}
// for adding doctors
void ADDDOCTORS(doctor_record doctor[], int &doc_count)
{
    ofstream file;
    string doctorFileName = "doctorfile.txt";

    file.open(doctorFileName, ios::app);

    cout << "\nREGISTERING DOCTOR: " << endl;
    cout << "ID: ";
    cin >> doctor[doc_count].id;
    file << doctor[doc_count].id << endl;
    cout << "NAME: ";
    cin.ignore();
    getline(cin, doctor[doc_count].name);
    file << doctor[doc_count].name << endl;
    cout << "SPECIALIZATION: ";
    getline(cin, doctor[doc_count].specialization);
    file << doctor[doc_count].specialization << endl;
    file.close();

    doc_count++;
}

void DISPLAYPATIENTS(patient_record patients[], int count)
{
    ifstream file;
    string PatientFileName = "patient.txt";
    file.open(PatientFileName, ios::in); // Open in read mode
    if (!file.is_open())
    {
        cout << "ERROR OPENING FILE..." << endl;
        return; // return from the function if the file cannot be opened
    }

    cout << "\nPRINTING PATIENT DATA......" << endl;

    while (file >> patients[count].id)
    {
        file.ignore(); // Ignore newline character left by previous file operation
        getline(file, patients[count].name);
        file >> patients[count].age;
        file >> patients[count].gender;
        file.ignore(); // Ignore newline character left by previous file operation
        getline(file, patients[count].diagnoses);

        cout << "Patient Id: " << patients[count].id << endl;
        cout << "Patient Name: " << patients[count].name << endl;
        cout << "Patient Age: " << patients[count].age << endl;
        cout << "Patient Gender: " << patients[count].gender << endl;
        cout << "Patient Diagnoses: " << patients[count].diagnoses << endl;

        count++;
    }

    file.close();
}

void DISPLAYDOCTORS(doctor_record doctor[max_doctors], int counter)
{
    ifstream file;
    string doctorFileName = "doctorfile.txt";

    file.open(doctorFileName, ios::in);
    if (!file.is_open())
    {
        cout << "ERROR OPENING FILE...." << endl;
        return;
    }
    cout << "\nPRINTING DOCTOR DATA....." << endl;
    while (file >> doctor[counter].id)
    {
        file.ignore();
        getline(file, doctor[counter].name);
        file.ignore();
        getline(file, doctor[counter].specialization);
        cout << "DOCTOR ID: " << doctor[counter].id << endl;
        cout << "DOCTOR NAME: " << doctor[counter].name << endl;
        cout << "DOCTOR SPECIALIZATION: " << doctor[counter].specialization << endl;
        counter++;
    }
    file.close();
}