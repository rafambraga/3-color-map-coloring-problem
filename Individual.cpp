#include "Individual.h"
#include <string>
#include <cstdio>
#include <iostream> 
#include <iomanip>

using namespace std;

Individual::Individual(const Map& map) : map(&map)
{
  // TODO generate random individual
    int size = map.states.size();
    genom.resize(size);
    for (int i = 0; i < size; i++) 
    {
        genom.at(i) = rand() % 4;
    }
    updateFitness();
}

Individual Individual::reproduce(const Individual& x, const Individual& y)
{
  Individual child(*x.map);

  // TODO generate child from parent individuals x and y

  const int size = child.map->states.size();
  child.genom.resize(size);
  const int crossover = rand() % size;
  for (int i = 0; i < size; i++) 
  {
      if (i < crossover) 
      {
          child.genom.at(i) = x.genom.at(i);
      }
      else 
      {
          child.genom.at(i) = y.genom.at(i);
      }
  }

  //
  child.updateFitness();
  return child;
}

bool Individual::isGoal() const
{
  // TODO implement goal test
    if (fitness == map->borders.size()) 
    {
        return true;
    }

  //
  return false;
}

double Individual::getFitness() const
{
    //
    int fitness = 0;
    int size = map->borders.size();
    for (int i = 0; i < size; i++) 
    {
        int x = genom.at(map->borders.at(i).index1);
        int y = genom.at(map->borders.at(i).index2);
        if (x != y) 
        {
            fitness++;
        }
    }
    return fitness;
    //
}

void Individual::updateFitness()
{
  // TODO implement fitness function
    fitness = getFitness();
  // set member fitness to computed fitness value
}

void Individual::mutate()
{
    // TODO implement random mutation
    const int size = map->states.size();
    const int position = rand() % size;
    genom[position] = rand() % 4;
    updateFitness();
}



void Individual::print() const
{
  // TODO implement printing function
  // it should print the genom in the following form:
  // fitness: 15
  // North Carolina: 0
  // South Carolina: 3
  // ...
   
    cout << endl << "Fitness:" << fitness << endl << endl << endl;
 
    cout << "State \t \t \t \t Color" << endl << endl;

    const char* state = " ";
    for (int i = 0; i < genom.size(); i++) 
    {
        state = map->states.at(i);
        cout << state << ": \t \t \t";        
        switch (genom.at(i)) 
        {
        case 0:
            cout << "Red" << endl;
            break;
        case 1:
            cout << "Green" << endl;
            break;
        case 2:
            cout << "Blue" << endl;
            break;
        case 3:
            cout << "Yellow" << endl;
            break;
        default:
            break;
        }
    }
}