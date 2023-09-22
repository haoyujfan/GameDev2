#include "wall.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void Wall::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_normal"), &Wall::get_normal);
    ClassDB::bind_method(D_METHOD("set_normal", "p_normal"), &Wall::set_normal);
    ClassDB::add_property("Wall", PropertyInfo(Variant::VECTOR3, "normal"), "set_normal", "get_normal");
}

Wall::Wall() {
    normal = Vector3(0, 0, 0);
}

Wall::~Wall() {
    // Add your cleanup here.
}

void Wall::_process(double delta) {
}

void Wall::set_normal(const Vector3 p_normal) {
    normal = p_normal;
}

Vector3 Wall::get_normal() const {
    return normal;
}