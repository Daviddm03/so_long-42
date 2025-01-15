# So_long-42 👾
<h3>What is So_long ⁉️</h3>
The So_long project at 42 is a practical introduction to 2D game development and the use of the MiniLibX graphical library. The goal is to create a small game with simple mechanics where the player must traverse a map, collect items, avoid obstacles, and reach the exit to win. This project teaches fundamental concepts of graphical rendering, event handling, and game logic.

<h3>Key points 🔑</h3>

**Map Handling**
- The map is represented by a .ber file and must follow a specific format containing walls, collectible items, empty spaces, the player's starting point, and the exit.

**Graphical Rendering**
- Uses MiniLibX to display the map, sprites, and animations. This includes frame-by-frame rendering and efficient window management.

**Event and Movement Handling**
- Captures events such as key presses to move the character across the map and interact with the environment.

**Resource Management**
- Handles proper memory allocation and deallocation, as well as graceful game termination when specific conditions are met or in case of errors.

<h3>Conclusion ✅</h3>
In summary, so_long is a practical introduction to 2D game development and graphical libraries in C. It allows students to consolidate their knowledge of event handling, game logic, and resource management while building a fun and interactive application.

<h3>How to run</h3>

1 - **Clone my repository**
```bash
$ git clone https://github.com/Daviddm03/so_long-42.git
```

2 - **Navigate to the directory**
```bash
$ cd so_long-42
```

3 - **Clone the minilibx**
```bash
$ git clone https://github.com/42Paris/minilibx-linux minilibx_linux
```

4 - **Install the following packages**
```bash
$ apt install libx11-dev
apt install libxext-dev
apt install libbsd-dev
apt install clang
```

4 - **Compile the program**
```bash
$ make
```

5 - **Run the game**
```bash
$ ./so_long map/map_name
```

