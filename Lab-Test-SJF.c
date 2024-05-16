#include<stdio.h>
int main()
{
    int burst[15],
    p[15],
    waiting[15],
    turnAround[15],
    i,j,n,
    totalWaiting=0,
    totalTurnAround=0,
    pos,temp;
    float avg_waiting,avg_turnAround;
    printf("Enter number of process:");
    scanf("%d",&n);

    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&burst[i]);
        p[i]=i+1;
    }
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(burst[j]<burst[pos])
                pos=j;
        }

        temp=burst[i];
        burst[i]=burst[pos];
        burst[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }

    waiting[0]=0;

    for(i=1;i<n;i++)
    {
        waiting[i]=0;
        for(j=0;j<i;j++)
            waiting[i]+=burst[j];
        totalWaiting+=waiting[i];
    }

    avg_waiting=(float)totalWaiting/n;

    printf("\nProcess\t Burst Time \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        turnAround[i]=burst[i]+waiting[i];

        totalTurnAround+=turnAround[i];
        printf("\np%d\t\t %d\t\t %d\t\t\t%d",p[i],burst[i],waiting[i],turnAround[i]);
    }
    avg_turnAround=(float)totalTurnAround/n;
    printf("\n\nAverage Waiting Time=%f",avg_waiting);
    printf("\nAverage Turnaround Time=%f",avg_turnAround);
}

