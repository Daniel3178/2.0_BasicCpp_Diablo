#pragma once
#include "GameManager.h"

namespace diablo_II 
{
	class				Player;

	struct Door 
	{
	public:
						Door(const Room_States aCurrentRoom, const Room_States aDestinationRoom, const Room_States aDoorState, uint8_t aLockStrength);
		const bool		IsBreakable(const uint16_t& aPlayerStrength);
		void			BreakLock(const uint16_t& aPlayerStrength);
		const			Room_States& GetCurrentRoom() const;
		const			Room_States& GetDestinationRoom(const Room_States& aPlayerCurrentRoom) const;
		const			uint8_t& GetDoorID() const;
		const			Room_States& GetStates() const;
	private:
		Room_States		currentRoom;
		Room_States		destinationRoom;
		static uint8_t	doorIDGen;
		uint8_t			doorID;
		Room_States		state;
		uint8_t			lockStrenght;
	};
}
