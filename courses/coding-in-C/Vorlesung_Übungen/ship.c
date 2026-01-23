#include<stdio.h>

int main()
{
    char class[] = "";
    int crew = 0;
    int mission_days = 0;
    long long distance_travelled = 900000000000;
    double fraction_of_c = 13.5;
    float current_range = 12860383.867; 
    
    printf("%s\n", "Please enter the class of this vessel");
    scanf("%s", &class);
    printf("%s %s\n", "Please enter the amount of crew aboard the", class);
    scanf("%d", &crew);
    printf("%s %s %s\n", "How long is the", class, "going to be travelling for?");
    scanf("%d", &mission_days);
    printf("%-40s %s\n", "Name", "Value");
    printf("--------------------------------------------------\n");
    
    printf("%-40s %s\n", "Class:", class);
    printf("%-40s %d\n", "Crew Count:", crew);
    printf("%-40s %d\n", "Mission Days:", mission_days);
    printf("%-40s %lld\n", "Distance Travelled:", distance_travelled);
    printf("%-40s %lf\n", "Percentage of c travel speed:", fraction_of_c);
    printf("%-40s %f\n", "Current Range:", current_range);
    
    return 0;
}