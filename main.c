#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void intro() {
    printf("Welcome to \n");
    printf("                                                                                         _\n");       
    printf("  __   _  _   _ _   _ _   ___   _ _    __   _  _     __   ___   _ _   __ __  ___   _ _  | |_   ___   _ _  \n");
    printf(" / _| | || | | '_| | '_| / -_) | ' \\  / _| | || |   / _| / _ \\ | ' \\  \\ V / / -_) | '_| |  _| / -_) | '_| \n");
    printf(" \\__|  \\_,_| |_|   |_|   \\___| |_||_| \\__|  \\_, |   \\__| \\___/ |_||_|  \\_/  \\___| |_|    \\__| \\___| |_|   \n");
    printf("                                            |__/\n\n");
    printf("* All conversion rates are accurate as of Feb 2022.\n\n");
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
    else if (strcmp(*from, "Castar") == 0) {
        return amt * 1.332;
    }
    else if (strcmp(*from, "Imperial Credit") == 0) {
        return amt * 0.714;
    }
    else if (strcmp(*from, "Gold") == 0) {
        return amt * 3.333;
    }
    else if (strcmp(*from, "Rupee") == 0) {
        return amt * 0.833;
    }
    else if (strcmp(*from, "Latinum") == 0) {
        return amt * 0.01;
    }
    else if (strcmp(*from, "Gil") == 0) {
        return amt * 0.097;
    }
    else if (strcmp(*from, "Coin") == 0) {
        return amt * 0.357;
    }
    else if (strcmp(*from, "Ring") == 0) {
        return amt * 0.1923;
    }
    else if (strcmp(*from, "Solari") == 0) {
        return amt * 0.002;
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
    else if (strcmp(*to, "Castar") == 0) {
        return amt / 0.75;
    }
    else if (strcmp(*to, "Imperial Credit") == 0) {
        return amt / 1.4;
    }
    else if (strcmp(*to, "Gold") == 0) {
        return amt / 0.3;
    }
    else if (strcmp(*to, "Rupee") == 0) {
        return amt / 1.2;
    }
    else if (strcmp(*to, "Latinum") == 0) {
        return amt / 100;
    }
    else if (strcmp(*to, "Gil") == 0) {
        return amt / 10.3;
    }
    else if (strcmp(*to, "Coin") == 0) {
        return amt / 2.8;
    }
    else if (strcmp(*to, "Ring") == 0) {
        return amt / 5.2;
    }
    else if (strcmp(*to, "Solari") == 0) {
        return amt / 500;
    }
    else return 0;
}

void print_result(char **from, char **to, double amt1, double amt2) {
    printf("%.2f %s = %.2f %s\n\n", amt1, *from, amt2, *to);
}

void convert_file() {
    FILE * data;
    data = fopen("data.txt", "r");
    FILE * converted_data;
    converted_data = fopen("converted_data.txt", "w");

    double amt1, amt2;
    char *from = (char*)malloc(5*sizeof(char));
    char *to = (char*)malloc(5*sizeof(char));

        fscanf(data, "%s %s %lf", from, to, &amt1);
        amt2 = convert_curr(&to,convert_usd(&from,amt1));
        fprintf(converted_data, "%.2f %s = %.2f %s\n", amt1, from, amt2, to);
    
    fclose(data);
    fclose(converted_data);
    free(from);
    free(to);
}

void request() {
    FILE * rng;
    int num;
    rng = fopen("ui.txt", "w");
    fputs("get", rng);
    fclose(rng);
}

void randomnum() {
    FILE * rng;
    double num = 0.0;
    int val = 0;
    rng = fopen("ui.txt", "r");
    fscanf(rng, "%lf", &num);

    val = (int)num;
    switch (val%6) {
        case 0:
            printf("1 USD = 1.38 AUD\n");
            break;
        case 1:
            printf("1 USD = 0.75 GBP\n");
            break;
        case 2:
            printf("1 USD = 0.89 EUR\n");
            break;
        case 3:
            printf("1 USD = 114.91 JPY\n");
            break;
        case 4:
            printf("1 USD = 0.92 CHF\n");
            break;
        case 5:
            printf("1 USD = 1.27 CAD\n");
            break;
        default:
            printf("error\n");
            break;
    }
    fclose(rng);
    //printf("num = %lf, val = %d\n", num, val);
}

int main(int argc, char const *argv[]) {
    char *from, *to;
    double amt1, amt2;
    int input = 0;
    int x = atoi(argv[1]);

    if (x == 0) {
        while (input != 3) {
            printf("Please choose a mode:\n[0] Program description and documentation\n[1] Normal conversion mode\n[2] Show me a random conversion rate \n[3] Quit\n");
            scanf("%d", &input);

            if (input == 0) {
                printf("This program converts amounts of currency.\n");
                printf("[1] Normal conversion mode: This mode lets you enter in the currencies to convert between and the amount of currency to be converted.\n");
                printf("[2] Random conversion rate: This mode simply shows you a conversion rate between two random currencies.\n");
                printf("[3] Quit the program.\n");
                printf("\nAny questions? Please email maomal@oregonstate.edu.\n\n");
            }

            // 1 = normal conversion mode
            if (input == 1) {
                intro();
                get_all(&from, &to, &amt1);
                amt2 = convert_curr(&to, convert_usd(&from, amt1));
                
                print_result(&from, &to, amt1, amt2);
                free(from);
                free(to);
            }

            // 2 = random rate
            else if (input == 2) {
                //printf("Requesting a number from the random number generator...\n");
                request();
                sleep(2);
                printf("Random conversion rate: ");
                randomnum();
            }

            else if (input == 3) {
                // quit
            }
        }
    }
    else if (x == 1) {
        //printf("'converted_data.txt' will now be overwritten.\n...\n");
        while (1) {
            sleep(1);
            convert_file();
        }
        //printf("Your file has been converted.\n\n");
    }
}