#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
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
        inFile >> p[i].arrivalTime >> p[i].burstTime;
        p[i].remainingTime = p[i].burstTime;
    }

    int quantum;
    inFile >> quantum;

    queue<int> q;
    int currentTime = 0;
    int completed = 0;
    bool visited[n] = {false};

    while (completed < n) {

        for (int i = 0; i < n; i++) {
            if (p[i].arrivalTime <= currentTime && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }

        if (q.empty()) {
            currentTime++;
            continue;
        }

        int idx = q.front();
        q.pop();

        int execTime = min(quantum, p[idx].remainingTime);

        p[idx].remainingTime -= execTime;
        currentTime += execTime;

        for (int i = 0; i < n; i++) {
            if (p[i].arrivalTime <= currentTime && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }

        if (p[idx].remainingTime > 0) {
            q.push(idx);
        } else {
            completed++;
            p[idx].completionTime = currentTime;
            p[idx].turnaroundTime =
                p[idx].completionTime - p[idx].arrivalTime;
            p[idx].waitingTime =
                p[idx].turnaroundTime - p[idx].burstTime;
        }
    }

    outFile << "PID\tAT\tBT\tWT\tTAT\tCT\n";

    for (int i = 0; i < n; i++) {
        outFile << "P" << p[i].pid << "\t"
                << p[i].arrivalTime << "\t"
                << p[i].burstTime << "\t"
                << p[i].waitingTime << "\t"
                << p[i].turnaroundTime << "\t"
                << p[i].completionTime << endl;
    }

    inFile.close();
    outFile.close();

    return 0;
}