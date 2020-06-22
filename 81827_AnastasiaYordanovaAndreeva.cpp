// Example program
#include <iostream>
#include <string>
int const MAX=50000;

void nextStep(int n,int number,int val,int* steps,int* path)
{
    int newNumber;
    if(val==1)newNumber=number+1;
    else newNumber=number*val;
    if(newNumber<=n && (steps[newNumber]==0 || steps[newNumber] > steps[number]+1))
    {
        steps[newNumber]=steps[number]+1;
        path[newNumber]=val;
    }

}
void print(int* path , int n)
{
    int reversedPath[MAX]={0};
    int number=n;
    int i=0;
   while(number!=1)
   {
      reversedPath[i]=path[number];
      if(path[number]==1)number=number-1;
      else number=number/path[number];
      i++;
    }
    i--;
    while(i>=0)
    {
        printf("%d",reversedPath[i]);
        i--;
    }


}
void searchPath(int n)
{
    int  steps[MAX]={0};
    int path[MAX]={0};
    for(int number=1;number<n;number++)
    {
        if(steps[number]!=0 || number==1)
        {
            nextStep(n,number,3,steps,path);
            nextStep(n,number,2,steps,path);
            nextStep(n,number,1,steps,path);
        }
    }
    print(path,n);
}
int main()
{
int n;
scanf("%d",&n);
  searchPath(n);
}
