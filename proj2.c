#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student
{
    int rollno;
    char name[50];
    float marks;
    struct student *next;
} SLL;

void addNew(SLL **);
void deleteRec(SLL **);
void showList(SLL *);
void modifyRec(SLL *);
void saveRec(SLL *);
void loadRecords(SLL **);
void sortList(SLL **);
void deleteAll(SLL **);
void reverseList(SLL **);

void deleteByRoll(SLL **);
void deleteByName(SLL **);

void modifyByRoll(SLL *);
void modifyByName(SLL *);
void modifyBymarks(SLL *);

int main()
{
    SLL *ptr = 0;
    char op;
    char ch;
   
    loadRecords(&ptr);

    while(1)
    {
        printf("\n");
        printf("******** STUDENT RECORD MENU ********\n");
        printf("a/A : Add new record\n");
        printf("d/D : Delete a record\n");
        printf("s/S : Show the list\n");
        printf("m/M : Modify a record\n");
        printf("v/V : Save records\n");
        printf("e/E : Exit\n");
        printf("t/T : Sort the list\n");
        printf("l/L : Delete all the records\n");
        printf("r/R : Reverse the list\n");
        printf("Enter your choice: ");

        scanf(" %c", &op);

        switch(op)
        {
            case 'a':
            case 'A':addNew(&ptr);break;
            case 'd':
            case 'D':deleteRec(&ptr);break;
            case 's':
            case 'S':showList(ptr);break;
            case 'm':
            case 'M':modifyRec(ptr);break;
            case 'v':
            case 'V':saveRec(ptr);break;
            case 't':
            case 'T':sortList(&ptr);break;
            case 'l':
            case 'L':deleteAll(&ptr);break;
            case 'r':
            case 'R':reverseList(&ptr);break;
            case 'e':
            case 'E':
                printf("\nS/s : Save and exit\n");
                printf("E/e : Exit without saving\n");
                printf("Enter choice: ");

                scanf(" %c", &ch);

                if(ch == 's' || ch == 'S')
                {
                    saveRec(ptr);
                }

                deleteAll(&ptr);

                printf("Program terminated\n");
                return 0;

            default:
                printf("Unknown choice\n");
        }}}

// Add New Record
void addNew(SLL **ptr)
{
    SLL *temp,*last,*p;
    int roll = 1;
    int found;
    temp = malloc(sizeof(SLL));
    if(temp == 0)
    {
        printf("Memory allocation failed\n");
        return;
    }
    while(1)
    {
        found = 0;
        p = *ptr;
        while(p != 0)
        {
            if(p->rollno == roll)
            {
                found = 1;
                break;
            }
            p = p->next;
        }
        if(found == 0)
	{
            break;
        }
	roll++;
    }
    temp->rollno = roll;
    printf("Roll number : %d\n", temp->rollno);
    printf("Enter student name: ");
    scanf("%s", temp->name);
    printf("Enter marks: ");
    scanf("%f", &temp->marks);

    if(temp->marks < 0 || temp->marks > 100)
    {
        printf("Invalid marks\n");
        free(temp);
        return;
    }
    temp->next = NULL;
// First node 

    if(*ptr ==0)
    {
        *ptr = temp;
    }
    else
    {
        last = *ptr;

        while(last->next !=0)
        {
            last = last->next;
        }

        last->next = temp;
    }
    printf("Record added successfully\n");
}

// Show All Record

void showList(SLL *ptr)
{
    if(ptr ==0)
    {
        printf("\nNo student records available\n");
        return;
    }
    printf("\n");
    printf("---------------------------------------------\n");
    printf("Roll No.     Name                  marks\n");
    printf("---------------------------------------------\n");

    while(ptr !=0)
    {
        printf("%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);

        ptr = ptr->next;
    }
    printf("---------------------------------------------\n");
}

// Delete Menu
void deleteRec(SLL **ptr)
{
    char ch;
    if(*ptr == 0)
    {
        printf("No records available\n");
        return;
    }
    printf("\n");
    printf("R/r : Enter roll number to delete\n");
    printf("N/n : Enter name to delete\n");
    printf("Enter choice: ");
    scanf(" %c", &ch);
    if(ch == 'r' || ch == 'R')
    {
        deleteByRoll(ptr);
    }
    else if(ch == 'n' || ch == 'N')
    {
        deleteByName(ptr);
    }
    else
    {
        printf("Invalid choice\n");
    }
}

// Delete By Roll Number 
void deleteByRoll(SLL **ptr)
{
    SLL *del;
    SLL *prev;
    int roll;

    printf("Enter roll number: ");
    scanf("%d", &roll);

    del = *ptr;
    prev = 0;

    while(del !=0)
    {
        if(del->rollno == roll)
        {
            if(prev ==0)
            {
                *ptr = del->next;
            }
            else
            {
                prev->next = del->next;
            }
            free(del);
            printf("Record deleted successfully\n");
            return;
        }
        prev = del;
        del = del->next;
    }
    printf("Record not found\n");
}

// Delete By Name
void deleteByName(SLL **ptr)
{
    SLL *p,*del,*prev;
    char name[50];
    int roll;
    int found = 0;

    printf("Enter name: ");
    scanf("%s", name);

    p = *ptr;
    printf("\nMatching records:\n");
    while(p != 0)
    {
        if(strcmp(p->name, name) == 0)
        {
            printf("Roll No: %d  Name: %s  marks: %f\n",p->rollno,p->name,p->marks);
            found = 1;
        }
        p = p->next;
    }

    if(found == 0)
    {
        printf("Record not found\n");
        return;
    }
    printf("Enter roll number of record to delete: ");
    scanf("%d", &roll);

    del = *ptr;
    prev = NULL;
    while(del !=0)
    {
        if(del->rollno == roll && strcmp(del->name, name) == 0)
        {
            if(prev ==0)
            {
                *ptr = del->next;
            }
            else
            {
                prev->next = del->next;
            }
            free(del);
            printf("Record deleted successfully\n");
            return;
        }
        prev = del;
        del = del->next;
    }
    printf("Selected record not found\n");
}

// Modify Menu
void modifyRec(SLL *ptr)
{
    char ch;
    if(ptr ==0)
    {
        printf("No records available\n");
        return;
    }
    printf("\n");
    printf("R/r : Search by roll number\n");
    printf("N/n : Search by name\n");
    printf("P/p : Search by marks\n");
    printf("Enter choice: ");

    scanf(" %c", &ch);

    if(ch == 'r' || ch == 'R')
    {
        modifyByRoll(ptr);
    }
    else if(ch == 'n' || ch == 'N')
    {
        modifyByName(ptr);
    }
    else if(ch == 'p' || ch == 'P')
    {
        modifyBymarks(ptr);
    }
    else
    {
        printf("Invalid choice\n");
    }
}

// Modify By Roll 
void modifyByRoll(SLL *ptr)
{
    int roll;
    printf("Enter roll number: ");
    scanf("%d", &roll);

    while(ptr != NULL)
    {
        if(ptr->rollno == roll)
        {
            printf("\nCurrent details\n");

            printf("Roll       : %d\n", ptr->rollno);
            printf("Name       : %s\n", ptr->name);
            printf("marks      : %f\n",ptr->marks);

            printf("\nEnter new name: ");
            scanf("%s", ptr->name);

            printf("Enter new marks: ");
            scanf("%f", &ptr->marks);

            if(ptr->marks < 0 ||ptr->marks > 100)
            {
                printf("Invalid marks\n");
                return;
            }
            printf("Record modified successfully\n");
            return;
        }
        ptr = ptr->next;
    }
   printf("Record not found\n");
}

// Modify By Name
void modifyByName(SLL *ptr)
{
    char name[50];
    int roll;
    int found = 0;

    printf("Enter name: ");
    scanf("%s", name);

    printf("\nMatching records:\n");

    while(ptr !=0)
    {
        if(strcmp(ptr->name, name) == 0)
        {
            printf("Roll No: %d  Name: %s  marks: %f\n",ptr->rollno,ptr->name,ptr->marks);
            found = 1;
        }
        ptr = ptr->next;
    }
    if(found == 0)
    {
        printf("Record not found\n");
        return;
    }

    printf("Enter roll number to modify: ");
    scanf("%d", &roll);

    ptr = NULL;
}
// Modify By marks
void modifyBymarks(SLL *ptr)
{
    float marks;

    printf("Enter marks: ");
    scanf("%f", &marks);


    while(ptr !=0)
    {
        if(ptr->marks == marks)
        {
            printf("\nRecord found\n");

            printf("Roll       : %d\n", ptr->rollno);
            printf("Name       : %s\n", ptr->name);
            printf("marks      : %f\n",ptr->marks);

            printf("\nEnter new name: ");
            scanf("%s", ptr->name);

            printf("Enter new marks: ");
            scanf("%f", &ptr->marks);

            if(ptr->marks< 0 ||ptr->marks > 100)
            {
                printf("Invalid marks\n");
                return;
            }
            printf("Record modified successfully\n");
            return;
        }
        ptr = ptr->next;
    }
    printf("Record not found\n");
}

// Save Records 
void saveRec(SLL *ptr)
{
    FILE *fp;

    fp = fopen("student.dat", "w");

    if(fp ==0)
    {
        printf("Unable to open student.dat\n");
        return;
    }

    while(ptr !=0)
    {
        fprintf(fp,"%d %s %f\n",ptr->rollno,ptr->name,ptr->marks);

        ptr = ptr->next;
    }

    fclose(fp);
    printf("Records saved successfully\n");
}

// Load Record
void loadRecords(SLL **ptr)
{
    FILE *fp;
    SLL *temp,*last;
    fp = fopen("student.dat", "r");
    if(fp ==0)
    {
        return;
    }
    while(1)
    {
        temp = malloc(sizeof(SLL));
        if(temp ==0)
        {
            fclose(fp);
            return;
        }
        if(fscanf(fp,"%d %s %f",&temp->rollno,temp->name,&temp->marks) != 3)
        {
            free(temp);
            break;
        }
        temp->next =0;
        if(*ptr ==0)
        {
            *ptr = temp;
        }
        else
        {
            last = *ptr;
            while(last->next !=0)
            {
                last = last->next;
            }
            last->next = temp;
        }
    }
    fclose(fp);
}
// Sort Menu 
void sortList(SLL **ptr)
{
    char ch;
    if(*ptr ==0)
    {
        printf("No records available\n");
        return;
    }
    printf("\n");
    printf("N/n : Sort by name\n");
    printf("P/p : Sort by marks\n");
    printf("Enter choice: ");

    scanf(" %c", &ch);

    if(ch == 'n' || ch == 'N')
    {
        SLL *i,*j,*min,*sorted = NULL;

	while(*ptr != NULL)
        {
            SLL **minPtr = ptr;
            SLL **p = ptr;

            while((*p)->next !=0)
            {
                if(strcmp((*p)->next->name,(*minPtr)->name) < 0)
                {
                    minPtr = &(*p)->next;
                }

                p = &(*p)->next;
            }
            min = *minPtr;
            *minPtr = min->next;
            min->next = sorted;
            sorted = min;
        }

        *ptr = 0;

        while(sorted != 0)
        {
            min = sorted;
            sorted = sorted->next;

            min->next = *ptr;
            *ptr = min;
        }
        printf("Sorted by name\n");
    }

    else if(ch == 'p' || ch == 'P')
    {
        SLL *i, *j;
        int tempRoll;
        float tempmarks;
        char tempName[50];      

        for(i = *ptr; i != 0; i = i->next)
        {
            for(j = i->next; j !=0; j = j->next)
            {
                if(i->marks < j->marks)
                {
                    tempRoll = i->rollno;
                    i->rollno = j->rollno;
                    j->rollno = tempRoll;

                    strcpy(tempName, i->name);
                    strcpy(i->name, j->name);
                    strcpy(j->name, tempName);

                    tempmarks = i->marks;
                    i->marks = j->marks;
                    j->marks = tempmarks;
                }
            }
        }

        printf("Sorted by marks\n");
    }

    else
    {
        printf("Invalid choice\n");
    }
}

// Delete All Record 
void deleteAll(SLL **ptr)
{
    SLL *del;
    int count = 0;
    while(*ptr != 0)
    {
        del = *ptr;
        *ptr = del->next;
        free(del);
        count++;
    }

    if(count > 0)
    {
        printf("%d record(s) deleted\n", count);
    }
}

// Reversing List
void reverseList(SLL **ptr)
{
    SLL *prev;
    SLL *curr;
    SLL *next;

    if(*ptr == 0)
    {
        printf("No records available\n");
        return;
    }

    prev = NULL;
    curr = *ptr;

    while(curr !=0)
    {
        next = curr->next;

        curr->next = prev;

        prev = curr;
        curr = next;
    }
    *ptr = prev;
    printf("List reversed successfully\n");
}

