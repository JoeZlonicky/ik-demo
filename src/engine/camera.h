#ifndef IK_DEMO_CAMERA_H_
#define IK_DEMO_CAMERA_H_

#include "math/vector_3.h"
#include "math/matrix_4.h"

class Camera {
public:
    Camera(Vector3 pos, Vector3 target, float aspect_ratio);

    void setPos(Vector3 pos);
    void setPosX(float x);
    void setPosY(float y);
    void setPosZ(float z);

    void setTarget(Vector3 target);
    void setFOV(float degrees);
    void setNearPlane(float d);
    void setFarPlane(float d);
    void setAspectRatio(float ratio);

    const Matrix4& getProjectionViewMatrix();
    const Vector3& getPos();

private:
    void calculateProjectionViewMatrix();

    bool dirtyMatrixFlag = false;
    Vector3 pos_;
    Vector3 target_;
    float fov_degrees_ = 45.0f;
    float near_plane_ = 0.1f;
    float far_plane_ = 100.f;
    float aspect_ratio_;

    Matrix4 projection_view_matrix_ = {};
};

#endif
