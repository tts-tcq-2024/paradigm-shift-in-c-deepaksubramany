#include <stdio.h>
#include <assert.h>

// Function to check if the battery is okay
int batteryIsOk(float temperature, float soc, float chargeRate)
{
    int isOk = 1;

    // Consolidate temperature checks
    if (temperature < 0 || temperature > 45) {
        if (temperature < 0) {
            printf("Temperature too low!\n");
        } else {
            printf("Temperature too high!\n");
        }
        isOk = 0;
    }

    // Consolidate state of charge (SOC) checks
    if (soc < 20 || soc > 80) {
        if (soc < 20) {
            printf("State of Charge too low!\n");
        } else {
            printf("State of Charge too high!\n");
        }
        isOk = 0;
    }

    // Consolidate charge rate check
    if (chargeRate > 0.8) {
        printf("Charge Rate too high!\n");
        isOk = 0;
    }

    return isOk;
}

int main()
{
    // Tests
    assert(batteryIsOk(25.0, 50.0, 0.5)); 
    assert(!batteryIsOk(50.0, 70.0, 0.6)); 
    assert(!batteryIsOk(-5.0, 70.0, 0.6)); 
    assert(!batteryIsOk(25.0, 15.0, 0.6)); 
    assert(!batteryIsOk(25.0, 85.0, 0.6)); 
    assert(!batteryIsOk(25.0, 70.0, 0.9)); 

    return 0;
}
