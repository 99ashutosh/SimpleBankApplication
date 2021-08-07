#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "bank.h"

typedef struct file_structure {
    int acc_id;
    char *name;
    char *password;
    int number;
    float balance;
    char *email;
    char *upi_handler;
    int upi_pass;
} csv_data;

csv_data *data;
FILE *fp;
int user_location = 0;

int get_rows(){
    FILE* stream = fopen("data.csv", "r");
    if (stream == NULL){
        return 0;
    }
    int no_of_rows = 0;
    char line[1024];
    while (fgets(line, 1024, stream)){
        no_of_rows++;
    }
    fclose(stream);
    return no_of_rows;
}

int get_acc_id(){
    return get_rows()-1;
}

int init(){
    int rows = get_rows();
    char buffer[1024];
    char *tmp;
    data = malloc(rows * sizeof *data);
    fp = fopen("test.csv", "r");
    if (fp == NULL){
        printf("Cannot open file");
        return 0;
    }
    int i = 0;
    while (fgets(buffer, 1024, fp) != NULL){
        if ((strlen(buffer)>0) && (buffer[strlen (buffer) - 1] == '\n'))
            buffer[strlen (buffer) - 1] = '\0';
        
        tmp = strtok(buffer, ",");
        data[i].name = (char*)malloc(sizeof(char*));
        strcpy(data[i].name,tmp);

        tmp = strtok(NULL, ",");
        data[i].password = (char*)malloc(sizeof(char*));
        strcpy(data[i].password,tmp);

        tmp = strtok(NULL, ",");
        data[i].number=atoi(tmp);

        tmp = strtok(NULL, ",");
        data[i].balance=atof(tmp);

        tmp = strtok(NULL, ",");
        data[i].email = (char*)malloc(sizeof(char*));
        strcpy(data[i].email,tmp);

        tmp = strtok(NULL, ",");
        data[i].upi_handler = (char*)malloc(sizeof(char*));
        strcpy(data[i].upi_handler,tmp);

        tmp = strtok(NULL, ",");
        data[i].upi_pass=atoi(tmp);

        i++;
    }
    fclose(fp);
    return 0;
}

int find(char *username){
    for (int i = 1; i<=get_rows(); i++){
        if (data[i].name == username){
			return 1;
		}
    }
	return 0;
}

int login(char *username, char *password){
	for (int i = 1; i<=get_rows(); i++){
		if (data[i].name == username && data[i].password == password){
            user_location = i;
            return 1;
        } else if (data[i].name == username && data[i].password != password)
            return 2;
        else
            return 3;
    }
}

int create_new_account(char *username, char *password, int number, char *email){
    data[get_rows()+1].acc_id = get_acc_id();
    data[get_rows()+1].name = username;
    data[get_rows()+1].password = password;
    data[get_rows()+1].number = number;
    data[get_rows()+1].balance = 0;
    data[get_rows()+1].email = email;
    data[get_rows()+1].upi_handler = "Not Set";
    data[get_rows()+1].upi_pass = 0;

    data = realloc(data, get_rows() * sizeof *data);

}

int flush(){
    fp = fopen("data2.csv", "w");
    if (fp == NULL){
        printf("Cannot open file");
        return 0;
    }
    fprintf(fp, "Name,Password,Number,Balance,Email,UPI Handler,UPI Passcode\n");
    for (int i = 1; i<=get_rows(); i++){
        fprintf(fp, "%s,%s,%d,%d,%s,%s,%d\n", data[i].name, data[i].password, data[i].number, data[i].balance, data[i].email, data[i].upi_handler, data[i].upi_pass);
		}
    fclose(fp);
    free(data);
}

void gen_upi_handler(char handler[], int passcode){
    char *buffer;
    snprintf(buffer, 40, "%s@pesu", handler);
    data[user_location].upi_handler = buffer;
    data[user_location].upi_pass = passcode;
}