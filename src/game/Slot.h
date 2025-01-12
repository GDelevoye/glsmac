#pragma once

#include "types/Serializable.h"

#include "game/Player.h"

namespace game {

CLASS( Slot, types::Serializable )

	enum slot_state_t {
		SS_CLOSED,
		SS_OPEN,
		SS_PLAYER,
	};
	const slot_state_t GetState() const;

	typedef uint8_t player_flag_t;
	static const player_flag_t PF_NONE = 0;
	static const player_flag_t PF_READY = 1 << 0;
	static const player_flag_t PF_MAP_DOWNLOADED = 1 << 1;

	void Open();
	void Close();
	void SetCloseAfterClear();

	size_t GetCid() const;
	const std::string& GetRemoteAddress() const;
	void SetPlayerFlag( const player_flag_t flag );
	const bool HasPlayerFlag( const player_flag_t flag ) const;
	void UnsetPlayerFlag( const player_flag_t flag );

	Player* GetPlayer() const;
	Player* GetPlayerAndClose();
	void SetPlayer( Player* player, const size_t cid, const std::string& remote_address );

	const types::Buffer Serialize() const override;
	void Unserialize( types::Buffer buf ) override;

private:

	slot_state_t m_slot_state = SS_OPEN;
	bool m_close_after_clear = false;
	struct {
		Player* player = nullptr;
		size_t cid = 0;
		std::string remote_address = "";
		player_flag_t flags = PF_NONE;
	} m_player_data = {};

};

}
