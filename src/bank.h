struct customer {
    char userName[40];
    char password[40];
    char mob_no[11];
    char accNo[40];//16bits long
    char IFSCcode[40];//10bits long
    float balance;
    char email[50];
    char upiId[40];//10bits long
    int upiPass;//6digits
    char last_login[50];
};

//Bank Management Functions
void getFile();
void putFile();
int get_user_index(char user[]);
int find_user(char username[]);
void signup(char username[40], char password[40], char number[10], char email[100]);
int login(char username[50], char password[50]);
int set_upi_pass(int user_index, int pass);

//Greet Functions
int greet_main();


//Dashboard Functions
int dashboard_main(int index, int argc, char *argv[]);