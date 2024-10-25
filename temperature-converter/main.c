#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

/*
Temperature converter
-----------------
converts temperature between Celsius, Fahrenheit and Kelvin

Celsius to Fahrenheit: F = C * 9/5 + 32
Celsius to Kelvin: K = C + 273.15
Fahrenheit to Celsius: C = (F - 32) * 5/9
Fahrenheit to Kelvin: K = (F - 32) * 5/9 + 273.15
Kelvin to Celsius: C = K - 273.15
Kelvin to Fahrenheit: F = (K - 273.15) * 9/5 + 32

*/

// function prototypes
float celsius_to_fahrenheit(float celsius);
float celsius_to_kelvin(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float fahrenheit_to_kelvin(float fahrenheit);
float kelvin_to_celsius(float kelvin);
float kelvin_to_fahrenheit(float kelvin);
void start_converting();
float get_temperature(void);
bool convert_again(void);

int main(void)
{
    do
    {
        start_converting();
    } while (convert_again());

    printf("Thank you for using temperature converter.\n");
    return 0;
}

// functions definitions
float celsius_to_fahrenheit(float celsius)
{
    float fahrenheit = celsius * 9 / 5.0 + 32;
    return fahrenheit;
}

float celsius_to_kelvin(float celsius)
{
    float kelvin = celsius + 273.15;
    return kelvin;
}

float fahrenheit_to_celsius(float fahrenheit)
{
    float celsius = (fahrenheit - 32) * 5 / 9.0;
    return celsius;
}

float fahrenheit_to_kelvin(float fahrenheit)
{
    float kelvin = (fahrenheit - 32) * 5 / 9.0 + 273.15;
    return kelvin;
}

float kelvin_to_celsius(float kelvin)
{
    float celsius = kelvin - 273.15;
    return celsius;
}

float kelvin_to_fahrenheit(float kelvin)
{
    float fahrenheit = (kelvin - 273.15) * 9 / 5.0 + 32;
    return fahrenheit;
}

void start_converting()
{
    float temperature = get_temperature();
    printf("Choose the conversion you want to make:\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Celsius to Kelvin\n");
    printf("3. Fahrenheit to Celsius\n");
    printf("4. Fahrenheit to Kelvin\n");
    printf("5. Kelvin to Celsius\n");
    printf("6. Kelvin to Fahrenheit\n");
    int choice;
    do
    {
        choice = get_int("Enter your choice: ");
    } while (choice < 1 || choice > 6);

    switch (choice)
    {
    case 1:
        printf("%.2f Celsius is %.2f Fahrenheit\n", temperature, celsius_to_fahrenheit(temperature));
        break;
    case 2:
        printf("%.2f Celsius is %.2f Kelvin\n", temperature, celsius_to_kelvin(temperature));
        break;
    case 3:
        printf("%.2f Fahrenheit is %.2f Celsius\n", temperature, fahrenheit_to_celsius(temperature));
        break;
    case 4:
        printf("%.2f Fahrenheit is %.2f Kelvin\n", temperature, fahrenheit_to_kelvin(temperature));
        break;
    case 5:
        printf("%.2f Kelvin is %.2f Celsius\n", temperature, kelvin_to_celsius(temperature));
        break;
    case 6:
        printf("%.2f Kelvin is %.2f Fahrenheit\n", temperature, kelvin_to_fahrenheit(temperature));
        break;
    }
}
float get_temperature(void)
{
    float temperature;
    do
    {
        temperature = get_float("Enter temperature: ");
    } while (temperature < -273.15); // absolute zero
    return temperature;
}

bool convert_again(void)
{
    char answer;
    do
    {
        answer = get_char("Do you want to convert another temperature? (y/n): ");
        answer = tolower(answer);
    } while (answer != 'y' && answer != 'n');
    return answer == 'y';
}