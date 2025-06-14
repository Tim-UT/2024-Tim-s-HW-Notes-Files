//Part 2: Robot Shooting
/*
The speed with which the robot throws the ball is v = 20 m/s.
The robot will stand at a horizontal distance d between 3 and 30 m (inclusive).
The basketball rim will be at a vertical height H between 3 and 6 m (inclusive).
The height of the robot is 2 m
*/
// error is 0.3 m

#include <stdio.h>
#include <math.h>

int main(void) {

    double distance, height;
    double angle;
    double y;
    const double PI = 3.14159;      //defi Pi


    printf("Please enter the horizontal distance from the wall between 3 and 30 m: \n");        //initial input
    scanf("%lf", &distance);
    
        while (distance > 30 || distance < 3) {     //judge the input distance
    
        printf("Please enter the horizontal distance from the wall between 3 and 30 m: \n");        //enter the distance again
        scanf("%lf", &distance);
        }

    printf("Please enter the target height between 3 and 6 m: \n");     //initial input
    scanf("%lf", &height);

        while (height>6 || height <3) {     //judge the input height
    
        printf("Please enter the target height between 3 and 6 m: \n");     //enter the height again
        scanf("%lf", &height);
    

        }


    


    y = 0;      //initalization

    double v_x, v_y, t, angle_r;

    for (angle = 0; fabs(y - height) >= 0.3; angle +=1) {       //try every angle in degree and test the height of the ball

        angle_r = (angle / 180) * PI;       //convert degree to radius

            v_x = 20 * cos(angle_r);
            t = distance / v_x;
            v_y = 20 * sin(angle_r);
            y = 2 + v_y * t - 1.0/2.0  *9.81 * t*t;         //calculate the height of the ball


    }

        //printf("%lf,%lf",y, t);  TEST

    if (angle <= 90 && angle >= 0) {              // judge whether the angle is from 0 to 90 or not
    printf("The angle should be %.2lf\n",angle-1);      //output
    }

return 0;

}
