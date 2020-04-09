#pragma once

#include "Core/Entity.h"

class Job;

class Agent : public Entity{

public:

	Agent() = default;
	Agent(Job* job);
	virtual ~Agent();

	virtual void Begin() override;
	
	virtual void Update(float dt) override;
	
	template<class T>
	static Agent* CreateAgentWithJob() {
		Job* job = T::Get();
		return new Agent(job);
	}
	
	Job* AgentJob = nullptr;
};

