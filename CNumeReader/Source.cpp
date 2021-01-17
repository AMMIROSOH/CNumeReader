#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>
void Analyze(int input);
void Print(int triple, int index, bool least_zero);

int main() {
    int input;
    scanf("%d", &input);
    Analyze(input);
    printf("\n");

    return 0;
}
void Analyze(int input) {
    int digits = floor(log10(input)) + 1;
    int instant = input;
    int triple, first_tri = 0, triple_index;
    int r = digits % 3;
    bool least_zero = false;

    //see if number is round
    if (r == 0) {
        triple_index = (digits - r) / 3;
    }
    else {
        triple_index = (digits - r) / 3 + 1;
    }
    for (int m = 1;m <= 9;m++) {
        int num = 0;
        for (int n = 1;n <= 9;n++) {
            num = n * pow(10, m);
            if (input == num) {
                least_zero = true;
            }
        }
    }
    //this take first triple from left
    if (r == 0) {
        r = 3;
    }
    for (int n = 0; n < r; n++) {
        int x = instant / int(pow(10, digits - n - 1));
        first_tri += x * int(pow(10, r - n)) / 10;
        instant = instant - x * pow(10, digits - n - 1);

    }
    Print(first_tri, triple_index, least_zero);
    triple_index--;

    int ndigits = floor(log10(instant)) + 1;
    for (int i = 1;i <= 3 || instant != 0;i++) {
        if (triple_index >= 1) {
            triple = (instant - instant % int(pow(10, 3 * (triple_index - 1)))) / int(pow(10, 3 * (triple_index - 1)));
            instant = instant - triple * int(pow(10, 3 * (triple_index - 1)));
            Print(triple, triple_index, least_zero);
            triple_index--;
        }
    }
}

void Print(int triple, int index, bool least_zero) {
    if (triple == 0) { return; }
    int digits = floor(log10(triple)) + 1;

    //Defining names of the numbers
            //1 - 20
    char num_1_20[20][10] = { "yek", "do", "se", "char" , "panj" , "shesh" , "haft" , "hasht" , "noh" , "dah", "yazdah"
        , "davazdah" , "sizdah" , "chardah" , "panzdah" , "shanzdah" , "hefdah" , "hejdah" , "noozdah" , "bist" };
    //10 - 90
    char num_10_90[9][10] = { "dah", "bist", "si", "chehel", "panjah", "shast", "haftad", "hashtad", "navad" };
    //100 - 900
    char num_100_900[9][10] = { "sad", "devist", "sisad", "charsad", "pansad", "sheshsad", "haftsad", "hashtsad", "nohsad" };
    //1000, 1000000, 1000000000
    char num_1000[3][10] = { "hezar", "milioon", "milyard" };

    //Here i figure 1 - 20
    if (triple <= 20) {
        printf("%s ", num_1_20[triple - 1]);
        if (index != 1) {
            printf("%s ", num_1000[index - 2]);
        }
        if (not least_zero && index != 1) {
            printf("o ");
        }
    }

    //Here i figure 30 - 90
    else if (triple == 30 || triple == 40 || triple == 50 || triple == 60 || triple == 70 || triple == 80 || triple == 90) {
        printf("%s ", num_10_90[triple / 10 - 1]);
        if (index != 1) {
            printf("%s ", num_1000[index - 2]);
        }
        if (not least_zero && index != 1) {
            printf("o ");
        }
    }

    //Here i figure 21 - 99 instead ten Multiplications
    else if (triple <= 99) {
        int one_mul = triple % 10;
        int ten_mul = (triple - one_mul) / 10;
        printf("%s o %s ", num_10_90[ten_mul - 1], num_1_20[one_mul - 1]);
        if (index != 1) {
            printf("%s ", num_1000[index - 2]);
        }
        if (not least_zero && index != 1) {
            printf("o ");
        }
    }

    //Here i figure 100 - 900
    else if (triple == 100 || triple == 200 || triple == 300 || triple == 400 || triple == 500 || triple == 600 || triple == 700 ||
        triple == 800 || triple == 900) {
        printf("%s ", num_100_900[triple / 100 - 1]);
        if (index != 1) {
            printf("%s ", num_1000[index - 2]);
        }
        if (not least_zero && index != 1) {
            printf("o ");
        }
    }

    //Here i figure 101 - 999 instead hundred Multiplications
    else if (triple <= 999) {
        int one_mul = triple % 10;
        int ten_mul = (triple % 100 - one_mul) / 10;
        int hundred_mul = (triple - one_mul - ten_mul * 10) / 100;

        printf("%s o %s o %s ", num_100_900[hundred_mul - 1], num_10_90[ten_mul - 1], num_1_20[one_mul - 1]);

        if (index != 1) {
            printf("%s ", num_1000[index - 2]);
        }
        if (not least_zero && index != 1) {
            printf("o ");
        }
    }
}