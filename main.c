#include <stdio.h>
#include <stdlib.h>
struct contact
{
    char firstName[20];
    char lastName[20];
    char address[100];
    char city[20];
    char phone[12];
};
int main()
{
    char x;
    printf("\n\t\t\t      Telephone Directory\n\t\t\t   =========================\nPlease choose an option:\n-------------------------\n(1)Show contacts\n(2)Add contact\n(3)Search for a contact\n(4)Delete contact\n(5)Modify contact\n(6)Save\n(7)Exit");
    while(x!='7')
    {
        printf("\n\nYour choice: ");
        scanf("%s",&x);
        switch (x)
        {
        case '1':
            load();
            break;
        case '2':
            add();
            break;
        case '3':
            query();
            break;
        case '4':
            del();
            break;
        case '5':
            modify();
            break;
        case '6':
            save();
            break;
        case '7':
            break ;

        case '\n':
        case '\t':
        case ' ':


        default:
            printf( "\nWrong entry!" );
        }
    }
    return 0;
}
void load()
{
    struct contact person[100];
    int i=0,j;
    FILE *file;
    file=fopen("phonebook.txt","r");
    while(!feof(file))
    {
        fscanf(file,"%[^,],%[^,],%[^,],%[^,],%s\n",person[i].firstName,person[i].lastName,person[i].address,person[i].city,person[i].phone);

        i++;
    }
    for(j=0; j<i; j++)
    {
        printf("\nLast name: %s\nFirst name: %s\nAddress: %s\nCity: %s\nNumber: %s\n-----------------------------",person[j].lastName,person[j].firstName,person[j].address,person[j].city,person[j].phone);
    }
}
void query()
{
    struct contact person[100];
    char ln[20];
    int i=0,j;
    FILE *file;
    file=fopen("phonebook.txt","r");
    while(!feof(file))
    {
        fscanf(file,"%[^,],%[^,],%[^,],%[^,],%s\n",person[i].firstName,person[i].lastName,person[i].address,person[i].city,person[i].phone);
        i++;
    }
    printf("\nPlease enter the person's last name: ");
    scanf("%s",&ln);
    for(j=0; j<i; j++)
    {
        if(strcmp(ln,person[j].lastName)==0)
        {
            printf("\n-----------------------------\nLast name: %s\nFirst name: %s\nAddress: %s\nCity: %s\nNumber: %s\n-----------------------------",person[j].lastName,person[j].firstName,person[j].address,person[j].city,person[j].phone);
            return;
        }

    }
    printf("\nContact not found.\n");
}
void add()
{
    struct contact person[100];
    int i=0;
    FILE *file;
    file=fopen("phonebook.txt","a+");
    while(!feof(file))
    {
        fscanf(file,"%[^,],%[^,],%[^,],%[^,],%s\n",person[i].firstName,person[i].lastName,person[i].address,person[i].city,person[i].phone);
        i++;
    }
    printf("\nPlease enter the first name: ");
    scanf("%s",person[i].firstName);
    printf("\nPlease enter the last name: ");
    scanf("%s",person[i].lastName);
    printf("\nPlease enter the address: ");
    scanf("%s",person[i].address);
    printf("\nPlease enter the city: ");
    scanf("%s",person[i].city);
    printf("\nPlease enter the phone number: ");
    scanf("%s",person[i].phone);
    fprintf(file,"%s,%s,%s,%s,%s\n",person[i].firstName,person[i].lastName,person[i].address,person[i].city,person[i].phone);
    i++;
    fclose(file);
}
void del()
{
    struct contact person[100];
    char fn[20];
    char ln[20];
    int i=0,j,z;
    FILE *file;
    FILE *file2;
    file=fopen("phonebook.txt","a+");
    while(!feof(file))
    {
        fscanf(file,"%[^,],%[^,],%[^,],%[^,],%s\n",person[i].firstName,person[i].lastName,person[i].address,person[i].city,person[i].phone);
        i++;
    }
    printf("\nPlease enter the person's first name:");
    scanf("%s",&fn);
    printf("\nPlease enter the person's last name:");
    scanf("%s",&ln);
    for(j=0; j<i; j++)
    {
        if(strcmp(ln,person[j].lastName)==0&&strcmp(fn,person[j].firstName)==0)
        {
            file2=fopen("phonebook2.txt","w");
            for(z=0; z<i; z++)
            {
                if(z!=j)
                {

                    fprintf(file2,"%s,%s,%s,%s,%s\n",person[z].firstName,person[z].lastName,person[z].address,person[z].city,person[z].phone);
                }
            }
            fclose(file);
            fclose(file2);
            file=fopen("phonebook.txt","w");
            file2=fopen("phonebook2.txt","r");
            i=0;
            while(!feof(file2))
            {
                fscanf(file2,"%[^,],%[^,],%[^,],%[^,],%s\n",person[i].firstName,person[i].lastName,person[i].address,person[i].city,person[i].phone);
                i++;
            }
            for(j=0; j<i; j++)
            {

                fprintf(file,"%s,%s,%s,%s,%s\n",person[j].firstName,person[j].lastName,person[j].address,person[j].city,person[j].phone);
            }
            fclose(file);
            fclose(file2);
            printf("\nContact is deleted.");
            return;

        }


    }
    printf("\nContact not found.\n");


}
    void modify()
{
    struct contact person[100];
    char ln[20];
    int i=0,j;
    FILE *file;
    FILE *file2;
    file2=fopen("phonebook2.txt","w");
    file=fopen("phonebook.txt","a+");
    while(!feof(file))
    {
        fscanf(file,"%[^,],%[^,],%[^,],%[^,],%s\n",person[i].firstName,person[i].lastName,person[i].address,person[i].city,person[i].phone);
        i++;
    }
    printf("\nPlease enter the person's last name:");
    scanf("%s",&ln);
    for(j=0; j<i; j++)
    {
        if(strcmp(ln,person[j].lastName)==0)
        {

            printf("\nPlease enter the first name: ");
            scanf("%s",person[j].firstName);
            printf("\nPlease enter the last name: ");
            scanf("%s",person[j].lastName);
            printf("\nPlease enter the address: ");
            scanf("%s",person[j].address);
            printf("\nPlease enter the city: ");
            scanf("%s",person[j].city);
            printf("\nPlease enter the phone number: ");
            scanf("%s",person[j].phone);
        }
    }
    for(j=0; j<i; j++)
    {

        fprintf(file2,"%s,%s,%s,%s,%s\n",person[j].firstName,person[j].lastName,person[j].address,person[j].city,person[j].phone);
    }
    fclose(file);
    fclose(file2);
    file=fopen("phonebook.txt","w");
    file2=fopen("phonebook2.txt","r");
    i=0;
    while(!feof(file2))
    {
        fscanf(file2,"%[^,],%[^,],%[^,],%[^,],%s\n",person[i].firstName,person[i].lastName,person[i].address,person[i].city,person[i].phone);
        i++;
    }
    for(j=0; j<i; j++)
    {

        fprintf(file,"%s,%s,%s,%s,%s\n",person[j].firstName,person[j].lastName,person[j].address,person[j].city,person[j].phone);
    }
    fclose(file);
    fclose(file2);
    printf("\nContact modified.");
}

void save()
{
    struct contact person[100];
    int i=0,j;
    FILE *file;
    FILE *file2;
    file=fopen("phonebook.txt","r");
    file2=fopen("phonebook2.txt","w");
    while(!feof(file))
    {
        fscanf(file,"%[^,],%[^,],%[^,],%[^,],%s\n",person[i].firstName,person[i].lastName,person[i].address,person[i].city,person[i].phone);

        i++;
    }
    for(j=0; j<i; j++)
    {

        fprintf(file2,"%s,%s,%s,%s,%s\n",person[j].firstName,person[j].lastName,person[j].address,person[j].city,person[j].phone);
    }
    fclose(file);
    fclose(file2);
    printf("\nContacts saved in the external file.");
}
