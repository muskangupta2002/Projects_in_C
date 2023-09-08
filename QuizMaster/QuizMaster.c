#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // for sleep function

typedef struct {
    char question[1000];
    char options[4][100];
    int correct_option;
} Question;

typedef struct {
    char name[100];
    int roll_number;
    int marks;
} User;

Question questions[5] = {
    {"Question 1: Who is the father of C language?", {"Steve Jobs", "James Gosling", "Dennis Ritchie", "Rasmus Lerdorf"}, 3},
    {"Question 2: Which of the following is not a valid C variable name?", {"int number;", "float rate;", "int variable_count;", "int $main;"}, 4},
    {"Question 3: Which is valid C expression?", {"int my_num = 100,000;", "int my_num = 100000;", "int my num = 1000;", "int $my_num = 10000;"}, 2},
    {"Question 4: Which of the following cannot be a variable name in C?", {"volatile", "true", "friend", "export"}, 2},
    {"Question 5: Which keyword is used to prevent any changes in the variable within a C program?", {"immutable", "mutable", "const", "volatile"}, 3}
    
};

void displayQuestion(Question q) {
    printf("%s\n", q.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}

int getUserChoice() {
    int choice;
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    User user;
    printf("Enter your name: ");
    scanf("%s", user.name);
    printf("Enter your roll number: ");
    scanf("%d", &user.roll_number);
    user.marks = 0;
    int currentQuestion = 0; // Initialize the question index
    time_t startTime = time(NULL);
    time_t endTime = startTime + 1 * 60; // 1 minute time limit

    while (currentQuestion < 5 && time(NULL) < endTime) {
        printf("Question %d:\n", currentQuestion + 1);
        displayQuestion(questions[currentQuestion]);

        int choice;
        if (time(NULL) <= endTime)
        {
            choice = getUserChoice();
        }

        if (time(NULL) <= endTime)
        {
            if (choice == questions[currentQuestion].correct_option)
            {
                user.marks++;
            }
        
        }
        currentQuestion++; // Move to the next question

        if (time(NULL) >= endTime)
        {
            printf("\nTime's up! Test closed.\n");
            break;
        }
    }

    int elapsedTime = time(NULL) - startTime;  // time taken to complete the test

    FILE *marksFile = fopen("marks.txt", "a");
    if (marksFile == NULL) {
        printf("Error!! Your marks could not be recorded.\n");
        return 1;
    }

    fprintf(marksFile, "Name: %s\nRoll Number: %d\nMarks: %d\nTime taken: %d seconds\n\n",
            user.name, user.roll_number, user.marks, elapsedTime);  // saving the marks in text file

    fclose(marksFile);

    printf("Test completed! Your marks have been recorded.\n");

    return 0;
}
