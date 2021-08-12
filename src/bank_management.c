#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "bank.h"

extern int user_index;

customer s[100];

char file[] = "..\\data\\user_data.csv";
int size = 0;

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
            while (value){
                strcpy(s[i].userName,value);
                value = strtok(NULL, ",");
                strcpy(s[i].password,value);
                value = strtok(NULL, ",");
                strcpy(s[i].mobile_no, value);
                value = strtok(NULL, ",");
                strcpy(s[i].accNo,value);
                value = strtok(NULL, ",");
                s[i].IFSCcode = "PESU0002001";
                value = strtok(NULL, ",");
                s[i].balance = strtof(value,NULL);
                value = strtok(NULL, ",");
                strcpy(s[i].email, value);
                value = strtok(NULL, ",");
                strcpy(s[i].upiId,value);
                value = strtok(NULL, ",");
                s[i].upiPass = atoi(value);
                value = strtok(NULL, ",");
                strcpy(s[i].last_login,value);
                value = strtok(NULL, ",");
                i++;
            }
        }
        fclose(fp);
    }
    size=i;
}

void putFile(customer c[]){
    FILE* fp = fopen(file, "w");
    int i=0;
    fputs("Username,Password,MobNo,AccountID,IFSC,Balance,Email,UPI_ID,UPI_passcode,Logout_time\n",fp);
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
        fputs(s[i].email,fp);
        fputc(',',fp);
        fputs(s[i].upiId,fp);
        fputc(',',fp);
        sprintf(text, "%d", s[i].upiPass); 
        fputs(text,fp);
        sprintf(text, "%.2f", s[i].last_login);
        fputs(text,fp);
        fputc(',',fp);
        fputs("\n",fp);
        i++;
    }
    fclose(fp);
}

int get_user_index(char user[]){
    for(int i=0;i<size;i++){
        if(!strcmp(s[i].userName,user))
            user_index = i;
            return i;
    }
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

int set_upi_pass(int pass){
    if(pass>=100000 && pass<=999999){
        s[user_index].upiPass = pass;
        return 1;
    } else {
        return 2;
    }
}

int deposit(int user_index, float cash){
    s[user_index].balance += cash;
    putFile(s);
}

int withdraw(int user_index, float amount){
    s[user_index].balance -= amount;
    putFile(s);
    return 1;
}

float get_balance(int user_index){
    return s[user_index].balance;
}
/*
int upi_transfer(int user_index, int upi_passcode, float amount){
    char reciever[15], reci[15];
    int i, checkpass, u, flag = 0;
    if (s[user_index].upiPass == upi_passcode){
        u = i;
        return 1; //PAss case
    } else {
        return 2; //Fail case

    }
xyz:
    scanf("%s", &reciever);
    float cash;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(s[i].upiId, reciever) == '0' || strcmp(s[i].upiId, reciever) == 0)
        {
            s[u].balance -= amount;
            s[i].balance += amount;
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
*/
void signup(const char *username, const char *password, const char *number, const char *email){
    size++;
    int i = size - 1;
    char mob_no[15];
    strcpy(s[i].userName, username);
    strcpy(s[i].password, password);
    strcpy(s[i].mobile_no, number);
    accGenerator(s[i].accNo);
    s[i].balance = 0;
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
