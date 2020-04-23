#include "cruise.h"
#include "aircraft_state.h"

#include <geometry3d/position.h>
#include <geometry3d/orientation.h>
#include <geometry3d/velocity.h>
#include <geometry3d/rotation.h>

using namespace Geometry3D;

namespace
{
	bool areEqual(double a, double b)
	{
		return abs(a - b) <= std::numeric_limits<double>::epsilon();
	}

	double clamp(double& val, double min, double max)
	{
		return val<min ? min : val>max ? max : val;
	}
}

namespace Scripted6DoFFlight
{

	EnterCruise::EnterCruise(
		const AircraftState& enteringCondition,
		double transitionTime,
		double targetSpeed,
		double targetAzimouth,
		const Orientation& offsetDuringManueover
	) :
		remainingTransitionTime(transitionTime),
		targetVel(
			targetSpeed* std::cos(targetAzimouth),
			targetSpeed* std::sin(targetAzimouth),
			0. // no change in altitude
		),
		targetOrient(
			0., // no pitch
			0., // no roll
			targetAzimouth
		)
	{
		targetOrient = offsetDuringManueover.inReferenceFrame(targetOrient);
	}

	// Todo: avoid creating new TargetState Objects evey call
	AircraftState EnterCruise::update(double deltaT, const AircraftState& currentState)
	{
		AircraftState nextState(currentState);
		{
			//peek update
			//nextState.x = interpolate;
		}
		remainingTransitionTime 
		return nextState;
	}

	bool EnterCruise::hasTransitioned() const
	{
		return areEqual(0., remainingTransitionTime)
	}

}