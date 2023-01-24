#pragma once

#include "base/Base.h"

#include "scene/actor/Actor.h"
#include "../shader_program/ShaderProgram.h"

#include "types/Vec3.h"

using namespace types;

namespace graphics {
namespace opengl {

CLASS( Actor, base::Base )
	Actor( scene::actor::Actor *actor );
	~Actor();
	virtual void Load() {};
	virtual void Unload() {};
	virtual bool ReloadNeeded() { return false; }
	virtual void Draw( shader_program::ShaderProgram *shader_program ) = 0;
	scene::actor::Actor *GetActor() const {
		return m_actor;
	}
	void UnlinkActor() {
		m_actor = nullptr;
	}
	const Vec3& GetPosition() const;
	void SetPosition( const Vec3& position );
protected:
	scene::actor::Actor *m_actor;
	
	Vec3 m_position;
	
};

} /* namespace opengl */
} /* namespace graphics */