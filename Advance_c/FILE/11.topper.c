/*11Write a program to read the above file and print who is topper.    */


#include <stdio.h>
struct student
{
	int id;
	char name[50];
	char dob[20];
	float marks;
};

int main() 
{
	int n, i;
	printf("Enter the number of students: ");
	scanf("%d", &n);
	struct student students[n];
	float highest_marks = 0;
	int topper_index = -1;

	for (i = 0; i < n; i++) {
		printf("Enter details of student %d\n", i + 1);
		printf("ID: ");
		scanf("%d", &students[i].id);
		printf("Name: ");
		scanf("%s", students[i].name);
		printf("Date of Birth (dd-mm-yyyy): ");
		scanf("%s", students[i].dob);
		printf("Marks: ");
		scanf("%f", &students[i].marks);
		if (students[i].marks > highest_marks) {   // Finding the topper
			highest_marks = students[i].marks;
			topper_index = i;
		}
	}

	FILE *file = fopen("student_details.csv", "w");
	if (file == NULL) 
	{
		printf("Error opening file.\n");
		return 1;
	}

	fprintf(file, "Id,Name,Date of Birth,Marks\n");
	for (i = 0; i < n; i++) 
	{
		fprintf(file, "%d,%s,%s,%.2f\n", students[i].id, students[i].name, students[i].dob, students[i].marks);
	}
	fclose(file);
	printf("Student details have been written to student_details.csv\n");

	if (topper_index != -1)
	{       // Print the details of the topper
		printf("Topper Details:\n");
		printf("ID: %d\n", students[topper_index].id);
		printf("Name: %s\n", students[topper_index].name);
		printf("Date of Birth: %s\n", students[topper_index].dob);
		printf("Marks: %.2f\n", students[topper_index].marks);

	}
	return 0;

}
