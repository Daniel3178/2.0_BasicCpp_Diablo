#pragma once
#include "GameManager.h"

namespace diablo_III 
{
	class				Player;
	enum class eRoomID;
	class Door 
	{
	public:
						Door(const eRoomID aCurrentRoom, const eRoomID aDestinationRoom, const Room_States aDoorState, uint8_t aLockStrength);
		const bool		IsBreakable(const uint16_t& aPlayerStrength);
		void			BreakLock(const uint16_t& aPlayerStrength);
		const			eRoomID& GetCurrentRoom() const;
		const			eRoomID& GetDestinationRoom(const eRoomID& aPlayerCurrentRoom) const;
		const			uint8_t& GetDoorID() const;
		const			Room_States& GetStates() const;
	private:
		eRoomID		currentRoom;
		eRoomID		destinationRoom;
		static uint8_t	doorIDGen;
		uint8_t			doorID;
		Room_States		state;
		uint8_t			lockStrenght;
	};
}
