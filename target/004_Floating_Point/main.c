

#include <stdio.h>

int main(){
	float number = 12.12345678910;

	printf("%d\n", number); //int is not big enough
	printf("%f\n", number); //float loses precision
	printf("%0.2f\n", number); //2 places after decimal
	printf("%0.2e\n", number); //Scientific Notation

	float chargeOfElectron = -1.60217662e-19;

	printf("%f\n", chargeOfElectron);
	printf("%e\n", chargeOfElectron);
	printf("%0.28lf\n", chargeOfElectron);
	printf("%0.2le\n", chargeOfElectron);
	return 0;
}
