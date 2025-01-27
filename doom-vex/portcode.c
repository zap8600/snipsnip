/*
This snippet is for porting DOOM to the VEX V5 Robot brain usin PROS
At the time of writing this, I cannot work on the port until later today
So I'm writing the funnctions I would need now so that I don't forget them
*/

/*
Joystick code
*/

// These functions can remain empty. I don't need them
void I_InitJoystick(void) {}
void I_ShutdownJoystick(void) {}

// This I do need
void I_UpdateJoystick(void) {
    if(controller_is_connected(E_CONTROLLER_MASTER)) {
        event_t ev;

        ev.type = ev_joystick;
        ev.data1 = 0;
        ev.data2 = controller_get_analog(E_CONTROLLER_MASTER, E_CONTROLLER_ANALOG_RIGHT_X);
        ev.data3 = controller_get_analog(E_CONTROLLER_MASTER, E_CONTROLLER_ANALOG_LEFT_Y);
        ev.data4 = controller_get_analog(E_CONTROLLER_MASTER, E_CONTROLLER_ANALOG_LEFT_X);

        D_PostEvent(&ev);
    }
}


/*
Drawing code
*/

// Max resolution defined in the PROS LVGL config
#define DOOMGENERIC_RESX 480
#define DOOMGENERIC_RESY 240

// Last time, I drew the framebuffer pixel by pixel, but it drew incorrectly
void DG_DrawFrame() {
    // I don't think this is right, but this is what PROS does for LVGL, so I'm just going to do the same thing.
    screen_copy_area(0, 0, DOOMGENERIC_RESX, DOOMGENERIC_RESY, DG_ScreenBuffer, DOOMGENERIC_RESX + 1);
}
