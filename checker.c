#include <stdio.h>
#include <assert.h>

int isTemperatureOutOfRange(float temperature)
{
    return (temperature < 0 || temperature > 45);
}

int isSocOutOfRange(float soc) 
{
    return (soc < 20 || soc > 80);
}

int isChargeRateOutOfRange(float chargeRate) 
{
    return (chargeRate > 0.8);
}

void printErrorMessage(const char *message) 
{
    printf("%s\n", message);
}

int batteryIsOk(float temperature, float soc, float chargeRate)
{
    if (isTemperatureOutOfRange(temperature)) 
    {
        printErrorMessage("Temperature out of range!");
        return 0;
    }
    
    if (isSocOutOfRange(soc)) 
    {
        printErrorMessage("State of Charge out of range!");
        return 0;
    }
    
    if (isChargeRateOutOfRange(chargeRate))
   {
        printErrorMessage("Charge Rate out of range!");
        return 0;
    }
    
    return 1;
}

int main()
{
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}








