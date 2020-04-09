#pragma once
#include "Job.h"

class WoodCutter : public Job{

public:
	
	virtual void DoJob() override;

	virtual void ShowJobInfo() override;

	static WoodCutter* Get();

private:
	WoodCutter();
	virtual ~WoodCutter();

	static WoodCutter* WoodCutterJob;
};