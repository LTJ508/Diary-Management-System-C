#include <stdio.h>//standard input output
#include <stdlib.h>//for using system("cls"); function
#include <string.h>//for using various string function
#include <conio.h>//for using getch() function
#include <unistd.h>//for using getcwd and mkdir function for creating folder and checking file

//all function prototype
void CHECK_DIRECTORY(void);//for checking admin file exist or not
void DIRECTORY_CREATE(void);//for creating folder and sub folder
void SET_PASSWORD(void);//for setting new user name and password
void IDENTITY_VERIFY(void);//for login
void UPDATE_PASSWORD(void);//for set new password and security questions
void UPDATE_SECURITY_QUESTION(void);//for setting new security questions
void RESET_PASSWORD(void);//for reset password

void ADD_NOTES(void);
void VIEW_NOTES(void);
void EDIT_NOTES(void);
void DELETE_NOTES(void);

void ADD_SCHEDULE(void);
void VIEW_SCHEDULE(void);
void EDIT_SCHEDULE(void);
void DELETE_SCHEDULE(void);

void ADD_CLIENT_INFORMATION(void);
void VIEW_CLIENT_INFORMATION(void);
void EDIT_CLIENT_INFORMATION(void);
void DELETE_CLIENT_INFORMATION(void);

void ABOUT(void);
void WELCOME_SCREEN(void);
void HEADER_SCREEN(char menu_msg[]);
void EXIT_SCREEN(void);

//global variable
char current_directory[1000];//Ready to use
char admin_directory[1000];//Ready to use
char filename_admin[] = "\\database\\admin";//complete
char reverse_current_directory[1000];//complete
char folder_notes[] = "/database/notes";//complete
char folder_client_information[] = "/database/client_information";//complete
char folder_daily_schedule[] = "/database/daily_schedule";//complete
char notes_directory[1000];//complete
char client_information_directory[1000];//complete
char daily_schedule_directory[1000];//complete

//main function start here
int main()
{
    char command;

    CHECK_DIRECTORY();//calling function

    system("cls");//clearing console

    IDENTITY_VERIFY();//calling function

    //now its time to show menu

    while(1){
        system("cls");//clearing console

        WELCOME_SCREEN();//calling function
        HEADER_SCREEN("MAIN MENU");//calling function

        printf("\n\t\t=> 1. Open Note Book\n\t\t=> 2. Open Daily Schedule\n\t\t=> 3. Open Client Information\n\t\t=> 4. Security Settings\n\t\t=> 5. About\n\t\t=> 6. Exit\n\n\tNow Enter Command: ");
        command = getch();

        if(command == '1'){//if command is 1
            while(1){//again infinity loop
                system("cls");//clearing console first

                HEADER_SCREEN("NOTE BOOK");//calling function

                printf("\n\t\t=> 1. Add New Note\n\t\t=> 2. View Note\n\t\t=> 3. Edit Note\n\t\t=> 4. Delete Note\n\t\t=> 5. Exit\n\n\tNow Enter Command: ");
                command = getch();

                if(command == '1'){
                    ADD_NOTES();//calling function
                }
                else if(command == '2'){
                    VIEW_NOTES();//calling function
                }
                else if(command == '3'){
                    EDIT_NOTES();//calling function
                }
                else if(command == '4'){
                    DELETE_NOTES();//calling function
                }
                else if(command == '5'){
                    break;//it will break the loop and go to previous menu
                }
                else{//if wrong command enter
                    printf("\n\tWrong Command!! Press any key to try again..");
                    getch();//taking any  key input
                    continue;//it will continue the loop again
                }
            }
        }
        else if(command == '2'){//if command is 2
            while(1){//again infinity loop
                system("cls");//clearing console first

                HEADER_SCREEN("DAILY SCHEDULE");//calling function

                printf("\n\t\t=> 1. Add New Schedule\n\t\t=> 2. View Schedule\n\t\t=> 3. Edit Schedule\n\t\t=> 4. Delete Schedule\n\t\t=> 5. Exit\n\n\tNow Enter Command: ");
                command = getch();

                if(command == '1'){
                    ADD_SCHEDULE();//calling function
                }
                else if(command == '2'){
                    VIEW_SCHEDULE();//calling function
                }
                else if(command == '3'){
                    EDIT_SCHEDULE();//calling function
                }
                else if(command == '4'){
                    DELETE_SCHEDULE();//calling function
                }
                else if(command == '5'){
                    break;//it will break the loop and go to previous menu
                }
                else{//if wrong command enter
                    printf("\n\tWrong Command!! Press any key to try again..");
                    getch();//taking any  key input
                    continue;//it will continue the loop again
                }
            }
        }
        else if(command == '3'){//if command is 3
            while(1){//again infinity loop
                system("cls");//clearing console first

                HEADER_SCREEN("CLIENT INFORMATION");//calling function

                printf("\n\t\t=> 1. Add New Client\n\t\t=> 2. View Client Information\n\t\t=> 3. Edit Client Information\n\t\t=> 4. Delete Client Information\n\t\t=> 5. Exit\n\n\tNow Enter Command: ");
                command = getch();

                if(command == '1'){
                    ADD_CLIENT_INFORMATION();//calling function
                }
                else if(command == '2'){
                    VIEW_CLIENT_INFORMATION();//calling function
                }
                else if(command == '3'){
                    EDIT_CLIENT_INFORMATION();//calling function
                }
                else if(command == '4'){
                    DELETE_CLIENT_INFORMATION();//calling function
                }
                else if(command == '5'){
                    break;//it will break the loop and go to previous menu
                }
                else{//if wrong command enter
                    printf("\n\tWrong Command!! Press any key to try again..");
                    getch();//taking any  key input
                    continue;//it will continue the loop again
                }
            }
        }
        else if(command == '4'){//if command is 5
            while(1){//again infinity loop
                system("cls");//clearing console first

                HEADER_SCREEN("SECURITY SETTINGS");//calling function

                printf("\n\t\t=> 1. Update Password\n\t\t=> 2. Update Security Question\n\t\t=> 3. Exit\n\n\tNow Enter Command: ");
                command = getch();

                if(command == '1'){
                    UPDATE_PASSWORD();//calling function
                }
                else if(command == '2'){
                    UPDATE_SECURITY_QUESTION();//calling function
                }
                else if(command == '3'){
                    break;//it will break the loop and go to previous menu
                }
                else{//if wrong command enter
                    printf("\n\tWrong Command!! Press any key to try again..");
                    getch();//taking any  key input
                    continue;//it will continue the loop again
                }
            }
        }
        else if(command == '5'){//if command is 6
            ABOUT();
        }
        else if(command == '6'){//if command is 7
            EXIT_SCREEN();
            break;
        }
        else{//if read any wrong input
            printf("\n\tWrong Command!! Press any key to try again..");
            getch();
            continue;
        }
    }
}//main function end

void CHECK_DIRECTORY(void)
{
    FILE *check_directory;//assigning file pointer
    int i, j, length_current_directory, length_filename_admin;

    getcwd(current_directory, 1000);//getting current working directory

    length_current_directory = strlen(current_directory);//calculating length of current directory
    length_filename_admin = strlen(filename_admin);

    strcpy(admin_directory, current_directory);//copy current directory to admin directory
    strcat(admin_directory, filename_admin);//combining admin directory and filename admin

    check_directory = fopen(admin_directory, "r");//trying to open a file to check it exist or not

    if(check_directory == NULL){//if not exist
        printf("\n\tIt seems that you have opened this program for the first time.\n\tYou need to set a user name and a password first;\n\tthen, you can use this program.\n\tPress any key to continue: ");
        getch();
        DIRECTORY_CREATE();
        SET_PASSWORD();
    }
    else{//if exist
        fclose(check_directory);
    }
}

void DIRECTORY_CREATE(void)
{
    int i, j, temp;
    FILE *create_file_admin;

    for( i = 0; i < strlen(current_directory); i++){//making a reverse directory for creating folder
        if(current_directory[i] == '\\'){
            reverse_current_directory[i] = '/';
        }
        else{
            reverse_current_directory[i] = current_directory[i];
        }
    }

    reverse_current_directory[i] = '\0';//end of reverse directory

    strcpy(notes_directory, reverse_current_directory);//copy reverse current directory to notes directory
    strcpy(client_information_directory, reverse_current_directory);//copy reverse current directory to address book directory
    strcpy(daily_schedule_directory, reverse_current_directory);//copy reverse current directory to daily schedule directory

    strcat(notes_directory, folder_notes);//combining notes directory and folder notes
    strcat(client_information_directory, folder_client_information);//combining address directory and folder address book
    strcat(daily_schedule_directory, folder_daily_schedule);//combining daily schedule directory and folder daily schedule

    mkdir("database");//creating folder "database"
    mkdir(notes_directory);//creating folder notes
    mkdir(client_information_directory);//creating folder address book
    mkdir(daily_schedule_directory);//creating folder daily schedule

    create_file_admin = fopen(admin_directory, "w");//creating file admin
    fclose(create_file_admin);//closing file
}

void SET_PASSWORD(void)
{
    FILE *open_admin;//declaring file pointer
    char user_name[10];
    char password[20];
    char password_confirm[20];
    char color[20];
    char sports[20];
    char pets[20];
    int i;

    open_admin = fopen(admin_directory, "w");//opening admin file

    if(open_admin == NULL){
        printf("\n\tSystem File Missing..");//if file is missing
    }
    else{
        system("cls");//clearing console

        printf("\n\tEnter your new User Name(no space, limit 10): ");
        scanf("%s", user_name);//taking user name
        getchar();//clearing buffer

        for(i = 0; i < strlen(user_name); i++){
            fprintf(open_admin, "%c", user_name[i] + 508);//storing user name using encryption
        }
        fprintf(open_admin, "\n");//for new line in database

        while(1){
            system("cls");

            printf("\n\tEnter your User Name(no space, limit 10): %s", user_name);

            printf("\n\tEnter New Password(limit 20, no space): ");
            scanf("%s", password);//scanning password
            getchar();//clearing buffer

            printf("\n\tConfirm New Password(limit 20, no space): ");
            scanf("%s", password_confirm);//scanning password
            getchar();//clearing buffer

            if(strcmp(password, password_confirm) == 0){//checking password match or not
                for(i = 0; i < strlen(password); i++){//if match then store it
                    fprintf(open_admin, "%c", password[i] + 508);//storing password using encryption
                }
                break;//and break the loop
            }
            else{
                printf("\n\tPassword doesn't match. Press any key to try again: ");
                getch();
                continue;//if not match then retry it;
            }
        }

        system("cls");//clearing console

        printf("\n\tPassword set successfully.\n\tPress any key to continue: ");//success message
        getch();//getting any key signal

        fprintf(open_admin, "\n");//for new line in database

        system("cls");//clearing console

        printf("\n\tIn case you forget your password:\n\n\tWhats your favorite color: ");
        scanf("%s", color);//taking input of color name
        getchar();//clearing buffer
        printf("\n\tWhats your favorite sports: ");
        scanf("%s", sports);//taking input of sports name
        getchar();//clearing buffer
        printf("\n\tWhats your favorite pets name: ");
        scanf("%s", pets);//taking input of pets name
        getchar();//clearing buffer

        for(i = 0; i < strlen(color); i++){
            fprintf(open_admin, "%c", color[i] + 508);//storing color name in file using encryption
        }
        fprintf(open_admin, "\n");//for new line in database

        for(i = 0; i < strlen(sports); i++){
            fprintf(open_admin, "%c", sports[i] + 508);//storing sports name in file using encryption
        }
        fprintf(open_admin, "\n");//for new line in database

        for(i = 0; i < strlen(pets); i++){
            fprintf(open_admin, "%c", pets[i] + 508);//storing pets name in file using encryption
        }

        system("cls");//clearing console

        printf("\n\tSecurity Question set successfully.\n\tPress any key to continue: ");//success message
        getch();//getting any key signal

        fclose(open_admin);//closing file
    }
}

void IDENTITY_VERIFY(void)
{
    FILE *open_admin;
    char user_name[10];//this will be real user name
    char user_name_input[10];//user input user name
    char password[20];//this will be real password
    char password_input[20];//user input password
    int i, run = 1, access = 0;//for running loop
    char command, ch = ' ';

    open_admin = fopen(admin_directory, "r");//opening admin file in reading mood

    if(open_admin == NULL){
        printf("\n\tSystem File Missing..Press any key to continue..");//if not open system file missing program crash
        getch();//any key signal
    }
    else{//if open perfectly then do this
        fgets(user_name, 10, open_admin);//reading encrypted user name from file
        for(i = 0; i < strlen(user_name); i++){//decrypting user name
            user_name[i] = user_name[i] - 508;
        }
        user_name[i-1] = '\0';//deleting the new line in admin file

        fgets(password, 20, open_admin);//reading encrypted password
        for(i = 0; i < strlen(password); i++){//decrypting password
            password[i] = password[i] - 508;
        }
        password[strlen(password)-1] = '\0';//deleting the new line in admin file

        while(run < 4){//now checking user input
            system("cls");//clearing console
            printf("\n\tPlease Verify your Identity:");
            printf("\n\tEnter Your User Name: ");
            scanf("%s", user_name_input);//taking input of user name
            getchar();//clearing buffer

            if(strcmp(user_name, user_name_input) == 0){//checking is it match with admin user name or not
                printf("\n\tEnter Your Password: ");

                for(i = 0; i < 20; i++){
                    password_input[i] = getch();//taking input as ghost no character will display in the console
                    ch = password_input[i];//assigning to ch for checking
                    if(ch == 13){//if ch equals to enter key
                        break;//break
                    }
                    else{
                        printf("*");//otherwise it will print *
                    }
                }
                password_input[i] = '\0';//end of password

                if(strcmp(password, password_input) == 0){//again checking if is it match with admin password
                    printf("\n\n\tACCESS GRANTED..\n\n\tPress Any Key to Continue..");//if match print access granted
                    getch();//taking any key input
                    system("cls");//clearing console
                    access = 1;
                    break;//breaking while loop
                }
                else{//if password not match
                    printf("\n\tWrong Password. Press any key to try Again..");
                    getch();
                    system("cls");
                    run++;
                    continue;//it will repeat the password input option again
                }
            }
            else{//if user  name not match it will be repeat
                printf("\n\tWrong User Name. Press any key to try Again..");
                getch();
                system("cls");
                continue;//it will be repeat the user name input option
            }
        }

        fclose(open_admin);//closing file

        if(access == 0){//if continuous enter wrong password three times
            while(1){
                system("cls");//clearing console screen

                printf("\n\tIt seems that you entered the wrong cardinals three times.\n\tDo you forget your password?\n\tWant to reset it?(Y/N)\n\n\tEnter Command: ");
                command = getch();

                if(command == 'Y' || command == 'y'){//if command 1
                    RESET_PASSWORD();//calling function
                    break;
                }
                else{//if read any wrong input
                    printf("\n\tWrong Command!! Press any key to try again..");
                    getch();//for any key signal
                    continue;//it will continue the loop
                }
            }
        }
    }
}

void UPDATE_PASSWORD(void)
{
    IDENTITY_VERIFY();//calling function

    SET_PASSWORD();//calling function
}

void UPDATE_SECURITY_QUESTION(void)
{
    FILE *open_admin;//declaring file pointer

    char user_name[20];//declaring user name string
    char password[20];//declaring password string
    char color[20];//declaring color string
    char sports[20];//declaring sports string
    char pets[20];//declaring pets string

    int i;//for running loop

    IDENTITY_VERIFY();//calling function

    open_admin = fopen(admin_directory, "r");//opening file in reading mood for collecting user name and password

    if(open_admin == NULL){
        printf("\n\tSystem File Missing...\n\tPress any key to continue..");//if file cannot be open
        getch();//any key signal
    }
    else{//if open then collect information
        fgets(user_name, 20, open_admin);//scanning user name
        for(i = 0; i < strlen(user_name); i++){
            user_name[i] = user_name[i] - 508;//decryption
        }
        user_name[i-1] = '\0';//removing new line

        fgets(password, 20, open_admin);//scanning password
        for(i = 0; i < strlen(password); i++){
            password[i] = password[i] - 508;//decryption
        }
        password[i-1] = '\0';//removing new line

        fclose(open_admin);//closing file

        system("cls");//clearing console

        printf("\n\tIn case you forget your password:\n\n\tWhats your favorite color: ");
        scanf("%s", color);//taking input of color name
        getchar();//clearing buffer
        printf("\n\tWhats your favorite sports: ");
        scanf("%s", sports);//taking input of sports name
        getchar();//clearing buffer
        printf("\n\tWhats your favorite pets name: ");
        scanf("%s", pets);//taking input of pets name
        getchar();//clearing buffer

        open_admin = fopen(admin_directory, "w");//opening file again in writing mood

        if(open_admin == NULL){
            printf("\n\tSecurity Question Update Failed.. Press any key to continue..");//if can't open
            getch();//any key signal
        }
        else{//if open then start writing
            for(i = 0; i < strlen(user_name); i++){
                fprintf(open_admin, "%c", user_name[i] + 508);//storing user name using encryption
            }

            fprintf(open_admin, "\n");//for new line in database

            for(i = 0; i < strlen(password); i++){//if match then store it
                fprintf(open_admin, "%c", password[i] + 508);//storing password using encryption
            }

            fprintf(open_admin, "\n");//for new line in database

            for(i = 0; i < strlen(color); i++){
                fprintf(open_admin, "%c", color[i] + 508);//storing color name in file using encryption
            }
            fprintf(open_admin, "\n");//for new line in database

            for(i = 0; i < strlen(sports); i++){
                fprintf(open_admin, "%c", sports[i] + 508);//storing sports name in file using encryption
            }
            fprintf(open_admin, "\n");//for new line in database

            for(i = 0; i < strlen(pets); i++){
                fprintf(open_admin, "%c", pets[i] + 508);//storing pets name in file using encryption
            }

            system("cls");//clearing console

            printf("\n\tSecurity Question Updated Successfully.\n\tPress any key to continue..");//success message
            getch();//any key signal
            fclose(open_admin);//closing file
        }
    }
}

void RESET_PASSWORD(void)
{
    FILE *open_admin;//declaring file pointer
    char color[20];//declaring color string which will be scan from file
    char sports[20];//declaring sports string which will be scan from file
    char pets[20];//declaring pets string which will be scan from file
    char color_input[20];//declaring color string which will be scan from user
    char sports_input[20];//declaring sports string which will be scan from user
    char pets_input[20];//declaring pets string which will be scan from user
    char temp_string[20];//declaring temp string i will use it for moving the pointer in file
    int i;//for running loop

    open_admin = fopen(admin_directory, "r");//opening file in reading mood

    if(open_admin == NULL){//if file missing
        printf("\n\tSystem File Missing.. Press any key to continue...");
        getch();//any key signal
    }

    else{
        fgets(temp_string, 20, open_admin);//moving pointer location by scanning temp string
        fgets(temp_string, 20, open_admin);//moving pointer location by scanning temp string

        fgets(color, 20, open_admin);//scanning color from file
        for(i = 0; i < strlen(color); i++){//decryption
            color[i] = color[i] - 508;
        }
        color[i-1] = '\0';//removing new line

        fgets(sports, 20, open_admin);//scanning sports from file
        for(i = 0; i < strlen(sports); i++){//decryption
            sports[i] = sports[i] - 508;
        }
        sports[i-1] = '\0';//removing new line

        fgets(pets, 20, open_admin);//scanning pets from file
        for(i = 0; i < strlen(pets); i++){//decryption
            pets[i] = pets[i] - 508;
        }

        while(1){
            system("cls");//clearing console

            printf("\n\tWhats your favorite color: ");
            gets(color_input);//taking input from user for color

            if(strcmp(color, color_input) == 0){//comparing color input
                printf("\n\tWhats your favorite sports: ");
                gets(sports_input);//taking input from user for sports name

                if(strcmp(sports, sports_input) == 0){//comparing sports name
                    printf("\n\tWhats your favorite pets name: ");
                    gets(pets_input);//taking input from user for pets name

                    if(strcmp(pets, pets_input) == 0){//comparing pets name
                        printf("\n\tAccess Granted..\n\tPress any key to continue..");
                        getch();//any key signal
                        fclose(open_admin);//closing file
                        SET_PASSWORD();//calling function
                        break;//breaking the loop
                    }
                    else{
                        printf("\n\tWrong Input.. Press any key to try again..");
                        getch();//any key signal
                        continue;//if pets name not match continue again
                    }
                }
                else{
                    printf("\n\tWrong Input.. Press any key to try again..");
                    getch();//any key signal
                    continue;//if sports name not match continue again
                }
            }
            else{
                printf("\n\tWrong Input.. Press any key to try again..");
                getch();//any key signal
                continue;//if color name not match continue again
            }
        }
    }
}




void ADD_NOTES(void)
{
    system("cls");//clearing console

    char title[100];//declaring title string
    char notes[1000];//declaring notes string
    char notes_direction_file[1000];//this will be the file directory where notes will be save
    FILE *open_notes_file;//declaring file pointer

    while(1){
        system("cls");//clearing console

        printf("\n\tEnter Title: ");
        gets(title);//taking input for title

        strcpy(notes_direction_file, current_directory);//copy current directory to notes directory
        strcat(notes_direction_file, "\\database\\notes\\");//combining extra directory to notes file directory
        strcat(notes_direction_file, title);//combining file name to notes directory

        open_notes_file = fopen(notes_direction_file, "r");//opening notes file in reading mood

        if(open_notes_file != NULL){
            printf("\n\tIt seems that you already have a notes by this name.\n\tYou can't add two notes by the same name.\n\tPress any key to try again...");
            getch();//any key signal
            fclose(open_notes_file);//closing file
            continue;//continue loop for another input
        }
        else{
            break;//break the loop
        }
    }

    open_notes_file = fopen(notes_direction_file, "w");//opening notes file in writing mood

    if(open_notes_file == NULL){//if cannot create file
        printf("\n\tUnable to create file..\n\tPress any key to continue..");
        getch();//any key signal
    }
    else{
        printf("\n\tEnter your Notes: ");
        gets(notes);//taking input for notes

        for(int i = 0; i < strlen(notes); i++){
            fprintf(open_notes_file, "%c", notes[i] + 508);//storing notes in file using encryption
        }

        printf("\n\tYour notes saved successfully.\n\tPress any key to continue..");
        getch();//any key signal
        fclose(open_notes_file);//closing file
    }
}

void VIEW_NOTES(void)
{
    system("cls");//clearing console

    char title[100];//declaring title string
    char ch;//declaring character

    printf("\n\tFor opening your notes please enter Title: ");
    gets(title);//taking input for title

    char notes_direction_file[1000];//declaring string for creating directory

    strcpy(notes_direction_file, current_directory);//copy current directory to notes directory
    strcat(notes_direction_file, "\\database\\notes\\");//combining extra directory to notes directory
    strcat(notes_direction_file, title);//combining title to notes directory

    FILE *open_notes_file;//declaring file pointer

    open_notes_file = fopen(notes_direction_file, "r");//opening file in reading mood

    if(open_notes_file == NULL){//if file not found
        printf("\n\tNotes not found in database..\n\tPress any key to continue..");
        getch();//any key signal
    }

    else{
        printf("\n\tNotes: ");

        while(1){
            ch = fgetc(open_notes_file);//scanning character one by one
            if(ch == EOF){
                break;//if end of file then break
            }
            else{
                printf("%c", ch-508);//printing in console character one by one by decrypting
            }
        }

        printf("\n\n\tPress any key to continue..");
        getch();//any key signal

        fclose(open_notes_file);//closing file
    }
}

void EDIT_NOTES(void)
{
    FILE *open_notes_file;//declaring file pointer

    char title[100];//declaring title string
    char notes[1000];//declaring notes string
    char ch;//declaring character

    system("cls");//clearing console

    printf("\n\tFor opening your notes please enter Title: ");
    gets(title);//taking input for title

    char notes_direction_file[1000];//declaring string for creating directory

    strcpy(notes_direction_file, current_directory);//copy current directory to notes directory
    strcat(notes_direction_file, "\\database\\notes\\");//combining extra directory to notes directory
    strcat(notes_direction_file, title);//combining title to notes directory

    open_notes_file = fopen(notes_direction_file, "r");//opening file in reading mood

    if(open_notes_file == NULL){//if file not found
        printf("\n\tNotes not found in database..\n\tPress any key to continue..");
        getch();//any key signal
    }
    else{
        printf("\n\tPrevious Notes: ");//showing previous notes

        while(1){
            ch = fgetc(open_notes_file);//scanning character one by one
            if(ch == EOF){
                break;//if end of file then break
            }
            else{
                printf("%c", ch-508);//printing in console character one by one by decrypting
            }
        }

        fclose(open_notes_file);//closing file

        printf("\n\n\tEnter your New Notes: ");
        gets(notes);//taking input for notes

        printf("\n\n\tAre you sure you want to edit your notes?(Y/N): ");
        ch = getch();

        if(ch == 'Y' || ch == 'y'){
            IDENTITY_VERIFY();//calling function for security

            open_notes_file = fopen(notes_direction_file, "w");//opening notes file in writing mood

            if(open_notes_file == NULL){//if cannot create file
                printf("\n\tUnable to Edit Notes..\n\tPress any key to continue..");
                getch();//any key signal
            }
            else{
                for(int i = 0; i < strlen(notes); i++){
                    fprintf(open_notes_file, "%c", notes[i] + 508);//storing notes in file using encryption
                }

                printf("\n\n\tYour notes edited successfully.\n\tPress any key to continue..");
                getch();//any key signal
                fclose(open_notes_file);//closing file
            }
        }
        else{
            printf("\n\n\tEdit canceled..\n\tPress any key to Continue...");
            getch();//any key signal
        }
    }
}

void DELETE_NOTES(void)
{
    FILE *open_notes_file;//declaring

    char title[100];//declaring title string
    char ch;//declaring character
    int status;//declaring integer for checking file deletion

    system("cls");//clearing console

    printf("\n\tFor deleting your notes please enter Title: ");
    gets(title);//taking input for title

    char notes_direction_file[1000];//declaring string for creating directory

    strcpy(notes_direction_file, current_directory);//copy current directory to notes directory
    strcat(notes_direction_file, "\\database\\notes\\");//combining extra directory to notes directory
    strcat(notes_direction_file, title);//combining title to notes directory

    open_notes_file = fopen(notes_direction_file, "r");//opening file in reading mood

    if(open_notes_file == NULL){//if file not found
        printf("\n\tNotes not found in database..\n\tPress any key to continue..");
        getch();//any key signal
    }
    else{
        printf("\n\tNotes: ");//showing notes

        while(1){
            ch = fgetc(open_notes_file);//scanning character one by one
            if(ch == EOF){
                break;//if end of file then break
            }
            else{
                printf("%c", ch-508);//printing in console character one by one by decrypting
            }
        }

        fclose(open_notes_file);//closing file

        printf("\n\n\tAre you sure you want to delete this notes? (Y/N): ");
        ch = getch();

        if(ch == 'Y' || ch == 'y'){

            IDENTITY_VERIFY();

            status = remove(notes_direction_file);//removing file

            if(status == 0){//if status 0 then file remove successful
                printf("\n\tFile Deleted successfully..\n\tPress any key to continue...");
                getch();//any key signal
            }
            else{//if not then unable to delete
                printf("\n\tFile Delete failed..\n\tPress any key to try again...");
                getch();//any key signal
            }
        }
        else{
            printf("\n\tDelete canceled...\n\tPress any key to continue..");
            getch();//any key signal
        }
    }
}




void ADD_SCHEDULE(void)
{
    FILE *open_schedule_file;

    char date[200];//declaring date string
    char time[200];//declaring time string
    char person[200];//declaring person string
    char place[200];//declaring place string
    char duration[200];//declaring duration string
    char notes[1000];//declaring notes string
    char schedule_file_direction[1000];//file directory string
    char ch;//for command

    char variable_name_Time[] = "\tTime: ";
    char variable_name_Person[] = "\n\tPerson: ";
    char variable_name_Place[] = "\n\tPlace: ";
    char variable_name_Duration[] = "\n\tDuration: ";
    char variable_name_Notes[] = "\n\tNotes: ";
    char variable_name_New_Line[] = "\n\n";

    int i;//for running loop

    system("cls");//clearing console

    printf("\n\tFor add new schedule please enter the date(DD-MM-YYYY): ");
    gets(date);//taking input for date

    //making file directory
    strcpy(schedule_file_direction, current_directory);
    strcat(schedule_file_direction, "\\database\\daily_schedule\\");
    strcat(schedule_file_direction, date);

    open_schedule_file = fopen(schedule_file_direction, "r");//trying to opening file in reading file

    if(open_schedule_file == NULL){//if cannot open thats means there is no file in this date
        open_schedule_file = fopen(schedule_file_direction, "w");//opening file in writing mood

        if(open_schedule_file == NULL){
            printf("\n\tUnable to create file..\n\tPress any key to continue..");
            getch();//any key signal
        }
        else{
            printf("\n\tEnter Time(HH:MM): ");
            gets(time);//taking input
            printf("\n\tEnter Person Name: ");
            gets(person);//taking input
            printf("\n\tEnter Place: ");
            gets(place);//taking input
            printf("\n\tEnter Duration: ");
            gets(duration);//taking input
            printf("\n\tEnter Short Notes: ");
            gets(notes);//taking input


            for(i = 0; i < strlen(variable_name_Time); i++){
                fprintf(open_schedule_file, "%c", variable_name_Time[i]+508);
            }
            for(i = 0; i < strlen(time); i++){
                fprintf(open_schedule_file, "%c", time[i] + 508);//storing time using encryption
            }


            for(i = 0; i < strlen(variable_name_Person); i++){
                fprintf(open_schedule_file, "%c", variable_name_Person[i]+508);
            }
            for(i = 0; i < strlen(person); i++){
                fprintf(open_schedule_file, "%c", person[i] + 508);//storing person using encryption
            }


            for(i = 0; i < strlen(variable_name_Place); i++){
                fprintf(open_schedule_file, "%c", variable_name_Place[i]+508);
            }
            for(i = 0; i < strlen(place); i++){
                fprintf(open_schedule_file, "%c", place[i] + 508);//storing place using encryption
            }


            for(i = 0; i < strlen(variable_name_Duration); i++){
                fprintf(open_schedule_file, "%c", variable_name_Duration[i]+508);
            }
            for(i = 0; i < strlen(duration); i++){
                fprintf(open_schedule_file, "%c", duration[i] + 508);//storing duration using encryption
            }

            for(i = 0; i < strlen(variable_name_Notes); i++){
                fprintf(open_schedule_file, "%c", variable_name_Notes[i]+508);
            }
            for(i = 0; i < strlen(notes); i++){
                fprintf(open_schedule_file, "%c", notes[i] + 508);//storing duration using encryption
            }


            for(i = 0; i < strlen(variable_name_New_Line); i++){
                fprintf(open_schedule_file, "%c", variable_name_New_Line[i]+508);
            }

            printf("\n\tYour Schedule saved successfully.\n\tPress any key to continue..");
            getch();//any key signal
            fclose(open_schedule_file);//closing file
        }
    }
    else{//if file can open in reading mood thats means user already have a schedule in this date
        fclose(open_schedule_file);//closing file from reading mood

        printf("\n\tIt seems that you already have a schedule for this date.\n\tDo you want to add another plan at a different time,\n\tor you can cancel and add another program on a different date?(Y/N): ");
        ch = getch();

        if(ch == 'Y' || ch == 'y'){//if yes then
            open_schedule_file = fopen(schedule_file_direction, "a");//open file in append mood

            if(open_schedule_file == NULL){
                printf("\n\tUnable to open file..\n\tPress any key to continue..");//if can't open
                getch();
            }
            else{
                printf("\n\tEnter Time(HH:MM): ");
                gets(time);//taking input
                printf("\n\tEnter Person Name: ");
                gets(person);//taking input
                printf("\n\tEnter Place: ");
                gets(place);//taking input
                printf("\n\tEnter Duration: ");
                gets(duration);//taking input
                printf("\n\tEnter Short Notes: ");
                gets(notes);//taking input


                for(i = 0; i < strlen(variable_name_Time); i++){
                    fprintf(open_schedule_file, "%c", variable_name_Time[i]+508);
                }
                for(i = 0; i < strlen(time); i++){
                    fprintf(open_schedule_file, "%c", time[i] + 508);//storing time using encryption
                }


                for(i = 0; i < strlen(variable_name_Person); i++){
                    fprintf(open_schedule_file, "%c", variable_name_Person[i]+508);
                }
                for(i = 0; i < strlen(person); i++){
                    fprintf(open_schedule_file, "%c", person[i] + 508);//storing person using encryption
                }


                for(i = 0; i < strlen(variable_name_Place); i++){
                    fprintf(open_schedule_file, "%c", variable_name_Place[i]+508);
                }
                for(i = 0; i < strlen(place); i++){
                    fprintf(open_schedule_file, "%c", place[i] + 508);//storing place using encryption
                }


                for(i = 0; i < strlen(variable_name_Duration); i++){
                    fprintf(open_schedule_file, "%c", variable_name_Duration[i]+508);
                }
                for(i = 0; i < strlen(duration); i++){
                    fprintf(open_schedule_file, "%c", duration[i] + 508);//storing duration using encryption
                }

                for(i = 0; i < strlen(variable_name_Notes); i++){
                fprintf(open_schedule_file, "%c", variable_name_Notes[i]+508);
                }
                for(i = 0; i < strlen(notes); i++){
                    fprintf(open_schedule_file, "%c", notes[i] + 508);//storing duration using encryption
                }


                for(i = 0; i < strlen(variable_name_New_Line); i++){
                    fprintf(open_schedule_file, "%c", variable_name_New_Line[i]+508);
                }

                printf("\n\tYour Schedule saved successfully.\n\tPress any key to continue..");
                getch();//any key signal
                fclose(open_schedule_file);//closing file
            }
        }
        else{
            printf("\n\n\tNew schedule add canceled...\n\tPress any key to continue...");
            getch();//any key signal
        }
    }
}

void VIEW_SCHEDULE(void)
{
    FILE *open_schedule_file;//declaring file pointer

    char date[200];//declaring date string
    char schedule_file_direction[1000];//file directory string
    char ch;//for printing character one by one

    int i;//for running loop

    system("cls");//clearing console

    printf("\n\tFor viewing your schedule, please enter the date(DD-MM-YYYY): ");
    gets(date);//taking input for date

    //making file directory
    strcpy(schedule_file_direction, current_directory);
    strcat(schedule_file_direction, "\\database\\daily_schedule\\");
    strcat(schedule_file_direction, date);

    open_schedule_file = fopen(schedule_file_direction, "r");//trying to opening file in reading file

    if(open_schedule_file == NULL){
        printf("\n\tIn the database, there is no schedule for this date.\n\tPress any key to continue...");
        getch();//any key signal
    }
    else{
        printf("\n\tSchedule for this date:\n");

        //printing every character one by one
        while(1){
            ch = fgetc(open_schedule_file);//scanning character one by one
            if(ch == EOF){
                break;//if end of file then break
            }
            else{
                printf("%c", ch-508);//printing in console character one by one by decrypting
            }
        }

        printf("\n\n\tPress any key to continue..");
        getch();//any key signal
        fclose(open_schedule_file);//closing file
    }
}

void EDIT_SCHEDULE(void)
{
    FILE *open_schedule_file;//declaring file pointer

    char date[100];//declaring date string
    char schedule_file_direction[1000];//file directory string
    char ch;//for printing character one by one and command

    char time[200];//declaring time string
    char person[200];//declaring person string
    char place[200];//declaring place string
    char duration[200];//declaring duration string
    char notes[1000];//declaring notes string

    char variable_name_Time[] = "\tTime: ";
    char variable_name_Person[] = "\n\tPerson: ";
    char variable_name_Place[] = "\n\tPlace: ";
    char variable_name_Duration[] = "\n\tDuration: ";
    char variable_name_Notes[] = "\n\tNotes: ";
    char variable_name_New_Line[] = "\n\n";

    int i;//for running loop

    system("cls");//clearing console

    printf("\n\tFor editing your schedule, please enter the date(DD-MM-YYYY): ");
    gets(date);//taking input for date

    //making file directory
    strcpy(schedule_file_direction, current_directory);
    strcat(schedule_file_direction, "\\database\\daily_schedule\\");
    strcat(schedule_file_direction, date);

    open_schedule_file = fopen(schedule_file_direction, "r");//trying to opening file in reading file

    if(open_schedule_file == NULL){
        printf("\n\tIn the database, there is no schedule for this date.\n\tPress any key to continue...");
        getch();//any key signal
    }
    else{
        printf("\n\tPrevious schedule for this date:\n");

        //printing every character one by one
        while(1){
            ch = fgetc(open_schedule_file);//scanning character one by one
            if(ch == EOF){
                break;//if end of file then break
            }
            else{
                printf("%c", ch-508);//printing in console character one by one by decrypting
            }
        }

        fclose(open_schedule_file);//closing file

        printf("\n\n\tNow Enter new schedule:\n");

        printf("\n\tEnter Time(HH:MM): ");
        gets(time);//taking input
        printf("\n\tEnter Person Name: ");
        gets(person);//taking input
        printf("\n\tEnter Place: ");
        gets(place);//taking input
        printf("\n\tEnter Duration: ");
        gets(duration);//taking input
        printf("\n\tEnter Short Notes: ");
        gets(notes);//taking input

        printf("\n\tAre you sure to edit this schedule?(Y/N): ");
        ch = getch();

        if(ch == 'Y' || ch == 'y'){
            IDENTITY_VERIFY();//calling function

            open_schedule_file = fopen(schedule_file_direction, "w");//opening file in writing mood

            if(open_schedule_file == NULL){
                printf("\n\tUnable to edit this schedule.\n\tPress any key to continue...");
                getch();//any key signal
            }
            else{
                for(i = 0; i < strlen(variable_name_Time); i++){
                    fprintf(open_schedule_file, "%c", variable_name_Time[i]+508);
                }
                for(i = 0; i < strlen(time); i++){
                    fprintf(open_schedule_file, "%c", time[i] + 508);//storing time using encryption
                }


                for(i = 0; i < strlen(variable_name_Person); i++){
                    fprintf(open_schedule_file, "%c", variable_name_Person[i]+508);
                }
                for(i = 0; i < strlen(person); i++){
                    fprintf(open_schedule_file, "%c", person[i] + 508);//storing person using encryption
                }


                for(i = 0; i < strlen(variable_name_Place); i++){
                    fprintf(open_schedule_file, "%c", variable_name_Place[i]+508);
                }
                for(i = 0; i < strlen(place); i++){
                    fprintf(open_schedule_file, "%c", place[i] + 508);//storing place using encryption
                }


                for(i = 0; i < strlen(variable_name_Duration); i++){
                    fprintf(open_schedule_file, "%c", variable_name_Duration[i]+508);
                }
                for(i = 0; i < strlen(duration); i++){
                    fprintf(open_schedule_file, "%c", duration[i] + 508);//storing duration using encryption
                }

                for(i = 0; i < strlen(variable_name_Notes); i++){
                fprintf(open_schedule_file, "%c", variable_name_Notes[i]+508);
                }
                for(i = 0; i < strlen(notes); i++){
                    fprintf(open_schedule_file, "%c", notes[i] + 508);//storing duration using encryption
                }


                for(i = 0; i < strlen(variable_name_New_Line); i++){
                    fprintf(open_schedule_file, "%c", variable_name_New_Line[i]+508);
                }

                printf("\n\tYour Schedule edited successfully.\n\tPress any key to continue..");
                getch();//any key signal
                fclose(open_schedule_file);//closing file
            }
        }
    }
}

void DELETE_SCHEDULE(void)
{
    FILE *open_schedule_file;//declaring file pointer

    char date[200];//declaring date string
    char schedule_file_direction[1000];//file directory string
    char ch;//for printing character one by one

    int i, status;//for running loop

    system("cls");//clearing console

    printf("\n\tFor viewing your schedule, please enter the date(DD-MM-YYYY): ");
    gets(date);//taking input for date

    //making file directory
    strcpy(schedule_file_direction, current_directory);
    strcat(schedule_file_direction, "\\database\\daily_schedule\\");
    strcat(schedule_file_direction, date);

    open_schedule_file = fopen(schedule_file_direction, "r");//trying to opening file in reading file

    if(open_schedule_file == NULL){
        printf("\n\tIn the database, there is no schedule for this date.\n\tPress any key to continue...");
        getch();//any key signal
    }
    else{
        printf("\n\tSchedule for this date:\n");

        //printing every character one by one
        while(1){
            ch = fgetc(open_schedule_file);//scanning character one by one
            if(ch == EOF){
                break;//if end of file then break
            }
            else{
                printf("%c", ch-508);//printing in console character one by one by decrypting
            }
        }

        fclose(open_schedule_file);//closing file

        printf("\n\n\tAre you sure you want to delete this Schedule? (Y/N): ");
        ch = getch();

        if(ch == 'Y' || ch == 'y'){

            IDENTITY_VERIFY();//calling function

            status = remove(schedule_file_direction);//removing file

            if(status == 0){//if status 0 then file remove successful
                printf("\n\tFile Deleted successfully..\n\tPress any key to continue...");
                getch();//any key signal
            }
            else{//if not then unable to delete
                printf("\n\tFile Delete failed..\n\tPress any key to try again...");
                getch();//any key signal
            }
        }
        else{
            printf("\n\tDelete canceled...\n\tPress any key to continue..");
            getch();//any key signal
        }
    }
}




void ADD_CLIENT_INFORMATION(void)
{
    FILE *open_client_info_file;//declaring file pointer

    char name[100];//string for name
    char profession[100];//string for profession
    char number[100];//string for number
    char email[200];//string for email
    char address_office[200];//string for office address
    char address_home[200];//string for home address
    char notes[1000];//for short notes

    char client_information_file_direction[1000];//file location directory

    int i;//for running loop

    system("cls");//clearing console

    printf("\n\tPlease enter your client Name: ");
    gets(name);//taking input for client name.. file will be saved by this name

    //creating directory for file
    strcpy(client_information_file_direction, current_directory);
    strcat(client_information_file_direction, "\\database\\client_information\\");
    strcat(client_information_file_direction, name);

    open_client_info_file = fopen(client_information_file_direction, "r");//trying to open file in reading mood

    if(open_client_info_file == NULL){//if can't open that means no file there by this name
        open_client_info_file = fopen(client_information_file_direction, "w");//opening file in writing mood

        if(open_client_info_file == NULL){//if can't open
            printf("\n\tUnable to create file...\n\tPlease try again...");
            getch();//any key signal
        }
        else{
            //taking input for all information
            printf("\n\tProfession: ");
            gets(profession);
            printf("\n\tPhone Number: ");
            gets(number);
            printf("\n\tE-Mail: ");
            gets(email);
            printf("\n\tOffice Address: ");
            gets(address_office);
            printf("\n\tHome Address: ");
            gets(address_home);
            printf("\n\tShort Notes: ");
            gets(notes);

            for(i = 0; i < strlen(profession); i++){
                fprintf(open_client_info_file, "%c", profession[i] + 508);//store with encryption
            }
            fprintf(open_client_info_file, "\n");//for new line in file

            for(i = 0; i < strlen(number); i++){
                fprintf(open_client_info_file, "%c", number[i] + 508);//store with encryption
            }
            fprintf(open_client_info_file, "\n");//for new line in file

            for(i = 0; i < strlen(email); i++){
                fprintf(open_client_info_file, "%c", email[i] + 508);//store with encryption
            }
            fprintf(open_client_info_file, "\n");//for new line in file

            for(i = 0; i < strlen(address_office); i++){
                fprintf(open_client_info_file, "%c", address_office[i] + 508);//store with encryption
            }
            fprintf(open_client_info_file, "\n");//for new line in file

            for(i = 0; i < strlen(address_home); i++){
                fprintf(open_client_info_file, "%c", address_home[i] + 508);//store with encryption
            }
            fprintf(open_client_info_file, "\n");//for new line in file

            for(i = 0; i < strlen(notes); i++){
                fprintf(open_client_info_file, "%c", notes[i] + 508);//store with encryption
            }

            fclose(open_client_info_file);//closing file

            printf("\n\tClient Information saved successfully.\n\tPress any key to continue....");
            getch();//any key signal
        }
    }
    else{
        printf("\n\tIt seems that you already have client information by this name.\n\tYou can't add two client information by the same name.\n\tPlease add a different name.\n\tPress any key to continue...");
        getch();
        fclose(open_client_info_file);//closing file
    }
}

void VIEW_CLIENT_INFORMATION(void)
{
    FILE *open_client_info_file;//declaring file pointer

    char name[100];//string for name
    char profession[200];//string for profession
    char number[200];//string for number
    char email[200];//string for email
    char address_office[200];//string for office address
    char address_home[200];//string for home address
    char notes[1000];//for short notes

    char client_information_file_direction[1000];//file location directory

    int i;//for running loop

    system("cls");//clearing console

    printf("\n\tFor viewing information, please enter your client name: ");
    gets(name);//taking input for client name.. file will be saved by this name

    //creating directory for file
    strcpy(client_information_file_direction, current_directory);
    strcat(client_information_file_direction, "\\database\\client_information\\");
    strcat(client_information_file_direction, name);

    open_client_info_file = fopen(client_information_file_direction, "r");//trying to open file in reading mood

    if(open_client_info_file == NULL){
        printf("\n\tIn the database, there is no client information by this name..\n\tPress any key to try again...");
        getch();//any key signal
    }
    else{
        fgets(profession, 200, open_client_info_file);//scanning string from file
        for(i = 0; i < strlen(profession); i++){
            profession[i] = profession[i] - 508;//decryption
        }
        profession[i-1] = '\0';//removing extra line from string

        fgets(number, 200, open_client_info_file);//scanning string from file
        for(i = 0; i < strlen(number); i++){
            number[i] = number[i] - 508;//decryption
        }
        number[i-1] = '\0';//removing extra line from string

        fgets(email, 200, open_client_info_file);//scanning string from file
        for(i = 0; i < strlen(email); i++){
            email[i] = email[i] - 508;//decryption
        }
        email[i-1] = '\0';//removing extra line from string

        fgets(address_office, 200, open_client_info_file);//scanning string from file
        for(i = 0; i < strlen(address_office); i++){
            address_office[i] = address_office[i] - 508;//decryption
        }
        address_office[i-1] = '\0';//removing extra line from string

        fgets(address_home, 200, open_client_info_file);//scanning string from file
        for(i = 0; i < strlen(address_home); i++){
            address_home[i] = address_home[i] - 508;//decryption
        }
        address_home[i-1] = '\0';//removing extra line from string

        fgets(notes, 200, open_client_info_file);//scanning string from file
        for(i = 0; i < strlen(notes); i++){
            notes[i] = notes[i] - 508;//decryption
        }

        printf("\n\tProfession: %s\n\tPhone Number: %s\n\tE-Mail: %s\n\tOffice Address: %s\n\tHome Address: %s\n\tShort Notes: %s\n\n\tPress any key to continue..", profession, number, email, address_office, address_home, notes);
        getch();//any key signal
        fclose(open_client_info_file);//closing file
    }
}

void EDIT_CLIENT_INFORMATION(void)
{
    FILE *open_client_info_file;//declaring file pointer

    char name[100];//string for name
    char profession[200];//string for profession
    char number[200];//string for number
    char email[200];//string for email
    char address_office[200];//string for office address
    char address_home[200];//string for home address
    char notes[1000];//for short notes

    char ch;//for command

    char client_information_file_direction[1000];//file location directory

    int i;//for running loop

    system("cls");//clearing console

    printf("\n\tFor viewing information, please enter your client name: ");
    gets(name);//taking input for client name.. file will be saved by this name

    //creating directory for file
    strcpy(client_information_file_direction, current_directory);
    strcat(client_information_file_direction, "\\database\\client_information\\");
    strcat(client_information_file_direction, name);

    open_client_info_file = fopen(client_information_file_direction, "r");//trying to open file in reading mood

    if(open_client_info_file == NULL){
        printf("\n\tIn the database, there is no client information by this name..\n\tPress any key to try again...");
        getch();//any key signal
    }
    else{
        fgets(profession, 200, open_client_info_file);//scanning string from file
        for(i = 0; i < strlen(profession); i++){
            profession[i] = profession[i] - 508;//decryption
        }
        profession[i-1] = '\0';//removing extra line from string

        fgets(number, 200, open_client_info_file);//scanning string from file
        for(i = 0; i < strlen(number); i++){
            number[i] = number[i] - 508;//decryption
        }
        number[i-1] = '\0';//removing extra line from string

        fgets(email, 200, open_client_info_file);//scanning string from file
        for(i = 0; i < strlen(email); i++){
            email[i] = email[i] - 508;//decryption
        }
        email[i-1] = '\0';//removing extra line from string

        fgets(address_office, 200, open_client_info_file);//scanning string from file
        for(i = 0; i < strlen(address_office); i++){
            address_office[i] = address_office[i] - 508;//decryption
        }
        address_office[i-1] = '\0';//removing extra line from string

        fgets(address_home, 200, open_client_info_file);//scanning string from file
        for(i = 0; i < strlen(address_home); i++){
            address_home[i] = address_home[i] - 508;//decryption
        }
        address_home[i-1] = '\0';//removing extra line from string

        fgets(notes, 200, open_client_info_file);//scanning string from file
        for(i = 0; i < strlen(notes); i++){
            notes[i] = notes[i] - 508;//decryption
        }

        fclose(open_client_info_file);//closing file

        printf("\n\tProfession: %s\n\tPhone Number: %s\n\tE-Mail: %s\n\tOffice Address: %s\n\tHome Address: %s\n\tShort Notes: %s\n\n\tWhich information do you want to edit?\n\t=> 1. Profession\n\t=> 2. Number\n\t=> 3. E-Mail\n\t=> 4. Office Address\n\t=> 5. Home Address\n\t=> 6. Short Notes\n\t=> 7. Whole Information\n\t=> 8. Cancel\n\n\tEnter Command: ", profession, number, email, address_office, address_home, notes);
        ch = getch();

        if(ch == '1'){
            printf("\n\tEnter Profession: ");
            gets(profession);//taking input
        }
        else if(ch == '2'){
            printf("\n\tEnter Phone Number: ");
            gets(number);//taking input
        }
        else if(ch == '3'){
            printf("\n\tEnter E-Mail: ");
            gets(email);//taking input
        }
        else if(ch == '4'){
            printf("\n\tEnter Office Address: ");
            gets(address_office);//taking input
        }
        else if(ch == '5'){
            printf("\n\tEnter Home Address: ");
            gets(address_home);//taking input
        }
        else if(ch == '6'){
            printf("\n\tEnter Short Notes: ");
            gets(notes);//taking input
        }
        else if(ch == '7'){
            printf("\n\tProfession: ");
            gets(profession);//taking input
            printf("\n\tPhone Number: ");
            gets(number);//taking input
            printf("\n\tE-Mail: ");
            gets(email);//taking input
            printf("\n\tOffice Address: ");
            gets(address_office);//taking input
            printf("\n\tHome Address: ");
            gets(address_home);//taking input
            printf("\n\tShort Notes: ");
            gets(notes);//taking input
        }
        else{
            printf("\n\tEdit canceled....\n\tPress any key to continue...");
            getch();//any key signal
        }

        if(ch >= '1' && ch <= '7'){//if input a valid command then file will be edit

            printf("\n\tAre you sure to edit this information?(Y/N): ");
            ch = getch();

            if(ch == 'Y' || ch == 'y'){
                IDENTITY_VERIFY();

                open_client_info_file = fopen(client_information_file_direction, "w");//opening file in writing mood

                if(open_client_info_file == NULL){
                    printf("\n\tUnable to edit information.... Please try again...");
                    getch();//any key signal
                }

                else{
                    for(i = 0; i < strlen(profession); i++){
                        fprintf(open_client_info_file, "%c", profession[i] + 508);//store with encryption
                    }
                    fprintf(open_client_info_file, "\n");//for new line in file

                    for(i = 0; i < strlen(number); i++){
                        fprintf(open_client_info_file, "%c", number[i] + 508);//store with encryption
                    }
                    fprintf(open_client_info_file, "\n");//for new line in file

                    for(i = 0; i < strlen(email); i++){
                        fprintf(open_client_info_file, "%c", email[i] + 508);//store with encryption
                    }
                    fprintf(open_client_info_file, "\n");//for new line in file

                    for(i = 0; i < strlen(address_office); i++){
                        fprintf(open_client_info_file, "%c", address_office[i] + 508);//store with encryption
                    }
                    fprintf(open_client_info_file, "\n");//for new line in file

                    for(i = 0; i < strlen(address_home); i++){
                        fprintf(open_client_info_file, "%c", address_home[i] + 508);//store with encryption
                    }
                    fprintf(open_client_info_file, "\n");//for new line in file

                    for(i = 0; i < strlen(notes); i++){
                        fprintf(open_client_info_file, "%c", notes[i] + 508);//store with encryption
                    }

                    fclose(open_client_info_file);//closing file

                    printf("\n\tEdited Successfully..\n\tPress any key to continue...");
                    getch();//any key signal
                }
            }
            else{
                printf("\n\tEdit canceled....\n\tPress any key to continue...");
                getch();//any key signal
            }
        }
    }
}

void DELETE_CLIENT_INFORMATION(void)
{
    FILE *open_client_info_file;//declaring file pointer

    char name[100];//string for name
    char profession[200];//string for profession
    char number[200];//string for number
    char email[200];//string for email
    char address_office[200];//string for office address
    char address_home[200];//string for home address
    char notes[1000];//for short notes

    char ch;//for command

    char client_information_file_direction[1000];//file location directory

    int i, status;//for running loop and delete status

    system("cls");//clearing console

    printf("\n\tFor deleting information, please enter your client name: ");
    gets(name);//taking input for client name.. file will be saved by this name

    //creating directory for file
    strcpy(client_information_file_direction, current_directory);
    strcat(client_information_file_direction, "\\database\\client_information\\");
    strcat(client_information_file_direction, name);

    open_client_info_file = fopen(client_information_file_direction, "r");//trying to open file in reading mood

    if(open_client_info_file == NULL){
        printf("\n\tIn the database, there is no client information by this name..\n\tPress any key to try again...");
        getch();//any key signal
    }
    else{
        fgets(profession, 200, open_client_info_file);//scanning string from file
        for(i = 0; i < strlen(profession); i++){
            profession[i] = profession[i] - 508;//decryption
        }
        profession[i-1] = '\0';//removing extra line from string

        fgets(number, 200, open_client_info_file);//scanning string from file
        for(i = 0; i < strlen(number); i++){
            number[i] = number[i] - 508;//decryption
        }
        number[i-1] = '\0';//removing extra line from string

        fgets(email, 200, open_client_info_file);//scanning string from file
        for(i = 0; i < strlen(email); i++){
            email[i] = email[i] - 508;//decryption
        }
        email[i-1] = '\0';//removing extra line from string

        fgets(address_office, 200, open_client_info_file);//scanning string from file
        for(i = 0; i < strlen(address_office); i++){
            address_office[i] = address_office[i] - 508;//decryption
        }
        address_office[i-1] = '\0';//removing extra line from string

        fgets(address_home, 200, open_client_info_file);//scanning string from file
        for(i = 0; i < strlen(address_home); i++){
            address_home[i] = address_home[i] - 508;//decryption
        }
        address_home[i-1] = '\0';//removing extra line from string

        fgets(notes, 200, open_client_info_file);//scanning string from file
        for(i = 0; i < strlen(notes); i++){
            notes[i] = notes[i] - 508;//decryption
        }

        fclose(open_client_info_file);//closing file
        printf("\n\tProfession: %s\n\tPhone Number: %s\n\tE-Mail: %s\n\tOffice Address: %s\n\tHome Address: %s\n\tShort Notes: %s\n\n\tAre you sure to delete this client information?(Y/N): ", profession, number, email, address_office, address_home, notes);
        ch = getch();

        if(ch == 'Y' || ch == 'y'){
            IDENTITY_VERIFY();//calling function

            status = remove(client_information_file_direction);//deleting file

            if(status == 0){
                printf("\n\tClient information deleted successfully..\n\tPress any key to continue..");
                getch();//any key signal
            }
            else{
                printf("\n\tClient information deletion failed...\n\tPress any key to continue...");
                getch();//any key signal
            }
        }
        else{
            printf("\n\tDelete canceled...\n\tPress any key to continue...");
            getch();//any key signal
        }
    }
}





void ABOUT(void)
{
    system("cls");

    WELCOME_SCREEN();

    printf("\n\n\tVersion: 01.04\n\tLast Updated: 24.04.2022\n\n\tPowered by SfM1");
    printf("\n\n\tTeam: TUF CODER\n\n\tTeam Members:");
    printf("\n\tJoy Kumar Ghosh\n\tID: 2211424 6 42");
    printf("\n\n\tKazi Abid Shahoriar\n\tID: 2211967 0 42");
    printf("\n\n\tJannatul Mawa Tahi\n\tID: 2212096 0 42");
    printf("\n\n\tFarhana Rahman Risha\n\tID: 2211598 6 42");
    printf("\n\n\tKhandaker Anjuman Parvez\n\tID: 2212536 0 42");

    getch();

    EXIT_SCREEN();
}

void WELCOME_SCREEN(void)
{
printf("\t    __________________   __________________");
printf("\n\t.-/|                  \\ /                  |\\-.");
printf("\n\t||||                   |                   ||||");
printf("\n\t||||   Welcome to      |                   ||||");
printf("\n\t||||                   |                   ||||");
printf("\n\t||||Password Protected |                   ||||");
printf("\n\t||||                   |     V. 01.04      ||||");
printf("\n\t||||  Personal Diary   |  Powered by SfM1  ||||");
printf("\n\t||||                   |                   ||||");
printf("\n\t||||  with Encryption  |                   ||||");
printf("\n\t||||                   |                   ||||");
printf("\n\t||||                   |                   ||||");
printf("\n\t||||__________________ | __________________||||");
printf("\n\t||/===================\\|/===================\\||");
printf("\n\t`--------------------~___~-------------------''");
}

void HEADER_SCREEN(char menu_msg[])
{
    int lenght_menu_msg = strlen(menu_msg), i, j;

    printf("\n\n\t");

    for(i = 0; i <= (45-lenght_menu_msg-2)/2; i++){
        printf("\xB2");
    }

    printf(" %s ", menu_msg);

    for(j = 0; j <= (44-lenght_menu_msg-i); j++){
        printf("\xB2");
    }
    printf("\n");
}

void EXIT_SCREEN(void)
{
    system("cls");

    printf("\n\t   _       .-\"--._");
    printf("\n\t  / \\     /   ____\\");
    printf("\n\t  ||\\\\   /  /`(");
    printf("\n\t  || \\\\ _| '``'-.");
    printf("\n\t  | \\_\\\\ `      9\\              ,");
    printf("\n\t   \\_      9    _ '-.=      .--'|}");
    printf("\n\t    |  _        \\)   |     /    /}}");
    printf("\n\t     \\/   = \\   ;_.'/    .=\\.--'`\\}");
    printf("\n\t     |       `-`__.;---.//` '---./'");
    printf("\n\t      '.___..-'`        `|   ___   _ _   ___   _  _   _  _");
    printf("\n\t       _/        __.-.__/   |_ _| | | | / _ \\ | \\| | | |/ /");
    printf("\n\t    .-'       .-'   |||      | |  |   | |   | |  ` | |   <");
    printf("\n\t .-/         /      |\\\\      |_|  |_|_| |_|_| |_|\\_| |_|\\_\\");
    printf("\n\t{  |        /_     /  \\|           _ _   ___   _ _");
    printf("\n\t `-\\          `\\--;`              | | | /   \\ | | |");
    printf("\n\t    '-.         |  |              \\   / | | | | | |");
    printf("\n\t       )       / _/                |_|  \\___/ \\___/");
    printf("\n\t      /    __.'  '--.");
    printf("\n\t     (      '--. ___)))");
    printf("\n\t      `-..____)))");
    printf("\n\n\t\t\t\t\tFOR USING OUR SOFTWARE\n\n\n");
    getch();
}
