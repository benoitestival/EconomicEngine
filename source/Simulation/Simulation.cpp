#include "Simulation/Simulation.h"
#include <iostream>
#include "Engine/Parser/Parser.h"
#include "Engine/Parser/Json.h"


Simulation::Simulation(){
}

Simulation::~Simulation() {
	Agents.clear();
	Events.clear();
	CyclesEventRegistry.clear();
	SimulationsResults.clear();
	
}

void Simulation::ConsummeCycle() {

	std::cout << ActualCycle << std::endl;
	std::cout << Agents.size() << std::endl;
	GameMode* _GameMode = GamePlayStatics::GetGameMode();
	bool GetCycleData = false;
	if (ActualCycle % DataCollectionOccurence == 0) {
		GetCycleData = true;
	}
	
	//Event
	if (!CyclesEventRegistry[ActualCycle].empty()) {
		std::cout << "Events Happened" << std::endl;
		for (auto& Index : CyclesEventRegistry[ActualCycle]) {
			if (!Events[Index]->AsBegin) {
				Events[Index]->EventStart();
			}
			else {
				Events[Index]->EventEnd();
			}
		}
	}
	//Agents
	for (auto& Agent: Agents) {
		if (GetCycleData) {
			SimulationsResults[ActualCycle/DataCollectionOccurence]._AgentCycleResult.push_back(Agent->PreviousTurnResult);
		}
		Agent->DoLife();
	}
	_GameMode->TradeManager->ResolveTrades();
	if (GetCycleData) {
		
		for (auto& Item : _GameMode->ItemsManager->GetRegistry()) {
			SimulationsResults[ActualCycle / DataCollectionOccurence]._ItemCycleResult.push_back({Item.Price, Item.ItemName});
		}
	}
	
	ActualCycle++;
	if (ActualCycle >= TotalNbrCycles) {
		EndSimulation();
	}
}

void Simulation::EndSimulation(){
	SimulationActive = false;
}
