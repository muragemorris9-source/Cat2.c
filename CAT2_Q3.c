/*
Name: Morris Murage Muriuki 
Reg no:CT100/G/26143/25
Description:Prompting the user to read the integers from a file
*/

#include <stdio.h>
#include <stdlib.h>

void writeIntegers() {
    FILE *fp;
    int numbers[10];

    fp = fopen("input.txt", "w");
    if (fp == NULL) {
        printf("Error opening input file!\n");
        exit(1);
    }

    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &numbers[i]);
        fprintf(fp, "%d\n", numbers[i]); // write to file
    }

    fclose(fp);
    printf("Numbers successfully written to input.txt\n\n");
}

void processIntegers() {
    FILE *input, *output;
    int num, sum = 0, count = 0;
    float average;

    input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("Error opening input file!\n");
        exit(1);
    }

    output = fopen("output.txt", "w");
    if (output == NULL) {
        printf("Error opening output file!\n");
        fclose(input);
        exit(1);
    }

    printf("Contents of input.txt:\n");
    while (fscanf(input, "%d", &num) == 1) {
        printf("%d ", num);
        sum += num;
        count++;
    }

    average = (float)sum / count;

    fprintf(output, "Sum = %d\nAverage = %.2f\n", sum, average);
    printf("\n\nSum = %d\nAverage = %.2f\n", sum, average);
    printf("Results successfully written to output.txt\n");

    fclose(input);
    fclose(output);
}

int main() {
    writeIntegers();
    processIntegers();
    return 0;
}