#include <stdio.h>
#include <assert.h>

// Function to check if temperature is out of range
int isTemperatureOutOfRange(float temperature) 
{
    if (temperature < 0) {
        printf("Temperature too low!\n");
        return 1;
    }
    if (temperature > 45) {
        printf("Temperature too high!\n");
        return 1;
    }
    return 0;
}

// Function to check if SOC (State of Charge) is out of range
int isSocOutOfRange(float soc) 
{
    if (soc < 20) {
        printf("State of Charge too low!\n");
        return 1;
    }
    if (soc > 80) {
        printf("State of Charge too high!\n");
        return 1;
    }
    return 0;
}

// Function to check if charge rate is out of range
int isChargeRateOutOfRange(float chargeRate) 
{
    if (chargeRate > 0.8) {
        printf("Charge Rate too high!\n");
        return 1;
    }
    return 0;
}

// Function to check battery status
int batteryIsOk(float temperature, float soc, float chargeRate)
{
    int isOk = 1;
    
    // Check temperature
    if (isTemperatureOutOfRange(temperature)) {
        isOk = 0;
    }

    // Check SOC
    if (isSocOutOfRange(soc)) {
        isOk = 0;
    }

    // Check charge rate
    if (isChargeRateOutOfRange(chargeRate)) {
        isOk = 0;
    }
    
    return isOk;
}

int main()
{
    // Tests
    assert(batteryIsOk(25.0, 50.0, 0.5)); // Should pass, all values are okay

    // Should fail and print appropriate error messages
    assert(!batteryIsOk(50.0, 70.0, 0.6)); // Temperature too high
    assert(!batteryIsOk(-5.0, 70.0, 0.6)); // Temperature too low
    assert(!batteryIsOk(25.0, 15.0, 0.6)); // SOC too low
    assert(!batteryIsOk(25.0, 85.0, 0.6)); // SOC too high
    assert(!batteryIsOk(25.0, 70.0, 0.9)); // Charge Rate too high
    
    return 0;
}
