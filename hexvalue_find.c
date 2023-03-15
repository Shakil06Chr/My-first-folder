#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file = fopen("C:\\Users\\USER\\Desktop\\test\\tt.jpg", "rb"); // replace "filename.txt" with the name of your file
    if (file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char hex[999999]; // create a string to store the hexadecimal values
    int i = 0, ch;
    while ((ch = fgetc(file)) != EOF) {
        sprintf(&hex[i], "%02X", ch); // convert the character to its hexadecimal value and store it in the string
        i += 2; // increment the index by 2 to move to the next position in the string
    }
    hex[i] = '\0'; // terminate the string with a null character

    printf("%s\n", hex); // print the string of hexadecimal values
    fclose(file); // close the file

    return 0;
}
