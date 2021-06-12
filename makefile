output: main.o TextRenderer.o Shader.o
	g++ -std=c++14 -framework OpenGL -framework IOKit -framework Cocoa -lglew -lglfw -lfreetype -I/usr/local/Cellar/glfw/** -I/usr/local/Cellar/glew/** -I -L/usr/local/Cellar/glfw/3.3.2/lib -L/usr/local/Cellar/glew/2.1.0_1/lib  main.o TextRenderer.o Shader.o -o main

main.o: main.cpp
	g++ -c -std=c++14 -I/usr/local/opt/freetype/include/freetype2 -I/Users/pashaukolov/Documents/libraries/glm  main.cpp
TextRenderer.o: TextRenderer.cpp TextRenderer.hpp 
	g++ -c -std=c++14 -I/usr/local/opt/freetype/include/freetype2 -I/Users/pashaukolov/Documents/libraries/glm TextRenderer.cpp
Shader.o: Shader.cpp Shader.hpp
	g++ -c -std=c++14 Shader.cpp
clean:
	rm *.o main