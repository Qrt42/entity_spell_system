/*
Copyright (c) 2019-2020 Péter Magyar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef SPELL_ENUMS_H
#define SPELL_ENUMS_H

#include "core/object.h"

class SpellEnums : public Object {
	GDCLASS(SpellEnums, Object);

public:
	static const String BINDING_STRING_SPELL_TYPES;
	static const String BINDING_STRING_SPELL_CATEGORY;
	static const String BINDING_STRING_DIMINISHING_RETURN_CATEGORIES;
	static const String BINDING_STRING_TRIGGER_EVENTS;
	static const String BINDING_STRING_DAMAGE_TYPES;
	static const String BINDING_STRING_AURA_TYPES;
	static const String BINDING_STRING_AURA_FLAG_TYPES;
	static const String BINDING_STRING_COLLIDER_TYPE;
	static const String BINDING_STRING_TARGET_TYPE;

	enum DamageType {
		DAMAGE_TYPE_NONE = 0,
		DAMAGE_TYPE_MELEE = 1 << 0,
		DAMAGE_TYPE_HOLY = 1 << 1,
		DAMAGE_TYPE_SHADOW = 1 << 2,
		DAMAGE_TYPE_NATURE = 1 << 3,
		DAMAGE_TYPE_FIRE = 1 << 4,
		DAMAGE_TYPE_FROST = 1 << 5,
		DAMAGE_TYPE_LIGHTNING = 1 << 6,
		DAMAGE_TYPE_CHAOS = 1 << 7,
	};

	enum SpellCategory {
		SPELL_CATEGORY_NORMAL = 0,
		SPELL_CATEGORY_ALCHEMY = 1,
		SPELL_CATEGORY_COOKING = 2,
		SPELL_CATEGORY_ENGINEERING = 3,
		SPELL_CATEGORY_CRAFTING = 4,
		SPELL_CATEGORY_HIDDEN = 5,
		SPELL_CATEGORY_DEVELOPMENT = 6,
	};

	enum SpellType {
		SPELL_TYPE_NONE = 0,
		SPELL_TYPE_MELEE = 1 << 0,
		SPELL_TYPE_HOLY = 1 << 1,
		SPELL_TYPE_SHADOW = 1 << 2,
		SPELL_TYPE_NATURE = 1 << 3,
		SPELL_TYPE_FIRE = 1 << 4,
		SPELL_TYPE_FROST = 1 << 5,
		SPELL_TYPE_LIGHTNING = 1 << 6,
		SPELL_TYPE_CHAOS = 1 << 7,
	};

	enum DiminishingReturnCategory {
		DIMINISHING_RETURN_CATEGORY_NONE,
		DIMINISHING_RETURN_CATEGORY_ROOT,
		DIMINISHING_RETURN_CATEGORY_STUN,
	};

	enum TriggerEvents {
		TRIGGER_NONE,
		TRIGGER_AURA_EVENT_S_ON_BEFORE_DAMAGE,
		TRIGGER_AURA_EVENT_S_ON_DAMAGE_RECEIVE,
		TRIGGER_AURA_EVENT_S_ON_HIT,
		TRIGGER_AURA_EVENT_S_ON_DAMAGE_DEALT,
		TRIGGER_AURA_EVENT_S_ON_AURA_REMOVE,
		TRIGGER_AURA_EVENT_S_ON_AURA_DISPELL,
		TRIGGER_AURA_EVENT_S_ON_BEFORE_AURA_APPLIED,
		TRIGGER_AURA_EVENT_S_ON_AFTER_AURA_APPLIED,
		TRIGGER_AURA_EVENT_C_ON_AURA_ADDED,
		TRIGGER_AURA_EVENT_C_ON_AURA_REMOVED,
		TRIGGER_AURA_EVENT_C_ON_AURA_REFRESHED,
	};

	enum AuraType {
		AURA_TYPE_NONE = 0,
		AURA_TYPE_MAGIC = 1 << 0,
		AURA_TYPE_POISON = 1 << 1,
		AURA_TYPE_PHYSICAL = 1 << 2,
		AURA_TYPE_CURSE = 1 << 3,
		AURA_TYPE_BLEED = 1 << 4,
		AURA_TYPE_TALENT = 1 << 5,
		AURA_TYPE_SKILL = 1 << 6,
	};

	enum ColliderType {
		COLLIDER_TYPE_NONE = 0,
		COLLIDER_TYPE_SPHERE,
		COLLIDER_TYPE_BOX
	};

	enum TargetType {
		TARGET_TYPE_NONE = 0,
		TARGET_TYPE_NODE,
		TARGET_TYPE_BONE_ID,
		TARGET_TYPE_COORDS,
	};

	enum {
		NOTIFICATION_AURA_BEFORE_APPLIED = 0,
		NOTIFICATION_AURA_AFTER_APPLIED,
		NOTIFICATION_AURA_APPLIED,
		NOTIFICATION_AURA_ADDED,
		NOTIFICATION_AURA_REMOVED,
		NOTIFICATION_AURA_REFRESHED,
	};

	enum {
		NOTIFICATION_DAMAGE_BEFORE_HIT = 0,
		NOTIFICATION_DAMAGE_HIT,
		NOTIFICATION_DAMAGE_BEFORE_DAMAGE,
		NOTIFICATION_DAMAGE_RECEIVE,
		NOTIFICATION_DAMAGE_DEALT_DAMAGE,
		NOTIFICATION_DAMAGE_DAMAGE_DEALT,
		NOTIFICATION_DAMAGE_DAMAGE,
	};

	enum {
		NOTIFICATION_HEAL_BEFORE_HIT = 0,
		NOTIFICATION_HEAL_BEFORE_HEAL,
		NOTIFICATION_HEAL_RECEIVE,
		NOTIFICATION_HEAL_DEALT_HEAL,
		NOTIFICATION_HEAL_HEAL_DEALT,
	};

	enum {
		NOTIFICATION_CAST_BEFORE = 0,
		NOTIFICATION_CAST_BEFORE_CAST_TARGET,
		NOTIFICATION_CAST_FINISHED_TARGET,
		NOTIFICATION_CAST_FINISHED,
		NOTIFICATION_CAST_STARTED,
		NOTIFICATION_CAST_FAILED,
		NOTIFICATION_CAST_SUCCESS,
		NOTIFICATION_CAST_INTERRUPTED,
		NOTIFICATION_CAST_DELAYED,
	};

	SpellEnums() {}

protected:
	static void _bind_methods() {
		BIND_ENUM_CONSTANT(DAMAGE_TYPE_NONE);
		BIND_ENUM_CONSTANT(DAMAGE_TYPE_MELEE);
		BIND_ENUM_CONSTANT(DAMAGE_TYPE_HOLY);
		BIND_ENUM_CONSTANT(DAMAGE_TYPE_SHADOW);
		BIND_ENUM_CONSTANT(DAMAGE_TYPE_NATURE);
		BIND_ENUM_CONSTANT(DAMAGE_TYPE_FIRE);
		BIND_ENUM_CONSTANT(DAMAGE_TYPE_FROST);
		BIND_ENUM_CONSTANT(DAMAGE_TYPE_LIGHTNING);
		BIND_ENUM_CONSTANT(DAMAGE_TYPE_CHAOS);

		BIND_ENUM_CONSTANT(SPELL_CATEGORY_NORMAL);
		BIND_ENUM_CONSTANT(SPELL_CATEGORY_ALCHEMY);
		BIND_ENUM_CONSTANT(SPELL_CATEGORY_COOKING);
		BIND_ENUM_CONSTANT(SPELL_CATEGORY_ENGINEERING);
		BIND_ENUM_CONSTANT(SPELL_CATEGORY_CRAFTING);
		BIND_ENUM_CONSTANT(SPELL_CATEGORY_HIDDEN);
		BIND_ENUM_CONSTANT(SPELL_CATEGORY_DEVELOPMENT);

		BIND_ENUM_CONSTANT(SPELL_TYPE_NONE);
		BIND_ENUM_CONSTANT(SPELL_TYPE_MELEE);
		BIND_ENUM_CONSTANT(SPELL_TYPE_HOLY);
		BIND_ENUM_CONSTANT(SPELL_TYPE_SHADOW);
		BIND_ENUM_CONSTANT(SPELL_TYPE_NATURE);
		BIND_ENUM_CONSTANT(SPELL_TYPE_FIRE);
		BIND_ENUM_CONSTANT(SPELL_TYPE_FROST);
		BIND_ENUM_CONSTANT(SPELL_TYPE_LIGHTNING);
		BIND_ENUM_CONSTANT(SPELL_TYPE_CHAOS);

		BIND_ENUM_CONSTANT(DIMINISHING_RETURN_CATEGORY_NONE);
		BIND_ENUM_CONSTANT(DIMINISHING_RETURN_CATEGORY_ROOT);
		BIND_ENUM_CONSTANT(DIMINISHING_RETURN_CATEGORY_STUN);

		BIND_ENUM_CONSTANT(TRIGGER_NONE);
		BIND_ENUM_CONSTANT(TRIGGER_AURA_EVENT_S_ON_BEFORE_DAMAGE);
		BIND_ENUM_CONSTANT(TRIGGER_AURA_EVENT_S_ON_DAMAGE_RECEIVE);
		BIND_ENUM_CONSTANT(TRIGGER_AURA_EVENT_S_ON_HIT);
		BIND_ENUM_CONSTANT(TRIGGER_AURA_EVENT_S_ON_DAMAGE_DEALT);
		BIND_ENUM_CONSTANT(TRIGGER_AURA_EVENT_S_ON_AURA_REMOVE);
		BIND_ENUM_CONSTANT(TRIGGER_AURA_EVENT_S_ON_AURA_DISPELL);
		BIND_ENUM_CONSTANT(TRIGGER_AURA_EVENT_S_ON_BEFORE_AURA_APPLIED);
		BIND_ENUM_CONSTANT(TRIGGER_AURA_EVENT_S_ON_AFTER_AURA_APPLIED);
		BIND_ENUM_CONSTANT(TRIGGER_AURA_EVENT_C_ON_AURA_ADDED);
		BIND_ENUM_CONSTANT(TRIGGER_AURA_EVENT_C_ON_AURA_REMOVED);
		BIND_ENUM_CONSTANT(TRIGGER_AURA_EVENT_C_ON_AURA_REFRESHED);

		BIND_ENUM_CONSTANT(AURA_TYPE_NONE);
		BIND_ENUM_CONSTANT(AURA_TYPE_MAGIC);
		BIND_ENUM_CONSTANT(AURA_TYPE_POISON);
		BIND_ENUM_CONSTANT(AURA_TYPE_PHYSICAL);
		BIND_ENUM_CONSTANT(AURA_TYPE_CURSE);
		BIND_ENUM_CONSTANT(AURA_TYPE_BLEED);
		BIND_ENUM_CONSTANT(AURA_TYPE_TALENT);
		BIND_ENUM_CONSTANT(AURA_TYPE_SKILL);

		BIND_ENUM_CONSTANT(COLLIDER_TYPE_NONE);
		BIND_ENUM_CONSTANT(COLLIDER_TYPE_SPHERE);
		BIND_ENUM_CONSTANT(COLLIDER_TYPE_BOX);

		BIND_ENUM_CONSTANT(TARGET_TYPE_NONE);
		BIND_ENUM_CONSTANT(TARGET_TYPE_NODE);
		BIND_ENUM_CONSTANT(TARGET_TYPE_BONE_ID);
		BIND_ENUM_CONSTANT(TARGET_TYPE_COORDS);

		BIND_CONSTANT(NOTIFICATION_AURA_BEFORE_APPLIED);
		BIND_CONSTANT(NOTIFICATION_AURA_AFTER_APPLIED);

		BIND_CONSTANT(NOTIFICATION_DAMAGE_BEFORE_HIT);
		BIND_CONSTANT(NOTIFICATION_DAMAGE_HIT);
		BIND_CONSTANT(NOTIFICATION_DAMAGE_BEFORE_DAMAGE);
		BIND_CONSTANT(NOTIFICATION_DAMAGE_RECEIVE);
		BIND_CONSTANT(NOTIFICATION_DAMAGE_DEALT_DAMAGE);
		BIND_CONSTANT(NOTIFICATION_DAMAGE_DAMAGE_DEALT);

		BIND_CONSTANT(NOTIFICATION_HEAL_BEFORE_HIT);
		BIND_CONSTANT(NOTIFICATION_HEAL_BEFORE_HEAL);
		BIND_CONSTANT(NOTIFICATION_HEAL_RECEIVE);
		BIND_CONSTANT(NOTIFICATION_HEAL_DEALT_HEAL);
		BIND_CONSTANT(NOTIFICATION_HEAL_HEAL_DEALT);

		BIND_CONSTANT(NOTIFICATION_CAST_BEFORE);
		BIND_CONSTANT(NOTIFICATION_CAST_BEFORE_CAST_TARGET);
		BIND_CONSTANT(NOTIFICATION_CAST_FINISHED_TARGET);
		BIND_CONSTANT(NOTIFICATION_CAST_FINISHED);
		BIND_CONSTANT(NOTIFICATION_CAST_STARTED);
		BIND_CONSTANT(NOTIFICATION_CAST_FAILED);
		BIND_CONSTANT(NOTIFICATION_CAST_SUCCESS);
		BIND_CONSTANT(NOTIFICATION_CAST_INTERRUPTED);
		BIND_CONSTANT(NOTIFICATION_CAST_DELAYED);
	}
};

VARIANT_ENUM_CAST(SpellEnums::SpellType);
VARIANT_ENUM_CAST(SpellEnums::SpellCategory);
VARIANT_ENUM_CAST(SpellEnums::DiminishingReturnCategory);
VARIANT_ENUM_CAST(SpellEnums::TriggerEvents);
VARIANT_ENUM_CAST(SpellEnums::DamageType);
VARIANT_ENUM_CAST(SpellEnums::AuraType);
VARIANT_ENUM_CAST(SpellEnums::ColliderType);
VARIANT_ENUM_CAST(SpellEnums::TargetType);

#endif
