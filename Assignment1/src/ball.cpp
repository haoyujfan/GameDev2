#include "ball.h"
#include "wall.h"
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/random_number_generator.hpp>

using namespace godot;

void Ball::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_velocity", "p_velocity"), &Ball::set_velocity);
    ClassDB::bind_method(D_METHOD("_when_area_entered", "area"), &Ball::_when_area_entered);
}

void Ball::_when_area_entered(const Area3D* area) {
    const Wall* wall = Object::cast_to<Wall>(area);
    if (wall) {
        Vector3 N = wall->get_normal();
        Vector3 R = velocity - 2 * N * (N.x * velocity.x + N.y * velocity.y + N.z * velocity.z);
        set_velocity(R);
    } else {
        const Ball* ball = Object::cast_to<Ball>(area);
        if (!ball) {
            return;
        }
        Vector3 N = get_position() - ball->get_position();
        N = N / N.length();
        Vector3 R = velocity - 2 * N * (N.x * velocity.x + N.y * velocity.y + N.z * velocity.z);
        set_velocity(R);
    }
}

Ball::Ball() {
    velocity = Vector3(0, 0, 0);
    connect("area_entered", Callable(this, "_when_area_entered"));
}

Ball::~Ball() {
    // Add your cleanup here.
}

void Ball::_ready() {
    RandomNumberGenerator rand;
    float x = rand.randf_range(-1, 1);
    float y = rand.randf_range(-1, 1);
    float z = rand.randf_range(-1, 1);
    set_velocity(Vector3(x, y, z));
}

void Ball::_process(double delta) {
    if(Engine::get_singleton()->is_editor_hint()) {
        return;
    }
    Vector3 old_position = get_position();
    Vector3 new_positon = old_position + velocity;
    set_position(new_positon);
}

void Ball::set_velocity(const Vector3 p_velocity) {
    velocity = p_velocity;
}
