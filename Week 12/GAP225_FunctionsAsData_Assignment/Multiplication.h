#pragma once
#include "Operation.h"

/////////////////////////////////////////////////////////////////
// Encapsulates a multiplication operation.
/////////////////////////////////////////////////////////////////
class MultiplicationOperation : public Operation
{
public:
	virtual std::string GetDescription() const override;
	virtual float operator()(float& left, float& right) const override;
};