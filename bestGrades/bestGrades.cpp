#include <iostream>
#include <fstream>
#include <string>

struct bestStudent {
	std::string studentSurname;
	double studentAvg;
};

int main()
{
	FILE* students = fopen("students.txt", "r+");
	if (students == NULL) {
		std::cout << "Error: the file wasn't found.";
		return -1;
	}
	char surname[13];
	int groupNumber, mathGrade, physicsGrade, programmingGrade, index = 0;
	double avgGrade;
	bestStudent topGrades[10];
	topGrades[0].studentAvg = 0;
	while (fscanf(students, "%[^,], %d, %d, %d, %d; ", surname, &groupNumber, &mathGrade, &physicsGrade, &programmingGrade) == 5) {
		avgGrade = (mathGrade + physicsGrade + programmingGrade) / 3.0;
		if (avgGrade > topGrades[index].studentAvg) {
			index = 0;
			topGrades[index].studentAvg = avgGrade;
			topGrades[index].studentSurname = surname;
		}
		else if (avgGrade == topGrades[index].studentAvg) {
			index++;
			topGrades[index].studentAvg = avgGrade;
			topGrades[index].studentSurname = surname;
		}
	}
	fclose(students);
	students = fopen("students.txt", "a");
	fprintf(students, "\nBest students: ");
	for (int i = 0; i <= index; i++) {
		std::cout << topGrades[i].studentSurname << " ";
		fprintf(students, "%s ", topGrades[i].studentSurname.c_str());
	}
	fclose(students);
	return 0;
}