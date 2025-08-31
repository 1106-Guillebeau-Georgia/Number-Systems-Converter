//Author: Georgia Guillebeau
//01.09.2025
//Purpose: Convert integers into other bases

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define MAX_STR 100

//Function Prototypes
int dectobin(int num, int binary_array[], int mode);
int dectohex(int num, char hex_num[], int mode);
int dectooct(int num, int oct_array[], int mode);
void print_clear(int array[], char array_1[], int mode, char type_of);

int main(){
    char from_array[MAX_STR];
    char to_array[MAX_STR];
    int number;
    int binary[50], oct[50];
    char hex[50], answer;
    bool cont = true;
    printf("Convert any integer to Decimal (D), Hexadecimal (H), Octal (O), or Binary (B)! \n");
    do{
        printf("\nWhat base would you like to convert from? ");
        scanf("%s", from_array);
        printf("What base would you like to convert to? ");
        scanf("%s", to_array);
        if(from_array[0] == 'D' || from_array[0] == 'd'){
            printf("What decimal number would you like to convert: ");
            scanf("%d", &number);
            if(to_array[0] == 'B' || to_array[0] == 'b'){
                dectobin(number, binary, 1);
                printf("\n%d in binary is: ", number);
                print_clear(binary, hex, 2, 'I'); //Passing hex just as a place holder
                printf("\n");
            }
            else if(to_array[0] == 'H' || to_array[0] == 'h'){
                dectohex(number, hex, 1);
                printf("\n%d in hexadecimal is: ", number);
                print_clear(binary, hex, 2, 'C'); //Passing binary just as a placeholder 
                printf("\n");
            }
            else if(to_array[0] == 'O' || to_array[0] == 'o'){
                dectooct(number, oct, 2);
                printf("\n%d in octal is: ", number);
                print_clear(oct, hex, 2, 'I'); //Passing binary just as a placeholder 
                printf("\n");
            }
        }
        else if(from_array[0] == 'H' || from_array[0] == 'h'){
            printf("What hexidecimal number would you like to convert: ");
            scanf("%s", hex);
            if(to_array[0] == 'D' || to_array[0] == 'd'){
                number = dectohex(0, hex, 2);
                printf("\n");
                print_clear(binary, hex, 2, 'C'); 
                printf(" in decimal is: %d ", number);
                printf("\n");
            }
            else if(to_array[0] == 'B' || to_array[0] == 'b'){
                number = dectohex(0, hex, 2); //Passing 0 as a placeholder
                printf("%d", number);
                dectobin(number, binary, 1);
                printf("\n");
                print_clear(binary, hex, 2, 'C'); //Passing binary as a placeholder
                printf(" in binary is: ");
                print_clear(binary, hex, 2, 'I'); //Passing hex just as a place holder
                printf("\n");
            }
            else if(to_array[0] == 'O' || to_array[0] == 'o'){
                number = dectohex(0, hex, 2);
                dectooct(number, oct, 1);
                printf("\n");
                print_clear(binary, hex, 2, 'I'); //Passing hex as a placeholder
                printf(" in octal is: ");
                print_clear(binary, hex, 2, 'I'); //Passing binary just as a placeholder 
                printf("\n");
            }

        }
        else if(from_array[0] == 'B' || from_array[0] == 'b'){
            printf("What binary number would you like to convert: ");
            scanf("%d", &number);
            if(to_array[0] == 'D' || to_array[0] == 'd'){
                int decimal = dectobin(number, binary, 2); //Passing binary as a placeholder
                printf("\n%d in decimal is: %d ", number, decimal);
                printf("\n");
            }
            else if(to_array[0] == 'H' || to_array[0] == 'H'){
                int num = dectobin(number, binary, 2);
                dectohex(num, hex, 1);
                printf("\n%d in hexadecimal is: ", number);
                print_clear(binary, hex, 2, 'C'); //Passing binary as a placeholder
                printf("\n");
            }
            else if(to_array[0] == 'O' || to_array[0] == 'o'){
                int num = dectobin(number, binary, 2);
                dectooct(num, oct, 1);
                printf("\n%d in octal is: ", number);
                print_clear(oct, hex, 2, 'I'); //Passing hex as a placeholder
                printf("\n");
            }
        }
        else if(from_array[0] == 'O' || from_array[0] == 'o'){
            printf("What octal number would you like to convert: ");
            scanf("%d", &number);
            if(to_array[0] == 'D' || to_array[0] == 'd'){
                int num = dectooct(number, oct, 2);
                printf("\n%d in decimal is: %d", number, num);
                printf("\n");
            }
            else if(to_array[0] == 'B' || to_array[0] == 'B'){
                int num = dectooct(number, oct, 2);
                dectobin(num, binary, 1);
                printf("\n%d in binary is: ", number);
                print_clear(binary, hex, 2, 'I'); //Passing hex as a placeholder 
                printf("\n");
            }
            else if(to_array[0] == 'H' || to_array[0] == 'H'){
                int num = dectooct(number, oct, 2);
                dectohex(num, hex, 1);
                printf("\n%d in hexadecimal is: ", number);
                print_clear(oct, hex, 2, 'C'); //Passing octal as a placeholder
                printf("\n");
            }
        }
        printf("\nWould you like to continue converting? (Y or N): ");
        scanf(" %c", &answer);
        if(answer == 'N' || answer == 'n'){
            cont = false;
        }
    }while(cont);
    return 0;
}

int dectobin(int num, int binary_array[], int mode){ //Mode 1 converts from dec to bin, Mode 2 converts from bin to dec
    int temp_array[50];
    int remainder = 0, length = 0, i = 0;
    char holder_array[50]; //Using this as a placeholder array for print_clear function
    print_clear(temp_array, holder_array, 1, 'I'); 
    print_clear(binary_array, holder_array, 1, 'I');
    if(mode == 1){
        if(num == 0){
            binary_array[0] = 0;
            return 0;
        }
        else{
            while(num != 0){
                remainder = num % 2;
                if(remainder != 0){
                    temp_array[i] = 1;
                    i++;
                }
                else{
                    temp_array[i] = 0;
                    i++;
                }
                num = num / 2;
            }
            for(int j = 0; j < 50; j++){
                if(temp_array[j] == 0 || temp_array[j] == 1){
                    length++;
                }
            }
            for(int k = 0 ; k < 50; k++){
                binary_array[50 - 1 - k] = temp_array[k];
            }
            return 0;
        }
    }
    else if(mode == 2){ //This works :)
        int decimal_num = 0, exponent = 0;
        while(num > 0){
            remainder = num % 10;
            if(remainder != 0){
                decimal_num += pow(2, exponent);
            }
            exponent++;
            num = num/10;
        }
        return decimal_num;
    }  
    return 0;
}

int dectohex(int num, char hex_num[], int mode){ //This works :)
    if(mode == 1){
        int remainder = 0, index = 0, length = 0;
        int holder_array[50]; //Using this as a placeholder array for print_clear function
        char temp_array[50];
        print_clear(holder_array, hex_num, 1, 'C');
        if(num == 0){
            hex_num[0] = '0';
            return 0;
        }
        else{
            while(num > 0){
                remainder = num % 16;
                if(remainder < 10){
                    switch(remainder){
                        case 0:
                            temp_array[index] = '0';
                            break;
                        case 1:
                            temp_array[index] = '1';
                            break;
                        case 2:
                            temp_array[index] = '2';
                            break;
                        case 3:
                            temp_array[index] = '3';
                            break;
                        case 4:
                            temp_array[index] = '4';
                            break;
                        case 5:
                            temp_array[index] = '5';
                            break;
                        case 6:
                            temp_array[index] = '6';
                            break;
                        case 7:
                            temp_array[index] = '7';
                            break;
                        case 8:
                            temp_array[index] = '8';
                            break;
                        case 9:
                            temp_array[index] = '9';
                            break;
                        default:
                            break;
                    }
                }
                else if(remainder >= 10){
                    switch(remainder){
                        case 10:
                            temp_array[index] = 'a';
                            break;
                        case 11:
                            temp_array[index] = 'b';
                            break;
                        case 12:
                            temp_array[index] = 'c';
                            break;
                        case 13:
                            temp_array[index] = 'd';
                            break;
                        case 14:
                            temp_array[index] = 'e';
                            break;
                        case 15:
                            temp_array[index] = 'f';
                            break;
                        default:
                            break;
                    }
                }
                num = num / 16;
                index++;
                length++;
            }
            for(int i = 0; i < length; i++){
                hex_num[length - 1 - i] = temp_array[i];
            }
            return 0;
        }
    }
    else if(mode == 2){
        int index = 0, decimal_num = 0;
        int length = strlen(hex_num) - 1;
        for(index = 0; hex_num[index] != '\0'; index++){
            char current = hex_num[index];
            switch(current){
                case '0':
                    decimal_num += 0 * pow(16, length);
                    break;
                case '1':
                    decimal_num += 1 * pow(16, length);
                    break;
                case '2':
                    decimal_num += 2 * pow(16, length);
                    break;
                case '3':
                    decimal_num += 3 * pow(16, length);
                    break;
                case '4':
                    decimal_num += 4 * pow(16, length);
                    break;
                case '5':
                    decimal_num += 5 * pow(16, length);
                    break;
                case '6':
                    decimal_num += 6 * pow(16, length);
                    break;
                case '7':
                    decimal_num += 7 * pow(16, length);
                    break;
                case '8':
                    decimal_num += 8 * pow(16, length);
                    break;
                case '9':
                    decimal_num += 9 * pow(16, length);
                    break;
                case 'a':
                    decimal_num += 10 * pow(16, length);
                    break;
                case 'b':
                    decimal_num += 11 * pow(16, length);
                    break;
                case 'c':
                    decimal_num += 12 * pow(16, length);
                    break;
                case 'd':
                    decimal_num += 13 * pow(16, length);
                    break;
                case 'e':
                    decimal_num += 14 * pow(16, length);
                    break;
                case 'f':
                    decimal_num += 15 * pow(16, length);
                    break;    
                default:
                    break;        
            }
            length--;
        }
        return decimal_num;
    }   
    return 0;
}

int dectooct(int num, int oct_array[], int mode){
    int temp_array[50], remainder = 0, length = 0, index = 0;
    char holder_array[50]; //Will pass this as a placeholder for print_clear function
    print_clear(temp_array, holder_array, 1, 'I'); 
    if(mode == 1){
        print_clear(oct_array, holder_array, 1, 'I');
        if(num == 0){
            oct_array[0] = 0;
        }
        else{
            while(num > 0){
                remainder = num % 8;
                temp_array[index] = remainder;
                length++;
                index++;
                num = num / 8;
            }   
        }
        for(index = 0; index < length; index++){
            oct_array[length - 1 - index] = temp_array[index];
        }
        return 0;
    }
    else if(mode == 2){
        int decimal_num = 0, exponent = 0;
        while(num > 0){
            decimal_num += (num % 10) * pow(8, exponent);
            exponent++;
            num = num / 10;
        }
        return decimal_num;
    }
    return 0;
}

void print_clear(int array[], char array_1[], int mode, char type_of){ //Mode 1 to clear, mode 2 to print, C for character array, I for integer array
    int i = 0; 
    if(type_of == 'I'){
        if(mode == 1){
            for(i = 0; i < 50; i++){
                array[i] = ' ';
            }
        }
        else{
            for(i = 0; i < 50; i++){
                if(array[i] != ' '){
                    printf("%d", array[i]);
                }
            }
        }
    }    
    else if(type_of == 'C'){
        if(mode == 1){
            for(i = 0; i < 50; i++){
                array_1[i] = ' ';
            }
        }
        else{
            for(i = 0; i < 50; i++){
                printf("%c", array_1[i]);
            }
        }
    }
}