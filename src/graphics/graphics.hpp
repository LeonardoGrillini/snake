#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <cstdint>
#include <ctime>

#ifdef _WIN32
#include <ncurses/ncurses.h>
#else
#include <ncurses.h>
#endif

namespace Graphics {

typedef enum {
    RED_TEXT = 1,
    GREEN_TEXT = 2,
    BLUE_TEXT = 3,
    YELLOW_TEXT = 4
} UIColors;

/**
 * Puts centered text inside of a window
 */
void put_centered_text(WINDOW *win, const char *text);

/**
 * Puts centered text inside of a window
 * that has a certain color
 */
void put_centered_colored_text(WINDOW *win, const char *text, int color_id);

/**
 * Returns true if the given coordinates are inside of the given window
 */
bool is_inside_window(WINDOW *win, int x, int y);

/**
 * Returns true if the given coordinates are inside of the given subpad
 * requires the parent's current line
 */
bool is_inside_subpad(WINDOW *subpad, int x, int y, int current_parent_line);

/*
* Draws snake ASCII art
*/
void draw_art(WINDOW* win, const char** art, uint16_t art_lines, int start_y, int start_x);

void start_ncurses();
void stop_ncurses();

/**
 * Returns a new bordered window with the given paramethers
 */
WINDOW *new_bordered_window(int height, int width, int y, int x);

/**
 * Returns a new bordered subpad with the given paramethers
 */
WINDOW *new_bordered_subpad(WINDOW* parent, int height, int width, int y, int x);

/**
 * Returns a new bordered subpad with the given paramethers
 */
WINDOW *new_colored_bordered_subpad(WINDOW* parent, int height, int width, int y, int x, int color_id);

} // namespace Graphics

#endif