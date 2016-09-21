// smg$routines
//
// Part of a simple library using ncurses to implement SMG under
// Linux?unix enough to make a specific set of programs work.
//
// Definitions based on the SMG routines manual.
// This is not the VMS smg#routines header file.
// Many incompatabilities exist, many functions are missing, and
// those that exist may not operate like the original.
//
# if !defined _smg_routines_h_
#define _smg_routines_h_

#include <string>
#include <smgdef.h>

//! \brief Special structure used by this implementation
//!
//! This structure is pointed to by the DISPLAY_ID variable.
//!
struct ncurses_struct
{
	WINDOW *win;			//!< Window
	PANEL *pan;			//!< Panel
	int border;			//!< Width of border (if exists)
	std::string label;		//!< Window border label (for repaint)
	long width;			//!< Width to create at
	long height;			//!< Height to create at
	long hpos;			//!< Horozontal position for window
	long vpos;			//!< Vertical position of window
};

long smg$change_pbd_characteristics(
	long *pasteboard_id,
	const long *desired_width = 0,
	long *width = 0,
	const long *desired_height = 0,
	long *height = 0,
	long *desired_background_color = 0,
	long *background_color = 0);

long smg$create_pasteboard(
	long *pasteboard_id,
	const std::string *output_device = 0,
	long *number_of_pasteboard_rows = 0,
	long *number_of_pasteboard_columns = 0,
	const long *flags = 0,
	long *type_of_terminal = 0,
	std::string *device_name = 0);

long smg$create_virtual_display(
	const long *number_of_rows,
	const long *number_of_columns,
	ncurses_struct **display_id,
	const long *display_attributes = 0,
	const long *video_attributes = 0,
	const long *character_set = 0);

long smg$create_virtual_keyboard(
	long *keyboard_id,
	const std::string *input_device = 0,
	const std::string *default_filespec = 0,
	std::string *resultant_filespec = 0,
	const long *recall_size = 0);

long smg$erase_display(
	struct ncurses_struct **display_id,
	long start_row = 0,
	long end_row = 0,
	long start_column = 0,
	long end_column = 0);

long smg$paste_virtual_display(
	struct ncurses_struct **display_id,
	const long *pasteboard_id,
	const long *pasteboard_row = 0,
	const long *pasteboard_column = 0,
	const long top_display_id = 0);

long smg$set_cursor_mode(
	long *pasteboard_id,
	long *flags);

#endif
