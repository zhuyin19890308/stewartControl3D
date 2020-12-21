import QtQuick 2.4
import QtQuick3D 1.15
import Qt3D.Input 2.15
import Qt3D.Core 2.14
import Qt3D.Extras 2.15
import Qt3D.Animation 2.10
import Qt3D.Render 2.15
import Qt3D.Logic 2.0
import QtQuick 2.15

Item {
    id: root
    width: 400
    height: 400

    Model {
        id: cylinder
        x: 0
        y: 123.072
        source: "#Cylinder"
        z: 42.3432
        materials: cylinderMaterial
        DefaultMaterial {
            id: cylinderMaterial
            diffuseColor: "#4aee45"
        }

        AreaLight {
            id: lightArea
            x: -370.799
            y: 131.029
            z: -131.02901
        }
    }

    View3D {
        id: view3D
        x: 0
        y: 0
        width: 400
        height: 400
        environment: sceneEnvironment
        SceneEnvironment {
            id: sceneEnvironment
            antialiasingQuality: SceneEnvironment.High
            antialiasingMode: SceneEnvironment.MSAA
        }

        Node {
            id: scene
            DirectionalLight {
                id: directionalLight
            }

            PerspectiveCamera {
                id: camera
                z: 350
            }

            Model {
                id: cubeModel
                source: "#Cube"
                materials: cubeMaterial
                DefaultMaterial {
                    id: cubeMaterial
                    diffuseColor: "#4aee45"
                }
                eulerRotation.y: 45
                eulerRotation.x: 30
            }

            Model {
                id: sphere
                source: "#Sphere"
                materials: sphereMaterial
                DefaultMaterial {
                    id: sphereMaterial
                    diffuseColor: "#4aee45"
                }
            }

            Model {
                id: sphere1
                source: "#Sphere"
                materials: sphereMaterial1
                DefaultMaterial {
                    id: sphereMaterial1
                    diffuseColor: "#4aee45"
                }
            }
        }
    }
}
