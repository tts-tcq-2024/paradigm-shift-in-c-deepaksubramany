
#include <stdio.h>
#include <assert.h>


const float WARNING_TOLERANCE_TEMPERATURE = 2.25; // 5% of 45
const float WARNING_TOLERANCE_SOC = 4.0; // 5% of 80
const float WARNING_TOLERANCE_CHARGE_RATE = 0.04; // 5% of 0.8

// Function to check if a parameter is in a valid range and print messages
int checkParameter(float value, float lowerLimit, float upperLimit, float warningTolerance, const char* errorMessageLow, const char* errorMessageHigh, const char* warningMessageLow, const char* warningMessageHigh) {
    int isOk = 1;

    if (value < lowerLimit) {
        printf("%s\n", errorMessageLow);
        isOk = 0;
    } else if (value > upperLimit) {
        printf("%s\n", errorMessageHigh);
        isOk = 0;
    }

    
    if (value >= (lowerLimit + warningTolerance) && value < lowerLimit) {
        printf("%s\n", warningMessageLow);
    } else if (value > (upperLimit - warningTolerance) && value <= upperLimit) {
        printf("%s\n", warningMessageHigh);
    }

    return isOk;
}

// Functions for parameter checks with embedded message printing
int isTemperatureOk(float temperature) {
    return checkParameter(temperature, 0, 45, WARNING_TOLERANCE_TEMPERATURE,
                          "Temperature too low!", "Temperature too high!",
                          "Warning: Approaching discharge!", "Warning: Approaching high temperature!");
}

int isStateOfChargeOk(float soc) {
    return checkParameter(soc, 20, 80, WARNING_TOLERANCE_SOC,
                          "State of Charge too low!", "State of Charge too high!",
                          "Warning: Approaching discharge!", "Warning: Approaching charge-peak!");
}

int isChargeRateOk(float chargeRate) {
    return checkParameter(chargeRate, 0, 0.8, WARNING_TOLERANCE_CHARGE_RATE,
                          "Charge Rate too high!", "Charge Rate too high!",
                          "Warning: Approaching high rate!", "Warning: Approaching high rate!");
}


int batteryIsOk(float temperature, float soc, float chargeRate) {
    return isTemperatureOk(temperature) &&
           isStateOfChargeOk(soc) &&
           isChargeRateOk(chargeRate);
}


void testBatteryIsOk() {
  
    assert(batteryIsOk(25.0, 50.0, 0.5));  // All parameters okay
    assert(!batteryIsOk(50.0, 70.0, 0.6)); // Temperature too high
    assert(!batteryIsOk(-5.0, 70.0, 0.6)); // Temperature too low
    assert(!batteryIsOk(25.0, 15.0, 0.6)); // State of Charge too low
    assert(!batteryIsOk(25.0, 85.0, 0.6)); // State of Charge too high
    assert(!batteryIsOk(25.0, 70.0, 0.9)); // Charge Rate too high
    
  
    assert(batteryIsOk(40.0, 24.0, 0.77)); // Warning: Approaching high temperature
    assert(batteryIsOk(25.0, 21.0, 0.78)); // Warning: Approaching discharge
    assert(batteryIsOk(25.0, 79.0, 0.76)); // Warning: Approaching charge-peak
    assert(batteryIsOk(25.0, 70.0, 0.76)); // Warning: Approaching high rate

    printf("All tests passed.\n");
}


int main() {
    testBatteryIsOk();
    return 0;
}
