#include <iostream>
#include <string>
using namespace std;

void consolePrint();
void addTask(string tasks[], bool done[], int &taskCount);
void viewTask(string task[], bool done[], int taskCount);
void markTask(string tasks[], bool done[], int &taskCount);
void deleteTask(string task[], bool done[], int &taskCount);
void selectTaskNumber(string tasks[], bool done[], int taskCount);
int countCompletedTasks(bool done[], int &taskCount);
bool checkTasksNum(int taskNumber);

int main() {

    string taskName;
    string tasks[100];
    bool done[100];
    int taskCount = 0;
    int input = 0;

    do {
        consolePrint();
        cin >> input;

        switch (input) {
            case 1:
                addTask(tasks, done, taskCount);
                break;
            case 2:
                viewTask(tasks, done, taskCount);
                break;
            case 3:
                markTask(tasks, done, taskCount);
                break;
            case 4:
                deleteTask(tasks, done, taskCount);
                break;
            case 5: {
                int result = countCompletedTasks(done,taskCount);
                cout << "There are: " << result << " completed tasks"<< endl;
                break;
            }
            case 6:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid input" << endl;
        }

    }while (input != 0);

    return 0;
}

void consolePrint() {
    cout << "1. Add task" << endl;
    cout << "2. View tasks" << endl;
    cout << "3. Mark task as done" << endl;
    cout << "4. Delete task" << endl;
    cout << "5. Count completed tasks" << endl;
    cout << "6. Exit" << endl;
}

void addTask(string tasks[], bool done[], int &taskCount) {
    string taskName;
    if (taskCount >= 100) {
        cout << "Task list is full" << endl;
        return;
    }

    cin.ignore();

    getline(cin, taskName);
    if (taskName.empty()) {
        cout << "Task name is empty" << endl;
        return;
    }
    for (int i = 0; i < taskCount; i++) {
        if (tasks[i] == taskName) {
            cout << "Task " << taskName << " already exists" << endl;
            return;
        }
    }
    tasks[taskCount] = taskName;
    done[taskCount] = false;
    taskCount++;

    cout << "Added task " << taskName << endl;
}

void viewTask(string tasks[], bool done[], int taskCount) {
    if (!checkTasksNum(taskCount)) return;
    selectTaskNumber(tasks, done, taskCount);
}

void markTask(string tasks[], bool done[], int &taskCount) {
    //check if there are tasks
    if (!checkTasksNum(taskCount)) return;

    int input = 0;

    //prints the tasks
    selectTaskNumber(tasks, done, taskCount);

    //grab the input for 'X' task
    cin >> input;
    if (input < 1 || input > taskCount) {
        cout << "Invalid input" << endl;
        return;
    }
    done[input - 1] = true;
    cout << "Marked task " << tasks[input-1] << endl;
}

void deleteTask(string task[], bool done[], int &taskCount) {
    //check if there are tasks in the first place
    if (!checkTasksNum(taskCount)) return;

    //display the tasks
    selectTaskNumber(task, done, taskCount);

    //get input
    cin.ignore();
    string taskName;
    getline(cin, taskName);
    if (taskName.empty()) {
        cout << "Task name is empty" << endl;
    }
    //loop through all the tasks and shift left if a match is found
    for (int i = 0; i < taskCount; i++) {
        if (task[i] == taskName) {
            for (int j = i; j < taskCount - 1; j++) {
                task[j] = task[j+1];
                done[j] = done[j+1];
            }

            taskCount--;
            cout << "Deleted task " << taskName << endl;
            return; //stop after 1 match is deleted
        }
    }
}
int countCompletedTasks(bool done[], int &taskCount) {
    int completedTaskCount = 0;
    //check if there are tasks
    if (!checkTasksNum(taskCount)) return 0;

    //loop through all the tasks and check if they are done
    for (int i = 0; i < taskCount; i++) {
        if (done[i]) {
            completedTaskCount++;
        }
    }
    return completedTaskCount;
}

bool checkTasksNum(int taskNumber) {
    if (taskNumber == 0) {
        cout << "No tasks yet" << endl;
        return false;
    }
    return true;
}
void selectTaskNumber(string tasks[], bool done[], int taskCount) {
    for (int i = 0; i < taskCount; i++) {
        cout << (i + 1) << ". [" << (done[i] ? 'X' : ' ') << "] " << tasks[i] << "\n";
    }
}
