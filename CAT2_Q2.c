/*
Name: Morris Murage Muriuki 
Reg no:CT100/G/26143/25
Description:Program that requests the user to enter hours worked in a week and the hourly wage
*/
 #include <stdio.h>

int main() {
    // Declare variables to store hours, wage, and calculated values
    double hours_worked, hourly_wage, gross_pay, taxes, net_pay;

    // Prompt the user for input and store the values
    printf("Enter hours worked in a week: ");
    scanf("%lf", &hours_worked);

    printf("Enter the hourly wage: ");
    scanf("%lf", &hourly_wage);

    // Check for negative input and provide an error message
    if (hours_worked < 0 || hourly_wage < 0) {
        printf("Hours and wage must be positive numbers.\n");
        return 1; // Exit with an error code
    }

    // Step 1: Calculate Gross Pay
    if (hours_worked > 40.0) {
        double regular_hours = 40.0;
        double overtime_hours = hours_worked - regular_hours;
        gross_pay = (regular_hours * hourly_wage) + (overtime_hours * hourly_wage * 1.5);
    } else {
        gross_pay = hours_worked * hourly_wage;
    }

    // Step 2: Calculate Taxes
    if (gross_pay <= 600.0) {
        taxes = gross_pay * 0.15;
    } else {
        taxes = (600.0 * 0.15) + ((gross_pay - 600.0) * 0.20);
    }

    // Step 3: Calculate Net Pay
    net_pay = gross_pay - taxes;

    //  Step 4: Print the results
    printf("\nGross Pay: $%.2f\n", gross_pay);
    printf("Taxes: $%.2f\n", taxes);
    printf("Net Pay: $%.2f\n", net_pay);

    return 0; // Indicate successful execution
}