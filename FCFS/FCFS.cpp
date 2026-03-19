#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct Process
{
    int pid;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
    int completionTime;
};

bool compareArrival(Process a, Process b)
{
    return a.arrivalTime < b.arrivalTime;
}

int main()
{

    ifstream inFile("input.txt");
    ofstream outFile("output.txt");

    // kiểm tra nếu không mở được file input
    if (!inFile.is_open())
    {
        cout << "Khong mo duoc file input.txt\n";
        return 1;
    }

    // kiểm tra nếu không tạo được file output
    if (!outFile.is_open())
    {
        cout << "Khong tao duoc file output.txt\n";
        return 1;
    }

    int n;
    inFile >> n;

    Process p[n];

    for (int i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        inFile >> p[i].arrivalTime >> p[i].burstTime;
    }

    sort(p, p + n, compareArrival);

    int currentTime = 0;

    for (int i = 0; i < n; i++)
    {

        if (currentTime < p[i].arrivalTime)
            currentTime = p[i].arrivalTime;

        p[i].waitingTime = currentTime - p[i].arrivalTime;
        currentTime += p[i].burstTime;
        p[i].completionTime = currentTime;
        p[i].turnaroundTime = p[i].completionTime - p[i].arrivalTime;
    }

    outFile << "PID\tAT\tBT\tWT\tTAT\tCT\n";

    for (int i = 0; i < n; i++)
    {
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