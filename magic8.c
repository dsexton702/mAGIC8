#include <pebble.h>


#define INVERT_COLORS

#ifndef INVERT_COLORS
#define COLOR_FOREGROUND GColorBlack
#define COLOR_BACKGROUND GColorWhite
#else
#define COLOR_FOREGROUND GColorWhite
#define COLOR_BACKGROUND GColorBlack
#endif
#define NUM_OPTIONS 21;

static Window *window;
static TextLayer *text_layer;
static const int x[] = {'1', '2', '3','4'};
static int y;

void accel_tap_handler(AccelAxisType axis, int32_t direction) {
  // Process tap on ACCEL_AXIS_X, ACCEL_AXIS_Y or ACCEL_AXIS_Z
  //  
srand( time(NULL) );

y = rand() % NUM_OPTIONS;

if(ACCEL_AXIS_Y == 1 || ACCEL_AXIS_Y == -1){
if(y == 1){
text_layer_set_text(text_layer, "Yes");
	}else
	if(y == 2){
text_layer_set_text(text_layer, "My reply is no");
		}else
		if(y == 3){
text_layer_set_text(text_layer, "Ask again later");
			}else
			if(y == 4){
text_layer_set_text(text_layer, "Reply hazy try again");
					}else
if(y == 5){
text_layer_set_text(text_layer, "Better not say now");
	}else
	if(y == 6){
text_layer_set_text(text_layer, "Cannot predict now");
		}else
		if(y == 7){
text_layer_set_text(text_layer, "Concentrate and ask again");
			}else
			if(y == 8){
text_layer_set_text(text_layer, "Don't count on it");
					}else
		if(y == 9){
text_layer_set_text(text_layer, "My sources say no");
			}else
			if(y == 10){
text_layer_set_text(text_layer, "Outlook not so good");
					}else
if(y == 11){
text_layer_set_text(text_layer, "Very doubtful");
	}else
	if(y == 12){
text_layer_set_text(text_layer, "Outlook good");
		}else
		if(y == 13){
text_layer_set_text(text_layer, "Most likely");
			}else
			if(y == 14){
text_layer_set_text(text_layer, "Signs point to yes");
					}else
if(y == 15){
text_layer_set_text(text_layer, "As i see it yes");
	}else
	if(y == 16){
text_layer_set_text(text_layer, "You may rely on it");
		}else
		if(y == 17){
text_layer_set_text(text_layer, "Yes definitely");
			}else
			if(y == 18){
text_layer_set_text(text_layer, "Without a doubt");
					}else
		if(y == 19){
text_layer_set_text(text_layer, "It is certain");
			}else
			if(y == 20){
text_layer_set_text(text_layer, "It is decidedly so");
					}
}
}





static void select_click_handler(ClickRecognizerRef recognizer, void *context) {
  text_layer_set_text(text_layer, "mAGIC8");
}

static void up_click_handler(ClickRecognizerRef recognizer, void *context) {
  
}

static void down_click_handler(ClickRecognizerRef recognizer, void *context) {
  
}

static void click_config_provider(void *context) {
  window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
  window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
  window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
}

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);

  text_layer = text_layer_create((GRect) { .origin = { 0, 72 }, .size = { bounds.size.w, 20 } });
text_layer_set_text_color(text_layer, COLOR_FOREGROUND);
text_layer_set_background_color(text_layer, COLOR_BACKGROUND);
  text_layer_set_text(text_layer, "mAGIC8");
  text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
  layer_add_child(window_layer, text_layer_get_layer(text_layer));
}

static void window_unload(Window *window) {
  text_layer_destroy(text_layer);
}

static void init(void) {
  window = window_create();
  window_set_click_config_provider(window, click_config_provider);
window_set_background_color(window, COLOR_BACKGROUND);
  window_set_window_handlers(window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });
  const bool animated = true;
  window_stack_push(window, animated);
 accel_tap_service_subscribe(&accel_tap_handler);
}

static void deinit(void) {
  window_destroy(window);
accel_tap_service_unsubscribe();
}

int main(void) {
  init();

  APP_LOG(APP_LOG_LEVEL_DEBUG, "Done initializing, pushed window: %p", window);

  app_event_loop();
  deinit();
}
