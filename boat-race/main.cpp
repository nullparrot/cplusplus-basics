#include <fstream> 
#include <iostream> 
#include <string> 
#include <vector>
#include <math.h>

using namespace std;


class Race
{
public:
  int time;
  int distance;
  int wins;
};

int main() {
  // Pepare final result variable
  int answer = 1;
  // Open File
  ifstream puzzle_input ("input.txt");
  // Hold lines from file
  vector<string> lines;
  // Load file into vector
  if (puzzle_input.is_open()) {
    // Iterate through lines of file
    string line;
    while (getline(puzzle_input, line)) {
      // Load Line in vector
      lines.push_back(line);
    }
    // Close File
    puzzle_input.close();
  } else { 
    // Output error if unable to load file
        cerr << "Unable to open file!" << endl; 
    }
  // Start to organize the data
  vector<Race> races;
  // Remove line headings
  lines[0].erase (0,9);
  lines[1].erase (0,9);

  // Seperate Times and Distances
  // Load into races
  while (lines[0].size() > 0){
    // Create New Race
    Race race;
    // Remove Spaces from begining of times
    while (lines[0][0] == ' '){
      lines[0].erase(0,1);
    }
    // Store first time in race
    race.time = stoi(lines[0].substr(0, lines[0].find(" ")));
    // Remove time from string
    lines[0].erase(0, lines[0].find(" "));
    // Remove Spaces from beginning of distances
    while (lines[1][0] == ' '){
      lines[1].erase(0,1);
    }
    // Store first distance in race
    race.distance = stoi(lines[1].substr(0, lines[1].find(" ")));
    // Remove distance from string
    lines[1].erase(0, lines[1].find(" "));
    // Add race to races vector
    races.push_back(race);
  }

  cout << races.size() << " Races Found in File" << endl;

// Process races
for (size_t i = 0; i < races.size(); i++)
{
  // Output Race Details
  cout << "Race " << i << endl;
  cout << "Distance: " << races[i].distance << endl;
  cout << "Time: "  << races[i].time << endl;
  // Determine and print best possible score
  cout << "Hold button for " << round(races[i].time/2) << " milliseconds to maximize distance at " << round(races[i].time/2)*(races[i].time-round(races[i].time/2)) << "mm"<< endl;
  // Determine possible new records
  int wins = 0;
  // Try each button holding time
  for (size_t n = 0; n <= races[i].time; n++)
  {
    // Increment if it wins
    if (n*(races[i].time-n) > races[i].distance) {
      wins++;
    }
    // Store possible wins
    races[i].wins = wins;
  }
  // Return possible win states
  cout << "There are " << races[i].wins << " ways to beat the current record" << endl;
  // Multiply win scenarios to document
  answer *= races[i].wins;

}
// Return final result
  cout << "Final Result: " << answer << endl;
  return 0;
}