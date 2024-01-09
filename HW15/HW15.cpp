#include <iostream>
#include <string>

const int numOfMarks = 4;
struct Student {
    std::string name;
    unsigned marks[numOfMarks];
};

double averageMark(const Student& student) {
    unsigned sum = 0;
    for (int i = 0; i < numOfMarks; ++i) {
        sum += student.marks[i];
    }
    return sum / 4.0;
}
void bubbleSortStudents(Student students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; ++i) {
        for (int j = 0; j < numStudents - i - 1; ++j) {
            if (averageMark(students[j]) > averageMark(students[j + 1])) {
                std::swap(students[j], students[j + 1]);
            }
        }
    }
}

const Student* findMostSuccessfulStudent(const Student students[], int numStudents) {
    const Student* mostSuccessful = &students[0];
    double mostSuccessfulMark = averageMark(*mostSuccessful);

    for (int i = 1; i < numStudents; ++i) {
        double currentMark = averageMark(students[i]);

        if (currentMark > mostSuccessfulMark) {
            mostSuccessful = &students[i];
            mostSuccessfulMark = currentMark;
        }
    }
    return mostSuccessful;
}

int averageMarkAbove75Percent(const Student students[], int numStudents) {
    int count = 0;
    for (int i = 0; i < numStudents; ++i) {
        if (averageMark(students[i]) > 75.0) {
            ++count;
        }
    }
    return count;
}

int main()
{
    const int numStudents = 4;

    Student students[numStudents] = {
       {"Jane", {100, 87, 95, 67}},
       {"Diana", {100, 91, 56, 48}},
       {"Roman", {46, 99, 62, 83}},
       {"Luke", {68, 64, 100, 99}}
    };

    for (int i = 0; i < numStudents; ++i) {
        std::cout << students[i].name << "'s Average Mark: " << averageMark(students[i]) << std::endl;
    }
    std::cout << std::endl;

    const Student* mostSuccessfulStudent = findMostSuccessfulStudent(students, numStudents);
    std::cout << "Most Successful Student: " << mostSuccessfulStudent->name << std::endl;

    std::cout << std::endl;

    int countAbove75Percent = averageMarkAbove75Percent(students, 4);
    std::cout << "Number of students with an average mark above 75%: " << countAbove75Percent << std::endl;
}