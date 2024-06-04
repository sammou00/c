#include <stdio.h>
#include <cs50.h>

// Function Prototypes
double getTemperature();
double celsiusToFahrenheit(double temperature);
void displayTemperatureInfo(double temperature, double fahrenheit);

// Main Function
int main(void)
{
    double temperature = getTemperature();
    double fahrenheit = celsiusToFahrenheit(temperature);
    displayTemperatureInfo(temperature, fahrenheit);
    return 0;
}

// Function Definitions
double getTemperature()
{
    double temperature;

    while (true)
    {
        temperature = get_double("Enter temperature: ");
        if (temperature >= 0)
        {
            break;
        }
        else
        {
            printf("Temperature cannot be less than 0°C.\n");
            printf("Please try again.\n");
        }
    }

    return temperature;
}

double celsiusToFahrenheit(double temperature)
{
    return (temperature * 9.0 / 5.0) + 32;
}

void displayTemperatureInfo(double temperature, double fahrenheit)
{
    printf("Temperature in Celsius: %.2lf\n", temperature);
    printf("Temperature in Fahrenheit: %.2lf\n", fahrenheit);
}
