checkParameter Function:

    Simplified the decision-making logic to handle both error and warning messages.
    Reduced cyclomatic complexity by ensuring the function has only a few decision branches.

Parameter Check Functions:

    Used checkParameter for all individual parameter checks (isTemperatureOk, isStateOfChargeOk, isChargeRateOk).
    Each function now directly checks the corresponding parameter's validity and warnings.

Testing:

    Included assertions in the testBatteryIsOk function to test both normal operation and early warning scenarios.
    Verified that all error and warning conditions are handled correctly.
