#pragma once

#include "Operation.h"

/////////////////////////////////////////////////////////////////
// Encapsulates an  operation.
/////////////////////////////////////////////////////////////////
class SubtractionOperation : public Operation
{
public:
	virtual std::string GetDescription() const override;
	virtual float operator()(float& left, float& right) const override;
};