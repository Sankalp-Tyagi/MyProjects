#include<stdio.h>
void welcomeMessage();
void doubtforum();
void stdinfo();
void timetable();
void welcome(void);
void doubtwelcome();
void timetwelcome();
void it(int d);
void ece(int q);
void exit();
int grade(int);
float percentage(int, int, int);
int CGPA(int);
struct student
{
    char name[50];
    int id;
    char department[20];
    int phone_no;
    int physics_marks;
    int maths_marks;
    int sdf_marks;
};
int main()
{
    int mch;
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printf("\t\t\t###########################################################################");
    printf("\t\t\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############            S.D.F - 1 Lab Project in 'C'           ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################\n");
    printf("\t\t\t###########################################################################");
    printf("\t\t\t\t\t---------------------------------------------------------------------------\n");
    printf("\n\t\t\t----------------------------------------------------------------------------");
    welcomeMessage();
mainmm :
    printf("\nWELCOME !!! TO YOUR ONE AND ONLY COLLEGE DESTINATION : THE COLLEGE BUDDY\n");
    printf("FOLLOWING ARE THE AVAILABLE OPTIONS TO FULFILL YOUR DESIRES : \n");
    printf("----------------------------------*");
    printf("\n1 . Student Information Portal\n");
    printf("----------------------------------*");
    printf("\n2 . Doubt Forum\n");
    printf("----------------------------------*");
    printf("\n3 . Time Table Viewer\n");
    printf("----------------------------------*");
    printf("\n4 . Exit\n");
    printf("----------------------------------*");
    printf("\nEnter Your Respective Choice : ");
    scanf("%d", &mch);
    switch(mch)
    {
    case 1 :
        system("cls");
        stdinfo();
        break;
    case 2 :
        system("cls");
        doubtforum();
        break;
    case 3 :
        system("cls");
        timetable();
        break;
    case 4 :
        system("cls");
        exit();
        break;
    default :
        printf("Wrong Choice Entered !!!\n");
        printf("Press any key to return to main menu : ");
        getch();
        system("cls");
        goto mainmm;
    }

    return 0;
}
//Display message
void welcomeMessage()
{
    printf("\n\n\n\n\n");
    printf("\n\t\t\t\t  *---------------------------------------------------------*\n");
    printf("\n\t\t\t\t        *********************************************");
    printf("\n\t\t\t\t        *                                           *");
    printf("\n\t\t\t\t        *                  WELCOME                  *");
    printf("\n\t\t\t\t        *                    TO                     *");
    printf("\n\t\t\t\t        *                  COLLEGE                  *");
    printf("\n\t\t\t\t        *                   BUDDY                   *");
    printf("\n\t\t\t\t        *                                           *");
    printf("\n\t\t\t\t        *********************************************\n");
    printf("\n\t\t\t\t  *---------------------------------------------------------*\n");
    printf("\n\n\n\t\t\t\t Enter any key to continue.....");
    getch();
}
//Student Information Portal
void stdinfo()
{
    struct student S[6]=
    {
        {"Shreevardhan",100,"CSE",98989898,88,80,89},
        {"Sankalp",101,"CSE",87878787,94,85,83},
        {"Abhay",102,"IT",76767676,90,85,93},
        {"Devansh",103,"IT",65656565,91,80,79},
        {"Ajaydeep",104,"ECE",54545454,94,78,79},
        {"Lokendra",105,"ECE",43434343,74,95,90},
    };
    int digit;
    float average;
    welcome();
mmm :
    printf("\t MAIN MENU\n");
    printf("\n");
    printf("1. Modify student record\n");
    printf("2. Delete student record\n");
    printf("3. Search student record\n");
    printf("4. Display the marks of the student\n");
    printf("5. Show the CGPA and GRADE of the student from the stored record\n");
    printf("6. Show the students information of the your batch\n");
    printf("7. Exit\n");
    printf("Enter the respective option you want to perform :");
    scanf("%d",&digit);
    int enroll,i,option,change;
    char stud[40],dept[20];

    switch(digit)
    {
    case 1:
        printf("Enter the ID of the student you want to modify\n");//starting of modify case
        scanf("%d",&enroll);
        printf("Enter the Name of the student \n");
        scanf("%s",stud);
        for(i=0; i<6; i++)
        {
            if(strcmp(stud,S[i].name)==0 && enroll == S[i].id)
            {
                printf("Press '1' to change the ID\n");
                printf("Press '2' to change the DEPARTMENT\n");
                printf("Press '3' to change the PHONE NO.\n");
                scanf("%d",&option);
                /*change of the marks, uploaded by the teacher is not allowed through this portal*/
                if(option==1)
                {
                    printf("Enter the new specific ID of the student\n");
                    scanf("%d",&change);
                    S[i].id = change;
                }
                else if(option==2)
                {
                    printf("Enter the new department of the student\n");
                    scanf("%s",S[i].department);
                }
                else if(option==3)
                {
                    printf("Enter the new phone no. of the student\n");
                    scanf("%d",&change);
                    S[i].phone_no = change;
                }
            }
        }
        printf("\nPress any key to return to main menu : ");
        getch();
        system("cls");
        goto mmm;
        break;
    //ending of modify case.
    case 2:
        printf("Enter the ID of the student you want to delete\n");//starting of delete case.
        scanf("%d",&enroll);
        printf("Enter the Name of the student \n");
        scanf("%s",stud);
        for(i=0; i<6; i++)
        {
            if(strcmp(stud,S[i].name)==0&& enroll == S[i].id)
            {
                strcpy(S[i].department, "Deleted");
                S[i].phone_no=0;
                printf("You have deleted the record of %s\n",S[i].name);
            }
        }
        printf("\nPress any key to return to main menu : ");
        getch();
        system("cls");
        goto mmm;
        break;
    //end of delete case.
    case 3:
        printf("Enter the ID of the student you want to search record of\n");//starting of search student case.
        scanf("%d",&enroll);
        printf("Enter the Name of the student \n");
        scanf("%s",stud);
        for(i=0; i<6; i++)
        {
            if(strcmp(stud,S[i].name)==0 && enroll==S[i].id)
            {
                printf(" Name %s",S[i].name);
                printf(" Id of the student is %d\n",S[i].id);
                printf(" Department of the student is %s\n",S[i].department);
                printf(" Phone number of the student is %d\n",S[i].phone_no);
                printf(" The Marks of the student are as follows\n");
                printf("PHYSICS - %d\n",S[i].physics_marks);
                printf("MATHS - %d\n",S[i].maths_marks);
                printf("SDF - %d\n",S[i].sdf_marks);
            }
        }
        printf("\nPress any key to return to main menu : ");
        getch();
        system("cls");
        goto mmm;
        break;
    //ending of search student case.
    case 4:
        printf("Enter the ID of the student you want to be displayed\n");//starting of Display CGPA and marks case
        scanf("%d",&enroll);
        printf("Enter the Name of the student \n");
        scanf("%s",stud);
        for(i=0; i<6; i++)
        {
            if(strcmp(stud,S[i].name)==0 && enroll==S[i].id)
            {
                printf("* The Marks of the student are as follows\n");
                printf("PHYSICS - %d\n",S[i].physics_marks);
                printf("MATHS - %d\n",S[i].maths_marks);
                printf("SDF - %d\n",S[i].sdf_marks);
                average = percentage(S[i].physics_marks, S[i].maths_marks, S[i].sdf_marks);
                printf("And the percentage he had scored is %f\n ",average);
            }
        }
        printf("\nPress any key to return to main menu : ");
        getch();
        system("cls");
        goto mmm;
        break;
    //end of Display the marks case.
    case 5:
        printf("Enter the ID of the student you want to show the CGPA of\n");//starting of Display the marks case.
        scanf("%d",&enroll);
        int cgp;
        printf("Enter the Name of the student \n");
        scanf("%s",stud);
        for(i=0; i<6; i++)
        {
            if(strcmp(stud,S[i].name)==0 && enroll==S[i].id)
            {
                int value= percentage(S[i].physics_marks, S[i].maths_marks, S[i].sdf_marks);
                printf("                                   DISPLAY                                    ");
                printf("\n\n---------------------------------------------------------------------------------");
                printf("\n\tSTUDENT NAME\t\t|\tSTUDENT ID\t|\tSTUDENT DEPT\t|\tSTUDENT PERCENTAGE\t|\t");
                printf("\n---------------------------------------------------------------------------------\n");
                printf("\n\t%s\t\t|\t%s\t\t|\t%d\t\t|\t%d\t\t|\t\n",S[i].name,S[i].department,S[i].id,value);
                cgp=CGPA(value);
                printf("YOU HAVE OBTAINED A CGPA OF %d",cgp);
            }
        }
        printf("\nPress any key to return to main menu : ");
        getch();
        system("cls");
        goto mmm;
        break;
    //ending of Display the marks case.
    case 6:
        printf("The batch code of ECE is 001\n"); /*show students info*/
        printf("The batch code of CSE is 002\n");
        printf("The batch code of IT is 003\n");
        int batch;
        int cg;
        printf("Enter the code of the respective batch that you want information of :");
        scanf("%d",&batch);
        int *B;
        B=&batch;
        if(*B==001)
        {
            printf("\nBRANCH SELECTED - ECE");
            printf("\n------------------------------------------------------------------------------------------------------------\n");
            average = percentage(94,78,79);
            cg=CGPA(average);
            printf("\n\tSTUDENT NAME\t\t|\tSTUDENT ID\t|\tSTUDENT DEPT\t|\tSTUDENT PERCENTAGE\t|\t");
            printf("\n------------------------------------------------------------------------------------------------------------\n");
            printf("\n\t%s\t\t|\t%d\t\t|\t%s\t\t|\t\t%d\t\t|\t\t\n",S[4].name,S[4].id,S[4].department,cg);
            average = percentage(74,95,90);
            cg=CGPA(average);
            printf("\n------------------------------------------------------------------------------------------------------------\n");
            printf("\n\t%s\t\t|\t%d\t\t|\t%s\t\t|\t\t%d\t\t|\t\t\n",S[5].name,S[5].id,S[5].department,cg);
        }
        if(*B==002)
        {
            printf("\nBRANCH SELECTED - CSE");
            printf("\n------------------------------------------------------------------------------------------------------------\n");
            average = percentage(88,80,89);
            cg=CGPA(average);
            printf("\n\tSTUDENT NAME\t\t|\tSTUDENT ID\t|\tSTUDENT DEPT\t|\tSTUDENT PERCENTAGE\t|\t");
            printf("\n------------------------------------------------------------------------------------------------------------\n");
            printf("\n\t%s\t\t|\t%d\t\t|\t%s\t\t|\t\t%d\t\t|\t\t\n",S[0].name,S[0].id,S[0].department,cg);
            average = percentage(94,85,83);
            cg=CGPA(average);
            printf("\n------------------------------------------------------------------------------------------------------------\n");
            printf("\n\t%s\t\t\t|\t%d\t\t|\t%s\t\t|\t\t%d\t\t|\t\t\n",S[1].name,S[1].id,S[1].department,cg);
        }
        if(*B==003)
        {
            printf("\nBRANCH SELECTED - IT");
            printf("\n------------------------------------------------------------------------------------------------------------\n");
            average = percentage(90,85,93);
            cg=CGPA(average);
            printf("\n\tSTUDENT NAME\t\t|\tSTUDENT ID\t|\tSTUDENT DEPT\t|\tSTUDENT PERCENTAGE\t|\t");
            printf("\n------------------------------------------------------------------------------------------------------------\n");
            printf("\n\t%s\t\t\t|\t%d\t\t|\t%s\t\t|\t\t%d\t\t|\t\t\n",S[2].name,S[2].id,S[2].department,cg);
            average = percentage(91,80,79);
            cg=CGPA(average);
            printf("\n------------------------------------------------------------------------------------------------------------\n");
            printf("\n\t%s\t\t\t|\t%d\t\t|\t%s\t\t|\t\t%d\t\t|\t\t\n",S[3].name,S[3].id,S[3].department,cg);
        }
        printf("\nPress any key to return to main menu : ");
        getch();
        system("cls");
        goto mmm;
        break;
    case 7 :
        break;
    default :
        printf("WRONG CHOICE ENTERED !!!\n");
        printf("Press any key to return to menu ...");
        getch();
        goto mmm;
        break;

    }
}
void welcome(void)
{
    printf("       *********************************************\n");
    printf("       *********************************************\n");
    printf("       WELCOME TO STUDENT DATABASE MANAGEMENT SYSTEM\n");
    printf("       *********************************************\n");
    printf("       *********************************************\n\n\n");
}
float percentage(int x, int y, int z)
{
    float per;
    per=(x+y+z)/3;
    return per;
}
int CGPA(int x)
{
    int a=x/9.5;
    return a;
}
//DOUBT FORUM
void doubtforum()
{
    doubtwelcome();
    int doubt, acdoubt, sbjdoubt, subject, sem;
    FILE *fp1;
    FILE *fp2;
    char doub[200], paper[1000];
mm :
    printf("\nYOU SEEM TO BE IN TROUBLE, HMMM....\n");
    printf("What kind of problem are you facing : \n");
    printf("------------------------------");
    printf("\n1 . Academic Doubt\n");
    printf("------------------------------");
    printf("\n2 . Subjective Doubt\n");
    printf("------------------------------");
    printf("\n3 . Other Problem\n");
    printf("------------------------------");
    printf("\n4 . Exit\n");
    printf("------------------------------\n");
    printf("Enter your choice : ");
    scanf("%d", &doubt);
    printf("\n\n");
    switch(doubt)
    {
    case 1 :
        printf("Would you like to elaborate your problem By choosing something from below :\n");
        printf("1 . Information Regarding events\n");
        printf("2 . Information Regarding Exams\n");
        printf("3 . Counsellor talk\n");
        printf("4 . Registrar or Office issues\n");
        printf("5 . Others\n");
        printf("Enter your choice : ");
        scanf("%d", &acdoubt);
        printf("\n\n");
        switch(acdoubt)
        {
        case 1 :
            printf("22nd December , 2022 : \n2nd International Conference on Advanced\nMaterials and Nanotechnology organised by\nDept of PMSE from 22 - 24 December 2022\n");
            printf("\n");
            printf("18th January , 2023 : \n6th International Conference in 'Advances in\nBiosciences &Biotechnology' January 18 - 20, 2023 by Department of Biotechnology.\n");
            printf("\n");
            printf("2nd February , 2023 : \nOfficial Annual Tech-Fest both at JIIT Sector\n 62 and 128 from 2nd-3rd February , 2023");
            printf("\nPress any key to return to main menu : ");
            getch();
            system("cls");
            goto mm;
            break;
        case 2 :
            printf("Enter your current semester : ");
            scanf("%d",&sem);
            if(sem == 1)
            {
                printf("End semester exams : \n3rd Janauary , 2023 onwards");
            }
            else
            {
                printf("End semester exams : \n12th December , 2022 onwards");
            }
            printf("\nPress any key to return to main menu : ");
            getch();
            system("cls");
            goto mm;
            break;
        case 3 :
            printf("Kindly contact the Counsellor's Office\nLocated near the Engineering Drawing Lab\nin front of the H3 Hostel\n");
            printf("\nPress any key to return to main menu : ");
            getch();
            system("cls");
            goto mm;
            break;
        case 4 :
            printf("Kindly contact the Registrar's office located on IIIrd floor of ABB-III \nOr contact them through : registrar@mail.jiit.ac.in\nTelephone : 0591-452684");
            printf("\nPress any key to return to main menu : ");
            getch();
            system("cls");
            goto mm;
            break;
        case 5 :
            printf("If you have any other doubt kindly post your problem followed by your enrollment number\nand your query will be resolved by posting\nthe solution as soon as possible\n");
            printf("Enter your query : ");
            fflush(stdin);
            gets(doub);
            fp1 = fopen("DOUBTS.txt", "a");
            fputs(doub, fp1);
            fclose(fp1);
            printf("Thank you for posting your problem , It helps us improve our system .");
            printf("\nPress any key to return to main menu : ");
            getch();
            system("cls");
            goto mm;
            break;
        default :
            printf("Wrong choice entered\n");
            printf("\nPress any key to return to main menu : ");
            getch();
            system("cls");
            goto mm;
        }
    case 2 :
        printf("\nSubjective Doubts are of the utmost importance to be resolved for a student.\n");
        printf("Kindly elaborate the kind of problem you are facing by choosing an option from below : \n");
        printf("1 . Subject and teacher related query\n");
        printf("2 . Previous year papers and materials\n");
        printf("3 . Other issue");
        printf("Please Enter your choice : ");
        scanf("%d", &sbjdoubt);
        switch(sbjdoubt)
        {
        case 1 :
            printf("\nIt seems you have any subjectial problem\nPlease choose the subject from below to know more about the concerned teachers\nwho are an expertise in the same\n");
            printf("1 . Deptt of Mathematics\n");
            printf("2 . Deptt of Physics\n");
            printf("3 . Deptt of CSE / IT\n");
            printf("4 . Deptt of ECE\n");
            printf("5 . Deptt of HSS / Life Skills\n");
            printf("Enter Your Choice : ");
            scanf("%d", &subject);
            switch(subject)
            {
            case 1 :
                printf("\nFollowing is the list of faculty with their contact details for your help :\n");
                printf("*****************************************************************************\n");
                printf("1 . Prof . Alka Tripathi (Professor & Head) ---> alka.choubey@jiit.ac.in\n");
                printf("\n2 . Prof . Ramesh Chand Mittal ( Professor ) ---> rc.mittal@jiit.ac.in\n");
                printf("\n3 . Prof . Amrish Kumar Aggarwal ( Professor ) ---> amrish.aggarwal@jiit.ac.in\n");
                printf("\n4 . Prof . Bhagwati Prasad Chamola ( Professor ) ---> bhagwati.prasad@jiit.ac.in\n");
                printf("\n5 . Dr . Pankaj Kumar Srivastava (Associate Professor) ---> pankaj.srivastava@jiit.ac.in\n");
                printf("\nPress any key to return to main menu : ");
                getch();
                system("cls");
                goto mm;
                break;
            case 2 :
                printf("\nFollowing is the list of faculty with their contact details for your help :\n");
                printf("*****************************************************************************\n");
                printf("1 . Prof . D.K. Rai ( Professor & Dean[A & R] ) ---> dk.rai@jiit.ac.in\n");
                printf("\n2 . Prof . Anirban Pathak ( Professor & HOD ) ---> anirbanpathak@yahoo.co.in\n");
                printf("\n3 . Prof . S.P. Purohit ( Professor ) ---> sp.purohit@jiit.ac.in\n");
                printf("\n4 . Dr . Suneet Kumar Awasthi ( Associate Professor ) ---> suneet.awasthi@mail.jiit.ac.in\n");
                printf("\n5 . Dr . Sandeep Kumar ( Associate Professor ) ---> manoj.chauhan@mail.jiit.ac.in\n");
                printf("\nPress any key to return to main menu : ");
                getch();
                system("cls");
                goto mm;
                break;
            case 3 :
                printf("\nFollowing is the list of faculty with their contact details for your help :\n");
                printf("*****************************************************************************\n");
                printf("1 . Prof . Vikas Saxena ( Professor & Head (CSE & IT) ) ---> vikas.saxena@jiit.ac.in\n");
                printf("\n2 . Prof . Krishna Aswas ( Professor ) ---> krishna.aswas@jiit.ac.in\n");
                printf("\n3 . Prof . Sandeep Kumar Singh ( Professor ) ---> sandeepk.singh@jiit.ac.in\n");
                printf("\n4 . Prof . Satish Chandra ( Professor ) ---> satish.chandra@jiit.ac.in\n");
                printf("\n5 . Prof . Charu ( Professor ) ---> charu.gandhi@jiit.ac.in\n");
                printf("\nPress any key to return to main menu : ");
                getch();
                system("cls");
                goto mm;
                break;
            case 4 :
                printf("\nFollowing is the list of faculty with their contact details for your help :\n");
                printf("*****************************************************************************\n");
                printf("1 . Prof . Shweta Srivastava ( Professor and Head ) ---> shweta.srivastava@jiit.ac.in\n");
                printf("\n2 . Prof . Rajiv Saxena ( Adjunct Professor ) ---> rajiv.saxena@jiit.ac.in\n");
                printf("\n3 . Prof . Jitendra Mohan ( Professor , Associate Dean ) ---> jitendra.mohan@jiit.ac.in\n");
                printf("\n4 . Prof . Sajai Vir Singh ( Professor ) ---> sajaivir.singh@jiit.ac.in\n");
                printf("\n5 . Dr . Vineet Khandelwal ( Associate Professor ) ---> vineet.khandelwal@jiit.ac.in\n");
                printf("\nPress any key to return to main menu : ");
                getch();
                system("cls");
                goto mm;
                break;
            case 5 :
                printf("\nFollowing is the list of faculty with their contact details for your help :\n");
                printf("*****************************************************************************\n");
                printf("1 . Prof . Alka Sharma ( Dean ( Humanities ) ) ---> alka.sarma@jiit.ac.in\n");
                printf("\n2 . Dr . Mukta Mani ( Associate Professor ) ---> mukta.mani@jiit.ac.in\n");
                printf("\n3 . Dr . Monali Bhattacharaya ( Associate Professor ) ---> monali.bhattacharaya@jiit.ac.in\n");
                printf("\n4 . Dr . Nilu Choudhary ( Associate Professor ) ---> nilu.choudhary@jiit.ac.in\n");
                printf("\n5 . Dr . Ekta Singh ( Associate Professor ) ---> ekta.singh@mail.jiit.ac.in\n");
                printf("\nPress any key to return to main menu : ");
                getch();
                system("cls");
                goto mm;
                break;
            default :
                printf("Wrong choice entered\n");
                printf("\nPress any key to return to main menu : ");
                getch();
                system("cls");
                goto mm;
            }
        case 2 :
            printf("Enter your current semester : ");
            scanf("%d", &sem);
            fp2 = fopen("PREVIOUSYEARS.txt", "r");
            fgets(paper, 1000, fp2);
            printf("%s\n", paper);
            fclose(fp2);
            printf("\nPress any key to return to main menu : ");
            getch();
            system("cls");
            goto mm;
            break;
        case 3 :
            printf("If you have any other doubt kindly post your problem followed by your enrollment number\nand your query will be resolved by posting\nthe solution as soon as possible\n");
            printf("Enter your query : ");
            fflush(stdin);
            gets(doub);
            fp1 = fopen("DOUBTS.txt", "a");
            fputs(doub, fp1);
            fclose(fp1);
            printf("Thank you for posting your problem , It helps us improve our system .");
            printf("\nPress any key to return to main menu : ");
            getch();
            system("cls");
            goto mm;
            break;
        }
    case 3 :
        printf("If you have any other doubt kindly post your problem followed by your enrollment number\nand your query will be resolved by posting\nthe solution as soon as possible\n");
        printf("Enter your query : ");
        fflush(stdin);
        gets(doub);
        fp1 = fopen("DOUBTS.txt", "a");
        fputs(doub, fp1);
        fclose(fp1);
        printf("Thank you for posting your problem , It helps us improve our system .");
        printf("\nPress any key to return to main menu : ");
        getch();
        system("cls");
        goto mm;
        break;
    case 4 :
        break;
    default :
        printf("Wrong choice entered\n");
        printf("\nPress any key to return to main menu : ");
        getch();
        system("cls");
        goto mm;
    }
}
void doubtwelcome()
{
    printf("\t\t\t\t********************************************\n");
    printf("\t\t\t\t********************************************\n");
    printf("\t\t\t\t*******         WELCOME              *******\n");
    printf("\t\t\t\t*******            TO                *******\n");
    printf("\t\t\t\t*******      DOUBT - CENTRE          *******\n");
    printf("\t\t\t\t********************************************\n");
    printf("\t\t\t\t********************************************\n");
    printf("Press any key to continue : ....");
    getch();
}
//TIME TABLE
void timetable()
{
    timetwelcome();
    int ch,branch,day,day2;
    FILE *fp3;
    char guide[1000];
mainm:
    printf("\nGood to see you!!..\n");
    printf("All your schedule is here...\n");
    printf("What I can do for you-\n");
    printf("1 . SCHEDULE FOR THE DAY\n");
    printf("2 . CHECK FOR VACANT ROOM\n");
    printf("3 . CLASSROOM GUIDE\n");
    printf("4 . Exit\n");
    printf("");
    printf("-------------------------------------------------\n");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
    system("cls");
    printf("\n\n");
    switch(ch)
    {
    case 1:
        printf("Please choose your branch:\n");
        printf("1.I.T.\n");
        printf("2.E.C.E.\n");
        printf("-------------------------------------------------");
        printf("Enter your choice:");
        scanf("%d",&branch);
        system("cls");
        printf("\n\n");
        switch(branch)
        {
        case 1:
            printf("Please choose the week day:\n");
            printf("1.MONDAY\n");
            printf("2.TUESDAY\n");
            printf("3.WEDNESDAY\n");
            printf("4.THURSDAY\n");
            printf("5.FRIDAY\n");
            printf("6.SATURDAY\n");
            printf("-------------------------------------------------");
            printf("Enter your choice:");
            scanf("%d",&day);
            system("cls");
            printf("\n\n");
            it(day);
            printf("\n\nPress any key to return to main menu : ");
            getch();
            system("cls");
            goto mainm;
            break;

        case 2:
            printf("Please choose the week day:\n");
            printf("1.MONDAY\n");
            printf("2.TUESDAY\n");
            printf("3.WEDNESDAY\n");
            printf("4.THURSDAY\n");
            printf("5.FRIDAY\n");
            printf("6.SATURDAY\n");
            printf("-------------------------------------------------\n");
            printf("Enter your choice:");
            scanf("%d",&day);
            system("cls");
            printf("\n\n");
            ece(day);
            printf("\n\nPress any key to return to main menu : ");
            getch();
            system("cls");
            goto mainm;
            break;
        default:
            printf("Oops!! seems like you have entered a wrong choice\n");
            printf("\n\nPress any key to return to main menu : ");
            getch();
            system("cls");
            goto mainm;
            break;
        }

    case 2:
        printf("EXTRA CLASS??...The solution is here\n Check vacant room at one go-\n");
        printf("Please select the day:\n");
        printf("1.MONDAY\n");
        printf("2.TUESDAY\n");
        printf("3.WEDNESDAY\n");
        printf("4.THURSDAY\n");
        printf("5.FRIDAY\n");
        printf("6.SATURDAY\n");
        printf("-------------------------------------------------");
        printf("Enter your choice: ");
        scanf("%d",&day2);
        system("cls");
        printf("\n\n");
        switch(day2)
        {
        case 1:
            printf("9-9.50 :FF1,FF2,FF3\n");
            printf("10-10.50 : TS-8,TS-6\n");
            printf("11-11.50: FF2,FF3,FF4,FF5\n");
            printf("12-12.50 : LUNCH\n");
            printf("1-1.50 : FF2,TS-6,TS-8\n");
            printf("2-2.50 : G8,TS-7\n");
            printf("3-3.50 : FF3,FF4,G6\n");
            printf("4-4.50 : TS-6,TS-8\n");
            printf("\n\n Press any key to return to main menu : ");
            getch();
            system("cls");
            goto mainm;
            break;

        case 2:
            printf("9-9.50 : FF5,FF6,TS-9\n");
            printf("10-10.50 : G9,G6,FF1\n");
            printf("11-11.50: TS-2,FF6,FF2\n");
            printf("12-12.50 : G8,G6,FF1\n");
            printf("1-1.50 : TS-1,FF4,FF7\n");
            printf("2-2.50 : FF3,FF4,G6 \n");
            printf("3-3.50 : G9,FF1\n");
            printf("4-4.50 : F2,TS-6,TS-8\n");
            printf("\n\nPress any key to return to main menu : ");
            getch();
            system("cls");
            goto mainm;
            break;

        case 3:
            printf("9-9.50 : \n");
            printf("10-10.50 : \n");
            printf("11-11.50: F2,TS-6,TS-8\n");
            printf("12-12.50 : LUNCH\n");
            printf("1-1.50 : FF2,TS-6,TS-8\n");
            printf("2-2.50 : TS-1,FF4,FF7\n");
            printf("3-3.50 : TS-6,TS-8\n");
            printf("4-4.50 : G8,G6,FF1\n");
            printf("\n\nPress any key to return to main menu : ");
            getch();
            system("cls");
            goto mainm;
            break;

        case 4:
            printf("9-9.50 : G8,G6,FF1\n");
            printf("10-10.50 : F2,TS-6,TS-8\n");
            printf("11-11.50: TS-2,G8,FF5\n");
            printf("12-12.50 : LUNCH\n");
            printf("1-1.50 : TS-9,G7,FF6\n");
            printf("2-2.50 : FF6,FF7,TS-8\n");
            printf("3-3.50 : S-1,FF4,FF7\n");
            printf("4-4.50 : FF2,TS-6,TS-8\n");
            printf("\n\nPress any key to return to main menu : ");
            getch();
            system("cls");
            goto mainm;
            break;

        case 5:
            printf("9-9.50 : TS-9,FF1,FF4\n");
            printf("10-10.50 : TS-2,FF5,G1\n");
            printf("11-11.50: FF2,FF6,TS-9\n");
            printf("12-12.50 : LUNCH\n");
            printf("1-1.50 : FF4,G9,FF1\n");
            printf("2-2.50 : G9,TS-2,FF6\n");
            printf("3-3.50 : FF4,TS-3-G6\n");
            printf("4-4.50 : FF5,FF6,G9\n");
            printf("\n\nPress any key to return to main menu : ");
            getch();
            system("cls");
            goto mainm;
            break;

        case 6:
            printf("9-9.50 : G6,G8,FF2\n");
            printf("10-10.50 : FF6,FF7,TS-8\n");
            printf("11-11.50: FF5,FF6,G9\n");
            printf("12-12.50 : LUNCH\n");
            printf("1-1.50 : FF4,TS-3-G6\n");
            printf("2-2.50 : TS-9,G7,FF6\n");
            printf("3-3.50 : FF4,TS-8,G3\n");
            printf("4-4.50 : TS-2,G8,FF5\n");
            printf("\n\nPress any key to return to main menu : ");
            getch();
            system("cls");
            goto mainm;
            break;
        default:
            printf("Oops!! seems like you have entered a wrong choice\n");
            printf("\n\nPress any key to return to main menu : ");
            getch();
            system("cls");
            goto mainm;
            break;

        }
    case 3:
        printf("HEY THERE!..Need a guide??\n Don't worry,we're here to help you out...\n");
        fp3=fopen("CLASSGUIDE.txt","r");
        fgets(guide, 1000, fp3);
        printf("%s\n", guide);
        fclose(fp3);
        break;
    case 4 :
        break;
    default :
        printf("Oops!! seems like you have entered a wrong choice\n");
        printf("\n\nPress any key to return to main menu : ");
        getch();
        system("cls");
        goto mainm;

    }
}
void timetwelcome()
{

    printf("\t\t\t\t############################################\n");
    printf("\t\t\t\t#******************************************#\n");
    printf("\t\t\t\t#******************************************#\n");
    printf("\t\t\t\t#******             THE              ******#\n");
    printf("\t\t\t\t#******           SCHEDULE           ******#\n");
    printf("\t\t\t\t#******            CENTRE            ******#\n");
    printf("\t\t\t\t#******************************************#\n");
    printf("\t\t\t\t#******************************************#\n");
    printf("\t\t\t\t############################################\n");
    printf("Press any key to continue : ....");
    getch();
}
void it(int d)
{
    if(d==1)
    {
        printf("9-9.50 : PHYSICS-1 : FF5\n");
        printf("11-11.50 : SDF-1 : FF2\n");
        printf("12-12.50 : LUNCH\n");
        printf("1-1.50 : PHYSICS-1 TUT : TS-2\n");
        printf("3-4.50 : HSS LAB : LANG. LAB\n");

    }
    if(d==2)
    {
        printf("9-9.50 : PHYSICS-1: FF2 \n");
        printf("10-10.50 : MATHS-1 : FF4\n");
        printf("11-11.50 : SDF-1 : FF2\n");
        printf("12-12.50 : LUNCH\n");
        printf("1-1.50 : ENGLISH : FF3\n");
        printf("2-2.50 : MATHS TUT : TS-8\n");
        printf("3-4.50 : SDF-1 LAB : CL02\n");
    }
    if(d==3)
    {
        printf("9-9.50 : BRIDGE COURSE : FF6\n");
        printf("10-10.50 : SDF-1 : G2\n");
        printf("11-11.50: MATHS-1 : FF2\n");
        printf("12-12.50 : LUNCH\n");
        printf("1-1.50 : PHYSICS : FF4\n");
        printf("2-2.50 : MATHS TUT :TS-6\n");
        printf("3-3.50 : ENGLISH : G3\n");
        printf("4-4.50 : SDF TUT : TS-8\n");
    }
    if(d==4)
    {
        printf("9-9.50 : ENGLISH : FF2\n");
        printf("10-10.50 : PHYSICS-1 : FF5\n");
        printf("11-11.50 : SDF-1 : FF3\n");
        printf("12-12.50 : LUNCH\n");
        printf("1-3.50 : EDD : LAB\n");
        printf("4-4.50 : MATHS-1 : FF4\n");
    }
    if(d==5)
    {
        printf("9-9.50 : SDF-1 : G2\n");
        printf("10-10.50 : PHYSICS-1 :FF5\n");
        printf("11-11.50 : ENGLISH : FF4\n");
        printf("12-12.50 : LUNCH\n");
        printf("1-1.50 : MATHS-1 : FF2\n");
        printf("2-2.50 : PHYSICS TUT : TS-2\n");
        printf("3-4.50 : SDF-1 LAB : CL05\n");
    }
    if(d==6)
    {
        printf("9-9.50 : MATHS TUT : TS-8\n");
        printf("10-10.50 : ENGLISH : FF4\n");
        printf("11-11.50 : BRIDGE COURSE : FF6\n");
        printf("12-12.50 : LUNCH\n");
        printf("1-1.50 : MATHS-1 : FF2\n");
        printf("2-2.50 : SDF-1 TUT : TS-2\n");
        printf("3-4.50 : PHYSICS-1 LAB : LAB-1\n");
    }
}
void ece(int q)
{
    if(q==1)
    {
        printf("9-9.50 : SDF-1 : G6\n");
        printf("10-10.50 : MATHS-1 :FF1\n");
        printf("11-11.50 : PHYSICS-1 : FF3\n");
        printf("12-12.50 : LUNCH\n");
        printf("1-2.50 : SDF-1 LAB : CL04\n");
        printf("3-3.50 : ENGLISH : FF4\n");
        printf("4-4.50: SDF-1 TUT : TS-6\n");
    }
    if(q==2)
    {
        printf("9-9.50 : PHYSICS-1 : FF5\n");
        printf("11-11.50 : SDF-1 : FF2\n");
        printf("12-12.50 : LUNCH\n");
        printf("1-1.50 : PHYSICS-1 TUT : TS-2\n");
        printf("3-4.50 : HSS LAB : LANG. LAB\n");
    }
    if(q==3)
    {
        printf("9-9.50 : MATHS-1 : FF6\n");
        printf("10-10.50 : PHYSICS-1 : FF2\n");
        printf("11-11.50 : MATHS TUT : TS-8\n");
        printf("12-12.50 : LUNCH\n");
        printf("1-1.50 : ENGLISH : G2\n");
        printf("2-2.50 : BRIDGE COURSE : FF4\n");
        printf("3-4.50 : PHYSICS-1 LAB : LAB-2\n");
    }
    if(q==4)
    {
        printf("9-9.50 : BRIDGE COURSE : FF5\n");
        printf("10-10.50 : SDF-1 : FF2\n");
        printf("11-11.50 : PHYSICS-1 : G5\n");
        printf("12-12.50 : LUNCH\n");
        printf("1-2.50 : MATHS TUT : TS-9\n");
        printf("3-3.50 : ENGLISH : FF2\n");
        printf("3-4.50 : SDF-LAB : CL03\n");
    }
    if(q==5)
    {
        printf("9-9.50 : BRIDGE COURSE : G4\n");
        printf("10-10.50 : SDF-1 : FF5\n");
        printf("11-11.50: MATHS-1 : FF1\n");
        printf("12-12.50 : LUNCH\n");
        printf("1-1.50 : PHYSICS : FF2\n");
        printf("2-2.50 : MATHS TUT : TS-7\n");
        printf("3-3.50 : ENGLISH : FF2\n");
        printf("4-4.50 : SDF TUT : TS-2\n");
    }


    if(q==6)
    {
        printf("9-9.50 : ENGLISH : G2\n");
        printf("10-10.50 : PHYSICS-1 : FF5\n");
        printf("11-11.50 : MATHS-1 : FF1\n");
        printf("12-12.50 : LUNCH\n");
        printf("1-1.50: SDF-1 : G8\n");
        printf("2-4.50 : EDD WORKSHOP : WORKSHOP\n");
    }
}
//EXIT
void exit()
{
    printf("\n\t\t\t\t  *---------------------------------------------------------*\n");
    printf("\n\t\t\t\t        *********************************************");
    printf("\n\t\t\t\t        *                                           *");
    printf("\n\t\t\t\t        *                  THANK YOU                *");
    printf("\n\t\t\t\t        *                     FOR                   *");
    printf("\n\t\t\t\t        *                  YOUR TIME                *");
    printf("\n\t\t\t\t        *                                           *");
    printf("\n\t\t\t\t        *********************************************\n");
    printf("\n\t\t\t\t  *---------------------------------------------------------*\n");
    printf("Do recommend required improvements . It would help us Improve our system");
}
