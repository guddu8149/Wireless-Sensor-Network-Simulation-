#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class SensorNode {
public:
    int id;
    double x, y;
    double energy;
    
    SensorNode(int id, double x, double y, double energy)
        : id(id), x(x), y(y), energy(energy) {}

    double distanceTo(double baseX, double baseY) {
        return sqrt(pow(baseX - x, 2) + pow(baseY - y, 2));
    }

    void transmitData(double baseX, double baseY) {
        double distance = distanceTo(baseX, baseY);
        double energyConsumed = 0.01 * distance; 
        if (energy >= energyConsumed) {
            energy -= energyConsumed;
            cout << "Sensor " << id << " transmitted data. Remaining energy: " << energy << endl;
        } else {
            cout << "Sensor " << id << " has insufficient energy." << endl;
        }
    }
};

int main() {
    double baseStationX = 50.0, baseStationY = 50.0;

    
    vector<SensorNode> sensors = {
        SensorNode(1, 10.0, 10.0, 100.0),
        SensorNode(2, 20.0, 30.0, 100.0),
        SensorNode(3, 40.0, 50.0, 100.0),
    };

   
    for (auto &sensor : sensors) {
        sensor.transmitData(baseStationX, baseStationY);
    }

    return 0;
}
