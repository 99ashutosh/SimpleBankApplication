typedef struct{
    char *userName;
    char *password;
    char *email;
    char *mobile_no;
    char *accNo;
    char *IFSCcode;
    float balance;
    char *upiId;
    int upiPass;
    char *last_login;
} customer;

//Encrypt Decrypt functions
void encrypt(char *a);
void decrypt(char *a);

//Bank Management Functions
int get_user_index(char user[]);
void getFile(customer c[]);
int login(char username[50], char password[50]);
void signup(const char *username, const char *password, const char *number, const char *email);
int upi_transfer(int user_index, int upi_passcode, float amount);
int set_upi_pass(int pass);

//Greet Functions
int greet_main();


//Dashboard Functions
int dashboard_main(int index, int argc, char *argv[]);