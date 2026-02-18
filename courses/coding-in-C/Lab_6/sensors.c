#include <stdio.h>

#define SAMPLE_SIZE 3000
#define MAX_INTERVALS 100

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

void sensor_detections(Sensor *p_sensor)
{
    for (int i = 0; i < SAMPLE_SIZE; i++)
    {
        if (p_sensor->data[i].probability > p_sensor->threshold)
        {
            p_sensor->object_detection[i] = 1;
        }
        else
        {
            p_sensor->object_detection[i] = 0;
        }
    }
    return;
}

void sensor_intervals(int signal[], SensorData data[], const char *label)
{

    int active = 0;
    float starts[MAX_INTERVALS] = {[0 ... MAX_INTERVALS - 1] = -1};
    float ends[MAX_INTERVALS] = {[0 ... MAX_INTERVALS - 1] = -1};   
    int starts_time = 0;
    int ends_time = 0;

    for (int i = 0; i < SAMPLE_SIZE; i++)
    {
        if (signal[i] > 0 && !active)
        {
            if (starts_time < MAX_INTERVALS)
            {
                active = 1;
                starts[starts_time] = data[i].time;
                starts_time++;
            }
        }
        else if (signal[i] < 1 && active)
        {
            if (ends_time < MAX_INTERVALS)
            {
                active = 0;
                ends[ends_time] = data[i - 1].time;
                ends_time++;
            }
        }
    }
    if (starts_time > ends_time && ends_time < MAX_INTERVALS)
    {
        ends[ends_time] = data[SAMPLE_SIZE - 1].time;
    }
    print_interval(starts, ends, label);
    return;
}

void fusing_sensors(int sensor1_detection[], int sensor2_detection[], int fusion[])
{
    for (int i = 0; i < SAMPLE_SIZE; i++)
    {
        fusion[i] = sensor1_detection[i] && sensor2_detection[i];
    }
    return;
}

int main() {

    Sensor sensor1 = {1, 0.8};
    Sensor sensor2 = {2, 0.7};

    if (read_data("sensor1.txt", &sensor1) < 0)
    {
        return -1;
    }
    if (read_data("sensor2.txt", &sensor2) < 0)
    {
        return -1; 
    };

    sensor_detections(&sensor1);
    sensor_detections(&sensor2);

    sensor_intervals(&sensor1.object_detection, sensor1.data, "Sensor 1");
    sensor_intervals(&sensor2.object_detection, sensor2.data, "Sensor 2");

    return 0;
}
