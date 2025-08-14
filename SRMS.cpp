#include<iostream>
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;

const int MAX_RECORDS = 100;
int studentCount = 0, facultyCount = 0, staffCount = 0;

struct Student {
    string name, gender, enrollmentNumber, activities, feeStatus;
    int semester;
    float gpa;
    bool attendance;
};
Student students[MAX_RECORDS]; 

struct Faculty {
    string name, gender, department, qualification, specialization, designation;
    int experience, salary, age;
};
Faculty faculty[MAX_RECORDS];

struct Staff {
    string name, gender, jobRole;
    float salary;
    string shift;
};
Staff staff[MAX_RECORDS];

      
string sampleNames[8][4] = {
    {"Ayesha Khan", "Bilal Ahmed", "Fatima Ali", "Hassan Raza"}, 
    {"Iqra Malik", "Junaid Abbas", "Kiran Shah", "Lubna Akhtar"}, 
    {"Mohsin Khan", "Nadia Hussain", "Omar Farooq", "Parveen Bibi"}, 
    {"Qasim Ali", "Rabia Khan", "Saad Malik", "Tahira Ahmed"}, 
    {"Usman Sheikh", "Zainab Raza", "Abdul Rehman", "Bushra Khan"},
    {"Danish Ali", "Fariha Khan", "Ghulam Abbas", "Hina Malik"}, 
    {"Imran Khan", "Javeria Ahmed", "Kamran Ali",}
}; 
    
string semesterCourses[8][5] = {
        {"Programming Fundamentals", "Applications of ICT", "Digital Logic Design", "Functional English", "Islamic Studies"},
        {"Object-Oriented Programming", "Discrete Structures", "Data Structures", "Communication Skills", "Pakistan Studies"},
        {"Database Systems", "Operating Systems", "Computer Networks", "Technical Writing", "Ethics"},
        {"Software Engineering", "Theory of Automata", "Web Development", "Linear Algebra", "Islamic Ethics"},
        {"Artificial Intelligence", "Data Science", "Mobile App Development", "Probability & Statistics", "Quranic Studies"},
        {"Machine Learning", "Cloud Computing", "Cyber Security", "Numerical Analysis", "Hadith Studies"},
        {"Big Data Analytics", "Blockchain Technology", "DevOps", "Research Methodology", "Islamic Jurisprudence"},
        {"Capstone Project", "Advanced Algorithms", "Internet of Things", "Professional Practices", "Tafsir"}
    };
  
string intToString(int value) {
    char buffer[20];
    sprintf(buffer, "%d", value); 
    return string(buffer);
}

string floatToString(float value) {
    char buffer[20]; 
    sprintf(buffer, "%.2f", value); 
    return string(buffer);
}

void displayHeader() {
    cout << "============================================" << endl;
    cout << "       EDUCATIONAL MANAGEMENT SYSTEM" << endl;
    cout << "============================================" << endl;
}

void sampleStudentData(){


for (int sem = 1; sem <= 8; sem++) {
    for (int i = 0; i < 4; i++) { 
        students[studentCount].name = sampleNames[sem - 1][i] ;
        students[studentCount].gender = (i % 2 == 0) ? "Female" : "Male"; 
        students[studentCount].semester = sem;
        students[studentCount].enrollmentNumber = "EN" + intToString(sem) + "00" + intToString(i + 1);
        students[studentCount].gpa = 3.5 + (i % 4) * 0.5; 
        students[studentCount].activities = "Sports, Debate";
        students[studentCount].attendance = (i % 2 == 0); 
        students[studentCount].feeStatus = (i % 2 == 0) ? "Paid" : "Pending";
        studentCount++;
    }
}
}
void addStudent() {
	cout<<"------DEPARTMENT OF BS SOFTWARE ENGINEERING------"<<endl;
    if (studentCount < MAX_RECORDS) {
        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, students[studentCount].name);
        cout << "Enter Gender: ";
        getline(cin, students[studentCount].gender);
        cout << "Enter Semester (1-8): ";
        while (!(cin >> students[studentCount].semester) || students[studentCount].semester < 1 || students[studentCount].semester > 8) {
            cout << "Invalid semester! Please enter between 1 and 8: ";
            cin.clear();
            cin.ignore(123, '\n');
        }
        cin.ignore();

        cout << "Enter Enrollment Number: ";
        getline(cin, students[studentCount].enrollmentNumber);
        cout << "Enter your intermediate percentage: ";
        cin >> students[studentCount].gpa;
        cin.ignore();
        cout << "Enter Extracurricular Activities: ";
        getline(cin, students[studentCount].activities);
        students[studentCount].attendance = false;
        students[studentCount].feeStatus = "Pending";

        studentCount++;
        cout << "Student added successfully to semester " << students[studentCount - 1].semester << "." << endl;
    } else {
        cout << "No more students can be added." << endl;
    }
    cout << endl << endl;
}

void markAttendance() {
    cin.ignore();
    string enrollmentNumber;
    cout << "Enter Enrollment Number to Mark Attendance: ";
    getline(cin, enrollmentNumber);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].enrollmentNumber == enrollmentNumber) {
            students[i].attendance = true;
            cout << "Attendance marked successfully." << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

void updateFeeStatus() {
    cin.ignore();
    string enrollmentNumber;
    cout << "Enter Enrollment Number to Update Fee Status: ";
    getline(cin, enrollmentNumber);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].enrollmentNumber == enrollmentNumber) {
            cout << "Enter Fee Status (Paid/Pending): ";
            getline(cin, students[i].feeStatus);
            cout << "Fee status updated successfully." << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

void searchStudent() {
    string enrollmentNumber;
    cout << "Enter Enrollment Number: ";
    cin.ignore();
    getline(cin, enrollmentNumber);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].enrollmentNumber == enrollmentNumber) {
            cout << "Student Found:\n";
            cout << "Name: " << students[i].name << endl;
            cout << "Gender: " << students[i].gender << endl;
            cout << "Semester: " << students[i].semester << endl;
            cout << "Fee Status: " << students[i].feeStatus << endl;
            cout << "GPA: " << students[i].gpa << endl;
            cout << "Activities: " << students[i].activities << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

void editStudentRecord() {
    string enrollmentNumber;
    cout << "Enter Enrollment Number of Student to Edit: ";
    cin.ignore();
    getline(cin, enrollmentNumber);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].enrollmentNumber == enrollmentNumber) {
            int choice;
            cout << "What do you want to edit?" << endl;
            cout << "1. Name\n2. Gender\n3. Semester\n4. GPA\n5. Activities\n6. Attendance\n7. Fee Status\nEnter choice: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    cout << "Enter New Name: ";
                    getline(cin, students[i].name);
                    break;
                case 2:
                    cout << "Enter New Gender: ";
                    getline(cin, students[i].gender);
                    break;
                case 3:
                    cout << "Enter New Semester (1-8): ";
                    cin >> students[i].semester;
                    cin.ignore();
                    break;
                case 4:
                    cout << "Enter New GPA: ";
                    cin >> students[i].gpa;
                    cin.ignore();
                    break;
                case 5:
                    cout << "Enter New Extracurricular Activities: ";
                    getline(cin, students[i].activities);
                    break;
                case 6:
                    cout << "Mark Attendance (1 for Present, 0 for Absent): ";
                    int att;
                    cin >> att;
                    students[i].attendance = (att == 1);
                    break;
                case 7:
                    cout << "Enter Fee Status (Paid/Pending): ";
                    getline(cin, students[i].feeStatus);
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
            cout << "Student record updated successfully!" << endl;
            return;
        }
    }
    cout << "Student not found!" << endl;
}

void displayCourse() {
    int semester;
    string semesterCourses[8][5] = {
        {"Programming Fundamentals", "Applications of ICT", "Digital Logic Design", "Functional English", "Islamic Studies"},
        {"Object-Oriented Programming", "Discrete Structures", "Data Structures", "Communication Skills", "Pakistan Studies"},
        {"Database Systems", "Operating Systems", "Computer Networks", "Technical Writing", "Ethics"},
        {"Software Engineering", "Theory of Automata", "Web Development", "Linear Algebra", "Islamic Ethics"},
        {"Artificial Intelligence", "Data Science", "Mobile App Development", "Probability & Statistics", "Quranic Studies"},
        {"Machine Learning", "Cloud Computing", "Cyber Security", "Numerical Analysis", "Hadith Studies"},
        {"Big Data Analytics", "Blockchain Technology", "DevOps", "Research Methodology", "Islamic Jurisprudence"},
        {"Capstone Project", "Advanced Algorithms", "Internet of Things", "Professional Practices", "Tafsir"}
    };

    cout << "Enter semester (1-8) to see courses accordingly: ";
    cin >> semester;

    if (semester < 1 || semester > 8) {
        cout << "Invalid semester!" << endl;
        return;
    }

    cout << "=============================================================================================================" << endl;
    cout << "                                      DEPARTMENT OF BS SOFTWARE ENGINEERING                                  " << endl;
    cout << "=============================================================================================================" << endl;
    cout << "|                                      Semester " << semester << " Courses                                                  |" << endl;
    cout << "=============================================================================================================" << endl;
    
    for (int i = 0; i < 5; i++) {
        cout << "- " << semesterCourses[semester - 1][i] << endl;
    }
}

void displayStudentsBySemester() {
	
    int semester;
    cout << "Enter Semester to display records (1-8): ";
    cin >> semester;

    if (semester < 1 || semester > 8) {
        cout << "Invalid semester!" << endl;
        return;
    }
    cout << "============================================================================================================="<<endl;
    cout << "                                      DEPARTMENT OF BS SOFTWARE ENGINEERING                                  "<<endl;
    cout << "=============================================================================================================" << endl;
    cout << "|                                      Semester " << semester << " Students                                                 |" << endl;
    cout << "=============================================================================================================" << endl;
    cout << "| Sr. No | Student Name        | Gender | Semester | Enrollment | GPA  | Fee Status | Activities           |" << endl;
    cout << "=============================================================================================================" << endl;

    bool found = false;
    int srNo = 1; 

    for (int i = 0; i < studentCount; i++) {
        if (students[i].semester == semester) {
            found = true;
            cout << "| " << setw(6) << srNo++ << " | "  
                 << setw(19) << students[i].name << " | "
                 << setw(6) << students[i].gender << " | "
                 << setw(8) << students[i].semester << " | "
                 << setw(10) << students[i].enrollmentNumber << " | "
                 << setw(4) << fixed << setprecision(2) << students[i].gpa << " | " 
                 << setw(10) << students[i].feeStatus << " | "
                 << setw(16) << students[i].activities << " |" << endl;
        }
    }

    if (!found) {
        cout << "| No students found in semester " << semester << "                                               |" << endl;
    }

    cout << "=============================================================================================================" << endl;
}


void displayStudentAttendance() {

    
	int semester;
    cout << "Enter semester (1-8) to see student attendance: ";
    cin >> semester;

    if (semester < 1 || semester > 8) {
        cout << "Invalid semester!" << endl;
        return;
    }

    cout << "Attendance for Semester " << semester << " Students:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << sampleNames[semester - 1][i] << ": " << (students[i].attendance ? "Present" : "Absent") << endl;
    }
}

void deleteStudent() {
    cin.ignore();
    string enrollmentNumber;
    cout << "Enter Enrollment Number of Student to Delete: ";
    getline(cin, enrollmentNumber);
    for(int i = 0; i < studentCount; i++) {
        if(students[i].enrollmentNumber == enrollmentNumber) {
            for(int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            cout << "Student record deleted successfully."<<endl;
            return;
        }
    }
    cout << "Student not found."<<endl;
}

void addFaculty() {
    if (facultyCount < MAX_RECORDS) {
        cin.ignore();
        cout << "Enter Faculty Name: ";
        getline(cin, faculty[facultyCount].name);
        cout << "Enter Gender: ";
        getline(cin, faculty[facultyCount].gender);
        cout << "Enter Age: ";
        cin >> faculty[facultyCount].age;
        cin.ignore();
        cout << "Enter Department: ";
        getline(cin, faculty[facultyCount].department);
        cout << "Enter Qualification: ";
        getline(cin, faculty[facultyCount].qualification);
        cout << "Enter Specialization: ";
        getline(cin, faculty[facultyCount].specialization);
        cout << "Enter Years of Experience: ";
        cin >> faculty[facultyCount].experience;
        cin.ignore();
        cout << "Enter Designation (Professor/Associate Professor/Lecturer): ";
        getline(cin, faculty[facultyCount].designation);

        if (faculty[facultyCount].designation == "Professor")
            faculty[facultyCount].salary = 150000;
        else if (faculty[facultyCount].designation == "Associate Professor")
            faculty[facultyCount].salary = 120000;
        else if (faculty[facultyCount].designation == "Lecturer")
            faculty[facultyCount].salary = 90000;
        else {
            faculty[facultyCount].salary = 80000;
        }

        facultyCount++;
        cout << "Faculty added successfully." << endl;
    } else {
        cout << "No more faculty can be added." << endl;
    }
}
void samplefacultydata(){

 // Sample data for faculty (8 faculty members)
    string facultyNames[] = {"Dr. Ayesha Khan", "Dr. Fatima Ahmed", "Dr. Sana Ali", "Dr. Hina Raza", "Dr. Mariam Shah", "Dr. Zainab Malik", "Dr. Farah Iqbal", "Dr. Nida Hussain"};
    string departments[] = {"Computer Science", "Mathematics", "Physics", "Chemistry", "Biology", "English", "Economics", "Psychology"};
    string qualifications[] = {"PhD", "PhD", "PhD", "PhD", "PhD", "PhD", "PhD", "PhD"};
    string specializations[] = {"AI", "Algebra", "Quantum Physics", "Organic Chemistry", "Genetics", "Literature", "Microeconomics", "Clinical Psychology"};

    for (int i = 0; i < 8; i++) {
        faculty[facultyCount].name = facultyNames[i];
        faculty[facultyCount].gender = "Female";
        faculty[facultyCount].age = 35 + i;
        faculty[facultyCount].department = departments[i];
        faculty[facultyCount].qualification = qualifications[i];
        faculty[facultyCount].specialization = specializations[i];
        faculty[facultyCount].experience = 10 + i;
        faculty[facultyCount].designation = (i % 3 == 0) ? "Professor" : (i % 3 == 1) ? "Associate Professor" : "Lecturer";
        faculty[facultyCount].salary = (faculty[facultyCount].designation == "Professor") ? 150000 : (faculty[facultyCount].designation == "Associate Professor") ? 120000 : 90000;
        facultyCount++;
    }
}
void editFacultyRecord() {
    string name;
    cout << "Enter Faculty Name to Edit: ";
    cin.ignore();
    getline(cin, name);

    for (int i = 0; i < facultyCount; i++) {
        if (faculty[i].name == name) {
            int choice;
            cout << "What do you want to edit?" << endl;
            cout << "1. Name\n2. Gender\n3. Department\n4. Qualification\n5. Specialization\n6. Experience\nEnter choice: ";
            cin >> choice;
            cin.ignore();

            switch (choice) {
                case 1:
                    cout << "Enter New Name: ";
                    getline(cin, faculty[i].name);
                    break;
                case 2:
                    cout << "Enter New Gender: ";
                    getline(cin, faculty[i].gender);
                    break;
                case 3:
                    cout << "Enter New Department: ";
                    getline(cin, faculty[i].department);
                    break;
                case 4:
                    cout << "Enter New Qualification: ";
                    getline(cin, faculty[i].qualification);
                    break;
                case 5:
                    cout << "Enter New Specialization: ";
                    getline(cin, faculty[i].specialization);
                    break;
                case 6:
                    cout << "Enter New Experience (Years): ";
                    cin >> faculty[i].experience;
                    cin.ignore();
                    break;
                default:
                    cout << "Invalid choice!" << endl;
            }
            cout << "Faculty record updated successfully!" << endl;
            return;
        }
    }
    cout << "Faculty not found!" << endl;
}
void deleteFaculty() {
	
    cin.ignore();
    string name;
    cout << "Enter Name of Faculty to Delete: ";
    getline(cin, name);
    for(int i = 0; i < facultyCount; i++) {
        if(faculty[i].name == name) {
            for(int j = i; j < facultyCount - 1; j++) {
                faculty[j] = faculty[j + 1];
            }
            facultyCount--;
            cout << "Faculty record deleted successfully."<<endl;
            return;
        }
    }
    cout << "Faculty not found."<<endl;
}
void displayFaculty() {
    int record = facultyCount;
    if (record > 0) {
        cout << endl << "Faculty:" << endl;
        cout << "===================================================================================================================" << endl;
        cout << left << setw(15) << "  Name" << setw(10) << "  Gender" << setw(15) << "  Department" 
             << setw(20) << "   Qualification" << setw(20) << "Specialization" << setw(10) << "  Experience" 
             << setw(10) << "    Age" << "      Salary" << endl;
        cout << "===================================================================================================================" << endl;
        for (int i = 0; i < facultyCount; i++) {
            cout << left << setw(17) << faculty[i].name << setw(10) << faculty[i].gender 
                 << setw(17) << faculty[i].department << setw(18) << faculty[i].qualification 
                 << setw(24) << faculty[i].specialization << setw(10) << faculty[i].experience 
                 << setw(12) << faculty[i].age << faculty[i].salary << endl;
        }
    } else {
        cout << "No record found!!!";
    }
}

void facultyOperations() {
    int choice;
    do {
        cout << "\nFaculty Operations:\n";
        cout << "1. Add Faculty\n";
        cout << "2. Display Faculty\n";
        cout << "3. Edit Faculty Record\n";
        cout << "4. Delete Faculty\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: addFaculty(); break;
            case 2: displayFaculty(); break;
            case 3: editFacultyRecord(); break;
            case 4: deleteFaculty(); break;
            case 0: break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 0);
}


void addStaff() {
    if (staffCount < MAX_RECORDS) {
        cin.ignore();
        cout << "Enter Staff Name: ";
        getline(cin, staff[staffCount].name);
        cout << "Enter Gender: ";
        getline(cin, staff[staffCount].gender);

        int jobRoleChoice;
        do {
            cout << "Choose Job Role:" << endl;
            cout << "1. Administrative Staff" << endl;
            cout << "2. Technical Staff" << endl;
            cout << "3. Support Staff" << endl;
            cout << "Enter choice (1-3): ";
            cin >> jobRoleChoice;
            cin.ignore();
            if (jobRoleChoice == 1) {
                staff[staffCount].jobRole = "Administrative Staff";
                staff[staffCount].salary = 60000;
            } else if (jobRoleChoice == 2) {
                staff[staffCount].jobRole = "Technical Staff";
                staff[staffCount].salary = 80000;
            } else if (jobRoleChoice == 3) {
                staff[staffCount].jobRole = "Support Staff";
                staff[staffCount].salary = 40000;
            } else {
                cout << "Invalid choice. Please select a valid job role.\n";
            }
        } while (!(jobRoleChoice >= 1 && jobRoleChoice <= 3));

        cout << "Enter Shift (Morning/Evening/Night): ";
        getline(cin, staff[staffCount].shift);

        staffCount++;
        cout << "Staff added successfully." << endl;
    } else {
        cout << "No more staff can be added." << endl;
    }
}

void samplestaffddata(){
// Sample data for staff (5 staff members)
    string staffNames[] = {"Sara Ahmed", "Amina Khan", "Zara Ali", "Hira Raza", "Nadia Shah"};
    string jobRoles[] = {"Administrative Staff", "Technical Staff", "Support Staff", "Administrative Staff", "Technical Staff"};
    string shifts[] = {"Morning", "Evening", "Night", "Morning", "Evening"};

    for (int i = 0; i < 5; i++) {
        staff[staffCount].name = staffNames[i];
        staff[staffCount].gender = "Female";
        staff[staffCount].jobRole = jobRoles[i];
        staff[staffCount].salary = (staff[staffCount].jobRole == "Administrative Staff") ? 60000 : (staff[staffCount].jobRole == "Technical Staff") ? 80000 : 40000;
        staff[staffCount].shift = shifts[i];
        staffCount++;
    }}

void editStaff() {
    string name;
    cout << "Enter Staff Name to Edit: ";
    cin.ignore();
    getline(cin, name);

    for (int i = 0; i < staffCount; i++) {
        if (staff[i].name == name) {
            int choice;
            cout << "1. Update Shift Timings" << endl;
            cout << "2. Update Salary" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            cin.ignore();

            if (choice == 1) {
                cout << "Enter New Shift Timings: ";
                getline(cin, staff[i].shift);
            } else if (choice == 2) {
                cout << "Enter New Salary: ";
                cin >> staff[i].salary;
                cin.ignore();
            } else {
                cout << "Invalid choice!" << endl;
                return;
            }
            cout << "Staff record updated successfully!" << endl;
            return;
        }
    }
    cout << "Staff member not found!" << endl;
}	
void deleteStaff() {
    cin.ignore();
    string name;
    cout << "Enter Name of Staff to Delete: ";
    getline(cin, name);
    for(int i = 0; i < staffCount; i++) {
        if(staff[i].name == name) {
            for(int j = i; j < staffCount - 1; j++) {
                staff[j] = staff[j + 1];
            }
            staffCount--;
            cout << "Staff record deleted successfully."<<endl;
            return;
        }
    }
    cout << "Staff not found."<<endl;
}
void displayStaff() {
    if (staffCount > 0) {
        cout << endl << "Staff Members:" << endl;
        cout << "==================================================================================" << endl;
        cout << left << setw(15) << "Name" << setw(10) << "Gender" << setw(15) << "Job Role"
             << setw(12) << "       Salary" << setw(15) << "      Shift Timings" << endl;
        cout << "==================================================================================" << endl;

        for (int i = 0; i < staffCount; i++) {
            cout << left << setw(15) << staff[i].name << setw(10) << staff[i].gender 
                 << setw(22) << staff[i].jobRole << setw(12) << staff[i].salary 
                 << setw(23) << staff[i].shift << endl;
        }
    } else {
        cout << "No staff records found!" << endl;
    }
}
void staffOperations() {
    int choice;
    do {
        cout << "\nStaff Operations:\n";
        cout << "1. Add Staff\n";
        cout << "2. Display Staff\n";
        cout << "3. Edit Staff Record\n";
        cout << "4. Delete Staff\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: addStaff(); break;
            case 2: displayStaff(); break;
            case 3: editStaff(); break;
            case 4: deleteStaff(); break;
            case 0: break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 0);
}

int main() {
    displayHeader();
    int mainChoice;
    
    sampleStudentData();
    samplestaffddata();
    samplefacultydata();

    do {
        cout << "\nMain Menu:\n";
        cout << "1. Student Operations\n";
        cout << "2. Faculty Operations\n";
        cout << "3. Staff Operations\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1: {
                int studentChoice;
                do {
                    cout << "\nStudent Operations:\n";
                    cout << "1. Add Student\t";
                    cout << "\t2. Display Students by Semester\n";
                    cout << "3. Attendance\t";
                    cout << "\t4. Update Fee Status\n";
                    cout << "5. Search Student\t";
                    cout << "6. Edit Student Record\n";
                    cout << "7. Delete Student\t";
                    cout << "8. Display Courses\n";
                    cout << "0. Back to Main Menu\n";
                    cout << "Enter choice: ";
                    cin >> studentChoice;

                    switch (studentChoice) {
                        case 1: addStudent(); break;
                        case 2: displayStudentsBySemester(); break;
                        case 3:
						{
						  cout<<"1.Mark Attendance"<<endl;
						  cout<<"2.display Attendance"<<endl;
						  cin>>studentChoice;
						  if(studentChoice==1)
						  {
						  markAttendance();
					      }
					      else if(studentChoice==2){
					      	displayStudentAttendance();
						  }
					}
						  break;
                        case 4: updateFeeStatus(); break;
                        case 5: searchStudent(); break;
                        case 6: editStudentRecord(); break;
                        case 7: deleteStudent(); break;
                        case 8: displayCourse(); break;
                        case 0: break;
                        default: cout << "Invalid choice!\n";
                    }
                } while (studentChoice != 0);
                break;
            }
            
            case 2: facultyOperations(); break;
            case 3: staffOperations(); break;
            case 0: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (mainChoice != 0);

    return 0;
}
