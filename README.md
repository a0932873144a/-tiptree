# PTSD Template

This is a [PTSD](https://github.com/ntut-open-source-club/practical-tools-for-simple-design) framework template for students taking OOPL2024s.

## Quick Start

1. Use this template to create a new repository
   ![github screenshot](https://github.com/ntut-rick/ptsd-template/assets/126899559/ef62242f-03ed-481d-b858-12b730c09beb)

2. Clone your repository

   ```bash
   git clone YOUR_GIT_URL --recursive
   ```

3. Build your project

  > [!WARNING]
  > Please build your project in `Debug` because our `Release` path is broken D:
   
   ```sh
   cmake -DCMAKE_BUILD_TYPE=Debug -B build # -G Ninja
   ```
   better read [PTSD README](https://github.com/ntut-open-source-club/practical-tools-for-simple-design)

# UPDATE_NOTE

After making new things, please write here to notify the other.

## 3/11 by Tiptree

1. I won't take time to write any update before today. If you want to know, just call me.
2. At Resources: 
   1. remove background_test.png  
   2. add boundary_straight.png/horizontal.png at /Image/Background
   3. adjust the size of player.png, enemy.png
3. At src:
   1. add GameMechanics.cpp, create new functions like Move(), Push(), HitBoundaryGetBack(), CrushEnemy() which declare at App.hpp
   2. add the boundary at App.cpp and App.hpp
   3. add some lines to declare objects at App.cpp(and App.hpp)
4. At include:
   1. change some words at TaskText.hpp
   2. add StepText.hpp, which declare at App.hpp, with functions that can control the steps
   3. add GameMechanics.hpp, but barely write nothing in it
   4. add const float grid_size at App.hpp