#include "Door.h"

namespace diablo_I
{
	uint8_t Door::doorIDGen = 0;

	Door::Door(const Room_States aCurrentRoom, const Room_States aDestinationRoom, const Room_States aDoorState) :
		currentRoom(aCurrentRoom), doorID(0), destinationRoom(aDestinationRoom), state(aDoorState), lockStrenght(0)
	{



		if (aDoorState == Room_States::DOOR_STATE_LOCKED)
		{
			lockStrenght = 20;
		}
		doorID = ++doorIDGen;
	}

	const bool Door::IsBreakable(const uint16_t& aPlayerStrength)
	{

		if (aPlayerStrength >= lockStrenght)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	const Room_States& Door::GetCurrentRoom() const
	{
		return currentRoom;
	}
	
	const Room_States& Door::GetDestinationRoom(const Room_States& aPlayerCurrentRoom) const
	{
		if (aPlayerCurrentRoom == currentRoom)
		{
			return destinationRoom;
		}
		else
		{
			return currentRoom;
		}
	}

	const uint8_t& Door::GetDoorID() const
	{
		return doorID;
	}
	
	const Room_States& Door::GetStates() const
	{
		return state;
	}


	void Door::BreakLock(const uint16_t& aPlayerStrength)
	{

		if (state == Room_States::DOOR_STATE_LOCKED && this->IsBreakable(aPlayerStrength))
		{
			std::cout << "The lock has been broken \n";
			state = Room_States::DOOR_STATE_UNLOCKED;
		}

		else if (state == Room_States::DOOR_STATE_LOCKED)
		{
			std::cout << "You don't have enough strenght to break this lock \n";
		}

		else
		{
			std::cout << "The door has no lock or it has been unlocked earlier \n";
		}
	}
}