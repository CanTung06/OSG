#include <iostream>
#include <fstream>
using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int priority;
    int waitingTime;
    int turnaroundTime;
    int completionTime;
    bool finished;
};

int main() {

    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    if (!inFile) {
        cout << "Khong mo duoc input.txt";
        return 1;
    }

    int n;
    inFile >> n;

    Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        inFile >> p[i].arrivalTime >> p[i].burstTime >> p[i].priority;
        p[i].finished = false;
    }

    int completed = 0;
    int currentTime = 0;

    while (completed < n) {

        int idx = -1;
        int bestPriority = 9999;

        // tìm tiến trình có priority cao nhất (số nhỏ nhất)
        for (int i = 0; i < n; i++) {

            if (!p[i].finished && p[i].arrivalTime <= currentTime) {

                if (p[i].priority < bestPriority) {
                    bestPriority = p[i].priority;
                    idx = i;
                }
            }
        }

        // nếu chưa có tiến trình nào đến
        if (idx == -1) {
            currentTime++;
            continue;
        }

        p[idx].waitingTime = currentTime - p[idx].arrivalTime;

        currentTime += p[idx].burstTime;

        p[idx].completionTime = currentTime;

        p[idx].turnaroundTime =
            p[idx].completionTime - p[idx].arrivalTime;

        p[idx].finished = true;

        completed++;
    }

    outFile << "PID\tAT\tBT\tPR\tWT\tTAT\tCT\n";

    for (int i = 0; i < n; i++) {
        outFile << "P" << p[i].pid << "\t"
                << p[i].arrivalTime << "\t"
                << p[i].burstTime << "\t"
                << p[i].priority << "\t"
                << p[i].waitingTime << "\t"
                << p[i].turnaroundTime << "\t"
                << p[i].completionTime << endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}