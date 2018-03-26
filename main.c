#include <stdio.h>
#include <allegro.h>

volatile int close_button_pressed = FALSE;

void close_button_handler(void) {
	
	close_button_pressed = TRUE;
	
	}
	
END_OF_FUNCTION(close_button_handler)


int main(int argc, char **argv) {
	
	const int year = ALLEGRO_DATE / 10000;
	const int month = (ALLEGRO_DATE / 100) % 100;
	const int day = ALLEGRO_DATE % 100;
	
	char buf[100];
	
	

	if (allegro_init() < 0) {
		
		printf("Fehler: Allegro konnte nicht initialisiert werden");
		
		return (0); 
	}
	
	install_keyboard();
	
	set_color_depth(32);
	
	
	if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0) < 0) {
		
		printf("Fehler: Grafik konnte nicht initialisiert werden");
		
		return (0);
	}
	
	LOCK_FUNCTION(close_button_handler);
	
	set_close_button_callback(close_button_handler);

	
	set_window_title("Hallo in Allegro Welt");	
		
	printf("\nYear %d, month %d, day %d\n",year, month, day);
	
	// printf("\nAllegro-Version: %d.%d", ALLEGRO_VERSION,ALLEGRO_SUB_VERSION);
	
	printf("\nFarbtiefe: %d", get_color_depth());
	
	allegro_message("Hi");
	
	
	while((!key[KEY_ESC]) && (!close_button_pressed));	/*** Warte auf Tastendruck ***/
		
	
} END_OF_MAIN();

