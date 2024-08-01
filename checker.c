#include <stdio.h>
#include <assert.h>

int batteryIsOk(float temperature, float soc, float chargeRate)
{
    int isOk = 1;
    
    if (temperature < 0) {
        printf("Temperature too low!\n");
        isOk = 0;
    } else if (temperature > 45) {
        printf("Temperature too high!\n");
        isOk = 0;
    }
 
    if (soc < 20) {
        printf("State of Charge too low!\n");
        isOk = 0;
    } else if (soc > 80) {
        printf("State of Charge too high!\n");
        isOk = 0;
    }

  
    if (chargeRate > 0.8) {
        printf("Charge Rate too high!\n");
        isOk = 0;
    }
    
    return isOk;
}

int main()
{
    assert(batteryIsOk(25.0, 50.0, 0.5)); 

    assert(!batteryIsOk(50.0, 70.0, 0.6)); 
    assert(!batteryIsOk(-5.0, 70.0, 0.6)); 
    assert(!batteryIsOk(25.0, 15.0, 0.6)); 
    assert(!batteryIsOk(25.0, 85.0, 0.6)); 
    assert(!batteryIsOk(25.0, 70.0, 0.9)); 
    assert(batteryIsOk(25.0, 70.0, 0.9)); 
    return 0;
}
