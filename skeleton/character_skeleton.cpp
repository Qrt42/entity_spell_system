#include "character_skeleton.h"

const String CharacterSkeleton::BINDING_STRING_CHARCATER_SKELETON_BONE_ID = "Hip, Left Hand, Right Hand";


NodePath CharacterSkeleton::get_hip_path() {
	return _hip_path;
}

void CharacterSkeleton::set_hip_path(NodePath path) {
	_hip_path = path;

	_nodes[BONE_ID_HIP] = get_node_or_null(_hip_path);
}

NodePath CharacterSkeleton::get_left_hand_path() {
	return _left_hand_path;
}

void CharacterSkeleton::set_left_hand_path(NodePath path) {
	_left_hand_path = path;

	_nodes[BONE_ID_LEFT_HAND] = get_node_or_null(_left_hand_path);
}

NodePath CharacterSkeleton::get_right_hand_path() {
	return _right_hand_path;
}

void CharacterSkeleton::set_right_hand_path(NodePath path) {
	_right_hand_path = path;

	_nodes[BONE_ID_RIGHT_HAND] = get_node_or_null(_right_hand_path);
}

Node *CharacterSkeleton::get_bone_node(CharacterSkeletonBoneId node_id) {
	return _nodes[node_id];
}

NodePath CharacterSkeleton::get_animation_player_path() {
	return _animation_player_path;
}

void CharacterSkeleton::set_animation_player_path(NodePath path) {
	_animation_player_path = path;

	Node *node = get_node_or_null(_animation_player_path);

	if (node != NULL) {
		_animation_player = Object::cast_to<AnimationPlayer>(node);
	} else {
		_animation_player = NULL;
	}
}

AnimationPlayer *CharacterSkeleton::get_animation_player() {
	return _animation_player;
}

NodePath CharacterSkeleton::get_animation_tree_path() {
	return _animation_tree_path;
}

void CharacterSkeleton::set_animation_tree_path(NodePath path) {
	_animation_tree_path = path;

	Node *node = get_node_or_null(_animation_tree_path);

	if (node != NULL) {
		_animation_tree = Object::cast_to<AnimationTree>(node);
	} else {
		_animation_tree = NULL;
	}
}

AnimationTree *CharacterSkeleton::get_animation_tree() {
	return _animation_tree;
}

void CharacterSkeleton::update_nodes() {
	_nodes[BONE_ID_HIP] = get_node_or_null(_hip_path);
	_nodes[BONE_ID_LEFT_HAND] = get_node_or_null(_left_hand_path);
	_nodes[BONE_ID_RIGHT_HAND] = get_node_or_null(_right_hand_path);

	set_animation_player_path(_animation_player_path);
	set_animation_tree_path(_animation_tree_path);
}

CharacterSkeleton::CharacterSkeleton() {
	for (int i = 0; i < MAX_BONE_ID; ++i) {
		_nodes[i] = NULL;
	}

	_animation_player = NULL;
}

void CharacterSkeleton::_notification(int p_what) {
	switch (p_what) {
		case NOTIFICATION_ENTER_TREE: {
			update_nodes();
		} break;
		case NOTIFICATION_PROCESS: {
		} break;
		case NOTIFICATION_EXIT_TREE: {

		} break;
	}
}

void CharacterSkeleton::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_hip_path"), &CharacterSkeleton::get_hip_path);
	ClassDB::bind_method(D_METHOD("set_hip_path", "path"), &CharacterSkeleton::set_hip_path);
	ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "hip_path"), "set_hip_path", "get_hip_path");

	ClassDB::bind_method(D_METHOD("get_left_hand_path"), &CharacterSkeleton::get_left_hand_path);
	ClassDB::bind_method(D_METHOD("set_left_hand_path", "path"), &CharacterSkeleton::set_left_hand_path);
	ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "left_hand_path"), "set_left_hand_path", "get_left_hand_path");

	ClassDB::bind_method(D_METHOD("get_right_hand_path"), &CharacterSkeleton::get_right_hand_path);
	ClassDB::bind_method(D_METHOD("set_right_hand_path", "path"), &CharacterSkeleton::set_right_hand_path);
	ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "right_hand_path"), "set_right_hand_path", "get_right_hand_path");

	ClassDB::bind_method(D_METHOD("get_bone_node", "bone_idx"), &CharacterSkeleton::get_bone_node);

	ClassDB::bind_method(D_METHOD("get_animation_player_path"), &CharacterSkeleton::get_animation_player_path);
	ClassDB::bind_method(D_METHOD("set_animation_player_path", "path"), &CharacterSkeleton::set_animation_player_path);
	ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "animation_player_path"), "set_animation_player_path", "get_animation_player_path");

	ClassDB::bind_method(D_METHOD("get_animation_tree_path"), &CharacterSkeleton::get_animation_tree_path);
	ClassDB::bind_method(D_METHOD("set_animation_tree_path", "path"), &CharacterSkeleton::set_animation_tree_path);
	ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "animation_tree_path"), "set_animation_tree_path", "get_animation_tree_path");

	ClassDB::bind_method(D_METHOD("get_animation_player"), &CharacterSkeleton::get_animation_player);
	ClassDB::bind_method(D_METHOD("get_animation_tree"), &CharacterSkeleton::get_animation_tree);

	ClassDB::bind_method(D_METHOD("update_nodes"), &CharacterSkeleton::update_nodes);

	BIND_ENUM_CONSTANT(BONE_ID_HIP);
	BIND_ENUM_CONSTANT(BONE_ID_LEFT_HAND);
	BIND_ENUM_CONSTANT(BONE_ID_RIGHT_HAND);
	BIND_ENUM_CONSTANT(MAX_BONE_ID);
}