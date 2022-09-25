#include "Population.h"
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <ctime>

Population::Population(const Map& map, int initialSize) : map(&map)
{
  for(int i = 0; i < initialSize; ++i)
  {
    push_back(Individual(map));
  }
}

Population& Population::operator=(const Population& other)
{
  assign(other.begin(), other.end());
  map = other.map;
  return *this;
}

Individual& Population::randomSelection()
{
  // TODO implement random selection
  // it should return an individual of the population
  // with a probability proportional to its fitness
    int sum = 0;
    for (int i = 0; i < size(); i++) 
    {
        sum += at(i).getFitness();
    }
    vector<int>probabilities;
    for (int i = 0; i < size(); i++) 
    {
        int nnum = at(i).getFitness();
        int prob = (nnum * 100) / sum;
        for (int j = 0; j < prob; j++) 
        {
            probabilities.push_back(i);
        }
    }
    int randPosition = rand() % probabilities.size();
    return at(probabilities.at(randPosition));

    //
    //return front();
}