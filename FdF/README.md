***
*This project has been created as part of the 42 curriculum by jomason.*
***

# FdF - Wireframe Model

## 🗺️ Project Description
**FdF** (*FDF is short for ’fil de fer’ in French which means ’wireframe model’.*) is a graphic project at 42 that involves creating a 3D wireframe mesh of a landscape. By reading a grid of altitudes from a `.fdf` file, the program projects these points into a 2D window using isometric projection and connects them using Bresenham's line-drawing algorithm.

This version is implemented using the **MLX42** library.

---

## 🚀 Features
- **Isometric Projection**: Transforms raw $x, y, z$ coordinates into a 3D perspective.
- **Bresenham's Algorithm**: Efficiently draws line segments between points.
- **Interactive Camera**: 
    - **Zoom**: Scale the map using `+` and `-`.
    - **Translation**: Move the view using the Arrow Keys.
- **Optimization**: Features a "trivial rejection" system to skip rendering lines that fall outside the 1000x1000 viewport.

---

## 🛠️ Controls

| Key | Action |
| :--- | :--- |
| **`ESC`** | Close the application |
| **`Arrow Keys`** | Move the map |
| **`+` / `-`** | Zoom In / Out |
| **Window 'X'** | Exit program |

---

## 📐 Implementation Details

### Data Structures
The project is built around a centralized `t_data` structure that manages the MLX instance, the image buffer, the map dimensions, and the camera state.
- `t_point_in`: Stores the raw coordinates from the file.
- `t_point_render`: Stores the calculated 2D screen coordinates.

### Math: The Projection
To achieve the 3D effect, I applied an isometric projection formula found in `projection.c`:
- $x_{iso} = (x - y) \times \cos(30^\circ)$
- $y_{iso} = (x + y) \times \sin(30^\circ) - z$

---

## 📦 Instructions & Usage

### Prerequisites
- A C compiler (GCC or Clang)
- **MLX42** library and its dependencies (GLFW, CMake)
- **Libft** (included in the source)

### Compilation
Build the executable using the provided Makefile:
```bash
make
```

### Execution
Run the program by passing a valid map file as an argument:
```bash
./fdf maps/42.fdf
```
---

## 📚 Resources

* **Isometric Projection Theory**: The mathematical logic used to convert 3D coordinates into a 2D plane, typically using a $30^\circ$ angle.
* **Bresenham's Line Algorithm**: An efficient algorithm used to determine the points of an n-dimensional raster that should be selected in order to form a close approximation to a straight line.
* **42 Subject Manual**: The guiding constraints and sanctioned functions of the project.

---

## 🧙 Use of AI

In the spirit of modern development, Artificial Intelligence was leveraged as a collaborative tutor during the genesis of this project:

* **Fun While Learning**: AI assisted in breaking down foundational knowledge, providing intuitive metaphors for low-level concepts like `t_data` memory layouts, pixel-safe drawing, and computer graphics theory.
* **Algorithm Explained for Dummies**: AI served as a sounding board for logic structure, clarifying the mathematical theory behind coordinate mapping and the elegant implementation of Bresenham's algorithm within a C environment.
---