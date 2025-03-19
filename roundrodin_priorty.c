#include<stdio.h>
 main()
{
int	i,j,n,bu[10],wa[10],tat[10],t,ct[10],max; float awt=0,att=0,temp=0;
printf("Enter the no of processes -- "); scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\nEnter Burst Time for process %d -- ", i+1); scanf("%d",&bu[i]);
ct[i]=bu[i];
}
printf("\nEnter the size of time slice -- "); scanf("%d",&t);
max=bu[0]; 
for(i=1;i<n;i++) if(max<bu[i]) max=bu[i]; 
for(j=0;j<(max/t)+1;j++) for(i=0;i<n;i++) if(bu[i]!=0)
if(bu[i]<=t)	{ tat[i]=temp+bu[i]; temp=temp+bu[i]; bu[i]=0;
}
else { bu[i]=bu[i]-t; temp=temp+t;
}
for(i=0;i<n;i++){ wa[i]=tat[i]-
ct[i]; att+=tat[i]; awt+=wa[i];}

printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");
for(i=0;i<n;i++)
printf("\t%d \t %d \t\t %d \t\t %d \n",i+1,ct[i],wa[i],tat[i]); getch();}
printf("\nThe Average Turnaround time is -- %f",att/n); printf("\nThe Average Waiting time is -- %f ",awt/n);




#include<stdio.h>
main()
{
int p[20],bt[20],pri[20], wt[20],tat[20],i, k, n, temp; float wtavg, tatavg;

printf("Enter the number of processes --- "); scanf("%d",&n);
for(i=0;i<n;i++){ p[i] = i;
printf("Enter the Burst Time & Priority of Process %d --- ",i);
 scanf("%d%d",&bt[i], &pri[i]);
}
for(i=0;i<n;i++) for(k=i+1;k<n;k++) if(pri[i] > pri[k]){ temp=p[i]; p[i]=p[k]; p[k]=temp; temp=bt[i]; bt[i]=bt[k]; bt[k]=temp; temp=pri[i]; pri[i]=pri[k]; pri[k]=temp;
}
wtavg = wt[0] = 0; tatavg = tat[0] = bt[0]; for(i=1;i<n;i++)
{
wt[i] = wt[i-1] + bt[i-1];
tat[i] = tat[i-1] + bt[i];

wtavg = wtavg + wt[i]; tatavg = tatavg + tat[i];
}
printf("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME");
for(i=0;i<n;i++)
printf("\n%d \t\t %d \t\t %d \t\t %d \t\t %d ",p[i],pri[i],bt[i],wt[i],tat[i]);
 printf("\nAverage Waiting Time is --- %f",wtavg/n);
 printf("\nAverage Turnaround Time is --- %f",tatavg/n);
getch();
}





chatgpt

#include<stdio.h>

int main()
{
    int i, j, n, bu[10], wa[10], tat[10], t, ct[10], max, temp = 0;
    float awt = 0, att = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter Burst Time for process %d: ", i + 1);
        scanf("%d", &bu[i]);
        ct[i] = bu[i];  // Store initial burst time for each process
    }

    printf("\nEnter the time slice (quantum): ");
    scanf("%d", &t);

    max = bu[0]; 
    for(i = 1; i < n; i++) 
    {
        if(max < bu[i])
            max = bu[i]; 
    }

    for(j = 0; j < (max / t) + 1; j++)
    {
        for(i = 0; i < n; i++)
        {
            if(bu[i] != 0) 
            {
                if(bu[i] <= t)  // Process completes in this quantum
                {
                    tat[i] = temp + bu[i];
                    temp += bu[i];
                    bu[i] = 0;
                }
                else  // Process still requires more time
                {
                    bu[i] -= t;
                    temp += t;
                }
            }
        }
    }

    // Calculate waiting time and turnaround time
    for(i = 0; i < n; i++)
    {
        wa[i] = tat[i] - ct[i];  // Waiting time is turnaround time - burst time
        att += tat[i];
        awt += wa[i];
    }

    printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++)
    {
        printf("\t%d \t %d \t\t %d \t\t %d\n", i + 1, ct[i], wa[i], tat[i]);
    }

    printf("\nThe Average Turnaround Time is: %f", att / n);
    printf("\nThe Average Waiting Time is: %f", awt / n);

    return 0;
}







#include<stdio.h>

int main() {
    int p[20], bt[20], pri[20], wt[20], tat[20], i, k, n, temp;
    float wtavg = 0, tatavg = 0;

    printf("Enter the number of processes --- ");
    scanf("%d", &n);

    // Input burst time and priority for each process
    for(i = 0; i < n; i++) {
        p[i] = i;
        printf("Enter the Burst Time & Priority of Process %d --- ", i);
        scanf("%d%d", &bt[i], &pri[i]);
    }

    // Sorting processes by priority (ascending order, highest priority first)
    for(i = 0; i < n; i++) {
        for(k = i + 1; k < n; k++) {
            if(pri[i] > pri[k]) {
                // Swap process indices, burst times, and priorities
                temp = p[i]; p[i] = p[k]; p[k] = temp;
                temp = bt[i]; bt[i] = bt[k]; bt[k] = temp;
                temp = pri[i]; pri[i] = pri[k]; pri[k] = temp;
            }
        }
    }

    // Initialize waiting time and turnaround time for the first process
    wt[0] = 0;
    tat[0] = bt[0];

    // Calculate waiting time and turnaround time for all processes
    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];  // Waiting time is sum of previous burst times
        tat[i] = tat[i-1] + bt[i];  // Turnaround time is sum of burst times
    }

    // Calculate the total waiting time and turnaround time for average
    for(i = 0; i < n; i++) {
        wtavg += wt[i];
        tatavg += tat[i];
    }

    // Output process information
    printf("\nPROCESS\t\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for(i = 0; i < n; i++) {
        printf("%d \t\t %d \t\t %d \t\t %d \t\t %d\n", p[i], pri[i], bt[i], wt[i], tat[i]);
    }

    // Output average waiting time and turnaround time
    printf("\nAverage Waiting Time is --- %f", wtavg / n);
    printf("\nAverage Turnaround Time is --- %f", tatavg / n);

    return 0;
}
