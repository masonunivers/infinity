***
*This project has been created as part of the 42 curriculum by jomason*

# 🌌 Fract-ol: The Mathematical Sketchbook


## 🔭 Description

**fract-ol** is a high-performance, interactive fractal renderer powered by the MiniLibX graphical library. It serves as a viewport into the infinite complexity of the mathematical universe. 

By applying the Escape Time Algorithm to every single pixel on the screen, this program translates cold, abstract formulas into breathtaking, self-similar visual art. Beyond the visuals, this project represents a deep dive into bare-metal graphics programming, strict memory management, and the raw beauty of complex arithmetic.

### 🧠 Core Learning Outcomes
* **The Digital Canvas (Image Buffering):** Mastering the `t_img` structure to manipulate raw pixel data directly in memory, ensuring buttery-smooth, flicker-free rendering.
* **Cartesian to Complex (Coordinate Mapping):** Forging a mathematical "viewing window" to precisely translate standard screen coordinates `(x, y)` into the complex plane `(real, imag)`.
* **The Observer Effect (Event-Driven Architecture):** Wiring MiniLibX hooks to breathe life into the fractal, enabling real-time user manipulation through zooming, panning, and kaleidoscopic color shifting.

---

## 🚀 Instruction

### Compilation
To forge the executable and prepare the rendering engine, simply run the following command in the root directory:
```shell
make
```

### Execution
Launch the program by feeding it the name of the mathematical universe you wish to explore:
```shell
./fractol Mandel  # Delve into the iconic Mandelbrot Set
./fractol Julia   # Explore the hypnotic Julia Set
./fractol Ship    # Navigate the fiery Burning Ship
```

*For the memory-conscious engineer, you can verify the hull's integrity by running the program through Valgrind:*
```shell
valgrind --leak-check=full --show-leak-kinds=all ./fractol
```

---

## 🎮 Flight Controls

* **Mouse Wheel:** Zoom deep into the abyss (smartly anchored to your cursor's current position).
* **Arrow Keys:** Pan across the infinite fractal landscapes.
* **Space / Number Keys:** Shift the color palette and completely alter the visual atmosphere.
* **ESC / Close Window:** Safely terminate the session, gracefully freeing all allocated resources and memory.

---

## ⚙️ Technical Choices

To achieve uncompromising performance and a seamless user experience, **fract-ol** was built on several precise architectural decisions:

* **The Monolith (State Machine Architecture):** All critical state data—MLX pointers, image buffers, and complex coordinates—are elegantly encapsulated within a single `t_fractol` structure. This ensures clean, modular, and leak-free access across the program's lifecycle.
* **Ruthless Optimization:** Calculating square roots is an expensive operation. To maximize frame rates, the escape detection logic completely sidesteps `sqrt()`, relying instead on the squared distance: $zr^2 + zi^2 > 4$.
* **Polymorphic Rendering (Function Pointers):** The engine dynamically swaps between Mandelbrot and Julia rendering formulas via function pointers. This prevents the performance sink of clunky `if-else` chains during the computationally heavy pixel-drawing loop.
* **Off-Screen Drawing (Double Buffering):** Every single frame is painted entirely in a background memory buffer before being pushed to the display window, effectively eliminating screen tearing.

---

## 📚 Resources

* **Complex Number Arithmetic:** The mathematical beating heart of the engine, rooted in the formula $z = z^2 + c$.
* **42 Subject Manual:** The guiding constraints and sanctioned functions of the project.

---

## 🧙 Use of AI

In the spirit of modern development, Artificial Intelligence was leveraged as a collaborative tutor during the genesis of this project:

* **Demystifying the Arcane:** AI assisted in breaking down foundational knowledge, providing intuitive metaphors for low-level concepts like `t_img` memory layouts, Endianness, and computer graphics theory.
* **Algorithmic Whispers:** AI served as a sounding board for logic structure, clarifying the mathematical theory behind coordinate mapping, the Escape Time Algorithm, and the elegant implementation of function pointers within C structs.
***