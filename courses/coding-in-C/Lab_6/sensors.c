#include <stdio.h>

#define SAMPLE_SIZE 3000
#define INTERVAL 100

typedef struct 
{
    float time;
    double probability;
} SensorData;

typedef struct 
{
    double threshold;
    int object_detection[SAMPLE_SIZE];
    SensorData data[SAMPLE_SIZE];
} Sensor;


int read_data(const char *p_filename, Sensor *p_sensor)
{
    FILE *p_file = fopen(p_filename, "r");

    if (p_file == NULL)
    {
        printf("Error: Couldn't open file %s\n", p_filename);
        return -1;
    }

    int i = 0;
    while (i < SAMPLE_SIZE)
    {
        if (fscanf(p_file, "%f %lf", &p_sensor->data[i].time, &p_sensor->data[i].probability) != 2)
        {
            printf("Wrong file format or not enough data. Program exiting\n");
            fclose(p_file);
            return -1;
        }
        i++;
    }
    fclose(p_file);

    return 0;
}

int main() {

    Sensor sensor1 = {1, 0.8};
    Sensor sensor2 = {2, 0.7};
    if (read_sensor_data("sensor1.txt", &sensor1) < 0)
    {
        return -1;
    }
    if (read_sensor_data("sensor2.txt", &sensor2) < 0)
    {
        return -1;
    };

    return 0;
}
