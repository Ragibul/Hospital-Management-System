#include<stdio.h>
char pass_word[10]=("emle");

void docsec();
void patient_sec();
int checkid();

struct hospital
{


       char doc_name[30];
       int doc_id;
       char doc_degree[30];
       char doc_schedule[30];
       char doc_cellnumber [30];


        char pat_name[30];
        int pat_id;
        char pat_dis[30];
        char pat_bedNo[30];
        char pat_cellnumber[30];

};


struct hospital t1;

//files for doc section
FILE *doc_address,*ft;
//files for patient section
FILE *patient_address,*ft;


void mainmenu();

//char username[20]={};
//char password[20]={};
//void mainmenu();

//                         doctor section


void addingdoc()
{
    int ch;
   system("cls");

	doc_address=fopen("doctor.txt","ab+");
	if(get_doc_data()==1)
	{
	fseek(doc_address,0,SEEK_END);
	fwrite(&t1,sizeof(t1),1,doc_address);
	fclose(doc_address);
	printf("The record is sucessfully saved");
	printf("Save any more?(Y / N)or back to main menu press M:");
	if((ch=getch())=='n'||ch=='N')
	{
	    docsec();
	}
    else if(ch=='Y')
    {
        system("cls");
	    addingdoc();
    }
    else if(ch=='M'||ch=='m')
       mainmenu();
	}
}
void editingdoc()
{
    int ch;
     int c=0;
	int d,e;

	char another='y';
	while(another=='y')
	{
		system("cls");
		printf("Enter doctor's Id to be edited:");
		scanf("%d",&d);
		doc_address=fopen("doctor.txt","rb+");
		while(fread(&t1,sizeof(t1),1,doc_address)==1)
		{
			if(checkid(d)==0)
			{
                int t;
				printf("\n\n\n*********data perviously stored**********\n\n\n");
				printf("his name is=%s\n",t1.doc_name);
				printf("his id is=%d\n",t1.doc_id);
                printf("his degree is=%s\n",t1.doc_degree);
                printf("his schedule is=%s\n",t1.doc_schedule);
                printf("his cell number is=%s\n\n\n\n",t1.doc_cellnumber);

                printf("\n\n*********editing pervious stored data**********\n\n\n");
				printf("modify doctor name:");
                scanf("%s",&t1.doc_name);

                printf("modify doctor id:");
                scanf("%d",&t);
                t1.doc_id=t;

                printf("modify doctor degree:");
                scanf("%s",&t1.doc_degree);

                printf("modify doctor schedule:");
                scanf("%s",&t1.doc_schedule);

                printf("modify doctor cellnumber:");
                scanf("%s",t1.doc_cellnumber);

                printf("The record is modified");
				fseek(doc_address,ftell(doc_address)-sizeof(t1),0);
				fwrite(&t1,sizeof(t1),1,doc_address);
				fclose(doc_address);
				c=1;
			}
			if(c==0)
			{
				printf("No record found");
			}
		}

		printf("Modify another Record?(Y/N) or back to main menu press M");
		if((ch=getch())=='n'||ch=='N')
        {
            docsec();
        }
        else if(ch=='Y')
        {
            system("cls");
            addingdoc();
        }
        else if(ch=='M'||ch=='m')
            mainmenu();
        }
        docsec();
}
void searching_doc()
{
    int ch;
    int c=0;
	int d,e;

	char another='y';
	while(another=='y')
	{
		system("cls");
		printf("Enter doctor's Id to be search:");
		scanf("%d",&d);
		doc_address=fopen("doctor.txt","rb+");
		while(fread(&t1,sizeof(t1),1,doc_address)==1)
        {


			if(checkid(d)==0)
			{
                int t;
				printf("\n\n\n*********data perviously stored**********\n\n\n");
				printf("his name is=%s\n",t1.doc_name);
				printf("his id is=%d\n",t1.doc_id);
                printf("his degree is=%s\n",t1.doc_degree);
                printf("his schedule is=%s\n",t1.doc_schedule);
                printf("his cell number is=%s\n\n\n\n",t1.doc_cellnumber);

            }
		}
		printf("do you want to search again?(Y/N) or back to main menu press M");
    if((ch=getch())=='n'||ch=='N')
	{
	    docsec();
	}
    else if(ch=='Y')
    {
        system("cls");
	    addingdoc();
    }
    else if(ch=='M'||ch=='m')
       mainmenu();
    }
    //docsec();
}
void listof_docs()
{
    doc_address=fopen("doctor.txt","rb");
    while(fread(&t1,sizeof(t1),1,doc_address)==1)
    {

        printf("%d\t",t1.doc_id);

        printf("%s\t",strupr(t1.doc_name));

        printf("%s\t",strupr(t1.doc_schedule));

        printf("\n\n");

    }
    getch();
      fclose(doc_address);
}
void docsec()
{
    system("cls");
    printf("1.adding new docs\n");
    printf("2.editing new docs\n");
    printf("3.searching docs by id or name \n");
    printf("4.list of docs\n");
    printf("5.back to the main menu\n");

    int choice;
    printf("enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
    system("cls");
        addingdoc();
        break;
    case 2:
    system("cls");
        editingdoc();
        break;
    case 3:
    system("cls");
        searching_doc();
        break;
    case 4:
    system("cls");
        listof_docs();
        break;
    case 5:
    system("cls");
        mainmenu();
            break;

    }

}



//                      end of doc section

void adding_patients()
{
    int ch;
   system("cls");

	patient_address=fopen("patient.txt","ab+");
	if(get_patient_data()==1)
	{
	fseek(patient_address,0,SEEK_END);
	fwrite(&t1,sizeof(t1),1,patient_address);
	fclose(patient_address);
	printf("The record is sucessfully saved");
	printf("Save any more?(Y / N) or back to main menu press M:");
	if((ch=getch())=='n'||ch=='N')
	{
	    patient_sec();
	}
    else if(ch=='Y')
    {
        system("cls");
	    adding_patients();
    }
    else if(ch=='M'||ch=='m')
       mainmenu();
	}

}

void editingpatients()
{
    int ch;
    int c=0;
	int d,e;

	char another='y';
	while(another=='y')
	{
		system("cls");
		printf("Enter patient's Id to be edited:");
		scanf("%d",&d);
		patient_address=fopen("patient.txt","rb+");
		while(fread(&t1,sizeof(t1),1,patient_address)==1)
		{
			if(checkid4pat(d)==0)
			{
                int t;
				printf("\n\n\n*********data perviously stored**********\n\n\n");
				printf("his name is=%s\n",t1.pat_name);
				printf("his id is=%d\n",t1.pat_id);
                printf("his dis is=%s\n",t1.pat_dis);
                printf("his bedNo is=%s\n",t1.pat_bedNo);
                printf("his cell number is=%s\n\n\n\n",t1.pat_cellnumber);

                printf("\n\n*********editing pervious stored data**********\n\n\n");
				printf("modify patient name:");
                scanf("%s",&t1.pat_name);

                printf("modify patient id:");
                scanf("%d",&t);
                t1.pat_id=t;

                printf("modify patient dis:");
                scanf("%s",&t1.pat_dis);

                printf("modify patient bedNo:");
                scanf("%s",&t1.pat_bedNo);

                printf("modify patient cellnumber:");
                scanf("%s",t1.pat_cellnumber);

                printf("The record is modified");
				fseek(patient_address,ftell(patient_address)-sizeof(t1),0);
				fwrite(&t1,sizeof(t1),1,patient_address);
				fclose(patient_address);
				c=1;
			}
			if(c==0)
			{
				printf("No record found");
			}
		}

		printf("Modify another Record?(Y/N) or back to main menu press M");
    if((ch=getch())=='n'||ch=='N')
	{
	    patient_sec();
	}
    else if(ch=='Y')
    {
        system("cls");
	    adding_patients();
    }
    else if(ch=='M'||ch=='m')
       mainmenu();
    }
    //patient_sec();
}
void searchingpatients()
{
    int ch;
    int c=0;
	int d,e;

	char another='y';
	while(another=='y')
	{
		system("cls");
		printf("Enter patient's Id to be search:");
		scanf("%d",&d);
		patient_address=fopen("patient.txt","rb+");
		while(fread(&t1,sizeof(t1),1,patient_address)==1)
        {


			if(checkid(d)==0)
			{
                int t;
				printf("\n\n\n*********data perviously stored**********\n\n\n");
				printf("his name is=%s\n",t1.pat_name);
				printf("his id is=%d\n",t1.pat_id);
                printf("his dis is=%s\n",t1.pat_dis);
                printf("his bedNo is=%s\n",t1.pat_bedNo);
                printf("his cell number is=%s\n\n\n\n",t1.pat_cellnumber);

            }
		}
		 printf("do you want to search again?(Y/N) or back to main menu press M");
    if((ch=getch())=='n'||ch=='N')
	{
	    patient_sec();
	}
    else if(ch=='Y')
    {
        system("cls");
	    adding_patients();
    }
    else if(ch=='M'||ch=='m')
       mainmenu();
    }
    //patient_sec();
}
void listofpatients()
{
    patient_address=fopen("patient.txt","rb");
    while(fread(&t1,sizeof(t1),1,patient_address)==1)
    {

        printf("%d\t",t1.pat_id);

        printf("%s\t",strupr(t1.pat_name));

        printf("%s\t",strupr(t1.pat_bedNo));

        printf("\n\n");

    }
    getch();
      fclose(patient_address);
}

void patient_sec()
{
    int choice;
    system("cls");
    printf("1.adding new patients\n");
    printf("2.editing new patients\n");
    printf("3.searching patients by id or name \n");
    printf("4.list of patients\n");
    printf("5.back to the main menu\n");


    printf("enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
    system("cls");
        adding_patients();
        break;
    case 2:
    system("cls");
        editingpatients();
        break;
    case 3:
    system("cls");
        searchingpatients();
        break;
    case 4:
    system("cls");
        listofpatients();
    break;
    case 5:
    system("cls");
        mainmenu();
        break;
    }


}



void password()
{
    char ch;
    char pass[10];
    int i=0;
    printf("Enter Password:");
    while(ch!=13)
    {
	  ch=getch();
     if(ch!=13 && ch!=8){
	  putch('*');
	  pass[i] = ch;
	  i++;
	  }
    }
   pass[i] = '\0';
   if(strcmp(pass,pass_word)==0)
   {


	printf("\nPassword match");

	printf("\nPress any key to countinue.....");
	getch();
	mainmenu();
   }
   else
   {
	 printf("\n\aWarning!! Incorrect Password");
	 getch();
   }
}

    //{*
       // mainmenu();
    //}

    //else
    //{
      //  printf("enter correct username and pass");
        //getch();
    //}

//Main menu//
void mainmenu()
{
     system("cls");
     printf("1.Doctor's section");
     printf("\n2.Patient's section");
     printf("\n3.Exit");

     int choice;
     printf("\n\nenter your choice:");
     scanf("%d",&choice);
     switch(choice)
     {
          case 1:
    docsec();
    break;
    case 2:
    patient_sec();
    break;
    case 3:
    break;
     }

}

//adding data for docs

int get_doc_data()
{
	int t;
	printf("enter doctor name:");
	scanf("%s",&t1.doc_name);

	printf("enter doctor id:");
	scanf("%d",&t);
    t1.doc_id=t;

	printf("enter doctor degree:");
	scanf("%s",&t1.doc_degree);

	printf("enter doctor schedule:");
	scanf("%s",&t1.doc_schedule);

	printf("enter doctor cellnumber:");
	scanf("%s",t1.doc_cellnumber);

	return 1;
}
int get_patient_data()
{
	int t;
	printf("enter patient name:");
	scanf("%s",&t1.pat_name);

	printf("enter patient id:");
	scanf("%d",&t);
	t1.pat_id=t;

	printf("enter patient dis:");
	scanf("%s",&t1.pat_dis);

	printf("enter patient bedNo:");
	scanf("%s",&t1.pat_bedNo);

	printf("enter patient cellnumber:");
	scanf("%s",&t1.pat_cellnumber);

	return 1;
}
int checkid(int t)
{
	rewind(doc_address);
	while(fread(&t1,sizeof(t1),1,doc_address)==1)
	if(t1.doc_id==t)
	{
	   return 0;
	}
         //returns 0 if id exits
    return 1; //return 1 if it not
}
int checkid4pat(int t)
{
	rewind(patient_address);
	while(fread(&t1,sizeof(t1),1,patient_address)==1)
	if(t1.pat_id==t)
	{
	   return 0;
	}
         //returns 0 if id exits
    return 1; //return 1 if it not
}
void main()
{
    password();

}
