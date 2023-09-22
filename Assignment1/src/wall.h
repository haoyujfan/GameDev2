#ifndef WALL_H
#define WALL_H

#include <godot_cpp/classes/area3d.hpp>

namespace godot {

class Wall : public Area3D {
    GDCLASS(Wall, Area3D)

private:
    Vector3 normal;

protected:
    static void _bind_methods();

public:
    Wall();
    ~Wall();

    void _process(double delta) override;

    void set_normal(const Vector3 p_normal);
    Vector3 get_normal() const;
};

}

#endif