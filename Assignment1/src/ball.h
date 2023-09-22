#ifndef BALL_H
#define BALL_H

#include <godot_cpp/classes/area3d.hpp>

namespace godot {

class Ball : public Area3D {
    GDCLASS(Ball, Area3D)

private:
    Vector3 velocity;

protected:
    static void _bind_methods();

public:
    Ball();
    ~Ball();

    void _process(double delta) override;
    void _ready() override;
    void _when_area_entered(const Area3D* area);
    void set_velocity(const Vector3 p_velocity);
};

}

#endif