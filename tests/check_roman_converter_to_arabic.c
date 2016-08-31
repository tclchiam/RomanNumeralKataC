#include <check.h>
#include <roman_converter.h>

#include "check_suites.h"

START_TEST(test_single_numerals)
    {
        unsigned int result;

        result = convert_to_arabic("M");
        ck_assert_int_eq(1000, result);

        result = convert_to_arabic("D");
        ck_assert_int_eq(500, result);

        result = convert_to_arabic("C");
        ck_assert_int_eq(100, result);

        result = convert_to_arabic("L");
        ck_assert_int_eq(50, result);

        result = convert_to_arabic("X");
        ck_assert_int_eq(10, result);

        result = convert_to_arabic("V");
        ck_assert_int_eq(5, result);

        result = convert_to_arabic("I");
        ck_assert_int_eq(1, result);
    }
END_TEST

Suite *roman_converter_to_arabic_suite() {
    Suite *suite;
    TCase *tcase_core;

    suite = suite_create("Roman Converter - To Arabic");

    tcase_core = tcase_create("Core");

    tcase_add_test(tcase_core, test_single_numerals);

    suite_add_tcase(suite, tcase_core);

    return suite;
}