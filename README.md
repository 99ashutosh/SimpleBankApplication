## File structure for Project

`glade/`: Contains all the .glade files

`src/`: Contains `.c` and `.h` files

`Makefile`: Use with `mingw32-make` **Not Complete**

## Files in glade (will change later)

`greet.glade`: Has the final version of the login/create an account GUI.

`dashboard.glade`: **MAY** add the dashboard here, or may combine it with `greet_final.glade`.

## Files in src (can change later)

`main.c`: will have the `gtk_main()`

`bank.h`: header file

`encryptdecrypt.c`: will have Clouds's function for encrypting and decrypting data.

`check_user.c`: will have the final code for checking the user's inputs during login/signup part.

`file_operations.c`: will have all functions to read/write to `.csv` files.

`bank_main.c`: will have all the functions to deal with account transactions and other related activities.

## Some important references
- GTK+: https://developer.gnome.org/gtk3/stable/
- Glade interface: https://developer.gnome.org/gladeui/stable/
- Examples and tutorials: https://prognotes.net/gtk-glade-c-programming/
