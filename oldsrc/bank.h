// csv_db functions
int init();
int find(char *username);
int login(char *username, char *password);
int create_new_account(char *username, char *password, int number, char *email);
int flush();
void gen_upi_handler(char handler[], int passcode);
