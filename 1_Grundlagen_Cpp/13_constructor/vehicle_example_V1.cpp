#include <iostream>

class Vehicle
{
public:
    Vehicle(){
        std::cout << "Created Vehicle" << std::endl;
    }
    ~Vehicle(){}

    void drive_to_x_pos(float new_x){
        float distance = abs(new_x - x_pos);
        float needed_fuel = consumption * distance/100;

        if (needed_fuel > fuel){
            std::cout << "Not enough fuel" << std::endl;
            return;
        }

        x_pos = new_x;
        fuel -= needed_fuel;
        total_consumption += needed_fuel;

        std::cout << "Drove for " << distance << "km" << std::endl;
        std::cout << "New position: " << new_x << std::endl;
    }

    void refuel(){
        fuel = max_fuel;
        std::cout << "Refueled to " << max_fuel << "L" << std::endl;
    }

    float get_total_consumption(){
        std::cout << "Total consumption: " << total_consumption << "L" << std::endl;
        return total_consumption;
    }

    float get_total_distance(){
        float total = total_consumption*100/consumption;
        std::cout << "Total distance: " << total << "km" << std::endl;
        return total;
    }

private:
    float x_pos = 0.0;
    const float max_fuel = 50.0;
    float fuel = max_fuel;
    float consumption = 6.0; // l/100km
    float total_consumption = 0.0;
};

int main()
{
    Vehicle V;
    V.drive_to_x_pos(50.0/6.0*100.0);
    V.get_total_consumption();
    V.get_total_distance();
    V.refuel();

    V.drive_to_x_pos(0.0);
    V.get_total_consumption();
    V.get_total_distance();
    return 0;
}
