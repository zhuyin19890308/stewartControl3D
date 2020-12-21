import QtQuick 2.15
import QtQuick3D 1.15

Node {
    id: file_obj

    Model {
        id: f16_fuselage
        source: "meshes/f16_fuselage.mesh"

        DefaultMaterial {
            id: f16_tail_fin__left_side__material
            diffuseColor: "#ff999999"
        }
        materials: [
            f16_tail_fin__left_side__material,
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_right_AMRAAM
        source: "meshes/f16_right_AMRAAM.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_rear_gear_right_door
        source: "meshes/f16_rear_gear_right_door.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_rear_canopy
        source: "meshes/f16_rear_canopy.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_left_wing_pivot
        source: "meshes/f16_left_wing_pivot.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_front_canopy_frame
        source: "meshes/f16_front_canopy_frame.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_hud_display
        source: "meshes/f16_hud_display.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_lights
        source: "meshes/f16_lights.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_engine
        source: "meshes/f16_engine.mesh"
        materials: [
            f16_tail_fin__left_side__material,
            f16_tail_fin__left_side__material,
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_red_light
        source: "meshes/f16_red_light.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_blue_light
        source: "meshes/f16_blue_light.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_rear_gear_right_4
        source: "meshes/f16_rear_gear_right_4.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_right_wing_pivot
        source: "meshes/f16_right_wing_pivot.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_front_canopy
        source: "meshes/f16_front_canopy.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_rear_gear_left_door
        source: "meshes/f16_rear_gear_left_door.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_front_gear_3
        source: "meshes/f16_front_gear_3.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_front_gear2
        source: "meshes/f16_front_gear2.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_rear_gear_right_3
        source: "meshes/f16_rear_gear_right_3.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_rear_canopy_frame
        source: "meshes/f16_rear_canopy_frame.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_rear_gear_right_light
        source: "meshes/f16_rear_gear_right_light.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_rear_gear_inside
        source: "meshes/f16_rear_gear_inside.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_rear_gear_left_3
        source: "meshes/f16_rear_gear_left_3.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_rear_gear_left_light
        source: "meshes/f16_rear_gear_left_light.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_rear_gear_left_4
        source: "meshes/f16_rear_gear_left_4.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_rear_gear_right_wheel
        source: "meshes/f16_rear_gear_right_wheel.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_cockpit
        source: "meshes/f16_cockpit.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_front_gear_door
        source: "meshes/f16_front_gear_door.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_rear_gear_left_wheel
        source: "meshes/f16_rear_gear_left_wheel.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_rear_gear_left_2
        source: "meshes/f16_rear_gear_left_2.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_right_fuel_tank
        source: "meshes/f16_right_fuel_tank.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_rear_gear_rigt_2
        source: "meshes/f16_rear_gear_rigt_2.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_rear_gear_left_1
        source: "meshes/f16_rear_gear_left_1.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_rear_gear_right_1
        source: "meshes/f16_rear_gear_right_1.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_left_AMRAAM
        source: "meshes/f16_left_AMRAAM.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_front_gear_4
        source: "meshes/f16_front_gear_4.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_front_gear_wheel
        source: "meshes/f16_front_gear_wheel.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_left_fuel_tank
        source: "meshes/f16_left_fuel_tank.mesh"
        materials: [
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_front_gear_1
        source: "meshes/f16_front_gear_1.mesh"
        materials: [
            f16_tail_fin__left_side__material,
            f16_tail_fin__left_side__material
        ]
    }

    Model {
        id: f16_horizontal_stabilizer
        source: "meshes/f16_horizontal_stabilizer.mesh"
        materials: [
            f16_tail_fin__left_side__material,
            f16_tail_fin__left_side__material
        ]
    }
}
