// EconomicEngine.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include "Engine.h"
#include "Simulation.h"
#include "Entity.h"
#include "Parser.h"
#include <iostream>
#include <chrono>


int main()
{
	Engine* EconomicEngine = new Engine();
	Simulation* EconomicSimulation = EconomicEngine->CreateSimulation();
	while (EconomicSimulation->SimulationActive) {
		EconomicSimulation->ConsummeCycle();
	}
	//TODO Simulation Output
	delete EconomicSimulation;
	delete EconomicEngine;
	EconomicSimulation = nullptr;
	EconomicEngine = nullptr;
	return 0;
}
