#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))

#include <string.h>
#include <stdio.h>

#include "roman_converter.h"
#include "roman_numeral_pair.h"

void convert_to_roman(unsigned int value, char *result) {
    struct RomanNumeralPair *pairs[13];
    pairs[0] = new_rn_pair(1000, "M");
    pairs[1] = new_rn_pair(900, "CM");
    pairs[2] = new_rn_pair(500, "D");
    pairs[3] = new_rn_pair(400, "CD");
    pairs[4] = new_rn_pair(100, "C");
    pairs[5] = new_rn_pair(90, "XC");
    pairs[6] = new_rn_pair(50, "L");
    pairs[7] = new_rn_pair(40, "XL");
    pairs[8] = new_rn_pair(10, "X");
    pairs[9] = new_rn_pair(9, "IX");
    pairs[10] = new_rn_pair(5, "V");
    pairs[11] = new_rn_pair(4, "IV");
    pairs[12] = new_rn_pair(1, "I");

    int i;
    for (i = 0; i < ARRAY_LEN(pairs); i++) {
        unsigned int arabic = get_arabic(pairs[i]);
        char *roman = get_roman(pairs[i]);

        while (value >= arabic) {
            strcpy(result, roman);
            result += strlen(roman);
            value -= arabic;
        }

        free_rn_pair(pairs[i]);
    }
}

unsigned int convert_to_arabic(char *value) {
    struct RomanNumeralPair *pairs[13];
    pairs[0] = new_rn_pair(1000, "M");
    pairs[1] = new_rn_pair(900, "CM");
    pairs[2] = new_rn_pair(500, "D");
    pairs[3] = new_rn_pair(400, "CD");
    pairs[4] = new_rn_pair(100, "C");
    pairs[5] = new_rn_pair(90, "XC");
    pairs[6] = new_rn_pair(50, "L");
    pairs[7] = new_rn_pair(40, "XL");
    pairs[8] = new_rn_pair(10, "X");
    pairs[9] = new_rn_pair(9, "IX");
    pairs[10] = new_rn_pair(5, "V");
    pairs[11] = new_rn_pair(4, "IV");
    pairs[12] = new_rn_pair(1, "I");

    int result_array[strlen(value)], result_pos = 0;
    memset(result_array, 0, sizeof(result_array));

    printf("Result array: %zu\n", strlen(value));

    int i;
    for (i = 0; i < ARRAY_LEN(pairs); i++) {
        unsigned int arabic = get_arabic(pairs[i]);
        char *roman = get_roman(pairs[i]);

        while (strncmp(roman, value, strlen(roman)) == 0) {
            printf("value: %s\n", value);
            printf("roman: %s\n", roman);
            result_array[result_pos++] = arabic;
            value += strlen(roman);
        }

        free_rn_pair(pairs[i]);
    }
    unsigned int result = 0;

    for (i = 0; i < ARRAY_LEN(result_array); i++) {
        printf("%d", result);
        result += result_array[i];
        printf(" + %d = %d\n", result_array[i], result);
    }
    printf("\n");

    return result;
}
