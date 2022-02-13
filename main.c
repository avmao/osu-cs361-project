#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void intro() {
    printf("Welcome to \n");
    printf("                                                                                         _\n");       
    printf("  __   _  _   _ _   _ _   ___   _ _    __   _  _     __   ___   _ _   __ __  ___   _ _  | |_   ___   _ _  \n");
    printf(" / _| | || | | '_| | '_| / -_) | ' \\  / _| | || |   / _| / _ \\ | ' \\  \\ V / / -_) | '_| |  _| / -_) | '_| \n");
    printf(" \\__|  \\_,_| |_|   |_|   \\___| |_||_| \\__|  \\_, |   \\__| \\___/ |_||_|  \\_/  \\___| |_|    \\__| \\___| |_|   \n");
    printf("                                            |__/\n\n");
    printf("* All conversion rates are accurate as of Feb 2022.\n");
}

void get_input(char *input) {
    scanf("%s", input);
    if (strcmp(input, "AUD") == 0) {}
    else if (strcmp(input, "GBP") == 0) {}
    else if (strcmp(input, "EUR") == 0) {}
    else if (strcmp(input, "JPY") == 0) {}
    else if (strcmp(input, "CHF") == 0) {}
    else if (strcmp(input, "USD") == 0) {}
    else if (strcmp(input, "CAD") == 0) {}
    else { 
        printf("Invalid currency. Please try again\n");
        get_input(input);
    }
    return;
}

void get_all(char **from, char **to, double* amt) {
    char *input = (char*)malloc(16*sizeof(char));
    char *input2 = (char*)malloc(16*sizeof(char));

    printf("Please choose the currency you would like to convert from.\n[AUD, GBP, EUR, JPY, CHF, USD, CAD] ");
    get_input(input);
    *from = input;

    printf("Please choose the currency you would like to convert to.\n[AUD, GBP, EUR, JPY, CHF, USD, CAD] ");
    get_input(input2);
    *to = input2;

    printf("Please enter the amount of currency you would like to convert: ");
    scanf("%lf", amt);
}

double convert_usd(char **from, double amt) {
    if (strcmp(*from, "AUD") == 0) {
        return amt * 0.71841;
    }
    else if (strcmp(*from, "GBP") == 0) {
        return amt * 1.35604;
    }
    else if (strcmp(*from, "EUR") == 0) {
        return amt * 1.14336;
    }
    else if (strcmp(*from, "JPY") == 0) {
        return amt * 0.00863;
    }
    else if (strcmp(*from, "CHF") == 0) {
        return amt * 1.08136;
    }
    else if (strcmp(*from, "USD") == 0) {
        return amt * 1;
    }
    else if (strcmp(*from, "CAD") == 0) {
        return amt * 0.78837;
    }
    else return 0;
}

double convert_curr(char **to, double amt) {
    if (strcmp(*to, "AUD") == 0) {
        return amt / 0.71841;
    }
    else if (strcmp(*to, "GBP") == 0) {
        return amt / 1.35604;
    }
    else if (strcmp(*to, "EUR") == 0) {
        return amt / 1.14336;
    }
    else if (strcmp(*to, "JPY") == 0) {
        return amt / 0.00863;
    }
    else if (strcmp(*to, "CHF") == 0) {
        return amt / 1.08136;
    }
    else if (strcmp(*to, "USD") == 0) {
        return amt / 1;
    }
    else if (strcmp(*to, "CAD") == 0) {
        return amt / 0.78837;
    }
    else return 0;
}

void print_result(char **from, char **to, double amt1, double amt2) {
    printf("%.2f %s = %.2f %s\n", amt1, *from, amt2, *to);
}

void convert_file() {
    FILE * data;
    data = fopen("data.txt", "r");
    FILE * converted_data;
    converted_data = fopen("converted_data.txt", "w");

    double amt1, amt2;
    char *from = (char*)malloc(5*sizeof(char));
    char *to = (char*)malloc(5*sizeof(char));

    do {
        fscanf(data, "%s %s %lf", from, to, &amt1);
        amt2 = convert_curr(&to,convert_usd(&from,amt1));
        fprintf(converted_data, "%.2f %s = %.2f %s\n", amt1, from, amt2, to);
    } while (fgetc(data) != EOF);
    fclose(data);
    fclose(converted_data);
    free(from);
    free(to);
}

int main(int argc, char const *argv[]) {
    char *from, *to;
    double amt1, amt2;
    int input;

    printf("Please choose a mode:\n[0] Normal conversion mode\n[1] File conversion mode\n[2] Show me a random conversion rate \n[3] Quit\n");
    scanf("%d", &input);

    // 0 = normal conversion mode
    if (input == 0) {
        intro();
        while(1) {
            get_all(&from, &to, &amt1);
            amt2 = convert_curr(&to, convert_usd(&from, amt1));
            
            print_result(&from, &to, amt1, amt2);
            free(from);
            free(to);
        }
    }
    // 1 = file input mode
    else if (input == 1) {
        convert_file();
        printf("Your file has been converted.\n");
    }

    else if (input == 2) {
        printf("Requesting a number from the random number generator...\n");
        printf("Random conversion rate: 1 CAD = 0.79 USD\n");
    }

    else {
        printf("An error has occurred. Terminating program...\n");
    }

}