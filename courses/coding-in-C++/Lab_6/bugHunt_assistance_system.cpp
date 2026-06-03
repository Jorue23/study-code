#include "bugHunt_assistance_system.hpp"

#include <iostream>
#include <vector>
#include <memory>

#define EMERGENCY_BRAKING_SPEED 30.0

DistanceSensor::DistanceSensor(const std::string &sensor_position,
                               double initial_distance_m)
    : position(sensor_position),
      active(true),
      measured_distance_m(initial_distance_m)
{
}

void DistanceSensor::set_distance(double distance_m)
{
    measured_distance_m = distance_m;
}

void DistanceSensor::activate()
{
    active = true;
}

void DistanceSensor::deactivate()
{
    active = false;
}

double DistanceSensor::get_distance() const
{
    return measured_distance_m;
}

bool DistanceSensor::is_active() const
{
    return active;
}

std::string DistanceSensor::get_position() const
{
    return position;
}

void DistanceSensor::print_info() const
{
    std::cout << "Sensor position: " << position << '\n';
    std::cout << "Distance: " << measured_distance_m << " m\n";
    std::cout << "Active: " << std::boolalpha << active << "\n\n";
}

EmergencyBrakeSystem::EmergencyBrakeSystem(double critical_distance, std::shared_ptr<DistanceSensor> front_sensor)
    : critical_distance_m(critical_distance), front_sensor(front_sensor)
{
}

void EmergencyBrakeSystem::evaluate(Vehicle &vehicle)
{
    if (!front_sensor->is_active())
    {
        return;
    }

    if (front_sensor->get_distance() <= critical_distance_m)
    {
        std::cout << "[EmergencyBrakeSystem] Emergency braking triggered.\n";
        vehicle.brake(EMERGENCY_BRAKING_SPEED);
    }
}

LaneKeepingAssist::LaneKeepingAssist(double max_offset,
                                     double correction,
                                     std::shared_ptr<DistanceSensor> front_sensor)
                                    : max_allowed_offset_m(max_offset),
                                      correction_angle(correction),
                                      front_sensor(front_sensor)
{
}

void LaneKeepingAssist::evaluate(Vehicle &vehicle) const
{
    double offset = vehicle.get_lane_offset();

    if (offset > max_allowed_offset_m)
    {
        std::cout << "[LaneKeepingAssist] Correcting to the left.\n";
        vehicle.steer(-correction_angle);
    }
    else if (offset < -max_allowed_offset_m)
    {
        std::cout << "[LaneKeepingAssist] Correcting to the right.\n";
        vehicle.steer(correction_angle);
    }
    else
    {
        vehicle.steer(0.0);
    }
}

AdaptiveCruiseControl::AdaptiveCruiseControl(double target_speed,
                                             double minimum_distance,
                                             std::shared_ptr<DistanceSensor> front_senor)
    : target_speed_kmh(target_speed),
      minimum_distance_m(minimum_distance),
      front_sensor(front_senor)
{
}

void AdaptiveCruiseControl::evaluate(Vehicle &vehicle) const
{
    if (!front_sensor->is_active())
    {
        return;
    }

    if (front_sensor->get_distance() < minimum_distance_m)
    {
        std::cout << "[AdaptiveCruiseControl] Vehicle ahead is close. Braking.\n";
        vehicle.brake(5.0);
    }
    else if (vehicle.get_speed() < target_speed_kmh)
    {
        std::cout << "[AdaptiveCruiseControl] Increasing speed.\n";
        vehicle.accelerate(5.0);
    }
    else if (vehicle.get_speed() > target_speed_kmh)
    {
        std::cout << "[AdaptiveCruiseControl] Reducing speed.\n";
        vehicle.brake(5.0);
    }
}

ParkingAssistant::ParkingAssistant(double warning_distance)
    : warning_distance_m(warning_distance)
{
}

void ParkingAssistant::add_sensor(std::shared_ptr<DistanceSensor> sensor)
{
    sensors.push_back(sensor);
}

void ParkingAssistant::print_warnings() const
{
    for (auto sensor : sensors)
    {
        if (sensor != nullptr &&
            sensor->is_active() &&
            sensor->get_distance() < warning_distance_m)
        {
            std::cout << "[ParkingAssistant] Warning at "
                      << sensor->get_position()
                      << ": obstacle detected.\n";
        }
    }
}