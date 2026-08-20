/*For each of the items, a corresponding function should be implemented and used. Except for scanf and printf, you are not allowed to use any other function that is available in any library. But you can use the functions that you have implemented or any auxiliary functions you implemented. For all functions that you are going to implement that correspond to particular items, no printing should be done. All inputs and outputs should be done in the main function.

Input:

The first line of input is the number of test cases. Each test case is composed of sets of inputs. The first one is a positive integer indicating what item is to be performed. This is then followed by the necessary inputs for that particular item. The necessary inputs are described below.

Items 1, 14, and 20 - an integer
Items 2 and 3 - a double value
Items 4 to 10 - a character
Items 11 to 13 and  18 to 19 - an array of characters ( a string)
Items 15 and 17 - 2 arrays of characters (2 strings)
For all string inputs, assume that they will not contain any spaces. Also assume that all string inputs will not exceed 50 characters.

Output:

Check the descriptions of outputs below:

Computes the log of an integer input base 10. The answer is the integer part only. e.g. n = 1000, answer is 3. n = 850, answer is 2. n = 1000000, answer is 6. n = 123456, answer is 5.
Computes the floor of a double input. e.g. n = 12, answer is 12. n = 12.3, answer is 12. n = 12.9, answer is 12.
Computes the ceiling of a double input. e.g. n = 12, answer is 12. n = 12.3, answer is 13. n = 12.9, answer is 13.
Determines if a character input is alphanumeric ('0'-'9' or 'a'-'z' or 'A'-'Z'), or not. Display either YES or NO.
Determines if a character input is a letter from the English Alphabet ('a'-'z' or 'A'-'Z'), or not. Display either YES or NO.
Determines if a character input is an upper case letter ('A'-'Z'), or not. Display either YES or NO.
Determines if a character input is a lower case letter ('a'-'z'), or not. Display either YES or NO.
Gives the uppercase equivalent of a character input if it is a lower case letter. Otherwise, it simply gives the same input character. Display the character.
Gives the lowercase equivalent of a character input if it is an upper case letter. Otherwise, it simply gives the same input character. Display the character.
Determines if a character input is a punctuation mark (only for this purpose, we will consider the period, question mark, exclamation point, comma, semicolon, and colon as punctuation marks).
Gives the integer equivalent of the string input. Assume that the input string is in correct integer format. Display the integer.
Gives the double equivalent of the string input. Assume that the input string is in correct double format. Assume the string input has 4 characters at most after a dot (.), if there's any. Display the double value with a precision of 4 digits after the dot (.).
Determines if a string input is in correct float format or not. Display either YES or NO. Some samples: "1.5678", answer is YES. "24", answer is YES. "0.5678", answer is YES.  "1.25.78", answer is NO.
Gives the absolute value of an integer input. Display the absolute value.
Copies the contents of a source string input to a destination string (second argument for the function). Display the destination string as output. To be able to check whether this is done correctly or not, the destination string is the second input string.
Determines if the first string input is a substring of the second string input. Display YES if it is, NO otherwise. Again, printing should be done in the main function and not inside the substring function you are to implement.
Determines if the first and second string inputs the same string or not. If they are, display YES. If they are not, it further determines if the first string input comes before or after the second string input in terms of alphabetic ordering (based on ASCII code). Assuming s1 is the first string input and s2 is the second string input: e.g. s1 = "hello", s2 = "world", display BEFORE. s1 = "universe", s2 = "galaxy", display AFTER. s1 = "Zebra", s2 = "apple", display BEFORE.
Converts the string input to "camel case" (our definition of camel case: wE aSsUmE tHaT tHe FiRsT cHaRaCtEr Of ThE sTrInG iS aLwAyS iN lOwEr CaSe). e.g. "HELLO", answer is "hElLo". Assume that st has letters only. Display the answer.
Reverses the string input st. e.g. "wonder", answer is "rednow". Display the answer.
Reverses the integer input. The use of strings in this function is not allowed. Again, the input here is an integer. e.g. n = 102, answer is 201. n = 5300, answer is 35.
*/

#include <stdio.h>

int num1(int);
int num2(double);
int num3(double);
int num4(char);
int num5(char);
int num6(char);
int num7(char);
int num8(char);
int num9(char);
int num10(char);
int num11(char[]);
double num12(char[]);
int num13(char[]);
int num14(int);
void num15(char[], char[]);
int num16(char[], char[]);
int num17(char[], char[]);
void num18(char[]);
void num19(char[]);
int num20(int);


int alphabet(char);
int uppercase(char);
int lowercase(char);
int lengthcounter(char[]);
int strtoint(char[]);

int main(){
    int tests, casenum = 0;

    scanf("%d", &tests);
    for (int i = 1; i <= tests; i++){
        scanf("%d ", &casenum);
        if (casenum == 1 || casenum == 14 || casenum == 20){
            int inum;
            scanf("%d", &inum);

            if (casenum == 1)
                printf("%d", num1(inum));
            else if (casenum == 14)
                printf("%d", num14(inum));
            else if (casenum == 20)
                printf("%d", num20(inum));

        } else if (casenum == 2 || casenum == 3){
            double dnum;
            scanf("%lf", &dnum);

            if (casenum == 2)
                printf("%d", num2(dnum));
            else if (casenum == 3)
                printf("%d", num3(dnum));

        } else if (casenum == 4 || casenum == 5 || casenum == 6 || casenum == 7 || casenum == 8 || casenum == 9 || casenum == 10){
            char letter;
            scanf("%c", &letter);

            if (casenum == 4){
                if (num4(letter))
                    printf("YES");
                else
                    printf("NO");
            } else if (casenum == 5){
                if (num5(letter))
                    printf("YES");
                else
                    printf("NO");
            } else if (casenum == 6){
                if (num6(letter))
                    printf("YES");
                else
                    printf("NO");
            } else if (casenum == 7){
                if (num7(letter))
                    printf("YES");
                else
                    printf("NO");
            } else if (casenum == 8){
                printf("%c", num8(letter));
            } else if (casenum == 9){
                printf("%c", num9(letter));
            } else if (casenum == 10){
                if (num10(letter))
                    printf("YES");
                else
                    printf("NO");
            }

        } else if (casenum == 11 || casenum == 12 || casenum == 13 || casenum == 18 || casenum == 19){
            char strings[50];
            scanf("%s", strings);

            if (casenum == 11)
                printf("%d", num11(strings));
            else if (casenum == 12)
                printf("%.4lf", num12(strings));
            else if (casenum == 13)
                if (num13(strings))
                    printf("YES");
                else
                    printf("NO");
            else if (casenum == 18){
                num18(strings);
                printf("%s", strings);
            } else if (casenum == 19){
                num19(strings);
                printf("%s", strings);
            }

        } else if (casenum == 15 || casenum == 16 || casenum == 17){
            char str1[50], str2[50];
            scanf("%s %s", str1, str2);

            if (casenum == 15){
                num15(str1, str2);
                printf("%s", str2);
            } else if (casenum == 16){
                if (num16(str1, str2))
                    printf("YES");
                else
                    printf("NO");
            } else if (casenum == 17){
                if (num17(str1, str2) == 1)
                    printf("AFTER");
                else if (num17(str1, str2) == 0)
                    printf("YES");
                else if (num17(str1, str2) == -1)
                    printf("BEFORE");
            }

        }

        printf("\n");
    }

}

int num1(int n){
    int ctr = 0;
    while (n>=10){
        n = n/10;
        ctr+=1;
    }

    return ctr;
}

int num2(double n){
    int final = (int)n;

    if (n < 0 && final != n)
        return final - 1;
    return final;
}

int num3(double n){
    int final = (int)n;

    if (n > 0 && final != n)
        return final + 1;
    return final;
}

int num4(char n){
    if ((n >= '0' && n <= '9') || alphabet(n))
        return 1;
    return 0;
}

int num5(char n){
    return alphabet(n);
}

int num6(char n){
    return uppercase(n);
}

int num7(char n){
    return lowercase(n);
}

int num8(char n){
    if (lowercase(n))
        return n - 32;
    return n;
}

int num9(char n){
    if (uppercase(n))
        return n + 32;
    return n;
}

int num10(char n){
    char symbols[6] = {'.', '?', '!', ',', ';', ':'};

    for (int i = 0; i < 6; i++){
        if (n == symbols[i])
            return 1;
    }
    return 0;
}

int num11(char n[]){
    return strtoint(n);
}

double num12(char n[]){
    char wholenum[47];
    char decimal[5];
    int i = 0;
    int j = 0;
    int sign = 1;

    if (n[i] == '-'){
        sign = -1;
        i = 1;
    }

    while (n[i] != '.'  && n[i] != '\0'){
        wholenum[j] = n[i];
        i++;
        j++;
    }
    wholenum[j] = '\0';

    if (n[i] != '.')
        return sign * strtoint(wholenum);

    i += 1;
    j = 0;
    while (n[i] != '\0'){
        decimal[j] = n[i];
        i++;
        j++;
    }
    decimal[j] = '\0';

    int whole = strtoint(wholenum);
    int deci = strtoint(decimal);
    double divisor = 1;

    i = 0;
    while (decimal[i] != '\0'){
        divisor = divisor * 10;
        i++;
    }

    double final = sign * (whole + (deci / divisor));

    return final;
}

int num13(char n[]){
    int dot = 0;
    for (int i = 0; n[i] != '\0'; i++){
        if (n[i] == '.'){
            dot++;
        } else if (i == 0 && n[i] == '-'){
            continue;
        } else if (n[i] < '0' || n[i] > '9'){
            return 0;
        }
    }

    if (dot > 1)
        return 0;

    return 1;
}

int num14(int n){
    if (n < 0)
        return -n;
    return n;
}

void num15(char first[], char second[]){
    int i = 0;
    while (first[i] != '\0'){
        second[i] = first[i];
        i++;
    }
    second[i] = '\0';
}

int num16(char first[], char second[]){
    int checker;
    int lenfirst = lengthcounter(first), lensecond = lengthcounter(second);
    int limit = lensecond - lenfirst;

    for (int i = 0; i <= limit; i++){
        checker = 1;
        for (int j = 0; j < lenfirst; j++){
            if (first[j] != second[i+j]){
                checker = 0;
                break;
            }
        }
        if (checker)
            return checker;
    }

    return 0;
}

int num17(char first[], char second[]){
    int checker = 0, i;

    for (i = 0; first[i] != '\0' && second[i] != '\0'; i++){
        if (first[i] < second[i]){
            checker = -1;
            return checker;
        } else if (first[i] > second[i]){
            checker = 1;
            return checker;
        }
    }

    if (first[i] == '\0' && second[i] != '\0'){
        checker = -1;
    } else if (first[i] != '\0' && second[i] == '\0'){
        checker = 1;
    }

    return checker;
}


void num18(char n[]){
    if (uppercase(n[0]))
        n[0] = n[0] + 32;
    for (int i = 1; n[i] != '\0'; i++){
        if (i % 2 == 1){
            if (lowercase(n[i]))
                n[i] = n[i] - 32;
        } else if (i % 2 == 0){
            if (uppercase(n[i]))
                n[i] = n[i] + 32;
        }
    }
}

void num19(char n[]){
    int first = 0;
    int last = lengthcounter(n) - 1;
    char temp;

    while (first < last){
        temp = n[first];
        n[first] = n[last];
        n[last] = temp;

        first++;
        last--;
    }
}

int num20(int n){
    if (n == 0)
        return 0;
    int reversed = 0;
    int sign = 1;
    if (n < 0){
        sign = -1;
        n = num14(n);
    }
    while (n>0){
        reversed = reversed * 10 + (n % 10);
        n = n/10;
    }
    return reversed * sign;
}

int alphabet(char n){
    if (uppercase(n) || lowercase(n))
        return 1;
    return 0;
}

int uppercase(char n){
    if (n >= 'A' && n <= 'Z')
        return 1;
    return 0;
}

int lowercase(char n){
    if (n >= 'a' && n <= 'z')
        return 1;
    return 0;
}

int lengthcounter(char n[]){
    int ctr = 0;

    while(n[ctr] != '\0')
        ctr++;

    return ctr;
}

int strtoint(char n[]){
    int intvalue = 0, i = 0, sign = 1;

    if (n[i] == '-'){
        sign = -1;
        i = 1;
    }
    for (i; n[i] != '\0'; i++){
        intvalue = intvalue * 10 + (n[i] - '0');
    }

    return sign * intvalue;
}
