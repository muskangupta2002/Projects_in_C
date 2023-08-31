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
    {"Question 1: What is this", {"Option A", "Option B", "Option C", "Option D"}, 1},
    {"Question 2: What is this", {"Option A", "Option B", "Option C", "Option D"}, 1},
    {"Question 3: What is this", {"Option A", "Option B", "Option C", "Option D"}, 1},
    {"Question 4: What is this", {"Option A", "Option B", "Option C", "Option D"}, 1},
    {"Question 5: What is this", {"Option A", "Option B", "Option C", "Option D"}, 1}
    
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
    time_t endTime = startTime + 1 * 60; // 30 minutes time limit

    while (currentQuestion < 5 && time(NULL) < endTime) {
        printf("Question %d:\n", currentQuestion + 1);
        displayQuestion(questions[currentQuestion]);
        int choice = getUserChoice();

        if (choice == questions[currentQuestion].correct_option) {
            user.marks++;
        }

        currentQuestion++; // Move to the next question

        if (time(NULL) >= endTime) {
            printf("\nTime's up! Test closed.\n");
            break;
        }
    }

    int elapsedTime = time(NULL) - startTime;

    FILE *marksFile = fopen("marks.txt", "a");
    if (marksFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(marksFile, "Name: %s\nRoll Number: %d\nMarks: %d\nTime taken: %d seconds\n\n",
            user.name, user.roll_number, user.marks, elapsedTime);

    fclose(marksFile);

    printf("Test completed! Your marks have been recorded.\n");

    return 0;
}
