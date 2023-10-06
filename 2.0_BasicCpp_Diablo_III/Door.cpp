#include "Door.h"

namespace diablo_III
{
	uint8_t Door::doorIDGen = 0;

	Door::Door(const eRoomID aCurrentRoom, const eRoomID aDestinationRoom, const Room_States aDoorState, uint8_t aLockStrength) :
		currentRoom(aCurrentRoom), doorID(0), destinationRoom(aDestinationRoom), state(aDoorState)
	{
		if(aDoorState == Room_States::DOOR_STATE_LOCKED)
		{
			lockStrenght = aLockStrength;
		}
		else
		{
			lockStrenght = 0;
		}
		doorID = ++doorIDGen;
	}

	const bool Door::IsBreakable(const uint16_t& aPlayerStrength)
	{
		if(aPlayerStrength >= lockStrenght)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	const eRoomID& Door::GetCurrentRoom() const
	{
		return currentRoom;
	}

	const eRoomID& Door::GetDestinationRoom(const eRoomID& aPlayerCurrentRoom) const
	{
		if(aPlayerCurrentRoom == currentRoom)
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
		if(state == Room_States::DOOR_STATE_LOCKED && this->IsBreakable(aPlayerStrength))
		{
			std::cout << "The lock has been broken \n";
			state = Room_States::DOOR_STATE_UNLOCKED;
		}
		else if(state == Room_States::DOOR_STATE_LOCKED)
		{
			std::cout << "You don't have enough strenght to break this lock! | Strength required : " << (int) lockStrenght << '\n';
		}
		else
		{
			std::cout << "The door has no lock or it has been unlocked earlier \n";
		}
	}
}