#include <iostream>
#include <math.h>
#include <stdio.h>
#pragma warning(disable: 4996)
using namespace std;


int main() {
   
   

    double x0 = 0.0;
    if (!(std::cin >> x0)) {
        return 0;
    }

    if (x0 > 0 && x0 <= 4) {
        double step = (4-x0)/9;
        double x1;
        for (int i = 0; i < 10; i++)
        {
            x1 = sin(x0) / x0;
            cout << " " << x1;
            x0 += step;
        }
        cout << endl;
    }


    long long max_value = 0;
    if (!(std::cin >> max_value)) {
        return 0;
    }
    bool limit = true;
    long long value_new = 1, value, num1 = 0, num2 = 1, num3, quantity = 2;

    if (max_value >= 0) {
        
        if (max_value == 0) { limit = false; value = 0; quantity = 0; }
        if (max_value == 1) { limit = false; value = 1; quantity = 2; }


        while (limit == true) {

            num3 = num2 + num1;
            value_new += num3;
            if (value_new > max_value) { limit = false; break; };

            num1 = num2;
            num2 = num3;
            value = value_new;
            quantity++;

        }

        cout << quantity << " " << value;
    }
    cout << endl;
      

    double time, summa, percent, percentSumma, allPercentSumma = 0, payment;

        
    printf("Time: ");
    scanf_s("%lf", &time);
    printf("Summa: ");
    scanf_s("%lf", &summa);
    printf("Percent: ");
    scanf_s("%lf", &percent);
    printf("\n");
    
    if (summa >= 0 && time >= 0 && percent >= 0) {

        payment = summa / time;
        printf("         credit      percen     payment\n");
        for (int i = 1; i <= time; i++)
        {
            percentSumma = summa * percent / 100 / time;
            allPercentSumma += percentSumma;
            printf("%3d  %10.2f  %10.2f  %10.2f\n",i, round(summa*100)/100, round(percentSumma*100)/100, round((payment + percentSumma)*100)/100);
            summa -= payment;
            
        }

        printf("All percent: %.2f\n", round(allPercentSumma*100)/100);
    }
    

    return 0;
}
