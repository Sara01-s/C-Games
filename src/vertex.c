#include "vertex.h"
#include <assert.h>

#define X 0
#define Y 1
#define Z 2
#define W 3
#define R X
#define G Y
#define B Z
#define A W
#define U X
#define V Y

void vertex_set_position(Vertex* vertex, vec2 position) {
    vertex->position[X] = position[X];
    vertex->position[Y] = position[Y];
}

void vertex_set_color(Vertex* vertex, vec4 color) {
    vertex->color[R] = color[R];
    vertex->color[G] = color[G];
    vertex->color[B] = color[B];
    vertex->color[A] = color[A];
}

void vertex_set_texcoords(Vertex* vertex, vec2 texcoords) {
    vertex->texcoords[U] = texcoords[U];
    vertex->texcoords[V] = texcoords[V];
}

void vertex_create(Vertex* vertex, vec2 position, vec4 color, vec2 texcoords) {
    vertex_set_position(vertex, position);
    vertex_set_color(vertex, color);
    vertex_set_texcoords(vertex, texcoords);
}

/* Don't forget to free() the created vertex */
Vertex* vertex_square_create(vec2 origin_position, float size) {

    Vertex* square_vertices = malloc(4 * sizeof(Vertex));

    assert(square_vertices != NULL);

    vertex_set_position(&square_vertices[0], (vec2) { origin_position[X],        origin_position[Y]        });
    vertex_set_position(&square_vertices[1], (vec2) { origin_position[X] + size, origin_position[Y]        });
    vertex_set_position(&square_vertices[2], (vec2) { origin_position[X] + size, origin_position[Y] + size });
    vertex_set_position(&square_vertices[3], (vec2) { origin_position[X],        origin_position[Y] + size });

    return square_vertices;
}