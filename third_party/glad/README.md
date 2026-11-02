# glad

Vendored OpenGL loader generated with [glad 2.0.8](https://github.com/Dav1dde/glad).

- API: `gl:core=3.3`
- Extensions: none
- Options: none

The generated files are committed so no Python or `libglew` is needed to
build the game.

## Regenerating

Requires Python 3 and `pip install glad2`:

```bash
python -m glad \
    --api gl:core=3.3 \
    --extensions "" \
    --out-path third_party/glad \
    --reproducible \
    c
```

To include specific extensions later, pass a comma-separated list, for example:

```bash
--extensions "GL_KHR_debug,GL_ARB_direct_state_access"
```

Then rebuild; no CMake changes are needed.
