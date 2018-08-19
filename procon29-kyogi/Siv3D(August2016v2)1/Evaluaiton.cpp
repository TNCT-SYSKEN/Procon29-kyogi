#include "MapClass/Evaluation.h"

Evaluation* Evaluation::InsEvaluation = nullptr;
Evaluation* Evaluation::getEvaluation()
{
	if (InsEvaluation == nullptr)
	{
		InsEvaluation = new Evaluation;
	}
	return InsEvaluation;
}