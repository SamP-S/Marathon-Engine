#pragma once

#include "la_extended.h"
using namespace LA;
#include "transform.hpp"
#include "component.h"

class Camera : public Component {

    private:
        float _fov = 45.0f;
        float _near = 0.1f;
        float _far = 100.0f;
        unsigned int _width = 800;
        unsigned int _height = 600;

        void UpdateProjection()
        {
            proj = Perspective(_fov, (float)_width / (float)_height, _near, _far);
        }
    
    public:

        mat4 proj = mat4();

        Camera(Entity& entity) :
            Component(entity) {}

        ~Camera() {}

        std::string ComponentType() {
            return "Camera";
        }

        float GetFov() {
            return _fov;
        }
        void SetFov(float fov) {
            _fov = fov;
            UpdateProjection();
        }

        float GetNear() {
            return _near;
        }
        void SetNear(float near) {
            _near = near;
            UpdateProjection();
        }

        float GetFar() {
            return _far;
        }
        void SetFar(float far) {
            _far = far;
            UpdateProjection();
        }

        int GetWidth() {
            return _width;
        }
        void SetWidth(int width) {
            _width = width;
            UpdateProjection();
        }

        int GetHeight() {
            return _height;
        }
        void SetHeight(int height) {
            _height = height;
            UpdateProjection();
        }

        void SetResolution(int width, int height) {
            _width = width;
            _height = height;
            UpdateProjection();
        }
};