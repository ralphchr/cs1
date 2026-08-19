/*Less than 2.5 mm of rain in the Philippines is considered light. 2.5 mm to 7.5 mm is considered moderate. More than 7.5 up to 15 mm is considered heavy and a yellow warning is broadcast. More than 15 up to 30 mm is considered intense and an orange warning is broadcast. More than 30 mm of rain is considered torrential and a red warning is broadcast. A yellow warning means that flooding is possible. Orange warning means flooding is threatening. Finally, a red warning means serious flooding is expected in low lying areas and residents here are advised to evacuate. Ask the user to enter a rainfall measurement in mm. Determine what kind of warning should be broadcast. DO NOT FORGET ABOUT THE HONOR CODE.

Sample Input and output:

input =1.7
output ="Rain is considered light"

input =3.8
output="Rain is considered moderate"

input =12
output ="Yellow warning"

input =22.5
output ="Orange warning"

input =36
output ="Red warning"
*/

#include <stdio.h>

int main(){
    float rain;

    scanf("%f", &rain);

    if (rain < 2.5){
        printf("Rain is considered light");
    } else if (rain >= 2.5 && rain <= 7.5){
        printf("Rain is considered moderate");
    } else if (rain > 7.5 && rain <= 15){
        printf("Yellow warning");
    } else if (rain > 15 && rain <= 30){
        printf("Orange warning");
    } else if ("rain > 30"){
        printf("Red warning");
    }

}