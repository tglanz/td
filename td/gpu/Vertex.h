#ifndef __TD_GPU_VERTEX_H__
#define __TD_GPU_VERTEX_H__

#include <stdio.h>

#include <GL/glew.h>
#include <glm/glm.hpp>

using namespace glm;

namespace td {
    namespace gpu{

        struct VertexAttribMeta
        {
            const int ComponentSize;
            const int Components;
            const int Size;
            const int Offset;
            const GLuint Type;
            const GLboolean Normalize;

            VertexAttribMeta(const int& componentSize, const int& components, const int& offset, GLuint type, GLboolean normalize):
                ComponentSize(componentSize),
                Components(components),
                Size(ComponentSize * components),
                Offset(offset),
                Type(type),
                Normalize(normalize)

            { }
        };

        class Vertex
        {
        private:
            vec3 m_position;
            vec4 m_color;
            vec3 m_normal;

        public:
            const static gpu::VertexAttribMeta Position;
            const static gpu::VertexAttribMeta Color;
            const static gpu::VertexAttribMeta Normal;

            Vertex()
            {
                m_position = vec3(0.0f, 0.0f, 0.0f);
                m_color = vec4(0.5f, 0.5f, 0.5f, 1.0);
                m_normal = vec3(0, 0, 0);
            }

            void printPosition()
            {
                printf("xyz:\t%f\t%f\t%f\n", m_position.x, m_position.y, m_position.z);
            }

            void printColor()
            {
                printf("rgba:\t%f\t%f\t%f\t%f\n", m_color.r, m_color.g, m_color.b, m_color.a);
            }

            void printNormal()
            {
                printf("xyz:\t%f\t%f\t%f\n", m_normal.x, m_normal.y, m_normal.z);
            }

            /**
                position functions
                all functions are explicitly implemented

                refactor
            **/

            const glm::vec3 & getPosition()
            {
                return m_position;
            }

            Vertex& setPosition(const vec3& position)
            {
                m_position.x = position.x;
                m_position.y = position.y;
                m_position.z = position.z;
                return *this;
            }

            Vertex& setPosition(const float& x, const float& y, const float& z)
            {
                m_position.x = x;
                m_position.y = y;
                m_position.z = z;
                return *this;
            }

            /**
                setNormal
                all functions are explicitly implemented
            **/

            const vec3 & getNormal()
            {
                return m_normal;
            }

            Vertex & setNormalUnormalized(const vec3& normal)
            {
                m_normal = normal;
                return *this;
            }

            Vertex & setNormal(const vec3& normal)
            {
                m_normal = normalize(normal);
                return *this;
            }

            Vertex & setNormal(const float& x, const float& y, const float& z)
            {
                m_normal = normalize(glm::vec3(x, y, z));
                return *this;
            }

            /**
                setColor
                all functions are explicitly implemented
            **/

            Vertex& setColor(const vec4& color)
            {
                m_color.r = color.r;
                m_color.g = color.g;
                m_color.b = color.b;
                m_color.a = color.a;
                return *this;
            }

            Vertex& setColor(const vec3& color)
            {
                m_color.r = color.r;
                m_color.g = color.g;
                m_color.b = color.b;
                return *this;
            }

            Vertex& setColor(const float& r, const float& g, const float& b)
            {
                m_color.r = r;
                m_color.g = g;
                m_color.b = b;
                return *this;
            }

            Vertex& setColor(const float& r, const float& g, const float& b, const float& a)
            {
                m_color.r = r;
                m_color.g = g;
                m_color.b = b;
                m_color.a = a;
                return *this;
            }
        };

    }
}

#endif // __TD_GPU_VERTEX_H__
