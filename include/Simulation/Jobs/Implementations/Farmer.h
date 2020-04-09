#pragma once
#include "Job.h"

class Farmer : public Job{

public:
	
	virtual void DoJob() override;

	virtual void ShowJobInfo() override;

	static Farmer* Get();

	
	
private:

	Farmer();
	virtual ~Farmer();

	static Farmer* FarmerJob;
};
