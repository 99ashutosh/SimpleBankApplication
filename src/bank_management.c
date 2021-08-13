#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "bank.h"

struct customer s[100];
char file[] = "../data/user_data.csv";
int size = 0;

void getFile(){
    FILE* fp = fopen(file, "r");
    int i=0;
    if (!fp){
        printf("File is empty!!\n");
    } else {
        char buffer[256];
        int row = 0,column=0;
        while (fgets(buffer,256, fp)){
            column = 0;
            row++;
            if (row == 1)continue;
            char* value = strtok(buffer, ",");
            while (value){
                strcpy(s[i].userName,value);
                value = strtok(NULL, ",");
                strcpy(s[i].password,value);
                value = strtok(NULL, ",");
                strcpy(s[i].mob_no,value);
                value = strtok(NULL, ",");
                strcpy(s[i].accNo,value);
                value = strtok(NULL, ",");
                strcpy(s[i].IFSCcode,value);
                value = strtok(NULL, ",");
                s[i].balance = strtof(value,NULL);
                value = strtok(NULL, ",");
                strcpy(s[i].email,value);
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

void putFile(){
    FILE* fp = fopen(file, "w");
    int i=0;
    fputs("Username,Password,MobNo,AccountID,IFSC,Balance,Email,UPI_ID,UPI_passcode,Logout_time\n",fp);
    while(i<size)
    {
        fputs(s[i].userName,fp);
        fputc(',',fp);
        fputs(s[i].password,fp);
        fputc(',',fp);
        fputs(s[i].mob_no, fp);
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

int set_upi_pass(int user_index, int pass){
    s[user_index].upiPass = pass;
    putFile();
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

//TODO: UPI Transfer missing

void signup(char username[32], char password[50], char number[10], char email[100]){
    size++;
    int i = size-1;
    char mob_no[10];
    strcpy(s[i].userName, username);
    strcpy(s[i].password, password);
    strcpy(s[i].mob_no, number);
    strcpy(s[i].email, email);
    accGenerator(s[i].accNo);
    s[i].balance = 0;
    strcpy(mob_no, s[i].mob_no);
    strcat(mob_no, "@pesu");
    printf("%s", mob_no);
    strcpy(s[i].upiId, mob_no);
    s[i].upiPass = 0;
    putFile();
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

int find_user(char username[]){
    for (int i = 0; i < size; i++){
        if (strcmp(s[i].userName, username) == '0' || strcmp(s[i].userName, username) == 0) {
            return 1;
        }
    }
    return 0;
}