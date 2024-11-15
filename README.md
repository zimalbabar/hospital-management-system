# Hospital Management System (HMS)

This **Hospital Management System (HMS)** is a simple, console-based application built in **C++**. It helps manage patient and doctor records, allowing users to add new entries, view existing records, and maintain a persistent data store in text files.


## Features

- **Add New Patient**  
  Register a patient with the following details:
  - Patient ID
  - Name
  - Age
  - Gender
  - Diagnoses  
  Data is saved in a file for persistence.

- **Display All Patients**  
  View the details of all registered patients.

- **Add New Doctor**  
  Register a doctor with the following details:
  - Doctor ID
  - Name
  - Specialization  

- **Display All Doctors**  
  View the details of all registered doctors.

All data is stored in text files (`patient.txt` and `doctorfile.txt`), ensuring no loss of information between program executions.


## File Structure

- **Files**:
  - `patient.txt`: Stores patient records (one record per line).
  - `doctorfile.txt`: Stores doctor records (one record per line).
  
- **Code File**:
  - `hospital_management.cpp`: Contains the complete implementation of the HMS, including functions for adding and displaying records.


## How to Use

1. **Run the program** and select an option from the menu:
   - **Option 1**: Add a new patient.
   - **Option 2**: Display all registered patients.
   - **Option 3**: Add a new doctor.
   - **Option 4**: Display all registered doctors.
   - **Option 5**: Exit the program.


## Code Overview

### Core Structures

1. **`patient_record`**  
   Stores information about a patient:
   - `int id`: Unique identifier for the patient.
   - `string name`: Full name of the patient.
   - `int age`: Age of the patient.
   - `char gender`: Gender of the patient (`M` or `F`).
   - `string diagnoses`: Medical diagnoses of the patient.

2. **`doctor_record`**  
   Stores information about a doctor:
   - `int id`: Unique identifier for the doctor.
   - `string name`: Full name of the doctor.
   - `string specialization`: Doctor's area of expertise.


### Main Functions

1. **`int Menu()`**  
   Displays the main menu and returns the user's choice.

2. **`void ADDPATIENTS(patient_record patient[], int &count)`**  
   - Registers a new patient.
   - Saves the patient's details to the `patient.txt` file.
   - Updates the `count` of patients.

3. **`void DISPLAYPATIENTS(patient_record patients[], int count)`**  
   - Reads and displays all patient records from `patient.txt`.

4. **`void ADDDOCTORS(doctor_record doctor[], int &doc_count)`**  
   - Registers a new doctor.
   - Saves the doctor's details to the `doctorfile.txt` file.
   - Updates the `doc_count` of doctors.

5. **`void DISPLAYDOCTORS(doctor_record doctor[], int counter)`**  
   - Reads and displays all doctor records from `doctorfile.txt`.



## Requirements

### Software
- **C++ Compiler**  
  - Example: GCC.

### Files
- Ensure the following files are in the same directory as the compiled executable:
  - `patient.txt`: Used to store patient records.
  - `doctorfile.txt`: Used to store doctor records.  
  *(These files will be created automatically if they don’t exist.)*
