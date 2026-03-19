#include <iostream>
#include <fstream>
using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
    int completionTime;
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

    int completed = 0;
    int currentTime = 0;

    while (completed < n) {

        int idx = -1;
        int minRT = 9999;

        // tìm tiến trình có remaining time nhỏ nhất
        for (int i = 0; i < n; i++) {

            if (p[i].arrivalTime <= currentTime &&
                p[i].remainingTime > 0 &&
                p[i].remainingTime < minRT) {

                minRT = p[i].remainingTime;
                idx = i;
            }
        }

        // nếu chưa có tiến trình nào đến
        if (idx == -1) {
            currentTime++;
            continue;
        }

        // chạy tiến trình 1 đơn vị thời gian
        p[idx].remainingTime--;
        currentTime++;

        // nếu tiến trình hoàn thành
        if (p[idx].remainingTime == 0) {

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