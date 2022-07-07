/*
    courtesy of @ReFil, some custom code for layer LED behaviour

    this _should_ be made redundant in the near future by changes
    in upstream ZMK, but for now, it's useful

    insert this replacing the contents of the relevant function in
    zmk/app/src/rgb_underglow.c
*/

static void zmk_rgb_underglow_effect_layer_default() {
    struct led_rgb rgb;

    if (zmk_keymap_layer_active(2)) { // this matches the position of the shift layer in the keymap
        if (!state.on) {
#if IS_ENABLED(CONFIG_ZMK_RGB_UNDERGLOW_EXT_POWER)
            if (ext_power != NULL) {
                int rc = ext_power_enable(ext_power);
                if (rc != 0) {
                    LOG_ERR("Unable to enable EXT_POWER: %d", rc);
                }
            }
#endif

            state.on = true;
            state.animation_step = 0;
        }
        switch (zmk_keymap_layer_default()) {
        case 0:
            rgb.r = 10;
            rgb.g = 147;
            rgb.b = 150;
            break;
        case 1:
            rgb.r = 202;
            rgb.g = 103;
            rgb.b = 2;
            break;
        case 2:
            rgb.r = 0;
            rgb.g = 0;
            rgb.b = 255; // in the current keymap, these are never hit
            break;
        case 3:
            rgb.r = 255;
            rgb.g = 255;
            rgb.b = 0;
            break;
        case 4:
            rgb.r = 0;
            rgb.g = 255;
            rgb.b = 255;
            break;
        case 5:
            rgb.r = 255;
            rgb.g = 0;
            rgb.b = 255;
            break;
        default:
            break;
        }

        for (int i = 0; i < STRIP_NUM_PIXELS; i++) {
            pixels[i] = rgb;
        }
    } else {
        if (state.on) {
            if (ext_power != NULL) {
                int rc = ext_power_disable(ext_power);
                if (rc != 0) {
                    LOG_ERR("Unable to disable EXT_POWER: %d", rc);
                }
            }
            for (int i = 0; i < STRIP_NUM_PIXELS; i++) {
                pixels[i] = (struct led_rgb){r : 0, g : 0, b : 0};
            }

            state.on = false;
        }
    }
}

/*
    in the original patch for this, a leading return statement in the form -

        if (!state.on) {
            return;
        }

    - was removed from the zmk_rgb_underglow_tick_handler function
    not entirely sure if that's necessary for functionality or an artefact
    of a quick commit, but if ever necessary to re-patch, perform some tests
*/