#include<iostream>
#include<time.h>
#include<malloc.h>
using namespace std;
int selsort(int*);
void bubsort(int*);
int insort(int*,int);
int quicksort(int*,int,int);
void initial(int*);
void display(int*);
void swape(int*,int*);
void heapSort(int*);
int n,i,j,k;
int main()
{
    char ch;
    while(1)
    { cout<<"\n\t\t\t\tSelection Menu\n\n\t\t1.Sort Comparator\n\t\t2.Sorting\n\t\t3.Exit\n\nEnter your choice: ";
      cin>>ch;
      switch(ch)
      { case '1': {system("cls");
                  cout<<"\n\t\t\tSort Comparator\n\nEnter amount of data to be sorted: ";
                  cin>>n;
                  if(n>40000)
                   {
                     cout<<"Quick sort is best!!";
                     break;
                   }
                  cout<<"\nFor best case scenario Time taken by:-\n\n";
                  int *a=(int*)malloc(n*sizeof(int));
                  for(i=0;i<n;i++)
                  *(a+i)=i;
                  clock_t tStart = clock();
                  insort(a,1);
                  printf("Insertion sort: %fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
                  tStart = clock();
                  k=0;
                  do
                  { k=3*k+1;
                  }while(k<10);
                  k=(k-1)/3;
                  for(;k>=1;k=(k-1)/3)
                    insort(a,k);
                  printf("Shell sort: %fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
                  tStart = clock();
                  selsort(a);
                  printf("Selection sort: %fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
                  tStart = clock();
                  bubsort(a);
                  printf("Bubble sort: %fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
                  tStart=clock();
                  quicksort(a,0,n-1);
                  printf("Quick sort: %fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
                  cout<<"\nFor Worst case scenario Time taken by:-\n\n";
                  initial(a);
                  tStart = clock();
                  insort(a,1);
                  printf("Insertion sort: %fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
                  initial(a);
                  tStart = clock();
                  k=0;
                  do
                  { k=3*k+1;
                  }while(k<10);
                  k=(k-1)/3;
                  for(;k>=1;k=(k-1)/3)
                    insort(a,k);
                  printf("Shell sort: %fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
                  initial(a);
                  tStart = clock();
                  selsort(a);
                  printf("Selection sort: %fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
                  initial(a);
                  tStart = clock();
                  bubsort(a);
                  printf("Bubble sort: %fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
                  initial(a);
                  tStart = clock();
                  quicksort(a,0,n-1);
                  printf("Quick sort: %fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
                  cout<<endl;
                  system("pause");
                  system("cls");
                  break;}
        case '2': {system("cls");
                  cout<<"\n\t\t\tSorting\n\nEnter total number of elements: ";
                  cin>>n;
                  int *a=(int*)malloc(n*sizeof(int));
                  cout<<"Enter elements:\n";
                  for(i=0;i<n;i++)
                    cin>>*(a+i);
                  cout<<"\nSelect sorting technique to be used\n\n1.Selection sort\n2.Insertion sort\n3.Bubble sort\n4.Shell sort\n5.Quick sort\n\nEnter your choice: ";
                  cin>>ch;
                  switch(ch)
                  {
                      case '1': selsort(a);
                                display(a);
                                break;
                      case '2': insort(a,1);
                                display(a);
                                break;
                      case '3': bubsort(a);
                                display(a);
                                break;
                      case '4': k=0;
                                do
                                { k=3*k+1;
                                }while(k<10);
                                k=(k-1)/3;
                                for(;k>=1;k=(k-1)/3)
                                    insort(a,k);
                                display(a);
                                break;
                      case '5': quicksort(a,0,n-1);
                                display(a);
                                break;
                      default:  cout<<"Invalid choice!!!";
                  }
                  cout<<endl;
                  system("pause");
                  system("cls");
                  break;}
        case '3': return 0;
        default : cout<<"Invalid choice!!!";
      }
    }
}
void display(int *a)
{
    cout<<"\n";
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
}
void initial(int *a)
{   for(j=0,i=n;i>0;i--)
    {  *(a+j)=i;
        j++;
    }
}
void bubsort(int* a)
{
    for(i=n;i>0;i--)
    {
        for(j=0;j<i-1;j++)
        {
            if(*(a+j+1)<*(a+j))
              swape(a+j,a+j+1);
        }
    }
}
int selsort(int *a)
{
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(*(a+j)<*(a+i))
              swape(a+j,a+i);
        }
    }
    return 0;
}
int insort(int *a,int k)
{
    for(int i=2*k-1;i<n;i++)
    {
        j=i;
        while(j-k>=0)
        {
            if(*(a+j)<*(a+j-k))
            {
                swape(a+j,a+j-k);
                j--;
            }
            else
                break;
        }
    }
    return 0;
}
int quicksort(int *a,int lb,int ub)
{
    int pivot=*(a+ub);
    //cout<<"\n\n"<<pivot;
    i=lb;      j=ub-1;
    do
    {
        if((*(a+i)<pivot)&&i<j)
           i++;
        else if((*(a+j)>pivot)&&j>i)
                j--;
             else
              {
                 swape(a+i,a+j);
                 continue;
              }
    }while(i<j);
    if(*(a+i)>pivot)
      swape(a+j,a+ub);
    else
      j++;
    if(j-1>lb)
      quicksort(a,lb,j-1);
    if(j+1<ub)
      quicksort(a,j+1,ub);
    return 0;
}
void swape(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapSort(int *a)
{
    void minHeapify(int *a,int ind)
    {
        
    }
}
