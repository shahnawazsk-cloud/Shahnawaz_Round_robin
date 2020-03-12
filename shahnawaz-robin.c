#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>


int hr()		// For Horizontal Line
	{
		int g,h;
				g=178;
				printf("\n");
				for(h=1;h<=42;h++)
				printf("%c",g);
				for(h=1;h<=15;h++)
				printf("%c",177);
				for(h=1;h<=10;h++)
				printf("%c",219);
				printf("\n");
	}
	
	
struct process
{
	int id;
	int at;
	int bt;
	int copybt;
	int priority;
	int copypriority;
	int wt;
	int ct;
	int flag;
	int tat;
};


struct process p[50];
struct process q[50];
int start = 0;
int end = 0;
int time = 0;

void insert(struct process onep)	//one process
{	
	q[end] = onep;
	end = end + 1;
	int i;
	for(i = start; i<end; i++)
	{
		p[q[i].id].flag = 1;
	}
	/*	
	for(i = 0; i<end; i++)
	{
	printf("\nID = %d",q[i].id);
	}
	printf("\n");*/
}

void kill()
{
	int i;
	struct process temp;
	temp = q[start];
	
	for(i = start; i<=end-1; i++)
	{
		q[i] = q[i+1];
	}
	end = end - 1;
	//insert(temp);
	//printf("SIZE = %d", end);	
}

int table(int n, int k, int t)
	{
		int i;
		
		printf("\n Total Number of Processes = %d\n",n);
		printf("\t      Time Quantum = %d\n",t);
		printf("___________________________________________________________________");
		printf("\n\n PID\t| \tAT\tBT\tPriority     TAT\tWT\tCT\n");
		printf("___________________________________________________________________\n");
		
		for (i = 0; i < n; i++)
		{	
			if(i<k)	
			printf("\n P%d\t| \t%d\t%d\t   %d\t      %c\t\t%c\t%c",p[i].id,p[i].at,p[i].bt,p[i].priority,45,45,45);
			else
			printf("\n P%d\t| \t%c\t%c\t   %c\t      %c\t\t%c\t%c",i,45,45,45,45,45,45);						
		}
		
		printf("\n___________________________________________________________________\n");		
	}
	
int finaltable(int n, int t)
	{
		int i;
		printf("\n COMPUTED DATA\n");
		printf("__________________________________________________\n");
		printf("\n Total Number of Processes = %d\n",n);
		printf("\t      Time Quantum = %d\n",t);
		printf("___________________________________________________________________");
		printf("\n\n PID\t| \tAT\tBT\tPriority     TAT\tWT\tCT\n");
		printf("___________________________________________________________________\n");
		
		for (i = 0; i < n; i++)
		{	
			printf("\n P%d\t| \t%d\t%d\t   %d\t      %d      \t%d    \t%d",p[i].id,p[i].at,p[i].copybt,p[i].copypriority,p[i].tat,p[i].wt,p[i].ct);						
		}
		
		printf("\n___________________________________________________________________\n");		
	}

int max(int n, int k)
{
	if(k==1)	// Maximum Arrival Time
	{
		int i,maximum,index;
		maximum = p[0].at;
		
		for(i=0;i<n;i++)
		{
			if(p[i].at>maximum)
			{						
				maximum=p[i].at;
				index = i;
			}	
		}
		return(p[index].id);
	}
	else if(k==2)	// Maximum Burst Time
	{
		int i,maximum;
		maximum = p[0].bt;
		
		for(i=0;i<n;i++)
		{
			if(p[i].bt>maximum)
			{						
				maximum=p[i].bt;
			}	
		}
		return(maximum);
	}
	else if(k==3)	// Maximum Priority from Queue
	{
		int i,maximum,index;
		maximum = q[0].priority;
		
		for(i=0;i<n;i++)
		{
			if(q[i].priority>maximum)
			{						
				maximum=q[i].priority;
				index = i;
			}	
		}
		return(q[index].id);
	}
	
}

// ----------------------------------------------------------------------------------------

	
int min(int n, int k)
{
	if(k==1)// Minimum Arrival Time
	{
		int i,minimum,index;
		minimum = p[0].at;
		
		for(i=0;i<n;i++)
		{
			if(p[i].at<minimum)
			{						
				minimum=p[i].at;
				index = i;
			}	
		}
		return(p[index].id);
	}
	
	else if(k==2)// Minimum Burst Time
	{
		int i,minimum;
		minimum = p[0].bt;
		
		for(i=0;i<n;i++)
		{
			if(p[i].bt<minimum)
			{						
				minimum=p[i].bt;
			}	
		}
		return(minimum);
	}
	
	else if(k==3)//Minimum Priority
	{
		int i,minimum;
		minimum = p[0].priority;
		
		for(i=0;i<n;i++)
		{
			if(p[i].priority<minimum)
			{						
				minimum=p[i].priority;
			}	
		}
		return(minimum);
	}
}

//---------------------------------------------------------------------------------------

void sort(int n)
{
	int i, j;
	struct process temp;
	for(i = 0; i<n-1; i++)
	{
		for(j = i+1; j<n; j++)
		{
			if(p[i].at>p[j].at)
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
	
	for(i = 0; i<n; i++)
	{
		p[i].id = i;
		p[i].flag = 0;
	
	}
}

void sortqueuepriority()
{
	int i, j;
	struct process temp;
	for(i = 0; i<end-1; i++)
	{
		for(j = i+1; j<end; j++)
		{
			if(q[i].priority<q[j].priority)
			{
				temp = q[i];
				q[i] = q[j];
				q[j] = temp;
			}
		}
	}

}


//===============================================================================


int main()
{
	int n; 						// n = Number of Processes
	int t;						// t = Time Quantum
	up:
	hr();
	printf("\n Enter Total Number of Processes = ");
	scanf("%d",&n);
	
	printf("\n Enter Time Quantum = ");
	scanf("%d",&t);
	
	if((n<0)||(t<0))	
	{
		system("cls");
		hr();
		printf("\n Invalid Entry\n");
		goto up;
	}
	
	int i;
	
	printf("___________________________________________________________________");
		printf("\n\n PID\t| \tAT\tBT\tPriority     TAT\tWT\tCT\n");
		printf("___________________________________________________________________\n");
		
		for (i = 0; i < n; i++)
		{
			printf("\n P%d\t| \t%c\t%c\t   %c\t      %c\t\t%c\t%c",i,45,45,45,45,45,45);
		}
		
		printf("\n___________________________________________________________________\n");
	
	hr();
	
	
	
	int x,y,z;
	
	for ( i = 0; i < n; i++)
	{		
		printf("\n %c%c PROCESS P%d \n",177,177,i+1);
				
		
		printf("______________________________________________________________\n");
		
		printf("\n Enter |P%d| Arrival Time : ",i+1);
		scanf("%d",&p[i].at);		 
		
		printf("\n Enter |P%d| Burst Time : ",i+1);
		scanf("%d",&p[i].bt);		
		p[i].copybt = p[i].bt;
		
		printf("\n Enter |P%d| Priority : ",i+1);
		scanf("%d",&p[i].priority);	
		p[i].copypriority = p[i].priority;
		
		if((p[i].at<0)||(p[i].bt<0)||(p[i].priority<0))
			{
				system("cls");
				hr();
				printf("\n Invalid Entry\n");
				goto up;	
			}
			
		p[i].id=i;		// Assigning ID
		
		system("cls");
		hr();
		table(n,i+1,t);
		hr();	
	}
	
	system("cls");
	hr();
	printf("\n USER DATA \n");
	printf("__________________________________________________\n");
	table(n,n,t);
	
	printf("\n\n\n");
	hr();	
	sort(n);
	printf("\n SORTED DATA \n");
	printf("__________________________________________________\n");
	table(n,n,t);
	
	printf("\n\n\n");
	hr();

	int minatpid;	// minimum arrival time process id
	minatpid = min(n,1);
	
	for(i=0; i<n; i++)
	{
		if(p[minatpid].at==p[i].at)
		{
			insert(p[i]);
			p[i].flag==1;
		}
	}
	
	int maxprioritypid; // max priority process id
	maxprioritypid = max(end,3);
	
	int totalbt = 0;	// total burst time
	for(i = 0; i<n; i++)
	{
		totalbt = totalbt + p[i].bt;
	}

/*	printf("\n AT = %d",q[maxprioritypid].at);
	printf("\n BT = %d",q[maxprioritypid].bt);
	printf("\n Priority = %d",q[maxprioritypid].priority);
	printf("\n ID = %d",q[maxprioritypid].id);
	
	printf("\n TOTAL BT = %d",totalbt);	*/
	
	sortqueuepriority();
	
	printf("\n__________________________________________________\n");
	
	/*for(i =0; i<n; i++)
	{
	printf("\n ID = %d	Flag = %d",p[i].id,p[i].flag);
	}*/
	
	int j,k;
	int count = 0;
	while(count!=n)	// while burst time of all processes !=0
	{
		count = 0;
		
		for(j = 0; j<n; j++)
		{
			if((p[j].flag==0)&&(p[j].at<=time))
			{
				insert(p[j]);	
			}	
		}
		sortqueuepriority();
		
		if((q[start].at!=0)&&(time==0))
		{
			printf("\n0 - %d -> No Process",q[start].at);
			printf("\n__________________________________________________\n");
			time = time + q[start].at;
		}
		
		if(q[start].bt <= t)
		{
			int oldtime = time;
			time = time + q[start].bt;
			p[q[start].id].bt = 0;
			q[start].bt = 0;
			if(q[start].priority!=0)
			{
				q[start].priority = q[start].priority - 1;
			}
		//	printf("\n----------------------------------------------");
			printf("\n%d - %d -> P%d ",oldtime,time,q[start].id);
			printf("\nPending BT = %d",p[q[start].id].bt);
			p[q[start].id].ct = time;
			p[q[start].id].tat = p[q[start].id].ct - p[q[start].id].at;
			p[q[start].id].wt = p[q[start].id].tat - p[q[start].id].copybt;
			if(p[q[start].id].priority!=0)
			{
				p[q[start].id].priority = p[q[start].id].priority - 1;
			}
			kill();
		}	
		else
		{
			int oldtime = time;
			time = time + t;
			q[start].bt = q[start].bt - t;
			p[q[start].id].bt = p[q[start].id].bt - t;
			if(q[start].priority!=0)
			{
				q[start].priority = q[start].priority - 1;
			}
			struct process temp;
			temp = q[start];
			kill();
			insert(temp);
		//	printf("\n----------------------------------------------");
			printf("\n%d - %d -> P%d",oldtime,time,temp.id);
			printf("\nPending BT = %d",temp.bt);
			temp.ct = time;
			temp.tat = temp.ct - temp.at;
			temp.wt = temp.tat - temp.copybt;
			if(temp.priority!=0)
			{
				temp.priority = temp.priority - 1;
			}
		}	
		
		printf("\nTIME HAPPEND = %d",time);
		printf("\n__________________________________________________\n");
		for(k=0; k<n; k++)
		{
			if(p[k].bt==0)
			{
				count = count + 1;
		//	printf("\n %d",count);
			}
		}
			
		if(start==end)
		{
			if(count==n)
			{
				break;
			}
			else
			{
			int lastat;
			lastat = max(n,1);
			int oldtime = time;
			time = p[lastat].at; 
			printf("\n%d - %d -> No process",oldtime,time);
			printf("\n__________________________________________________\n");
			}
		}
	}
	printf("\n\n");
	
	hr();
	finaltable(n,t);

	printf("\n\n");
	
	float avgwt,avgtat,avgct;
	float totalwt, totaltat, totalct;
	totalwt = 0;
	totaltat = 0;
	totalct = 0;
	
	for(i = 0; i< n;i++)
	{
		totalwt = totalwt + p[i].wt;
		totaltat = totaltat + p[i].tat;
		totalct = totalct + p[i].ct;
	}
	
	avgwt = totalwt/n;
	avgtat = totaltat/n;
	avgct = totalct/n;
	
	printf("\n Average Waitng Time      = %f",avgwt);
	printf("\n Average Turn Around Time = %f",avgtat);
	printf("\n Average Completion time  = %f",avgct);
	printf("\n\n");
	hr();
	
	
	
	/*for(i = 0; i< n;i++)
	{
		printf("\n ID = %d CT = %d TAT = %d WT = %d",p[i].id,p[i].ct,p[i].tat,p[i].wt);
	}*/
	
}

