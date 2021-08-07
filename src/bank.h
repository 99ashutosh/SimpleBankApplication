#ifndef BANK
#define BANK

struct customer {
    char userName[40];
    char password[40];
    char email[100];
    char mobile_no[11];
    char accNo[40];//16bits long
    char IFSC[12]="PESU0002001";
    float balance;
    char upiId[40];//10bits long
    int upiPass;//6digits
    char last_login;
}s[100];

int user_index = 0;

//Encrypt Decrypt functions
void encrypt(char *a);
void decrypt(char *a);

//Bank Management Functions
int getFile();
int login(char username[50], char password[50]);
void signup(char username, char password, char number, char email);

//Greet Functions
int greet_main();


//Dashboard Functions
int dashboard_main(int index, int argc, char *argv[]);
#endif