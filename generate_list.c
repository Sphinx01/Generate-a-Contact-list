#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**fEempty return 1 if the file is empty or 0 if it's not**/
int fEmpty(FILE* file)
{
    int firstChar = 0;

    //Read the first char of the file
    firstChar = fgetc(file);
    if(firstChar == EOF)
    {
        return 1;//The file is empty, return 1
    }
    return 0;//The file is not empty, return 0
}

/** Concatenate : makes contact list lines. Example :  **/
/** ,,,,,,,,,,,,,,personne1@gmail.com,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,Normal,,,
 **/

void concatenate(char*line){

    char a[200] = ",,,,,,,,,,,,,,";
    char b[200] = ",,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,Normal,,,\n";

    strcat(a,line);
    a[strlen(a) - 1] = '\0';
    strcat(a,b);
    strcpy(line,a);
}

/** fillFile adds lines after concatenation to the contact list **/
/* file1 is the contact list, file2 is the emails file */

void fillFile(FILE *file1, FILE *file2){

   if ( file2 != NULL )
   {
        char email [ 200 ];
        char a = fgetc (file2);

        while(a != EOF){
        while ( fgetc (file2 ) != ',' ) /* read a line */
        {
            strcat(email,a);
            fprintf(file1, email);
        }
    }
   }
    fclose ( file1 );
    fclose ( file2 );
}

int main(int argc, char *argv[])
{
    FILE* file1 = NULL, *file2 = NULL;
    const char *firstLine= "First Name,Middle Name,Last Name,Title,Suffix,Initials,Web Page,Gender,Birthday,Anniversary,Location,Language,Internet Free Busy,Notes,E-mail Address,E-mail 2 Address,E-mail 3 Address,Primary Phone,Home Phone,Home Phone 2,Mobile Phone,Pager,Home Fax,Home Address,Home Street,Home Street 2,Home Street 3,Home Address PO Box,Home City,Home State,Home Postal Code,Home Country,Spouse,Children,Manager's Name,Assistant's Name,Referred By,Company Main Phone,Business Phone,Business Phone 2,Business Fax,Assistant's Phone,Company,Job Title,Department,Office Location,Organizational ID Number,Profession,Account,Business Address,Business Street,Business Street 2,Business Street 3,Business Address PO Box,Business City,Business State,Business Postal Code,Business Country,Other Phone,Other Fax,Other Address,Other Street,Other Street 2,Other Street 3,Other Address PO Box,Other City,Other State,Other Postal Code,Other Country,Callback,Car Phone,ISDN,Radio Phone,TTY/TDD Phone,Telex,User 1,User 2,User 3,User 4,Keywords,Mileage,Hobby,Billing Information,Directory Server,Sensitivity,Priority,Private,Categories\n";

    file1 = fopen("f1.csv", "a");
    file2 = fopen("f2.txt", "r");

    if (file1 != NULL)
    {
        if(fEmpty(file1) == 1)
        {
            fputs(firstLine, file1);
        }
        fillFile(file1,file2);

        fclose(file1);
        fclose(file2);
    }
    else
    {
        // Error message
        printf("Impossible to open the file ");
    }

    return 0;
    }
