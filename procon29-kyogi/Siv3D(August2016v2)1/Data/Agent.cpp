#include "Agent.h"

Agent* Agent::InsAgent = nullptr;
Agent* Agent::getAgent() {
	if (InsAgent == nullptr) {
		InsAgent = new Agent;
	}
	return InsAgent;
}