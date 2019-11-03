#include<iostream>
using namespace std;
int main()
{
   int at[100],bt[100],ct[100],tat[100],wt[100],n,pid[100],l[100];;
   cout<<"how many process is there "<<"\n";
   cin>>n;
   cout<<"please enter the arrival time and correponding burst time for table "<<"\n";
   for(int i=0;i<n;i++)
   {
      cin>>at[i];
      cin>>bt[i];
      ct[i]=0;
      tat[i]=0;
      wt[i]=0;
      pid[i]=i;
      l[i]=at[i];
   }
   ct[-1]=0;
for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
               if(at[i]>at[j])
                {
                  int t=at[i];
                  at[i]=at[j];
                  at[j]=t;
                  t=bt[i];
                  bt[i]=bt[j];
                  bt[j]=t;
                  t=pid[i];
                  pid[i]=pid[j];pid[j]=t;

                }
            }
        }

       for(int i=0;i<n;i++)
        {
           for(int j=i+1;j<n;j++)
            {
               if(bt[i]>bt[j]&&at[i]==at[j])
                {
                   int t=bt[i];
                   bt[i]=bt[j];
                   bt[j]=t;
                   t=pid[i];
                   pid[i]=pid[j];pid[j]=t;

                }
            }
        }


   int kl=0;
   int y=0;

   //completion time
   for(int k=0;k<n;k++)
   {
        

      int r=0;
      if((ct[k-1]+kl)>=at[k])
      {
         ct[k]=ct[k-1]+bt[k]+kl;
         kl=0;
         y=ct[k];
         r=1;
      }
      else
      {
         kl++;
         k=k-1;
         r=0;
      }
      if(r==1){


      for(int i=k+1;i<n;i++)
        {
           for(int j=i+1;j<n;j++)
            {
               if(bt[i]>bt[j]&&at[j]<=y&&at[j]<=y)
                {
                   int t=bt[i];
                   bt[i]=bt[j];
                   bt[j]=t;
                   t=pid[i];
                   pid[i]=pid[j];pid[j]=t;
                   t=at[i];
                  at[i]=at[j];
                  at[j]=t;

                }
            }
        }
}

   	// cout<<"hegfgrf";
   }

   //turn around time

   for(int i=0;i<n;i++)
   {
      tat[i]=ct[i]-at[i];
   }
    for(int i=0;i<n;i++)
   {
      wt[i]=tat[i]-bt[i];
   }
   for(int i=0;i<n;i++)
   {
      cout<<"completition time is "<<ct[i]<<" "<<"tat time is "<<tat[i]<<" "<<"waiting time is "<<wt[i]<<" "<<"and corresponding pid is :"<<(pid[i]+1)<<"\n";
   }

 float avgtat=0,avgwt=0;
  for(int i=0;i<n;i++)
  {
   avgtat=avgtat+tat[i];
   avgwt=avgwt+wt[i];
  }
  cout<<"avg tat is : "<<(avgtat/n)<<"avg wt : "<<(avgwt/n)<<"\n";
   return 0;

}