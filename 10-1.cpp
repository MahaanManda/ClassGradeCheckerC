#include <iostream>
#include <string>

using namespace std;

//class
class StudentType {
public:
    void setStudentFName(string fName);
    void setStudentLName(string lName);
    void setTestScore(int score);
    void setGrade(int testScore);
    int getTestScore();
    string getStudentFName();
    string getStudentLName();
    char getGrade();

private:
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

//function prototypes
int findHighestScore(StudentType student[], int size);
void printStudentsWithHighestScore(StudentType student[], int size, int highest);
void printStudentNames(StudentType student[], int size);

int main() {
    int size = 4;
    StudentType student[size];
    int highest = 0; // Move the declaration of highest here

    for (int i = 0; i < size; i++) {
        string fName, lName;
        int score;

        cout << "Enter student's first name: ";
        cin >> fName;
        student[i].setStudentFName(fName);

        cout << "Enter student's last name: ";
        cin >> lName;
        student[i].setStudentLName(lName);

        cout << "Enter student's test score: ";
        cin >> score;
        student[i].setTestScore(score);
        student[i].setGrade(score);
}
//end of loop
    printStudentNames(student, size);
    highest = findHighestScore(student, size);
    printStudentsWithHighestScore(student, size, highest);

    return 0;
}










//function definitions
int findHighestScore(StudentType student[], int size) {
    int highest = 0;
    for (int i = 0; i < size; i++) {
        if (student[i].getTestScore() > highest) {
            highest = student[i].getTestScore();
        }
    }
    return highest;
}

void printStudentsWithHighestScore(StudentType student[], int size, int highest) { 
    cout << "Students with the highest scores: " << endl;
    for (int i = 0; i < size; i++) {
        if (student[i].getTestScore() == highest) {
            cout << student[i].getStudentLName() << ", " << student[i].getStudentFName() << ", " << student[i].getTestScore() << ", " << student[i].getGrade() << endl;
        }
    }
}

void printStudentNames(StudentType student[], int size) {
        cout << "Students' names: " << endl;
        for (int i = 0; i < size; i++) {
        cout << student[i].getStudentLName() << ", " << student[i].getStudentFName() << endl;
    }
}





//class member function definitions

void StudentType::setStudentFName(string fName) {
    studentFName = fName;
}

void StudentType::setStudentLName(string lName) {
    studentLName = lName;
}

void StudentType::setTestScore(int score) {
    testScore = score;
}

void StudentType::setGrade(int testScore) {
    if (testScore >= 90) {
        grade = 'A';
    } else if (testScore >= 80) {
        grade = 'B';
    } else if (testScore >= 70) {
        grade = 'C';
    } else if (testScore >= 60) {
        grade = 'D';
    } else {
        grade = 'F';
    }
}

int StudentType::getTestScore() {
    return testScore;
}

string StudentType::getStudentFName() {
        return studentFName;
    }
string StudentType::getStudentLName() {
        return studentLName;
    }
char StudentType::getGrade() {
        return grade;
    }
