#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

typedef struct reporter
{
    char name[35];
    char attend[10];
    int rollno;
} report;
void eencrypt(char *c)
{
    char *ptr = c;
    while (*ptr != '\0')
    {
        *ptr = *ptr + 3;
        ptr++;
    }
}

void decrypt(char *c);
void create(void)
{
    int studenttotalnumber;
    char name[35];
    char caste[15];
    char class[30];
    char section[10];
    printf("Enter class in number : ");
    scanf("%s", class);
    printf("Enter section (all capital): ");
    scanf("%s", section);
    strcat(class, "-");
    strcat(class, section);
    char filename[20];
    strcpy(filename, class);
    strcat(class, ".txt");
    printf("Enter the total number of students : ");
    scanf("%d", &studenttotalnumber);
    printf("Enter name and caste seperately\n");
    report students[studenttotalnumber];
    int i;
    // taking input of roll no, name and caste and saving to structure
    for (i = 0; i < studenttotalnumber; i++)
    {
        students[i].rollno = i + 1;
        printf("Roll No : %d\nName : ", i + 1);
        scanf("%s", name);
        fflush(stdin);
        printf("Caste : ");
        fflush(stdin);
        scanf("%s", caste);
        eencrypt(name);
        strcat(name, " ");
        eencrypt(caste);
        strcat(name, caste);
        strcpy(students[i].name, name);
    }
    int filenumber = 0;
    // creating a file to have record of all list of students
    FILE *data;
    data = fopen("detail.txt", "r");
    if (data == NULL)
    {
        data = fopen("detail.txt", "w");
        fprintf(data, "1\n");
        fprintf(data, "%s\n", filename);
    }
    else
    {
        fscanf(data, "%d", &filenumber);
        char classsection[filenumber][20];
        int ol;
        for (ol = 0; ol < filenumber; ol++)
        {
            fscanf(data, "%s", classsection[ol]);
            int filenumber_1 = 0;
            filenumber_1++;
        }
        data = fopen("detail.txt", "w");
        fprintf(data, "%d\n", filenumber + 1);
        int op;
        for (op = 0; op < filenumber; op++)
        {
            fprintf(data, "%s\n", classsection[op]);
        }
        fprintf(data, "%s\n", filename);
    }
    fclose(data);
    // saving students list with file name class-section
    FILE *saver;
    saver = fopen(class, "w");
    fprintf(saver, "%d\n", studenttotalnumber);
    int k;
    for (k = 0; k < studenttotalnumber; k++)
    {
        fprintf(saver, "%d %s\n", students[k].rollno, students[k].name);
    }
    fclose(saver);
}

void edit(void)
{
    int studentstotalnumber;
    char name[35];
    char caste[15];
    char class[10];
    // checking the exiting list of students from detail.txt
    FILE *data;
    data = fopen("detail.txt", "r");
    if (data == NULL)
    {
        printf("No previous record of data found for editing!");
    }
    else
    {
        int filenumber;
        int solver1 = 0;
        fscanf(data, "%d", &filenumber);
        if (filenumber == 0)
        {
            printf("No any list founded\n");
            solver1 = 1;
        }
        if (solver1 == 0)
        {
            char filename[filenumber][20];
            int ol;
            // scanning list available
            for (ol = 0; ol < filenumber; ol++)
            {
                fscanf(data, "%s", filename[ol]);
            }
            int op;
            for (op = 0; op < filenumber; op++)
            {
                printf("%d)\t%s\n", op + 1, filename[op]);
            }
            // taking input to open the needed file
            int editornumber = 1000;
            int sloverr = 1000;
            do
            {
                fflush(stdin);
                printf("Enter number according to above list : ");
                scanf("%d", &editornumber);
                if (editornumber <= filenumber)
                {
                    sloverr = 1;
                }
            } while (sloverr != 1);
            strcpy(class, filename[editornumber - 1]);
            strcat(class, ".txt");
            fclose(data);
            FILE *edit;
            edit = fopen(class, "r");
            fscanf(edit, "%d", &studentstotalnumber);
            report students[studentstotalnumber];
            int i;
            // scanning data from the desired list and saving to structures
            for (i = 0; i < studentstotalnumber; i++)
            {
                fscanf(edit, "%d", &students[i].rollno);
                fflush(stdin);
                fscanf(edit, "%s", name);
                fscanf(edit, "%s", caste);
                strcat(name, " ");
                strcat(name, caste);
                strcpy(students[i].name, name);
            }
            int solver2 = 11110;
            int totalnumberofedit = 1900;
            do
            {
                fflush(stdin);
                printf("How many numbers of edit do you want to make? : ");
                scanf("%d", &totalnumberofedit);
                if (totalnumberofedit <= studentstotalnumber)
                {
                    solver2 = 1;
                }
            } while (solver2 != 1);
            int k;
            // taking input and replacing name with previous name
            for (k = 0; k < totalnumberofedit; k++)
            {
                int rollno = 11111, arraynumber;
                int solver3 = 1111000110;
                do
                {
                    fflush(stdin);
                    printf("Enter roll no : ");
                    scanf("%d", &rollno);
                    if (rollno <= studentstotalnumber)
                    {
                        solver3 = 1;
                    }
                } while (solver3 != 1);
                arraynumber = rollno - 1;
                printf("Enter name and caste seperately\n");
                printf("Enter Name : ");
                scanf("%s", name);
                eencrypt(name);
                printf("Enter Caste : ");
                scanf("%s", caste);
                eencrypt(caste);
                strcat(name, " ");
                strcat(name, caste);
                students[arraynumber].rollno = rollno;
                strcpy(students[arraynumber].name, name);
            }
            fclose(edit);
            FILE *saver;
            // saving name to the same list by updating name
            saver = fopen(class, "w");
            fprintf(saver, "%d\n", studentstotalnumber);
            int l;
            for (l = 0; l < studentstotalnumber; l++)
            {
                fprintf(saver, "%d %s\n", students[l].rollno, students[l].name);
            }
            fclose(saver);
        }
    }
}

void add(void)
{
    int studentstotalnumber;
    char name[35];
    char caste[15];
    char class[25];
    FILE *data;
    // scanning file to know all list of students available
    data = fopen("detail.txt", "r");
    if (data == NULL)
    {
        printf("No previous record of data found for editing!\n");
    }
    else
    {
        int filenumber;
        fscanf(data, "%d", &filenumber);
        int solver = 0;
        if (filenumber == 0)
        {
            printf("No list available\n");
            solver = 1;
        }
        if (solver == 0)
        {
            char filename[filenumber][20];
            int ol;
            for (ol = 0; ol < filenumber; ol++)
            {
                fscanf(data, "%s", filename[ol]);
            }
            int op;
            // displaying all available students list
            for (op = 0; op < filenumber; op++)
            {
                printf("%d)\t%s\n", op + 1, filename[op]);
            }
            int editornumber = 11111;
            // taking input to open desired list
            int solver1 = 11111110;
            while (solver1 != 1)
            {
                fflush(stdin);
                printf("Enter number according to above list : ");
                scanf("%d", &editornumber);
                if (editornumber <= filenumber)
                {
                    solver1 = 1;
                }
            }
            strcpy(class, filename[editornumber - 1]);
            strcat(class, ".txt");
            fclose(data);
            FILE *edit;
            edit = fopen(class, "r");
            fscanf(edit, "%d", &studentstotalnumber);
            int totalstudentss = studentstotalnumber + 1;
            report students[totalstudentss];
            int i;
            // scanning name from desired list and saving to structure
            for (i = 0; i < studentstotalnumber; i++)
            {
                fscanf(edit, "%d", &students[i].rollno);
                fscanf(edit, "%s", name);
                fscanf(edit, "%s", caste);
                strcat(name, " ");
                strcat(name, caste);
                strcpy(students[i].name, name);
            }
            // taking input of roll no, name and caste to add
            int rolln0o = 111111, arraynumber;
            int solver2 = 111111110;
            while (solver2 != 1)
            {
                fflush(stdin);
                printf("Enter roll no : ");
                scanf("%d", &rolln0o);
                if (rolln0o <= totalstudentss)
                {
                    solver2 = 1;
                }
            }
            arraynumber = rolln0o - 1;
            printf("Enter name and caste seperately\n");
            printf("Enter Name : ");
            scanf("%s", name);
            eencrypt(name);
            printf("Enter Caste : ");
            scanf("%s", caste);
            eencrypt(caste);
            strcat(name, " ");
            strcat(name, caste);
            int looper;
            // shifting previous students data to one roll number up from back to add new one in middle
            for (looper = studentstotalnumber + 1; looper > arraynumber; looper--)
            {
                students[looper].rollno = students[looper - 1].rollno + 1;
                strcpy(students[looper].name, students[looper - 1].name);
            }
            // adding new name on desired roll no
            students[arraynumber].rollno = rolln0o;
            strcpy(students[arraynumber].name, name);
            fclose(edit);
            // saving all students list on same file with edit
            FILE *saver;
            saver = fopen(class, "w");
            fprintf(saver, "%d\n", totalstudentss);
            int l;
            for (l = 0; l < totalstudentss; l++)
            {
                fprintf(saver, "%d %s\n", students[l].rollno, students[l].name);
            }
            fclose(saver);
        }
    }
}

void delete (void)
{
    int studentstotalnumber;
    char name[35];
    char caste[15];
    char class[25];
    FILE *data;
    // scaning list of files available
    data = fopen("detail.txt", "r");
    if (data == NULL)
    {
        printf("No previous record of data found for editing!\n");
    }
    else
    {
        int filenumber;
        fscanf(data, "%d", &filenumber);
        int solver = 0;
        if (filenumber == 0)
        {
            printf("No list found\n");
            solver = 1;
        }
        if (solver == 0)
        {
            char filename[filenumber][20];
            int ol;
            for (ol = 0; ol < filenumber; ol++)
            {
                fscanf(data, "%s", filename[ol]);
            }
            int op;
            for (op = 0; op < filenumber; op++)
            {
                printf("%d)\t%s\n", op + 1, filename[op]);
            }
            int editornumber = 10000;
            // taking input to open desired list
            int solver1 = 0;
            while (solver1 == 0)
            {
                fflush(stdin);
                printf("Enter number according to above list : ");
                scanf("%d", &editornumber);
                if (editornumber <= filenumber)
                {
                    solver1 = 1;
                }
            }
            strcpy(class, filename[editornumber - 1]);
            strcat(class, ".txt");
            fclose(data);
            FILE *edit;
            edit = fopen(class, "r");
            fscanf(edit, "%d", &studentstotalnumber);
            int totalstudentss = studentstotalnumber - 1;
            report students[studentstotalnumber];
            int i;
            // scanning all students name and saving to structure
            for (i = 0; i < studentstotalnumber; i++)
            {
                fscanf(edit, "%d", &students[i].rollno);
                fscanf(edit, "%s", name);
                fscanf(edit, "%s", caste);
                strcat(name, " ");
                strcat(name, caste);
                strcpy(students[i].name, name);
            }
            // taking input of roll no to delete it
            int rolln0o = 1000, arraynumber;
            int solver2 = 0;
            while (solver2 == 0)
            {
                fflush(stdin);
                printf("Enter roll no which you want to remove : ");
                scanf("%d", &rolln0o);
                if (rolln0o <= studentstotalnumber)
                {
                    solver2 = 1;
                }
            }
            arraynumber = rolln0o - 1;
            int looper;
            // decreasing roll no of student which are after the removing roll no and shifting all name one step ahead
            for (looper = arraynumber; looper < studentstotalnumber; looper++)
            {
                students[looper].rollno = students[looper + 1].rollno - 1;
                strcpy(students[looper].name, students[looper + 1].name);
            }
            fclose(edit);
            // saving data on same list by removing the desired name
            FILE *saver;
            saver = fopen(class, "w");
            fprintf(saver, "%d\n", totalstudentss);
            int l;
            for (l = 0; l < totalstudentss; l++)
            {
                fprintf(saver, "%d %s\n", students[l].rollno, students[l].name);
            }
            fclose(saver);
        }
    }
}

void attendance(void)
{
    int studentstotalnumber;
    char name[35];
    char caste[15];
    char class[10];
    char fornewname[50];
    int absnet = 0, present = 0;
    FILE *data;
    data = fopen("detail.txt", "r");
    // scanning all required list
    if (data == NULL)
    {
        printf("No data of students\nPlease create students list!\n");
    }
    else
    {
        int filenumber;
        int solver1 = 0;
        fscanf(data, "%d", &filenumber);
        if (filenumber == 0)
        {
            printf("No any list found\n");
            solver1 = 1;
        }
        if (solver1 == 0)
        {
            char filename[filenumber][20];
            int ol;
            for (ol = 0; ol < filenumber; ol++)
            {
                fscanf(data, "%s", filename[ol]);
            }
            int op;
            for (op = 0; op < filenumber; op++)
            {
                printf("%d)\t%s\n", op + 1, filename[op]);
            }
            // taking input to open desired list for attendance
            int editornumber = 1000;
            int solver = 0;
            while (solver == 0)
            {
                fflush(stdin);
                printf("Enter number of class section according to above list : ");
                scanf("%d", &editornumber);
                if (editornumber <= filenumber)
                {
                    solver = 1;
                }
            }
            strcpy(class, filename[editornumber - 1]);
            strcpy(fornewname, class);
            strcat(fornewname, "-");
            strcat(class, ".txt");
            FILE *detail;
            detail = fopen(class, "r");
            if (detail == NULL)
            {
                printf("Students list doesn`t exist!\nPlease recreate students information list!");
            }
            else
            {
                fscanf(detail, "%d", &studentstotalnumber);
                report students[studentstotalnumber];
                int i;
                // scanning all students name from desired list and saving it to structure by decrypting
                for (i = 0; i < studentstotalnumber; i++)
                {
                    fscanf(detail, "%d", &students[i].rollno);
                    fscanf(detail, "%s", name);
                    fscanf(detail, "%s", caste);
                    decrypt(name);
                    strcat(name, " ");
                    decrypt(caste);
                    strcat(name, caste);
                    strcpy(students[i].name, name);
                }
                char date[20];
                fflush(stdin);
                // taking input of date to create file name with date
                printf("Enter date in format XX-XX-XXXX : ");
                scanf("%s", date);
                int k;
                // taking attendance
                for (k = 0; k < studentstotalnumber; k++)
                {
                    char aandp;
                    int checker = 0;
                    while (checker == 0)
                    {
                        printf("Roll No : %d\n%s\nEnter 'a' for absent and 'p' for present : ", students[k].rollno, students[k].name);
                        fflush(stdin);
                        scanf("%c", &aandp);
                        if (aandp == 'p')
                        {
                            strcpy(students[k].attend, "Present");
                            present++;
                            checker = 1;
                        }
                        else if (aandp == 'a')
                        {
                            strcpy(students[k].attend, "Absent");
                            absnet++;
                            checker = 1;
                        }
                        else
                        {
                            checker = 0;
                        }
                    }
                }
                // reasking to change some attendance for convenient
                char repeat = 'y';
                while (repeat == 'y')
                {
                    int mistakesolver = 0;
                    do
                    {
                        printf("Do you want to continue or edit the report?\nPress 'y' for editing and 'n' to continue : ");
                        fflush(stdin);
                        scanf("%c", &repeat);
                        if (repeat == 'y' || repeat == 'n')
                        {
                            mistakesolver = 1;
                        }
                    } while (mistakesolver == 0);

                    if (repeat == 'y')
                    {
                        int edit2 = 10000;
                        int solver6 = 0;
                        int solver5 = 0;
                        while (solver5 == 0)
                        {
                            fflush(stdin);
                            printf("1 - Edit date\n2 - Edit attendance\nEnter according to above list : ");
                            scanf("%d", &edit2);
                            if (edit2 <= 2)
                            {
                                solver5 = 1;
                            }
                            if (edit2 == 1)
                            {
                                printf("Enter date in format XX-XX-XXXX : ");
                                scanf("%s", date);
                            }
                            else if (edit2 == 2)
                            {
                                solver6 = 1;
                            }
                        }
                        if (solver6 == 1)
                        {
                            int enternumbererror = 1000;
                            int number_of_changes = 1000;
                            do
                            {
                                fflush(stdin);
                                printf("Enter the number of changes you want to make : ");
                                scanf("%d", &number_of_changes);
                                if (number_of_changes <= studentstotalnumber)
                                {
                                    enternumbererror = 1;
                                }
                            } while (enternumbererror != 1);
                            for (int edit = 0; edit < number_of_changes; edit++)
                            {
                                int rollerror = 0;
                                int rollnoedit = 0;
                                do
                                {
                                    fflush(stdin);
                                    int rollnoeditinput = 10000;
                                    printf("Enter the roll number to make change : ");
                                    scanf("%d", &rollnoeditinput);
                                    rollnoedit = rollnoeditinput - 1;
                                    if (rollnoeditinput <= studentstotalnumber)
                                    {
                                        rollerror = 1;
                                    }
                                    else
                                    {
                                        printf("Enter carefully!\n");
                                    }
                                } while (rollerror != 1);
                                int edit_reciecer = 100;
                                int oname = 0;
                                char repeattaker;
                                while (oname == 0)
                                {
                                    printf("%d\t%s\n", students[rollnoedit].rollno, students[rollnoedit].name);
                                    fflush(stdin);
                                    printf("Enter 'a' for absent and 'p' for present : ");
                                    scanf("%c", &repeattaker);
                                    if (repeattaker == 'a')
                                    {
                                        edit_reciecer = 1;
                                        oname = 1;
                                    }
                                    else if (repeattaker == 'p')
                                    {
                                        edit_reciecer = 2;
                                        oname = 1;
                                    }
                                }
                                if (edit_reciecer == 1)
                                {
                                    if (strcmp(students[rollnoedit].attend, "Present") == 0)
                                    {
                                        present -= 1;
                                        absnet += 1;
                                    }
                                    strcpy(students[rollnoedit].attend, "Absent");
                                }
                                else if (edit_reciecer == 2)
                                {
                                    if (strcmp(students[rollnoedit].attend, "Absent") == 0)
                                    {
                                        present += 1;
                                        absnet -= 1;
                                    }
                                    strcpy(students[rollnoedit].attend, "Present");
                                }
                            }
                        }
                    }
                }

                char realname[50];
                strcpy(realname, fornewname);
                strcat(realname, date);
                strcat(realname, ".txt");
                FILE *saver;
                saver = fopen(realname, "w");
                fprintf(saver, "\t\tAttendance Report of %s!!\n", date);
                int pl;
                // saving attendance report with file name class section date
                for (pl = 0; pl < studentstotalnumber; pl++)
                {
                    fprintf(saver, "%d\t%s\t---->\t%s\n", students[pl].rollno, students[pl].name, students[pl].attend);
                }
                fprintf(saver, "\n\nTotal number of present : %d\nTotal number of absent : %d", present, absnet);
                fclose(saver);
                fclose(data);
                fclose(detail);
            }
        }
    }
}

void view(void)
{
    int studentstotalnumber;
    char name[35];
    char caste[15];
    char class[10];
    FILE *data;
    data = fopen("detail.txt", "r");
    if (data == NULL)
    {
        printf("No previous record of data found for displaying!\n");
    }
    else
    {
        int solver = 0;
        int filenumber;
        fscanf(data, "%d", &filenumber);
        if (filenumber == 0)
        {
            solver = 1;
            printf("No any data found\n");
        }
        if (solver == 0)
        {
            char filename[filenumber][20];
            int ol;
            for (ol = 0; ol < filenumber; ol++)
            {
                fscanf(data, "%s", filename[ol]);
            }
            int op;
            for (op = 0; op < filenumber; op++)
            {
                printf("%d)\t%s\n", op + 1, filename[op]);
            }
            int editornumber = 1000;
            int solver1 = 0;
            while (solver1 == 0)
            {
                fflush(stdin);
                printf("Enter number of class and section according to above list to display students list : ");
                scanf("%d", &editornumber);
                if (editornumber <= filenumber)
                {
                    solver1 = 1;
                }
            }
            strcpy(class, filename[editornumber - 1]);
            strcat(class, ".txt");
            fclose(data);
            FILE *edit;
            edit = fopen(class, "r");
            fscanf(edit, "%d", &studentstotalnumber);
            report students[studentstotalnumber];
            int i;
            // scanning all name from desired list and saving to structure by decrypting
            for (i = 0; i < studentstotalnumber; i++)
            {
                fscanf(edit, "%d", &students[i].rollno);
                fscanf(edit, "%s", name);
                decrypt(name);
                fscanf(edit, "%s", caste);
                decrypt(caste);
                strcat(name, " ");
                strcat(name, caste);
                strcpy(students[i].name, name);
            }
            int la;
            // displaying all name from structure
            for (la = 0; la < studentstotalnumber; la++)
            {
                printf("%d)\t%s\n", students[la].rollno, students[la].name);
            }
            fclose(edit);
        }
    }
    fclose(data);
}

void listremover(void)
{
    FILE *detail;
    detail = fopen("detail.txt", "r");
    if (detail == NULL)
    {
        printf("No any existing lists to remove\n");
    }
    else
    {
        int numberoffiles;
        int solver = 0;
        fscanf(detail, "%d", &numberoffiles);
        if (numberoffiles == 0)
        {
            printf("No any list found\n");
            solver = 1;
        }
        if (solver == 0)
        {
            char filename[numberoffiles][30];
            int i;
            fflush(stdin);
            for (i = 0; i < numberoffiles; i++)
            {
                fscanf(detail, "%s", filename[i]);
            }
            int k;
            for (k = 0; k < numberoffiles; k++)
            {
                printf("%d)\t%s\n", k + 1, filename[k]);
            }
            // taking input to delete desired list
            int deleter = 1000, realdelete;
            int solver1 = 0;
            while (solver1 == 0)
            {
                fflush(stdin);
                printf("Enter number of class and section to remove list from above detail : ");
                scanf("%d", &deleter);
                if (deleter <= numberoffiles)
                {
                    solver1 = 1;
                }
            }
            realdelete = deleter - 1;
            strcat(filename[realdelete], ".txt");
            int solver = 0;
            // deleting list
            if (remove(filename[realdelete]) == 0)
            {
                solver = 1;
            }
            else
            {
                printf("Cann't delete list\n");
                solver = 0;
            }
            fclose(detail);
            // updating detail by removing name of deleted list
            if (solver == 1)
            {
                FILE *savedetail;
                savedetail = fopen("detail.txt", "w");
                fprintf(savedetail, "%d\n", numberoffiles - 1);
                int l;
                for (l = 0; l < numberoffiles; l++)
                {
                    if (l != realdelete)
                    {
                        fprintf(savedetail, "%s\n", filename[l]);
                    }
                }
                fclose(savedetail);
            }
        }
    }
}
// decrypt
void decrypt(char *c)
{
    char *ptr = c;
    while (*ptr != '\0')
    {
        *ptr = *ptr - 3;
        ptr++;
    }
}

int main(void)
{
    int saver = 0;
    int choice;
    int out = 0;
    char newpassword[20];
    char password_[20];
    char password_input[20];
    int security = 0;
    int chance = 0;
    while (saver == 0 && chance < 5)
    {
        FILE *password;
        FILE *passwordsaver;
        password = fopen("allok.txt", "r");

        if (password == NULL)
        {
            // creating new password
            fflush(stdin);
            printf("Enter new password character only : ");
            scanf("%s", newpassword);
            eencrypt(newpassword);
            passwordsaver = fopen("allok.txt", "w");
            fprintf(passwordsaver, "%s", newpassword);
            fclose(passwordsaver);
        }
        else
        {
            fscanf(password, "%s", password_);
            decrypt(password_);
            do
            {
                // taking password and checking with real password for 5 times
                fflush(stdin);
                printf("Enter password : ");
                scanf("%s", password_input);
                int result;
                result = strcmp(password_, password_input);
                if (result == 0)
                {
                    security = 1;
                    chance = 10;
                    saver = 1;
                }
                chance++;
            } while (chance < 5);
        }
        fclose(password);
    }

    while (out == 0 && security == 1)
    {
        fflush(stdin);
        printf("1 - Take attendance\n2 - Create students list\n3 - Edit\n4 - Remove students list\n5 - View students list\n6 - Exit\nEnter number according to above list : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            attendance();
            break;
        }
        case 2:
        {
            create();
            break;
        }
        case 3:
        {
            int choice_edit;
            printf("1 - Replace name from existing list\n2 - Add name to existing list\n3 - Remove name from existing list\nEnter according to above information : ");
            scanf("%d", &choice_edit);
            switch (choice_edit)
            {
            case 1:
                edit();
                break;
            case 2:
            {
                add();
                break;
            }
            case 3:
            {
                delete ();
                break;
            }
            default:
                printf("Enter carefully\n");
                break;
            }
            break;
        }
        case 4:
        {
            listremover();
            break;
        }
        case 5:
        {
            view();
            break;
        }
        case 6:
        {
            out = 1;
            break;
        }
        default:
            printf("Enter Carefully!\n");
            break;
        }
    }
    return 0;
}














