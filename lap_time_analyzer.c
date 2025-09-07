#include <stdio.h>
#include<math.h>
int main()
{
    int n;
    printf("Enter number of sectors: ");
    scanf("%d", &n);
    
    double times[100];
    double total_time = 0;
    
    for(int i = 0; i < n; i++)
    {
        int type;
        printf("\nSector %d - Enter 1 for Straight, 2 for Corner: ", i + 1);
        scanf("%d", &type);
        
    double time=0;
    
    if (type == 1)
    {
        double length, speed;
        printf("\nLength of straight: ");
        scanf("%lf", &length);
        printf("\nSpeed (km/h): ");
        scanf("%lf", &speed);
        double speed_ms= speed*1000/3600;
        time= length/speed_ms;
    }
    else if(type == 2)
    {
        double radius, angle, speed;
        printf("\nRadius of corner(m): ");
        scanf("%lf", &radius);
        printf("\nEnter angle of the corner(degree): ");
        scanf("%lf", &angle);
        printf("\nEnter the speed(km/h): ");
        scanf("%lf", &speed);
        
        double angle_rad = angle*M_PI/180;
        double arc_length = radius*angle_rad;
        double speed_ms = speed*1000/3600;
        time = arc_length/speed_ms;
    
    }
    else
    {
        printf("\nInvalid sector type! Skipping.....");
        continue;
    }
    times[i]=time;
    total_time+= time;
    }
    
    printf("\n----Results----\n");
    for(int i=0; i<n; i++)
    {
        printf("Sector %d time: %.2f sec\n", i + 1, times[i]);
    }
    printf("\nTotal Lap Time: %.2f sec\n", total_time);
    
 return 0;
}