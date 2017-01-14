#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#pragma warning(disable : 4996)


typedef struct student{
	char name[10];
	int number;
	int age;
	char score;
}STU;

void ArrayName(STU Dataset[], int len);
void ArrayNum(STU DataSet[], int len);
void ArrayAge(STU DataSet[], int len); 
void ArrayScore(STU DataSet[], int len);
void Search(STU DataSet[], int len);
void Sname(STU DataSet[], char name[], int len);
void Snum(STU DataSet[], int num, int len);
void Sage(STU DataSet[], int num, int len);
void Score(STU DataSet[], char s, int len);

int main(void){

	FILE* fp = fopen("input.txt", "rt");
	int i;
	STU student[20];

	if (fp == NULL)
	{
		puts("file open fail");
		return -1;
	}

	for (i = 0; i < 20; i++){
		fscanf(fp, "%s %d %d %c\n", &student[i].name, &student[i].number, &student[i].age, &student[i].score);
	}

	while (1)
	{
		printf("Choose the one : 1]SortName 2]SortStdID 3]SortAge 4]SortScore 5]BinarySearch 6]Exit\n");
		scanf("%d", &i);

		switch (i)
		{
		case 1:
			ArrayName(student, 20);	 break;
		case 2:
			ArrayNum(student, 20);  break;
		case 3:
			ArrayAge(student, 20);  break;
		case 4:
			ArrayScore(student, 20);  break;
		case 5:
			Search(student, 20);  break;
		case 6:
			printf("Exit.\n");
			exit(1);
		default:
			printf("Input wrong number.\n");
			fflush(stdin); 
			break;
		}
	}
		fclose(fp);
		return 0;	
}

void Search(STU DataSet[], int len)
{
	int s=0;
	char name[15];
	int num=0;
	char score=0;
	while (s != 5)
	{
		printf("Please select a form to find. 1]Name 2]StdID 3]Age 4]Score 5]Exit\n ");
		scanf("%d", &s);
		fflush(stdin);
		switch (s)
		{
		case 1: printf("Please enter a name to find.\n"); scanf("%s", name); Sname(DataSet,name, len); break;
		case 2: printf("Please enter a stdID to find.\n"); scanf("%d",&num); Snum(DataSet,num, len); break;
		case 3: printf("Please enter a age to find.\n"); scanf("%d",&num); Sage(DataSet,num,len); break;
		case 4: printf("Please enter a score to find.\n"); scanf("%c",&score); Score(DataSet, score, len); break;
		case 5: printf("Exit.\n"); break;
		default:
			printf("Input wrong number.\n");
			fflush(stdin);
			break;
		}
	}
}

void Sname(STU DataSet[], char name[], int len)
{// binary search
	int left, right, mid,k;
      left = 0;
      right = len - 1;
	 
      while (left <= right)
	  {
	             mid = (left + right) / 2;
                 k = strncmp(name, DataSet[mid].name,2);//equal 0 first one is big >0, small <0
				 
	             if (k < 0)
				 {
		             right = mid - 1;
                 }
                 else if (k > 0)
				 {
					 left = mid + 1;
				 }
				 else if (k==0)
				 {
					 printf("->The Name is in the %d th.\nstdID is %d, Age is %d, Score is %c.\n",
						 mid + 1, DataSet[mid].number, DataSet[mid].age, DataSet[mid].score);
					 return ;
				 }
       }
      printf(" --> No name\n");
 }

void Snum(STU DataSet[], int n, int len)
{// binary search 
	int left, right, mid;
	left = 0;
	right = len - 1;

	while (left <= right)
	{
		mid = (left + right) / 2;
		
		if (n < DataSet[mid].number)
		{
			right = mid - 1;
		}
		else if (n > DataSet[mid].number)
		{
			left = mid + 1;
		}
		else
		{
			printf("->The stdID is in the %d th.\nName is %s, Age is %d, Score is %c.\n",
				mid + 1, DataSet[mid].name, DataSet[mid].age, DataSet[mid].score);
			return;
		}
	}
	printf(" --> No stdID.\n") ;
	fflush(stdin);
}
void Sage(STU DataSet[], int n, int len)
{// binary search 
	int left=0, right,sw=0;
	left = 0;
	right = len - 1;

	while (left <= right)
	{
		if (n == DataSet[left].age)
		{
			printf("->The Age is in the %d th.\nName is %s, stdID is %d, Score is %c.\n",
				left + 1, DataSet[left].name, DataSet[left].number, DataSet[left].score);
			sw = 1;
			left++;
			
		}
		else
			left++;
	}
	if (sw==1)
	printf(" --> Search is finished.\n");
	else 
		printf(" --> You did not find any results, or you entered an incorrect number.\n");

	fflush(stdin);
}

void Score(STU DataSet[], char s, int len)
{// binary searh
	int left = 0, right,sw=0;
	left = 0;
	right = len - 1;

	while (left <= right)
	{
		if (s == DataSet[left].score)
		{
			printf("->Score is in the %d th.\nName is %s, stdID is %d, Age is %d.\n",
				left + 1, DataSet[left].name, DataSet[left].number, DataSet[left].age);
			sw = 1;
			left++;
		}
		else
			left++;
	}
	if (sw == 1)
		printf(" --> Search is finished.\n");
	else
		printf(" --> You did not find any results, or you entered an incorrect number.\n");
	fflush(stdin);
}

void ArrayName(STU DataSet[], int len){//Sort by name. 

	int i,j;
	STU temp;

	for (i = 0; i<len-1 ; i++)
	{
		for (j = 1; j < len; j++)
		{
			if (DataSet[j - 1].name[0] > DataSet[j].name[0])
			{	
				temp = DataSet[j];
				DataSet[j] = DataSet[j - 1];
				DataSet[j - 1] = temp;
			} 
			else if (DataSet[j - 1].name[0] == DataSet[j].name[0])
			{
				if (DataSet[j - 1].name[1] > DataSet[j].name[1])//Sort by score. 
				{	                                           
					temp = DataSet[j];
					DataSet[j] = DataSet[j - 1];
					DataSet[j - 1] = temp;
				}
			}
		}
	}
	for (i = 0; i < 20; i++)
	{
		printf("%s %d %d %c\n", DataSet[i].name, DataSet[i].number, DataSet[i].age, DataSet[i].score);
    }
}

void ArrayNum(STU DataSet[], int len){//Sort by stdID

	int i, j;
	STU temp;

	for (i = 0; i<len - 1; i++)
	{
		for (j = 1; j < len; j++)
		{
			if( DataSet[j - 1].number > DataSet[j].number) 
			{	                 
				temp = DataSet[j];
				DataSet[j] = DataSet[j - 1];
				DataSet[j - 1] = temp;
			}
		}
	}
	for (i = 0; i < 20; i++)
	{
		printf("%s %d %d %c\n", DataSet[i].name, DataSet[i].number, DataSet[i].age, DataSet[i].score);
	}
}

void ArrayAge(STU DataSet[], int len){//sort by age

	int i, j;
	STU temp;

	for (i = 0; i<len - 1; i++)
	{
		for (j = 1; j < len; j++)
		{
			if (DataSet[j - 1].age < DataSet[j].age) 
			{	
				temp = DataSet[j];
				DataSet[j] = DataSet[j - 1];
				DataSet[j - 1] = temp;
			}
		}
	}
	for (i = 0; i < 20; i++)
	{
		printf("%s %d %d %c\n", DataSet[i].name, DataSet[i].number, DataSet[i].age, DataSet[i].score);
	}
}

void ArrayScore(STU DataSet[], int len){//sort by score

	int i, j;
	STU temp;

	for (i = 0; i<len - 1; i++)
	{
		for (j = 1; j < len; j++)
		{
			if (DataSet[j - 1].score > DataSet[j].score)
			{	             
				temp = DataSet[j];
				DataSet[j] = DataSet[j - 1];
				DataSet[j - 1] = temp;
			}
		}
	}
	for (i = 0; i < 20; i++)
	{
		printf("%s %d %d %c\n", DataSet[i].name, DataSet[i].number, DataSet[i].age, DataSet[i].score);
	}
}


