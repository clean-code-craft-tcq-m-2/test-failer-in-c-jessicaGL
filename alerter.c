#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;
int MaxTempInCelcius = 100;
int Alert = 0;

int networkAlertStub(float celcius) {
    if(celcius > MaxTempInCelcius)
    {
        printf("ALERT: Temperature is %.1f celcius.\n", celcius);
        Alert = 1;
        return 500;
    }
    else
    {
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
        return 200;
    }
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        assert(Alert == 0);
        alertFailureCount += 0;
    }
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
