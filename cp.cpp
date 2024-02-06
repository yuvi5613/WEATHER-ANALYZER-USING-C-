#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

struct WeatherData {
    std::string date;
    double temperature;
    double humidity;
};

// Function to read weather data from a file
std::vector<WeatherData> 
readWeatherData(const std::string& filename) 
{
    std::vector<WeatherData> data;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return data;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        WeatherData entry;
        ss >> entry.date >> entry.temperature >> entry.humidity;
        data.push_back(entry);
    }

    return data;
}

// Function to calculate average temperature
double calculateAverageTemperature(const std::vector<WeatherData>& data) {
    double sum = 0.0;
    for (const WeatherData& entry : data) {
        sum += entry.temperature;
    }
    return sum / data.size();
}

int main() {
    std::string filename = "weather_data.txt"; // Replace with your data file
    std::vector<WeatherData> weatherData = readWeatherData(filename);

    if (weatherData.empty()) {
        return 1;
    }

    double averageTemperature = calculateAverageTemperature(weatherData);

    std::cout << "Average Temperature: " << averageTemperature << " degrees Celsius" << std::endl;

    return 0;
}