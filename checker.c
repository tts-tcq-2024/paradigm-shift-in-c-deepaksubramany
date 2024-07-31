#include <stdio.h>
#include <assert.h>

// Function to check battery status and print error messages
int batteryIsOk(float temperature, float soc, float chargeRate)
{
    int isOk = 1;
    
    // Check temperature
    if (temperature < 0) {
        printf("Temperature too low!\n");
        isOk = 0;
    } else if (temperature > 45) {
        printf("Temperature too high!\n");
        isOk = 0;
    }

    // Check SOC (State of Charge)
    if (soc < 20) {
        printf("State of Charge too low!\n");
        isOk = 0;
    } else if (soc > 80) {
        printf("State of Charge too high!\n");
        isOk = 0;
    }

    // Check charge rate
    if (chargeRate > 0.8) {
        printf("Charge Rate too high!\n");
        isOk = 0;
    }
    
    return isOk;
}

int main()
{
    // Test cases
    assert(batteryIsOk(25.0, 50.0, 0.5)); // Should pass, all values are okay

    assert(!batteryIsOk(50.0, 70.0, 0.6)); // Should fail, Temperature too high
    assert(!batteryIsOk(-5.0, 70.0, 0.6)); // Should fail, Temperature too low
    assert(!batteryIsOk(25.0, 15.0, 0.6)); // Should fail, SOC too low
    assert(!batteryIsOk(25.0, 85.0, 0.6)); // Should fail, SOC too high
    assert(!batteryIsOk(25.0, 70.0, 0.9)); // Should fail, Charge Rate too high
    
    return 0;
}
