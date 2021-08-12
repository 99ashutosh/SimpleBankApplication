#ifndef BANK
#define BANK

typedef struct{
    char *userName;
    char password[40];
    char email[100];
    char mobile_no[11];
    char accNo[40];//16bits long
    char *IFSCcode;
    float balance;
    char upiId[40];//10bits long
    int upiPass;//6digits
    char *last_login;
} customer;

//Encrypt Decrypt functions
void encrypt(char *a);
void decrypt(char *a);

//Bank Management Functions
int get_user_index(char user[]);
int getFile();
int login(char username[50], char password[50]);
void signup(const char *username, const char *password, const char *number, const char *email);
int upi_transfer(int user_index, int upi_passcode, float amount);
int set_upi_pass(int pass);

//Greet Functions
int greet_main();


//Dashboard Functions
int dashboard_main(int index, int argc, char *argv[]);
#endif