#include <stdio.h>

void calculate_letter_grade(int grade) {
    if (grade < 0 || grade > 100) {
        printf("Grade %d is not valid. The grade must be between 0 and 100!\n", grade);
    } else if (grade >= 95) {
        printf("Grade: %d Letter Grade: A\n", grade);
    } else if (grade >= 90) {
        printf("Grade: %d Letter Grade: A-\n", grade);
    } else if (grade >= 85) {
        printf("Grade: %d Letter Grade: B+\n", grade);
    } else if (grade >= 80) {
        printf("Grade: %d Letter Grade: B\n", grade);
    } else if (grade >= 75) {
        printf("Grade: %d Letter Grade: B-\n", grade);
    } else if (grade >= 70) {
        printf("Grade: %d Letter Grade: C+\n", grade);
    } else if (grade >= 65) {
        printf("Grade: %d Letter Grade: C\n", grade);
    } else if (grade >= 60) {
        printf("Grade: %d Letter Grade: C-\n", grade);
    } else if (grade >= 55) {
        printf("Grade: %d Letter Grade: D+\n", grade);
    } else if (grade >= 50) {
        printf("Grade: %d Letter Grade: D\n", grade);
    } else if (grade >= 0) {
        printf("Grade: %d Letter Grade: F\n", grade);
    }
}

void main() {
    calculate_letter_grade(-40);
    calculate_letter_grade(156);
    calculate_letter_grade(96);
    calculate_letter_grade(92);
    calculate_letter_grade(87);
    calculate_letter_grade(82);
    calculate_letter_grade(77);
    calculate_letter_grade(71);
    calculate_letter_grade(65);
    calculate_letter_grade(63);
    calculate_letter_grade(57);
    calculate_letter_grade(52);
    calculate_letter_grade(43);
    calculate_letter_grade(20);
    calculate_letter_grade(5);
}
