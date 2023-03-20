#include <stdio.h>
#include <assert.h>

#define ALERT 500
#define NO_ALERT 200
#define LIMIT 100

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
    else if(celcius < MaxTempInCelcius)
    {
        printf("NO ALERT \n");
        return NO_ALERT;
    }
    else
    {
        return LIMIT;
    }
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != ALERT) {
        assert(Alert == 0);
      
    }
    else
    {
       alertFailureCount += 0; 
    }
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    printf("%d alerts failed.\n", alertFailureCount);
    assert(networkAlertStub(MaxTempInCelcius) == ALERT);
    
    printf("All is well (maybe!)\n");
    return 0;
}
