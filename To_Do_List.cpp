#include <cstdio>
#include <vector>
#include <cstdlib> // for atoi

using namespace std;

// Function prototypes
void addTask(vector<string> &tasks);
void viewTasks(const vector<string> &tasks);
void deleteTask(vector<string> &tasks);

int main() {
    vector<string> tasks; // Vector to store tasks

    while (true) {
        // Display menu
        printf("\n======= TO-DO LIST MANAGER =======\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");

        // Prompt user for choice
        printf("Enter your choice (1-4): ");
        int choice;
        scanf("%d", &choice);

        // Handle user choice
        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a number from 1 to 4.\n");
                // Clear input buffer
                while (getchar() != '\n'); // Clear input buffer
                break;
        }
    }

    return 0;
}

// Function to add a task
void addTask(vector<string> &tasks) {
    // Clear input buffer
    while (getchar() != '\n');
    
    printf("Enter the task to add: ");
    char buffer[256];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer) - 1] = '\0'; // Remove newline character
    tasks.push_back(buffer);
    printf("Task added successfully!\n");
}

// Function to view all tasks
void viewTasks(const vector<string> &tasks) {
    if (tasks.empty()) {
        printf("No tasks found.\n");
    } else {
        printf("Tasks:\n");
        for (size_t i = 0; i < tasks.size(); ++i) {
            printf("%zu. %s\n", i + 1, tasks[i].c_str());
        }
    }
}

// Function to delete a task
void deleteTask(vector<string> &tasks) {
    if (tasks.empty()) {
        printf("No tasks to delete.\n");
        return;
    }

    viewTasks(tasks); // Show current tasks with indices
    printf("Enter the task number to delete: ");
    char buffer[256];
    fgets(buffer, sizeof(buffer), stdin);
    int index = atoi(buffer);

    // Validate index
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + index - 1);
        printf("Task deleted successfully!\n");
    } else {
        printf("Invalid task number. Please try again.\n");
    }
}
