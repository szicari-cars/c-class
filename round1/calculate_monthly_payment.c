#include <stdio.h>
#include <math.h>

void display_greeting();
double calculate_monthly_payment(double, double, int);
double calculate_interest_percent(double);
double calculate_total_paid(double monthly_payment, int years);

/**
 * You *know* what this is.
 */
int main()
{
    double interest_rate, principle, monthly_payment, total_paid;
    int loan_term;

    display_greeting();

    // Collect the loan details.
    printf("Please enter the interest rate on the loan: ");
    scanf("%lf", &interest_rate);

    printf("Please enter the loan term (in years): ");
    scanf("%d", &loan_term);

    printf("Please enter the amount you borrowed: ");
    scanf("%lf", &principle);

    // Now, calculate the monthly payment.
    monthly_payment = calculate_monthly_payment(principle, interest_rate, loan_term);
    total_paid = calculate_total_paid(monthly_payment, loan_term);

    printf("\nCongratulations! You're giving your life away for $%.2lf/month!\n", monthly_payment);
    printf("You will pay $%.2lf on this loan, ", total_paid);
    printf("$%.2lf more than if you just paid in cash.\n", total_paid - principle);

    return 0;
}

double calculate_total_paid(double monthly_payment, int years)
{
    int months = years * 12;
    return monthly_payment * months;
}

/**
 * Calculates the user's monthly payment.
 */
double calculate_monthly_payment(double principle, double interest_rate, int loan_term)
{
    int months = get_months_from_years(loan_term);
    double percent_interest = calculate_interest_percent(interest_rate), monthly_payment = 0.0;

    monthly_payment = pow(1+percent_interest, months);
    monthly_payment = monthly_payment - 1;
    monthly_payment = percent_interest / monthly_payment;
    monthly_payment = percent_interest + monthly_payment;
    monthly_payment = monthly_payment * principle;

    return monthly_payment;
}

/**
 * Takes a "whole number" interest rate and returns a value appropriate for
 * calculations.
 */
double calculate_interest_percent(double interest_rate)
{
    return interest_rate / 1200.0;
}

int get_months_from_years(int years)
{
    return years * 12;
}

/**
 * Displays a simple introductory greeting, adjusting the user to our ever-
 * tightening realm of control.
 */
void display_greeting()
{
    printf("Welcome! Please answer a few questions so I can calculate your monthly payment.\n");
}

