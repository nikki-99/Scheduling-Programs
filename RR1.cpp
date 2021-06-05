#include <bits/stdc++.h>
using namespace std;
struct process
{
    int Pid;
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
    int RT;
};
struct Compareprocess
{
    bool operator()(process const &p1, process const &p2)
    {
        return p1.BT > p2.BT;
    }
};
int main()
{
    int n;
    cout << "Enter the number of process\n";
    cin >> n;
    process P[n];
    for (int i = 0; i < n; i++)
        P[i].Pid = i + 1;
    cout << "Enter the arrival time of all the process\n";
    for (int i = 0; i < n; i++)
        cin >> P[i].AT;
    cout << "Enter the burst time of all the process\n";
    for (int i = 0; i < n; i++)
        cin >> P[i].BT;
    sort(P, P + n, [](process &a, process &b)
         {
             if (a.AT == b.AT)
             {
                 if (a.BT == b.BT)
                     return a.Pid < b.Pid;
                 else
                     return a.BT < b.BT;
             }
             else
                 return a.AT < b.AT;
         });
    priority_queue<process, vector<process>, Compareprocess> pq;
    int current_time = P[0].AT;
    pq.push(P[0]);
    P[0].AT = -1;
    cout << "Process are \n";
    cout << "Process\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    int TAT = 0, WT = 0, RT = P[0].AT;
    while (!pq.empty())
    {
        process p = pq.top();
        pq.pop();
        RT = current_time - p.AT;
        current_time += p.BT;
        p.CT = current_time;
        p.TAT = p.CT - p.AT;
        p.WT = p.TAT - p.BT;
        TAT += p.TAT;
        WT += p.WT;
        cout << "P[" << p.Pid << "]\t" << p.AT << "\t" << p.BT << "\t" << p.CT << "\t" << p.TAT << "\t" << p.WT << "\t" << RT << "\n";
        for (int i = 0; i < n; i++)
        {
            if (P[i].AT <= current_time && P[i].AT != -1)
            {
                pq.push(P[i]);
                P[i].AT = -1;
            }
        }
    }
    cout << "Average Turn around time:  " << (float)TAT / n << "\n";
    cout << "Average Waiting time:  " << (float)WT / n;

    cout << "Schedule length :" << current_time - P[0].AT;
}