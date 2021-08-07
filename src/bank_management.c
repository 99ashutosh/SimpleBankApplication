#include <stdio.h>
#include <string.h>
extern int user_index;
char file[] = "..\\data\\user_data.csv"

extern struct customer s[100];

int getFile(){
    FILE* fp = fopen(file, "r");
    int i=0;
    if (!fp)
        return 3;
    else 
    {
        char buffer[256];
        int row = 0,column=0;
        while (fgets(buffer,256, fp)) 
        {
            column = 0;
            row++;
            if (row == 1)continue;
  
            char* value = strtok(buffer, ",");
  
            while (value) 
            {
                strcpy(s[i].userName,value);
                value = strtok(NULL, ",");
                strcpy(s[i].password,value);
                value = strtok(NULL, ",");
                strcpy(s[i].mobile_no, value);
                value = strtok(NULL, ",");
                strcpy(s[i].accNo,value);
                value = strtok(NULL, ",");
                strcpy(s[i].IFSCcode,value);
                value = strtok(NULL, ",");
                s[i].balance = strtof(value,NULL);
                value = strtok(NULL, ",");
                strcpy(s[i].upiId,value);
                value = strtok(NULL, ",");
                s[i].upiPass = atoi(value);
                value = strtok(NULL, ",");
                i++;
            }
        }
        fclose(fp);
    }
    size=i;
}

void putFile(struct customer c[]){
    FILE* fp = fopen(file, "w");
    int i=0;
    fputs("Username,Password,MobNo,AccountID,IFSC,Balance,UPI_ID,UPI_passcode\n",fp);
    while(i<size)
    {
        fputs(s[i].userName,fp);
        fputc(',',fp);
        fputs(s[i].password,fp);
        fputc(',',fp);
        fputs(s[i].mobile_no, fp);
        fputc(',', fp);
        fputs(s[i].accNo,fp);
        fputc(',',fp);
        fputs(s[i].IFSCcode,fp);
        fputc(',',fp);
        char text[20];
        sprintf(text, "%.2f", s[i].balance); 
        fputs(text,fp);
        fputc(',',fp);
        fputs(s[i].upiId,fp);
        fputc(',',fp);
        sprintf(text, "%d", s[i].upiPass); 
        fputs(text,fp);
        fputs("\n",fp);
        i++;
    }
    fclose(fp);
}

int get_user_index(){

}
void accGenerator(char *s){
    srand(time(0));
    char str[17]="";
    for(int i=0;i<16;i++)
    {
        int n = rand()%10;
        char ch = '0'+n;
        str[i]=ch;
    }
    strcpy(s,str);
}	

int check_user(char user[]){
    for(int i=0;i<size;i++){
        if(!strcmp(s[i].userName,user))
            return 1;
        return 0;
    }
}

int set_upi_pass(int pass)
    s[i].upiPass = pass;
    if(s[i].upiPass>=100000 && s[i].upiPass<=999999){
        return 2;
    }
}

int deposit(char *user, float cash;){
    getFile(s);
    for(int i=0;i<size;i++)
    {
        if (strcmp(s[i].userName, user) == '0' || strcmp(s[i].userName, user) == 0) {
            s[i].balance += cash;
            return 1;
        }
        else {
            return 2;
        }
    }
    putFile(s);
}

void withdraw(char* user){
    float cash;
    printf("\nEnter the cash to be withdrawn: ");
    scanf("%f", &cash);
    getFile(s);
    for (int i = 0; i < size; i++)
    {
        if (strcmp(s[i].userName, user) == '0' || strcmp(s[i].userName, user) == 0)
            s[i].balance -= cash;

    }
    putFile(s);
    printf("Withdraw successfull\n");
}

float balance(char* user){
    for (int i = 0; i < size; i++){
        if (strcmp(s[i].userName, user) == '0' || strcmp(s[i].userName, user) == 0)
            return s[i].balance;
    }
    return -1;
}

void transfer(char* user)
{
    char reciever[15], reci[15];
    int i, checkpass, u, flag = 0;
    printf("\nEnter your UPIpass to continue: ");
abc:
    scanf("%d", &checkpass);
    getFile(s);
    for (i = 0; i < size; i++)
    {
        if (strcmp(s[i].userName, user) == '0' || strcmp(s[i].userName, user) == 0)
        {
            if (s[i].upiPass == checkpass)
            {
                printf("UPIpass matched\n");
                u = i;
            }
            else
            {
                printf("Wrong UPIpass,try again\n");
                goto abc;
            }
        }
    }
    printf("Enter a reciever UPIid\n");
xyz:
    scanf("%s", &reciever);
    getFile(s);
    float cash;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(s[i].upiId, reciever) == '0' || strcmp(s[i].upiId, reciever) == 0)
        {
            printf("Enter the amount of cash to be transferred: ");
            scanf("%f", &cash);
            s[u].balance -= cash;
            s[i].balance += cash;
            flag = 1;
            putFile(s);
        }
    }
    if (flag != 1)
    {
        printf("Enter the correct reciever upiID! ");
        goto xyz;
    }
    printf("Money transfer successfull!\n");
}

void signup(char username, char password, char number, char email){
    size++;
    int i = size - 1;
    char mob_no[15];
    strcpy(s[i].userName, username);
    strcpy(s[i].password, password);
    strcpy(s[i].mobile_no, number);
    accGenerator(s[i].accNo);
    s[i].balance = 0;
    s[i].IFSC = "PESU0002001";
    strcpy(mob_no, s[i].mobile_no);
    strcat(mob_no, "@pesu");
    strcpy(s[i].upiId, mob_no);
    s[i].upiPass = 0;
}

int login_checker(char username[], char pass[]){
    for (int i = 0; i < size; i++){
        if (strcmp(s[i].userName, username) == '0' || strcmp(s[i].userName, username) == 0) {
            char p[50];
            strcpy(p, s[i].password);
            //decrypt(p);
            strcpy(pass, p);
            return 1;
        }
    }
    return 0;
}

int login(char username[50], char password[50]){
    char pass[50];
    if (!login_checker(username, pass))
        return 1;
    if (strcmp(pass, password) == '0' || strcmp(pass, password) == 0)
        return 0;
    else {
        return 2;
    }
}
