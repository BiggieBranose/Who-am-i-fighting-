import glfw, moderngl, numpy as np

glfw.init()
glfw.window_hint(glfw.CONTEXT_VERSION_MAJOR, 3)
glfw.window_hint(glfw.CONTEXT_VERSION_MINOR, 3)
glfw.window_hint(glfw.OPENGL_PROFILE, glfw.OPENGL_CORE_PROFILE)

window = glfw.create_window(800, 600, "Who Am I Fighting?", None, None)
glfw.make_context_current(window)
ctx = moderngl.create_context()

prog = ctx.program(
    vertex_shader='''
        #version 330
        in vec3 in_vert;
        void main() { gl_Position = vec4(in_vert, 1.0); }
    ''',
    fragment_shader='''
        #version 330
        out vec4 f_color;
        void main() { f_color = vec4(1.0, 0.5, 0.2, 1.0); }
    ''',
)

vertices = np.array([-0.5, -0.5, 0.0,  0.5, -0.5, 0.0,  0.0, 0.5, 0.0], dtype='f4')
vbo = ctx.buffer(vertices.tobytes())
vao = ctx.vertex_array(prog, [(vbo, '3f', 'in_vert')])

while not glfw.window_should_close(window):
    ctx.clear(0.1, 0.1, 0.1)
    vao.render()
    glfw.swap_buffers(window)
    glfw.poll_events()
    
glfw.terminate()